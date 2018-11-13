#pragma once
#ifndef _menu_
#define _menu_


#include "iGraphics.h"
#include "menu.h"
#include "variable.h"
#include<iostream>

void Main_Menu(void) {

	char new_button[2][100] = { "newgame_button.bmp","newgame_button_inc.bmp" };
	char Back_Graound_Image[] = "Main_menu.bmp";
	iShowBMP(0, 0, Back_Graound_Image);
	//iShowBMP2(900, 500, new_button[button_indx], 0);
	if (but_ind[0].butt_indx == 0)
		iShowBMP2(900, 500, menu_button[0], 0); //NewGame
	else
		iShowBMP2(900, 500, menu_button[1], 0);
	if (but_ind[1].butt_indx == 0)
		iShowBMP2(900, 430, menu_button[2], 0); //Level
	else
		iShowBMP2(900, 430, menu_button[3], 0);
	if (but_ind[2].butt_indx == 0)
		iShowBMP2(900, 360, menu_button[4], 0); //Highscore
	else
		iShowBMP2(900, 360, menu_button[5], 0);  // Highscore
	if (but_ind[3].butt_indx == 0)
		iShowBMP2(900, 290, menu_button[6], 0);  //Shop
	else
		iShowBMP2(900, 290, menu_button[7], 0); // Shop
	if (but_ind[4].butt_indx == 0)
		iShowBMP2(900, 220, menu_button[8], 0);  //Instranction
	else
		iShowBMP2(900, 220, menu_button[9], 0);
	
	if (but_ind[6].butt_indx == 0)
		iShowBMP2(900, 150, menu_button[12], 0);  //Quit
	else
		iShowBMP2(900, 150, menu_button[13], 0);
}



void Increase_button(int mx, int my) {
	if (mx > 900 && mx < 1129 && my>500 && my < 500 + 56) {  //NewGame

		but_ind[0].butt_indx = 1;
	}
	else
		but_ind[0].butt_indx = 0;

	if (mx > 900 && mx < 1129 && my > 430 && my < 430 + 56) {  //Level

		but_ind[1].butt_indx = 1;

	}
	else
		but_ind[1].butt_indx = 0;

	if (mx > 900 && mx < 1129 && my > 360 && my < 360 + 56) { // Highscore

		but_ind[2].butt_indx = 1;

	}
	else
		but_ind[2].butt_indx = 0;
	if (mx > 900 && mx < 1129 && my> 290 && my < 290 + 56) { //Shop

		but_ind[3].butt_indx = 1;

	}
	else
		but_ind[3].butt_indx = 0;

	if (mx > 900 && mx < 1129 && my> 220 && my < 220 + 56) {    // Instruction

		but_ind[4].butt_indx = 1;

	}
	else
		but_ind[4].butt_indx = 0;

	

	if (mx > 900 && mx < 1129 && my> 150 && my < 150 + 56) {     //Quit

		but_ind[6].butt_indx = 1;

	}
	else
		but_ind[6].butt_indx = 0;
}

#endif
















