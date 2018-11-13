#pragma once
#include "iGraphics.h"
#include "variable.h"
#include "control.h"
#include "Initiallize.h"

void level(int x, int y) {


	// ********************** Level Working *******************//

	if (x > 870 && x < 1032 && y > 240 && y < 288) {
		if( (!button_music))
			PlaySound("Music\\Button.wav", NULL, ASYNCH);
			Level = 1;
			bow_dy = 7, arrow_dy = 7, arrow_dx = 50;
			inti();
			nameStringI1 = strlen(nameString1) - 1;    //// Initializing all String containg player name
			nameStringI2 = strlen(nameString2) - 1;
			nameString1[0] = '_';
			nameString1[1] = '\0';
			nameString2[0] = ' ';
			nameString2[1] = '\0';
			/// Variable to alternate between player name
			but_ind[7].butt_indx = 0;              /// 
			nameInputFlag = 0;
			gamestate = -1;
		}
	
	else if (x > 870 && x < 1032 && y > 170 && y < 218) {
		if ((!button_music))
			PlaySound("Music\\Button.wav", NULL, ASYNCH);
		Level = 2;
		bow_dy = 5, arrow_dy = 5, arrow_dx = 50, bullseye_dy = 8;
		inti();
		nameStringI1 = strlen(nameString1) - 1;    //// Initializing all String containg player name
		nameStringI2 = strlen(nameString2) - 1;
		nameString1[0] = '_';
		nameString1[1] = '\0';
		nameString2[0] = ' ';
		nameString2[1] = '\0';
		/// Variable to alternate between player name
		but_ind[7].butt_indx = 0;              /// 
		nameInputFlag = 0;
		gamestate = -1;
	}
	else if (x > 870 && x < 1032 && y > 100 && y < 148) {
		if ((!button_music))
			PlaySound("Music\\Button.wav", NULL, ASYNCH);
		Level = 3;
		bow_dy = 5, arrow_dy = 5, arrow_dx = 50, bullseye_dy = 15;
		inti();
		nameStringI1 = strlen(nameString1) - 1;    //// Initializing all String containg player name
		nameStringI2 = strlen(nameString2) - 1;
		nameString1[0] = '_';
		nameString1[1] = '\0';
		nameString2[0] = ' ';
		nameString2[1] = '\0';
		/// Variable to alternate between player name
		but_ind[7].butt_indx = 0;              /// 
		nameInputFlag = 0;
		gamestate = -1;
	}
	


}

void levelShow() {

	char back[] = "Images//game_level.bmp";
	iShowBMP(0, 0, back);
	char lev[6][1000] = { "Button_images\\easy_1.bmp", "Button_images\\easy_2.bmp", "Button_images\\medium_1.bmp", "Button_images\\medium_2.bmp", "Button_images\\hard_1.bmp", "Button_images\\hard_2.bmp" };

	if(level_flag[0].butt_indx)
		iShowBMP2(870, 240, lev[1], 0);
	else 
	iShowBMP2(870, 240, lev[0], 0);   /// Easy level

	if(level_flag[1].butt_indx)
		iShowBMP2(870, 170, lev[3], 0);
	else 
		iShowBMP2(870, 170, lev[2], 0);			///medium level
	if(level_flag[2].butt_indx)
		iShowBMP2(870, 100, lev[5], 0);
	else
	iShowBMP2(870, 100, lev[4], 0);			/// hard level


}
void level_button_increase(int mx, int my)
{
	char lev[6][1000] = { "Button_images\\easy_1.bmp", "Button_images\\easy_2.bmp", "Button_images\\medium_1.bmp", "Button_images\\medium_2.bmp", "Button_images\\hard_1.bmp", "Button_images\\hard_2.bmp" };
	
	if (gamestate == 5)
	{
		if (mx > 870 && mx < 1032 && my > 240 && my < 288)
			level_flag[0].butt_indx  = 1;   /// Easy level
		else 
			level_flag[0].butt_indx = 0;
		 if (mx > 870 && mx < 1032 && my > 170 && my < 218)
			level_flag[1].butt_indx = 1;	///medium level
		 else
			 level_flag[1].butt_indx = 0;
		if (mx > 870 && mx < 1032 && my > 100 && my < 148)
			level_flag[2].butt_indx = 1;	/// hard level
		else 
			level_flag[2].butt_indx = 0;
	}
}

