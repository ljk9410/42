FROM	debian:buster

LABEL	maintainer="jung-lee@student.42seoul.kr"

RUN		apt-get update
RUN		apt-get -y install nginx \
		php7.3-fpm \
		mariadb-server php-mysql php-mbstring \
		openssl \
		vim \
		wget

COPY	./srcs/* /tmp

CMD		bash /tmp/run.sh
