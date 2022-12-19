#include "MyForm1.h";
#include "AddPlayerForm.h";
#include "Game2048.h";
#include <Windows.h>
#include <stdio.h>;
#using <system.drawing.dll>
#include <stdlib.h>;
#include <ctime>; 
#include <string>;
#include <time.h>;
#include "MyForm2.h";
#include "MyForm.h";
using namespace Project4; 
using namespace System;
using namespace System::Data::OleDb;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm1);
	return 0;
}

Void MyForm1::MyForm1_Load(System::Object^ sender, System::EventArgs^ e)
{
	ReadData(true);
}

Void MyForm1::pictureTetris_Click(System::Object^ sender, System::EventArgs^ e) {
	startGame(1);
}

Void MyForm1::pictureSnake_Click(System::Object^ sender, System::EventArgs^ e) {
	startGame(2);
}

Void MyForm1::picture2048Game_Click(System::Object^ sender, System::EventArgs^ e) {
	startGame(3);
}

Void MyForm1::Add_Click(System::Object^ sender, System::EventArgs^ e) {
	Koef = 1;
	AddPlayerForm^ ff = gcnew AddPlayerForm(this);
	ff->Show();
}

Void MyForm1::Delete_Click(System::Object^ sender, System::EventArgs^ e) {
	Koef = 2;
	AddPlayerForm^ ff = gcnew AddPlayerForm(this);
	ff->Show();
}

Void MyForm1::Update_Click(System::Object^ sender, System::EventArgs^ e) {
	ReadData(false);
	UpdateLiderBoard();
}

bool MyForm1::FindExistPlayer(String^ fname, String^ fsurname) {
	int size = PlayersData->RowCount;
	size--;
	String^ name, ^ surname;
	for (int i = 0; i < size; i++) {
		name = PlayersData->Rows[i]->Cells[1]->Value->ToString();
		surname = PlayersData->Rows[i]->Cells[2]->Value->ToString();
		if (fname->Equals(name) && fsurname->Equals(surname)) {
			return false;
		}
	}
	return true;
}

void MyForm1::AddDataView(String^ fname, String^ fsurname) {
	int kol = PlayersData->RowCount;
	kol--;
	bool CheckEqualRows = FindExistPlayer(fname, fsurname);
	
	if (CheckEqualRows) {
		PlayersData->RowCount++;
		String^ num = Convert::ToString(kol+1);
		String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=Database.mdb";
		OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

		dbConnection->Open();
		String^ query = "INSERT INTO [table1] ([Num], [FirstName], [LastName], [Count1], [Count2], [Count3]) VALUES ('" + num + "', '" + fname + "', '" + fsurname + "', '" + 0 + "', '" + 0 + "', '" + 0 + "')";
		OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);
		if (dbComand->ExecuteNonQuery() == 1)
		{
			MessageBox::Show("Player Was Added!", "Successfully!");
		}
		else MessageBox::Show("Request Execution Error!", "Error!");

		ReadData(false);
		dbConnection->Close();
	}
	else MessageBox::Show("Such Player already exists!", "Error!");
	
}

void MyForm1::DeleteDataView(String^ fname, String^ fsurname) {
	int kol = PlayersData->RowCount;
	kol--;
	String^ name, ^ surname, ^num;
	bool CheckEqualRows = false;
	int k;
	for (int i = 0; i < kol; i++) {
		name = PlayersData->Rows[i]->Cells[1]->Value->ToString();
		surname = PlayersData->Rows[i]->Cells[2]->Value->ToString();
		if (fname->Equals(name) && fsurname->Equals(surname)) {
			num = PlayersData->Rows[i]->Cells[0]->Value->ToString();
			CheckEqualRows = true;
			k = i;
			break;
		}
	}

	if (CheckEqualRows) {
		
		for (int i = k; i < kol; i++) {
			PlayersData->Rows[i]->Cells[0]->Value = i;
		}
		PlayersData->Rows->RemoveAt(k);

		String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=Database.mdb";
		OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

		dbConnection->Open();
		String^ query;
		query = "DELETE FROM [table1] WHERE Num = " + num;
		OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);
		if (dbComand->ExecuteNonQuery() == 1)
		{
			MessageBox::Show("Player Was Deleted!", "Successfully!");
		}
		else MessageBox::Show("Request Execution Error!", "Error!");

		dbConnection->Close();

		
		for (int i = k; i < kol-1; i++) {
			int whereNum = Convert::ToInt64(PlayersData->Rows[i]->Cells[6]->Value);
			int setNum = Convert::ToInt64(PlayersData->Rows[i]->Cells[0]->Value);
			Update(whereNum, setNum);	
		}		

	}
	else MessageBox::Show("There is no such Player!", "Error!");
} 

