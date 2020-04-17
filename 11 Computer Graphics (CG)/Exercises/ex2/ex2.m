clear all;
close all;
clc;

% points=[0 1 1 0 -1 -1 0 0; 0 0 1 2 1 0 -1 -2]; 
points=[0 1 4 5 7 8 9 10; 
    0 2 1 7 3 0 8 9]; 
cv=cscvn(points);
fnplt(cv); 
hold on, plot(points(1,:),points(2,:),'o'), hold off

figure;
hold on,
coefs = fnbrk(cv,'coef'); 
[~, count] = size(points);


color = 'rgbcmyk';
for i=1:count-1
%     x_start = points(1,i);
%     x_end = points(1,i+1);
    t = 0:0.01:cv.breaks(1,i+1)-cv.breaks(1,i);
    T = [t.^3; t.^2; t;ones(1,length(t))];
    
    x = coefs(i*2-1,:) * T
    y = coefs(i*2, :) * T

    plot(x,y,color(i),'linewidth',2);
end
hold off

% c=fnplt(cscvn([0 .3 .82 .92 0 0 -.92 -.82 -.3 0; .66 .85 .9 0 ...
% -.83 -.83 0 .9 .85 .66])); fill(c(1,:),c(2,:),'r'), axis equal