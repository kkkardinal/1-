#include <Windows.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct Human
{
	string surname, name, country, city, street;
	string height, weight, year, number, house;
};

// Возвращает кол-во записей в файле ../db.txt считает количество строк
int getCount() {

	ifstream file("../test.txt");//ввод и чтение данных с файла

	if (file.is_open()) {
		string str;

		int count = 0;//переменная счета

		while (getline(file, str)) {
			count++;
		}
		//считывает все строки
		file.close();

		return count;
	}

	return 0;

}

// Возвращает массив структур всех людей //считывает содержимое строк
Human* getAllData() {

	int count = getCount();
	//указатель на структуру в динамической памяти
	Human* h = new Human[count];

	ifstream file("../test.txt");//ввод и чтение

	if (file.is_open()) {

		string str;

		int i = 0;

		while (getline(file, str)) {
			//для функции ввода строковый поток ввода
			istringstream istr(str);

			istr >> h[i].surname >> h[i].name >> h[i].height >> h[i].weight >> h[i].year >> h[i].number >> h[i].country >> h[i].city >> h[i].street >> h[i].house;

			i++;
		}

		file.close();

		return h;
	}

	return 0;

}

// Ввыводит все структуры команд
void selectAll() {

	int count = getCount();

	Human* h = 	getAllData();
	//получение указателя на 1 структуру
	int i = 0;

	for (int i = 0; i < count; i++) {
		cout << "--- " << i << " ---" << endl
			<< "Фамилия: " << h[i].surname << endl
			<< "Имя: " << h[i].name << endl
			<< "Рост: " << h[i].height << endl
			<< "Вес: " << h[i].weight << endl
			<< "Год: " << h[i].year << endl
			<< "Номер: " << h[i].number << endl
			<< "Страна: " << h[i].country << endl
			<< "Город: " << h[i].city << endl
			<< "Улица: " << h[i].street<< endl
			<< "Дом: " << h[i].house << endl << endl;
	}

}

// Добовляет новую структуру. Возвращает true в случае успеха, иначе false
bool create() {

	ofstream file("../test.txt", ios::app);//запись в конец файла(append)

	if (!file.is_open()) return false;

	Human h;

	cout << "Фамилия: ";
	cin >> h.surname;
	cout << "Имя: ";
	cin >> h.name;
	cout << "Рост: ";
	cin >> h.height;
	cout << "Вес: ";
	cin >> h.weight;
	cout << "Год: ";
	cin >> h.year;
	cout << "Номер: ";
	cin >> h.number;
	cout << "Страна: ";
	cin >> h.country;
	cout << "Город: ";
	cin >> h.city;
	cout << "Улица: ";
	cin >> h.street;
	cout << "Дом: ";
	cin >> h.house;

	file << "\n" << h.surname << "\t"
		<< h.name << "\t"
		<< h.height << "\t"
		<< h.weight << "\t"
		<< h.year << "\t"
		<< h.number << "\t"
		<< h.country << "\t"
		<< h.city << "\t"
		<< h.street << "\t"
		<< h.house;

	return true;

}

// Находит и выводит команду с данными введеными с консоли
void search() {

	cout << "Введите данные для поиска. Если нужно пропустить поле введите в качестве значения 0." << endl;

	Human h;

	Human* hs = getAllData();
	int count = getCount();

	cout << "Фамилия: ";
	cin >> h.surname;
	cout << "Имя: ";
	cin >> h.name;
	cout << "Рост: ";
	cin >> h.height;
	cout << "Вес: ";
	cin >> h.weight;
	cout << "Год: ";
	cin >> h.year;
	cout << "Номер: ";
	cin >> h.number;
	cout << "Страна: ";
	cin >> h.country;
	cout << "Город: ";
	cin >> h.city;
	cout << "Улица: ";
	cin >> h.street;
	cout << "Дом: ";
	cin >> h.house;
	if (h.surname == "0" && h.name == "0" && h.height == "0" && h.weight == "0" && h.year == "0"
		&& h.number == "0" && h.country == "0" && h.city == "0" && h.street == "0" && h.house == "0") return;
	for (int i = 0; i < count; i++) {
		if ((h.surname == "0" || h.surname == hs[i].surname) && (h.name == "0" || h.name == hs[i].name)
			&& (h.height == "0" || h.height == hs[i].height)
			&& (h.weight== "0" || h.weight == hs[i].weight)
			&& (h.year == "0" || h.year == hs[i].year)
			&& (h.number == "0" || h.number == hs[i].number)
			&& (h.country == "0"|| h.country == hs[i].country) && (h.city == "0"|| h.city == hs[i].city)
			&& (h.street == "0" || h.street == hs[i].street) && (h.house == "0" || h.house == hs[i].house)) {
// смещает указатель на столько структур(=i)
			cout << "Фамилия: " << hs[i].surname << endl
				<< "Имя: " << hs[i].name << endl
				<< "Рост: " << hs[i].height << endl
				<< "Вес: " << hs[i].weight << endl
				<< "Год: " << hs[i].year << endl
				<< "Номер: " << hs[i].number << endl
				<< "Страна: " << hs[i].country << endl
				<< "Город: " <<hs[i].city << endl
				<< "Улица: " << hs[i].street << endl
				<< "Дом: " << hs[i].house << endl;
		}
	}

}
// Возвращает true если строка a должна стоять перед строкой b при сортировке по алфавиту 
bool maxStr(string a, string b) {

	for (int i = 0; i < size(a); i++) {
		if ((int)a[i] == (int)b[i]) continue;
		if ((int)a[i] < 0) return (int)a[i] < (int)b[i];
		return !((int)a[i] > (int)b[i]);
	}

	return false;

}

