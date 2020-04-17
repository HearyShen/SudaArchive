function Bspline2D(target_axis, Points)
    % B-spline on 2D surface
    B=[1  -2  1;-2  2  0;1  1  0]; 
    
    plot(target_axis, Points(1,1:3),Points(2,1:3),'o') 
    hold on;
    
    for t=0:0.01:1 
        T= [t^2  t  1];  
        P1=1/2*T*B*Points(1,1:3)'; 
        P2=1/2*T*B*Points(2,1:3)'; 
        plot(target_axis, P1,P2,'r.') 
        hold on 
    end 
    title('Bspline2D')
    hold off 
end

