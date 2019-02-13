
ser = serial('com25');
fopen(ser);



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
        fwrite(ser,'S');

    case 6
        disp('right bottom');
	fwrite(ser,'S');


    case 7
        disp('right center');
	fwrite(ser,'R');

    case 9
        disp('left top');
	fwrite(ser,'S');

    case 10
        disp('left bottom');
	fwrite(ser,'S');

    case 11
        disp('left center');
	fwrite(ser,'L');

    case 13
        disp('middle Up');
        fwrite(ser,'F');
 

    case 14
        disp('middle down');
	fwrite(ser,'B');


    otherwise
        disp('stop');
	fwrite(ser,'S');


end




end














