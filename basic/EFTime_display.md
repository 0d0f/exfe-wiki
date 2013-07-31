## EFTime显示方案

### Origin原文输出
  * 时间标题显示Origin，时间文本空。
    * Date和Time有效时，时间文本显示相对时间（距当前时刻的间隔）。
  * 单时间文本（无时间标题只显示时间文本的场景，如·X· list列表中）时显示Origin。
  * 输出Origin时如果首尾字符都为单引号'或双引号"，则不显示引号。

### 有效字段：Date、Time
  * 时间标题根据Date和Time显示相对时间。
  * 时间文本格式：TimeWord Time Date DateWord。例：Dinner 6:30PM Fri, Apr 8

### 有效字段：Date
  * 时间标题根据Date和Time显示相对时间。
  * 时间文本格式：TimeWord, Date DateWord。例：Dinner, Fri, Apr 8

### 有效字段：Time
  * 时间标题格式：TimeWord Time, DateWord。例：Dinner 6:30PM, Someday
  * 时间文本空。单时间文本时格式同上。

### 有效字段：DateWord或TimeWord
  * 时间标题格式：TimeWord, DateWord。例：Dinner, Someday
  * 时间文本空。单时间文本时格式同上。

### 时区判断
  * 只要Timezone与当前设备时区不同，就在时间正文结尾显示时区信息。例：(+8:00 CST Beijing)

### Date、Time字段格式
  * Date字段可根据不同场景和用户偏好指定格式：“2011-4-8”、“Apr 8”、“Fri，Apr 8”、“Friday, April 8”
  * Time字段可根据不同场景和用户偏好指定格式：“6PM”、“6:00PM”、“18:00”
  * 年份与当前时间不同时，日期要显示年份。例：Fri, Apr 8 2011
