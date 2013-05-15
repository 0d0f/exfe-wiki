# Deploy
    author: Leask Huang
    created date: 2013-05-15
    updated date: 2013-05-15


## Config UTC timezone

        #!bash
        # echo "UTC" | tee /etc/timezone
        # dpkg-reconfigure --frontend noninteractive tzdata


## Upgrade system

        # apt-get update
        # apt-get upgrade
        # apt-get dist-upgrade


## Install mysql

        #!bash
        # apt-get install mysql-server mysql-client

### /etc/mysql/my.cnf

        [mysqld]
        default-time-zone='+00:00'
        init_connect='SET NAMES utf8mb4'
        collation-server='utf8mb4_unicode_ci'
        character-set-server='utf8mb4'

### Restore data

        #!bash
        # mysql
        > source exfe_schema_*******.sql
        > source exfe_data_*******.sql
        > source exfe_services_schema_*******.sql
        > source exfe_services_data_*******.sql
        > grant all privileges on exfe.* to 'exfe'@'%' identified by '*******';
        > grant all privileges on exfe_services.* to 'exfe'@'%' identified by '*******';
        > FLUSH PRIVILEGES;


## Install redis

        #!bash
        # apt-get install redis-server

### redis_cache.conf

        pidfile /var/run/redis_cache.pid
        port 6380
        dbfilename dump_cache.rdb
        maxmemory 52428800
        maxmemory-policy volatile-lru


## Install lighttpd

        #!bash
        # apt-get install lighttpd

### /etc/lighttpd/lighttpd.conf

        server.modules = (
            "mod_access",
            "mod_alias",
            "mod_compress",
            "mod_redirect",
            # changed by @leask {
            "mod_fastcgi",
            "mod_setenv",
            "mod_rewrite",
            # }
        )

### /exfe/exfe_lighttpd.conf

        fastcgi.server = (
            ".php" => (
                "localhost" => (
                    "min-procs" => 8,
                    "max-procs" => 20,
                    "socket" => "/tmp/php-fastcgi.socket",
                    "bin-path" => "/usr/bin/php-cgi"
                )
            )
        )

        $SERVER["socket"] == "96.126.122.51:443" {
            ssl.engine    = "enable"
            ssl.ca-file   = "/exfe/certs/ca-certs.crt"
            ssl.pemfile   = "/exfe/certs/server.pem"
            ssl.use-sslv2 = "disable"
            setenv.add-environment = ( "HTTPS" => "on" )

            $HTTP["host"] =~ "^exfe.com|api.exfe.com$" {
                server.document-root = "/exfe/exfeweb"
                server.error-handler-404 = "index.php?_route=/error/404"
                server.error-handler-500 = "views/error/500.html"
                url.rewrite-once = (
                    "^/static/(.*)$" => "/static/$1",
                    "^/eimgs/(.*)$" => "/eimgs/$1",
                    "^/404$" => "index.php?_route=/error/404",
                    "^/500$" => "views/error/500.html",
                    "^.*(\?.*)$" => "index.php$1",
                    "^.*$" => "index.php",
                )
            }

        } else $HTTP["host"] == "img.exfe.com" {
            server.document-root="/exfe/upload"
            setenv.add-response-header = (
                "access-control-allow-origin"      => "http://exfe.com",
                "access-control-allow-credentials" => "true",
            )
        } else $HTTP["host"] == "www.exfe.com" {
            url.redirect = ( "^/(.*)" => "https://exfe.com/$1" )
        } else $HTTP["host"] =~ "(.*)" {
            url.redirect = ( "^/(.*)" => "https://%1/$1" )
        }


## Install php

        #!bash
        # add-apt-repository ppa:ondrej/php5
        # install php5-cli php5-cgi php5-curl php5-mysqlnd php5-gd php5-intl php5-dev

### php.ini

        date.timezone = 'UTC'
        magic_quotes_gpc = Off
        post_max_size = 15M
        upload_max_filesize = 15M
        zlib.output_compression = On
        session.cookie_domain = '.exfe.com'
        log_errors = On
        error_log = /var/log/php.log


## Install phpredis

        #!bash
        # git clone https://github.com/nicolasff/phpredis.git
        # cd phpredis
        # phpize
        # ./configure
        # make
        # make install


## Install git

        #!bash
        # apt-get install git
        # su git
        $ git config  --global  user.email "pandaci@exfe.com"
        $ git config --global user.name "Panda Ci"


## Install make

        #!bash
        # apt-get install make


## Config sshd

### /etc/ssh/sshd_config

        PasswordAuthentication no


## deploy codes

        #!bash
        # mkdir /exfe
        # chown git:git /exfe
        # sudo su git
        $ cd /exfe
        $ mkdir exfeweb
        $ cd exfeweb
        $ git init
        $ git config --add receive.denycurrentbranch ignore
        $ touch love
        $ git add .
        $ git commit -am 'Hello World!'







//////////////////////////////// icu OLD OLD OLD //////////////////////////////

    a php增加 --enable-intl 编译，实现先安装icu-project http://www.icu-project.org/

    b config.php 里面增加了 define('INTL_RESOURCES', '/Users/huoju/www/exfe/intl'); 用来定义资源文件所在位置

    c common.php 里面增加了

    $locale=Locale::acceptFromHttp($_SERVER['HTTP_ACCEPT_LANGUAGE']);
    $exfe_res = new ResourceBundle($locale, INTL_RESOURCES);

    用来根据locale载入资源。目前是根据浏览器判断，因为界面上还没有切换语言的位置。但未来应该把这些从common移动到其他地方，因为这个位置还没法读数据库和设置cookie。

    d 在intl目录里面，root.txt和zh.txt是资源文件，root是默认的，用英文，zh是中文。格式一看就明白。在一个table里面中英文字段要对应，不然会有显示成空白的情况，比如 gather 就是一个table，其中字段要一致。现在我是按照一个view文件一个table这样来的。完全不存在的table会自动继承root的资源，反而无所谓。

    e views/x/gatherView.php 是我目前修改了一点的模版

    首先 <?php global $exfe_res;?>  把common里面的全局变量声明了，然后 <?php echo $exfe_res["gather"]["Write_some_words_about_this_X"];?>  这样就是本地化的资源串了。