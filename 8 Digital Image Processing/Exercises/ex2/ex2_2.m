% Matlab编程：分别使用Roberts算子、Sobel算子、拉普拉斯算子实现图像锐化。
% 要求：使用subplot函数按1行3列，分别显示3种锐化结果。每幅图都要有标题。

%close all;
clear all;
pkg load image;

I=imread('cameraman.tif');
I=im2double(I);
subplot(1,4,1);imshow(I,[]);
title('original');

G = I;
 
[m,n]=size(G);

for i=1:m
    for j=1:n
      if i==m || j==n
        A(i,j) = G(i,j);
        continue;
      end
      A(i,j)=abs(G(i,j)-G(i+1,j+1)) + abs(G(i+1,j)-G(i,j+1));
    end
end
subplot(1,4,2);imshow(A,[]);
title('Roberts');

for i=1:m
    for j=1:n
      if i==1 || i==m || j==1 || j==n
        B(i,j) = G(i,j);
        continue;
      end
      B(i,j) = abs(G(i-1,j+1)+2*G(i,j+1)+G(i+1,j+1)-G(i-1,j-1)-2*G(i,j-1)-G(i+1,j-1))+abs(G(i-1,j-1)+2*G(i-1,j)+G(i-1,j+1)-G(i+1,j-1)-2*G(i+1,j)-G(i+1,j+1));
    end
end
subplot(1,4,3);imshow(B,[]);
title('Sobel');


for i=1:m
    for j=1:n
      if i==1 || i==m || j==1 || j==n
        C(i,j) = G(i,j);
        continue;
      end
      C(i,j) = abs(8*G(i,j)-G(i+1,j)-G(i-1,j)-G(i,j+1)-G(i,j-1));
    end
end
subplot(1,4,4);imshow(C,[]);
title('Laplace');