#include "MyForm2.h";
#include <Windows.h>
#include <stdio.h>;
#using <system.drawing.dll>
#include <stdlib.h>;
#include <ctime>; 
#include <string>;
#include <time.h>;
#include <malloc.h>;
using namespace Project4; // Название проекта
using namespace System;
using namespace System::Drawing;
using namespace System::Drawing::Drawing2D;
using namespace System::Drawing::Imaging;
using namespace System::Data::OleDb;

const int m = 15;
const int n = 15;
int fild[m][n];
int Snakem, Snaken;
int* space;
int* temp;
int cube = 36;
int sped;
int kspeed;
bool kEnd;
int headpolozh;
int api;
int apj;
bool Proc;
int Apples;
int isApple;
int mouthi,mouthj;
System::Drawing::Rectangle rect;
System::Drawing::Point p;

void MyForm2::Initialize()
{
	Proc = true;
	sped = 40;
	kspeed = 0;
	Snakem = 3;
	Snaken = 2;
	space = (int*)malloc(Snakem * Snaken * sizeof(int));

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			fild[i][j] = 0;
		}
	}
	
	for (int i = 0; i < Snakem; i++) {
		*(space + i * Snaken) = 7;
		*(space + i * Snaken + 1) = Snakem - i;
		fild[7][i+1] = 1;
	}

	headpolozh = 1;
	api = 7;
	apj = 10;
	Apples = 0;
	label1->Text = "0";
	isApple = 0;
	pictureBox1->BackColor = Color::Red;
	label3->Text = "";
	label4->Text = "";
	kEnd = true;
	simpleSound->Play();
}

Void MyForm2::pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
{
	if (Proc) {		
		Bitmap^ Img = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
		canv = Graphics::FromImage(Img);
		pictureBox1->Image = Img;
		pictureBox1->BackColor = Color::LightGreen;

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
					rect = System::Drawing::Rectangle(cube * j, cube * i, cube, cube);
					canv->DrawRectangle(System::Drawing::Pens::White, rect);
			}
		}		

		for (int i = 0; i < Snakem; i++) {
			if (i == 0) {
				rect = System::Drawing::Rectangle(cube * *(space + 1), cube * *(space), cube, cube);
				canv->FillRectangle(System::Drawing::Brushes::Purple, rect);
				canv->DrawRectangle(System::Drawing::Pens::DarkGreen, rect);
			}
			else {
				rect = System::Drawing::Rectangle(cube * *(space + i * Snaken + 1), cube * *(space + i * Snaken), cube, cube);
				canv->FillRectangle(System::Drawing::Brushes::Yellow, rect);
				canv->DrawRectangle(System::Drawing::Pens::DarkGreen, rect);
			}				
		}
		//Yazik
		if (isApple == 1 || isApple==2) {
			switch (headpolozh) {
			case 1:
			{
				rect = System::Drawing::Rectangle(cube * mouthj + 36, cube * mouthi + 13, 20, 10);
				break;
			}
			case 2:
			{
				rect = System::Drawing::Rectangle(cube * mouthj + 13, cube * mouthi -18, 10, 20);
				break;
			}
			case 3:
			{
				rect = System::Drawing::Rectangle(cube * mouthj - 18, cube * mouthi + 13, 20, 10);
				break;
			}
			case 4: {
				rect = System::Drawing::Rectangle(cube * mouthj + 13, cube * mouthi + 36, 10, 20);
				break;
			}
			}
			canv->FillRectangle(System::Drawing::Brushes::Pink, rect);			
		}
		//Apple
		rect = System::Drawing::Rectangle(cube * apj+5, cube * api+5, cube-5, cube-5);
		canv->FillEllipse(System::Drawing::Brushes::Red, rect);
		canv->DrawLine(System::Drawing::Pens::Black, apj*cube + 10, api*cube, apj*cube+18,api*cube+10);
		rect = System::Drawing::Rectangle(cube * apj + 14, cube * api, 4, 8);
		canv->FillEllipse(System::Drawing::Brushes::Green, rect);
	
		kspeed++;
		if (kspeed == sped) {		
			int tempi = *(space), tempj = *(space + 1);
			switch (headpolozh) {
			case 1:
			{
				if (CheckHead1()) (*(space + 1))++;
				else Proc = false;
				break;	
			}

			case 2:
			{
				if (CheckHead2()) (*(space))--;
				else Proc = false;
				break;
			}
			case 3:
			{
				if (CheckHead3()) (*(space + 1))--;
				else Proc = false;
				break;
			}
			case 4:
			{
				if (CheckHead4()) (*(space))++;
				else Proc = false;
				break;
			}
			}

			if (Proc) {
				CheckForApple();
				ChangePosition(tempi,tempj);
			}	
			kspeed = 0;
		}	
		if (!Proc) {
			
		}
	} 
	else {
		if (kEnd) {
			simpleSound->Stop();
			PlayerScore = Convert::ToInt64(label1->Text);
			label3->Text = "PRESS SPACE TO PLAY AGAIN.";
			if (PlayerScore > StartScore) {
				label4->Text = "Congratulations, " + Pname + " " + Psurname + "!\n      You have broken your record.";
				UpdateSnakeScore(PlayerScore, PlayerCode);
			}
			kEnd = false;
		}
	}
	return Void();
}

bool MyForm2::CheckHead1() {
	if (*(space + 1) == n - 1) return false;
	if ( fild[*(space)][*(space + 1) + 1] == 1) return false;
	return true;
}

bool MyForm2::CheckHead2() {
	if (*(space) == 0) return false;
	if (fild[*(space) - 1][*(space + 1)] == 1) return false;
	return true;
}

