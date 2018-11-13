#pragma once
#include "iGraphics.h"
#include "variable.h"
#include "File.h"
#include "control.h"


void PinitialialState(int SC, int Life) {

																					/*Player Changing Conditions*/
	player[player_flag].dx_initialized = false;
	player[player_flag].bow_x = 0;
	player[player_flag].bow_y = 200;
	player[player_flag].arrow_x = 120;
	player[player_flag].arrow_y = 330;
	player[player_flag].n-=Life;
	player[player_flag].score += SC;
	player[player_flag].arrow_come = false;
	player[player_flag].charecter_ready = false;
	player[player_flag].bow_indx = 0;
	player[player_flag].bullseye_y = rand() % 300 + 100;
	if (!button_music && SC!=0)
		PlaySound("Music\\Hit.wav", NULL, ASYNCH);
	if (SC == 10)
		bingo = true;
	else
		bingo = false;
	playerChangeDelay = true;
	player[player_flag].charecter_ready = false;
	lev3 = true;
	
}
void arrow_change_player1() {


	if (player[player_flag].dx_initialized && player[player_flag].arrow_come) {
		
		player[player_flag].arrow_x += arrow_dx;

	}


	if (!player[player_flag].dx_initialized)
	{
		player[player_flag].arrow_y += arrow_dy;
		player[player_flag].bow_y += bow_dy;
		if ((player[player_flag].bow_y >= 600 - 210) || (player[player_flag].bow_y <= 0)) {
			bow_dy *= (-1);
			arrow_dy *= (-1);
		}

	}

	/*************** In the condition the scoring collision is detected ***********/
	if (((player[player_flag].arrow_y >= player[player_flag].bullseye_y && player[player_flag].arrow_y <= (player[player_flag].bullseye_y + 23)) && (player[player_flag].arrow_x > 1089)) || ((player[player_flag].arrow_y >= player[player_flag].bullseye_y + 111 && player[player_flag].arrow_y <= (player[player_flag].bullseye_y + 134)) && (player[player_flag].arrow_x > 1089)))
	{

		
		PinitialialState(2, 1);
		
	}
	if (((player[player_flag].arrow_y >= player[player_flag].bullseye_y + 23 && player[player_flag].arrow_y <= (player[player_flag].bullseye_y + 35)) && (player[player_flag].arrow_x > 1089)) || ((player[player_flag].arrow_y >= player[player_flag].bullseye_y + 109 && player[player_flag].arrow_y <= (player[player_flag].bullseye_y + 121)) && (player[player_flag].arrow_x > 1089)))
	{
		
		PinitialialState(4, 1);
	}
	if (((player[player_flag].arrow_y >= player[player_flag].bullseye_y + 35 && player[player_flag].arrow_y <= (player[player_flag].bullseye_y + 46)) && (player[player_flag].arrow_x > 1089)) || ((player[player_flag].arrow_y >= player[player_flag].bullseye_y + 98 && player[player_flag].arrow_y <= (player[player_flag].bullseye_y + 109)) && (player[player_flag].arrow_x > 1089)))
	{
		PinitialialState(6, 1);

	}
	if (((player[player_flag].arrow_y >= player[player_flag].bullseye_y + 46 && player[player_flag].arrow_y <= (player[player_flag].bullseye_y + 56)) && (player[player_flag].arrow_x > 1089)) || ((player[player_flag].arrow_y >= player[player_flag].bullseye_y + 88 && player[player_flag].arrow_y <= (player[player_flag].bullseye_y + 98)) && (player[player_flag].arrow_x > 1089)))
	{
		PinitialialState(8, 1);

	}
	if (((player[player_flag].arrow_y >= player[player_flag].bullseye_y + 56) && player[player_flag].arrow_y <= (player[player_flag].bullseye_y + 88)) && (player[player_flag].arrow_x > 1089))
	{
		if (player[player_flag].n < 14)
			PinitialialState(10, -1);
		else
			PinitialialState(10, 0);

	}
	if (player[player_flag].arrow_x > 1150) {
		PinitialialState(0, 2);
	}
	if (player[0].n <= 0 && (gamestate == 1) && player[1].n <= 0) {
		if (highscoreContent[3].score < player[0].score) {
			highscoreContent[3].score = player[0].score;
			strcpy(highscoreContent[3].name, nameString1);
			std::sort(highscoreContent, highscoreContent + 4, compare);                       //////////////// High score is compared
			
		}
		 if (highscoreContent[3].score < player[1].score) {
			highscoreContent[3].score = player[1].score;
			strcpy(highscoreContent[3].name, nameString2);
			std::sort(highscoreContent, highscoreContent + 4, compare);
			
		}
		 fileStore();
		gamestate = 3;
		
	}

}
