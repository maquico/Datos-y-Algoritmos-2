/*
* ENUNCIADO: TAREA 2. TIC TAC TOE
* ASUNTO: Haga un programa C++ que permita que dos jugadores jueguen Tic-Tac-Toe.
*
AUTORES: ANGEL MORENO ID:1104666
*        GLEIDY ESPINAL ID:1104225
*        ALLEN SILVERIO ID:1104220
*        CRISTIAN JIM�NEZ ID:1106166
*        WILLIAM FERREIRA ID:1104228
* FECHA: 08/12/2022
*/

/*
Significado del Arreglo
- 0 cuando est� vac�o
- 1 cuando est� la letra del usuario
- -1 cunado est� la letra del bot
{  00 ,  01 ,  02 ,  10 ,  11 ,  12 ,  20 ,  21 ,  22 } -> Posiciones del Boton
{  0  ,  0  ,  0  ,  0  ,  0  ,  0  ,  0  ,  0  ,  0  } -> El Arreglo
*/

#pragma once
#include "iostream"
using namespace std;

namespace TicTacTOe {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	//Variables Globales
	int arregloTablero[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
	bool Juega0 = false;
	bool JuegaX = true;
	int jugadas = 0;
	int numpartidas = 0;
	bool partidaTerminada = false;
	bool esX = false;
	string simboloOponente;
	public ref class FormJuego : public System::Windows::Forms::Form
	{
	public:
		FormJuego(void)
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
		~FormJuego()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ PanelTablero;
	private: System::Windows::Forms::Button^ btn00;
	private:

	private: System::Windows::Forms::PictureBox^ picBoxEquis;
	public: System::Windows::Forms::Label^ labelNomX;
	public: System::Windows::Forms::Label^ labelNomO;
	private:


	private:

	private: System::Windows::Forms::PictureBox^ picBoxCirculo;
	public: System::Windows::Forms::Label^ label2;

	public:


	private: System::Windows::Forms::Button^ btn01;
	private: System::Windows::Forms::Button^ btn02;
	private: System::Windows::Forms::Button^ btn22;

	private: System::Windows::Forms::Button^ btn21;

	private: System::Windows::Forms::Button^ btn20;

	private: System::Windows::Forms::Button^ btn12;

	private: System::Windows::Forms::Button^ btn11;

	private: System::Windows::Forms::Button^ btn10;
	private: System::Windows::Forms::Label^ textoGanador;
	private: System::Windows::Forms::Button^ btnReiniciar;
	private: System::Windows::Forms::Button^ btnSalir;
	private: System::Windows::Forms::Label^ jugEmpieza;
	public: System::Windows::Forms::Label^ labelJugadorJugandp;
	private:

	private:


	public:


	public:

	public:


	protected:


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->PanelTablero = (gcnew System::Windows::Forms::Panel());
			this->btn22 = (gcnew System::Windows::Forms::Button());
			this->btn21 = (gcnew System::Windows::Forms::Button());
			this->btn20 = (gcnew System::Windows::Forms::Button());
			this->btn12 = (gcnew System::Windows::Forms::Button());
			this->btn11 = (gcnew System::Windows::Forms::Button());
			this->btn10 = (gcnew System::Windows::Forms::Button());
			this->btn02 = (gcnew System::Windows::Forms::Button());
			this->btn01 = (gcnew System::Windows::Forms::Button());
			this->btn00 = (gcnew System::Windows::Forms::Button());
			this->picBoxEquis = (gcnew System::Windows::Forms::PictureBox());
			this->labelNomX = (gcnew System::Windows::Forms::Label());
			this->labelNomO = (gcnew System::Windows::Forms::Label());
			this->picBoxCirculo = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textoGanador = (gcnew System::Windows::Forms::Label());
			this->btnReiniciar = (gcnew System::Windows::Forms::Button());
			this->btnSalir = (gcnew System::Windows::Forms::Button());
			this->jugEmpieza = (gcnew System::Windows::Forms::Label());
			this->labelJugadorJugandp = (gcnew System::Windows::Forms::Label());
			this->PanelTablero->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBoxEquis))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBoxCirculo))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Calibri", 48, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(82, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(314, 78);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Tic Tac Toe";
			// 
			// PanelTablero
			// 
			this->PanelTablero->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->PanelTablero->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->PanelTablero->Controls->Add(this->btn22);
			this->PanelTablero->Controls->Add(this->btn21);
			this->PanelTablero->Controls->Add(this->btn20);
			this->PanelTablero->Controls->Add(this->btn12);
			this->PanelTablero->Controls->Add(this->btn11);
			this->PanelTablero->Controls->Add(this->btn10);
			this->PanelTablero->Controls->Add(this->btn02);
			this->PanelTablero->Controls->Add(this->btn01);
			this->PanelTablero->Controls->Add(this->btn00);
			this->PanelTablero->Location = System::Drawing::Point(123, 108);
			this->PanelTablero->Name = L"PanelTablero";
			this->PanelTablero->Size = System::Drawing::Size(220, 220);
			this->PanelTablero->TabIndex = 6;
			this->PanelTablero->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FormJuego::PanelReina_Paint);
			// 
			// btn22
			// 
			this->btn22->BackColor = System::Drawing::Color::White;
			this->btn22->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->btn22->Location = System::Drawing::Point(146, 146);
			this->btn22->Name = L"btn22";
			this->btn22->Size = System::Drawing::Size(70, 70);
			this->btn22->TabIndex = 12;
			this->btn22->UseVisualStyleBackColor = false;
			this->btn22->Click += gcnew System::EventHandler(this, &FormJuego::button1_Click_1);
			// 
			// btn21
			// 
			this->btn21->BackColor = System::Drawing::Color::White;
			this->btn21->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->btn21->Location = System::Drawing::Point(73, 146);
			this->btn21->Name = L"btn21";
			this->btn21->Size = System::Drawing::Size(70, 70);
			this->btn21->TabIndex = 11;
			this->btn21->UseVisualStyleBackColor = false;
			this->btn21->Click += gcnew System::EventHandler(this, &FormJuego::button1_Click_1);
			// 
			// btn20
			// 
			this->btn20->BackColor = System::Drawing::Color::White;
			this->btn20->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->btn20->Location = System::Drawing::Point(0, 146);
			this->btn20->Name = L"btn20";
			this->btn20->Size = System::Drawing::Size(70, 70);
			this->btn20->TabIndex = 10;
			this->btn20->UseVisualStyleBackColor = false;
			this->btn20->Click += gcnew System::EventHandler(this, &FormJuego::button1_Click_1);
			// 
			// btn12
			// 
			this->btn12->BackColor = System::Drawing::Color::White;
			this->btn12->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->btn12->Location = System::Drawing::Point(146, 73);
			this->btn12->Name = L"btn12";
			this->btn12->Size = System::Drawing::Size(70, 70);
			this->btn12->TabIndex = 9;
			this->btn12->UseVisualStyleBackColor = false;
			this->btn12->Click += gcnew System::EventHandler(this, &FormJuego::button1_Click_1);
			// 
			// btn11
			// 
			this->btn11->BackColor = System::Drawing::Color::White;
			this->btn11->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->btn11->Location = System::Drawing::Point(73, 73);
			this->btn11->Name = L"btn11";
			this->btn11->Size = System::Drawing::Size(70, 70);
			this->btn11->TabIndex = 8;
			this->btn11->UseVisualStyleBackColor = false;
			this->btn11->Click += gcnew System::EventHandler(this, &FormJuego::button1_Click_1);
			// 
			// btn10
			// 
			this->btn10->BackColor = System::Drawing::Color::White;
			this->btn10->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->btn10->Location = System::Drawing::Point(0, 73);
			this->btn10->Name = L"btn10";
			this->btn10->Size = System::Drawing::Size(70, 70);
			this->btn10->TabIndex = 7;
			this->btn10->UseVisualStyleBackColor = false;
			this->btn10->Click += gcnew System::EventHandler(this, &FormJuego::button1_Click_1);
			// 
			// btn02
			// 
			this->btn02->BackColor = System::Drawing::Color::White;
			this->btn02->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->btn02->Location = System::Drawing::Point(146, 0);
			this->btn02->Name = L"btn02";
			this->btn02->Size = System::Drawing::Size(70, 70);
			this->btn02->TabIndex = 6;
			this->btn02->UseVisualStyleBackColor = false;
			this->btn02->Click += gcnew System::EventHandler(this, &FormJuego::button1_Click_1);
			// 
			// btn01
			// 
			this->btn01->BackColor = System::Drawing::Color::White;
			this->btn01->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->btn01->Location = System::Drawing::Point(73, 0);
			this->btn01->Name = L"btn01";
			this->btn01->Size = System::Drawing::Size(70, 70);
			this->btn01->TabIndex = 5;
			this->btn01->UseVisualStyleBackColor = false;
			this->btn01->Click += gcnew System::EventHandler(this, &FormJuego::button1_Click_1);
			// 
			// btn00
			// 
			this->btn00->BackColor = System::Drawing::Color::White;
			this->btn00->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->btn00->Location = System::Drawing::Point(0, 0);
			this->btn00->Name = L"btn00";
			this->btn00->Size = System::Drawing::Size(70, 70);
			this->btn00->TabIndex = 4;
			this->btn00->UseVisualStyleBackColor = false;
			this->btn00->Click += gcnew System::EventHandler(this, &FormJuego::button1_Click_1);
			// 
			// picBoxEquis
			// 
			this->picBoxEquis->Location = System::Drawing::Point(446, 119);
			this->picBoxEquis->Name = L"picBoxEquis";
			this->picBoxEquis->Size = System::Drawing::Size(113, 62);
			this->picBoxEquis->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->picBoxEquis->TabIndex = 7;
			this->picBoxEquis->TabStop = false;
			this->picBoxEquis->Click += gcnew System::EventHandler(this, &FormJuego::pictureBox1_Click);
			// 
			// labelNomX
			// 
			this->labelNomX->AutoSize = true;
			this->labelNomX->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelNomX->Location = System::Drawing::Point(424, 90);
			this->labelNomX->Name = L"labelNomX";
			this->labelNomX->Size = System::Drawing::Size(68, 27);
			this->labelNomX->TabIndex = 8;
			this->labelNomX->Text = L"label2";
			this->labelNomX->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->labelNomX->Click += gcnew System::EventHandler(this, &FormJuego::labelNom1_Click);
			// 
			// labelNomO
			// 
			this->labelNomO->AutoSize = true;
			this->labelNomO->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelNomO->Location = System::Drawing::Point(428, 247);
			this->labelNomO->Name = L"labelNomO";
			this->labelNomO->Size = System::Drawing::Size(68, 27);
			this->labelNomO->TabIndex = 9;
			this->labelNomO->Text = L"label3";
			this->labelNomO->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// picBoxCirculo
			// 
			this->picBoxCirculo->Location = System::Drawing::Point(446, 275);
			this->picBoxCirculo->Name = L"picBoxCirculo";
			this->picBoxCirculo->Size = System::Drawing::Size(113, 62);
			this->picBoxCirculo->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->picBoxCirculo->TabIndex = 10;
			this->picBoxCirculo->TabStop = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Black;
			this->label2->Location = System::Drawing::Point(439, 201);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(70, 42);
			this->label2->TabIndex = 11;
			this->label2->Text = L"VS";
			this->label2->Click += gcnew System::EventHandler(this, &FormJuego::label2_Click_1);
			// 
			// textoGanador
			// 
			this->textoGanador->AutoSize = true;
			this->textoGanador->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->textoGanador->ForeColor = System::Drawing::Color::LimeGreen;
			this->textoGanador->Location = System::Drawing::Point(110, 373);
			this->textoGanador->Name = L"textoGanador";
			this->textoGanador->Size = System::Drawing::Size(57, 20);
			this->textoGanador->TabIndex = 14;
			this->textoGanador->Text = L"label4";
			this->textoGanador->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->textoGanador->Visible = false;
			// 
			// btnReiniciar
			// 
			this->btnReiniciar->BackColor = System::Drawing::Color::PaleGreen;
			this->btnReiniciar->Enabled = false;
			this->btnReiniciar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnReiniciar->Location = System::Drawing::Point(420, 365);
			this->btnReiniciar->Name = L"btnReiniciar";
			this->btnReiniciar->Size = System::Drawing::Size(117, 33);
			this->btnReiniciar->TabIndex = 15;
			this->btnReiniciar->Text = L"Reiniciar";
			this->btnReiniciar->UseVisualStyleBackColor = false;
			this->btnReiniciar->Click += gcnew System::EventHandler(this, &FormJuego::btnReiniciar_Click);
			// 
			// btnSalir
			// 
			this->btnSalir->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->btnSalir->Enabled = false;
			this->btnSalir->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->btnSalir->Location = System::Drawing::Point(12, 369);
			this->btnSalir->Name = L"btnSalir";
			this->btnSalir->Size = System::Drawing::Size(85, 32);
			this->btnSalir->TabIndex = 16;
			this->btnSalir->Text = L"Salir";
			this->btnSalir->UseVisualStyleBackColor = false;
			this->btnSalir->Click += gcnew System::EventHandler(this, &FormJuego::btnSalir_Click);
			// 
			// jugEmpieza
			// 
			this->jugEmpieza->AutoSize = true;
			this->jugEmpieza->BackColor = System::Drawing::Color::Transparent;
			this->jugEmpieza->Font = (gcnew System::Drawing::Font(L"Calibri", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->jugEmpieza->ForeColor = System::Drawing::Color::Black;
			this->jugEmpieza->Location = System::Drawing::Point(410, 39);
			this->jugEmpieza->Name = L"jugEmpieza";
			this->jugEmpieza->Size = System::Drawing::Size(146, 33);
			this->jugEmpieza->TabIndex = 17;
			this->jugEmpieza->Text = L"Comienza X";
			// 
			// labelJugadorJugandp
			// 
			this->labelJugadorJugandp->AutoSize = true;
			this->labelJugadorJugandp->Font = (gcnew System::Drawing::Font(L"Calibri", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelJugadorJugandp->ForeColor = System::Drawing::Color::Blue;
			this->labelJugadorJugandp->Location = System::Drawing::Point(8, 90);
			this->labelJugadorJugandp->Name = L"labelJugadorJugandp";
			this->labelJugadorJugandp->Size = System::Drawing::Size(49, 19);
			this->labelJugadorJugandp->TabIndex = 18;
			this->labelJugadorJugandp->Text = L"label3";
			this->labelJugadorJugandp->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// FormJuego
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(601, 413);
			this->Controls->Add(this->labelJugadorJugandp);
			this->Controls->Add(this->jugEmpieza);
			this->Controls->Add(this->btnSalir);
			this->Controls->Add(this->btnReiniciar);
			this->Controls->Add(this->textoGanador);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->picBoxCirculo);
			this->Controls->Add(this->labelNomO);
			this->Controls->Add(this->labelNomX);
			this->Controls->Add(this->picBoxEquis);
			this->Controls->Add(this->PanelTablero);
			this->Controls->Add(this->label1);
			this->Name = L"FormJuego";
			this->Text = L"MyForm1";
			this->Load += gcnew System::EventHandler(this, &FormJuego::MyForm1_Load);
			this->Click += gcnew System::EventHandler(this, &FormJuego::FormJuego_Click);
			this->PanelTablero->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBoxEquis))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBoxCirculo))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public: System::Void MyForm1_Load(System::Object^ sender, System::EventArgs^ e) {
		this->picBoxEquis->Image = Image::FromFile("C:\\Users\\Chawillfer\\Desktop\\ImagenesTicTacToe\\equiscasillas.jpg");
		this->picBoxCirculo->Image = Image::FromFile("C:\\Users\\Chawillfer\\Desktop\\ImagenesTicTacToe\\circulocasilla.jpg");
		labelJugadorJugandp->Text = "Est� jugando " + labelNomX->Text;
		if (labelNomX->Text == "BOT") {
			esX = true;
			simboloOponente = "0";
			JugadaBot();
		}
		else { 
			esX = false; 
			simboloOponente = "X";
		}
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void labelNom1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void picBocVersus_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label2_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) { //Evento que sucede cada vez que se hace una jugada   

	Point posicionForm = this->Location; //Ubicacion del form en la pantalla
	Point posicionCliqueada = PanelTablero->MousePosition; //Donde el usuario hizo click

	posicionCliqueada.X = Convert::ToInt32((posicionCliqueada.X - 133 - posicionForm.X));
	posicionCliqueada.Y = Convert::ToInt32((posicionCliqueada.Y - 140 - posicionForm.Y));
	for each (Button ^ var in PanelTablero->Controls)
	{
		if (posicionCliqueada.X > var->Location.X && posicionCliqueada.X < (var->Location.X + 73) && posicionCliqueada.Y  > var->Location.Y && posicionCliqueada.Y < (var->Location.Y + 73) && jugadas < 9)
		{
			if (var->Tag == nullptr && !partidaTerminada) {
				ColocarTagImagen(var);
				if (jugadas >= 5) {
					//revisar si hay victoria
					if (RevisarDiagonales("X") || RevisarColumnas("X") || RevisarFilas("X"))
					{
						(numpartidas % 2 == 0) ? numpartidas += 0 : numpartidas++;
						partidaTerminada = true;
						JuegaX = false;
						Juega0 = false;
						labelNomX->ForeColor = Color::LimeGreen;
						textoGanador->ForeColor = Color::LimeGreen;
						textoGanador->Visible = true;
						textoGanador->Text = "���Felicidades " + labelNomX->Text + ", eres el ganador!!!";
						btnReiniciar->Enabled = true;
						btnSalir->Enabled = true;
					}
					else if (RevisarDiagonales("0") || RevisarColumnas("0") || RevisarFilas("0"))
					{
						(numpartidas % 2 == 0) ? numpartidas++ : numpartidas += 0;
						partidaTerminada = true;
						JuegaX = false;
						Juega0 = false;
						labelNomO->ForeColor = Color::LimeGreen;
						textoGanador->Visible = true;
						textoGanador->ForeColor = Color::LimeGreen;
						textoGanador->Text = "���Felicidades " + labelNomO->Text + ", eres el ganador!!!";
						btnReiniciar->Enabled = true;
						btnSalir->Enabled = true;
					}
					else if (jugadas == 9) {
						numpartidas++;
						partidaTerminada = true;
						btnReiniciar->Enabled = true;
						btnSalir->Enabled = true;
						textoGanador->Visible = true;
						textoGanador->ForeColor = Color::Red;
						textoGanador->Text = "���Son duros, se dio un empate!!!";
					}
				}
				
			}
		}
	}
}
private: System::Void PanelReina_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void FormJuego_Click(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void btn01_Click(System::Object^ sender, System::EventArgs^ e) {
}
 bool RevisarDiagonales(String^ entrada) {
	 if (btn00->Tag == entrada && btn11->Tag == entrada && btn22->Tag == entrada) {
		 return true;
	 }
	 else if (btn02->Tag == entrada && btn11->Tag == entrada && btn20->Tag == entrada){
		 return true;
	 }
	 else{
		 return false;
	 }
}
bool RevisarColumnas(String^ entrada){
	if (btn00->Tag == entrada && btn10->Tag == entrada && btn20->Tag == entrada) {
		 return true;
	 }
	 else if (btn01->Tag == entrada && btn11->Tag == entrada && btn21->Tag == entrada){
		 return true;
	 }
	 else if (btn02->Tag == entrada && btn12->Tag == entrada && btn22->Tag == entrada) {
	 return true;
	 }
	 else{
		 return false;
	 }
}
bool RevisarFilas(String^ entrada){
	if (btn00->Tag == entrada && btn01->Tag == entrada && btn02->Tag == entrada) {
		 return true;
	 }
	 else if (btn10->Tag == entrada && btn11->Tag == entrada && btn12->Tag == entrada){
		 return true;
	 }
	 else if (btn20->Tag == entrada && btn21->Tag == entrada && btn22->Tag == entrada) {
	 return true;
	 }
	 else{
		 return false;
	 }
}
void JugadaBot() 
{
	if (jugadas == 0) 
	{
		ColocarTagImagen(btn11);
	}
	else 
	{

	}
}
bool HayAmenaza(int n, int opcion) 
{
	for each (Button ^ var in PanelTablero->Controls)
	{
		if (var->Tag == nullptr) 
		{
			int sumaLocalizaciones = var->Location.X + var->Location.Y;
			if(sumaLocalizaciones == 0 || sumaLocalizaciones == 73 || sumaLocalizaciones == 146 || sumaLocalizaciones == 292){
				BusquedaDiagonal(var, simboloOponente);
			}
			
			
		}
	}
}

bool BusquedaDiagonal(Button^ boton, string simbolo) 
{
	int posicionX = boton->Location.X;
	int posicionY = boton->Location.Y;

	if (boton->Name == "btn00");
}
int SumaArregloColumna(int a[3][3], int nColumna) {
	int suma=0;
	for(int i = 0; i < 3 ; i++){
		suma = suma + a[nColumna][i];
	}
	return suma;
}

//la posicion en x y la posicion y. a[x][y] =  simbolo;
void ColocarTagImagen(Button^ boton) 
{
	if (JuegaX) {
		boton->Image = picBoxEquis->Image;
		boton->Tag = "X";
		JuegaX = false;
		Juega0 = true;
		labelJugadorJugandp->Text = "Est� jugando " + labelNomO->Text;
	}
	else {
		boton->Image = picBoxCirculo->Image;
		boton->Tag = "0";
		Juega0 = false;
		JuegaX = true;
		labelJugadorJugandp->Text = "Est� jugando " + labelNomX->Text;
	}
	jugadas++;
}
private: System::Void btnReiniciar_Click(System::Object^ sender, System::EventArgs^ e) {
	for each (Button ^ var in PanelTablero->Controls)
	{	
			var->Enabled = true;
			var->Image = btnReiniciar->Image;
			var->Tag = nullptr;
	}
	jugadas = 0;
	partidaTerminada = false;
	btnReiniciar->Enabled = false;
	btnSalir->Enabled = false;
	labelNomX->ForeColor = Color::Black;
	labelNomO->ForeColor = Color::Black;
	textoGanador->Visible = false;
	if (numpartidas % 2 == 0) {
		jugEmpieza->Text = "Comienza X";
		JuegaX = true;
		Juega0 = false;
		labelJugadorJugandp->Text = "Est� jugando " + labelNomX->Text;
	}
	else {
		jugEmpieza->Text = "Comienza O";
		JuegaX = false;
		Juega0 = true;
		labelJugadorJugandp->Text = "Est� jugando " + labelNomO->Text;
	}

}
private: System::Void btnSalir_Click(System::Object^ sender, System::EventArgs^ e) {
	for each (Button ^ var in PanelTablero->Controls)
	{
		var->Enabled = true;
		var->Image = btnReiniciar->Image;
		var->Tag = nullptr;
	}
	jugadas = 0;
	numpartidas = 0;
	JuegaX = true;
	Juega0 = false;
	partidaTerminada = false;
	this->Close();
}
};
}
