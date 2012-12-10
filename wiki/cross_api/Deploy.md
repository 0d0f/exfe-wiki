# install
sudo apt-get install python-software-properties
apt-get update
apt-get upgrade
apt-get dist-upgrade
apt-get install git lighttpd mysql-client mysql-server openssh-client openssh-server php5 php5-cgi php5-cli php5-gd php5-intl php5-curl php5-mysqlnd redis-server
# clone source
cd /
mkdir 0d0f
cd 0d0f
git clone git@dlol.us:exfeweb.git
git clone git@dlol.us:exfelight.git
cd exfeweb
ln -s ../exfelight/production static
cd ..
# config lighttpd.conf
server.modules = (
        "mod_access",
        "mod_alias",
        "mod_compress",
        # Changed by @Leask {
        "mod_fastcgi",
        "mod_rewrite",
        "mod_redirect",
        # }
)
# init database
source exfe_schema_1354600349.sql;
grant all privileges on exfe_dev.* to 'exfe'@'%' identified by '135qetadg';
FLUSH PRIVILEGES;




old version:



部署记录

0 服务器
    lighttpd
    mysql 5
    redis 2.4
    php 5
    monit

    php需要安装 php-redis
//linux
#'./configure' '--with-mysql' '--enable-mbstring' '--with-curl' '--with-pdo-mysql' '--with-openssl' '--with-gd' '--with-jpeg-dir=/usr/lib' '--disable-fileinfo' '--with-iconv-dir=/usr/local/lib'
'./configure' '--with-mysql' '--enable-mbstring' '--with-curl' '--with-pdo-mysql' '--with-openssl' '--with-gd' '--with-jpeg-dir=/usr/lib' '--disable-fileinfo' '--with-iconv-dir=/usr/local/lib' --with-imap  --with-imap-ssl --with-kerberos

git clone https://github.com/nicolasff/phpredis.git

//freebsd
/usr/ports/textproc/php5-simplexml
/usr/ports/security/php5-hash
/usr/ports/textproc/php5-ctype
/usr/ports/databases/php5-redis
/usr/ports/mail/php5-imap

//icu

    a php增加 --enable-intl 编译，实现先安装icu-project http://www.icu-project.org/

    b config.php 里面增加了 define('INTL_RESOURCES', '/Users/huoju/www/exfe/intl'); 用来定义资源文件所在位置

    c common.php 里面增加了

    $locale=Locale::acceptFromHttp($_SERVER['HTTP_ACCEPT_LANGUAGE']);
    $exfe_res = new ResourceBundle($locale, INTL_RESOURCES);

    用来根据locale载入资源。目前是根据浏览器判断，因为界面上还没有切换语言的位置。但未来应该把这些从common移动到其他地方，因为这个位置还没法读数据库和设置cookie。

    d 在intl目录里面，root.txt和zh.txt是资源文件，root是默认的，用英文，zh是中文。格式一看就明白。在一个table里面中英文字段要对应，不然会有显示成空白的情况，比如 gather 就是一个table，其中字段要一致。现在我是按照一个view文件一个table这样来的。完全不存在的table会自动继承root的资源，反而无所谓。

    e views/x/gatherView.php 是我目前修改了一点的模版

    首先 <?php global $exfe_res;?>  把common里面的全局变量声明了，然后 <?php echo $exfe_res["gather"]["Write_some_words_about_this_X"];?>  这样就是本地化的资源串了。


1 脚本

    发送邮件等的任务脚本。位于script目录
    注意，对于需要组合多个消息发送的任务需要使用 MULTI=true 参数

2 配置文件
config.php.sample
mailclient/mailconf.php.sample


php 配置文件
session.cookie_domain = '.exfe.com'


mysql 配置文件
[mysqld]
default-time-zone='+00:00'
