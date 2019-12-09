/*
	Amaizingly_simple_HPDL1414_library_for_arduino.cpp
	(or HPDL.cpp)
	Created by Mario Muñoz, April 24, 2017.
	Based from the DL1416Test.ino supplied by JoeN on Arduino Forums
	Released into the public domain.
*/

#include	"Arduino.h"
#include	"HPDL.h"

HPDL::HPDL(byte wri, byte ds0, byte ds1, byte d0, byte d1, byte d2, byte d3, byte d4, byte d5, byte d6)
{
	pinMode(wri, OUTPUT);
	pinMode(ds0, OUTPUT);
	pinMode(ds1, OUTPUT);
	pinMode(d0, OUTPUT);
	pinMode(d1, OUTPUT);
	pinMode(d2, OUTPUT);
	pinMode(d3, OUTPUT);
	pinMode(d4, OUTPUT);
	pinMode(d5, OUTPUT);
	pinMode(d6, OUTPUT);
	_wri 	= 	wri;
	_ds0	=	ds0;
	_ds1	=	ds1;
	
  output[0]=d0;
  output[1]=d1;
  output[2]=d2;
  output[3]=d3;
  output[4]=d4;
  output[5]=d5;
  output[6]=d6;
	
  charset[' ']  = 0b0100000;		//You can delete as many of these as you like in case you low on memory
  charset['!']  = 0b0100001;		
  charset['"']  = 0b0100010;
  charset['#']  = 0b0100011;
  charset['$']  = 0b0100100;
  charset['%']  = 0b0100101;
  charset['&']  = 0b0100110;
  charset['\''] = 0b0100111;
  
  charset['(']  = 0b0101000;
  charset[')']  = 0b0101001;
  charset['*']  = 0b0101010;
  charset['+']  = 0b0101011;
  charset[',']  = 0b0101100;
  charset['-']  = 0b0101101;
  charset['.']  = 0b0101110;
  charset['/']  = 0b0101111;
  
  charset['0']  = 0b0110000;
  charset['1']  = 0b0110001;
  charset['2']  = 0b0110010;
  charset['3']  = 0b0110011;
  charset['4']  = 0b0110100;
  charset['5']  = 0b0110101;
  charset['6']  = 0b0110110;
  charset['7']  = 0b0110111;
  
  charset['8']  = 0b0111000;  
  charset['9']  = 0b0111001;
  charset[':']  = 0b0111010;
  charset[';']  = 0b0111011;
  charset['<']  = 0b0111100;
  charset['=']  = 0b0111101;
  charset['>']  = 0b0111110;
  charset['?']  = 0b0111111;
  
  charset['@']  = 0b1000000;  
  charset['A']  = 0b1000001;
  charset['B']  = 0b1000010;
  charset['C']  = 0b1000011;
  charset['D']  = 0b1000100;
  charset['E']  = 0b1000101;
  charset['F']  = 0b1000110;
  charset['G']  = 0b1000111;
  
  charset['H']  = 0b1001000;  
  charset['I']  = 0b1001001;
  charset['J']  = 0b1001010;
  charset['K']  = 0b1001011;
  charset['L']  = 0b1001100;
  charset['M']  = 0b1001101;
  charset['N']  = 0b1001110;
  charset['O']  = 0b1001111;
  
  charset['P']  = 0b1010000;  
  charset['Q']  = 0b1010001;
  charset['R']  = 0b1010010;
  charset['S']  = 0b1010011;
  charset['T']  = 0b1010100;
  charset['U']  = 0b1010101;
  charset['V']  = 0b1010110;
  charset['W']  = 0b1010111;
  
  charset['X']  = 0b1011000;  
  charset['Y']  = 0b1011001;
  charset['Z']  = 0b1011010;
  charset['[']  = 0b1011011;
  charset['\\'] = 0b1011100;
  charset[']']  = 0b1011101;
  charset['^']  = 0b1011110;
  charset['_']  = 0b1011111;

  
}

void HPDL::putcc(byte ds,char d)
{	
	delay(1);
	digitalWrite(_wri, 1);
	delay(1);
	switch (ds)					//THIS DETERMINES TO WHICH DIGIT IS THE DISPLAY GOING TO WRITE
	{
		case 0:
		digitalWrite(_ds0, 1);
		digitalWrite(_ds1, 1);
		break;	
		case 1:
		digitalWrite(_ds0, 0);
		digitalWrite(_ds1, 1);
		break;
		case 2:
		digitalWrite(_ds0, 1);
		digitalWrite(_ds1, 0);
		break;
		case 3:
		digitalWrite(_ds0, 0);
		digitalWrite(_ds1, 0);
		break;		
		default:
		digitalWrite(_ds0, 1);
		digitalWrite(_ds1, 1);
	}
	
	for(byte i = 0 ; i < 7 ; i++)			//THIS IS WHERE ALL THE MAGIC HAPPENS. IT READS A BYTE FROM THE CHARSET ARRAY AND THEN TRANSFORMS IT TO INDIVUDUAL BITS
      {
        state = bitRead(charset[d], i);
        digitalWrite(output[i], state); 
      }
	delay(1);
	digitalWrite(_wri, 0);
	delay(5);
	digitalWrite(_wri, 1);
	return;
}
