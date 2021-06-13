#include "pch.h"
#include "WinForm.h"
#include "MyClass.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Data::OleDb;

[STAThreadAttribute]

int main(array<System::String^>^ args)
{
	
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Lab3::WinForm form;
	Application::Run(% form);

	return 0;
}