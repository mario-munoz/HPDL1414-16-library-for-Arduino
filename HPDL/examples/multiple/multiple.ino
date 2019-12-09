#include <HPDL.h>

int W0=16;
int W1=17;
int S0=3;
int S1=2;
int D0=10;
int D1=9;
int D2=8;
int D3=7;
int D4=6;
int D5=5;
int D6=4;

HPDL dip1(W0,S0,S1,D0,D1,D2,D3,D4,D5,D6);
HPDL dip2(W1,S0,S1,D0,D1,D2,D3,D4,D5,D6);

void initap()
{
  digitalWrite(W0, HIGH);
  digitalWrite(W1, HIGH);
  digitalWrite(S0, LOW);
  digitalWrite(S1, LOW);
  digitalWrite(D0, LOW);
  digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(D4, LOW);
  digitalWrite(D5, LOW);
  digitalWrite(D6, LOW);
}

void setup() {
  // put your setup code here, to run once:
dip1.putcc(0,'T');
dip1.putcc(1,'E');
dip1.putcc(2,'S');
dip1.putcc(3,'T');
dip2.putcc(0,'H');
dip2.putcc(1,'P');
dip2.putcc(2,'D');
dip2.putcc(3,'L');

}

void loop() {
  // put your main code here, to run repeatedly:

}
