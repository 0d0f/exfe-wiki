# Deploy
    author: Leask Huang
    created date: 2013-05-15
    updated date: 2013-07-01


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
        > create user exfe@localhost identified by '******';
        > grant all privileges on exfe.* to 'exfe'@'%' identified by '*******';
        > grant all privileges on exfe_services.* to 'exfe'@'%' identified by '*******';
        > FLUSH PRIVILEGES;


## Install redis

        #!bash
        # add-apt-repository ppa:rwky/redis
        # apt-get update
        # apt-get install redis-server

### /etc/redis/redis-cache.conf

        pidfile /var/run/redis-cache.pid
        port 6380
        logfile /var/log/redis/redis-cache.log
        # save 900 1
        # save 300 10
        # save 60 10000
        dbfilename dump-cache.rdb
        maxmemory 128000000
        maxmemory-policy allkeys-lru

### /etc/init/redis-cache-server.conf

        # redis-cache-server - Redis Datastore Server, for cache
        #
        # Redis is a key value in memory persistent datastore

        start on (local-filesystems and runlevel [2345])
        stop on runlevel [016]
        respawn
        limit nofile 20000 65000
        expect fork
        pre-start script
        mkdir -p /var/run/redis
        chown redis:redis /var/run/redis
        end script
        exec start-stop-daemon --start --chuid redis:redis --pidfile /var/run/redis/redis-cache.pid --umask 007 --exec /usr/bin/redis-server -- /etc/redis/redis-cache.conf


## Install git

        #!bash
        # apt-get install git
        # adduser git
        # su git
        $ git config --global user.email "pandaci@exfe.com"
        $ git config --global user.name "Panda Ci"


## Install php

        #!bash
        # add-apt-repository ppa:ondrej/php5
        # apt-get update
        # apt-get install php5-fpm php5-cli php5-curl php5-mysqlnd php5-gd php5-intl php5-dev

### /etc/php5/fpm/php.ini

        date.timezone = 'UTC'
        # magic_quotes_gpc = Off
        post_max_size = 15M
        upload_max_filesize = 15M
        zlib.output_compression = On
        zlib.output_handler = On
        session.cookie_domain = '.exfe.com'
        error_reporting = E_ALL
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
        # cp rpm/redis.ini /etc/php5/mods-available/
        # ln -s /etc/php5/mods-available/redis.ini /etc/php5/fpm/conf.d/20-redis.ini
        # ln -s /etc/php5/mods-available/redis.ini /etc/php5/cli/conf.d/20-redis.ini


## deploy codes

        #!bash
        # mkdir /exfe
        # chown git:git /exfe
        # sudo su git
        $ cd /exfe

        $ mkdir exfebus
        $ cd exfebus
        $ git init
        $ git config --add receive.denycurrentbranch ignore
        $ touch world
        $ git add .
        $ git commit -am 'Hello World!'

        $ cd ..
        $ mkdir exfeweb
        $ cd exfeweb
        $ git init
        $ git config --add receive.denycurrentbranch ignore
        $ touch love
        $ git add .
        $ git commit -am 'Hello World!'

        $ cd ..
        $ mkdir exfelight
        $ cd exfelight
        $ git init
        $ git config --add receive.denycurrentbranch ignore
        $ touch love
        $ git add .
        $ git commit -am 'Hello World!'

    add git repository to build server.

        > vi /exfe/exfebus_release/.git/config
        > vi /exfe/exfeweb_release/.git/config
        > vi /exfe/exfelight_release/.git/config
        [remote "release"]
            url = git@domain:/exfe/exfebus

    push code.

### deploy exfebus

        # su git
        $ cd /exfe/exfebus
        $ git checkout -f HEAD
        // edit exfe.json
        $ ./bin/mysql.sh
        $ su

        # cd /usr/lib/lighttpd/
        # ln -s /exfe/exfebus/mod_mysql_obj.so

        # cd /etc/rsyslog.d/
        # ln -s /exfe/exfebus/configure/syslog.conf 30-exfebus.conf
        # service rsyslog restart

        # cd /etc/logrotate.d/
        # ln -s /exfe/exfebus/configure/logrotate.conf exfebus

        # cd /etc/init.d
        # ln -s /exfe/exfebus/configure/init.d/exfe_bot
        # ln -s /exfe/exfebus/configure/init.d/exfe_queue
        # ln -s /exfe/exfebus/configure/init.d/exfe_service
        # update-rc.d exfe_bot defaults
        # update-rc.d exfe_queue defaults
        # update-rc.d exfe_service defaults

