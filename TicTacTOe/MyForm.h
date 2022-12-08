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
			this->picboxEquis1 ->Image= Image::FromFile("C:\\Users\\Gateway\\Downloads\\ImagenesTicTacToe\\ImagenesTicTacToe\\equiscasillas.jpg");
			this->picboxCirculo2->Image= Image::FromFile("C:\\Users\\Gateway\\Downloads\\ImagenesTicTacToe\\ImagenesTicTacToe\\circulocasilla.jpg");
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
	public: System::Windows::Forms::GroupBox^ groupBox1;
	private:

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ txtNom2;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ txtNom1;
	private: System::Windows::Forms::Label^ labelLlenarNombres;
	private: System::Windows::Forms::PictureBox^ picboxEquis1;
	private: System::Windows::Forms::PictureBox^ picboxCirculo2;






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
			this->picboxEquis1 = (gcnew System::Windows::Forms::PictureBox());
			this->picboxCirculo2 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picboxEquis1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picboxCirculo2))->BeginInit();
			this->SuspendLayout();
			// 
			// btnSalir
			// 
			this->btnSalir->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->btnSalir->Font = (gcnew System::Drawing::Font(L"Calibri", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSalir->ForeColor = System::Drawing::Color::Black;
			this->btnSalir->Location = System::Drawing::Point(530, 290);
			this->btnSalir->Margin = System::Windows::Forms::Padding(4);
			this->btnSalir->Name = L"btnSalir";
			this->btnSalir->Size = System::Drawing::Size(131, 57);
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
			this->btnJugar->Location = System::Drawing::Point(530, 194);
			this->btnJugar->Margin = System::Windows::Forms::Padding(4);
			this->btnJugar->Name = L"btnJugar";
			this->btnJugar->Size = System::Drawing::Size(131, 57);
			this->btnJugar->TabIndex = 5;
			this->btnJugar->Text = L"Jugar";
			this->btnJugar->UseVisualStyleBackColor = false;
			this->btnJugar->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::WhiteSmoke;
			this->label1->Font = (gcnew System::Drawing::Font(L"Calibri", 45, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(164, 20);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(369, 91);
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
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(69, 161);
			this->groupBox1->Margin = System::Windows::Forms::Padding(4);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(4);
			this->groupBox1->Size = System::Drawing::Size(423, 226);
			this->groupBox1->TabIndex = 8;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Ingrese los nombres de los jugadores";
			// 
			// txtNom2
			// 
			this->txtNom2->Location = System::Drawing::Point(43, 174);
			this->txtNom2->Margin = System::Windows::Forms::Padding(4);
			this->txtNom2->MaxLength = 15;
			this->txtNom2->Name = L"txtNom2";
			this->txtNom2->Size = System::Drawing::Size(336, 32);
			this->txtNom2->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Calibri", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			this->label3->Location = System::Drawing::Point(44, 132);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(135, 24);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Jugador 2 (O): ";
			// 
			// txtNom1
			// 
			this->txtNom1->Location = System::Drawing::Point(43, 74);
			this->txtNom1->Margin = System::Windows::Forms::Padding(4);
			this->txtNom1->MaxLength = 15;
			this->txtNom1->Name = L"txtNom1";
			this->txtNom1->Size = System::Drawing::Size(336, 32);
			this->txtNom1->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Calibri", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			this->label2->Location = System::Drawing::Point(46, 33);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(133, 24);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Jugador 1 (X): ";
			// 
			// labelLlenarNombres
			// 
			this->labelLlenarNombres->AutoSize = true;
			this->labelLlenarNombres->Font = (gcnew System::Drawing::Font(L"Calibri", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			this->labelLlenarNombres->ForeColor = System::Drawing::Color::Red;
			this->labelLlenarNombres->Location = System::Drawing::Point(91, 122);
			this->labelLlenarNombres->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelLlenarNombres->Name = L"labelLlenarNombres";
			this->labelLlenarNombres->Size = System::Drawing::Size(378, 24);
			this->labelLlenarNombres->TabIndex = 4;
			this->labelLlenarNombres->Text = L"Rellene todos los campos para poder jugar.";
			this->labelLlenarNombres->Visible = false;
			this->labelLlenarNombres->Click += gcnew System::EventHandler(this, &MyForm::label4_Click);
			// 
			// picboxEquis1
			// 
			this->picboxEquis1->Location = System::Drawing::Point(71, 38);
			this->picboxEquis1->Name = L"picboxEquis1";
			this->picboxEquis1->Size = System::Drawing::Size(100, 50);
			this->picboxEquis1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->picboxEquis1->TabIndex = 9;
			this->picboxEquis1->TabStop = false;
			// 
			// picboxCirculo2
			// 
			this->picboxCirculo2->Location = System::Drawing::Point(569, 38);
			this->picboxCirculo2->Name = L"picboxCirculo2";
			this->picboxCirculo2->Size = System::Drawing::Size(100, 50);
			this->picboxCirculo2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->picboxCirculo2->TabIndex = 10;
			this->picboxCirculo2->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::WhiteSmoke;
			this->ClientSize = System::Drawing::Size(727, 422);
			this->Controls->Add(this->picboxCirculo2);
			this->Controls->Add(this->picboxEquis1);
			this->Controls->Add(this->labelLlenarNombres);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->btnSalir);
			this->Controls->Add(this->btnJugar);
			this->Controls->Add(this->label1);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm";
			this->Text = L"Inicio";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picboxEquis1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picboxCirculo2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	//BTN JUGAR
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (txtNom1->Text != " " && txtNom1->Text != nullptr && txtNom2->Text != " " && txtNom2->Text != nullptr && txtNom1->Text != txtNom2->Text) {
			this->Visible = false;
			FormJuego formq;
			formq.labelNom1->Text = txtNom1->Text;
			formq.labelNom2->Text = txtNom2->Text;
			formq.ShowDialog();
			this->Visible = true;
			delete(%formq);
			txtNom1->Text = nullptr;
			txtNom2->Text = nullptr;
			labelLlenarNombres->Visible = false;
		}
		else if (txtNom1->Text != "" && txtNom1->Text != nullptr && txtNom2->Text != "" && txtNom2->Text != nullptr && txtNom1->Text == txtNom2->Text)
		{
			labelLlenarNombres->Text = "Los nombres no pueden ser iguales, coloque una distinción.";
			labelLlenarNombres->Visible = true;

		}else
		{
			labelLlenarNombres->Text = "Rellene todos los campos para poder jugar.";
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
