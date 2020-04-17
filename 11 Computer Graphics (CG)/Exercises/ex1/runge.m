clc; clear all; close all;

x = -1:0.01:1;
y = 1./(1+25*x.^2);
figure; plot(x,y,'r','linewidth',2);

m = 10;
n = m+1;
xp = -1:2/(n-1):1;
yp = 1./(1+25*xp.^2);
hold on
plot(xp,yp,'o','markersize',15);

p = polyfit(xp,yp,m);
ys = polyval(p,x);
plot(x,ys,'b','linewidth',2)
hold off