#include <reg51.h>
#define swtchs P1
#define leds P3
#define segments P2
sbit seg1=P0^2;
sbit seg2=P0^3;
sbit buzzerout=P0^1;
sbit bulbout=P0^0;
unsigned char SegData[10]= {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};

void main(){
	unsigned int k,D1,D2;
	unsigned char swtchinput;
	swtchs=0xff;
	while(1){
		
		swtchinput=swtchs;
		leds=swtchinput;
		
		D1=((P1>>4) & 0x0F);
		D2=(P1 & 0x0F);

		segments=SegData[D1];
		seg1=0;
		for(k=0;k<10000;k++);
		seg1=1;
		
		segments=SegData[D2];
		seg2=0;
		for(k=0;k<10000;k++);
		seg2=1;
		
		if(swtchinput==0x13)
		{
				bulbout=0;
				buzzerout=0;			
		}
		else
		{
				buzzerout=0;
				bulbout=1;
				buzzerout=1;
		}
	}
}