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
mv /tmp/default /etc/nginx/sites-available/

# Wordpress
wget https://wordpress.org/latest.tar.gz
tar -xvf latest.tar.gz
mv wordpress/ var/www/html/
mv /tmp/wp-config.php var/www/html/wordpress/
chown -R www-data:www-data /var/www/html/wordpress

service nginx start
service php7.3-fpm start
bash
