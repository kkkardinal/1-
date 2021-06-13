#include "Header.h"

int _menu;
int Menu() {
	cout << "Выбери" << endl;
	cout << "(1)Выход" << endl;
	cout << "(2)вывод" << endl;
	cout << "(3)ввод" << endl;
	cout << "(4)изменение" << endl;
	cout << "(5)удаление" << endl;
	cout << "(6)удалить все" << endl;
	cout << "(7)сортировка" << endl;
	cout << "(8)сохранение" << endl;
	cout << "Цифра : ";
	cin >> _menu;
	return _menu;
}

int main()
{
	//Руссификация консоли
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Menu();


	vector<Data> data;
	vector<Data>::iterator TY;
	string filename;
	

	while (_menu != 1)
	{
		switch (_menu)
		{
		case 2:
			system("cls");
			Data_out(data);
			system("pause");
			system("cls");
			Menu();
			break;
		case 3:
			system("cls");
			int case_if;
			cout << "Информация вводится вурчную? 1-да 0-нет";
			cin >> case_if;
			system("cls");
			switch (case_if)
			{
			case 1:
				Data_input(data);
				break;
			case 0:
				Data_read(data);
				break;
			default:
				cout << "Ошибка ввода";
				break;
			}
			system("pause");
			system("cls");
			Menu();
			break;
		case 4:
			system("cls");
			Data_change(data);
			system("pause");
			system("cls");
			Menu();
			break;
		case 5:
			system("cls");
			Data_erase(data);
			system("pause");
			system("cls");
			Menu();
			break;
		case 6:
			system("cls");
			Data_del_all(data);
			system("pause");
			system("cls");
			Menu();
			break;
		case 7:
			system("cls");
			Data_sort(data);
			system("pause");
			system("cls");
			Menu();
			break;
		case 8:
			system("cls");
			Data_save(data);
			system("pause");
			system("cls");
			Menu();
			break;
		default:
			break;
		}


	}
	

	system("pause");
	return 0;
}