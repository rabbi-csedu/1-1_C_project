#pragma once
#include "variable.h"
#include "iGraphics.h"
#include "menu.h"
#include "game.h"
#include <iostream>
#include "Initiallize.h"
#include "ControlArrow.h"
#include "level.h"
#include "character.h"
#include "File.h"
#define MAINGAME 1
#define HOMESCREEN 0
#define NAMEWINDOW -1
#define WINNERSCREEN 3
#define HIGHSCORE 4
#define LEVELSCREEN 5
#define CREDIT 5
#define SHOP 6
#define INSTRUCTION 7
void MoveCharecter();
void scoreShow();


void iDraw()
{
	iClear();

	if (quit)
		exit(0);    // Quit Option
	
	if (gamestate == HOMESCREEN) {
		/* ******************** Main menu *************************************/
		Main_Menu();
	}
	else if (gamestate == NAMEWINDOW) {

		//******************************** GameState Name Input ************************//
		char nameBackground[] = "Images//NameUI.bmp";
		iShowBMP(0, 0, nameBackground);
		iSetColor(255, 255, 0);
		char instruction[] = "Use UP ARROW and DOWN ARROW to shift between Player's Name";
		iText(320, 80, instruction, GLUT_BITMAP_HELVETICA_18);
		iSetColor(255, 0, 0);
		iText(300, 400, nameString1, GLUT_BITMAP_TIMES_ROMAN_24); //FIrst Name Co ordinate
		iText(300, 300, nameString2, GLUT_BITMAP_TIMES_ROMAN_24); // Second  Name co ordinate
	}

	else if (gamestate == MAINGAME) {

		//****************************** Main Game ********************************//

			if (playerChangeDelay)
			{
				iDelayMS(1000);												/// Daleying Palyer 
				if (player_flag && player[0].n > 0)
					player_flag = 0;
				else if (player[1].n <= 0)
					player_flag = 0;
				else if (player_flag == 0 && player[1].n > 0)				///Changing Player
					player_flag = 1;
				else if (player[0].n <= 0)
					player_flag = 1;
				playerChangeDelay = false;		
				bingo = false;
			}
			game();															///Calling game function for making Gaming Interface
			bullseye();														/// Bullseye Randering 
			arrow_change_player1();											// Changing Player
			MoveCharecter();
			scoreShow();
			
			if (player[player_flag].arrow_come)
				iShowBMP2(player[player_flag].arrow_x, player[player_flag].arrow_y, lol, 0);    /// lol contains the arrow and it is About the appiring Arrow
			
	}
	else if (gamestate == WINNERSCREEN) {

		//******************** Winner ************** //
		//char back[] = { "Images//Win.bmp" };
		// iShowBMP(0, 0, back);
		 char trophy[] = { "Images//TR.bmp" };
		 iShowBMPAlternativeSkipWhite(300, 150, trophy);

		 if (player[1].score > player[0].score) {

			 char player_State[1000] = "Player 2   Score: ";
			 char player_State2[1000] = "Palyer 1 Score: ";
			 char score2[5];
			 char score[5];
			 char player2Wins[] = { "Images//images2 - Copy.bmp" };      ///   Player 2 wins
			 iShowBMP2(360, 100, player2Wins, 0);
			 											
			 
			 itoa(player[1].score, score, 10);
			 strcat(player_State, score);
			 iText(720, 250, player_State, GLUT_BITMAP_HELVETICA_18);

			 itoa(player[0].score, score2, 10);
			 strcat(player_State2, score2);
			 iText(720, 225, player_State2, GLUT_BITMAP_HELVETICA_18);

		 }

		 else if (player[1].score < player[0].score) {

			 char player_State[1000] = "Player 1   Score: ";
			 char score[5];
			 char player_State2[1000] = "Palyer 2 Score: ";
			 char score2[5];
			 char player1Wins[] = { "Images//images - Copy.bmp" };    /// Player 1 wins
			 iShowBMP2(360, 100, player1Wins, 0);
			 
			 
			 itoa(player[0].score, score, 10);
			 strcat(player_State, score);
			 iText(720, 250, player_State, GLUT_BITMAP_HELVETICA_18);

			 itoa(player[1].score, score2, 10);
			 strcat(player_State2, score2);
			 iText(720, 220, player_State2, GLUT_BITMAP_HELVETICA_18);
		 }
		 else
		 {
			 char text[100] = "ITS A DRAW!!!!!";
			 iText(500, 250 , text, GLUT_BITMAP_HELVETICA_18);
		 }
		 iSetColor(255, 255, 255);
		 char command[] = { "Esc for back" };
		 iText(70, 20, command, GLUT_BITMAP_TIMES_ROMAN_24);  //Back command to main menu;
	}
	else if (gamestate == HIGHSCORE) {

		/****************************** High Score ********** 4 persons *******************************/

		int i, j;   //////////////// i is the number of high scores and j is the y co ordinate
		char back[] = "Images//level_background.bmp";
		iShowBMP(0, 0, back);
		for (i = 0, j = 350; i < 4; i++, j -= 60) {
			char high[1000] = " ";
			itoa(highscoreContent[i].score, high, 10);		     // Highs scores	
			char ind[3];
			ind[0] = (i + 1) + '0';
			ind[1] = '.';
			ind[2] = '\0';
			iSetColor(1, 0, 0);
			iText(900, j, ind, GLUT_BITMAP_TIMES_ROMAN_24);
			iText(930, j, highscoreContent[i].name, GLUT_BITMAP_TIMES_ROMAN_24);   /// Name of high scorers
			iText(1130, j, high, GLUT_BITMAP_TIMES_ROMAN_24);
			char Esc[] = { "Press Esc To Back" };             //// Back command to main menu
			iSetColor(200, 12, 12);

			iText(500, 60, Esc, GLUT_BITMAP_TIMES_ROMAN_24);

		}
	
	}
	else if (gamestate == LEVELSCREEN) {

		/************ Three Levels ***********/
		/*************** Choose Level***************/
		/*   Level header  */
		
		levelShow();
		iSetColor(250, 230, 51);
		char text[] = "Press Esc to Back";
		iText(550, 80, text, GLUT_BITMAP_TIMES_ROMAN_24);

	}
	else if (gamestate == SHOP) {        ///SHOP
		/********** SHow characters *************/
		/*     Character Header         */
		character();
		iSetColor(254, 250, 255);
		char text[] = "Press Esc to Back";
		iText(550, 50, text, GLUT_BITMAP_TIMES_ROMAN_24);
	
	}
	else if (gamestate == INSTRUCTION) {
	/************Showing   Instruction *********/
	//char ins[] = "Images//Instruction.bmp";
	//iShowBMP(0, 0, ins);
	//printf("YES");
	fileOpen();
	char back[] = "Press Esc to Back";
	iSetColor(255, 255, 255);
	iText(400, 80, back, GLUT_BITMAP_TIMES_ROMAN_24);
	}

	if (gamestate == 10) {

		char exit[] = "Button_images//exit.bmp";
		iShowBMP2(420, 220, exit, 0);
		char continu[] = "Button_images//continue.bmp";
		iShowBMP2(680, 220, continu, 0);
		//iPauseTimer(0);
	}


}
void iMouseMove(int mx, int my)
{
	//Ki problem?
}
//*******************************************************************ipassiveMouse***********************************************************************//
void iPassiveMouseMove(int mx, int my)
{
	 /************************ To make the button more realistic **************************/
		
	if (gamestate == HOMESCREEN) {    ////////in the main menu
		Increase_button(mx, my);
		}
	
	if (gamestate == MAINGAME && (mx > 530 && mx < 530 + 118 && my>20 && my < 20 + 48)) {      //// MAin Game Back
		but_ind[7].butt_indx = 1;

	}
	else
		but_ind[7].butt_indx = 0;
	if (gamestate == LEVELSCREEN)
	{
		level_button_increase( mx,  my);
	}
	

}

