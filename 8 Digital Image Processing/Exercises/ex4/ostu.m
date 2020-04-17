%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%  
%ostu 最大类间方差法图像分类  
%该方法将图像分为前景和背景两部分，背景和目标之间的类间方差越大,说明构成图像的2部分的差别越大,  
%当部分目标错分为背景或部分背景错分为目标都会导致2部分差别变小。因此,使类间方差最大的分割意味着错分概率最小。  
%Command 中调用方式：threshold = ostu('D:\Images\pic_loc\1870405130305041503.jpg')
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%  
function threshold = ostu(url);   
   G=imread(url);   
   subplot(2,1,1);  
   imshow(G,[]);  
   %[count x]=imhist(a);   
   [row_count,col_count]=size(G);   
   N=row_count*col_count;   
   L=256;   
   
theta_squared = zeros(L,1);
for th=0:L-1
    F_a = length(find(G<=th))/N;
    F_b = length(find(G>th))/N;
    avg_a = mean(find(G<=th));
    avg_b = mean(find(G>th));
    avg = mean(G(:));
    theta_squared(th+1) = F_a*((avg_a - avg)^2) + F_b*((avg_b - avg)^2);
end

[max_theta, threshold] = max(theta_squared)
length(theta_squared);

for i=1:row_count   
    for j=1:col_count   
        if G(i,j)>threshold   
            G(i,j)=255;   
        else   
            G(i,j)=0;   
        end   
    end   
end  
subplot(2,1,2);  
imshow(G,[]);  
