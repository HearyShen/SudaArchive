#!/bin/bash
# Linux course
# ex3 - Shell Scripts
# 1427405017 - Jiayun Shen - 2017/4/7
if test $# -eq 1
then 
    if test -f $1
    then 
        echo 'Result shown below:'
        row_entries=`ls -lh $1`
        col_count=`ls -lh $1 | wc -w`
        # echo ${row_str[0]}
        i=0
        for col_entry in $row_entries
        do
            let "i++"

            # user(owner)
            if test $i -eq 3
            then
                echo 'User: ' $col_entry
            fi

            # revise time(latest)
            if test $i -eq 6
            then
                echo -en 'Time: '
            fi
            if test $i -ge 6 && test $i -lt $col_count
            then
                echo -en $col_entry ' '
            fi
        done
        echo ''
    else echo 'ERROR: Not a normal file!'
    fi
else echo 'ERROR: support only one param(file)!'
fi

