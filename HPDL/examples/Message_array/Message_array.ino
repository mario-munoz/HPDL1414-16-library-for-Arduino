/* Test code for the HPDL.h Library. 
 * Created by Mario Muñoz, April 24, 2017.
 * Released into the publlic domain.
 * 
 * This will work with the HPDL1414 or HPDL1416
 * Characters used have to CAPS or else they
 * won't be displayed.
 */


#include<HPDL.h>

HPDL dip(2,3,4,5,6,7,8,9,10,11);  //(WR,A0,A1,D0,D1,D2,D3,D4,D5,D6) PIN NUMBERS
char msg[]="SKOOKUM AS FRIGG";    //CHAR ARRAY ALL CAPS
int msgsize=strlen(msg);   
       
void setup() {
}

void loop() {
for(int i=0; i<msgsize ;i++)    
{
char d0=(msg[i]);
char d1=(msg[i+1]);
char d2=(msg[i+2]);
char d3=(msg[i+3]);
dip.putcc(0,d0);
dip.putcc(1,d1);
dip.putcc(2,d2);
dip.putcc(3,d3);
delay(300);
}
}
