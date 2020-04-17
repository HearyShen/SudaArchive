%%Hough变换实例1：经过一条直线的3个点（0，2）、（1，1）、（2，0）
clc,clear all,close all;
x=-1:3;
y=-x+2;     %y=kx+c,截距式直线表达式
 
subplot(2,2,1),plot(x,y);
title('（1）直线及线上的3个点'),xlabel('x'),ylabel('y');
axis([-1,3,-1,3]);
hold on;grid on;axis equal;
x1=0;y1=2;   %直线上的3个点坐标
x2=1;y2=1;
x3=2;y3=0;
plot(x1,y1,'r*',x2,y2,'r*',x3,y3,'r*');
 
theta=[0:pi/180:pi];
x1=0;y1=2;
p=x1*cos(theta)+y1*sin(theta);      %图像空间转换回参数空间
subplot(2,2,2),plot(theta,p);
title('（2）图像空间变换到参数空间'),xlabel('\theta'),ylabel('\rho');
text(0.5,0.2,'交点');
hold on;
axis([0,pi,-3,3]);
 
x2=1;y2=1;
p=x2*cos(theta)+y2*sin(theta);
plot(theta,p);
 
x3=2;y3=0;
p=x3*cos(theta)+y3*sin(theta);
plot(theta,p);
 
 
[r,t]=solve('2*sin(t)-r=0','2*cos(t)-r=0','r','t'); %返回的值是符号，即解方程
r=double(r);
t=double(t);
subplot(2,2,3),polar(t,r,'r*');
title('（3）交点的极坐标');
 
y=(r-x*cos(t))/sin(t);          %参数空间转换回图像空间
subplot(2,2,4),plot(x,y);
title('（4）参数空间变换回图像空间'),xlabel('x'),ylabel('y');
axis([-1,3,-1,3]);
grid on;axis equal;
