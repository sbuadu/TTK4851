% comment
clear all;
clear all hidden; 
close all;
clc;

B = [];
while true 
temp = getImage();
B = [B ; temp]; % returns angle
angle = int8(B(1)/5);
ascii = angle+48;
symbol = char(ascii);
disp(angle)
disp(symbol);

end

 