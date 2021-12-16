FROM alpine:3.7

RUN apk add --update gcc g++ clang gdb cmake make ninja \
	autoconf automake dos2unix tar rsync python3 \
	boost-dev  \
	&& rm -rf /tmp/* /var/cache/apk/*

WORKDIR /opt/build

COPY CMakeLists.txt main.cpp /opt/build

RUN mkdir build;cd build;echo $PWD; cmake ..; make

CMD ["build/pinger"]
#CMD ["/bin/sh"]