## Install Nginx

        #!bash
        # add-apt-repository ppa:nginx-openresty/stable
        # apt-get update
        # apt-get install nginx-openresty


### /etc/nginx/site-enable/exfe

        server {
            listen [::]:80 default_server;

            ssl on;
            ssl_certificate cert.pem;
            ssl_certificate_key cert.key;
        
            ssl_session_timeout 5m;
        
            ssl_protocols SSLv3 TLSv1;
            ssl_ciphers ALL:!ADH:!EXPORT56:RC4+RSA:+HIGH:+MEDIUM:+LOW:+SSLv3:+EXP;
            ssl_prefer_server_ciphers on;

            server_name 0d0f.com api.0d0f.com;
            root /exfe/exfeweb;
            index index.php;
            access_log /var/log/nginx/exfe-access.log;
            error_log /var/log/nginx/exfe-error.log;

            gzip             on;
            gzip_min_length  1000;
            gzip_proxied     any;
            gzip_types       "application/x-javascript" "application/javascript" "application/json" "text/css" "text/plain";

            error_page 404 /index.php?_route=/error/404;
            error_page 500 /views/error/500.html;

            access_by_lua '
                local args = ngx.req.get_uri_args()
                local token = args["token"]
                if token == "" then
                    token = args["t"]
                end
                -- ngx.log(ngx.ERR, "token: ", token)
                if not token or token == "" then
                    return
                end

                local mysql = require "resty.mysql"
                local db, err = mysql:new()
                if not db then
                    ngx.log(ngx.ERR, "failed to instantiate db: ", err)
                    return
                end
                db:set_timeout(1000)

                local ok, err, errno, sqlstate = db:connect{
                    host = "127.0.0.1",
                    port = 3306,
                    database = "exfe_services",
                    user = "root",
                    password = "",
                    max_packet_size = 1024 * 1024 }
                if not ok then
                    ngx.log(ngx.ERR, "failed to connect: ", err, ": ", errno, " ", sqlstate)
                    return
                end
                local s = "SELECT `scopes`, `user_id`, `client`, `expires_at`, `touched_at`, `data` FROM `tokens` WHERE `key`=\\""..token.."\\" LIMIT 1"
                -- ngx.log(ngx.ERR, "sql: ", s)
                local res, err, errno, sqlstate = db:query(s)
                if not res then
                    ngx.log(ngx.ERR, "bad result: ", err, ": ", errno, ": ", sqlstate, ".")
                    return
                end
                -- local cjson = require "cjson"
                -- ngx.log(ngx.ERR, "token data: ", cjson.encode(res))
                if #res == 0 then
                    return
                end
                res = res[1]
                ngx.req.set_header("Exfe-Auth-Version", "1")
                ngx.req.set_header("Exfe-Auth-Scopes", res["scopes"])
                ngx.req.set_header("Exfe-Auth-User-Id", res["user_id"])
                ngx.req.set_header("Exfe-Auth-Client", res["client"])
                ngx.req.set_header("Exfe-Auth-Expires-At", res["expires_at"])
                ngx.req.set_header("Exfe-Auth-Touched-At", res["touched_at"])
                ngx.req.set_header("Exfe-Auth-Data", res["data"])
            ';

            location /v3/routex/_inner {
                return 404;
            }
            location /v3/routex {
                proxy_pass http://127.0.0.1:23333;
                proxy_buffering off;
                proxy_cache off;
                break;
            }
            location ~ \.php$ {
                fastcgi_split_path_info ^(.+\.php)(/.+)$;
                fastcgi_pass unix:/var/run/php5-fpm.sock;
                fastcgi_index index.php;
                include fastcgi_params;
                break;
            }

            add_header Cache-Control "public, must-revalidate";

            location /static {
                expires 1y;
                break;
            }
            location /eimgs {
                expires 1y;
                break;
            }
            location / {
                rewrite ^/404$ /index.php?_route=/error/404;
                rewrite ^/500$ /views/error/500.html;
                rewrite ^.*(/?.*)$ /index.php$1;
                rewrite ^.*$ /index.php;
            }
        }

        server {
            listen [::]:80;
            server_name img.0d0f.com;
            root /exfe/upload;

            add_header Access-Control-Allow-Origin "http://0d0f.com";
            add_header Access-Control-Allow-Credentials "true";
            add_header Cache-Control "public, must-revalidate";
            expires 1y;
        }

        server {
            listen [::]:80;
            server_name www.0d0f.com;
            return 301 http://0d0f.com$request_uri;
        }


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
            "mod_accesslog",
            "mod_expire",
            # }
            # Changed by @lzh {
            "mod_mysql_obj",
            # }
        )

        compress.filetype = (
            "application/javascript",
            "text/css",
            "text/html",
            "text/plain"
        )


