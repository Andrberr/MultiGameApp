#include "MyForm.h";
#include <Windows.h>
#include <stdio.h>;
#using <system.drawing.dll>
#include <stdlib.h>;
#include <ctime>; 
#include <string>;
#include <time.h>;
using namespace Project4; 
using namespace System;
using namespace System::Drawing;
using namespace System::Drawing::Drawing2D;
using namespace System::Drawing::Imaging;
using namespace System::Data::OleDb;

struct Dot {
	int k;
	int color;
};
const int m = 20;
const int n = 10;
struct Dot field[m][n];
int speed;
int koefspeed;
int cell = 36;
bool fl;
int k, x;
System::Drawing::Rectangle rec;
int figure[4][2];
int col;
int ymax;
bool Keyup;
bool Keydown;
int polozh;
bool Process;
bool Broke;
int Count = 0;

void MyForm::Initialize()
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			field[i][j].k = 0;
			field[i][j].color = 0;
		}
	}
	Broke = true;
	fl = false;
	speed = 60;
	koefspeed = speed - 1;
	ymax = m;
	Keyup = false;
	Keydown = false;
	polozh = 0;
	Process = true;
	Count = 0;
	label2->Text = Convert::ToString(Count);
	label3->Text = "";
	label4->Text = "";
	simpleSound->Play();
}

