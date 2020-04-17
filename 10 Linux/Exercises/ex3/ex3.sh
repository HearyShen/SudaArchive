#!/bin/bash
# Linux course
# ex3 - Shell Scripts
# 1427405017 - Jiayun Shen - 2017/4/7
# 1) date and who
date
who
# 2) myname
myname=`echo "Hello, world"`
echo 'myname=' $myname
# 3) anyname
anyname=$myname
readonly anyname
unset myname
unset anyname
echo 'unset myname=' $myname
echo 'unset readonly anyname=' $anyname
