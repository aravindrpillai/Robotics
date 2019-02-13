

disp(' Ball Tracing Robo ');

imaqhwinfo('winvideo' , 2 );

video = videoinput('winvideo' , 2 ,'YUY2_320x240');

preview(video);
pause(14);

i = getsnapshot(video);
rgb = ycbcr2rgb(i);
%imshow(rgb);
%pause(3);

hsv = rgb2hsv(rgb);
%imshow(hsv);
%pause(3);


h = hsv(:,:,1);
%imshow(h);
%pause(3);

s = hsv(:,:,2);
%imshow(s);
%pause(3);

v = hsv(:,:,3);
%imshow(v);
%pause(3);

imtool(h);
imtool(s);
imtool(v);


h_ball = h>0.38 & h<0.49;
s_ball = s>0.86 & s<0.99;
v_ball = v>0 & v<1;

ball = h>0.38 & h<0.49 & s>0.86 & s<0.99

imtool(h_ball);
imtool(s_ball);
imtool(v_ball);


