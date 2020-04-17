%% �����ͼ��ѧ ʵ����
% plotTree.m
% 1427405017  ����S
% 2017.6.15

%% plotTree
% a - �������
% n - ��������
% �Ľ�˵����
%   1��ͨ��if-else�ṹ���ټ���������ߵ������ܣ�
%   2������ʽ�ɵ���������n

function plotTree(a,n)

x0=1;y0=1;
for i=1:n
    r=rand;
    if r<=a(1,7)
        x1=a(1,1)*x0+a(1,2)*y0+a(1,5);
        y1=a(1,3)*x0+a(1,4)*y0+a(1,6);
    elseif r>a(1,7) && r<=sum(a(1:2,7))
        x1=a(2,1)*x0+a(2,2)*y0+a(2,5);
        y1=a(2,3)*x0+a(2,4)*y0+a(2,6);
    elseif r>sum(a(1:2,7)) && r<=sum(a(1:3,7))
        x1=a(3,1)*x0+a(3,2)*y0+a(3,5);
        y1=a(3,3)*x0+a(3,4)*y0+a(3,6);
    elseif r>sum(a(1:3,7)) && r<=sum(a(1:4,7))
        x1=a(4,1)*x0+a(4,2)*y0+a(4,5);
        y1=a(4,3)*x0+a(4,4)*y0+a(4,6);
    elseif r>sum(a(1:4,7)) && r<=1
        x1=a(5,1)*x0+a(5,2)*y0+a(5,5);
        y1=a(5,3)*x0+a(5,4)*y0+a(5,6);
    end
    x0=x1;y0=y1;
    plot(x1,y1,'.');
    hold on
end

hold off

end