bool MyForm2::CheckHead3() {
	if (*(space + 1) == 0) return false;
	if (fild[*(space)][*(space + 1) - 1] == 1) return false;
	return true;
}

bool MyForm2::CheckHead4() {
	if (*(space) == m - 1) return false;
	if (fild[*(space) + 1][*(space + 1)] == 1) return false;
	return true;
}

void MyForm2::ChangePosition(int headi, int headj) {
	fild[*(space)][*(space + 1)] = 1;
	fild[*(space + (Snakem - 1) * Snaken)][*(space + (Snakem - 1) * Snaken + 1)] = 0;
	//Присвоение предыдущим последующие
	for (int i = Snakem - 1; i > 1; i--) {
		*(space + i * Snaken) = *(space + (i - 1) * Snaken);
		*(space + i * Snaken + 1) = *(space + (i - 1) * Snaken + 1);
	}

	*(space + Snaken) = headi;
	*(space + Snaken + 1) = headj;
}

void MyForm2::CheckForApple() {
	
	if (*(space) == api && *(space + 1) == apj) {
		isApple++;
		mouthi = api;
		mouthj = apj;
		Apples++;
		label1->Text = Convert::ToString(Apples);
		Snakem++;
		space = (int*)realloc(space, Snakem * Snaken * sizeof(int));
		//Задание позиции конца
		if (*(space + (Snakem - 2) * Snaken) + 1 == *(space + (Snakem - 3) * Snaken)) {
			*(space + (Snakem - 1) * Snaken) = *(space + (Snakem - 2) * Snaken) - 1;
			*(space + (Snakem - 1) * Snaken + 1) = *(space + (Snakem - 2) * Snaken + 1);
		}
		else if (*(space + (Snakem - 2) * Snaken) - 1 == *(space + (Snakem - 3) * Snaken)) {
			*(space + (Snakem - 1) * Snaken) = *(space + (Snakem - 2) * Snaken) + 1;
			*(space + (Snakem - 1) * Snaken + 1) = *(space + (Snakem - 2) * Snaken + 1);
		}
		else if (*(space + (Snakem - 2) * Snaken + 1) - 1 == *(space + (Snakem - 3) * Snaken + 1)) {
			*(space + (Snakem - 1) * Snaken) = *(space + (Snakem - 2) * Snaken);
			*(space + (Snakem - 1) * Snaken + 1) = *(space + (Snakem - 2) * Snaken + 1) + 1;
		}
		else if (*(space + (Snakem - 2) * Snaken + 1) + 1 == *(space + (Snakem - 3) * Snaken + 1)) {
			*(space + (Snakem - 1) * Snaken) = *(space + (Snakem - 2) * Snaken);
			*(space + (Snakem - 1) * Snaken + 1) = *(space + (Snakem - 2) * Snaken + 1) - 1;
		}

		fild[*(space + (Snakem - 1) * Snaken)][*(space + (Snakem - 1) * Snaken + 1)] = 1;

		srand(time(NULL));
		bool EmptyCell = true;
		do {
			api = rand() % 15;
			apj = rand() % 15;
			int i = 0;
			while (i < Snakem) {
				if ((*(space + i * Snaken) == api) && (*(space + i * Snaken + 1) == apj)) break;
				i++;
			}
			if (i == Snakem) EmptyCell = false;

		} while (EmptyCell);
	}
	else if (isApple == 1) {
		isApple++;
		mouthi = *(space);
		mouthj = *(space + 1);
	}
	else isApple = 0;
}

Void MyForm2::MyForm2_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) 
{
	if (e->KeyCode == Keys::Space) {
		if (!Proc) Initialize();
	}
	else {
		if (Proc) {
			int tempi = *(space), tempj = *(space + 1);
			if (e->KeyCode == Keys::Up) {

				if (headpolozh == 1 || headpolozh == 3) {
					if (CheckHead2()) {
						(*(space))--;
						CheckForApple();
						ChangePosition(tempi, tempj);
						headpolozh = 2;
						kspeed = -10;
					}
					else Proc = false;
				}
			}
			else if (e->KeyCode == Keys::Left) {

				if (headpolozh == 2 || headpolozh == 4) {
					if (CheckHead3()) {
						(*(space + 1))--;
						CheckForApple();
						ChangePosition(tempi, tempj);
						headpolozh = 3;
						kspeed = -10;
					}
					else Proc = false;
				}
			}
			else if (e->KeyCode == Keys::Down) {
				if (headpolozh == 1 || headpolozh == 3) {
					if (CheckHead4()) {
						(*(space))++;
						CheckForApple();
						ChangePosition(tempi, tempj);
						headpolozh = 4;
						kspeed = -10;
					}
					else Proc = false;
				}
			}
			else if (e->KeyCode == Keys::Right) {

				if (headpolozh == 2 || headpolozh == 4) {
					if (CheckHead1()) {
						(*(space + 1))++;
						CheckForApple();
						ChangePosition(tempi, tempj);
						headpolozh = 1;
						kspeed = -10;
					}
					else Proc = false;
				}
			}
		}
	}
}

Void MyForm2::MyForm2_Load(System::Object^ sender, System::EventArgs^ e) {
	Initialize();
}

Void MyForm2::MyForm2_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
	simpleSound->Stop();
}

void MyForm2::UpdateSnakeScore(int Score, int Code) {
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=Database.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);
	dbConnection->Open();
	String^ query = "UPDATE table1 SET Count2 ='" + Score + "' WHERE [Code] = " + Code;
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);
	dbComand->ExecuteNonQuery();
	dbConnection->Close();
}











