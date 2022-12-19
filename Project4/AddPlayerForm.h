#pragma once
#include "MyForm1.h"
namespace Project4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ AddPlayerForm
	/// </summary>
	public ref class AddPlayerForm : public System::Windows::Forms::Form
	{
	public:
		AddPlayerForm(MyForm1^ parent)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			parentform = parent;
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~AddPlayerForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ PName;
	private: System::Windows::Forms::TextBox^ PSurname;

	private: System::Windows::Forms::Button^ AddPlayerButton;
	private: System::Windows::Forms::Label^ PlayerName;
	private: System::Windows::Forms::Label^ PlayerSurname;
	protected:

	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;
		MyForm1^ parentform;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->PName = (gcnew System::Windows::Forms::TextBox());
			this->PSurname = (gcnew System::Windows::Forms::TextBox());
			this->AddPlayerButton = (gcnew System::Windows::Forms::Button());
			this->PlayerName = (gcnew System::Windows::Forms::Label());
			this->PlayerSurname = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// PName
			// 
			this->PName->Location = System::Drawing::Point(155, 61);
			this->PName->Name = L"PName";
			this->PName->Size = System::Drawing::Size(144, 22);
			this->PName->TabIndex = 0;
			// 
			// PSurname
			// 
			this->PSurname->Location = System::Drawing::Point(155, 130);
			this->PSurname->Name = L"PSurname";
			this->PSurname->Size = System::Drawing::Size(144, 22);
			this->PSurname->TabIndex = 1;
			// 
			// AddPlayerButton
			// 
			this->AddPlayerButton->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->AddPlayerButton->Location = System::Drawing::Point(135, 188);
			this->AddPlayerButton->Name = L"AddPlayerButton";
			this->AddPlayerButton->Size = System::Drawing::Size(184, 34);
			this->AddPlayerButton->TabIndex = 2;
			this->AddPlayerButton->Text = L"Add Player";
			this->AddPlayerButton->UseVisualStyleBackColor = true;
			this->AddPlayerButton->Click += gcnew System::EventHandler(this, &AddPlayerForm::AddPlayerButton_Click);
			// 
			// PlayerName
			// 
			this->PlayerName->AutoSize = true;
			this->PlayerName->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->PlayerName->Location = System::Drawing::Point(173, 35);
			this->PlayerName->Name = L"PlayerName";
			this->PlayerName->Size = System::Drawing::Size(111, 23);
			this->PlayerName->TabIndex = 3;
			this->PlayerName->Text = L"Input name:";
			// 
			// PlayerSurname
			// 
			this->PlayerSurname->AutoSize = true;
			this->PlayerSurname->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->PlayerSurname->Location = System::Drawing::Point(162, 104);
			this->PlayerSurname->Name = L"PlayerSurname";
			this->PlayerSurname->Size = System::Drawing::Size(137, 23);
			this->PlayerSurname->TabIndex = 4;
			this->PlayerSurname->Text = L"Input surname:";
			// 
			// AddPlayerForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Khaki;
			this->ClientSize = System::Drawing::Size(473, 253);
			this->Controls->Add(this->PlayerSurname);
			this->Controls->Add(this->PlayerName);
			this->Controls->Add(this->AddPlayerButton);
			this->Controls->Add(this->PSurname);
			this->Controls->Add(this->PName);
			this->Name = L"AddPlayerForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Player";
			this->Load += gcnew System::EventHandler(this, &AddPlayerForm::AddPlayerForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void AddPlayerButton_Click(System::Object^ sender, System::EventArgs^ e) {
		if (PName->Text != "" && PSurname->Text != "") {
			if (parentform->Koef == 1) parentform->AddDataView(PName->Text, PSurname->Text);
			else if (parentform->Koef == 2) parentform->DeleteDataView(PName->Text, PSurname->Text);
		}
	}

	private: System::Void AddPlayerForm_Load(System::Object^ sender, System::EventArgs^ e) {
		if (parentform->Koef == 1) {
			AddPlayerButton->Text = "Add Player";
		}
		else if (parentform->Koef == 2) AddPlayerButton->Text = "Delete Player";
	}
};
}
