#pragma once
#include "iGraphics.h"
#include "variable.h"
#include <string.h>

void character () {

	/********* Chose Characters *********/
	

	char back[] = "Images//Game_Backgroun.bmp";      //// Background
	iShowBMP(0, 0, back);

	iSetColor(255, 255, 0);
	char text[] = "Choose Your Character";
	iText(300, 520, text, GLUT_BITMAP_HELVETICA_18);   

	char c1[] = "Images//charecter//BMP//1.bmp";     ////// Zigzag Zap.
	iShowBMP2(50, 300, c1, 0);																							//1)
																														//2) 
	iSetColor(250, 23, 0);																													//3) 
																														//4) 
	char text1[] = "1.Zigzag Zap";
	iText(50, 280, text1, GLUT_BITMAP_HELVETICA_18);
	char c2[] = "Images//charecter//BMP//p2_0.bmp";   //////// Zodiac Snipe.
	iShowBMP2(220, 300, c2, 0);

	char text2[] = "2.Zodiac Snipe";
	iText(220, 280, text2, GLUT_BITMAP_HELVETICA_18);

	char c3[] = "Images//charecter//BMP//Capture2.bmp"; ///////// Juggernaut Roar.
	iShowBMP2(390, 300, c3, 0);

	char text3[] = "3.Juggernaut Roar";
	iText(390, 280, text3, GLUT_BITMAP_HELVETICA_18);

	char c4[] = "Images//charecter//BMP//hm1.bmp"; ///////////  Odin’s Arc.
	iShowBMP2(560, 300, c4, 0);

	char text4[] = "4.Odin’s Arc";
	iText(560, 280, text4, GLUT_BITMAP_HELVETICA_18);

	iSetColor(254, 250, 255);
	if (Player_select == 2) {
		char m[] = "Choose Player TWO";
		iText(100, 50, m, GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(Player_select == 1)
	{
		char m[] = "Choose Player ONE";
		iText(100, 50, m, GLUT_BITMAP_TIMES_ROMAN_24);
	}

}
void selectCharacter(int x, int y) {

	if (x > 50 && x < 200 && y>300 && y < 510) {
		if (Player_select == 1) {
			charecter1[0][0] = '\0';
			strcpy(charecter1[0], "Images//charecter//BMP//1.bmp");
			charecter1[1][0] = '\0';
			strcpy(charecter1[1], "Images//charecter//BMP//2.bmp");
			charecter1[2][0] = '\0';
			strcpy(charecter1[2], "Images//charecter//BMP//3.bmp");
			charecter1[3][0] = '\0';
			strcpy(charecter1[3], "Images//charecter//BMP//4.bmp");
			charecter1[4][0] = '\0';
			strcpy(charecter1[4], "Images//charecter//BMP//5.bmp");
			Player_select = 2;
		}
		else if (Player_select == 2) {
			charecter2[0][0] = '\0';
			strcpy(charecter2[0], "Images//charecter//BMP//1.bmp");
			charecter2[1][0] = '\0';
			strcpy(charecter2[1], "Images//charecter//BMP//2.bmp");
			charecter2[2][0] = '\0';
			strcpy(charecter2[2], "Images//charecter//BMP//3.bmp");
			charecter2[3][0] = '\0';
			strcpy(charecter2[3], "Images//charecter//BMP//4.bmp");
			charecter2[4][0] = '\0';
			strcpy(charecter2[4], "Images//charecter//BMP//5.bmp");
			Player_select = 0;
			gamestate = 0;
		}
		
	}
	else if (x > 220 && x < 370 && y> 300 && y < 510) {
		if (Player_select == 1) {
			charecter1[0][0] = '\0';
			strcpy(charecter1[0], "Images//charecter//BMP//p2_0.bmp");
			charecter1[1][0] = '\0';
			strcpy(charecter1[1], "Images//charecter//BMP//p2_1.bmp");
			charecter1[2][0] = '\0';
			strcpy(charecter1[2], "Images//charecter//BMP//p2_2.bmp");
			charecter1[3][0] = '\0';
			strcpy(charecter1[3], "Images//charecter//BMP//p2_3.bmp");
			charecter1[4][0] = '\0';
			strcpy(charecter1[4], "Images//charecter//BMP//p2_4.bmp");
			Player_select = 2;
		}
		else if (Player_select == 2) {
	
			charecter2[0][0] = '\0';
			strcpy(charecter2[0], "Images//charecter//BMP//p2_0.bmp");
			charecter2[1][0] = '\0';
			strcpy(charecter2[1], "Images//charecter//BMP//p2_1.bmp");
			charecter2[2][0] = '\0';
			strcpy(charecter2[2], "Images//charecter//BMP//p2_2.bmp");
			charecter2[3][0] = '\0';
			strcpy(charecter2[3], "Images//charecter//BMP//p2_3.bmp");
			charecter2[4][0] = '\0';
			strcpy(charecter2[4], "Images//charecter//BMP//p2_4.bmp");
			Player_select = 0;
			gamestate = 0;
		}

	}
	else if (x > 390 && x < 540 && y> 300 && y < 510) {
		if (Player_select == 1) {

			 charecter1[0][0] = '\0';
			 strcpy(charecter1[0], "Images//charecter//BMP//Capture2.bmp");
			 charecter1[1][0] = '\0';
			 strcpy(charecter1[1], "Images//charecter//BMP//Capture3.bmp");
			 charecter1[2][0] = '\0';
			 strcpy(charecter1[2], "Images//charecter//BMP//Capture4.bmp");
			 charecter1[3][0] = '\0';
			 strcpy(charecter1[3], "Images//charecter//BMP//Capture6.bmp");
			 charecter1[4][0] = '\0';
			 strcpy(charecter1[4], "Images//charecter//BMP//Capture7.bmp");
			 Player_select = 2;
		}
		else if (Player_select == 2) {

			charecter2[0][0] = '\0';
			strcpy(charecter2[0], "Images//charecter//BMP//Capture2.bmp");
			charecter2[1][0] = '\0';
			strcpy(charecter2[1], "Images//charecter//BMP//Capture3.bmp");
			charecter2[2][0] = '\0';
			strcpy(charecter2[2], "Images//charecter//BMP//Capture4.bmp");
			charecter2[3][0] = '\0';
			strcpy(charecter2[3], "Images//charecter//BMP//Capture6.bmp");
			charecter2[4][0] = '\0';
			strcpy(charecter2[4], "Images//charecter//BMP//Capture7.bmp");
			Player_select = 0;
			gamestate = 0;
		}
	}
	else if (x > 560 && x < 710 && y> 300 && y < 510) {
		if (Player_select == 1) {

			charecter1[0][0] = '\0';
			strcpy(charecter1[0], "Images//charecter//BMP//hm1.bmp");
			charecter1[1][0] = '\0';
			strcpy(charecter1[1], "Images//charecter//BMP//hm2.bmp");
			charecter1[2][0] = '\0';
			strcpy(charecter1[2], "Images//charecter//BMP//hm3.bmp");
			charecter1[3][0] = '\0';
			strcpy(charecter1[3], "Images//charecter//BMP//hm4.bmp");
			charecter1[4][0] = '\0';
			strcpy(charecter1[4], "Images//charecter//BMP//hm5.bmp");
			Player_select = 2;
		}
		else if (Player_select == 2) {
			
			charecter2[0][0] = '\0';
			strcpy(charecter2[0], "Images//charecter//BMP//hm1.bmp");
			charecter2[1][0] = '\0';
			strcpy(charecter2[1], "Images//charecter//BMP//hm2.bmp");
			charecter2[2][0] = '\0';
			strcpy(charecter2[2], "Images//charecter//BMP//hm3.bmp");
			charecter2[3][0] = '\0';
			strcpy(charecter2[3], "Images//charecter//BMP//hm4.bmp");
			charecter2[4][0] = '\0';
			strcpy(charecter2[4], "Images//charecter//BMP//hm5.bmp");
			Player_select = 0;
			gamestate = 0;
		}
	}






}