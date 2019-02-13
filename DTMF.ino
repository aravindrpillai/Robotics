
const int dtmf_in_pin_1 = 2;
const int dtmf_in_pin_2 = 3;
const int dtmf_in_pin_3 = 4;
const int dtmf_in_pin_4 = 5;
int a,b,c,d,pre_num,num;
void setup(){
 
 pinMode(dtmf_in_pin_1,INPUT);
 pinMode(dtmf_in_pin_2,INPUT);
 pinMode(dtmf_in_pin_3,INPUT);
 pinMode(dtmf_in_pin_4,INPUT);
 Serial.begin(9600); 
}

void loop(){
 
 if(digitalRead(dtmf_in_pin_1) == HIGH) a=1; else a=0;
 if(digitalRead(dtmf_in_pin_2) == HIGH) b=1; else b=0;
 if(digitalRead(dtmf_in_pin_3) == HIGH) c=1; else c=0;
 if(digitalRead(dtmf_in_pin_4) == HIGH) d=1; else d=0;
 
   if((a==0) && (b==0) && (c==0) && (d==0)) num = 0;
   if((a==0) && (b==0) && (c==0) && (d==1)) num = 1;
   if((a==0) && (b==0) && (c==1) && (d==0)) num = 2;
   if((a==0) && (b==0) && (c==1) && (d==1)) num = 3;
   if((a==0) && (b==1) && (c==0) && (d==0)) num = 4;
   if((a==0) && (b==1) && (c==0) && (d==1)) num = 5;
   if((a==0) && (b==1) && (c==1) && (d==0)) num = 6;
   if((a==0) && (b==1) && (c==1) && (d==1)) num = 7;
   if((a==1) && (b==0) && (c==0) && (d==0)) num = 8;
   if((a==1) && (b==0) && (c==0) && (d==1)) num = 9;
   
   if(pre_num != num )  Serial.println(num);
 
 pre_num = num;
 
}
