#pragma once
ref class MyForm2;
ref class AddPlayerForm;
ref class MyForm;

namespace Project4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}


	protected:


	private: System::Windows::Forms::DataGridView^ PlayersData;

	private: System::Windows::Forms::GroupBox^ groupBox1;






	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Place;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ FirstName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ LastName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ TetrisScore;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ SnakeScore;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Score2048;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Code;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::PictureBox^ pictureTetris;
	private: System::Windows::Forms::PictureBox^ pictureSnake;
	private: System::Windows::Forms::PictureBox^ picture2048Game;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PictureBox^ DeletePB;
	private: System::Windows::Forms::PictureBox^ UpdatePB;

	private: System::Windows::Forms::PictureBox^ AddPB;









	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm1::typeid));
			this->PlayersData = (gcnew System::Windows::Forms::DataGridView());
			this->Place = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->FirstName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->LastName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->TetrisScore = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->SnakeScore = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Score2048 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Code = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->DeletePB = (gcnew System::Windows::Forms::PictureBox());
			this->UpdatePB = (gcnew System::Windows::Forms::PictureBox());
			this->AddPB = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->picture2048Game = (gcnew System::Windows::Forms::PictureBox());
			this->pictureSnake = (gcnew System::Windows::Forms::PictureBox());
			this->pictureTetris = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PlayersData))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DeletePB))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->UpdatePB))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AddPB))->BeginInit();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picture2048Game))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureSnake))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureTetris))->BeginInit();
			this->SuspendLayout();
			// 
			// PlayersData
			// 
			this->PlayersData->BackgroundColor = System::Drawing::Color::DarkKhaki;
			this->PlayersData->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->PlayersData->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->Place, this->FirstName,
					this->LastName, this->TetrisScore, this->SnakeScore, this->Score2048, this->Code
			});
			this->PlayersData->GridColor = System::Drawing::Color::Olive;
			this->PlayersData->Location = System::Drawing::Point(429, 116);
			this->PlayersData->Name = L"PlayersData";
			this->PlayersData->RowHeadersWidth = 51;
			this->PlayersData->RowTemplate->Height = 24;
			this->PlayersData->Size = System::Drawing::Size(1070, 694);
			this->PlayersData->TabIndex = 2;
			// 
			// Place
			// 
			this->Place->HeaderText = L"Place";
			this->Place->MinimumWidth = 6;
			this->Place->Name = L"Place";
			this->Place->ReadOnly = true;
			this->Place->Width = 125;
			// 
			// FirstName
			// 
			this->FirstName->HeaderText = L"Name";
			this->FirstName->MinimumWidth = 6;
			this->FirstName->Name = L"FirstName";
			this->FirstName->ReadOnly = true;
			this->FirstName->Width = 125;
			// 
			// LastName
			// 
			this->LastName->HeaderText = L"Surname";
			this->LastName->MinimumWidth = 6;
			this->LastName->Name = L"LastName";
			this->LastName->ReadOnly = true;
			this->LastName->Width = 125;
			// 
			// TetrisScore
			// 
			this->TetrisScore->HeaderText = L"Tetris Score";
			this->TetrisScore->MinimumWidth = 6;
			this->TetrisScore->Name = L"TetrisScore";
			this->TetrisScore->ReadOnly = true;
			this->TetrisScore->Width = 125;
			// 
			// SnakeScore
			// 
			this->SnakeScore->HeaderText = L"Snake Score";
			this->SnakeScore->MinimumWidth = 6;
			this->SnakeScore->Name = L"SnakeScore";
			this->SnakeScore->ReadOnly = true;
			this->SnakeScore->Width = 125;
			// 
			// Score2048
			// 
			this->Score2048->HeaderText = L"2048 Score";
			this->Score2048->MinimumWidth = 6;
			this->Score2048->Name = L"Score2048";
			this->Score2048->ReadOnly = true;
			this->Score2048->Width = 125;
			// 
			// Code
			// 
			this->Code->HeaderText = L"";
			this->Code->MinimumWidth = 6;
			this->Code->Name = L"Code";
			this->Code->ReadOnly = true;
			this->Code->Visible = false;
			this->Code->Width = 125;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->DeletePB);
			this->groupBox1->Controls->Add(this->UpdatePB);
			this->groupBox1->Controls->Add(this->AddPB);
			this->groupBox1->Location = System::Drawing::Point(1334, 61);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(165, 58);
			this->groupBox1->TabIndex = 4;
			this->groupBox1->TabStop = false;
			// 
			// DeletePB
			// 
			this->DeletePB->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"DeletePB.Image")));
			this->DeletePB->Location = System::Drawing::Point(120, 11);
			this->DeletePB->Name = L"DeletePB";
			this->DeletePB->Size = System::Drawing::Size(38, 37);
			this->DeletePB->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->DeletePB->TabIndex = 2;
			this->DeletePB->TabStop = false;
			this->DeletePB->Click += gcnew System::EventHandler(this, &MyForm1::Delete_Click);
			this->DeletePB->MouseEnter += gcnew System::EventHandler(this, &MyForm1::DeletePB_MouseEnter);
			this->DeletePB->MouseLeave += gcnew System::EventHandler(this, &MyForm1::DeletePB_MouseLeave);
			// 
			// UpdatePB
			// 
			this->UpdatePB->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"UpdatePB.Image")));
			this->UpdatePB->Location = System::Drawing::Point(6, 11);
			this->UpdatePB->Name = L"UpdatePB";
			this->UpdatePB->Size = System::Drawing::Size(37, 37);
			this->UpdatePB->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->UpdatePB->TabIndex = 1;
			this->UpdatePB->TabStop = false;
			this->UpdatePB->Click += gcnew System::EventHandler(this, &MyForm1::Update_Click);
			this->UpdatePB->MouseEnter += gcnew System::EventHandler(this, &MyForm1::UpdatePB_MouseEnter);
			this->UpdatePB->MouseLeave += gcnew System::EventHandler(this, &MyForm1::UpdatePB_MouseLeave);
			// 
			// AddPB
			// 
			this->AddPB->BackColor = System::Drawing::Color::Olive;
			this->AddPB->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"AddPB.Image")));
			this->AddPB->Location = System::Drawing::Point(62, 11);
			this->AddPB->Name = L"AddPB";
			this->AddPB->Size = System::Drawing::Size(38, 37);
			this->AddPB->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->AddPB->TabIndex = 0;
			this->AddPB->TabStop = false;
			this->AddPB->Click += gcnew System::EventHandler(this, &MyForm1::Add_Click);
			this->AddPB->MouseEnter += gcnew System::EventHandler(this, &MyForm1::AddPB_MouseEnter);
			this->AddPB->MouseLeave += gcnew System::EventHandler(this, &MyForm1::AddPB_MouseLeave);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 28.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::Color::Khaki;
			this->label2->Location = System::Drawing::Point(689, 34);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(450, 55);
			this->label2->TabIndex = 7;
			this->label2->Text = L"TOP OF PLAYERS";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label1);
			this->groupBox2->Controls->Add(this->picture2048Game);
			this->groupBox2->Controls->Add(this->pictureSnake);
			this->groupBox2->Controls->Add(this->pictureTetris);
			this->groupBox2->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->groupBox2->Location = System::Drawing::Point(37, 154);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(346, 551);
			this->groupBox2->TabIndex = 8;
			this->groupBox2->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 25.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::Khaki;
			this->label1->Location = System::Drawing::Point(97, 32);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(149, 49);
			this->label1->TabIndex = 10;
			this->label1->Text = L"Games";
			// 
			// picture2048Game
			// 
			this->picture2048Game->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picture2048Game.Image")));
			this->picture2048Game->Location = System::Drawing::Point(55, 401);
			this->picture2048Game->Name = L"picture2048Game";
			this->picture2048Game->Size = System::Drawing::Size(241, 99);
			this->picture2048Game->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picture2048Game->TabIndex = 11;
			this->picture2048Game->TabStop = false;
			this->picture2048Game->Click += gcnew System::EventHandler(this, &MyForm1::picture2048Game_Click);
			this->picture2048Game->MouseEnter += gcnew System::EventHandler(this, &MyForm1::picture2048Game_MouseEnter);
			this->picture2048Game->MouseLeave += gcnew System::EventHandler(this, &MyForm1::picture2048Game_MouseLeave);
			// 
			// pictureSnake
			// 
			this->pictureSnake->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureSnake.Image")));
			this->pictureSnake->Location = System::Drawing::Point(53, 254);
			this->pictureSnake->Name = L"pictureSnake";
			this->pictureSnake->Size = System::Drawing::Size(243, 102);
			this->pictureSnake->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureSnake->TabIndex = 10;
			this->pictureSnake->TabStop = false;
			this->pictureSnake->Click += gcnew System::EventHandler(this, &MyForm1::pictureSnake_Click);
			this->pictureSnake->MouseEnter += gcnew System::EventHandler(this, &MyForm1::pictureSnake_MouseEnter);
			this->pictureSnake->MouseLeave += gcnew System::EventHandler(this, &MyForm1::pictureSnake_MouseLeave);
			// 
			// pictureTetris
			// 
			this->pictureTetris->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureTetris.Image")));
			this->pictureTetris->Location = System::Drawing::Point(53, 108);
			this->pictureTetris->Name = L"pictureTetris";
			this->pictureTetris->Size = System::Drawing::Size(243, 101);
			this->pictureTetris->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureTetris->TabIndex = 9;
			this->pictureTetris->TabStop = false;
			this->pictureTetris->Click += gcnew System::EventHandler(this, &MyForm1::pictureTetris_Click);
			this->pictureTetris->MouseEnter += gcnew System::EventHandler(this, &MyForm1::pictureTetris_MouseEnter);
			this->pictureTetris->MouseLeave += gcnew System::EventHandler(this, &MyForm1::pictureTetris_MouseLeave);
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Olive;
			this->ClientSize = System::Drawing::Size(1648, 833);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->PlayersData);
			this->Name = L"MyForm1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Menu";
			this->Load += gcnew System::EventHandler(this, &MyForm1::MyForm1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PlayersData))->EndInit();
			this->groupBox1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DeletePB))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->UpdatePB))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AddPB))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picture2048Game))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureSnake))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureTetris))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: Bitmap^ com2048 = gcnew Bitmap("C:\\Users\\Abere\\source\\repos\\Project4\\images\\2048.jpg");
		private: Bitmap^ tetriscom = gcnew Bitmap("C:\\Users\\Abere\\source\\repos\\Project4\\images\\tet.png");
		private: Bitmap^ snakecom = gcnew Bitmap("C:\\Users\\Abere\\source\\repos\\Project4\\images\\snake.png");
		private: Bitmap^ font2048 = gcnew Bitmap("C:\\Users\\Abere\\source\\repos\\Project4\\images\\2048font.jpg"); 
		private: Bitmap ^ tetrisfont = gcnew Bitmap("C:\\Users\\Abere\\source\\repos\\Project4\\images\\tetfont.png");
		private: Bitmap ^ snakefont = gcnew Bitmap("C:\\Users\\Abere\\source\\repos\\Project4\\images\\snakefont.png");
	    private: Bitmap^ ad = gcnew Bitmap("C:\\Users\\Abere\\source\\repos\\Project4\\images\\add.png");
		private: Bitmap^ del = gcnew Bitmap("C:\\Users\\Abere\\source\\repos\\Project4\\images\\delet.png");
		private: Bitmap^ up = gcnew Bitmap("C:\\Users\\Abere\\source\\repos\\Project4\\images\\upd.png");
		private: Bitmap^ add = gcnew Bitmap("C:\\Users\\Abere\\source\\repos\\Project4\\images\\ad.png");
		private: Bitmap^ delet = gcnew Bitmap("C:\\Users\\Abere\\source\\repos\\Project4\\images\\del.png");
		private: Bitmap^ upd = gcnew Bitmap("C:\\Users\\Abere\\source\\repos\\Project4\\images\\update.png");
	public: int ValNeed;	
	private: System::Void Add_Click(System::Object^ sender, System::EventArgs^ e);	
	private: System::Void Delete_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void Update_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void MyForm1_Load(System::Object^ sender, System::EventArgs^ e);
	public: void ReadData(bool beginFlag);
    public: int Koef;
	public: void AddDataView(String^ fname, String^ fsurname);
	public: void DeleteDataView(String^ fname, String^ fsurname);
    private: void Update(int whereNum, int setNum);

	public: bool FindExistPlayer(String^ fname, String^ fsurname);

	private: void UpdateLiderBoard();
	private: void UpdateAllData();
    private: void startGame(int game);

	private: System::Void pictureTetris_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void pictureSnake_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void picture2048Game_Click(System::Object^ sender, System::EventArgs^ e);

    private: System::Void pictureTetris_MouseEnter(System::Object^ sender, System::EventArgs^ e);

	private: System::Void pictureSnake_MouseEnter(System::Object^ sender, System::EventArgs^ e);

	private: System::Void picture2048Game_MouseEnter(System::Object^ sender, System::EventArgs^ e);

private: System::Void picture2048Game_MouseLeave(System::Object^ sender, System::EventArgs^ e);
private: System::Void pictureTetris_MouseLeave(System::Object^ sender, System::EventArgs^ e);
private: System::Void pictureSnake_MouseLeave(System::Object^ sender, System::EventArgs^ e);
private: System::Void AddPB_MouseEnter(System::Object^ sender, System::EventArgs^ e);
private: System::Void AddPB_MouseLeave(System::Object^ sender, System::EventArgs^ e);
private: System::Void UpdatePB_MouseEnter(System::Object^ sender, System::EventArgs^ e);
private: System::Void UpdatePB_MouseLeave(System::Object^ sender, System::EventArgs^ e);
private: System::Void DeletePB_MouseEnter(System::Object^ sender, System::EventArgs^ e);
private: System::Void DeletePB_MouseLeave(System::Object^ sender, System::EventArgs^ e);
};
}
