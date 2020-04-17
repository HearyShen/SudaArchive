clc; clear all; close all;
 
[X,Y,Z]=cylinder(1,3);
 
L = [-1 -1 -1];
I_p = 1;
K_d = 1;
 
I_a = 0.1;
K_a = 1;
 
for i=1:3
    p1=[X(1,i),Y(1,i),Z(1,i)];
    p2=[X(1,i+1),Y(1,i+1),Z(1,i+1)];
    p3=[X(2,i+1),Y(2,i+1),Z(2,i+1)];
    v(i,:)=cross(p2-p1,p3-p2);
    cos_theta(i) = abs(dot(v(i,:),L)/(norm(v(i,:)*norm(L))));
    p = I_p*K_d*cos_theta(i) +I_a*K_a;
    if p < 0;
        p = 0;
    end
    if p > 1
        p = 1;
    end
    col(i,:) = [p p p];    
    fill3([X(1,i),X(1,i+1),X(2,i+1),X(2,i)],...
        [Y(1,i),Y(1,i+1),Y(2,i+1),Y(2,i)],...
        [Z(1,i),Z(1,i+1),Z(2,i+1),Z(2,i)],col(i,:))
    hold on
end
quiver3([0,0],[0,0],[0,0],[0,1],[0,1],[0,1]);
hold off