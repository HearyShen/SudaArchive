function touchable_bspline(P_init)
h_touchable = figure('WindowButtonDownFcn',@onBtnDown);
set(h_touchable, 'name', 'Touchable Bspline')
ah_Bspline = axes('SortMethod','childorder');

% P_init=[0  0  4  4; 0  2  4  0];
Bspline2D(ah_Bspline, P_init);
% axis ([1 10 1 10])
title('Click and drag a Point')

P_dynamic = P_init;
select = 0;     % 默认未选中点

   function onBtnDown(src,callbackdata)
     seltype = get(src,'SelectionType');
     
     if strcmp(seltype,'normal')
        cp = get(ah_Bspline,'CurrentPoint');
        
        % xinit = cp(1,1)
        % yinit = cp(1,2)
        
        select=0;
        P_delta(1,:) = abs(P_dynamic(1,:) - cp(1,1));    % x距离，注意：求距离需加abs
        P_delta(2,:) = abs(P_dynamic(2,:) - cp(1,2));    % y距离，注意：求距离需加abs
        [~, cols] = size(P_dynamic);    % cols即当前Bezier曲线所有控制点的个数
        for i=1:cols
            if(P_delta(1,i)<0.2 && P_delta(2,i)<0.2)    % 根据光标采点与Bezier控制点距离差，选中合适的拖动点
                select=i;   % 选中index为i的点
                set(src,'Pointer','circle'); % 改变光标样式，提供选中时的GUI交互反馈
            end
        end
        
        set(src,'WindowButtonMotionFcn',@onBtnMotion);
        set(src,'WindowButtonUpFcn',@onBtnUp);

     end    
 
        function onBtnMotion(src,callbackdata)
           % 鼠标按下，且光标移动时，根据光标位置动态更新控制点，并实时绘制
           cp = get(ah_Bspline,'CurrentPoint');
           if(select ~= 0)  % 有控制点被选中时，动态更新控制点位置
               P_dynamic(1,select) = cp(1,1);
               P_dynamic(2,select) = cp(1,2);
           end
           Bspline2D(ah_Bspline, P_dynamic)
           
           drawnow
        end
   
        function onBtnUp(src,callbackdata)
           % 鼠标按键Up，表示离开拖动状态，则恢复指针并取消动态回调
            src.Pointer = 'arrow';
            src.WindowButtonMotionFcn = '';
            src.WindowButtonUpFcn = '';
        end
   end

end