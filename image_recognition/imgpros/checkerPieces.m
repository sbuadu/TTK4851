function coordColor = checkerPieces(image)
%identifies color and coordinates of checker pieces in a scene and writes
%to txt-file

searchRange = [30,50];
edgeThreshold = 0.3;
resizeIm = 0.1;

image = ('test.jpg');
image = imread(image);
image = imresize(image,resizeIm);
[m,n] = size(image)

%makes sure all scenes starts with a red field
if image(5,5,3)>image(5,5,1)
    image = fliplr(image);
end

%using the edge detecting algorithm Canny (image segmentation)
red = image(:,:,1);
gray = rgb2gray(image);
BW2 = edge(gray,'canny', edgeThreshold);

imshow(BW2);

%using the circle Hough transform to identify the checker pieces 
%(object recognition)
%[centers, radii, metric] = imfindcircles(BW2,[20 40]);
[centers, radii, metric] = imfindcircles(BW2,searchRange);
[m,n] = size(centers);
antCircles = m
centersStrong5 = centers(1:antCircles,:);
radiiStrong5 = radii(1:antCircles);
metricStrong5 = metric(1:antCircles);

imshow(image);
viscircles(centersStrong5, radiiStrong5,'EdgeColor','b');


end