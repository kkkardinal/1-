#include "pch.h"

#include <Windows.h>
#include "MyClass.h"


#pragma once


namespace Lab3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class WinForm : public System::Windows::Forms::Form {
	public:
		WinForm(void)
		{
			InitializeComponent();
		}

		~WinForm()
		{
			if (components)
			{
				delete components;
			}
		}
	
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ справкаToolStripMenuItem;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ button_delete;
	private: System::Windows::Forms::Button^ button_update;
	private: System::Windows::Forms::Button^ button_add;
	private: System::Windows::Forms::Button^ button_exit;
	private: System::Windows::Forms::Button^ button_download;










	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Номер;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ searchWord;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ words_sites;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dayStart;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ monthStart;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dayEnd;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ monthEnd;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ numberInt;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ numberSix;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ numberFloat;











	private: MyClass Currency;
	

#pragma region Windows Form Designer generated code

		   void InitializeComponent(void)
		   {
			   this->button_exit = (gcnew System::Windows::Forms::Button());
			   this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			   this->справкаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			   this->Номер = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->searchWord = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->words_sites = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->dayStart = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->monthStart = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->dayEnd = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->monthEnd = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->numberInt = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->numberSix = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->numberFloat = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			   this->button_delete = (gcnew System::Windows::Forms::Button());
			   this->button_update = (gcnew System::Windows::Forms::Button());
			   this->button_add = (gcnew System::Windows::Forms::Button());
			   this->button_download = (gcnew System::Windows::Forms::Button());
			   this->menuStrip1->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			   this->groupBox1->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // button_exit
			   // 
			   this->button_exit->Location = System::Drawing::Point(261, 226);
			   this->button_exit->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			   this->button_exit->Name = L"button_exit";
			   this->button_exit->Size = System::Drawing::Size(115, 32);
			   this->button_exit->TabIndex = 1;
			   this->button_exit->Text = L"Выйти";
			   this->button_exit->UseVisualStyleBackColor = true;
			   this->button_exit->Click += gcnew System::EventHandler(this, &WinForm::Button_Exit);
			   // 
			   // menuStrip1
			   // 
			   this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			   this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->справкаToolStripMenuItem });
			   this->menuStrip1->Location = System::Drawing::Point(0, 0);
			   this->menuStrip1->Name = L"menuStrip1";
			   this->menuStrip1->Padding = System::Windows::Forms::Padding(5, 1, 0, 1);
			   this->menuStrip1->Size = System::Drawing::Size(948, 24);
			   this->menuStrip1->TabIndex = 2;
			   this->menuStrip1->Text = L"menuStrip1";
			   // 
			   // справкаToolStripMenuItem
			   // 
			   this->справкаToolStripMenuItem->BackColor = System::Drawing::SystemColors::Control;
			   this->справкаToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			   this->справкаToolStripMenuItem->ForeColor = System::Drawing::SystemColors::ControlText;
			   this->справкаToolStripMenuItem->Name = L"справкаToolStripMenuItem";
			   this->справкаToolStripMenuItem->Size = System::Drawing::Size(94, 22);
			   this->справкаToolStripMenuItem->Text = L"О программе";
			   this->справкаToolStripMenuItem->Click += gcnew System::EventHandler(this, &WinForm::СправкаToolStripMenuItem_Click_1);
			   // 
			   // dataGridView1
			   // 
			   this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			   this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(10) {
				   this->Номер,
					   this->searchWord, this->words_sites, this->dayStart, this->monthStart, this->dayEnd, this->monthEnd, this->numberInt, this->numberSix,
					   this->numberFloat
			   });
			   this->dataGridView1->Location = System::Drawing::Point(9, 25);
			   this->dataGridView1->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			   this->dataGridView1->Name = L"dataGridView1";
			   this->dataGridView1->RowHeadersWidth = 51;
			   this->dataGridView1->RowTemplate->Height = 24;
			   this->dataGridView1->Size = System::Drawing::Size(814, 191);
			   this->dataGridView1->TabIndex = 3;
			   this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &WinForm::dataGridView1_CellContentClick);
			   // 
			   // Номер
			   // 
			   this->Номер->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			   this->Номер->FillWeight = 40;
			   this->Номер->HeaderText = L"¹";
			   this->Номер->MinimumWidth = 6;
			   this->Номер->Name = L"Номер";
			   this->Номер->Width = 30;
			   // 
			   // searchWord
			   // 
			   this->searchWord->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			   this->searchWord->FillWeight = 70;
			   this->searchWord->HeaderText = L"Слово";
			   this->searchWord->MinimumWidth = 6;
			   this->searchWord->Name = L"searchWord";
			   this->searchWord->Width = 70;
			   // 
			   // words_sites
			   // 
			   this->words_sites->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			   this->words_sites->FillWeight = 200;
			   this->words_sites->HeaderText = L"Сайт";
			   this->words_sites->MinimumWidth = 6;
			   this->words_sites->Name = L"words_sites";
			   this->words_sites->Width = 200;
			   // 
			   // dayStart
			   // 
			   this->dayStart->FillWeight = 70;
			   this->dayStart->HeaderText = L"День (начало)";
			   this->dayStart->MaxInputLength = 2;
			   this->dayStart->MinimumWidth = 8;
			   this->dayStart->Name = L"dayStart";
			   this->dayStart->Width = 150;
			   // 
			   // monthStart
			   // 
			   this->monthStart->FillWeight = 70;
			   this->monthStart->HeaderText = L"Месяц (начало)";
			   this->monthStart->MaxInputLength = 10;
			   this->monthStart->MinimumWidth = 8;
			   this->monthStart->Name = L"monthStart";
			   this->monthStart->Width = 150;
			   // 
			   // dayEnd
			   // 
			   this->dayEnd->FillWeight = 70;
			   this->dayEnd->HeaderText = L"День (конец)";
			   this->dayEnd->MaxInputLength = 2;
			   this->dayEnd->MinimumWidth = 8;
			   this->dayEnd->Name = L"dayEnd";
			   this->dayEnd->Width = 150;
			   // 
			   // monthEnd
			   // 
			   this->monthEnd->FillWeight = 70;
			   this->monthEnd->HeaderText = L"Месяц (конец)";
			   this->monthEnd->MaxInputLength = 10;
			   this->monthEnd->MinimumWidth = 8;
			   this->monthEnd->Name = L"monthEnd";
			   this->monthEnd->Width = 150;
			   // 
			   // numberInt
			   // 
			   this->numberInt->HeaderText = L"число";
			   this->numberInt->MinimumWidth = 8;
			   this->numberInt->Name = L"numberInt";
			   this->numberInt->Width = 40;
			   // 
			   // numberSix
			   // 
			   this->numberSix->HeaderText = L"16-чное число";
			   this->numberSix->MinimumWidth = 8;
			   this->numberSix->Name = L"numberSix";
			   this->numberSix->Width = 40;
			   // 
			   // numberFloat
			   // 
			   this->numberFloat->HeaderText = L"дробное";
			   this->numberFloat->MinimumWidth = 8;
			   this->numberFloat->Name = L"numberFloat";
			   this->numberFloat->Width = 40;
			   // 
			   // groupBox1
			   // 
			   this->groupBox1->Controls->Add(this->button_delete);
			   this->groupBox1->Controls->Add(this->button_update);
			   this->groupBox1->Controls->Add(this->button_add);
			   this->groupBox1->Controls->Add(this->button_download);
			   this->groupBox1->Location = System::Drawing::Point(817, 24);
			   this->groupBox1->Margin = System::Windows::Forms::Padding(0);
			   this->groupBox1->Name = L"groupBox1";
			   this->groupBox1->Padding = System::Windows::Forms::Padding(2, 3, 2, 3);
			   this->groupBox1->Size = System::Drawing::Size(122, 191);
			   this->groupBox1->TabIndex = 4;
			   this->groupBox1->TabStop = false;
			   this->groupBox1->Enter += gcnew System::EventHandler(this, &WinForm::groupBox1_Enter);
			   // 
			   // button_delete
			   // 
			   this->button_delete->Location = System::Drawing::Point(43, 146);
			   this->button_delete->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			   this->button_delete->Name = L"button_delete";
			   this->button_delete->Size = System::Drawing::Size(71, 32);
			   this->button_delete->TabIndex = 3;
			   this->button_delete->Text = L"Удалить";
			   this->button_delete->UseVisualStyleBackColor = true;
			   this->button_delete->Click += gcnew System::EventHandler(this, &WinForm::Button_delete);
			   // 
			   // button_update
			   // 
			   this->button_update->Location = System::Drawing::Point(43, 103);
			   this->button_update->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			   this->button_update->Name = L"button_update";
			   this->button_update->Size = System::Drawing::Size(71, 32);
			   this->button_update->TabIndex = 2;
			   this->button_update->Text = L"Изменить";
			   this->button_update->UseVisualStyleBackColor = true;
			   this->button_update->Click += gcnew System::EventHandler(this, &WinForm::Button_update);
			   // 
			   // button_add
			   // 
			   this->button_add->Location = System::Drawing::Point(43, 65);
			   this->button_add->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			   this->button_add->Name = L"button_add";
			   this->button_add->Size = System::Drawing::Size(71, 32);
			   this->button_add->TabIndex = 1;
			   this->button_add->Text = L"Добавить";
			   this->button_add->UseVisualStyleBackColor = true;
			   this->button_add->Click += gcnew System::EventHandler(this, &WinForm::Button_add);
			   // 
			   // button_download
			   // 
			   this->button_download->Location = System::Drawing::Point(43, 17);
			   this->button_download->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			   this->button_download->Name = L"button_download";
			   this->button_download->Size = System::Drawing::Size(71, 42);
			   this->button_download->TabIndex = 0;
			   this->button_download->Text = L"Загрузить данные";
			   this->button_download->UseVisualStyleBackColor = true;
			   this->button_download->Click += gcnew System::EventHandler(this, &WinForm::Button_download);
			   // 
			   // WinForm
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(948, 266);
			   this->Controls->Add(this->groupBox1);
			   this->Controls->Add(this->dataGridView1);
			   this->Controls->Add(this->button_exit);
			   this->Controls->Add(this->menuStrip1);
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			   this->MainMenuStrip = this->menuStrip1;
			   this->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			   this->MaximizeBox = false;
			   this->Name = L"WinForm";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"Лаб. работа №3";
			   this->menuStrip1->ResumeLayout(false);
			   this->menuStrip1->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			   this->groupBox1->ResumeLayout(false);
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion
	private: System::Void Button_Exit(System::Object^ sender, System::EventArgs^ e);
	private: System::Void СправкаToolStripMenuItem_Click_1(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Button_download(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Button_add(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Button_update(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Button_delete(System::Object^ sender, System::EventArgs^ e);
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
private: System::Void groupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
}
};
}