Void MyForm::pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
{	
		if (Process) {
			Bitmap^ Img = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
			canvas = Graphics::FromImage(Img);
			pictureBox1->Image = Img;
			pictureBox1->BackColor = Color::Silver;

			srand(time(NULL));
			if (Keydown) {
				speed = 20;
				if (koefspeed >= 20) koefspeed = speed - 1;
			}
			else {
				speed = 60;
			}
			koefspeed++;
			if (koefspeed == speed) {
				if (!fl) {			
					k = 1 + rand() % 7;				
					Broke = false;
					if (Process) {
						switch (k) {
						case 1:
						{
							col = 1;
							x = rand() % 7;
							int j = 0;
							for (int i = x; i < x + 4; i++) {
								figure[j][0] = 0;
								figure[j][1] = i;
								j++;
							}
							break;
						}
						case 2:
						{
							col = 2;
							x = rand() % 8;
							col = 2;
							figure[0][0] = 0;
							figure[0][1] = x;
							figure[1][0] = 0;
							figure[1][1] = x + 1;
							figure[2][0] = 1;
							figure[2][1] = x + 1;
							figure[3][0] = 1;
							figure[3][1] = x + 2;
							break;
						}
						case 3:
						{
							col = 3;
							x = rand() % 8;
							figure[0][0] = 1;
							figure[0][1] = x;
							figure[1][0] = 1;
							figure[1][1] = x + 1;
							figure[2][0] = 0;
							figure[2][1] = x + 1;
							figure[3][0] = 0;
							figure[3][1] = x + 2;
							break;
						}
						case 4:
						{
							col = 4;
							x = rand() % 8;
							figure[0][0] = 0;
							figure[0][1] = x + 1;
							figure[1][0] = 1;
							figure[1][1] = x;
							figure[2][0] = 1;
							figure[2][1] = x + 1;
							figure[3][0] = 1;
							figure[3][1] = x + 2;
							break;
						}
						case 5:
						{
							col = 5;
							x = rand() % 9;
							figure[0][0] = 0;
							figure[0][1] = x;
							figure[1][0] = 0;
							figure[1][1] = x + 1;
							figure[2][0] = 1;
							figure[2][1] = x + 1;
							figure[3][0] = 2;
							figure[3][1] = x + 1;
							break;
						}
						case 6:
						{
							col = 6;
							x = rand() % 9;
							figure[0][0] = 2;
							figure[0][1] = x;
							figure[1][0] = 2;
							figure[1][1] = x + 1;
							figure[2][0] = 1;
							figure[2][1] = x + 1;
							figure[3][0] = 0;
							figure[3][1] = x + 1;
							break;
						}
						case 7:
						{
							col = 7;
							x = rand() % 9;
							figure[0][0] = 0;
							figure[0][1] = x;
							figure[1][0] = 0;
							figure[1][1] = x + 1;
							figure[2][0] = 1;
							figure[2][1] = x;
							figure[3][0] = 1;
							figure[3][1] = x + 1;
							break;
						}
						}
						polozh = 1;
						fl = true;
						Process = Proc(k);
						if (!Process) {
							Bitmap^ image1; // фото загрузки в pictureBox
							image1 = gcnew Bitmap("C:\\Users\\Abere\\source\\repos\\Project4\\images\\img.gif"); // инициализация файл с фото
							pictureBox1->Image = image1;
							pictureBox1->BackColor = Color::Black;
							if (Count > PlayerScore) {
								label4->Text ="Congratulations, "+ Pname + " " + Psurname + "!\n      You have broken your record.";
								PlayerScore = Count;
							}

							label3->Text = "  Press SPACE to start again.";
							simpleSound->Stop();
							if (PlayerScore > StartScore) {
								UpdateTetrisScore(PlayerScore, PlayerCode);
							}
						}
					}				
				}
				else {
					if (CheckDown()) {
						for (int i = 0; i < 4; i++) {
							figure[i][0]++;
						}
					}
					else {
						for (int i = 0; i < 4; i++) {
							field[figure[i][0]][figure[i][1]].k = 1;
							field[figure[i][0]][figure[i][1]].color = k;
						}

						for (int j = 0; j < 4; j++) {
							if (figure[j][0] < ymax) ymax = figure[j][0];
						}

						fl = false;
						koefspeed = speed - 1;
						LineDown();					
					}
				}
				koefspeed = 0;
			}

			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					rec = System::Drawing::Rectangle(cell * j, cell * i, cell, cell);

					if (field[i][j].k == 0) {
						canvas->FillRectangle(System::Drawing::Brushes::Gray, rec);
						canvas->DrawRectangle(System::Drawing::Pens::White, rec);
					}
					else {					
						switch (field[i][j].color) {
						case 1: canvas->FillRectangle(System::Drawing::Brushes::Aqua, rec);
							break;
						case 2: canvas->FillRectangle(System::Drawing::Brushes::Red, rec);
							break;
						case 3: canvas->FillRectangle(System::Drawing::Brushes::Green, rec);
							break;
						case 4: canvas->FillRectangle(System::Drawing::Brushes::Yellow, rec);
							break;
						case 5: canvas->FillRectangle(System::Drawing::Brushes::Orange, rec);
							break;
						case 6: canvas->FillRectangle(System::Drawing::Brushes::Purple, rec);
							break;
						case 7: canvas->FillRectangle(System::Drawing::Brushes::Pink, rec);
							break;
						}
					}			
				}
			}

			for (int i = ymax; i < m; i++) {
				for (int j = 0; j < n; j++) {
					rec = System::Drawing::Rectangle(cell * j, cell * i, cell, cell);
					if (field[i][j].k == 1) canvas->DrawRectangle(System::Drawing::Pens::Black, rec);
				}
			}
			
			if (!Broke) {
				for (int i = 0; i < 4; i++) {
					rec = System::Drawing::Rectangle(cell * figure[i][1], cell * figure[i][0], cell, cell);
					switch (col) {
					case 1: canvas->FillRectangle(System::Drawing::Brushes::Aqua, rec);
						break;
					case 2: canvas->FillRectangle(System::Drawing::Brushes::Red, rec);
						break;
					case 3: canvas->FillRectangle(System::Drawing::Brushes::Green, rec);
						break;
					case 4: canvas->FillRectangle(System::Drawing::Brushes::Yellow, rec);
						break;
					case 5: canvas->FillRectangle(System::Drawing::Brushes::Orange, rec);
						break;
					case 6: canvas->FillRectangle(System::Drawing::Brushes::Purple, rec);
						break;
					case 7: canvas->FillRectangle(System::Drawing::Brushes::Pink, rec);
						break;
					}
					canvas->DrawRectangle(System::Drawing::Pens::Black, rec);
				}
			}	
		}

	return Void();
}

Void MyForm::MyForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	Initialize();
}

Void MyForm::MyForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
{
	simpleSound->Stop();
}

void MyForm::UpdateTetrisScore(int Score, int Code) {
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=Database.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);
	dbConnection->Open();
	String^ query = "UPDATE table1 SET Count1 ='" + Score + "' WHERE [Code] = " + Code;
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);
	dbComand->ExecuteNonQuery();
	dbConnection->Close();
}

