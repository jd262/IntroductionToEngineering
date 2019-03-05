#include "mbed.h"

float Calculate_Period(unsigned int Freq);

PwmOut led(LED_GREEN);
PwmOut Sound(D7);


Serial pc(USBTX, USBRX);

	#define A 440
	#define As 466
	#define B 493
	#define C 523
	#define Cs 554 
	#define D 587
	#define Ds 622
	#define E 659
	#define F 698
	#define Fs 739
	#define G 783
	#define Gs 830
	#define A4 880
	#define As4 932
	#define B4 986
	#define R 0
	
	#define AS 466
	#define CS 554
	#define DS 622
	#define FS 739
	#define GS 830
	
	#define sR 1
	#define eR 2
	#define qR 4
	#define hR 6
	
	#define sN 1
	#define eN 2
	#define qN 4
	#define dqN 5
	#define hN 6
	#define wN 10
	
	const unsigned int song1 [] =       {B, B, E, B, B, E, B, B, E, B, B, E, B, B, E, F, B, B, E, B, B, E, B, 
                                         B, E, B, B, E, B, B, E, F, B, B, E, B, B, E, B, B, E, B, B, E, B, B, 
                                         E, F, B, B, E, B, B, E, B, B, E, F, As, D, As, F, As, D, As, F, As, 
                                         D, As, F, As, D, As, G, C, E, C, G, C, E, C, G, C, E, C, G, C, E, C, 
                                         A4, Cs, E, Cs, A4, Cs, E, Cs, A4, Cs, E, Cs, A4, Cs, E, Cs, A4, D, F, 
                                         D, A4, D, F, D, A4, D, F, D, A4, D, F, D, As4, D, F, D, As4, D, F, D, 
                                         As4, D, F, D, As4, D, F, D, As4, D, F, D, As4, D, F, D, As4, D, F, D, 
                                         As4, D, F, D, A4, E,  B4, A4, Fs, G, R, E,  B4, A4, G,  Fs, R,  E, B4, 
                                         A4, Fs, G, R, E, B4, A4, G, Fs, F, F, F, F, R, F, F, R, F, F, F, F, 
                                         R, F, F, G, F, E, R };    
	const unsigned int notelength1 [] = {eN, eN, eN, eN, eN, eN, eN, eN, eN, eN, eN, eN, eN, eN, eN, eN, eN, eN, 
                                         eN, eN, eN, eN, eN, eN, eN, eN, eN, eN, eN, eN, eN, eN, eN, eN, eN, eN,
                                         eN, eN, eN, eN, eN, eN, eN, eN, eN, eN, eN, eN, eN, eN, eN, eN, eN, eN,
                                         eN, eN, wN, sN, sN, sN, sN, sN, sN, sN, sN, sN, sN, sN, sN, sN, sN, sN,
                                         sN, sN, sN, sN, sN, sN, sN, sN, sN, sN, sN, sN, sN, sN, sN, sN, sN, sN,
                                         sN, sN, sN, sN, sN, sN, sN, sN, sN, sN, sN, sN, sN, sN, sN, sN, sN, sN,
                                         sN, sN, sN, sN, sN, sN, sN, sN, sN, sN, sN, sN, sN, sN, sN, sN, sN, sN,
                                         sN, sN, sN, sN, sN, sN, sN, sN, sN, sN, sN, sN, sN, sN, sN, sN, sN, sN,
                                         sN, sN, sN, sN, sN, sN, sN, sN, sN, wN, dqN,dqN, dqN, dqN, qN, sR, dqN,
                                         dqN, dqN, dqN, qN, sR, dqN, dqN, dqN, dqN, qN, sR, dqN, dqN, dqN, dqN,
                                         qN, qN, qN, eN, eN, eR, qN, qN, hR, qN, qN, eN, eN, eR, qN, qN, qN, qN,
                                         wN, qR};
    const unsigned int song2 [] =       {R, AS, AS, DS, DS, DS, AS, AS, DS, F, F, DS, F, DS, F, F, G, GS, AS*2, 
                                         DS, AS, AS, DS, DS, DS, AS, DS, AS, F, F, F, G, GS, GS, GS, GS, F, G,
                                         GS, GS, GS, DS, DS, DS, AS*2, AS*2, AS*2, GS, G, F, F, F, F, F, G, GS,
                                         GS, AS*2, GS, F, G, GS, GS, GS, DS, C*2, C*2, C*2, AS*2, AS*2, GS, C*2,
                                         C*2, C*2, CS*2, C*2, AS*2, AS*2, GS, DS*2, C*2, AS*2, GS, DS*2, C*2,
                                         GS, GS, GS, GS, G, DS, DS, R};
	const unsigned int notelength2 [] = {2,  1,  2,  2,  1,  1,  2,  2,  2, 1, 2, 1 , 2,  2, 1, 1, 2,  2,  3  ,  2, 1 , 2 ,  2,  1,  1, 2 ,  2, 1 , 2 , 4, 1, 2,  1 , 8 ,  4,  1, 1, 1,  1,  4,  1,  1,  1,  1,  4  ,  1 ,  1   , 1   , 1, 1, 1, 1, 2, 2, 1,  1,  1,  3,  1, 1, 1,  4,  1,  1,  1, 1  , 1  , 1  ,  4  ,  1  ,  1, 1  , 2  , 3  , 1   , 1   , 1   ,  1  ,  2,  6  ,  3  ,  3   , 8 ,    4,   3 ,  3 ,  7,  1, 1 ,  3,  3,  10, 5};

		
	const unsigned char line1[] = "*****************************************************\r\n";
	const unsigned char line2[] = "*******        1 - GO GO POWER RANGERS        *******\r\n";
	const unsigned char line3[] = "*******     2 - BASIC WHITE GIRL THEME SONG   *******\r\n";  
	const unsigned char line4[] = "*****************************************************\r\n";
		
		
int main(void) 
{

	int select=0;
	pc.printf((char*)line1);
	pc.printf((char*)line2);
	pc.printf((char*)line3);
	pc.printf((char*)line4);
	pc.scanf("%d",&select);
    while (true)
	  {	
			if(select !=0 and select <= 2)
			{
				pc.printf("You Selected: %d\r\n", select);
			}
			else
			{
				pc.printf("Your Selection was invalid please choose between 1-2\r\n");
			}
			
			switch (select)
			{
				case 1:
				for(int i=0; i<sizeof(song1)/4;i++)
				{
					Sound.period(Calculate_Period(song1[i]));
					Sound= .35;
					for(int t=0; t<notelength1[i];t++)
					{
						wait(.08);
					}
				}
				break;
					
				case 2:
				for(int i = 0; i < sizeof(song2)/4; i++)
				{
					Sound.period(Calculate_Period(song2[i]));
					Sound= .2;
					for(int t=0; t<notelength2[i];t++)
					{
						wait(.2);
					}
				}
				break;
			
				default:
				break;
			}
	pc.printf("You may select another song.\r\n");
	select = 0;
	pc.scanf("%d",&select);
	
   }
}


float Calculate_Period(unsigned int Freq)
{
	  return(1/(float)Freq);
}
