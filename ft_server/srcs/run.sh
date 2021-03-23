#!/bin/bash

service mysql start

# Database
echo "CREATE DATABASE wordpress;" | mysql -u root
echo "CREATE USER 'jung-lee'@'localhost' IDENTIFIED BY 'a12031234!';" | mysql -u root
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'jung-lee'@'localhost' IDENTIFIED BY 'a12031234!';" | mysql -u root
echo "FLUSH PRIVILEGES;" | mysql -u root

# SSL
openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Lee/CN=localhost" -keyout localhost.dev.key -out localhost.dev.crt
mv localhost.dev.crt etc/ssl/certs/
mv localhost.dev.key etc/ssl/private/
chmod 600 etc/ssl/certs/localhost.dev.crt etc/ssl/private/localhost.dev.key

# Nginx config file
rm /etc/nginx/sites-available/default
for (( ; ; ))
do
    echo -n "autoindex on/off?: "
    read autoindex;
    if [ "${autoindex}" = "on" ]; then
        mv /tmp/default_on /tmp/default
        mv /tmp/default /etc/nginx/sites-available/
        break
    elif [ "${autoindex}" = "off" ]; then
        mv /tmp/default_off /tmp/default
        mv /tmp/default /etc/nginx/sites-available/
        break
    else
        echo "just put 'on' or 'off' !!!"
    fi
done

# Wordpress
wget https://wordpress.org/latest.tar.gz
tar -xvf latest.tar.gz
mv wordpress/ var/www/html/
mv /tmp/wp-config.php var/www/html/wordpress/
chown -R www-data:www-data /var/www/html/wordpress

# phpMyAdmin
wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz
tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz
mv phpMyAdmin-5.0.2-all-languages phpmyadmin
mv phpmyadmin /var/www/html/
mv /tmp/config.inc.php /var/www/html/phpmyadmin/
mysql < var/www/html/phpmyadmin/sql/create_tables.sql

service nginx start
service php7.3-fpm start
bash
