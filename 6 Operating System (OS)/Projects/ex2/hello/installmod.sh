#!/bin/bash
# OS ex2 - build and install kernel module
# 1427405017 Jiayun Shen
echo -e "\nOS ex2"
echo -e "\t- build and install kernel module\n"
echo 'current working dir is'
pwd

echo -e "\n************ Makefile **************\n"
cat Makefile
echo -e "\n\n************************************\n"

echo -e "\n making module...\n"
make

echo -e "\n installing module...\n"
sudo insmod ./hello.ko

echo -e "\n listing module...\n"
lsmod | grep "hello" --color

echo -e "\n removing module...\n"
sudo rmmod hello

echo -e "\n checking kernel messages...\n"
dmesg | grep "hello" --color