// Сортирует массив структур по указанной строке
int sort() {

	cout << "Выберите строку для сортировки: " << endl
		<< "\t(1)Фамилия\n\t(2)Имя\n\t(3)Рост\n\t(4)Вес\n\t(5)Год \n\t(6)Номер\n\t(7)Страна\n\t(8)Город\n\t (9)Улица\n\t(10)Дом\n\t" << endl;

	int d = 0;
	int count = getCount();
	Human* hs = getAllData();
	Human h;
	cin >> d;

	if (d == 0) return 0;

	if (d == 1) {
		for (int i = 0; i < count; i++) {
			for (int j = 0; j < count; j++) {
				if (maxStr(hs[i].surname, hs[j].surname)) {
					h = hs[j];
					hs[j] = hs[i];
					hs[i] = h;
				}
			}
		}
	}

	if (d == 2) {
		for (int i = 0; i < count; i++) {
			for (int j = 0; j < count; j++) {
				if (maxStr(hs[i].name, hs[j].name)) {
					h = hs[j];
					hs[j] = hs[i];
					hs[i] = h;
				}
			}
		}
	}

	if (d == 3) {
		for (int i = 0; i < count; i++) {
			for (int j = 0; j < count; j++) {
				if (maxStr(hs[i].height,  hs[j].height)) {
					h = hs[j];
					hs[j] = hs[i];
					hs[i] = h;
				}
			}
		}
	}

	if (d == 4) {
		for (int i = 0; i < count; i++) {
			for (int j = 0; j < count; j++) {
				if (maxStr(hs[i].weight, hs[j].weight)) {
					h = hs[j];
					hs[j] = hs[i];
					hs[i] = h;
				}
			}
		}
	}

	if (d == 5) {
		for (int i = 0; i < count; i++) {
			for (int j = 0; j < count; j++) {
				if (maxStr(hs[i].year, hs[j].year)) {
					h = hs[j];
					hs[j] = hs[i];
					hs[i] = h;
				}
			}
		}
	}

	if (d == 6) {
		for (int i = 0; i < count; i++) {
			for (int j = 0; j < count; j++) {
				if (maxStr(hs[i].number, hs[j].number)) {
					h = hs[j];
					hs[j] = hs[i];
					hs[i] = h;
				}
			}
		}
	}

	if (d == 7) {
		for (int i = 0; i < count; i++) {
			for (int j = 0; j < count; j++) {
				if (maxStr(hs[i].country , hs[j].country)) {
					h = hs[j];
					hs[j] = hs[i];
					hs[i] = h;
				}
			}
		}
	}

	if (d == 8) {
		for (int i = 0; i < count; i++) {
			for (int j = 0; j < count; j++) {
				if (maxStr(hs[i].city, hs[j].city)) {
					h = hs[j];
					hs[j] = hs[i];
					hs[i] = h;
				}
			}
		}
	}
	if (d == 9) {
		for (int i = 0; i < count; i++) {
			for (int j = 0; j < count; j++) {
				if (maxStr(hs[i].street, hs[j].street)) {
					h = hs[j];
					hs[j] = hs[i];
					hs[i] = h;
				}
			}
		}
	}
	if (d == 10) {
		for (int i = 0; i < count; i++) {
			for (int j = 0; j < count; j++) {
				if (maxStr(hs[i].house, hs[j].house)) {
					h = hs[j];
					hs[j] = hs[i];
					hs[i] = h;
				}
			}
		}
	}
	
	for (int i = 1; i < count; i++) {
		cout << "--- " << i  << " ---" << endl
			<< "Фамилия: " << hs[i].surname << endl
			<< "Имя: " << hs[i].name << endl
			<< "Рост: " << hs[i].height << endl
			<< "Вес: " << hs[i].weight << endl
			<< "Год: " << hs[i].year << endl
			<< "Номер: " << hs[i].number << endl
			<< "Страна: " << hs[i].country << endl
			<< "Город: " << hs[i].city << endl
			<< "Улица: " << hs[i].street << endl
			<< "Дом: " << hs[i].house << endl << endl;
	}

}

// Вывод меню
void menu() {
	cout << "Выберите действие: " << endl
		<< "(1) Добавить структуру" << endl
		<< "(2) Поиск" << endl
		<< "(3) Вывести все структуры" << endl
		<< "(4) Упорядочить\n";
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	int i = 0;

	while (i != 10) {

		switch (i)
		{
		case 0:
			menu();
			cin >> i;
			break;
		case 1:
			create();
			cout << endl << "(0) Назад в меню (3) Вывести все структуры (10) Закрыть программу\n";
			cin >> i;
			break;
		case 2:
			search();
			cout << endl << "(0) Назад в меню (10) Закрыть программу\n";
			cin >> i;
			break;
		case 3:
			selectAll();
			cout << endl << "(0) Назад в меню (4) Упорядочить (10) Закрыть программу\n";
			cin >> i;
			break;
		case 4:
			sort();
			cout << endl << "(0) Назад в меню (10) Закрыть программу\n";
			cin >> i;
			break;
		}

		cout << endl << endl;

	}

}