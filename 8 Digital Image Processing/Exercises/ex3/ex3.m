% ʵ��3 : ͼ�������ѹ�����������룩
% 1427405017
% ����S
clc,clear all;
symbol=['abc']          %��֪����ֵ��ַ�
pr=[0.4 0.4 0.2]        %���ַ����ֵĸ���
disp('************************************');
format long;

%in=['aabbc']			
in=input('�����������a��b��c��5����ĸ���ַ�����');  %�ֶ�������Ҫ��������
 
disp('*********��ʼ����*********');
%��̣�Ҫ������ʾÿһ�ֱ�����Ͻ���½�
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

disp('*********������*********');
value=low   %Ϊ�����ٽ�ЧӦ������ȡֵ(low+high)/2����ȫ

 
disp('*********��ʼ����*********');
%��̣�Ҫ������ʾÿһ�ֽ�����ֵ��ע��������볤����֪
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
disp('*********������*********');
char(out) 