void MyForm1::Update(int whereNum, int setNum) {
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=Database.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);
	dbConnection->Open();   
	String^ query = "UPDATE table1 SET Num ='" + setNum + "' WHERE [Code] = " + whereNum;
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);
	dbComand->ExecuteNonQuery();
	dbConnection->Close();
}

void MyForm1::UpdateAllData() {
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=Database.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);
	String^ query;
	OleDbCommand^ dbComand;
	dbConnection->Open();
	int n = PlayersData->RowCount;
	n--;
	for (int i = 0; i < n; i++) {
		query = "UPDATE table1 SET Num ='" + PlayersData->Rows[i]->Cells[0]->Value + "' WHERE [Code] = " + PlayersData->Rows[i]->Cells[6]->Value;
		dbComand = gcnew OleDbCommand(query, dbConnection);
		dbComand->ExecuteNonQuery();
		query = "UPDATE table1 SET FirstName ='" + PlayersData->Rows[i]->Cells[1]->Value + "' WHERE [Code] = " + PlayersData->Rows[i]->Cells[6]->Value;
		dbComand = gcnew OleDbCommand(query, dbConnection);
		dbComand->ExecuteNonQuery();
		query = "UPDATE table1 SET LastName ='" + PlayersData->Rows[i]->Cells[2]->Value + "' WHERE [Code] = " + PlayersData->Rows[i]->Cells[6]->Value;
		dbComand = gcnew OleDbCommand(query, dbConnection);
		dbComand->ExecuteNonQuery();
		query = "UPDATE table1 SET Count1 ='" + PlayersData->Rows[i]->Cells[3]->Value + "' WHERE [Code] = " + PlayersData->Rows[i]->Cells[6]->Value;
		dbComand = gcnew OleDbCommand(query, dbConnection);
		dbComand->ExecuteNonQuery();
		query = "UPDATE table1 SET Count2 ='" + PlayersData->Rows[i]->Cells[4]->Value + "' WHERE [Code] = " + PlayersData->Rows[i]->Cells[6]->Value;
		dbComand = gcnew OleDbCommand(query, dbConnection);
		dbComand->ExecuteNonQuery();
		query = "UPDATE table1 SET Count3 ='" + PlayersData->Rows[i]->Cells[5]->Value + "' WHERE [Code] = " + PlayersData->Rows[i]->Cells[6]->Value;
		dbComand = gcnew OleDbCommand(query, dbConnection);
		dbComand->ExecuteNonQuery();
	}
	dbConnection->Close();
}

void MyForm1::ReadData(bool beginFlag) {
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=Database.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	dbConnection->Open(); 
	String^ query = "SELECT * FROM [table1]";  
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);  
	OleDbDataReader^ dbReader = dbComand->ExecuteReader(); 
	
	if (dbReader->HasRows == false) {
		MessageBox::Show("Data Reading Error!", "Error!");
	}
	else {
		int i = 0;
		while (dbReader->Read()) {
		if (beginFlag) PlayersData->RowCount++;
			PlayersData->Rows[i]->Cells[0]->Value = Convert::ToString(dbReader["Num"]);
			PlayersData->Rows[i]->Cells[1]->Value = Convert::ToString(dbReader["FirstName"]);
			PlayersData->Rows[i]->Cells[2]->Value = Convert::ToString(dbReader["LastName"]);
			PlayersData->Rows[i]->Cells[3]->Value = Convert::ToString(dbReader["Count1"]);
			PlayersData->Rows[i]->Cells[4]->Value = Convert::ToString(dbReader["Count2"]);
			PlayersData->Rows[i]->Cells[5]->Value = Convert::ToString(dbReader["Count3"]);
			PlayersData->Rows[i]->Cells[6]->Value = Convert::ToString(dbReader["Code"]);
			i++;
		}
	}
	dbReader->Close();
	dbConnection->Close();
}

