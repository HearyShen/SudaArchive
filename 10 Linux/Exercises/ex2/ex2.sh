#!/bin/bash
# Linux course
# ex2 - display a nine by nine multiply table
# 1427405017 - Jiayun Shen - 2017/3/24

echo 'Linux ex2 - 9 by 9 multiply table'
for((i=1;i<=9;i++))
do
    echo -en "$i:\t"
    for((j=1;j<=i;j++))
    do
        let "result=$i*$j"
        echo -en "$i*$j=$result\t"
    done
    echo ""
done
