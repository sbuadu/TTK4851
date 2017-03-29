fprintf('Function started')
b=Bluetooth('MakerStudio',1);
fopen(b);

for i=1:1:15      
    fprintf('\n\n')
fprintf('Value sendt to arduino:  %d\n', i)
fwrite(b, i); 

in1 = fscanf(b,'%d');
fprintf('What arduino received %d \n',in1); 

pause(2)
end

 fclose(b)