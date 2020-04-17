% 实验3 : 图像编码与压缩（算术编码）
% 1427405017
% 沈家赟
clc,clear all;
symbol=['abc']          %已知会出现的字符
pr=[0.4 0.4 0.2]        %各字符出现的概率
disp('************************************');
format long;

%in=['aabbc']			
in=input('请输入仅包含a、b、c的5个字母的字符串：');  %手动输入需要带单引号
 
disp('*********开始编码*********');
%编程：要求能显示每一轮编码的上界和下界
low = zeros(6,1);
high = zeros(6,1);
range = zeros(6,1);
high_char = [0.4; 0.8; 1];
low_char = [0.0; 0.4; 0.8];
low(1) = 0;
high(1) = 1;
range(1) = 1;
for i = 2:6
    if in(i-1) == 'a'
        high(i) = low(i-1) + range(i-1)*high_char(1);
        low(i)  = low(i-1) + range(i-1)*low_char(1);
        range(i) = range(i-1)*0.4;;
    end
    if in(i-1) == 'b'
        high(i) = low(i-1) + range(i-1)*high_char(2);
        low(i)  = low(i-1) + range(i-1)*low_char(2);
        range(i) = range(i-1)*0.4;
    end
    if in(i-1) == 'c'
        high(i) = low(i-1) + range(i-1)*high_char(3);
        low(i)  = low(i-1) + range(i-1)*low_char(3);
        range(i) = range(i-1)*0.2;
    end
end

high
low
range

disp('*********编码结果*********');
value=low   %为避免临界效应，可以取值(low+high)/2更安全

 
disp('*********开始解码*********');
%编程：要求能显示每一轮解码后的值。注：假设编码长度已知
start_value = value(6);
value = zeros(5,1);
value(1) = start_value;
range_char = zeros(5,1);
out = zeros(5,1);
for i=2:5
    if value(i-1) < high_char(1) & value(i-1) >= low_char(1)
        range_char(i-1) = 0.4;
        value(i) = (value(i-1) - low_char(1))/range_char(i-1);
    end
    if value(i-1) < high_char(2) & value(i-1) >= low_char(2)
        range_char(i-1) = 0.4;
        value(i) = (value(i-1) - low_char(2))/range_char(i-1);
    end
    if value(i-1) < high_char(3) & value(i-1) >= low_char(3)
        range_char(i-1) = 0.2;
        value(i) = (value(i-1) - low_char(3))/range_char(i-1);
    end
end
value

for i=1:5
    if value(i) < high_char(1) & value(i) >= low_char(1)
        out(i) = 'a';
    end
    if value(i) < high_char(2) & value(i) >= low_char(2)
        out(i) = 'b';
    end
    if value(i) < high_char(3) & value(i) >= low_char(3)
        out(i) = 'c';
    end
end
disp('*********解码结果*********');
char(out) 
