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
  * server: white.d0f0.com
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
  * 本地也可以单独配置: ~/.ssh/config

    <pre>
    Host git
      User git
      Hostname git.0d0f.com
      #Hostname 192.168.1.88
      PreferredAuthentications publickey
      IdentityFile ~/.ssh/xwhite/id_rsa # 注意这里你的私钥文件路径
    </pre>
