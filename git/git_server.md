t## Git User:
  * user: git
  * group: git

## install [gitolite](https://github.com/sitaramc/gitolite):

### Server:
  * login as `git`
    > ssh git@192.168.1.88
  * sudo -s
  * cd $HOME/.ssh
  * ssh-keygen -t rsa -f admin
  * cp admin.pub /exfe/exfegit/
  * # scp admin.pub admin@192.168.1.88:/exfe/exfegit/
  * cd $HOME
  * git clone git://github.com/sitaramc/gitolite
  * mkdir -p $HOME/bin
  * gitolite/install -to $HOME/bin
  * $HOME/bin/gitolite setup -pk $HOME/.ssh/admin.pub
  * vim .ssh/config # client config
    > Host exfegit
    >   User admin
    >   Hostname 192.168.1.88
    >   Port 22
    >   IdentityFile ~/.ssh/gitolite
  * git clone exfegit:gitolite-admin
  * mkdir repos && cd repos
  * git clone exfegit:gitolite-admin
  * cd gitolite-admin
  * # vim conf/gitolite.conf
  * # add user-pubkey to keydir
  * cd ..

### Testing:
  * ssh git@192.168.1.88 help
  * git clone git@192.168.1.88:testing

### Add exfewiki repo and setup wiki system
  * http://wiki0d0f.com
  * cd /home/git/repos/wiki
  * /usr/local/bin/markdoc init /home/git/repos/wiki --vcs-ignore git
  * /usr/local/bin/markdoc build
  * /usr/local/bin/markdoc serve
  * git init
  * git remote add origin git:wiki
  * cd /home/git/repos && git clone git:wiki

## Thanks to:
  * http://blog.countableset.ch/2012/04/29/ubuntu-12-dot-04-installing-gitolite-and-gitweb/
  * http://www.momo-lab.net/saru/
  * https://wiki.archlinux.org/index.php/Gitolite
  * http://www.linuxforu.com/2011/01/gitolite-specify-complex-access-controls-git-server/
  * http://www.bigfastblog.com/gitolite-installation-step-by-step
  * http://www.bigfastblog.com/install-gitolite-to-manage-your-git-repositories
  * http://automatica.com.au/2011/01/setup-git-server-on-mac-osx-server/
  * http://silas.sewell.org/blog/2011/01/08/setup-gitolite-on-ubuntu/
  * http://demonastery.org/2012/09/a-hooking-system-for-gitolite/
