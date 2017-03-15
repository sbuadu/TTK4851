function alpha =  findAngle(frontx, fronty, backx, backy, pointx, pointy)

%%setting the coordinates for the middle of the car 
if frontx < backx
    carx = frontx + abs(backx - frontx)/2; 
else
    carx = backx + abs(backx - frontx)/2; 
end

if fronty < backy
    cary = fronty + abs(backy - fronty)/2; 
else
    cary = backy + abs(backy - fronty)/2;  
end


%%finding the vector between car and destination 
deltax = pointx - carx; 
deltay = pointy-cary; 
delta = [deltax deltay]; 
%%tvector from rotation point to frot of vehicle
betax = frontx - carx;
betay = fronty-cary; 
beta = [betax betay]; 

alpha = atan2(beta(2), beta(1)) - atan2(delta(2), delta(1)); 

alpha = alpha*180/pi; 

if alpha > 180
alpha = alpha - 360; 
end
% 
% figure
% plot(frontx,fronty,'ro'); 
% hold on; 
% plot(backx,backy,'bo'); 
% plot(pointx,pointy,'go')
% plot(carx,cary,'x')
% plot([frontx backx], [fronty backy]); 
% plot([carx pointx], [cary pointy]); 

left = @(x)6.520934182*10^(-3)*x^2 + 53.90658398*x^(1/2) - 124.6841231; 
right =@(x)5.109266313*10^(-3)*x^2 + 63.03130035*x^(1/2) - 182.2983324; 
end