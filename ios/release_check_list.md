#iOS Release Check List
##0 新建发布分支

shell

    #!bash
    git co -b release-a.b.c dev

##1 清理图片

* 使用脚本（unused.js）找出候选图片

shell

    #!bash
    ./unused.js > unused.list

* 去掉依赖项目的图片
* 去掉app store相关的图片
* 余下图片逐一全文查找核对
* 找不到的从项目中删除引用
* 并从git库中删除

shell 

    #!bash
    xargs -a unused.list -d'\n' git rm

##2 检查翻译文档
* 去掉伪翻译：将英语文本全文覆盖伪翻译的语言（目前是繁体中文）

##3 检查并更新版本号   

* 检查Bundle Identifier是com.exfe.app
* 检查版本Version和Build，根据需要升级Version和Build
* 确定发布平台Deployment Target是否需要更新

##4 选择对应的证书

* 正式版本 （上传的时候再签名）

##5 编译项目

确认以下内容

* RKLogLevelDefault在正式版中是RKLogLevelWarning
* 服务器连的是生产服务器exfe.com和shuady.cn
  
##6 升级兼容检查

* 检查和最近的正式版本、最近大版本的升级兼容性，包括登陆、登出后升级的兼容。

##7 准备发布资料
截图、文字更新，设置app为待上传状态

##8 导出并发布版本

测试版本 导出后用脚本（publish.sh）发布到0d0f.com上。<br />
正式版本 导出后用xcode工具上传，确认push能够工作。

##9 提交、合并当前修改并打上版本tag

git cmd

    #!bash
    git commit -m "xxx"
    git checkout master
    git merge --no-ff release-a.b.c
    git tag -a a.b.c
    
    git checkout dev
    git merge --no-ff release-a.b.c
    
    git branch -d release-a.b.c
    
##10 附件
file: usused.sh

    #!bash
    #!/bin/sh
    for i in `find . -name "*.png" -o -name "*.jpg"`; do
        file=`basename -s .jpg "$i" | xargs basename -s .png | xargs basename -s @2x`
        result=`ack -i "$file"`
        if [ -z "$result" ]; then
            echo "$i"
        fi
    done

file: publish.sh

    #!bash
    #!/bin/sh
    project="EXFE"
    server="0d0f.com"
    ext=".ipa"
    ipa=$project$ext
    seed=$(date '+_%y%m%d')
    build=$project$seed$ext
    if [ -f $build ]
    then
        seed=$(date '+_%y%m%d_%H%M%S')
        build=$project$seed$ext
    fi
    echo $project $ipa $build
    cp $ipa $build
    scp $ipa $server:/usr/local/www/exfeweb/static/img/
    scp $build $server:/usr/home/stony/beta/iOS/


