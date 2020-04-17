function touchable_bezier
h_touchable = figure('WindowButtonDownFcn',@onBtnDown)
set(h_touchable, 'name', 'Touchable Bezier')
ah = axes('SortMethod','childorder');
axis ([1 10 1 10])
title('Click and drag')

P_init=[0  0  4  4; 0  2  4  0];
Bezier2D(P_init);
P_dynamic = P_init;
select = 0; % 默认未选中点

   function onBtnDown(src,callbackdata)
     seltype = src.SelectionType;
     % This code uses dot notation to set properties
     % Dot notation runs in R2014b and later.
     % For R2014a and earlier: seltype = get(src,'SelectionType');
     if strcmp(seltype,'normal')
        src.Pointer = 'circle';
        cp = ah.CurrentPoint;
        % For R2014a and earlier: 
        % set(src,'Pointer','circle');
        % cp = get(ah,'CurrentPoint');
        
        select=0;
        if(cp(1,1)-P_dynamic(1,1)<0.2 && cp(1,2)-P_dynamic(2,1)<0.2)
%             xinit = cp(1,1)
%             yinit = cp(1,2)
            select=1;   % 选中一号点
        end
        
%         hl = line('XData',xinit,'YData',yinit,...
%         'Marker','p','color','b');
        
        src.WindowButtonMotionFcn = @onBtnMotion;
        src.WindowButtonUpFcn = @onBtnUp;
        % For R2014a and earlier: 
        % set(src,'WindowButtonMotionFcn',@wbmcb);
        % set(src,'WindowButtonUpFcn',@wbucb);

     end    
 
        function onBtnMotion(src,callbackdata)
           cp = ah.CurrentPoint;
           % For R2014a and earlier: 
           % cp = get(ah,'CurrentPoint');
           if(select == 1)
               P_dynamic(1,1) = cp(1,1);
               P_dynamic(2,1) = cp(1,2);
           end
           Bezier2D(P_dynamic)
%            xdat = [xinit,cp(1,1)];
%            ydat = [yinit,cp(1,2)];
%            hl.XData = xdat;
%            hl.YData = ydat;
           % For R2014a and earlier: 
           % set(hl,'XData',xdat);
           % set(hl,'YData',ydat);
           drawnow
        end
   
        function onBtnUp(src,callbackdata)
           last_seltype = src.SelectionType;
           % For R2014a and earlier: 
           % last_seltype = get(src,'SelectionType');
           if strcmp(last_seltype,'alt')
              src.Pointer = 'arrow';
              src.WindowButtonMotionFcn = '';
              src.WindowButtonUpFcn = '';
              % For R2014a and earlier:
              % set(src,'Pointer','arrow');
              % set(src,'WindowButtonMotionFcn','');
              % set(src,'WindowButtonUpFcn','');
           else
              return
           end
        end
   end

   function Bezier2D(Points)
        % Bezier on 2D surface
        B=[-1 3 -3 1;3 -6 3 0;-3 3 0 0;1 0 0 0]; 
        
        plot(Points(1,:),Points(2,:),'o')
        hold on
        for t=0:0.01:1
            T= [t^3  t^2  t  1];
            P1=T*B*Points(1,:)';
            P2=T*B*Points(2,:)';
            plot(P1,P2,'.') 
%             hold on
        end
        [rows, cols] = size(Points);
        line(Points(1,1:2), Points(2,1:2));
        line(Points(1,cols-1:cols), Points(2,cols-1:cols));
        hold off
    end

end