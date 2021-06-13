#include <Windows.h>
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <cstring>
#include <sstream>
using namespace std;
int menu;

struct Human {
	string surname;
	string name;
	string height;
	string weight;
	string day;
	string month;
	string year;
	string number;
	string country;
	string region;
	string city;
	string street;
	string house;
	string flat;
	/* char *surname;
    char *name;
   // string mw;
    int height;
    int weight;
    int day;
    char *month;
    int year;
    int number;
    char* country;
	char* region;
	char* city;
	char* street;
    int house;
    int flat;
	*/
};

void vvod(Human* (&d), int& n)
{
	cout << "Кол-во элементов : ";
	cin >> n;//5
	ofstream fout("tabl.txt");
	for (int i = 0; i < n; i++) {
		//d = new Human[n];
		Human newHuman = {};
		cout << "Фамилия: ";
		cin >> newHuman.surname;
		fout << newHuman.surname << endl;
		cout << "Имя: ";
		cin >> newHuman.name;
		fout << newHuman.name << endl;
		//cout << "Пол: ";
		//cin >> newHuman.mw;
		//fout << newHuman.mw;
		cout << "Рост: ";
		cin >> newHuman.height;
		fout << newHuman.height << endl;
		cout << "Вес: ";
		cin >> newHuman.weight;
		fout << newHuman.weight << endl;
		cout << "день: ";
		cin >> newHuman.day;
		fout << newHuman.day << endl;
		cout << "месяц: ";
		cin >> newHuman.month;
		fout << newHuman.month << endl;
		cout << "год: ";
		cin >> newHuman.year;
		fout << newHuman.year << endl;
		cout << "номер телефона: ";
		cin >> newHuman.number;
		fout << newHuman.number << endl;
		cout << "страна: ";
		cin >> newHuman.country;
		fout << newHuman.country << endl;
		cout << "регион: ";
		cin >> newHuman.region;
		fout << newHuman.region << endl;
		cout << "город: ";
		cin >> newHuman.city;
		fout << newHuman.city << endl;
		cout << "улица: ";
		cin >> newHuman.street;
		fout << newHuman.street << endl;
		cout << "дом: ";
		cin >> newHuman.house;
		fout << newHuman.house << endl;
		cout << "квартира: ";
		cin >> newHuman.flat;
		fout << newHuman.flat << endl;
		cout << "____________________________________________" << endl;

	}
	fout.close();
	
 /*   ofstream fout("tabl.txt");
    fout << ;
    fin.close();
    cout << " Проверьте файл result";*/
}

/*void vivod(Human* (&d), int& n)
{
	ifstream fin;
	fin.open("tabl.txt");
	if (!fin.is_open()) {
		cout << "Ошибка"<<endl;
	}
	else {
		cout << "Файл открыт"<< endl;
	}

	cout << "surname" << "\t" << "name" << "\t"<< "height" << "\t"
		<< "weight" << "\t" << "day" << "\t"
		<< "month" << "\t" << "year" << "\t" << "number" << "\t" << "country" << "\t" << "region" << "\t" << "city" << "\t"
		<< "street" << "\t" << "house" << "\t"
		<< "flat" << endl;
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << d[i].surname << "\t" << d[i].name << "\t" << d[i].height << "\t"
			<< d[i].weight << "\t" << d[i].day << "\t"
			<< d[i].month << "\t" << d[i].year << "\t" << d[i].number << "\t" << d[i].country
			<< "\t" << d[i].region << "\t" << d[i].city << "\t"
			<< d[i].street << "\t" << d[i].house << "\t"
			<< d[i].flat << endl;
	}

	fin.close();
}*/
// Возвращает кол-во записей в файле ../db.txt
int getCount() {

	ifstream file("../db.txt");

	if (file.is_open()) {
		string str;

		int count = 0;

		while (getline(file, str)) {
			count++;
		}

		file.close();

		return count;
	}

	return 0;

}
// Возвращает массив структур всех команд
Human* getAllData() {

	int count = getCount();

	Human* d = new Human[count];

	ifstream file("../tabl.txt");

	if (file.is_open()) {

		string str;

		int i = 0;

		while (getline(file, str)) {

			istringstream istr(str);

			istr >> d[i].surname >> d[i].name >> d[i].height >> d[i].weight >> d[i].day >> d[i].month >> d[i].year >> d[i].number >> d[i].country >> d[i].region >> d[i].city >> d[i].street >> d[i].house;

			i++;
		}

		file.close();

		return d;
	}

	return 0;

}
void Human_vivod(Human* (&d), int &n)
{

 getCount();
getAllData();

	for (int i = 0; i < n; i++) {
		cout << "Человек № " << i + 1 << ":" << endl;
		cout << "Фамилия: " << d[i].surname << "\t";
		cout << "Имя: " << d[i].name << "\t";
		cout << "Рост: " << d[i].height << "\t";
		cout << "Вес: " << d[i].weight << "\t";
		cout << "День: " << d[i].day << "\t";
		cout << "Месяц: " << d[i].month << "\t";
		cout << "Год: " << d[i].year<< "\t";
		cout << "Номер: " << d[i].number << "\t";
		cout << "Страна: " << d[i].country << "\t";
		cout << "Регион: " << d[i].region << "\t";
		cout << "Город: " << d[i].city << "\t";
		cout << "Улица: " << d[i].street << "\t";
		cout << "Дом: " << d[i].house << "\t";
		cout << "Квартира: " << d[i].flat << endl;
	}
}

