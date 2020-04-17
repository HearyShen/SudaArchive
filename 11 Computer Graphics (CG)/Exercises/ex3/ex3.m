% %% Bezier on 2D surface
% B=[-1 3 -3 1;3 -6 3 0;-3 3 0 0;1 0 0 0]; 
% 
% figure,
% hold on
% 
% P_part1=[0  0  4  4; 0  2  4  0]; 
% plot(P_part1(1,:),P_part1(2,:),'o') 
% for t=0:0.01:1
%     T= [t^3  t^2  t  1];
%     P1=T*B*P_part1(1,:)'
%     P2=T*B*P_part1(2,:)' 
%     plot(P1,P2,'.') 
%     hold on
% end
% 
% P_part2=[0  0  4  4; 0  -2  -4  0]; 
% plot(P_part2(1,:),P_part2(2,:),'o') 
% for t=0:0.01:1
%     T= [t^3  t^2  t  1];
%     P1=T*B*P_part2(1,:)'
%     P2=T*B*P_part2(2,:)' 
%     plot(P1,P2,'.') 
%     hold on
% end
% 
% hold off 

%% B-spline on 2D surface
P=[1  2  5  5.5;  1.5  7  11  6; 3  5  6.8  2.1];
plot3(P(1,1:3),P(2,1:3),P(3,1:3),'o') 
hold on 
plot3(P(1,2:4),P(2,2:4),P(3,2:4),'+') 
hold on 
B=[1  -2  1;-2  2  0;1  1  0]; 
for t=0:0.01:1 
    T= [t^2  t  1];  
    P1=1/2*T*B*P(1,1:3)'; 
    P2=1/2*T*B*P(2,1:3)'; 
    P3=1/2*T*B*P(3,1:3)'; 
    plot3(P1,P2,P3,'r.') 
    hold on 
    Q1=1/2*T*B*P(1,2:4)'; 
    Q2=1/2*T*B*P(2,2:4)'; 
    Q3=1/2*T*B*P(3,2:4)'; 
    plot3(Q1,Q2,Q3,'b*') 
end 
hold off 
