function table = findTable(image)
%identifies color and coordinates of checker pieces in a scene and writes
%to txt-file

searchRange = [30,50];
edgeThreshold = 0.3;
resizeIm = 0.1;

image = ('rotated.png');
image = imread(image);
%image = imresize(image,resizeIm);
[m,n] = size(image);

%using the edge detecting algorithm Canny (image segmentation)
red = image(:,:,1);
gray = rgb2gray(image);
BW2 = edge(gray,'canny', edgeThreshold);

imshow(BW2);

Ifill = imfill(BW2,'holes');
Iarea = bwareaopen(Ifill,100);
Ifinal = bwlabel(Iarea);
stat = regionprops(Ifinal,'boundingbox');
imshow(image); hold on;
for cnt = 1 : numel(stat)
    bb = stat(cnt).BoundingBox;
    rectangle('position',bb,'edgecolor','r','linewidth',2);
end