void schitivanie(Human* (&d), int& n, string filename)//out.txt
{
	ifstream read(filename);

	if (read)
	{
		read >> n;

		d = new Human[n];

		for (int i = 0; i < n; i++) {
			read >> d[i].surname;
			read >> d[i].name;
			read >> d[i].height;
			read >> d[i].weight;
			read >> d[i].day;
			read >> d[i].month;
			read >> d[i].year;
			read >> d[i].number;
			read >> d[i].country;
			read >> d[i].region;
			read >> d[i].city;
			read >> d[i].street;
			read >> d[i].house;
			read >> d[i].flat;
		}
		cout << "Данные считаны" << endl;
	}
	else {
		cout << "Ощибка чтения файла. P.S. ЕБ проверь правильность написания файла" << endl;
	}

	read.close();
}
void Copy(Human* (&d_new), Human* (&d_old), int n)
	{
		for (int i = 0; i < n; i++) {
			d_new[i] = d_old[i];
		}
	}
void dobavlenie(Human* (&d), int& n){
	Human* NEW = new Human[n];
	Copy(NEW, d, n);
	n++;
	d = new Human[n];//заново выделяем память(новую) поновой выделяем память
	Copy(d, NEW, --n);
	
	cout << "Кол-во элементов, которые хотите добавить : ";
	cin >> n;//5
	for (int i = 0; i < n; i++) {
	//	d = new Human[n];
		cout << "Фамилия: ";
		cin >> d[n].surname;
		cout << "Имя: ";
		cin >> d[n].name;
		cout << "Рост: ";
		cin >> d[i].height;
		cout << "Вес: ";
		cin >> d[i].weight;
		cout << "день: ";
		cin >> d[i].day;
		cout << "месяц: ";
		cin >> d[n].month;
		cout << "год: ";
		cin >> d[i].day;
		cout << "номер телефона: ";
		cin >> d[i].number;
		cout << "страна: ";
		cin >> d[n].country;
		cout << "регион: ";
		cin >> d[n].region;
		cout << "город: ";
		cin >> d[n].city;
		cout << "улица: ";
		cin >> d[n].street;
		cout << "дом: ";
		cin >> d[i].house;
		cout << "квартира: ";
		cin >> d[i].flat;
		cout << "____________________________________________" << endl;
	}
	delete[]NEW;
	}
void coutColomns()
{

	cout << "surname" << "\t" << "name" << "\t" << "height" << "\t"
		<< "weight" << "\t" << "day" << "\t"
		<< "month" << "\t" << "year" << "\t" << "number" << "\t" << "country" << "\t" << "region" << "\t" << "city" << "\t"
		<< "street" << "\t" << "house" << "\t"
		<< "flat" << endl;
}

void coutDataByIndex(Human* (&d), int index)
{
	cout << d[index].surname << "\t" << d[index].name << "\t"
		 << d[index].height << "\t"
		<< d[index].weight << "\t" << d[index].day << "\t"
		<< d[index].month << "\t" << d[index].year << "\t"
		<< d[index].number << "\t" << d[index].country << "\t"
		<< d[index].region << "\t" << d[index].city << "\t"
		<< d[index].street << "\t" << d[index].house << "\t"
		<< d[index].flat << endl;
}