### /exfe/exfe_lighttpd.conf

        mysql_obj.host = "127.0.0.1"
        mysql_obj.port = 3306
        mysql_obj.user = "root"
        mysql_obj.pass = ""
        mysql_obj.sock = ""
        mysql_obj.db = "exfe_services"

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
            mysql_obj.insert = (
                "query" => ( "token", "t" ),
                "table" => "tokens",
                "key"   => "key",
                "map"   => (
                    "scopes"     => "Exfe-Auth-Scopes",
                    "user_id"    => "Exfe-Auth-User-Id",
                    "client"     => "Exfe-Auth-Client",
                    "expires_at" => "Exfe-Auth-Expires-At",
                    "touched_at" => "Exfe-Auth-Touched-At",
                    "data"       => "Exfe-Auth-Data",
                ),
                "extra" => (
                    "Exfe-Auth-Version" => "1",
                )
            )

            proxy.server  = (
                "/v3/routex" => ((
                    "host"  =>"127.0.0.1",
                    "port"  =>"23333"
                ))
            )

            ssl.engine    = "enable"
            ssl.ca-file   = "/exfe/certs/ca-certs.crt"
            ssl.pemfile   = "/exfe/certs/server.pem"
            ssl.use-sslv2 = "disable"
            setenv.add-environment = ( "HTTPS" => "on" )
            server.reject-expect-100-with-417 = "disable"
            $HTTP["host"] =~ "^(exfe.com|api.exfe.com)$" {
                server.document-root = "/exfe/exfeweb"
                server.error-handler-404 = "index.php?_route=/error/404"
                server.error-handler-500 = "views/error/500.html"
                url.rewrite-once = (
                    "^/static/(.*)$" => "/static/$1",
                    "^/eimgs/(.*)$" => "/eimgs/$1",
                    "^/404$" => "index.php?_route=/error/404",
                    "^/500$" => "views/error/500.html",
                    "^/v3/routex/_inner(.*)$" => "index.php?_route=/error/404",
                    "^/v3/routex(.*)$" => "/v3/routex$1",
                    "^.*(\?.*)$" => "index.php$1",
                    "^.*$" => "index.php",
                )
                $HTTP["url"] =~ "^/(static|eimgs)/(.*)$" {
                    expire.url = ( "" => "access 365 days" )
                }
                setenv.add-response-header += (
                    "Cache-Control" => "public, must-revalidate"
                )
            }

        } else $HTTP["host"] == "img.exfe.com" {
            server.document-root="/exfe/upload"
            setenv.add-response-header = (
                "access-control-allow-origin"      => "http://exfe.com",
                "access-control-allow-credentials" => "true",
                "Cache-Control" => "public",
            )
            expire.url = ( "" => "access 365 days" )
        } else $HTTP["host"] =~ "^(www.exfe.com|exfe.net|www.exfe.net|exfe.org|www.exfe.org|exfe.us|www.exfe.us)$" {
            url.redirect = ( "^/(.*)" => "https://exfe.com/$1" )
        } else $HTTP["host"] =~ "(.*)" {
            url.redirect = ( "^/(.*)" => "https://%1/$1" )
        }


## Config sshd

### /etc/ssh/sshd_config

        PasswordAuthentication no





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
