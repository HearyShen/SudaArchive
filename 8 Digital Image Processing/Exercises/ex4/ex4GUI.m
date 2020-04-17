function varargout = ex4GUI(varargin)
% EX4GUI MATLAB code for ex4GUI.fig
%      EX4GUI, by itself, creates a new EX4GUI or raises the existing
%      singleton*.
%
%      H = EX4GUI returns the handle to a new EX4GUI or the handle to
%      the existing singleton*.
%
%      EX4GUI('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in EX4GUI.M with the given input arguments.
%
%      EX4GUI('Property','Value',...) creates a new EX4GUI or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before ex4GUI_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to ex4GUI_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help ex4GUI

% Last Modified by GUIDE v2.5 22-Dec-2016 19:59:19

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @ex4GUI_OpeningFcn, ...
                   'gui_OutputFcn',  @ex4GUI_OutputFcn, ...
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


% --- Executes just before ex4GUI is made visible.
function ex4GUI_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to ex4GUI (see VARARGIN)


% Choose default command line output for ex4GUI
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes ex4GUI wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = ex4GUI_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in btn_openfile.
function btn_openfile_Callback(hObject, eventdata, handles)
% hObject    handle to btn_openfile (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global in;                  % 定义一个全局变量in，以便后期处理
[filename,pathname] = uigetfile({'*.png';'*.jpg';'*.tif'},'载入图像');  %选择图像路径
str = [pathname filename]   % 合成路径+文件名
in = imread(str);           % 读取图像
axes(handles.axes_raw);     % 使用axes_raw
cla(handles.axes_raw, 'reset');     % clear axes: 细节问题——保证显示不重叠，尺寸不出错
cla(handles.axes_done, 'reset');    % clear axes: 细节问题——保证显示不重叠，尺寸不出错
imshow(in);                 % 显示图像

% 交互细节：更新附注文字提示信息，提供准确易懂的使用体验
set(handles.text_attri, 'String', '属性');
str_raw = strcat('a) 原图', filename);
set(handles.text_raw, 'String', str_raw);
set(handles.text_done, 'String', 'b) 待变换');


% --- Executes on button press in btn_otsu.
function btn_otsu_Callback(hObject, eventdata, handles)
% hObject    handle to btn_otsu (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global in;

% 初始化：取图像副本，并计算基础数据
G_otsu = in;    % G_otsu矩阵为待处理的图像数据副本
[row_count,col_count] = size(G_otsu);   
N = row_count*col_count;   
L = 256;          % 程序处理目标为256灰度图

% 遍历阈值求方差：遍历0-255阈值，计算各阈值对应的方差
theta_squared = zeros(L,1); % 性能优化：初始化时静态分配频繁访问的方差内存空间，避免动态增长带来的性能损耗
for th=0:L-1
    F_a = length(find(G_otsu<=th))/N;   % 阈值以下区(a)比例
    F_b = length(find(G_otsu>th))/N;    % 阈值以上区(b)比例
    avg_a = mean(find(G_otsu<=th));     % 阈值以下区(a)均值
    avg_b = mean(find(G_otsu>th));      % 阈值以上区(b)均值
    avg = mean(G_otsu(:));              % 整体均值
    % 大津法求方差公式。注意：matlab中index从1开始
    theta_squared(th+1) = F_a*((avg_a - avg)^2) + F_b*((avg_b - avg)^2);
end

% 最优阈值：取最大方差项及其对应的阈值为最优阈值
[max_theta, index] = max(theta_squared) % 取最大方差项的方差及index
threshold = index - 1;  % 注意：matlab中index从1开始

% 二值化：根据取得的最优阈值将副本二值化以备显示
for i=1:row_count   
    for j=1:col_count   
        if G_otsu(i,j)>threshold   
            G_otsu(i,j)=255;   
        else   
            G_otsu(i,j)=0;   
        end   
    end   
end

% 显示图像
axes(handles.axes_done);   %使用第二个axes 
cla(handles.axes_done, 'reset');    % clear axes: 细节问题——保证显示不重叠，尺寸不出错
imshow(G_otsu);

% 交互细节：更新附注文字提示信息，提供准确易懂的使用体验
str_cap = strcat('Threshold = ', num2str(threshold));
set(handles.text_attri, 'String', str_cap);
set(handles.text_done, 'String', 'b) OTSU变换后');


% --- Executes on button press in btn_hough.
function btn_hough_Callback(hObject, eventdata, handles)
% hObject    handle to btn_hough (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global in;

axes(handles.axes_done);   %使用第二个axes 
cla(handles.axes_done, 'reset');    % clear axes: 细节问题——保证显示不重叠，尺寸不出错

% 初始化：取图像副本
G_hough = in;
% 二值化：使用canny算子提取边缘并二值化处理
BW = edge(G_hough,'canny');
% 调用hough，实现图像域到参数域 (Matlab API)
[H,T,R] = hough(BW);
% 调用houghpeaks，求取共线点，暂定目标个数为4 (Matlab API)
P  = houghpeaks(H,4,'threshold',ceil(0.3*max(H(:))));
% 调用houghlines，求出共线点对应参数的直线  (Matlab API)
lines = houghlines(BW,T,R,P,'FillGap',5,'MinLength',7);

% 显示图像
imshow(G_hough) % 图像
hold on
max_len = 0;
for k = 1:length(lines) % 遍历显示提取的边缘直线
   xy = [lines(k).point1; lines(k).point2];
   plot(xy(:,1),xy(:,2),'LineWidth',1,'Color','green');

   % 标记边缘线条的首位位置
   plot(xy(1,1),xy(1,2),'x','LineWidth',1,'Color','yellow');
   plot(xy(2,1),xy(2,2),'x','LineWidth',1,'Color','red');

   % 遍历时计算提取得到的最长边缘线段
   len = norm(lines(k).point1 - lines(k).point2);
   if ( len > max_len)
      max_len = len;
      xy_long = xy;
   end
end
% 交互细节：突出最长线段；更新附注文字提示信息，提供准确易懂的使用体验；
plot(xy_long(:,1),xy_long(:,2),'LineWidth',2,'Color','cyan');
str_cap = strcat('MaxLen = ', num2str(max_len));
set(handles.text_attri, 'String', str_cap);
set(handles.text_done, 'String', 'b) Hough变换后');
