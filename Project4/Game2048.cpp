#include "Game2048.h"
#include <Windows.h>
#include <stdio.h>;
#using <system.drawing.dll>
#include <stdlib.h>;
#include <ctime>; 
#include <string>;
#include <time.h>;
using namespace Project4; // Название проекта
using namespace System;
using namespace System::Data::OleDb;

int game[4][4];
int playerScore;
bool isFinished;

Void Game2048::Game2048_Load(System::Object^ sender, System::EventArgs^ e) {
	Initialize();
}

void Game2048::Initialize() {
	clearField();
	generateCell();
	generateCell();
	Score->Text = "0";
	playerScore = 0;
	isFinished = false;
	Restart->Visible = false;
}

void Game2048::clearField() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			game[i][j] = 0;
			ChoosePictureBox(i, j, ChooseCol(0),"");
		}
	}
}

void Game2048::setScore(int value) {
	playerScore += value;
	Score->Text = Convert::ToString(playerScore);
}   

bool Game2048::gameFinish() {
	if (isFinished) return true;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (game[i][j] == 0) return false;
		}
    }
	isFinished = true;
	clearField();
	Restart->Visible = true;
	return true;
}

void Game2048::generateCell() {
	srand(time(NULL));
	int i, j;
	do {
		i = rand() % 4;
		j = rand() % 4;
	} while (game[i][j] != 0);

	int value = 1 + rand() % 10;
	if (value == 10) value = 4;
	else value = 2;

	game[i][j] = value;
	ChoosePictureBox(i, j, ChooseCol(value), Convert::ToString(value));
}

void Game2048::updateField() {
	String^ num;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (game[i][j] == 0) num = "";
			else num = Convert::ToString(game[i][j]);
			ChoosePictureBox(i, j, ChooseCol(game[i][j]), num);
		}
	}
}

void Game2048::increaseValue(int i, int j, int ii, int jj) {
	if (game[i][j] == game[ii][jj]) {
		game[i][j] *= 2;
		game[ii][jj] = 0;
		setScore(game[i][j]);
	}
}

Void Game2048::Game2048_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	bool isSmah = false;
	bool isSmah2 = false;
	if (!gameFinish()) {
		if (e->KeyCode == Keys::Left) {
			for (int i = 0; i < 4; i++) {
				for (int j = 1; j < 4; j++) {
					if (game[i][j] != 0) {
						bool moved = false;
						int shift = 0;
						for (int k = j - 1; k >= 0; k--) {
							if (game[i][k] == 0) shift++;
							else if (game[i][k] == game[i][j]) {
								game[i][k] *= 2;
								game[i][j] = 0;
								isSmah2 = true;
								setScore(game[i][k]);
								moved = true;
								break;
							}
							else {
								if (k != j - 1) {
									isSmah = true;
									game[i][k + 1] = game[i][j];
									game[i][j] = 0;
								}
								moved = true;
								break;
							}
						}
						if (!moved) {
							isSmah = true;
							game[i][j - shift] = game[i][j];
							game[i][j] = 0;
						}
					}
				}
			}
			if (isSmah2) smah2->Play();
			else if (isSmah) smah->Play();
			updateField();
			generateCell();
		}
		else if (e->KeyCode == Keys::Right) {
			for (int i = 0; i < 4; i++) {
				for (int j = 2; j >= 0; j--) {
					if (game[i][j] != 0) {
						bool moved = false;
						int shift = 0;
						for (int k = j + 1; k < 4; k++) {
							if (game[i][k] == 0) shift++;
							else if (game[i][k] == game[i][j]) {
								game[i][k] *= 2;
								game[i][j] = 0;
								isSmah2 = true;
								setScore(game[i][k]);
								moved = true;
								break;
							}
							else {
								if (k != j + 1) {
									isSmah = true;
									game[i][k - 1] = game[i][j];
									game[i][j] = 0;
								}
								moved = true;
								break;
							}
						}
						if (!moved) {
							isSmah = true;
							game[i][j + shift] = game[i][j];
							game[i][j] = 0;
						}
					}
				}
			}
			if (isSmah2) smah2->Play();
			else if (isSmah) smah->Play();
			updateField();
			generateCell();
		}
		else if (e->KeyCode == Keys::Up) {
			for (int i = 0; i < 4; i++) {
				for (int j = 1; j < 4; j++) {
					if (game[j][i] != 0) {
						bool moved = false;
						int shift = 0;
						for (int k = j - 1; k >= 0; k--) {
							if (game[k][i] == 0) shift++;
							else if (game[k][i] == game[j][i]) {
								game[k][i] *= 2;
								game[j][i] = 0;
								isSmah2 = true;
								setScore(game[k][i]);
								moved = true;
								break;
							}
							else {
								if (k != j - 1) {
									isSmah = true;
									game[k + 1][i] = game[j][i];
									game[j][i] = 0;
								}
								moved = true;
								break;
							}
						}
						if (!moved) {
							isSmah = true;
							game[j - shift][i] = game[j][i];
							game[j][i] = 0;
						}
					}
				}
			}
			if (isSmah2) smah2->Play();
			else if (isSmah) smah->Play();
			updateField();
			generateCell();
		}
		else if (e->KeyCode == Keys::Down) {
			for (int i = 0; i < 4; i++) {
				for (int j = 2; j >= 0; j--) {
					if (game[j][i] != 0) {
						bool moved = false;
						int shift = 0;
						for (int k = j + 1; k < 4; k++) {
							if (game[k][i] == 0) shift++;
							else if (game[k][i] == game[j][i]) {
								game[k][i] *= 2;
								game[j][i] = 0;
								isSmah2 = true;
								setScore(game[k][i]);
								moved = true;
								break;
							}
							else {
								if (k != j + 1) {
									isSmah = true;
									game[k - 1][i] = game[j][i];
									game[j][i] = 0;
								}
								moved = true;
								break;
							}
						}
						if (!moved) {
							isSmah = true;
							game[j + shift][i] = game[j][i];
							game[j][i] = 0;
						}
					}
				}
			}
			if (isSmah2) smah2->Play();
			else if (isSmah) smah->Play();
			updateField();
			generateCell();
		}
	}
	else {
		if (e->KeyCode == Keys::Space) {
			Initialize();
		}
    }
}

