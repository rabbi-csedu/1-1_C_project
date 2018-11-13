#pragma once
#include <iostream>
#include <stdio.h>
#include <string.h>


struct Button
{
	int x;
	int y;
};
int i;
bool confirm = false;
bool lev3 = true;
bool bingo = false;
char lol[100] = "Images//charecter//BMP//Arrow_Copy.bmp";
int arrow_dx = 50;
int bow_dy =7;														
int arrow_dy = 7;
int bullseye_dy; 
bool button_music = false;
int gamestate = 0;
int quit = 0;
bool playerChangeDelay = false;
int player_flag = 0;
struct Player {
	bool charecter_ready = false;
	int bow_x = 0;
	int bow_indx = 0;
	int bow_y = 200;
	int arrow_x = 20, arrow_y = 330;

	bool dx_initialized = false;

	int bullseye_y = 300;
	int score = 0;

	int n = 10;
	bool arrow_come = false;
};
Player player[2];

struct button_index {
	int butt_indx = 0;

};
button_index level_flag[3]; /// Variable Detemine The up down position
int Level = 1;
int Player_select = 0;
button_index but_ind[8];
char menu_button[][100] = { "Button_images\\1.bmp", "Button_images\\2.bmp", "Button_images\\3.bmp", "Button_images\\4.bmp", "Button_images\\5.bmp", "Button_images\\6.bmp", "Button_images\\7.bmp", "Button_images\\8.bmp", "Button_images\\9.bmp", "Button_images//10.bmp","Button_images\\11.bmp" ,"Button_images\\12.bmp" ,"Button_images\\13.bmp" ,"Button_images\\14.bmp" };


char charecter1[5][100] = { "Images//charecter//BMP//1.bmp","Images//charecter//BMP//2.bmp","Images//charecter//BMP//3.bmp","Images//charecter//BMP//4.bmp","Images//charecter//BMP//5.bmp" };
char charecter2[][100] = { "Images//charecter//BMP//p2_0.bmp", "Images//charecter//BMP//p2_1.bmp", "Images//charecter//BMP//p2_2.bmp", "Images//charecter//BMP//p2_3.bmp",  "Images//charecter//BMP//p2_4.bmp", };

int nameInputFlag = 0;
char nameString1[100000] = "_";
char nameString2[100000] = " ";
int nameStringI1 = strlen(nameString1) - 1;
int  nameStringI2 = strlen(nameString2) - 1;
char Esc[] = { "Press Esc To Back" };
char ind[3];
char high[1000] = " ";

struct HighScore {			// Store inputs from file
	char name[50] = "Empty";
	int score = 0;

};
