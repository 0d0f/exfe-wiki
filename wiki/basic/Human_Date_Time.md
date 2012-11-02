h1. Human Date Time 主要逻辑

参数：
1：UTC 时间字符串，格式： Y-m-d H:i:s / Y-m-d (如果包含时间=>需要处理时区差异，如果不包含时间=>不需要处理时区差异)
2：时区，格式：+8:00
3：datetype 模糊时间/时间类型
4：origin_begin_at 用户输入的原始时间：

逻辑：
⋯⋯⋯⋯⋯⋯待续⋯⋯⋯⋯
注：当输入时间不是当前年份时需在日期后显示年份。

规则是：
Time_word (at) Time (Timezone) Date_word (on) Date

显示规则：

1 
outputformat = 0 需要格式化
outputformat = 1 直接输出，如果和终端时区不一样，就需要显示时区。

2  时区

outputformat = 0
若需要根据Timezone计算时区，则要求Time存在或者Time和Date都存在。 

如果要显示的终端时区和Timezone一样，就不需要显示时区，如果不同，就转换成当前终端时区。

outputformat = 1
如果和终端时区不一样，就显示出Timezone


3 格式化

Time_word (at) Time (Timezone) Date_word (on) Date 

Time_word/Time/Date_word/Date 都是字符串，所以如果为空就是不存在。否则就需要显示。

如果计算过时区之后，比较年份，如果年份和当前不同，就显示年份。






 