auto sort_algoritm(int arr[], int size)
{
	int temp;

	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	return arr;
}
void Human_sorting_height(Human* d, int n) 
{
	Human temp;
	for (int i = 0; i < n - 1; i++) {
		for (int j = (n - 1); j > i; i--) {
			if (d[j- 1].height > d[j].height) {
				temp.height = d[j - 1].height;
				d[j - 1].height = d[j].height;
				d[j].height = temp.height;
			}
		}
	}
}
void Human_sorting_weight(Human* d, int n)
{
	Human temp;
	for (int i = 0; i < n - 1; i++) {
		for (int j = (n - 1); j > i; i--) {
			if (d[j - 1].weight > d[j].weight) {
				temp.weight = d[j - 1].weight;
				d[j - 1].weight = d[j].weight;
				d[j].weight = temp.weight;
			}
		}
	}
}
/*void sortirovka(Human* (&d), int& n) {
	cout << "1.height" << "\n" << "2.weight" << endl;
	cout << "sort by: ";
	int sort_by;
	cin >> sort_by;
	switch (sort_by)
	{
	case(1):
	{
		string* arr = new string[n];
		for (int i = 0; i < n; i++)
		{
			arr[i] = d[i].height;
		}
		arr = sort_algoritm(arr, n);
		coutColomns();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (arr[i] == d[j].height)
				{
					coutDataByIndex(d, j);
					break;
				}
			}
		}
		delete[]arr;
		break;
	}
	case(2):
	{
		string* arr = new string[n];
		for (int i = 0; i < n; i++)
		{
			arr[i] = d[i].weight;
		}
		arr = sort_algoritm(arr, n);
		coutColomns();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (arr[i] == d[j].weight)
				{
					coutDataByIndex(d, j);
					break;
				}
			}
		}
		delete[]arr;
		break;
	}
	}
	}
	*/
