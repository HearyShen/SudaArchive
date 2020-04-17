function touchable_bspline(P_init)
h_touchable = figure('WindowButtonDownFcn',@onBtnDown);
set(h_touchable, 'name', 'Touchable Bspline')
ah_Bspline = axes('SortMethod','childorder');

% P_init=[0  0  4  4; 0  2  4  0];
Bspline2D(ah_Bspline, P_init);
% axis ([1 10 1 10])
title('Click and drag a Point')

P_dynamic = P_init;
select = 0;     % Ĭ��δѡ�е�

   function onBtnDown(src,callbackdata)
     seltype = get(src,'SelectionType');
     
     if strcmp(seltype,'normal')
        cp = get(ah_Bspline,'CurrentPoint');
        
        % xinit = cp(1,1)
        % yinit = cp(1,2)
        
        select=0;
        P_delta(1,:) = abs(P_dynamic(1,:) - cp(1,1));    % x���룬ע�⣺��������abs
        P_delta(2,:) = abs(P_dynamic(2,:) - cp(1,2));    % y���룬ע�⣺��������abs
        [~, cols] = size(P_dynamic);    % cols����ǰBezier�������п��Ƶ�ĸ���
        for i=1:cols
            if(P_delta(1,i)<0.2 && P_delta(2,i)<0.2)    % ���ݹ��ɵ���Bezier���Ƶ����ѡ�к��ʵ��϶���
                select=i;   % ѡ��indexΪi�ĵ�
                set(src,'Pointer','circle'); % �ı�����ʽ���ṩѡ��ʱ��GUI��������
            end
        end
        
        set(src,'WindowButtonMotionFcn',@onBtnMotion);
        set(src,'WindowButtonUpFcn',@onBtnUp);

     end    
 
        function onBtnMotion(src,callbackdata)
           % ��갴�£��ҹ���ƶ�ʱ�����ݹ��λ�ö�̬���¿��Ƶ㣬��ʵʱ����
           cp = get(ah_Bspline,'CurrentPoint');
           if(select ~= 0)  % �п��Ƶ㱻ѡ��ʱ����̬���¿��Ƶ�λ��
               P_dynamic(1,select) = cp(1,1);
               P_dynamic(2,select) = cp(1,2);
           end
           Bspline2D(ah_Bspline, P_dynamic)
           
           drawnow
        end
   
        function onBtnUp(src,callbackdata)
           % ��갴��Up����ʾ�뿪�϶�״̬����ָ�ָ�벢ȡ����̬�ص�
            src.Pointer = 'arrow';
            src.WindowButtonMotionFcn = '';
            src.WindowButtonUpFcn = '';
        end
   end

end