测试用例：
<pre>
  type EFTime struct {
    Date_word string
    Date string
    Time_word string
    Time string
    Timezone string
  }

  type OutputFormat uint

  const (
    Format OutputFormat = 0
    Origin = 1
  )

  type CrossTime struct {
    Begin_at EFTime
    Origin string
    OutputFormat OutputFormat
  }

  type CrossTimeTest struct {
    time CrossTime
    targetZone string
    expect string
  }

  var crossTimeTestData = []CrossTimeTest{
    // if OutputOrigin, then output origin directly
    {CrossTime{EFTime{"", ThisYearDate(), "", "06:08:00", "+08:00 CST"}, "2012-04-04 2:08:00 pm abc", Origin}, "+08:00 CST", fmt.Sprintf("2012-04-04 2:08:00 pm abc")},
    {CrossTime{EFTime{"", ThisYearDate(), "", "06:08:00", "+08:00 CST"}, "2012-04-04 14:08:00", Format}, "+08:00 CST", fmt.Sprintf("2:08PM on %s", ThisYear())},
    {CrossTime{EFTime{"", "", "", "", "+08:00 CST"}, "", Format}, "+08:00 CST", ""},

    // Time_word (at) Time Date_word (on) Date
    {CrossTime{EFTime{"This Week", "", "", "", "+08:00 CST"}, "This week", Format}, "+08:00 CST", fmt.Sprintf("This Week")},
    {CrossTime{EFTime{"", ThisYearDate(), "", "", "+08:00 CST"}, "2012 4 4", Format}, "+08:00 CST", fmt.Sprintf("%s", ThisYear())},
    {CrossTime{EFTime{"", "", "Dinner", "", "+08:00 CST"}, "dinner", Format}, "+08:00 CST", fmt.Sprintf("Dinner")},
    {CrossTime{EFTime{"", "", "", "06:08:00", "+08:00 CST"}, "14:08:00", Format}, "+08:00 CST", fmt.Sprintf("2:08PM")},
    {CrossTime{EFTime{"This Week", ThisYearDate(), "", "", "+08:00 CST"}, "This week 2012 04 04", Format}, "+08:00 CST", fmt.Sprintf("This Week on %s", ThisYear())},
    {CrossTime{EFTime{"This Week", "", "Dinner", "", "+08:00 CST"}, "dinner this week", Format}, "+08:00 CST", fmt.Sprintf("Dinner This Week")},
    {CrossTime{EFTime{"This Week", "", "", "06:08:00", "+08:00 CST"}, "14:08 this week", Format}, "+08:00 CST", fmt.Sprintf("2:08PM This Week")},
    {CrossTime{EFTime{"", ThisYearDate(), "Dinner", "", "+08:00 CST"}, "dinner 2012-04-04", Format}, "+08:00 CST", fmt.Sprintf("Dinner on %s", ThisYear())},
    {CrossTime{EFTime{"", ThisYearDate(), "", "06:08:00", "+08:00 CST"}, "2012 04 04 14:08", Format}, "+08:00 CST", fmt.Sprintf("2:08PM on %s", ThisYear())},
    {CrossTime{EFTime{"", "", "Dinner", "06:08:00", "+08:00 CST"}, "dinner at 14:08", Format}, "+08:00 CST", fmt.Sprintf("Dinner at 2:08PM")},
    {CrossTime{EFTime{"This Week", ThisYearDate(), "Dinner", "", "+08:00 CST"}, "dinner this week 2012-04-04", Format}, "+08:00 CST", fmt.Sprintf("Dinner This Week on %s", ThisYear())},
    {CrossTime{EFTime{"This Week", ThisYearDate(), "", "06:08:00", "+08:00 CST"}, "14:08 this week 2012-04-04", Format}, "+08:00 CST", fmt.Sprintf("2:08PM This Week on %s", ThisYear())},
    {CrossTime{EFTime{"This Week", "", "Dinner", "06:08:00", "+08:00 CST"}, "dinner 14:08 this week", Format}, "+08:00 CST", fmt.Sprintf("Dinner at 2:08PM This Week")},
    {CrossTime{EFTime{"This Week", ThisYearDate(), "Dinner", "06:08:00", "+08:00 CST"}, "dinner 14:08 this week 2012-4-4", Format}, "+08:00 CST", fmt.Sprintf("Dinner at 2:08PM This Week on %s", ThisYear())},

    // different target zone format
    {CrossTime{EFTime{"", ThisYearDate(), "", "06:08:00", "+08:00 CST"}, "2012-04-04 14:8:00", Format}, "+08:00", fmt.Sprintf("2:08PM on %s", ThisYear())},
    {CrossTime{EFTime{"", ThisYearDate(), "", "06:08:00", "+08:00 CST"}, "2012-04-04 14:8:00", Format}, "", fmt.Sprintf("2:08PM on %s", ThisYear())},
    {CrossTime{EFTime{"", ThisYearDate(), "", "06:08:00", "+08:00 CST"}, "2012-04-04 14:8:00", Format}, "+08:00 PST", fmt.Sprintf("2:08PM on %s", ThisYear())},

    // if Origin, use CrossTime zone
    {CrossTime{EFTime{"", ThisYearDate(), "", "06:08:00", "+08:00 CST"}, "2012-04-04 14:8:00", Format}, "+09:00 PST", fmt.Sprintf("3:08PM +09:00 PST on %s", ThisYear())},
    {CrossTime{EFTime{"", ThisYearDate(), "", "06:08:00", "+08:00 CST"}, "2012-04-04 14:8:00 abc", Origin}, "+09:00 PST", fmt.Sprintf("2012-04-04 14:8:00 abc +08:00 CST")},

    // Time_word (at) Time Zone Date_word (on) Date
    // Only show Zone with Time_word or Time
    {CrossTime{EFTime{"This Week", "", "", "", "+08:00 CST"}, "this week", Format}, "+09:00 PST", fmt.Sprintf("This Week")},
    {CrossTime{EFTime{"", ThisYearDate(), "", "", "+08:00 CST"}, "2012-04-04", Format}, "+09:00 PST", fmt.Sprintf("%s", ThisYear())},
    {CrossTime{EFTime{"", "", "Dinner", "", "+08:00 CST"}, "dinner", Format}, "+09:00 PST", fmt.Sprintf("Dinner +08:00 CST")},
    {CrossTime{EFTime{"", "", "", "06:08:00", "+08:00 CST"}, "14:08", Format}, "+09:00 PST", fmt.Sprintf("3:08PM +09:00 PST")},
    {CrossTime{EFTime{"This Week", ThisYearDate(), "", "", "+08:00 CST"}, "this week 2012 4 4", Format}, "+09:00 PST", fmt.Sprintf("This Week on %s", ThisYear())},
    {CrossTime{EFTime{"This Week", "", "Dinner", "", "+08:00 CST"}, "dinner this week", Format}, "+09:00 PST", fmt.Sprintf("Dinner +08:00 CST This Week")},
    {CrossTime{EFTime{"This Week", "", "", "06:08:00", "+08:00 CST"}, "14:08 this week", Format}, "+09:00 PST", fmt.Sprintf("3:08PM +09:00 PST This Week")},
    {CrossTime{EFTime{"", ThisYearDate(), "Dinner", "", "+08:00 CST"}, "dinner 2012-04-04", Format}, "+09:00 PST", fmt.Sprintf("Dinner +08:00 CST on %s", ThisYear())},
    {CrossTime{EFTime{"", ThisYearDate(), "", "06:08:00", "+08:00 CST"}, "2012-04-04 14:08", Format}, "+09:00 PST", fmt.Sprintf("3:08PM +09:00 PST on %s", ThisYear())},
    {CrossTime{EFTime{"", "", "Dinner", "06:08:00", "+08:00 CST"}, "dinner 14:08", Format}, "+09:00 PST", fmt.Sprintf("Dinner at 3:08PM +09:00 PST")},
    {CrossTime{EFTime{"This Week", ThisYearDate(), "Dinner", "", "+08:00 CST"}, "dinner this week 2012-04-04", Format}, "+09:00 PST", fmt.Sprintf("Dinner +08:00 CST This Week on %s", ThisYear())},
    {CrossTime{EFTime{"This Week", ThisYearDate(), "", "06:08:00", "+08:00 CST"}, "14:08 this week 2012 04 04", Format}, "+09:00 PST", fmt.Sprintf("3:08PM +09:00 PST This Week on %s", ThisYear())},
    {CrossTime{EFTime{"This Week", "", "Dinner", "06:08:00", "+08:00 CST"}, "14:08 dinner this week", Format}, "+09:00 PST", fmt.Sprintf("Dinner at 3:08PM +09:00 PST This Week")},
    {CrossTime{EFTime{"This Week", ThisYearDate(), "Dinner", "06:08:00", "+08:00 CST"}, "14:08 dinner this week 2012 04 04", Format}, "+09:00 PST", fmt.Sprintf("Dinner at 3:08PM +09:00 PST This Week on %s", ThisYear())},

    // different target zone format
    {CrossTime{EFTime{"", ThisYearDate(), "", "06:08:00", "+08:00 CST"}, "2012-04-04 14:8:00", Format}, "+09:00", fmt.Sprintf("3:08PM +09:00 on %s", ThisYear())},
    {CrossTime{EFTime{"", ThisYearDate(), "", "06:08:00", "+08:00 CST"}, "2012-04-04 14:8:00", Format}, "", fmt.Sprintf("2:08PM on %s", ThisYear())},
    {CrossTime{EFTime{"", ThisYearDate(), "", "06:08:00", "+08:00 CST"}, "2012-04-04 14:8:00", Format}, "+09:00 PST", fmt.Sprintf("3:08PM +09:00 PST on %s", ThisYear())},

    // different year
    // Time_word (at) Time Date_word (on) Date
    {CrossTime{EFTime{"", LastYearDate(), "", "", "+08:00 CST"}, "2012-04-04", Format}, "+08:00 CST", fmt.Sprintf("%s", LastYear())},
    {CrossTime{EFTime{"This Week", LastYearDate(), "", "", "+08:00 CST"}, "this week 2012-04-04", Format}, "+08:00 CST", fmt.Sprintf("This Week on %s", LastYear())},
    {CrossTime{EFTime{"", LastYearDate(), "Dinner", "", "+08:00 CST"}, "dinner 2012-04-04", Format}, "+08:00 CST", fmt.Sprintf("Dinner on %s", LastYear())},
    {CrossTime{EFTime{"", LastYearDate(), "", "06:08:00", "+08:00 CST"}, "2012-04-04 14:08", Format}, "+08:00 CST", fmt.Sprintf("2:08PM on %s", LastYear())},
    {CrossTime{EFTime{"This Week", LastYearDate(), "Dinner", "", "+08:00 CST"}, "2012-04-04 dinner this week", Format}, "+08:00 CST", fmt.Sprintf("Dinner This Week on %s", LastYear())},
    {CrossTime{EFTime{"This Week", LastYearDate(), "", "06:08:00", "+08:00 CST"}, "this week 2012-04-04 14:8:00", Format}, "+08:00 CST", fmt.Sprintf("2:08PM This Week on %s", LastYear())},
    {CrossTime{EFTime{"This Week", LastYearDate(), "Dinner", "06:08:00", "+08:00 CST"}, "14:08 this week 2012 04 04", Format}, "+08:00 CST", fmt.Sprintf("Dinner at 2:08PM This Week on %s", LastYear())},
  }

