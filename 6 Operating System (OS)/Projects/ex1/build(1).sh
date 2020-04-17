#!/bin/bash
echo 'OS ex1 编译开始...'
gcc game_judge.c -o judge
echo 'judge 编译完成.'
gcc game_player1.c -o player1
echo 'plater1 编译完成.'
gcc game_player2.c -o player2
echo 'player2 编译完成.'
echo '全部完成'
