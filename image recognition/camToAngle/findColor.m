function res = findColor(img)
% image is a 480 x 1920 matrix. image = [r g b] where r,g,b (480X640) 
%resizeIm = 0.7;

% Restructure img to image format. 
[x,y] = size(img);
width = y/3; 
image = uint8(zeros(x,width,3));
image(:,:,1) = img(:,1:width);
image(:,:,2) = img(:,width+1:width*2);
image(:,:,3) = img(:,width*2+1:y);

% Display original image 
figure(1)
imshow(image);

% Smoothing picture with a built in 2-D Gaussian smoothing kernel 
[m,n] = size(image);
image = imgaussfilt(image,2);

%display smoothed image 
figure(2)
imshow(image);

% Remove red from picture to enhance green. 
red = image(:,:,1);
blue = image(:,:,3);
blue1 = 0.5*blue;
green = image - red - blue1; % - blue; 

% display black and green picture
figure(3)
imshow(green);


greenIntensity = rgb2gray(green);
greenBinary = imbinarize(greenIntensity);
s = regionprops(greenBinary,'centroid');
centroids = cat(1, s.Centroid);
a = regionprops(greenBinary, 'area');
area = cat(1, a.Area);

figure(4)
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
else
    disp('did not find correct number of green spots');
end
   
    res = [frontPos(:) backPos(:) destination(:)]  ; 

end