void MyForm1::startGame(int game) {
	if (PlayersData->SelectedRows->Count != 1) {
		MessageBox::Show("Choose one Player!", "Attention!");
		return;
	}
	else {
		//Узнаём индекс выделенной строки
		int index = PlayersData->SelectedRows[0]->Index;

		if (PlayersData->Rows[index]->Cells[0]->Value == nullptr ||
			PlayersData->Rows[index]->Cells[1]->Value == nullptr ||
			PlayersData->Rows[index]->Cells[2]->Value == nullptr ||
			PlayersData->Rows[index]->Cells[3]->Value == nullptr) {
			MessageBox::Show("Choose one Player!", "Attention!");
			return;
		}
		else {
			switch (game) {
			case 1: {
				MyForm^ ff = gcnew MyForm(Convert::ToInt64(PlayersData->Rows[index]->Cells[3]->Value), Convert::ToString(PlayersData->Rows[index]->Cells[1]->Value), Convert::ToString(PlayersData->Rows[index]->Cells[2]->Value), Convert::ToInt64(PlayersData->Rows[index]->Cells[6]->Value));
				ff->Show();
				break;
			}
			case 2:
			{
				MyForm2^ ff = gcnew MyForm2(Convert::ToInt64(PlayersData->Rows[index]->Cells[4]->Value), Convert::ToString(PlayersData->Rows[index]->Cells[1]->Value), Convert::ToString(PlayersData->Rows[index]->Cells[2]->Value), Convert::ToInt64(PlayersData->Rows[index]->Cells[6]->Value));
				ff->Show();
				break;
			}
			case 3: {
				 Game2048^ ff = gcnew Game2048(Convert::ToInt64(PlayersData->Rows[index]->Cells[5]->Value), Convert::ToString(PlayersData->Rows[index]->Cells[1]->Value), Convert::ToString(PlayersData->Rows[index]->Cells[2]->Value), Convert::ToInt64(PlayersData->Rows[index]->Cells[6]->Value));
				ff->Show();
			}
			}
		}
	}
}

void MyForm1::UpdateLiderBoard() {

	int n = PlayersData->RowCount;
	n--;
	int temp;
	int tNum, Count1, Count2, Count3, tCode;
	String ^tName, ^tSurname;
	int curr;
	int j;
	for (int i = 1; i < n; i++) {
		tName = Convert::ToString(PlayersData->Rows[i]->Cells[1]->Value);
		tSurname = Convert::ToString(PlayersData->Rows[i]->Cells[2]->Value);
		Count1 = Convert::ToInt64(PlayersData->Rows[i]->Cells[3]->Value);
		Count2 = Convert::ToInt64(PlayersData->Rows[i]->Cells[4]->Value);
		Count3 = Convert::ToInt64(PlayersData->Rows[i]->Cells[5]->Value);

		temp = Convert::ToInt64(PlayersData->Rows[i]->Cells[3]->Value) + Convert::ToInt64(PlayersData->Rows[i]->Cells[4]->Value) + Convert::ToInt64(PlayersData->Rows[i]->Cells[5]->Value);
	    j = i - 1;
		while (j >= 0 && (Convert::ToInt64(PlayersData->Rows[j]->Cells[3]->Value) + Convert::ToInt64(PlayersData->Rows[j]->Cells[4]->Value) + Convert::ToInt64(PlayersData->Rows[j]->Cells[5]->Value)) < temp) {
			for (int l = 1; l <= 5; l++) {
				PlayersData->Rows[j + 1]->Cells[l]->Value = PlayersData->Rows[j]->Cells[l]->Value;
			}
	        j = j - 1;
      	}

		PlayersData->Rows[j + 1]->Cells[1]->Value = tName;
		PlayersData->Rows[j + 1]->Cells[2]->Value = tSurname;
		PlayersData->Rows[j + 1]->Cells[3]->Value = Count1;
		PlayersData->Rows[j + 1]->Cells[4]->Value = Count2;
		PlayersData->Rows[j + 1]->Cells[5]->Value = Count3;	
	}
	UpdateAllData();		
}

Void MyForm1::pictureTetris_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
	pictureTetris->Cursor = Cursors::Hand;
	pictureTetris->Image = tetrisfont;
}
Void MyForm1::pictureTetris_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
	pictureTetris->Image = tetriscom;
}
Void MyForm1::pictureSnake_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
	pictureSnake->Cursor = Cursors::Hand;
	pictureSnake->Image = snakefont;
}
Void MyForm1::pictureSnake_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
	pictureSnake->Image = snakecom;
}
Void MyForm1::picture2048Game_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
	picture2048Game->Cursor = Cursors::Hand;
	picture2048Game->Image = font2048;
}
Void MyForm1::picture2048Game_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
	picture2048Game->Image = com2048;
}
Void MyForm1::AddPB_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
	AddPB->Cursor = Cursors::Hand;
	AddPB->Image = ad;
}
Void MyForm1::AddPB_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
	AddPB->Image = add;
}
Void MyForm1::UpdatePB_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
	UpdatePB->Cursor = Cursors::Hand;
    UpdatePB->Image = up;
}
Void MyForm1::UpdatePB_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
	UpdatePB->Image = upd;
}
Void MyForm1::DeletePB_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
	DeletePB->Cursor = Cursors::Hand;
	DeletePB->Image = del;
}
Void MyForm1::DeletePB_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
	DeletePB->Image = delet;
}

