#iOS Release Check List
* 清理图片    

使用脚本（unused.js）找出候选图片

    ./unused.js > unused.list

去掉依赖项目的图片    
去掉app store相关的图片    
余下图片逐一全文查找核对    
找不到的从项目中删除引用    
并从git库中删除

    xargs -a unused.list -d'\n' git rm
 
将更改和工程文件一起准备提交

    git add EXFE.xcodeproj/project.pbxproj
    git commit -m "clean unused images"

* 检查并更新版本号   

检查Bundle Identifier    
  测试版本 com.0d0f.exfe    
  正式版本 com.exfe.app    
检查版本Version和Build，根据需要升级Version和Build    
确定发布平台Deployment Target是否需要更新    
以上若有修改则需要提交

    git commit -m "update build and etc."

* 选择对应的证书    

测试版本 eDoctor Healthcare ...
正式版本 暂时没有搞定

* 编译项目    

确认以下内容
编译参数Debug在正式版发布时已经去掉    
服务器连的是生产服务器exfe.com    
项目和依赖项目的log输出关闭，或者设置在高于等于warning级别    

* 准备发布资料
截图、文字更新，设置app为待上传状态

* 导出并发布版本    

测试版本 导出后用脚本（publish.sh）发布到0d0f.com上。
正式版本 导出后用xcode工具上传，确认push能够工作 

* 提交当前修改并打上版本tag    

code

    git push
    git tag
    
Files:    
usused.sh

    #!/bin/sh
    for i in `find . -name "*.png" -o -name "*.jpg"`; do    
        file=`basename -s .jpg "$i" | xargs basename -s .png | xargs basename -s @2x`    
        result=`ack -i "$file"`    
        if [ -z "$result" ]; then    
            echo "$i"
        fi    
    done

publish.sh

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


