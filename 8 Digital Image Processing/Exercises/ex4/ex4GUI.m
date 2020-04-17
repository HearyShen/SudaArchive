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
global in;                  % ����һ��ȫ�ֱ���in���Ա���ڴ���
[filename,pathname] = uigetfile({'*.png';'*.jpg';'*.tif'},'����ͼ��');  %ѡ��ͼ��·��
str = [pathname filename]   % �ϳ�·��+�ļ���
in = imread(str);           % ��ȡͼ��
axes(handles.axes_raw);     % ʹ��axes_raw
cla(handles.axes_raw, 'reset');     % clear axes: ϸ�����⡪����֤��ʾ���ص����ߴ粻����
cla(handles.axes_done, 'reset');    % clear axes: ϸ�����⡪����֤��ʾ���ص����ߴ粻����
imshow(in);                 % ��ʾͼ��

% ����ϸ�ڣ����¸�ע������ʾ��Ϣ���ṩ׼ȷ�׶���ʹ������
set(handles.text_attri, 'String', '����');
str_raw = strcat('a) ԭͼ', filename);
set(handles.text_raw, 'String', str_raw);
set(handles.text_done, 'String', 'b) ���任');


% --- Executes on button press in btn_otsu.
function btn_otsu_Callback(hObject, eventdata, handles)
% hObject    handle to btn_otsu (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global in;

% ��ʼ����ȡͼ�񸱱����������������
G_otsu = in;    % G_otsu����Ϊ�������ͼ�����ݸ���
[row_count,col_count] = size(G_otsu);   
N = row_count*col_count;   
L = 256;          % ������Ŀ��Ϊ256�Ҷ�ͼ

% ������ֵ�󷽲����0-255��ֵ���������ֵ��Ӧ�ķ���
theta_squared = zeros(L,1); % �����Ż�����ʼ��ʱ��̬����Ƶ�����ʵķ����ڴ�ռ䣬���⶯̬�����������������
for th=0:L-1
    F_a = length(find(G_otsu<=th))/N;   % ��ֵ������(a)����
    F_b = length(find(G_otsu>th))/N;    % ��ֵ������(b)����
    avg_a = mean(find(G_otsu<=th));     % ��ֵ������(a)��ֵ
    avg_b = mean(find(G_otsu>th));      % ��ֵ������(b)��ֵ
    avg = mean(G_otsu(:));              % �����ֵ
    % ����󷽲ʽ��ע�⣺matlab��index��1��ʼ
    theta_squared(th+1) = F_a*((avg_a - avg)^2) + F_b*((avg_b - avg)^2);
end

% ������ֵ��ȡ��󷽲�����Ӧ����ֵΪ������ֵ
[max_theta, index] = max(theta_squared) % ȡ��󷽲���ķ��index
threshold = index - 1;  % ע�⣺matlab��index��1��ʼ

% ��ֵ��������ȡ�õ�������ֵ��������ֵ���Ա���ʾ
for i=1:row_count   
    for j=1:col_count   
        if G_otsu(i,j)>threshold   
            G_otsu(i,j)=255;   
        else   
            G_otsu(i,j)=0;   
        end   
    end   
end

% ��ʾͼ��
axes(handles.axes_done);   %ʹ�õڶ���axes 
cla(handles.axes_done, 'reset');    % clear axes: ϸ�����⡪����֤��ʾ���ص����ߴ粻����
imshow(G_otsu);

% ����ϸ�ڣ����¸�ע������ʾ��Ϣ���ṩ׼ȷ�׶���ʹ������
str_cap = strcat('Threshold = ', num2str(threshold));
set(handles.text_attri, 'String', str_cap);
set(handles.text_done, 'String', 'b) OTSU�任��');


% --- Executes on button press in btn_hough.
function btn_hough_Callback(hObject, eventdata, handles)
% hObject    handle to btn_hough (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global in;

axes(handles.axes_done);   %ʹ�õڶ���axes 
cla(handles.axes_done, 'reset');    % clear axes: ϸ�����⡪����֤��ʾ���ص����ߴ粻����

% ��ʼ����ȡͼ�񸱱�
G_hough = in;
% ��ֵ����ʹ��canny������ȡ��Ե����ֵ������
BW = edge(G_hough,'canny');
% ����hough��ʵ��ͼ���򵽲����� (Matlab API)
[H,T,R] = hough(BW);
% ����houghpeaks����ȡ���ߵ㣬�ݶ�Ŀ�����Ϊ4 (Matlab API)
P  = houghpeaks(H,4,'threshold',ceil(0.3*max(H(:))));
% ����houghlines��������ߵ��Ӧ������ֱ��  (Matlab API)
lines = houghlines(BW,T,R,P,'FillGap',5,'MinLength',7);

% ��ʾͼ��
imshow(G_hough) % ͼ��
hold on
max_len = 0;
for k = 1:length(lines) % ������ʾ��ȡ�ı�Եֱ��
   xy = [lines(k).point1; lines(k).point2];
   plot(xy(:,1),xy(:,2),'LineWidth',1,'Color','green');

   % ��Ǳ�Ե��������λλ��
   plot(xy(1,1),xy(1,2),'x','LineWidth',1,'Color','yellow');
   plot(xy(2,1),xy(2,2),'x','LineWidth',1,'Color','red');

   % ����ʱ������ȡ�õ������Ե�߶�
   len = norm(lines(k).point1 - lines(k).point2);
   if ( len > max_len)
      max_len = len;
      xy_long = xy;
   end
end
% ����ϸ�ڣ�ͻ����߶Σ����¸�ע������ʾ��Ϣ���ṩ׼ȷ�׶���ʹ�����飻
plot(xy_long(:,1),xy_long(:,2),'LineWidth',2,'Color','cyan');
str_cap = strcat('MaxLen = ', num2str(max_len));
set(handles.text_attri, 'String', str_cap);
set(handles.text_done, 'String', 'b) Hough�任��');
