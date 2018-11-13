#pragma once
#include "iGraphics.h"
#include "variable.h"
void l3();
void bullseye() {
	if (Level == 1) {
		char target[] = "Images\\bulls_eye.bmp";
		iShowBMP2(1125, player[player_flag].bullseye_y, target, 0);
	}
	else if (Level == 2||Level ==3) {
		if (player[player_flag].bullseye_y < 100 || player[player_flag].bullseye_y > 400)                  /// In the level 1 the player is moving but
			bullseye_dy *= -1;
		player[player_flag].bullseye_y += bullseye_dy;
		char target[] = "Images\\bulls_eye.bmp";
		iShowBMP2(1125, player[player_flag].bullseye_y, target, 0);
	}

}
void game(void) {
	
		char game_background[] = "images\\Game_Background.bmp";
		iShowBMP(0, 0, game_background);
		if(player_flag==0)
		iShowBMP2(player[player_flag].bow_x, player[player_flag].bow_y, charecter1[player[player_flag].bow_indx], 0);
		else
			iShowBMP2(player[player_flag].bow_x, player[player_flag].bow_y, charecter2[player[player_flag].bow_indx], 0);            // The all photo in the main game
		char Back[] = "Button_images\\back.bmp";
		char Back1[] = "Button_images\\button_back (1).bmp";
		if (but_ind[7].butt_indx == 0) {
			iShowBMP2(530, 20, Back, 0);

		}
		else if (but_ind[7].butt_indx == 1)
		{
			iShowBMP2(530, 20, Back1, 0);


		}
		if (Level == 3) {
			char box[] = "images\\Box.bmp";
			iShowBMP(150, 100, box);
			iSetColor(250, 13, 100);
			char Power[] = { "Arrow Velocity" };
			iText(160, 70, Power, GLUT_BITMAP_HELVETICA_18);
			if (i == 1) {
				iSetColor(255, 255, 0);
				iFilledRectangle(150, 100, 50, 20);
				arrow_dx = 20;
				
			}
			else if (i == 2) {
				iSetColor(255, 140, 0);
				iFilledRectangle(150, 100, 50, 20);
				iFilledRectangle(200, 100, 50, 20);                                    //// The blocks showing the velocity of the arrow!
				arrow_dx = 30;
				

			}
			else if (i == 3) {
				iSetColor(255, 69, 0);
				iFilledRectangle(150, 100, 50, 20);
				iFilledRectangle(200, 100, 50, 20);
				iFilledRectangle(250, 100, 50, 20);
				arrow_dx = 40;
				
			}
			else if (i == 4) {
				iSetColor(255, 0, 0);
				iFilledRectangle(150, 100, 50, 20);
				iFilledRectangle(200, 100, 50, 20);
				iFilledRectangle(250, 100, 50, 20);
				iFilledRectangle(300, 100, 50, 20);
				arrow_dx = 50;
				
			}
			
		}


		char score[] = "images\\score.bmp";
		iShowBMP2(1000, 540, score, 0);
		char player[100];
		strcpy(player, "Player ");
		char t[3];
		itoa(player_flag + 1, t, 10);
		strcat(player, t);                               ///////////Score showing photo
		iSetColor(23, 234, 34);
		iText(550, 540, player, GLUT_BITMAP_TIMES_ROMAN_24);
		
}

void l3() {
	if (lev3) {
		i++;
		if (i > 4) {
			i = 1;
		}
	}
	
}
