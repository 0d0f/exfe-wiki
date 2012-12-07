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
