部署文档
=======

相关目录：
--------

- /var/log/gobus: log
- /var/run/gobus: pid文件
- /usr/local/bin: 执行文件目录
- /usr/local/etc/gobus: 配置文件目录
- /usr/local/etc/rc.d: 启动脚本目录

deploy目录下文件：
---------------

- root.ca: apple push服务根证书（push服务的cert和key不在代码库里，由霍炬保存。）
- logrotate.conf: log轮转配置脚本
- syslog.conf: syslog配置脚本
- monit.templ: monit配置模板
- launcher.templ: 启动脚本模板
- init_env.bash: 环境初始化脚本。此脚本会创建/etc/init.d/exfe启动脚本，目的是创建/var/run/gobus目录。仅适用于ubuntu环境。
- gen_monit.bash: 生成monit配置，运行前需要先编译，需要提供运行时uid和gid
- gen_launcher.bash: 生成启动脚本，运行前需要先编译，需要提供启动脚本目录位置
- deploy.bash: 部署脚本，运行前需要先编译

依赖服务：
--------

- monit
- logrotate
- syslog
- redis
- mysql
- go version 1（编译用）

部署过程：
--------

- 安装golang

添加源：

    > sudo add-apt-repository ppa:gophers/go

安装：

    > sudo apt-get install golang-stable

- 复制库

执行：

    > git clone git@dlol.us:exfebus.git

- 编译

执行：

    exfebus> ./all.bash

- 部署环境(以ubuntu为例，其余系统可能要单独安装monit和logrotate，并修改相关配置目录)

执行：

    exfebus/deploy> ./init_env.bash
    exfebus/deploy> ./gen_launcher.bash /usr/local/etc/rc.d
    exfebus/deploy> ./gen_monit.bash 33 33 > /etc/monit/conf.d/exfe # 33是ubuntu用户www-data的uid和gid
    exfebus/deploy> cp logrotate.conf /etc/logrotate.d/exfe
    exfebus/deploy> cp syslog.conf /etc/rsyslog.d/30-exfe.conf
    exfebus/deploy> service monit restart
    exfebus/deploy> service rsyslog restart

- 创建配置文件

执行：

    exfebus> cp exfe.json.example /usr/local/etc/gobus/exfe.json

之后根据环境配置/usr/local/gobus/exfe.json

如果需要token服务，启动mysql，并创建token表（与exfe.json的配置一致）：

    mysql> CREATE TABLE `tokens` (`id` SERIAL NOT NULL, `key` CHAR(32) NOT NULL, `rand` CHAR(32) NOT NULL, `created_at` DATETIME NOT NULL, `expire_at` DATETIME NOT NULL, `data` TEXT NOT NULL);

- 部署并执行

执行：

    exfebus> ./deploy/deploy.bash