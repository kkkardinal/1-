#pragma once

using namespace System;
using namespace System::Collections;

ref class MyClass
{
public:
	//конструктор класса
	MyClass(void);
	//добавить строку в список
	void AddNameToList(String^);
	//удалить строку из список
	void DelNameFromList(String^);
	//установить параметр для сохранения результатов поиска
	void SetTextFileName(String^);
	//получить список имен с заданным параметром
	ArrayList^ GetCurrencyWithParametr(String^);
	// получить список имен без заданого параметра
	ArrayList^ GetCurrencyWithoutParametr(String^);
	//сохранить список имен с заданным параметром
	void SaveToCurrencyWithParametr(String^);
	//сохранить список имен без заданого парметра
	void SaveToCurrencyWithoutParametr(String^);
	// проверка даты на корректность
	bool isCorrectDate(String^, String^);

	bool isCorrectDays(String^);

	bool isCorrectNumberInt(String^);
	
	bool isCorrectNumberSix(String^);

	bool isCorrectNumberFloat(String^);
	
	bool isCorrectCurrency(String^);

	
	
private:
	String^ TextFileName1;
	String^ TextFileName2;
	ArrayList^ aNames;
};