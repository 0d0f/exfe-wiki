部署文档
=======

相关目录：
--------

- /exfe/exfebus: 部署目录
- /var/log/exfebus: 日志目录
- /var/run/exfebus: pid文件

目录下文件：
---------------

- root.ca: apple push服务根证书（push服务的cert和key不在代码库里，由霍炬保存。）
- apns\_dev\_cert.pem  apns\_dev\_key.pem: 服务证书
- bin: 执行文件目录
- configure: 配置文件目录
- exfe.json: 配置文件
- exfe.json.example: 配置文件样例
- launch: 重启脚本
- templates: 模版文件

依赖服务：
--------

- daemon
- logrotate
- syslog
- redis
- mysql

部署过程：
--------

- 安装包

添加源：

    > sudo add-apt-repository ppa:gophers/go
    > sudo add-apt-repository ppa:rwky/redis

安装：

    > sudo apt-get install daemon redis mysql golang-stable

- 创建部署目录

执行：

    > sudo su git
    > mkdir -p /exfe/exfebus
    > cd /exfe/exfebus
    > git init
    > git config --add receive.denycurrentbranch ignore
    > touch abc
    > git add abc
    > git commit -m "init"

- 配置推送

将新服务器配置到推送服务器。

    > vi /exfe/exfebus_release/.git/config
    [remote "release"]
        url = git@domain:/exfe/exfebus

- 部署环境(以ubuntu为例)

执行：

    cd /exfe/exfebus
    git checkout -f HEAD
    ./bin/mysql.sh
    cd /etc/lighttpd/conf-enabled/
    sudo ln -s /exfe/exfebus/configure/lighttpd.conf exfebus
    sudo service lighttpd restart
    cd /etc/rsyslog.d/
    sudo ln -s /exfe/exfebus/configure/syslog.conf 30-exfebus.conf
    sudo service rsyslog restart
    cd /etc/logrotate.d/
    sudo ln -s /exfe/exfebus/configure/logrotate.conf exfebus
    cd /etc/init.d
    sudo ln -s /exfe/exfebus/configure/init.d/exfe_bot 
    sudo ln -s /exfe/exfebus/configure/init.d/exfe_queue 
    sudo ln -s /exfe/exfebus/configure/init.d/exfe_service
    sudo update-rc.d exfe_bot defaults
    sudo update-rc.d exfe_queue defaults
    sudo update-rc.d exfe_service defaults

将/exfe/exfebus/configure/crontab的配置写入crontab。

- 部署并执行

执行：

    cd /exfe/exfebus
    sudo ./launch
