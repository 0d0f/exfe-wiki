#iOS Translation Notes

##Generate localized template
Sample cmd
    
    #!bash
    $find . -name \*.m -print0 | xargs -0 genstrings -o en.lproj

Cmd
    
    #!bash
    $find EXFE -name \*.m -print0 |xargs -0 genstrings -o EXFE/en.lproj/
    
##Find most of NSString
RegEx

    \@"\w+ \w+
    
##Replace with
Content:

    before: NSLocalizedString(
    content: @"Strings to be localized"
    afte: , @"Comment")

##Pseudo Translation

http://www.ibabbleon.com/iphone_app_localization.html
http://pbi18n.com/2010/08/pseudo-localization/

Sample cmd

    #!bash
    $ prop2po Localizable.strings en.po
    $ podebug --rewrite=unicode en.po en_rewritten.po
    $ po2prop en_rewritten.po rewritten.strings -t Localizable.strings

Sample cmd

    #!bash
    $ prop2po EXFE/en.lproj/Localizable.strings en.po
	processing 1 files...
	[###########################################] 100%
	$ podebug --rewrite=unicode en.po en_rewritten.po
	processing 1 files...
	[###########################################] 100%
	$ po2prop en_rewritten.po EXFE/zh-Hans.lproj/Localizable.strings -t EXFE/en.lproj/Localizable.strings 
	processing 1 files...
	[###########################################] 100%
	$ rm *.po
    
## Pending files to translate

Util.m
WelcomeView.m
EFHeadView.m 
EXRSVPMenuView.m

Landing xib

## Language filer
en
zh-Hans
zh-Hant
https://developer.apple.com/library/mac/#documentation/MacOSX/Conceptual/BPInternational/Articles/LanguageDesignations.html#//apple_ref/doc/uid/20002144-BBCEGGFF

## Reference
https://developer.apple.com/library/mac/#documentation/Cocoa/Conceptual/LoadingResources/Strings/Strings.html#//apple_ref/doc/uid/10000051i-CH6

http://stackoverflow.com/questions/9895621/best-practice-using-nslocalizedstring

## Problem
"Accepted" = "Ȧƈƈḗƥŧḗḓ"; => "Accepted" = "Ȧccepŧḗḓ";<br />
"Pending" = "Ƥḗƞḓīƞɠ"; => "Pending" = "Pḗƞḓīƞɠ";
