function Bezier2D(target_axis, Points)
    % Bezier on 2D surface
    B=[-1 3 -3 1;3 -6 3 0;-3 3 0 0;1 0 0 0]; 

    plot(target_axis, Points(1,:),Points(2,:),'o')
    hold on
    
    for t=0:0.01:1
        T= [t^3  t^2  t  1];
        P1=T*B*Points(1,:)';
        P2=T*B*Points(2,:)';
        plot(target_axis, P1,P2,'.') 
%             hold on
    end
    [~, cols] = size(Points);
    line(target_axis, Points(1,1:2), Points(2,1:2));
    line(target_axis, Points(1,cols-1:cols), Points(2,cols-1:cols));
    title('Bezier2D')
    hold off
end