Void MyForm::MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
{
	if (e->KeyCode == Keys::Up)
	{
		if (fl) {

			switch (k) {
			case 1:
			{
				if (polozh == 1) {
					if (figure[1][0] > 0) {
						if (field[figure[1][0] - 1][figure[1][1]].k == 0 && field[figure[1][0] + 1][figure[1][1]].k == 0 && field[figure[1][0] + 2][figure[1][1]].k == 0) {
							figure[0][0]--;
							figure[0][1]++;
							figure[2][0]++;
							figure[2][1]--;
							figure[3][0] += 2;
							figure[3][1] -= 2;
							polozh = 2;
						}
					}
				}
				else {
					if (figure[1][1] > 0 && figure[1][1] < n - 2) {
						if (field[figure[1][0]][figure[1][1] - 1].k == 0 && field[figure[1][0]][figure[1][1] + 1].k == 0 && field[figure[1][0]][figure[1][1] + 2].k == 0) {
							figure[0][0]++;
							figure[0][1]--;
							figure[2][0]--;
							figure[2][1]++;
							figure[3][0] -= 2;
							figure[3][1] += 2;
							polozh = 1;
						}
					}
				}
				break;
			}

			case 2:
			{
				if (polozh == 1) {
					if (figure[0][0] < m - 2) {
						if (field[figure[0][0] + 2][figure[0][1]].k == 0 && field[figure[0][0] + 1][figure[0][1]].k == 0) {
							figure[0][0]++;
							figure[3][0]++;
							figure[3][1] -= 2;
							polozh = 2;
						}
					}
				}
				else {
					if (figure[2][1] < n - 1) {
						if (field[figure[2][0]][figure[2][1] + 1].k == 0 && field[figure[1][0]][figure[1][1] - 1].k == 0) {
							figure[0][0]--;
							figure[3][0]--;
							figure[3][1] += 2;
							polozh = 1;
						}
					}
				}
				break;
			}
			case 3:
			{
				if (polozh == 1) {
					if (figure[1][0] < m - 1) {
						if (field[figure[0][0] - 1][figure[0][1]].k == 0 && field[figure[1][0] + 1][figure[1][1]].k == 0) {
							figure[2][1]--;
							figure[3][0] += 2;
							figure[3][1]--;
							polozh = 2;
						}
					}
				}
				else {
					if (figure[2][1] < n - 2) {
						if (field[figure[2][0]][figure[2][1] + 1].k == 0 && field[figure[2][0]][figure[2][1] + 2].k == 0) {
							figure[2][1]++;
							figure[3][0] -= 2;
							figure[3][1]++;
							polozh = 1;
						}
					}
				}
				break;
			}
			case 4:
			{
				switch (polozh) {
				case 1:
				{
					if (figure[2][0] < m - 1) {
						if (field[figure[2][0] + 1][figure[2][1]].k == 0) {
							figure[3][0]++;
							figure[3][1]--;
							polozh = 2;
						}
					}
					break;
				}
				case 2:
				{
					if (figure[2][1] < n - 1) {
						if (field[figure[2][0]][figure[2][1] + 1].k == 0) {
							figure[0][0]++;
							figure[0][1]++;
							polozh = 3;
						}
					}
					break;
				}
				case 3:
				{
					if (figure[2][0] > 0) {
						if (field[figure[2][0] - 1][figure[2][1]].k == 0) {
							figure[1][0]--;
							figure[1][1]++;
							polozh = 4;
						}
					}
					break;
				}
				case 4:
				{
					if (figure[2][1] > 0) {
						if (field[figure[2][0]][figure[2][1] - 1].k == 0) {
							figure[0][0]--;
							figure[0][1]--;
							figure[1][0]++;
							figure[1][1]--;
							figure[3][0]--;
							figure[3][1]++;
							polozh = 1;
						}
					}
					break;
				}
				}
				break;
			}
			case 5:
			{
				switch (polozh) {
				case 1:
				{
					if (figure[2][1] < n - 1) {
						if (field[figure[0][0] + 1][figure[0][1]].k == 0 && field[figure[0][0] + 2][figure[0][1]].k == 0) {
							figure[0][0]++;
							figure[3][1]--;
							figure[1][0]++;
							figure[1][1]++;
							polozh = 2;
						}
					}
					break;
				}
				case 2:
				{
					if (figure[2][0] > 0) {
						if (field[figure[2][0] - 1][figure[2][1]].k == 0 && field[figure[2][0] + 1][figure[2][1]].k == 0 && field[figure[1][0] + 1][figure[1][1]].k == 0) {
							figure[0][0]--;
							figure[0][1]++;
							figure[3][1]++;
							figure[1][0]++;
							polozh = 3;
						}
					}
					break;
				}
				case 3:
				{
					if (figure[2][1] > 0) {
						if (field[figure[2][0]][figure[2][1] - 1].k == 0 && field[figure[2][0]][figure[2][1] + 1].k == 0 && field[figure[0][0]][figure[0][1] + 1].k == 0) {
							figure[0][1]++;
							figure[1][0]--;
							figure[3][0]--;
							figure[3][1]--;
							polozh = 4;
						}
					}
					break;
				}
				case 4:
				{
					if (figure[2][0] < m - 1) {
						if (field[figure[2][0] + 1][figure[2][1]].k == 0 && field[figure[2][0] - 1][figure[2][1]].k == 0 && field[figure[2][0] - 1][figure[2][1] - 1].k == 0) {
							figure[0][1] -= 2;
							figure[1][0]--;
							figure[1][1]--;
							figure[3][0]++;
							figure[3][1]++;
							polozh = 1;
						}
					}
					break;
				}
				}

				break;
			}
			case 6:
			{
				switch (polozh) {
				case 1:
				{
					if (figure[2][1] < n - 1) {
						if (field[figure[2][0]][figure[2][1] + 1].k == 0 && field[figure[2][0]][figure[2][1] - 1].k == 0 && field[figure[3][0]][figure[3][1] - 1].k == 0) {
							figure[0][0]--;
							figure[3][1]--;
							figure[1][0]--;
							figure[1][1]++;
							polozh = 2;
						}
					}
					break;
				}
				case 2:
				{
					if (figure[2][0] < m - 1) {
						if (field[figure[2][0] + 1][figure[2][1]].k == 0 && field[figure[3][0]][figure[3][1] + 1].k == 0 && field[figure[1][0] - 1][figure[1][1]].k == 0) {
							figure[3][1]++;
							figure[1][0]--;
							figure[0][0]++;
							figure[0][1]++;
							polozh = 3;
						}
					}
					break;
				}
				case 3:
				{
					if (figure[2][1] > 0) {
						if (field[figure[2][0]][figure[2][1] - 1].k == 0 && field[figure[2][0]][figure[2][1] + 1].k == 0 && field[figure[0][0]][figure[0][1] + 1].k == 0) {
							figure[1][0]++;
							figure[0][1]++;
							figure[3][0]++;
							figure[3][1]--;
							polozh = 4;
						}
					}
					break;
				}
				case 4:
				{
					if (figure[2][0] > 0) {
						if (field[figure[2][0] - 1][figure[2][1]].k == 0 && field[figure[2][0] + 1][figure[2][1]].k == 0 && field[figure[3][0] + 1][figure[3][1]].k == 0) {
							figure[0][1] -= 2;
							figure[1][0]++;
							figure[1][1]--;
							figure[3][0]--;
							figure[3][1]++;
							polozh = 1;
						}
					}
					break;
				}
				}
				break;
			}
			}
		}
	}
	else if (e->KeyCode == Keys::Down)
	{
		Keydown = true;
	}
	else if (e->KeyCode == Keys::Left)
	{
			if (CheckLeft()) {
				for (int i = 0; i < 4; i++) {
					figure[i][1]--;
				}
			}
	}
	else if (e->KeyCode == Keys::Right)
	{
		if(CheckRight()) {
			for (int i = 0; i < 4; i++) {
				figure[i][1]++;
			}
		}
	}
	else if (e->KeyCode == Keys::Space)
	{
	  if (!Process) {
		  Initialize();
	  }
    }
}

