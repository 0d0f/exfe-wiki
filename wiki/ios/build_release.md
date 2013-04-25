# iOS Build and Release Process

##Repo
###Check out Repo
code

    #!shell
    git clone git@git.0d0f.com:exfeiosv2
    
默认库位置，项目库名字exfeiosv2
###Init submodules
code

    cd exfeiosv2/
    git submodule update --init --recursive
    
初始化子模块要加上递归开关
## Shell
### make
code
    
    ./make.sh 0d0f|pilot
    
包含了2个脚本
build.sh
和
publish.sh
目前没有做出错检查，也就是说，如果build过程失败，publish会把上一个版本的内容上传，因此要确保能够正确Build，或者清空临时文件夹builds/下面的ipa。

### build
code

    ./build.sh -p 0d0f|pilot|exfe
    
### publish
code

    ./publish.sh 0d0f|pilot|exfe
    
## 发布位置
网页入口 [app.0d0f.com](http://app.0d0f.com/)    
服务器 app.0d0f.com 即 panda.0d0f.com    
路径 [/0d0f/app/ios/](ssh://app.0d0f.com/0d0f/app/ios/)    

## 配置环境
###证书
测试服务器使用eDoctor私钥，由yashure提供，Stony持有和管理，hj备份持有。    
正式服务器使用的是exfe的私钥。    
项目分为3个Targets，分别叫做EXFE、0d0f、Pilot。

EXFE是对应线上服务器，目前不支持Push，在实际开发的时候，Debug可以更改服务器，Release作为上线版本的编译环境。Identifier是com.exfe.app

0d0f对应黑盒服务器0d0f.com，支持Push，Identifier是com.0d0f.exfe，用来作为主要的开发的预览版本。

Pilot对应Panda服务器panda.0d0f.com，支持Push，Identifier是com.0d0f.production，主要用来开发测试新功能使用的版本。

导入如下iOS Profile(Provision Profile)    
0d0f (exfe)    
0d0f2 (0d0f)    
0d0fproduction (pilot)    
后，所有证书会通过Identifier自动选择匹配。
所有服务器可以通过增加DEBUG和服务器代号的宏定义来更改服务器，但是这样Push功能会失效。


###工程文件
工程的3个target，对应3个不同的Identifier，并有3个同名的scheme分别对应编译target的信息。
###服务器
在Panda上配置相应帐号和权限
建立帐号
上传公钥
确认文件夹权限

