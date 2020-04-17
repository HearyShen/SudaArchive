%%Hough�任ʵ��1������һ��ֱ�ߵ�3���㣨0��2������1��1������2��0��
clc,clear all,close all;
x=-1:3;
y=-x+2;     %y=kx+c,�ؾ�ʽֱ�߱��ʽ
 
subplot(2,2,1),plot(x,y);
title('��1��ֱ�߼����ϵ�3����'),xlabel('x'),ylabel('y');
axis([-1,3,-1,3]);
hold on;grid on;axis equal;
x1=0;y1=2;   %ֱ���ϵ�3��������
x2=1;y2=1;
x3=2;y3=0;
plot(x1,y1,'r*',x2,y2,'r*',x3,y3,'r*');
 
theta=[0:pi/180:pi];
x1=0;y1=2;
p=x1*cos(theta)+y1*sin(theta);      %ͼ��ռ�ת���ز����ռ�
subplot(2,2,2),plot(theta,p);
title('��2��ͼ��ռ�任�������ռ�'),xlabel('\theta'),ylabel('\rho');
text(0.5,0.2,'����');
hold on;
axis([0,pi,-3,3]);
 
x2=1;y2=1;
p=x2*cos(theta)+y2*sin(theta);
plot(theta,p);
 
x3=2;y3=0;
p=x3*cos(theta)+y3*sin(theta);
plot(theta,p);
 
 
[r,t]=solve('2*sin(t)-r=0','2*cos(t)-r=0','r','t'); %���ص�ֵ�Ƿ��ţ����ⷽ��
r=double(r);
t=double(t);
subplot(2,2,3),polar(t,r,'r*');
title('��3������ļ�����');
 
y=(r-x*cos(t))/sin(t);          %�����ռ�ת����ͼ��ռ�
subplot(2,2,4),plot(x,y);
title('��4�������ռ�任��ͼ��ռ�'),xlabel('x'),ylabel('y');
axis([-1,3,-1,3]);
grid on;axis equal;
