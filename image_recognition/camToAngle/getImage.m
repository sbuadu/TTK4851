function [ B ] = getImage()
%UNTITLED3 Summary of this function goes here
%   Detailed explanation goes here
% Comment
% Take picture and store in variable img.  
cam = webcam('Logitech-kamera');
img = snapshot(cam);

% Restructure image to a matrix 
r = uint8(img(:,:,1));
g = uint8(img(:,:,2));
b = uint8(img(:,:,3));
image = [r g b];

% run findcolor and findangle. 
[A] = findColor(image);
B = findAngle(A(1),A(2),A(3),A(4),A(5),A(6));

clear cam; 

end

