
import java.awt.Robot;
import java.awt.event.*;
mouse = Robot;
x_pos = 600;
y_pos = 400;
mouse.mouseMove(x_pos,y_pos);		

vid=videoinput('winvideo',1,'YUY2_320x240');

preview(vid);
pause(1);

x1 = 120;
x2 = 200;
y1 = 90;
y2 = 150;
e = 0;
rbuf =0;
cbuf =0;



while(1)
   
i=getsnapshot(vid);
q = ycbcr2rgb(i);
hsv = rgb2hsv(q);

h = hsv(:,:,1);
s = hsv(:,:,2);
v = hsv(:,:,3);

z = h>0.30 & h<0.50 & s>0.75;
%imshow(z);

se = strel('disk',5);
o=imopen(z,se);
c = imclose(o ,se);
imshow (c);

%pause(0.1);

[l,n] = bwlabel(c);



for k=1:n

[row,col] = find(l==k);
rbuf = mean(row);
cbuf = mean(col);
e = ((cbuf>x1)*8 + (cbuf<x2)*4 + (rbuf>y1)*2 + (rbuf<y2));

end

switch(e)
    case 5
        disp('right top');
        x_pos = x_pos+15;
        y_pos = y_pos-15;
        
    case 6
        disp('right bottom');
        x_pos = x_pos+15;
        y_pos = y_pos+15;
        
    case 7
        disp('right center');
        x_pos = x_pos+15;
        
    case 9
        disp('left top');
        x_pos = x_pos-15;
        y_pos = y_pos-15;
        
    case 10
        disp('left bottom');
	x_pos = x_pos-15;
        y_pos = y_pos+15;
        
    case 11
        disp('left center');
        x_pos = x_pos-15;
        
    case 13
        disp('middle Up');
        y_pos = y_pos-15;
        
    case 14
        disp('middle down');
	    y_pos = y_pos+15;
        
    otherwise
        disp('stop');
end

mouse.mouseMove(x_pos,y_pos);


end



