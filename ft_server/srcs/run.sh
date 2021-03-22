#!/bin/bash

# SSL
openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Lee/CN=localhost" -keyout localhost.dev.key -out localhost.dev.crt
mv localhost.dev.crt etc/ssl/certs/
mv localhost.dev.key etc/ssl/private/
chmod 600 etc/ssl/certs/localhost.dev.crt etc/ssl/private/localhost.dev.key

# Nginx config file
rm /etc/nginx/sites-available/default
mv /tmp/default /etc/nginx/sites-available/

service nginx start
service php7.3-fpm start
bash