</pre>



输入处理规则（*草稿*）

关键词组：
A组：(所有关键词不区分大小写)
    AM|PM: Midnight, Lunch, Noon, Midday, Night
    AM: Before dawn, Dawn, Daybreak, Sunrise, Morning, Breakfast, Brunch
    PM: Afternoon, Dinner, Supper, Nightfall, Evening
    --: All( -)day, any( )time, some( )time, later, (0-9)(hours/mins/days/weeks/months)(ago/before/later)
B组：
    (at) hh(:mm(:ss))( )(AM, PM)
C组：
    (on) (Next/Last) Monday - Sunday, Mon - Sun
    Tomorrow, Yesterday, The day after tomorrow, tomo, ystd, TDAT
    (on) (mm, Jan-Dec, January-December)./ -dd(./ -yy, yyyy)
    yyyy-W??(-?)
D组：
    weekend, any( -)day, some( -)day, (this/next/last) (week, weekend, month, quarter)
E组：
    (+-)h:mm CST

分析步骤：
首尾单双引号配对 -> origin
空串
去除首尾多于空格
//（起止时间判断）切分' to '前后为独立两串，或匹配'?-?'
解析字符串
A组内AM PM --与B组冲突 -> origin （同时高亮错误字段）
AB组内元素匹配超过两个 -> origin （同时高亮错误字段）
CD组内多个匹配字段日期或星期冲突 -> origin （同时高亮错误字段）
C组内匹配出的日期写入Date，该匹配串不存入Date_word中。
E组内时区与时区缩写冲突 -> origin （同时高亮错误字段）
有剩余字串无法命中关键词 -> origin
