%% Author Info
% 沈家赟  1427405017
% 2017.5.17
%% ========================== LIGHT EFFECT ===========================
% --- draw light effect demo graph on the current axis
% L = [val_inDirection_x val_inDirection_y val_inDirection_z];
% I_p = val_inBrightness;
% 
% K_d = val_surDisfussReflect;
% K_s = val_surMirrorReflect;
% n = val_surSmoothness;
%  
% I_a = val_envirBrightness;
% K_a = val_envirReflect;
function light_effect(L, I_p, K_d, K_s, n, I_a, K_a, View, handles)

axes(handles.axes_main);    % select current axis
cla(handles.axes_main, 'reset');    % reset axis


[X,Y,Z]=cylinder(1,3);
 
for i=1:3
    p1=[X(1,i),Y(1,i),Z(1,i)];
    p2=[X(1,i+1),Y(1,i+1),Z(1,i+1)];
    p3=[X(2,i+1),Y(2,i+1),Z(2,i+1)];
    v(i,:)=cross(p2-p1,p3-p2);  % 求光照面的法向量
    cos_theta(i) = abs(dot(v(i,:),L)/(norm(v(i,:)*norm(L))));   % 光照面法线与入射光的夹角余弦值
    
    % 计算并暂存镜面反射所需数据
    vec_mirrorReflect(i,:) = L-2*(L*v(i,:)')*v(i,:);
    cos_phi(i) = abs(dot(View,vec_mirrorReflect(i,:))/(norm(View*norm(vec_mirrorReflect(i,:)))));   % 光照面法线与入射光的夹角余弦值
    
    p_mirror = I_p*K_s*cos_phi(i)^n;    % 镜面反射光
    p_disfuss = I_p*K_d*cos_theta(i);   % 漫反射光
    p_envir = I_a*K_a;                  % 环境反射光
    
    p = p_mirror + p_disfuss + p_envir;  % Phong光照模型
    if p < 0;
        p = 0;
    end
    if p > 1
        p = 1;
    end
    col(i,:) = [p p p]; % 遍历存储光照面的漫反射光
    
    fill3([X(1,i),X(1,i+1),X(2,i+1),X(2,i)],...
        [Y(1,i),Y(1,i+1),Y(2,i+1),Y(2,i)],...
        [Z(1,i),Z(1,i+1),Z(2,i+1),Z(2,i)],col(i,:)) % 根据col保存的光强值绘制图形面
    hold on
end

quiver3([0,0],[0,0],[0,0],[0,L(1)],[0,L(2)],[0,L(3)]);  % 单向箭头，标注入射光向量
axis off    % make axis invisible 
view(View);

hold off

end