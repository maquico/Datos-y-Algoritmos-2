/*
* ENUNCIADO: TAREA FINAL. REINA VS TORRES
* ASUNTO: Este programa genera las jugadas posibles para una reina en un tablero de ajedrez con dos torres
*
AUTORES: ANGEL MORENO ID:1104666
*        GLEIDY ESPINAL ID:1104225p
*        ALLEN SILVERIO ID:1104220
*        CRISTIAN JIMÉNEZ ID:1106166
*        WILLIAM FERREIRA ID:1104228
* FECHA: 10/10/2022
*/
#include "MyForm.h"

using namespace InicioJuegoTicTacToe;
using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	MyForm formq;
	Application::Run(% formq);
	return 0;
}