#!/bin/sh
#读取数据
clear
sed '/^#/d' config.xml | sort > config.store
tr [,:\(\)] [' '' '' '' '] < config.store > config.store1
wc -l config.store1 > node_num
g++ GPSR.cc -l curses -o GPSR
./GPSR
rm -f GPSR config.store config.store1 node_num
