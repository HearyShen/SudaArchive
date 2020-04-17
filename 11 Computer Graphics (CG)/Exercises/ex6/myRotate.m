%% Author Info
% ����S  1427405017
% 2017.6.8
%% ========================== Rotate X,Y =========================
% ��תͼ��X,Y���ݣ�Χ��z����ת
function [newX, newY] = myRotate(X,Y,theta)

theta = (theta/360)*2*3.1415926;

R = sqrt(X.^2+Y.^2);
alpha = atan(Y./X);

newX = R.*cos(alpha+theta);
newY = R.*sin(alpha+theta);

end