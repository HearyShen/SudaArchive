clear
close all
clc

%% call Bezier2by2 function to draw graph

P_part1=[
    0 0 4 4; 
    0 2 4 0; 
    0 0 0 0
    ]; 

P_part2=[
    0 0 4 4; 
    0 -2 -4 0; 
    0 0 0 0
    ]; 

figure
hold on
Bezier2by2(P_part1(1,:), P_part1(2,:), P_part1(3,:));
hold on
Bezier2by2(P_part2(1,:), P_part2(2,:), P_part2(3,:));
hold off


%% call Bspline2by2 function to draw enclosing graph

P_part1=[
    0 0 4 4; 
    0 2 4 0; 
    0 0 0 0
    ]; 

P_part2=[
    0 4 4 3; 
    2 4 0 -2; 
    0 0 0 0
    ]; 

P_part3=[
    4 4 3 0; 
    4 0 -2 0; 
    0 0 0 0
    ]; 

P_part=[
    0 0 4 4; 
    0 4 4 0; 
    0 0 0 0
    ]; 

% figure
% hold on
% Bspline2by2(P_part1(1,:), P_part1(2,:), P_part1(3,:), 'b');
% hold on
% Bspline2by2(P_part2(1,:), P_part2(2,:), P_part2(3,:), 'r');
% hold on
% Bspline2by2(P_part3(1,:), P_part3(2,:), P_part3(3,:), 'r');

hold on
Bspline2by2(P_part(1,1:4), P_part(2,1:4), P_part(3,1:4), 'b');
hold on
Bspline2by2(P_part(1,2:5), P_part(2,1:4), P_part(3,1:4), 'b');

hold off