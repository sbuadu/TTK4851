clear all;
clear all hidden; 
close all;
clc;
%global cam; 
%cam = webcam('Logitech-kamera');
%sim('picpicpic');
B = [];
while true 
temp = getImage();
B = [B ; temp];
end

