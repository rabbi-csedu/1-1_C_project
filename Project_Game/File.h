#pragma once
#include <iostream>
#include <algorithm>
#include"variable.h"
#include <cstdio>

HighScore *p , highscoreContent[4];


FILE *fp=NULL;
void fileRead() {
	fp = fopen("HighScore.txt", "r");
	fseek(fp, 0, SEEK_END);                          ///////////Opening the high score file 
	if (ftell(fp) != 0) {                       ////////Keeping it in a sturcture
		fseek(fp, 0, SEEK_SET);
		for (int i = 0; i < 4; i++) {
			p = (HighScore *)calloc(sizeof(HighScore), 1);
			fread(p, sizeof(HighScore), 1, fp);
			highscoreContent[i] = *p;
		}
	}
	else
		std::cout << "emptyfile\n";
	fclose(fp);
}

bool compare(HighScore a, HighScore b)
{
	return a.score > b.score;               ////////Comparing the score with the file value
}

void fileStore()
{
	if(fp = fopen("HighScore.txt", "w"));
	

	for (int i = 0; i < 4; i++)
	{
		p = (HighScore *)calloc(sizeof(HighScore), 1);
		p = &highscoreContent[i];                  
		fwrite(p, sizeof(HighScore), 1, fp);
	}

	fclose(fp);
}

void fileOpen() {

	FILE *f;
	f = freopen("instructions.txt", "r",stdout);
	if (f == NULL) {
		std::cout << "Error Opening file\n";
		exit(0);
	}
	char string[300];
	int j = 550;
	iSetColor(255, 255, 0);
	while (fgets(string, 300, f)) {
		iText(20, j, string, GLUT_BITMAP_HELVETICA_18);
		j -= 20;
	}
	fclose(f);

}