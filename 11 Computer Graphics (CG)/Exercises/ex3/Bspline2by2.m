function Bspline2by2( X, Y, Z, mcolor )

if(length(X)~=length(Y) || length(Y)~=length(Z) )
    fprintf('ERROR: input X, Y, Z should have same dimension!')
end

B=[
    -1  3  -3  1;
    3  -6  3  0;
    -3  0  3  0;
    1  4  1  0
    ]; 

plot3(X, Y, Z,'o') 
hold on 

for t=0:0.01:1 
    T= [t^3  t^2  t  1];  
    P1=1/6*T*B*X'; 
    P2=1/6*T*B*Y'; 
    P3=1/6*T*B*Z'; 
    plot3(P1,P2,P3,'.', 'color', mcolor) 
end 
hold off 

end

