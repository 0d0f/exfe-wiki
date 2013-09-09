# git分支管理策略
## 来源参考
[Git分支管理策略 - 阮一峰](http://www.ruanyifeng.com/blog/2012/07/git.html)

## 方案（草稿）
###主要分支
* Master 主版本发布 对应线上
* Develop 开发支线，我们命名简写为dev 对应黑盒

Git创建Develop分支的命令：

    # 从master创建dev分支
    git checkout -b dev master
    # 将本地分支推送到origin
    git push origin dev:dev
    # 绑定本地和服务器上的对应分支
    git branch --set-upstream dev origin/dev

切换develop分支

    git checkout dev

将develop的结果合并到master （no-ff）

    # 切换到Master分支
    git checkout master
    # 对Develop分支进行合并
    git merge --no-ff dev

### 临时分支
其他临时分支前缀 根据情况对应

* 功能（feature）分支，命名方式为feature-功能名 主要对应Panda
* 预发布（release）分支，命名方式为release-版本号 主要对应黑盒
* 修补bug（fixbug）分支，命名方式为fixbug-bug号 或者 fixbug-bug名字 主要对应线上

#### 功能（feature）分支
创建一个功能分支：

    #!bash
    git checkout -b feature-x dev

共享分支到上游服务器（可选）

    # 将本地分支推送到origin
    git push origin feature-x:feature-x
    # 绑定本地和服务器上的对应分支
    git branch --set-upstream feature-x origin/feature-x

开发完成后，将功能分支合并到develop分支：

    #!bash
    git checkout dev
    git merge --no-ff feature-x

删除feature分支：

    #!bash
    git branch -d feature-x
    
#### 预发布（release）分支
创建一个预发布分支：

    #!bash
    git checkout -b release-a.b.c dev

共享分支到上游服务器（可选）

    # 将本地分支推送到origin
    git push origin release-a.b.c:release-a.b.c
    # 绑定本地和服务器上的对应分支
    git branch --set-upstream release-a.b.c origin/release-a.b.c

确认没有问题后，合并到master分支：

    #!bash
    git checkout master
    git merge --no-ff release-a.b.c
    # 对合并生成的新节点，做一个标签
    git tag -a a.b.c
    
再合并到develop分支：

    #!bash
    git checkout dev
    git merge --no-ff release-a.b.c

最后，删除预发布分支：

    #!bash
    git branch -d release-a.b.c

#### 修补bug（fixbug）分支
创建一个修补bug分支：

    #!bash
    git checkout -b fixbug-### master
    
共享分支到上游服务器（可选）

    # 将本地分支推送到origin
    git push origin fixbug-###:fixbug-###
    # 绑定本地和服务器上的对应分支
    git branch --set-upstream fixbug-### origin/fixbug-###

修补结束后，合并到master分支：

    #!bash
    git checkout master
    git merge --no-ff fixbug-###
    git tag -a 0.1.1

再合并到develop分支：

    #!bash
    git checkout dev
    git merge --no-ff fixbug-###

最后，删除"修补bug分支"：

    #!bash
    git branch -d fixbug-###

## Git配置建议
### ~/.gitconfig

    #!ini
    [user]
    	name = <user name>
    	email = <user@email>
    [alias]
    	co = checkout
    	ci = commit
    	st = status
    	br = branch
    	pl = pull
    	ps = push
    	sm = submodule
    	df = diff
    	dfc = diff --cached
    	oneline = log --pretty=oneline --since='2 days ago'
    	onelog = log -p -1
    	tree = log --graph --oneline
    [color]
    	status = auto
    	branch = auto
    	ui = auto
    [core]
    	excludesfile = /Users/stony/.gitignore_global
    
### ~/.gitignore_global

    *~
    .DS_Store
    *.lock
    *.swp
    *.out

### &lt;GIR_PROJECT_ROOT>/.gitignore

    # Xcode
    build/*
    *.pbxuser
    !default.pbxuser
    *.mode1v3
    !default.mode1v3
    *.mode2v3
    !default.mode2v3
    *.perspectivev3
    !default.perspectivev3
    *.xcworkspace
    !default.xcworkspace
    xcuserdata
    
    # old skool
    .svn
    
    # osx noise
    .DS_Store
    profile