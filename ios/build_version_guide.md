# iOS Build Version Guide

当前有三个 build 相关的参数
- Version
- Build
- EXFE-build

其中 Version 和 Build 分别用于发布，EXFE-build 用于测试发布版本时的版本标记。

## Version
App 的版本号，如 2.1.1。

## Build
一个只可递增的纯数字，其实已无意义。

## EXFE-build
基于构建日期的版本内部版本号
例：
m2B35P

- m: mobile
- 2: 第二个大版本
- B: 第二个大版本的第 2 个版本
- 35P: 日期，指 2013/5/25

Shell Sample

    #!bash
    EXFE_VER=m2B    for TEMP in $(expr $(date '+%y') - 10) $(expr $(date '+%m')) $(expr $(date '+%d'))    do      if [ $TEMP -ge 10 ]        then          TEMP=$(printf \\$(printf '%03o' $(expr 55 + $TEMP)))      fi      EXFE_VER=$EXFE_VER$TEMP    done