Void MyForm::MyForm_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
{
	if (e->KeyCode == Keys::Up)
	{
		Keyup = false;
	}
	else if (e->KeyCode == Keys::Down)
	{
		Keydown = false;
	}
}

int MyForm::FindUp()
{
	int min = figure[0][0];
	for (int i = 1; i < 4; i++) {
		if (figure[i][0] < min) min = figure[i][0];
	}
	return min;
}

int MyForm::FindDown()
{
	int max = figure[0][0];
	for (int i = 1; i < 4; i++) {
		if (figure[i][0] > max) max = figure[i][0];
	}
	return max;
}

int MyForm::FindLeft()
{
	int min = figure[0][1];
	for (int i = 1; i < 4; i++) {
		if (figure[i][1] < min) min = figure[i][1];
	}
	return min;
}

int MyForm::FindRight()
{
	int max = figure[0][1];
	for (int i = 1; i < 4; i++) {
		if (figure[i][1] > max) max = figure[i][1];
	}
	return max;
}

bool MyForm::CheckUp()
{
	int y = FindUp();
	if (y > 0) {
		for (int i = 0; i < 4; i++) {
			if (field[figure[i][0] - 1][figure[i][1]].k == 1) return false;
		}
	}
	else return false;

	return true;
}


bool MyForm::CheckDown()
{
	int y = FindDown();
	if (y < m - 1) {
		for (int i = 0; i < 4; i++) {
			if (field[figure[i][0] + 1][figure[i][1]].k == 1) return false;
		}
	}
	else return false;

	return true;
}

