function varargout = ex6(varargin)
% EX6 MATLAB code for ex6.fig
%      EX6, by itself, creates a new EX6 or raises the existing
%      singleton*.
%
%      H = EX6 returns the handle to a new EX6 or the handle to
%      the existing singleton*.
%
%      EX6('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in EX6.M with the given input arguments.
%
%      EX6('Property','Value',...) creates a new EX6 or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before ex6_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to ex6_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help ex6

% Last Modified by GUIDE v2.5 17-May-2017 17:01:44

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @ex6_OpeningFcn, ...
                   'gui_OutputFcn',  @ex6_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before ex6 is made visible.
function ex6_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to ex6 (see VARARGIN)

% Choose default command line output for ex6
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes ex6 wait for user response (see UIRESUME)
% uiwait(handles.figure1);

%--------------------- initial display ---------------------------
%----------------------- Refresh axis ----------------------------
% get params by retriving values from edit texts
[L, I_p, K_d, K_s, n, I_a, K_a, View] = retrive_values(handles);

% prepare axis and call light_effect func
light_effect(L, I_p, K_d, K_s, n, I_a, K_a, View, handles);



% --- Outputs from this function are returned to the command line.
function varargout = ex6_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;



function edit_inDirection_x_Callback(hObject, eventdata, handles)
% hObject    handle to edit_inDirection_x (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit_inDirection_x as text
%        str2double(get(hObject,'String')) returns contents of edit_inDirection_x as a double




% --- Executes during object creation, after setting all properties.
function edit_inDirection_x_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_inDirection_x (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit_inDirection_y_Callback(hObject, eventdata, handles)
% hObject    handle to edit_inDirection_y (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit_inDirection_y as text
%        str2double(get(hObject,'String')) returns contents of edit_inDirection_y as a double


% --- Executes during object creation, after setting all properties.
function edit_inDirection_y_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_inDirection_y (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit_inDirection_z_Callback(hObject, eventdata, handles)
% hObject    handle to edit_inDirection_z (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit_inDirection_z as text
%        str2double(get(hObject,'String')) returns contents of edit_inDirection_z as a double


% --- Executes during object creation, after setting all properties.
function edit_inDirection_z_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_inDirection_z (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit_inBrightness_Callback(hObject, eventdata, handles)
% hObject    handle to edit_inBrightness (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit_inBrightness as text
%        str2double(get(hObject,'String')) returns contents of edit_inBrightness as a double

% --- Executes during object creation, after setting all properties.
function edit_inBrightness_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_inBrightness (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit_surDisfussReflect_Callback(~, eventdata, handles)
% hObject    handle to edit_surDisfussReflect (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit_surDisfussReflect as text
%        str2double(get(hObject,'String')) returns contents of edit_surDisfussReflect as a double


% --- Executes during object creation, after setting all properties.
function edit_surDisfussReflect_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_surDisfussReflect (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit_envirBrightness_Callback(hObject, eventdata, handles)
% hObject    handle to edit_envirBrightness (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit_envirBrightness as text
%        str2double(get(hObject,'String')) returns contents of edit_envirBrightness as a double


% --- Executes during object creation, after setting all properties.
function edit_envirBrightness_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_envirBrightness (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit_envirReflect_Callback(hObject, eventdata, handles)
% hObject    handle to edit_envirReflect (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit_envirReflect as text
%        str2double(get(hObject,'String')) returns contents of edit_envirReflect as a double


% --- Executes during object creation, after setting all properties.
function edit_envirReflect_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_envirReflect (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit_surMirrorReflect_Callback(hObject, eventdata, handles)
% hObject    handle to edit_surMirrorReflect (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit_surMirrorReflect as text
%        str2double(get(hObject,'String')) returns contents of edit_surMirrorReflect as a double


% --- Executes during object creation, after setting all properties.
function edit_surMirrorReflect_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_surMirrorReflect (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit_surSmoothness_Callback(hObject, eventdata, handles)
% hObject    handle to edit_surSmoothness (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit_surSmoothness as text
%        str2double(get(hObject,'String')) returns contents of edit_surSmoothness as a double


% --- Executes during object creation, after setting all properties.
function edit_surSmoothness_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_surSmoothness (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit_surEnvirReflect_Callback(hObject, eventdata, handles)
% hObject    handle to edit_surEnvirReflect (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit_surEnvirReflect as text
%        str2double(get(hObject,'String')) returns contents of edit_surEnvirReflect as a double


% --- Executes during object creation, after setting all properties.
function edit_surEnvirReflect_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_surEnvirReflect (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


function edit_view_x_Callback(hObject, eventdata, handles)
% hObject    handle to edit_view_x (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit_view_x as text
%        str2double(get(hObject,'String')) returns contents of edit_view_x as a double


% --- Executes during object creation, after setting all properties.
function edit_view_x_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_view_x (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit_view_y_Callback(hObject, eventdata, handles)
% hObject    handle to edit_view_y (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit_view_y as text
%        str2double(get(hObject,'String')) returns contents of edit_view_y as a double


% --- Executes during object creation, after setting all properties.
function edit_view_y_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_view_y (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit_view_z_Callback(hObject, eventdata, handles)
% hObject    handle to edit_view_z (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit_view_z as text
%        str2double(get(hObject,'String')) returns contents of edit_view_z as a double


% --- Executes during object creation, after setting all properties.
function edit_view_z_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_view_z (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end

% --- Executes on button press in btn_refresh.
function btn_refresh_Callback(hObject, eventdata, handles)
% hObject    handle to btn_refresh (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

%-------------------------- Refresh axis --------------------------
% get params by retriving values from edit texts
[L, I_p, K_d, K_s, n, I_a, K_a, View] = retrive_values(handles);

% prepare axis and call light_effect func
light_effect(L, I_p, K_d, K_s, n, I_a, K_a, View, handles);


%========================== Retrive VALUES =========================
function [L, I_p, K_d, K_s, n, I_a, K_a, View] = retrive_values(handles)
% get values from edit texts
val_inDirection_x = str2double(get(handles.edit_inDirection_x, 'String'));
val_inDirection_y = str2double(get(handles.edit_inDirection_y, 'String'));
val_inDirection_z = str2double(get(handles.edit_inDirection_z, 'String'));
val_inBrightness = str2double(get(handles.edit_inBrightness, 'String'));

val_surDisfussReflect = str2double(get(handles.edit_surDisfussReflect, 'String'));
val_surMirrorReflect = str2double(get(handles.edit_surMirrorReflect, 'String'));
val_surSmoothness = str2double(get(handles.edit_surSmoothness, 'String'));


val_envirBrightness = str2double(get(handles.edit_envirBrightness, 'String'));
val_envirReflect = str2double(get(handles.edit_surEnvirReflect, 'String'));

val_view_x = str2double(get(handles.edit_view_x, 'String'));
val_view_y = str2double(get(handles.edit_view_y, 'String'));
val_view_z = str2double(get(handles.edit_view_z, 'String'));


% prepare params
L = [val_inDirection_x val_inDirection_y val_inDirection_z];
I_p = val_inBrightness;

K_d = val_surDisfussReflect;
K_s = val_surMirrorReflect;
n = val_surSmoothness;
 
I_a = val_envirBrightness;
K_a = val_envirReflect;

View = [val_view_x val_view_y val_view_z];


%========================== LIGHT EFFECT ===========================
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
 
% L = [-1 -1 -1];
% I_p = 1;
% 
% K_d = 1;
%  
% I_a = 0.1;
% K_a = 1;
 
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
