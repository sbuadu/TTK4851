function [ image ] = getImage(~)
%UNTITLED3 Summary of this function goes here
%   Detailed explanation goes here
cam = webcam('Logitech-kamera');
%if mod(t,5) == 0
img = snapshot(cam);

r = uint8(img(:,:,1));
g = uint8(img(:,:,2));
b = uint8(img(:,:,3));

% r = img(:,1:640);
% g = img(:,641:1280);
% b = img(:,1281:1920);
image = [r g b];
%imshow(img);
% C = zeros(480,640,3);
% C(:,:,1) = t(:,1:640);
% C(:,:,2) = t(:,641:1280);
% C(:,:,3) = t(:,1281:1920);
% image(C)
size(img)
size(image)
    %res = getPosAndDestination(img);
    %pause(5);
%end
clear cam; 

end

