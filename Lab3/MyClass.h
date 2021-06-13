#pragma once

using namespace System;
using namespace System::Collections;

ref class MyClass
{
public:
	//����������� ������
	MyClass(void);
	//�������� ������ � ������
	void AddNameToList(String^);
	//������� ������ �� ������
	void DelNameFromList(String^);
	//���������� �������� ��� ���������� ����������� ������
	void SetTextFileName(String^);
	//�������� ������ ���� � �������� ����������
	ArrayList^ GetCurrencyWithParametr(String^);
	// �������� ������ ���� ��� �������� ���������
	ArrayList^ GetCurrencyWithoutParametr(String^);
	//��������� ������ ���� � �������� ����������
	void SaveToCurrencyWithParametr(String^);
	//��������� ������ ���� ��� �������� ��������
	void SaveToCurrencyWithoutParametr(String^);
	// �������� ���� �� ������������
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