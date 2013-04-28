Readme
------

## Repositories
  - git@git.0d0f.com:exfeandroid
  - git@git.0d0f.com:exfebus
  - git@git.0d0f.com:exfeiosv1
  - git@git.0d0f.com:exfeiosv2
  - git@git.0d0f.com:exfelight
  - git@git.0d0f.com:exfeweb
  - git@git.0d0f.com:wiki
  - git@git.0d0f.com:gitolite-admin
  - git@git.0d0f.com:devops

  - git@git.0d0f.com:0d0f2b

## WIki http://wiki.0d0f.com/0d0fwiki:
  * web: [wiki.0d0f.com](http://wiki.0d0f.com)
  * git: [git.0d0f.com](git.0d0f.com)
    例如: wiki project

    <pre>
    git@git.0d0f.com:wiki
    或者 自定义 client: ~/.ssh/config
    git:wiki
    </pre>

## 组件：
  * server: panda.d0f0.com
    * user: git
    * group: git

  * git-server: [Gitolite](http://sitaramc.github.com/gitolite)
  * wiki-system: [Markdoc](http://markdoc.org/)

## 本地初始化:
  * 提供一个 user.pub 公钥
  * 测试链接状态: ssh git@git.0d0f.com
  * git clone git@git.0d0f.com:wiki 或者 git clone git:wiki
  * git clone git@git.0d0f.com:gitolite-admin 或者 git clone git:gitolite-admin
  * 查看 remote : git remote -v
  * 更改 remove: git remote set-url origin git@git.0d0f.com:exfebus
  * 本地也可以单独配置: ~/.ssh/config

    <pre>
    Host git
      User git
      Hostname git.0d0f.com
      #Hostname 192.168.1.88
      PreferredAuthentications publickey
      #注意这里你的私钥文件路径
      IdentityFile ~/.ssh/xwhite/id_rsa
    </pre>

## Others
  * 文件命名：始终用小写   
如果文件名描述得不够明确，第一行使用#开头的一级标题，可以用来替代在列表的文件名显示   
  * 代码块采用缩进4个空格来展示。
  * 行末带三个空格可以换行\<br/>而不是分段\<p>\</p>

## Defenders
  - @leask
  - @cfd
