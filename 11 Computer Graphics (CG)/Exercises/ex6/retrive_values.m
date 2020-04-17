%% Author Info
% Éò¼ÒÚS  1427405017
% 2017.5.17
%% ========================== Retrive VALUES =========================
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

end