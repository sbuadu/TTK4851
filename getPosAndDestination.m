function res = getPosAndDestination(img)

res = 0; 

r = img(:,:,1); 
g = img(:,:,2); 
b = img(:,:,3)

image(:,:,1) = r;
image(:,:,2) = g;
image(:,:,3) = b;
%resizeIm = 0.1;

[m,n] = size(image);

red = image(:,:,1);
blue = image(:,:,3);
green = image - red;
greenIntensity = rgb2gray(green);
greenBinary = imbinarize(greenIntensity);
s = regionprops(greenBinary,'centroid');
centroids = cat(1, s.Centroid);
a = regionprops(greenBinary, 'area');
area = cat(1, a.Area);

disp('Hello')
figure;
imshow(greenBinary);
hold on
plot(centroids(:,1),centroids(:,2), 'b*')
hold off
disp('Hello')

[sortedValues,sortIndex] = sort(area(:),'descend');

if size(area,1) == 2
    frontPos = centroids(sortIndex(1),:);
    backPos = centroids(sortIndex(2),:);
    destination = [0,0];
    disp('Hello')
elseif size(area,1)== 3
    destination = centroids(sortIndex(1),:);
    frontPos = centroids(sortIndex(2),:);
    backPos = centroids(sortIndex(3),:);
    disp('Hello')
else
    frontPos = [0, 0];
    backPos = [0,0];
    destination = [0,0];
    disp('didnt findHello')
    
end
res = [frontPos(1), frontPos(2), backPos(1),backPos(2), destination(1),destination(2)]

end
