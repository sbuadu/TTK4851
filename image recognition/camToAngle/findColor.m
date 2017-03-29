function res = findColor(img)
% image is a 480 x 1920 matrix. image = [r g b] where r,g,b (480X640) 
%resizeIm = 0.7;
disp('In find color')
%image = ('double1.jpg');
%image = imread(image);
C = uint8(zeros(480,640,3));
C(:,:,1) = img(:,1:640);
C(:,:,2) = img(:,641:1280);
C(:,:,3) = img(:,1281:1920);

figure(1)
imshow(C);
image=C;
%image = imresize(C,resizeIm);
[m,n] = size(image);
image = imgaussfilt(image,2);
disp('m:');
disp(m);
disp('n:');
disp(n);

% red = image(:,1:640);
% %green = image(:,641:1280);
% blue = image(:,1281:1920);
% green = image - red; 

red = image(:,:,1);
blue = image(:,:,3);
% red_temp = uint8(zeros(48,64,3));
% blue_temp = uint8(zeros(48,64,3));
% red_temp(:,:,1)= red;
% red_temp(:,:,2)= red;
% red_temp(:,:,3)= red;
% blue_temp(:,:,1)= blue;
% blue_temp(:,:,2)= blue;
% blue_temp(:,:,3)= blue;
green = image - red - blue; 

greenIntensity = rgb2gray(green);
greenBinary = imbinarize(greenIntensity);
s = regionprops(greenBinary,'centroid');
centroids = cat(1, s.Centroid);
a = regionprops(greenBinary, 'area');
area = cat(1, a.Area);

figure(2)
imshow(greenBinary); 
if (centroids ~= 0 )
    hold on
    plot(centroids(:,1),centroids(:,2), 'b*')
    hold off
end 


[sortedValues,sortIndex] = sort(area(:),'descend');

frontPos = [0 0]; 
backPos = [0 0]; 
destination = [0,0];

if size(area,1) == 2
    frontPos = centroids(sortIndex(1),:);
    backPos = centroids(sortIndex(2),:);
    destination = [0,0];
elseif size(area,1)== 3
    destination = centroids(sortIndex(1),:);
    frontPos = centroids(sortIndex(2),:);
    backPos = centroids(sortIndex(3),:);
%else
    %error('did not find correct number of green spots');
end
   
    res = [frontPos(:) backPos(:) destination(:)]  ; 
    disp(res);

end