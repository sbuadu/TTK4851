% Read in image into an array.
rgbImage = imread('table.jpg'); 
[rows, columns, numberOfColorBands] = size(rgbImage); 
% Display it.
subplot(2, 2, 1);
imshow(rgbImage, []);
title('Input Image', 'FontSize', 12);
% Enlarge figure to full screen.
set(gcf, 'units','normalized','outerposition',[0 0 1 1]);
% Give a name to the title bar.
set(gcf,'name','Shape Recognition Demo','numbertitle','off') 

rgbImage = imresize(rgbImage,0.1);

%using the edge detecting algorithm Canny (image segmentation)
red = rgbImage(:,:,1);
grayImage = rgb2gray(rgbImage);
% Display it.
subplot(2, 2, 2);
imshow(grayImage, []);
title('Grayscale Image', 'FontSize', 12);

% Binarize the image.
%binaryImage = grayImage > 120;
binaryImage = edge(grayImage,'canny', 0.3);
% Display it.
subplot(2, 2, 3);
imshow(binaryImage, []);
title('Initial (Noisy) Binary Image', 'FontSize', 12);

% Remove small objects.
binaryImage = bwareaopen(binaryImage, 200);
% Display it.
subplot(2, 2, 4);
imshow(binaryImage, []);
title('Cleaned Binary Image', 'FontSize', 12);

[labeledImage numberOfObjects] = bwlabel(binaryImage);
blobMeasurements = regionprops(labeledImage,...
	'Perimeter', 'Area', 'FilledArea', 'Solidity', 'Centroid'); 

% Get the outermost boundaries of the objects, just for fun.
filledImage = imfill(binaryImage, 'holes');
boundaries = bwboundaries(filledImage);

% Collect some of the measurements into individual arrays.
perimeters = [blobMeasurements.Perimeter];
areas = [blobMeasurements.Area];
filledAreas = [blobMeasurements.FilledArea];
solidities = [blobMeasurements.Solidity];
% Calculate circularities:
circularities = perimeters .^2 ./ (4 * pi * filledAreas);
% Print to command window.
fprintf('#, Perimeter,        Area, Filled Area, Solidity, Circularity\n');
for blobNumber = 1 : numberOfObjects
	fprintf('%d, %9.3f, %11.3f, %11.3f, %8.3f, %11.3f\n', ...
		blobNumber, perimeters(blobNumber), areas(blobNumber), ...
		filledAreas(blobNumber), solidities(blobNumber), circularities(blobNumber));
end

% Say what they are.
% IMPORTANT NOTE: depending on the aspect ratio of the rectangel or triangle
for blobNumber = 1 : numberOfObjects
	% Outline the object so the user can see it.
	thisBoundary = boundaries{blobNumber};
	subplot(2, 2, 2); % Switch to upper right image.
	hold on;
	% Display prior boundaries in blue
	for k = 1 : blobNumber-1
		thisBoundary = boundaries{k};
		plot(thisBoundary(:,2), thisBoundary(:,1), 'b', 'LineWidth', 3);
	end
	% Display this bounary in red.
	thisBoundary = boundaries{blobNumber};
	plot(thisBoundary(:,2), thisBoundary(:,1), 'r', 'LineWidth', 3);
	subplot(2, 2, 4); % Switch to lower right image.
	
	% Determine the shape.
	if circularities(blobNumber) < 1.2
		message = sprintf('The circularity of object #%d is %.3f,\nso the object is a circle',...
			blobNumber, circularities(blobNumber));
		shape = 'circle';
	elseif circularities(blobNumber) < 1.6
		message = sprintf('The circularity of object #%d is %.3f,\nso the object is a square',...
			blobNumber, circularities(blobNumber));
		shape = 'square';
	elseif circularities(blobNumber) > 1.6 && circularities(blobNumber) < 1.8
		message = sprintf('The circularity of object #%d is %.3f,\nso the object is an isocoles triangle',...
			blobNumber, circularities(blobNumber));
		shape = 'triangle';
	else
		message = sprintf('The circularity of object #%d is %.3f,\nso the object is something else.',...
			blobNumber, circularities(blobNumber));
		shape = 'something else';
	end
	% Display in overlay above the object
	overlayMessage = sprintf('Object #%d = %s\ncirc = %.2f, s = %.2f', ...
		blobNumber, shape, circularities(blobNumber), solidities(blobNumber));
	text(blobMeasurements(blobNumber).Centroid(1), blobMeasurements(blobNumber).Centroid(2), ...
		overlayMessage, 'Color', 'r');
	button = questdlg(message, 'Continue', 'Continue', 'Cancel', 'Continue');
	if strcmp(button, 'Cancel')
		break;
	end
end