void Show_Human(const Human& s)
{

	cout << "surname:" << s.surname << endl << "name:" << s.name << endl
		<< "height:" << s.height << endl << "weight:" << s.weight << endl << "day:" << s.day << endl
		<< "month:" << s.month << endl << "year:" << s.year << endl << "number:" << s.number << endl
		<< "country:" << s.country << endl << "region:" << s.region << endl << "city:" << s.city << endl
		<< "street:" << s.street << endl << "house:" << s.house << endl << "flat:" << s.flat << endl;
	cout << "_____________________________" << endl;
}
void poisk_surname(Human* d, int n, string key)
{
	int t = 0;
	for (int i = 0; i < n; i++)
		if (key == d[i].surname) {
			Show_Human(d[i]);
			t++;
		}
	if (t == 0)	cout << "Необнаружено соответствий" << endl;
}
void poisk_name(Human* d, int n, string key)
{
	int t = 0;
	for (int i = 0; i < n; i++)
		if (key == d[i].name) {
			Show_Human(d[i]);
			t++;
		}
	if (t == 0)	cout << "Необнаружено соответствий" << endl;
}
void poisk_height(Human* d, int n, string key)
{
	int t = 0;
	for (int i = 0; i < n; i++)
		if (key == d[i].height) {
			Show_Human(d[i]);
			t++;
		}
	if (t == 0)	cout << "Необнаружено соответствий" << endl;
}
void poisk_weight(Human* d, int n, string key)
{
	int t = 0;
	for (int i = 0; i < n; i++)
		if (key == d[i].weight) {
			Show_Human(d[i]);
			t++;
		}
	if (t == 0)	cout << "Необнаружено соответствий" << endl;
}
void poisk_day(Human* d, int n, string key)
{
	int t = 0;
	for (int i = 0; i < n; i++)
		if (key == d[i].day) {
			Show_Human(d[i]);
			t++;
		}
	if (t == 0)	cout << "Необнаружено соответствий" << endl;
}
void poisk_month(Human* d, int n, string key)
{
	int t = 0;
	for (int i = 0; i < n; i++)
		if (key == d[i].month) {
			Show_Human(d[i]);
			t++;
		}
	if (t == 0)	cout << "Необнаружено соответствий" << endl;
}
void poisk_year(Human* d, int n, string key)
{
	int t = 0;
	for (int i = 0; i < n; i++)
		if (key == d[i].year) {
			Show_Human(d[i]);
			t++;
		}
	if (t == 0)	cout << "Необнаружено соответствий" << endl;
}
void poisk_number(Human* d, int n, string key)
{
	int t = 0;
	for (int i = 0; i < n; i++)
		if (key == d[i].number) {
			Show_Human(d[i]);
			t++;
		}
	if (t == 0)	cout << "Необнаружено соответствий" << endl;
}
void poisk_country(Human* d, int n, string key)
{
	int t = 0;
	for (int i = 0; i < n; i++)
		if (key == d[i].country) {
			Show_Human(d[i]);
			t++;
		}
	if (t == 0)	cout << "Необнаружено соответствий" << endl;
}
void poisk_region(Human* d, int n, string key)
{
	int t = 0;
	for (int i = 0; i < n; i++)
		if (key == d[i].region) {
			Show_Human(d[i]);
			t++;
		}
	if (t == 0)	cout << "Необнаружено соответствий" << endl;
}
void poisk_city(Human* d, int n, string key)
{
	int t = 0;
	for (int i = 0; i < n; i++)
		if (key == d[i].city) {
			Show_Human(d[i]);
			t++;
		}
	if (t == 0)	cout << "Необнаружено соответствий" << endl;
}
void poisk_street(Human* d, int n, string key)
{
	int t = 0;
	for (int i = 0; i < n; i++)
		if (key == d[i].street) {
			Show_Human(d[i]);
			t++;
		}
	if (t == 0)	cout << "Необнаружено соответствий" << endl;
}
void poisk_house(Human* d, int n, string key)
{
	int t = 0;
	for (int i = 0; i < n; i++)
		if (key == d[i].house) {
			Show_Human(d[i]);
			t++;
		}
	if (t == 0)	cout << "Необнаружено соответствий" << endl;
}
void poisk_flat(Human* d, int n, string key)
{
	int t = 0;
	for (int i = 0; i < n; i++)
		if (key == d[i].flat) {
			Show_Human(d[i]);
			t++;
		}
	if (t == 0)	cout << "Необнаружено соответствий" << endl;
}


	int Menu() {
		cout << "Выбери" << endl;
		cout << "(1)Выход" << endl;//выход из меню
		cout << "(2)вывод" << endl;
		cout << "(3)ввод" << endl;
		cout << "(4)добавление" << endl;
		cout << "(5)сортировка" << endl;
		cout << "(6)поиск" << endl;
		cout << "Цифра : ";
		cin >> menu;
		return menu;
	}
	
	int main() {
		setlocale(LC_ALL, "rus");
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		Menu();
		int amount = 0;
		string filename;
		//Инициализация масива
		Human* d = new Human[amount];
		

		while (menu != 1) {
			switch (menu)
			{
			case 2:
				Human_vivod(d, amount);
				cout << endl;
				Menu();
				break;
			case 3:
				cout << "Информация вводится из файла? 1-да; 2-нет : ";
				int choise;
				cin >> choise;
				if (choise == 1) {
					cout << "Введи название фала с .txt : ";
					string file;
					cin >> file;
					schitivanie(d, amount, file);
				}
				else {
					vvod(d, amount);
				}
				Menu();
				break;
			case 4:
				dobavlenie(d, amount);
				amount++;
				Menu();
				break;
			case 5:
				int num;
				cout << "1.Сортировка по росту" << "\n" << "2.Сортировка по весу" << "\n";
				cin >> num;
				if (num == 1) {
					Human_sorting_height(d, amount);
				}
				if (num == 2) {
					Human_sorting_weight(d, amount);
				}

				Menu();
				break;
			case 6:
				string key;
				int comp;
				cout << "1.Поиск по фамилии" << "\n" << "2.Поиск по имени" << "\n";
				cout << "3.Поиск по росту" << "\n" << "4.Поиск по весу" << "\n";
				cout << "5.Поиск по дню" << "\n" << "6.Поиск по месяцу" << "\n";
				cout << "7.Поиск по году" << "\n" << "8.Поиск по номеру" << "\n";
				cout << "9.Поиск по стране" << "\n" << "10.Поиск по региону" << "\n";
				cout << "11.Поиск по городу" << "\n" << "12.Поиск по улице" << "\n";
				cout << "13.Поиск по дому" << "\n" << "14.Поиск по квартире" << "\n";
				cout << "Что искать" << endl;
				cin >> comp;
				cin >> key;
				switch (comp)
				{
				case 1:
					poisk_surname(d, amount, key);
					break;
				case 2:
					poisk_name(d, amount, key);
					break;
				case 3:
					poisk_height(d, amount, key);
					break;
				case 4:
					poisk_weight(d, amount, key);
					break;
				case 5:
					poisk_day(d, amount, key);
					break;
				case 6:
					poisk_month(d, amount, key);
					break;
				case 7:
					poisk_year(d, amount, key);
					break;
				case 8:
					poisk_number(d, amount, key);
					break;
				case 9:
					poisk_country(d, amount, key);
					break;
				case 10:
					poisk_region(d, amount, key);
					break;
				case 11:
					poisk_city(d, amount, key);
					break;
				case 12:
					poisk_street(d, amount, key);
					break;
				case 13:
					poisk_house(d, amount, key);
					break;
				case 14:
					poisk_flat(d, amount, key);
					break;
				}
			}
			//poisk(d, amount);
			Menu();
			break;
			}
	}
