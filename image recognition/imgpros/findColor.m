function findColor(image)

resizeIm = 0.1;

image = ('double1.jpg');
image = imread(image);
image = imresize(image,resizeIm);
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

imshow(greenBinary);
hold on
plot(centroids(:,1),centroids(:,2), 'b*')
hold off


[sortedValues,sortIndex] = sort(area(:),'descend');

if size(area,1) == 2
    frontPos = centroids(sortIndex(1),:)
    backPos = centroids(sortIndex(2),:)
elseif size(area,1)== 3
    destination = centroids(sortIndex(1),:)
    frontPos = centroids(sortIndex(2),:)
    backPos = centroids(sortIndex(3),:)
else
    error('did not find correct number of green spots');
end
    



%[i,j]=find(greenBinary == 1)

end