function findColor(image)

resizeIm = 0.1;

image = ('green1.png');
image = imread(image);
image = imresize(image,resizeIm);
[m,n] = size(image);

red = image(:,:,1);
blue = image(:,:,3);
green = image - red - blue;
greenIntensity = rgb2gray(green);
greenBinary = imbinarize(greenIntensity);
s = regionprops(greenBinary,'centroid');
s.Centroid

imshow(greenBinary);
%viscircles(s.Centroid, 10);
%[i,j]=find(greenBinary == 1)

end