void iMouse(int button, int state, int mx, int my)
{

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		/************* Most used **** Mouse left click *******/
		if (gamestate == MAINGAME && (mx > 530 && mx < 530 + 118 && my>20 && my < 20 + 48))
		{
			/******* In Main Game *******/
			if (!button_music)
				PlaySound("Music\\Button.wav", NULL, ASYNCH);    ///// Main Game Back button press Initilize all value and takes Main menu
			gamestate = 10;
			confirm = true;
		
		}
		if (gamestate == HOMESCREEN) {
			/************ Main menu command **************/
			if (mx > 900 && mx < 1129 && my>500 && my < 500 + 56) {   /// New Game button
				if (!button_music)
					PlaySound("Music\\Button.wav", NULL, ASYNCH);

				nameStringI1 = strlen(nameString1) - 1;    //// Initializing all String containg player name
				nameStringI2 = strlen(nameString2) - 1;
													/// Variable to alternate between player name
				but_ind[7].butt_indx = 0;              /// 
				nameInputFlag = 0;
				inti();
				nameString1[0] = '_';
				nameString1[1] = '\0';
				nameString2[0] = ' ';
				nameString2[1] = '\0';
				
					
				gamestate = NAMEWINDOW; // -1 indicates the player name input's window 
				

			}

			else if (mx > 900 && mx < 1129 && my > 360 && my < 360 + 56) { //HighScore
				if (!button_music)
					PlaySound("Music\\Button.wav", NULL, ASYNCH);
					gamestate = HIGHSCORE;   ///Highscore Gamestate
			}

			else if (mx > 900 && mx < 1129 && my > 430 && my < 430 + 56) {   //Level
				if (!button_music)
					PlaySound("Music\\Button.wav", NULL, ASYNCH);
					gamestate = LEVELSCREEN; ///Level
			}

			else if (mx > 900 && mx < 1129 && my> 290 && my < 290 + 56) { //Shop
				if (!button_music)
					PlaySound("Music\\Button.wav", NULL, ASYNCH);
				Player_select = 1;
				gamestate = SHOP; /////Shop 6
			}

			else if (mx > 900 && mx < 1129 && my> 220 && my < 220 + 56) { //Instruction
				if (!button_music)
					PlaySound("Music\\Button.wav", NULL, ASYNCH);
				gamestate = INSTRUCTION;////Instruction gamestate
			}

			else if (mx > 900 && mx < 1129 && my> 150 && my < 150 + 56) {  //Quit
				if (!button_music)
					PlaySound("Music\\Button.wav", NULL, ASYNCH);
				quit = 1;
			}
		}
		if (gamestate == NAMEWINDOW) {										/// Player Name Windows Command takes to Main game
			/************ Player name input *****************/
			if (mx > 910 && mx < 1110 && my > 40 && my < 100) {
				if (!button_music)
					PlaySound("Music\\Button.wav", NULL, ASYNCH);     // OK
				gamestate = MAINGAME;    
			}
			else if (mx > 90 && mx < 300 && my >40 && my < 100) {		//// Player Name Windnows Command  Takes to Main Menu
				if (!button_music)
					PlaySound("Music\\Button.wav", NULL, ASYNCH);
				gamestate = HOMESCREEN;
				nameInputFlag = 0;
				nameString1[0] ='_';
				nameString1[1] = '\0';
				nameString2[0] = ' ';
				nameString2[1] = '\0';
								                 // BACK
			}
		}
		if (gamestate == LEVELSCREEN) {
			level(mx, my);  //////// level selection  // Level.h
		}
		if (gamestate == SHOP) {
			selectCharacter(mx, my);
		}
		if (gamestate ==10) {
			
			if (mx > 420 && mx < 570 && my > 220 && my < 276) {
				if (!button_music)
					PlaySound("Music\\Button.wav", NULL, ASYNCH);
				/*Exit*/
				printf("I");
				inti();
				nameStringI1 = strlen(nameString1) - 1;    //// Initializing all String containg player name
				nameStringI2 = strlen(nameString2) - 1;
				nameInputFlag = 0;						/// Variable to alternate between player name
				but_ind[7].butt_indx = 0;
				gamestate = HOMESCREEN;
				nameString1[0] = '_';
				nameString1[1] = '\0';
				nameString2[0] = ' ';
				nameString2[1] = '\0';
			}
			else if (mx > 680 && mx < 830 && my > 220 && my < 276) {
				if (!button_music)
					PlaySound("Music\\Button.wav", NULL, ASYNCH);
				gamestate = MAINGAME;
				confirm = false;
			}
		}


	}


	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		

	}
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/