bool MyForm::CheckLeft()
{
	int x = FindLeft();
	if (x != 0) {
		for (int i = 0; i < 4; i++) {
			if (field[figure[i][0]][figure[i][1] - 1].k == 1) return false;
		}
	}
	else return false;

	return true;
}

bool MyForm::CheckRight()
{
	int x = FindRight();
	if (x != n-1) {
		for (int i = 0; i < 4; i++) {
			if (field[figure[i][0]][figure[i][1] + 1].k == 1) return false;
		}
	}
	else return false;

	return true;
}

bool MyForm::Process1() {
	for (int i = x; i < x + 4; i++) {
		if (field[0][i].k == 1) return false;
	}
	return true;
}

bool MyForm::Process2() {
	if (field[0][x].k == 1) return false;
	if (field[0][x + 1].k == 1) return false;
	if (field[1][x + 1].k == 1) return false;
	if (field[1][x + 2].k == 1) return false;
	return true;
}

bool MyForm::Process3() {
	if (field[0][x + 1].k == 1) return false;
	if (field[0][x + 2].k == 1) return false;
	if (field[1][x].k == 1) return false;
	if (field[1][x + 1].k == 1) return false;
	return true;
}

bool MyForm::Process4() {
	if (field[0][x + 1].k == 1) return false;
	for (int i = x; i < x + 3; i++) {
		if (field[1][i].k == 1) return false;
	}
	return true;
}

bool MyForm::Process5() {
	if (field[0][x].k == 1) return false;
	for (int i = 0; i < 3; i++) {
		if (field[i][x + 1].k == 1) return false;
	}
	return true;
}

bool MyForm::Process6() {
	if (field[2][x].k == 1) return false;
	for (int i = 0; i < 3; i++) {
		if (field[i][x + 1].k == 1) return false;
	}
	return true;
}

bool MyForm::Process7() {
	for (int i = 0; i < 2; i++) {
		for (int j = x; j < x + 2; j++) {
			if (field[i][j].k == 1) return false;
		}
	}
	return true;
}

bool MyForm::Proc(int k) {
	switch (k) {
	case 1: return Process1();
	case 2: return Process2();
	case 3: return Process3();
	case 4: return Process4();
	case 5: return Process5();
	case 6: return Process6();
	case 7: return Process7(); 
	}
}

void MyForm::LineDown() {
	int koef = 0;
	int brok[4];
	bool full;
	for (int i = 0; i < 4; i++) {
		full = true;
		for (int j = 0; j < n; j++) {
			if (field[figure[i][0]][j].k == 0) {
				full = false;
				break;
			}
		}
		if (full) {
			bool equal = false;
			for (int d = 0; d < koef; d++) {
				if (brok[d] == figure[i][0]) {
					equal = true;
					break;
				}
			}
			if (!equal) {
				brok[koef] = figure[i][0];
				koef++;
			}
		}	
    }
	if (koef!=0) {	
		int max = brok[0];
		for (int j = 1; j < koef; j++) {
			if (brok[j] > max) max = brok[j];
		}

		for (int k = max; k > koef; k--) {
			for (int l = 0; l < n; l++) {
				field[k][l] = field[k - koef][l];
			}

		}
		for (int i = 0; i < koef; i++) {
			for (int j = 0; j < n; j++) {
				field[i][j].k = 0;
			}
		}

		Broke = true;
		Count+=koef;
		label2->Text = Convert::ToString(Count);
		crashSound->Play();
		System::Threading::Thread::Sleep(TimeSpan::FromSeconds(0.25));
		simpleSound->Play();
	}
}









