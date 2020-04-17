clc,clear all;
I=imread('cameraman.tif');
I=im2double(I);
subplot(3,2,1);imshow(I,[]);
title('原始图');
 
F=fft2(I);      
G=fftshift(F);
 
subplot(3,2,2);imshow(log(1+abs(G)),[]);
title('傅里叶频谱');
 
[m,n]=size(G);      
c1=floor(m/2);      %中心行坐标
c2=floor(n/2);      %中心列坐标

d0=10;
nn=2;
for i=1:m
    for j=1:n
        d=sqrt((i-c1)^2+(j-c2)^2);
        h=1/(1+(d/d0)^(2*nn));
        A(i,j)=h*G(i,j);
    end
end
subplot(3,2,3);imshow(log(1+abs(A)),[]);    %取幅度
title('Butterworth低通滤波');

f=ifftshift(A);
i=real(ifft2(f));
subplot(3,2,4);imshow(i,[]);
title('Butterworth理想低通滤波');


d0=10;
nn=2;
for i=1:m
    for j=1:n
        d=sqrt((i-c1)^2+(j-c2)^2);
        if d==0
            h=0;
        else
            h=1/((1+(d0/d))^(2*nn));
        end
        C(i,j)=h*G(i,j);
    end
end
subplot(3,2,5);imshow(log(1+abs(C)),[]);    %取幅度
title('Butterworth高通滤波');

f=ifftshift(C);
i=real(ifft2(f));
subplot(3,2,6);imshow(i,[]);
title('Butterworth高通滤波');