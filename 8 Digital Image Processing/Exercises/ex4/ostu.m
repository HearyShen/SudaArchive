%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%  
%ostu �����䷽�ͼ�����  
%�÷�����ͼ���Ϊǰ���ͱ��������֣�������Ŀ��֮�����䷽��Խ��,˵������ͼ���2���ֵĲ��Խ��,  
%������Ŀ����Ϊ�����򲿷ֱ������ΪĿ�궼�ᵼ��2���ֲ���С�����,ʹ��䷽�����ķָ���ζ�Ŵ�ָ�����С��  
%Command �е��÷�ʽ��threshold = ostu('D:\Images\pic_loc\1870405130305041503.jpg')
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
