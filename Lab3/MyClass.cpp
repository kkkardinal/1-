#include "pch.h"
#include "Windows.h"
#include "MyClass.h"
#include "WinForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections;

MyClass::MyClass(void)
{
	TextFileName1 = gcnew String("FileIncluded.txt");
	TextFileName2 = gcnew String("FileNotIncluded.txt");
	aNames = gcnew ArrayList();
}

ArrayList^ MyClass::GetCurrencyWithParametr(String^ Words)
{
	ArrayList^ aNameList = gcnew ArrayList();
	for (int i = 0; i < aNames->Count; i++) {
		String^ e = (String^)aNames[i];
		if (e->IndexOf(Words) > -1) {
			aNameList->Add(e);
		}
	}
	return (aNameList);
}

ArrayList^ MyClass::GetCurrencyWithoutParametr(String^ Words)
{
	ArrayList^ aNameList = gcnew ArrayList();
	for (int i = 0; i < aNames->Count; i++) {
		String^ e = (String^)aNames[i];
		if (e->IndexOf(Words) == -1) {
			aNameList->Add(e);
		}
	}
	return(aNameList);
}

void MyClass::SetTextFileName(String^ NewName)
{
	TextFileName1 = NewName;
	TextFileName2 = NewName;
}

void MyClass::SaveToCurrencyWithParametr(String^ Words)
{
	ArrayList^ aNameList = gcnew ArrayList();
	aNameList = GetCurrencyWithParametr(Words);
	System::Console::WriteLine("Sites that include this word: \n");
	for (int i = 0; i < aNameList->Count; i++) {
		System::Console::WriteLine((String^)aNameList[i]);
	}
	System::IO::StreamWriter^ sw = gcnew System::IO::StreamWriter(this->TextFileName1);
	for (int i = 0; i < aNameList->Count; i++) {
		sw->WriteLine((String^)aNameList[i]);
	}
	sw->Close();
}

void MyClass::SaveToCurrencyWithoutParametr(String^ Words)
{
	ArrayList^ aNameList = gcnew ArrayList();
	aNameList = GetCurrencyWithoutParametr(Words);
	System::Console::WriteLine("\nSites that not include this word: \n");
	for (int i = 0; i < aNameList->Count; i++) {
		System::Console::WriteLine((String^)aNameList[i]);
	}
	System::IO::StreamWriter^ sw = gcnew System::IO::StreamWriter(this->TextFileName2);
	for (int i = 0; i < aNameList->Count; i++) {
		sw->WriteLine((String^)aNameList[i]);
	}
	sw->Close();
}

void MyClass::AddNameToList(String^ Name)
{
	aNames->Add(Name);
}

void MyClass::DelNameFromList(String^ Name)
{
	aNames->Remove(Name);
}

bool  MyClass::isCorrectDate(String^ dayS, String^ month ) {
	bool result = false;
	int day = Convert::ToInt32(dayS);
	if (day < 1) return result;
	if ((month == "Январь" || month == "Март" || month == "Май" || month == "Июль" || month == "Август" || month == "Октябрь" || month == "Декабрь") && (day < 32)) {
		
			result = true;
		
	}
	else if ( (month == "Февраль") && (day < 30)) {
		
			result = true;
		
	}
	else if ( (month == "Апрель" || month == "Июнь" || month == "Сентябрь" || month == "Ноябрь") && (day < 31)) {
		
			result = true;
		
	}
	return result;
}

bool MyClass::isCorrectDays(String^ days) {
	bool result = false;
	if (days == "1" || days == "2" || days == "3" || days == "4" || days == "5" || days == "6" || days == "7" || days == "8" || days == "9" || days == "10" || days == "11" || days == "12" || days == "13" || days == "14" || days == "15" || days == "16" || days == "17" || days == "18" || days == "19" || days == "20" || days == "21" || days == "22" || days == "23" || days == "24" || days == "25" || days == "26" || days == "27" || days == "28" || days == "29" || days == "30" || days == "31") {
		result = true;
	}
	return result;
}

bool MyClass::isCorrectNumberInt(String^ numberInt) {
	bool result = false;
	for (int i = 0; i < numberInt->Length; i++) {
	
		 if ((numberInt[i] == '1' || numberInt[i] == '2' || numberInt[i] == '3' || numberInt[i] == '4' || numberInt[i] == '5' || numberInt[i] == '6' || numberInt[i] == '7' || numberInt[i] == '8' || numberInt[i] == '9' || numberInt[i] == '0')) {
			result = true;
		}
		else {
			result = false;
			break;
		}
	}

	return result;
}

bool MyClass::isCorrectNumberSix(String^ numberInt) {
	bool result = false;
	for (int i = 0; i < numberInt->Length; i++) {

		if ((numberInt[i] == '1' || numberInt[i] == '2' || numberInt[i] == '3' || numberInt[i] == '4' || numberInt[i] == '5' || numberInt[i] == '6' || numberInt[i] == '7' || numberInt[i] == '8' || numberInt[i] == '9' || numberInt[i] == '0' || numberInt[i] == 'A' || numberInt[i] == 'B' || numberInt[i] == 'C' || numberInt[i] == 'D' || numberInt[i] == 'E' || numberInt[i] == 'F')) {
			result = true;
		}
		else {
			result = false;
			break;
		}
	}

	return result;
}

bool MyClass::isCorrectNumberFloat(String^ numberInt) {
	bool result = false;
	int countPoint;
	int Position;
	for (int i = 0; i < numberInt->Length; i++) {
		if (numberInt[i] == '.') {
			countPoint++;
			Position = i;

		}
		
		if ((numberInt[i] == '1' || numberInt[i] == '2' || numberInt[i] == '3' || numberInt[i] == '4' || numberInt[i] == '5' || numberInt[i] == '6' || numberInt[i] == '7' || numberInt[i] == '8' || numberInt[i] == '9' || numberInt[i] == '0' || numberInt[i] == '.' )  && numberInt[0]!='.' ) {
			result = true;
		}
		else {
			result = false;
			break;
		}
	}
	if (countPoint == 1 && Position != 0 && Position != (numberInt->Length) - 1);
	
	else result = false;
	return result;

}

bool MyClass::isCorrectCurrency(String^ nameCurrency) {
	bool result = false;

	for (int i = 0; i < nameCurrency->Length; i++) {
		if ((nameCurrency[i]>='A' && nameCurrency[i]<='Z') || (nameCurrency[i] >= 'a' && nameCurrency[i] <= 'z') ) {
			result = true;
		}
		else {
			result = false;
			break;
		}
	}
	return result;
}