void iKeyboard(unsigned char key)
{
	if (gamestate == MAINGAME) {     //Main Game 
		if (key == ' ')
		{
			if (!player[player_flag].charecter_ready) {    ////////////////////// SHOOTING COMMAND
				player[player_flag].charecter_ready = true;
			}
			lev3 = false;

		}
	}
	else if (gamestate == NAMEWINDOW) {   /// Name Input section
					/// SHIFTING TO 2nd STRING
		/****************** Input players name **********************/
		if (key != '\b' && nameInputFlag == 0 && key != 13) {  
		/// INPUT FIRST STRING
			
			nameString1[nameStringI1] = key;
			nameStringI1++;
			nameString1[nameStringI1] = '_';
			nameString1[nameStringI1+1] = '\0';  /// INPUT FIRST STRING
			

		}
		else if(key =='\b' && nameInputFlag == 0 && key != 13){
			////nameStringI = strlen(nameString);
			if (nameStringI1 < 1)						/// INPUT FIRST STRING
				nameStringI1 = 0;
			else {
				nameStringI1--;							/// INPUT FIRST STRING
				nameString1[nameStringI1] = '_';
				nameString1[nameStringI1+1] = '\0';
			}
		}
		 
		else if (key != '\b' && nameInputFlag == 1) {
			
			nameString2[nameStringI2] = key;
			nameStringI2++;
			nameString2[nameStringI2] = '_';
			nameString2[nameStringI2+1] = '\0';
		}
		else if (key == '\b' && nameInputFlag == 1) {
			////nameStringI = strlen(nameString);				/// INPUT SECOND STRING
			if (nameStringI2 < 1)
				nameStringI2 = 0;
			else {
				nameStringI2--;
				nameString2[nameStringI2] = '_';
				nameString2[nameStringI2+1] = '\0';
			}
		}
	}
	else if (gamestate == WINNERSCREEN) {       ////// Winning Result window esc;
		if (key == 27) {
			gamestate = HOMESCREEN;
		}
	}
	if (gamestate == 4) {         //// High score window esc
		if (key == 27) 
			gamestate = 0;
		
	}
	if (gamestate == LEVELSCREEN||gamestate == INSTRUCTION ||gamestate == SHOP|| gamestate == LEVELSCREEN) {
		if (key == 27)
			gamestate = HOMESCREEN;
	}
	if (gamestate == 6) {
		if (key == 13) {
			gamestate = HOMESCREEN;
		}
	}
	


}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{


	if (key == GLUT_KEY_RIGHT)
	{


	}
	if (key == GLUT_KEY_LEFT)
	{

	}

	if (key == GLUT_KEY_HOME)
	{

	}
	if (key == GLUT_KEY_DOWN) {

		nameInputFlag = 1;
		nameString1[nameStringI1] = '\0';
		nameString2[nameStringI2] = '_';
		nameString2[nameStringI2 + 1] = '\0';
	}
	if (key == GLUT_KEY_UP)
	{
		nameInputFlag = 0;
		nameString2[nameStringI2] = '\0';
		nameString1[nameStringI1] = '_';
		nameString1[nameStringI1 + 1] = '\0'; 
	}

}


void MoveCharecter() {

	if (player[player_flag].charecter_ready) {
		player[player_flag].bow_indx++;
		if (player[player_flag].bow_indx >= 5) {
			player[player_flag].bow_indx = 4;
			player[player_flag].arrow_come = true;
			player[player_flag].dx_initialized = true;
			//printf("Why?\n");
		}

	}


}

void scoreShow() {
	char m[] = "Images//happy_emoji.bmp";
	char text[] = " HURRAY !!!!!!";
	if (bingo) {
		iShowBMP2(500,300,m,0);
		iSetColor(255, 0, 0);
		iText(550, 250, text, GLUT_BITMAP_TIMES_ROMAN_24);
	}
	iSetColor(0, 255, 255);
	char t[4];
	_itoa_s(player[player_flag].score, t, 10);
	char l[100] = " ";
	strcat(l, t);
	iText(1110, 555, l, GLUT_BITMAP_TIMES_ROMAN_24);
	char arrows[100] = { "images\\Arrow1.bmp" };         ///////Lives Show
	int j = 0;
	for (int i = 0; i < player[player_flag].n; i++, j += 20) {
		iShowBMP2(700 + j, 60, arrows, 0);
	}

}