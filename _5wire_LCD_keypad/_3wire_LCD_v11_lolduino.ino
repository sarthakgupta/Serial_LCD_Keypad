int latchPin = 13;
int clockPin = 12;
int dataPin = 11;

void serial_LCD_out(int n1,int n0)
{
    shiftOut(dataPin, clockPin, MSBFIRST, n0);  
    shiftOut(dataPin, clockPin, MSBFIRST, n1+16);  
    digitalWrite(latchPin, HIGH);
    delayMicroseconds(1);
    digitalWrite(latchPin, LOW);
    
    delay(2);
    
    shiftOut(dataPin, clockPin, MSBFIRST, n0);  
    shiftOut(dataPin, clockPin, MSBFIRST, n1);  
    digitalWrite(latchPin, HIGH);
    delayMicroseconds(1);
    digitalWrite(latchPin, LOW);
    //delayMicroseconds(40);
}   

void serial_LCD_out_1(int n1,int n0)
{
    shiftOut(dataPin, clockPin, MSBFIRST, n0);  
    shiftOut(dataPin, clockPin, MSBFIRST, n1);  
    digitalWrite(latchPin, HIGH);
    delayMicroseconds(1);
    digitalWrite(latchPin, LOW);
}   

void print_number(int n)
{   
    serial_LCD_out(35,0);
    serial_LCD_out(32+n,255);
    delayMicroseconds(40); 
}  

void disp_clear()
{
    serial_LCD_out(0,0);
    serial_LCD_out(1,0);
}

void disp_startpoint()
{
    disp_clear();
    serial_LCD_out(8,0);
    serial_LCD_out(0,0);
}

void lcd_init()
{ 
    delay(15);
    serial_LCD_out(3,0);
    delayMicroseconds(4500);
    serial_LCD_out(3,0);
    delayMicroseconds(150);
    
    serial_LCD_out(3,0);
    delayMicroseconds(4500);
    serial_LCD_out(2,0);
    
    //Function Set interface to 4-bit
    serial_LCD_out(2,0);
    serial_LCD_out(8,0);
    
    //Display on
    serial_LCD_out(0,0);
    serial_LCD_out(12,0);
    
    //Display Clear
    serial_LCD_out(0,0);
    serial_LCD_out(1,0);
    
    //Entry Mode Set
    serial_LCD_out(0,0);
    serial_LCD_out(6,0);
  
    //RAM address offset 0x80
    serial_LCD_out(8,0);
    serial_LCD_out(0,0);
}  

void setup() 
{
  //set pins to output so you can control the shift register
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(10,INPUT);
  pinMode(9,INPUT);
 
  digitalWrite(latchPin, LOW);
  serial_LCD_out(0,0);

  lcd_init();   
  
  //Write #
  serial_LCD_out(34,255);
  serial_LCD_out(35,255);
  delayMicroseconds(40);
  Serial.begin(9600);
    
}

int a = 128;

void loop() 
{
 serial_LCD_out_1(0,255);
 
 //Checking row1(consisting of 8 switches)  
  if(digitalRead(9)==1)
     {
      serial_LCD_out_1(0,1);
      if(digitalRead(9)==1)
         {
         disp_startpoint();
         print_number(1);
         }
      serial_LCD_out_1(0,2);
      if(digitalRead(9)==1)
         {
         disp_startpoint();
         print_number(2);
         }
      serial_LCD_out_1(0,4);
      if(digitalRead(9)==1)
         {
         disp_startpoint();
         print_number(3);
         }
      serial_LCD_out_1(0,8);
      if(digitalRead(9)==1)
         {
         disp_startpoint();
         print_number(4);
         }
      serial_LCD_out_1(0,16);
      if(digitalRead(9)==1)
         {
         disp_startpoint();
         print_number(5);
         }
      serial_LCD_out_1(0,32);
      if(digitalRead(9)==1)
         {
         disp_startpoint();
         print_number(6);
         }
      serial_LCD_out_1(0,64);
      if(digitalRead(9)==1)
         {
         disp_startpoint();
         print_number(7);
         }
      serial_LCD_out_1(0,128);
      if(digitalRead(9)==1)
         {
         disp_startpoint();
         print_number(8);
         }
     }
  //Checking row 2(consisting of 8 switches  
  else if(digitalRead(10)==1)
     {
      serial_LCD_out_1(0,1);
      if(digitalRead(10)==1)
         {
         disp_startpoint();
         print_number(9);
         }
      serial_LCD_out_1(0,2);
      if(digitalRead(10)==1)
         {
         disp_startpoint();
         print_number(1);
         print_number(0);
         }
      serial_LCD_out_1(0,4);
      if(digitalRead(10)==1)
          {
         disp_startpoint();
         print_number(1);
         print_number(1);
         }
      serial_LCD_out_1(0,8);
      if(digitalRead(10)==1)
         {
         disp_startpoint();
         print_number(1);
         print_number(2);
         }
      serial_LCD_out_1(0,16);
      if(digitalRead(10)==1)
         {
         disp_startpoint();
         print_number(1);
         print_number(3);
         }
      serial_LCD_out_1(0,32);
      if(digitalRead(10)==1)
          {
         disp_startpoint();
         print_number(1);
         print_number(4);
         }
      serial_LCD_out_1(0,64);
      if(digitalRead(10)==1)
         {
         disp_startpoint();
         print_number(1);
         print_number(5);
         }
      serial_LCD_out_1(0,128);
      if(digitalRead(10)==1)
        {
          disp_startpoint();
          print_number(1);
          print_number(6);
        }
     }
     
}
