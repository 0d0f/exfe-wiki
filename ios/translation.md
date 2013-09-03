#iOS Translation
## <a id="index"></a>Index
* [Tool](#tool)
	* [Localization Manager](#manager)
	* [Pseudo Translation Tool](#pseudo)
	* [Template](#template)
	* [Plurals](#plurals)
* [Steps](#steps)
    * [1 Find display NSString](#step_1)
    * [2 Edit](#step_2)
    * [3 Generate localized template](#step_3)
    * [4 Translate](#step_4)
* [Misc](#misc)
* [Reference](#ref)

##<a id="tool"></a>Tool
###<a id="manager"></a>Localization Manager
* [Localization Suite](http://www.loc-suite.org/localization-manager/) ✓
* [Linguan](http://www.cocoanetics.com/apps/linguan/)

###<a id="pseudo"></a>Pseudo Translation Tool
#### Reference
[http://www.ibabbleon.com/iphone_app_localization.html] <br />
[]http://pbi18n.com/2010/08/pseudo-localization/]

####Sample cmd

    #!bash
    $ prop2po Localizable.strings en.po
    $ podebug --rewrite=unicode en.po en_rewritten.po
    $ po2prop en_rewritten.po rewritten.strings -t Localizable.strings

####For our project

    #!bash
    $ prop2po EXFE/en.lproj/Localizable.strings en.po
	processing 1 files...
	[###########################################] 100%
	$ podebug --rewrite=unicode en.po en_rewritten.po
	processing 1 files...
	[###########################################] 100%
	$ po2prop en_rewritten.po EXFE/zh-Hant.lproj/Localizable.strings -t EXFE/en.lproj/Localizable.strings 
	processing 1 files...
	[###########################################] 100%
	$ rm *.po

####Bug for Pseudo

    // 错误: 特征 key尾部包含空格 比如 查找 " " = "
    "EXFE " " = "ḖẊƑḖ ";
    // 修正: 去掉重复的空格和双引号
    "EXFE " = "ḖẊƑḖ";

    // 错误: 特征 key包含双引号 比如 查找 "" ＝ 或者 ＝ ""
    ""%@"" = ""%@"";
    // 修正: key的双引号转义
    "\"%@\"" = "\"%@\"";
    
    // 错误: 特征 key包含双引号 查找 一行多于4个双引号
    "Sorry, something is technically wrong in the "cloud", we’re fixing it up." = "Şǿřřẏ, şǿḿḗŧħīƞɠ īş ŧḗƈħƞīƈȧŀŀẏ ẇřǿƞɠ īƞ ŧħḗ "ƈŀǿŭḓ", ẇḗ’řḗ ƒīẋīƞɠ īŧ ŭƥ.";
    // 修正: key的双引号转义
    "Sorry, something is technically wrong in the \"cloud\", we’re fixing it up." = "Şǿřřẏ, şǿḿḗŧħīƞɠ īş ŧḗƈħƞīƈȧŀŀẏ ẇřǿƞɠ īƞ ŧħḗ \"ƈŀǿŭḓ\", ẇḗ’řḗ ƒīẋīƞɠ īŧ ŭƥ.";
    
###<a id="template"></a>Template
* [CocoaTemplateEngine](https://github.com/xhan/CocoaTemplateEngine) ✓
* [GRMustache](https://github.com/groue/GRMustache)

###<a id="plurals"></a>Plurals
* https://github.com/Smartling/ios-i18n ✓
	
	[Adopting the Smartling iOS Plurals Library](http://support.smartling.com/entries/23420757-Adopting-the-Smartling-iOS-Plurals-Library)
	
	We need a new tool for genstrings:[genstrings2](http://www.cocoanetics.com/2012/01/genstrings2/) [DTLocalizableStringScanner](https://github.com/Cocoanetics/DTLocalizableStringScanner) 
* https://github.com/junjie/JJPluralForm
* https://github.com/mattt/TTTLocalizedPluralString

[^Index](#index)
##<a id="steps"></a>Steps
### <a id="step_1"></a>1. Find display NSString

* 包含空格的大多数都是句子或者词组，一般用来显示

    \@"\w+ \w+
* 包含单个单词，大写开头

    @"[A-Z]\w*"


### <a id="step_2"></a>2. Edit
Content:

    Insert before: NSLocalizedString(
    NSString:      @"Strings to be localized"
    Insert after:  , @"Comment")

### <a id="step_3"></a>3. Generate localized template
####Sample cmd
    
    #!bash
    $find . -name \*.m -print0 | xargs -0 genstrings -o en.lproj

####For our project
    
    #!bash
    $find EXFE -name \*.m -print0 |xargs -0 genstrings -o EXFE/en.lproj/

Tips:

* 增量追加 －a (不建议使用)
* 使用版本工具对比
* -s 可以自定义替换的关键词，比如 -s MyLocalString 则搜索MyLocalString和MyLocalStringFromTable，而不是NSLocalizedString和NSLocalizedStringFromTable
* 目前无法支持复数方案

### <a id="step_4"></a>4. Translate

* Download [Localization Suite](http://www.loc-suite.org/pub/stable/Localization%20Suite.tbz). There are three apps in the suite: Localization Manager, Localizer and Localization Dictionary.
* Open shuady.ldb by Localization Manager
* Select the language to edit.

[^Index](#index)
## <a id="misc"></a>Misc 
### Pending files to translate
Util.m
WelcomeView.m
EXRSVPMenuView.m

Landing xib

### Language filer
* en
* zh-Hans
* zh-Hant

[Language Designations](https://developer.apple.com/library/mac/#documentation/MacOSX/Conceptual/BPInternational/Articles/LanguageDesignations.html#//apple_ref/doc/uid/20002144-BBCEGGFF)

[^Index](#index)
## <a id="ref"></a>Reference
* [Loading Resources](https://developer.apple.com/library/mac/#documentation/Cocoa/Conceptual/LoadingResources/Strings/Strings.html#//apple_ref/doc/uid/10000051i-CH6)
* [Best practice using nslocalizedstring](http://stackoverflow.com/questions/9895621/best-practice-using-nslocalizedstring)

[^Index](#index)