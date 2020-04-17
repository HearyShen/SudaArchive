#!/bin/bash
# Linux - ex5
# 沈家赟 1427405017
echo '================> ex5 - 1 <==============='
echo -e '\n1 - (1)\n'
cat emp.data | awk '$3>0{print $1, $2*$3}'
echo -e '\n---------------------------------------'

echo -e '\n1 - (2)\n'
cat emp.data | awk '$3>15{emp=emp+1}
        END{print emp, "employees worked more than 15 hours."}'
echo -e '\n---------------------------------------'

echo -e '\n1 - (3)\n'
cat emp.data | awk '{words=words+NF
        chars=chars+length($0)}
        END{print NR, "lines\t", words, "words\t", chars, "characters"}'
echo -e '\n---------------------------------------'
echo '======================================='


echo '================> ex5 - 2 <==============='
echo -e '\n2 - (1)\n'
cat telephone.txt | sed 's/^400/800/'
echo -e '\n---------------------------------------'

echo -e '\n2 - (2)\n'
cat telephone.txt | sed 's/^[0-9]\{3\}/(&)/'
echo -e '\n---------------------------------------'

echo -e '\n2 - (3)\n'
cat telephone.txt | sed 's/^\([0-9]\{3\}\)\([0-9]\{3\}\)/\1-\2-/'
echo -e '\n---------------------------------------'

echo -e '\n2 - (4)\n'
# echo '123abc' | sed -r 's/[0-9]+/& &/'
echo '123abc' | sed 's/[0-9]+/& &/'     # -r则报错
echo abcd123 | sed 's/\([a-z]*\).*/\1/'
echo -e '\n---------------------------------------'
echo '======================================='
