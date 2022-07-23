ARG UBUNTU_VERSION=18.04
FROM ubuntu:$UBUNTU_VERSION

RUN apt-get update && apt-get clean

RUN apt-get install -y g++ python-dev python-matplotlib

COPY . /app

WORKDIR /app

RUN g++ main.cpp -std=c++11 -I/usr/include/python2.7 -lpython2.7 -o main.out

CMD ["./main.out"]
