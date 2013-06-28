#iOS Translation Notes

##Generate localized template
Code
    
    #!bash
    find . -name "*.m" -print0 | xargs -0 genstrings -o en.lproj
    
##Find most of NSString
Code

    Regex: \@"\w+ \w+
    
##Replace with
Code

    before: NSLocalizedString(
    content: @"Strings to be localized"
    afte: , @"Comment")

##Pseudo Translation

http://www.ibabbleon.com/iphone_app_localization.html
http://pbi18n.com/2010/08/pseudo-localization/

Code

    $ prop2po Localizable.strings en.po
    $ podebug --rewrite=unicode en.po en_rewritten.po
    $ po2prop en_rewritten.po rewritten.strings -t Localizable.strings
    
## Pending files to translate

Util.m
WelcomeView.m
EFHeadView.m 
EXRSVPMenuView.m

## Language filer
en
zh-Hans
zh-Hant
https://developer.apple.com/library/mac/#documentation/MacOSX/Conceptual/BPInternational/Articles/LanguageDesignations.html#//apple_ref/doc/uid/20002144-BBCEGGFF

## Reference
https://developer.apple.com/library/mac/#documentation/Cocoa/Conceptual/LoadingResources/Strings/Strings.html#//apple_ref/doc/uid/10000051i-CH6
