#pragma once
#include "Juego.h"
using namespace TicTacTOe;
namespace InicioJuegoTicTacToe {

	//Variables Globales
	bool NombresIntroducidos;
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnSalir;
	protected:

	private: System::Windows::Forms::Button^ btnJugar;



	protected:


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ txtNom2;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ txtNom1;
	private: System::Windows::Forms::Label^ labelLlenarNombres;




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnSalir = (gcnew System::Windows::Forms::Button());
			this->btnJugar = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->txtNom2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txtNom1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->labelLlenarNombres = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnSalir
			// 
			this->btnSalir->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->btnSalir->Font = (gcnew System::Drawing::Font(L"Calibri", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSalir->ForeColor = System::Drawing::Color::Black;
			this->btnSalir->Location = System::Drawing::Point(358, 251);
			this->btnSalir->Name = L"btnSalir";
			this->btnSalir->Size = System::Drawing::Size(98, 46);
			this->btnSalir->TabIndex = 7;
			this->btnSalir->Text = L"Salir";
			this->btnSalir->UseVisualStyleBackColor = false;
			this->btnSalir->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// btnJugar
			// 
			this->btnJugar->BackColor = System::Drawing::Color::PaleGreen;
			this->btnJugar->Font = (gcnew System::Drawing::Font(L"Calibri", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnJugar->Location = System::Drawing::Point(358, 173);
			this->btnJugar->Name = L"btnJugar";
			this->btnJugar->Size = System::Drawing::Size(98, 46);
			this->btnJugar->TabIndex = 5;
			this->btnJugar->Text = L"Jugar";
			this->btnJugar->UseVisualStyleBackColor = false;
			this->btnJugar->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::WhiteSmoke;
			this->label1->Font = (gcnew System::Drawing::Font(L"Calibri", 48, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(100, 36);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(314, 78);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Tic Tac Toe";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->txtNom2);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->txtNom1);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(12, 153);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(277, 162);
			this->groupBox1->TabIndex = 8;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Ingresar Nombres de Jugadores";
			// 
			// txtNom2
			// 
			this->txtNom2->Location = System::Drawing::Point(9, 124);
			this->txtNom2->Name = L"txtNom2";
			this->txtNom2->Size = System::Drawing::Size(253, 20);
			this->txtNom2->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Calibri", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			this->label3->Location = System::Drawing::Point(9, 95);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(255, 19);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Ingrese el Nombre del Jugador 2 (O): ";
			// 
			// txtNom1
			// 
			this->txtNom1->Location = System::Drawing::Point(6, 49);
			this->txtNom1->Name = L"txtNom1";
			this->txtNom1->Size = System::Drawing::Size(253, 20);
			this->txtNom1->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Calibri", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			this->label2->Location = System::Drawing::Point(6, 20);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(253, 19);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Ingrese el Nombre del Jugador 1 (X): ";
			// 
			// labelLlenarNombres
			// 
			this->labelLlenarNombres->AutoSize = true;
			this->labelLlenarNombres->Font = (gcnew System::Drawing::Font(L"Calibri", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			this->labelLlenarNombres->ForeColor = System::Drawing::Color::Red;
			this->labelLlenarNombres->Location = System::Drawing::Point(21, 131);
			this->labelLlenarNombres->Name = L"labelLlenarNombres";
			this->labelLlenarNombres->Size = System::Drawing::Size(281, 19);
			this->labelLlenarNombres->TabIndex = 4;
			this->labelLlenarNombres->Text = L"!!!!Rellene los Campos de los Nombres!!!!";
			this->labelLlenarNombres->Visible = false;
			this->labelLlenarNombres->Click += gcnew System::EventHandler(this, &MyForm::label4_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::WhiteSmoke;
			this->ClientSize = System::Drawing::Size(545, 343);
			this->Controls->Add(this->labelLlenarNombres);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->btnSalir);
			this->Controls->Add(this->btnJugar);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"Inicio";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	//BTN JUGAR
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (txtNom1->Text != "" && txtNom1->Text != nullptr && txtNom2->Text != "" && txtNom2->Text != nullptr) {
			this->Visible = false;
			FormJuego formq;
			formq.labelNom1->Text = txtNom1->Text;
			formq.labelNom2->Text = txtNom2->Text;
			formq.ShowDialog();
			this->Visible = true;
			delete(%formq);
		}
		else {
			labelLlenarNombres->Visible = true;
		}
	}
	//BTN SALIR
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {

		this->Close();
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
