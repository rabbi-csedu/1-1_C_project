#pragma once
#include "variable.h"
#include "control.h"

void inti() {
	//////// All value is initialized
	player[1].charecter_ready = false;
	player[2].charecter_ready = false;
	button_music = false;
	player_flag = 0;
	//int gamestate = 0;
	player[0].bow_x = 0;
	player[1].bow_x = 0;
 	player[1].bow_indx = 0;
	player[0].bow_indx = 0;
	player[1].bow_y = 200;
	player[0].bow_y = 200;
	player[0].arrow_x = 120;
	player[1].arrow_x = 120;
	player[0].arrow_y = 330;
	player[1].arrow_y = 330;
	arrow_dx = 50;
	player[0].arrow_come = false;
	player[1].arrow_come = false;
	player[1].dx_initialized = false;
	player[0].dx_initialized = false;
	bow_dy;
	
	arrow_dy;
	player[1].bullseye_y = 300;
	player[0].bullseye_y = 330;
	quit = 0;
	player[0].score = 0;
	player[1].score = 0;
	player[0].n = 10;
	player[1].n = 10;
	playerChangeDelay = false;
}