Color Game2048::ChooseCol(int KoefColor) {
	switch (KoefColor) {
	case 0: return Color::MistyRose;
	case 2: return Color::Silver;
	case 4: return Color::FromArgb(255, 224, 192);
	case 8: return Color::FromArgb(222, 159, 82);
	case 16: return Color::FromArgb(224, 82, 43);
	case 32: return Color::FromArgb(224, 67, 43);
	case 64: return Color::FromArgb(224, 43, 43);
	case 128: return Color::FromArgb(201, 24, 24);
	case 256: return Color::FromArgb(166, 18, 18);
	case 512: return Color::FromArgb(128, 17, 17);
	case 1024: return Color::FromArgb(189, 23, 84);
	case 2048: return Color::FromArgb(240, 81, 140);
	}
}


void Game2048::ChoosePictureBox(int i, int j, Color col, String ^num) {

	switch (i) {
	case 0: 
	{
		switch (j) {
		case 0:
		{
			pictureBox1->BackColor = col;
			label1->Text = num;
			break;
		}
		case 1:
		{
			pictureBox2->BackColor = col;
			label2->Text = num;
			break;
		}
		case 2:
		{
			pictureBox3->BackColor = col;
			label3->Text = num;
			break;
		}
		case 3:
		{
			pictureBox4->BackColor = col;
			label4->Text = num;
			break;
		}
		}
		break;
	}
	case 1:
	{
		switch (j) {
		case 0:
		{
			pictureBox5->BackColor = col;
			label5->Text = num;
			break;
		}
		case 1:
		{
			pictureBox6->BackColor = col;
			label6->Text = num;
			break;
		}  
		case 2:
		{
			pictureBox7->BackColor = col;
			label7->Text = num;
			break;
		}
		case 3:
		{
			pictureBox8->BackColor = col;
			label8->Text = num;
			break;
		}
		}
		break;
	}
	case 2:
	{
		switch (j) {
		case 0:
		{
			pictureBox9->BackColor = col;
			label9->Text = num;
			break;
		}
		case 1:
		{
			pictureBox10->BackColor = col;
			label10->Text = num;
			break;
		}
		case 2:
		{
			pictureBox11->BackColor = col;
			label11->Text = num;
			break;
		}
		case 3:
		{
			pictureBox12->BackColor = col;
			label12->Text = num;
			break;
		}
		}
		break;
	}
	case 3:
	{
		switch (j) {
		case 0:
		{
			pictureBox13->BackColor =  col;
			label13->Text = num;
			break;
		}
		case 1:
		{
			pictureBox14->BackColor = col;
			label14->Text = num;
			break;
		}
		case 2:
		{
			pictureBox15->BackColor = col;
			label15->Text = num;
			break;
		}
		case 3:
		{
			pictureBox16->BackColor = col;
			label16->Text = num;
			break;
		}
		}
		break;
	}
	}
}

void Game2048::UpdateGame2048Score(int Score, int Code) {
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=Database.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);
	dbConnection->Open();
	String^ query = "UPDATE table1 SET Count3 ='" + Score + "' WHERE [Code] = " + Code;
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);
	dbComand->ExecuteNonQuery();
	dbConnection->Close();
}

Void Game2048::Game2048_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
	if (isFinished && playerScore > StartScore) {
		UpdateGame2048Score(playerScore, PlayerCode);
	}
}


