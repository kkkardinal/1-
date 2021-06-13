#define _CRT_SECURE_NO_WARNINGS
#define STR_LEN 32
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

// Возвращает true, если дата находится во 2 квартале 2020 года
bool is_in_second_part(char date[]) {
    int month, year;
    // Преобразуем числа формата string в int, отнимая 30 в шестнадцатиричной. (Например, 2 в string = 0x32 в int)
    // Обращаемся к конкретным индексам, что бы получить нужные цифры, затем делаем из них единое число
    month = (date[3] - 0x30) * 10 + (date[4] - 0x30);
    year = (date[6] - 0x30) * 1000 + (date[7] - 0x30) * 100 + (date[8] - 0x30) * 10 + (date[9] - 0x30);

    // Проверяем, находится ли дата во 2 квартале 2020 года
    return month >= 4 && month <= 6 && year == 2020;
}

struct Customer {
    char fio[STR_LEN * 3], date_start[STR_LEN], number[STR_LEN];
    vector<string> services; // ID-шники услуг, которые использует клиент
};

int main()
{


    // Список(вектор) клиентов
    vector<Customer> customers;

    // Блок обработки файла с клиентами
    {
        // Открываем clients.txt в режиме чтения
        FILE* clients_in = fopen("clients.txt", "r");

        // Строка на 128 символов +1 засчет \n и +1 засчет \0
        char current_line[130];

        // Считывая очередную строку, сразу проверяем, не NULL-овая ли она
        while (fgets(current_line, 130, clients_in) != NULL) {
            // Имя, фамилия, отчество, даты начала договора и его конца.
            char fio[STR_LEN * 3], date_start[STR_LEN], date_end[STR_LEN];



            // Телефонный номер клиента
            char number[STR_LEN];

            // Зануляем все байты в строках
            memset(fio, 0, STR_LEN * 3);
            memset(date_start, 0, STR_LEN);
            memset(number, 0, STR_LEN);

            // Задолженность и допустимый кредит не обрабатываем, т.к. задача этого не требует

            // Указатели на очередную строку и на поля с вводимыми данными
            char* ptr = current_line, * fio_ptr = fio, * date_start_ptr = date_start, * date_end_ptr = date_end, * num_ptr = number;

            // Блок для обработки очередной строки
            {
                // Пока не дошли до 1 запятой, считываем ФИО
                while (*ptr != ',') *fio_ptr++ = *ptr++;

                while (*ptr == ',' || *ptr == ' ') ptr++; // Чтобы пропустить запятую или пробел

                // Пока не дошли до 2 запятой, считываем номер
                while (*ptr != ',') *num_ptr++ = *ptr++;

                while (*ptr == ',' || *ptr == ' ') ptr++; // Чтобы пропустить запятую или пробел

                // Пока не дошли до 3 запятой, считываем дату начала
                while (*ptr != ',') *date_start_ptr++ = *ptr++;

                while (*ptr == ',' || *ptr == ' ') ptr++; // Чтобы пропустить запятую или пробел

                // Пока не дошли до 4 запятой, считываем дату конца
                while (*ptr != ',') *date_end_ptr++ = *ptr++;

                while (*ptr == ',' || *ptr == ' ') ptr++; // Чтобы пропустить запятую или пробел
            }

            // Создание скелета нового клиента
            Customer new_customer;

            // Заполнение данных о нём
            strcpy(new_customer.fio, fio);
            strcpy(new_customer.number, number);
            strcpy(new_customer.date_start, date_start);

            // Добавление очередного клиента в список, если он заключил договор во 2 квартале 2020
            if (is_in_second_part(date_start))
                customers.push_back(new_customer);
        }
        fclose(clients_in);
    }

    // Блок обработки файла с привязкой номера к услугам
    {
        // Открываем sptc.txt в режиме чтения
        FILE* clients_in = fopen("sptc.txt", "r");

        // Строка на 128 символов +1 засчет \n и +1 засчет \0
        char current_line[130];

        // Считывая очередную строку, сразу проверяем, не NULL-овая ли она
        while (fgets(current_line, 130, clients_in) != NULL) {

            // Телефонный номер клиента и id услуги
            char number[STR_LEN], id[STR_LEN];

            // Зануляем все байты в строках
            memset(number, 0, STR_LEN);
            memset(id, 0, STR_LEN);

            char* num_ptr = number, * id_ptr = id, * ptr = current_line;

            // Блок для обработки очередной строки
            {
                // Пока не дошли до 1 запятой, считываем ФИО
                while (*ptr != ',') *num_ptr++ = *ptr++;

                while (*ptr == ',' || *ptr == ' ') ptr++; // Чтобы пропустить запятую или пробел

                // Пока не дошли до 2 запятой, считываем номер
                while (*ptr != ',') *id_ptr++ = *ptr++;
            }

            // Сопоставление клиентов и использованных услуг
            for (int i = 0; i < customers.size(); i++) {

                // Сравниваем номера телефонов
                if (strcmp(customers[i].number, number) == 0) {

                    // Добавляем в список услуг клиента ещё услугу
                    customers[i].services.push_back(id);
                }
            }
        }
        fclose(clients_in);
    }
    // Создаем map, где id - ключ, а название услуги значение
    map<string, string> services;

    // Блок обработки файла с названиями услуг
    {
        // Открываем services.txt в режиме чтения
        FILE* clients_in = fopen("services.txt", "r");

        // Строка на 128 символов +1 засчет \n и +1 засчет \0
        char current_line[130];

        // Считывая очередную строку, сразу проверяем, не NULL-овая ли она
        while (fgets(current_line, 130, clients_in) != NULL) {

            // Название услуги и её id
            char name[STR_LEN * 3], id[STR_LEN];

            // Зануляем все байты в строках
            memset(name, 0, STR_LEN * 3);
            memset(id, 0, STR_LEN);

            char* name_ptr = name, * id_ptr = id, * ptr = current_line;

            // Блок для обработки очередной строки
            {
                // Пока не дошли до 1 запятой, считываем ФИО
                while (*ptr != ',') *name_ptr++ = *ptr++;

                while (*ptr == ',' || *ptr == ' ') ptr++; // Чтобы пропустить запятую или пробел

                // Пока не дошли до 2 запятой, считываем номер
                while (*ptr != ',') *id_ptr++ = *ptr++;
            }

            // Добавляем пару "Ключ - значение" в map
            services.insert({ id, name });
        }
        fclose(clients_in);
    }

    // Создаем поток для вывода
    ofstream out("Report.txt");

    // Если нет данных, так и пишем
    if (customers.empty()) {
        // Нет данных
        out << "No data" << endl;
    }

    // Если есть, выводим их
    else {

        // Проходим по списку клиентов
        for (int i = 0; i < customers.size(); i++) {
            out << customers[i].number << endl;
            out << "Services:" << endl;

            cout << customers[i].number << endl;
            cout << "Services:" << endl;

            // Проходим по списку услуг клиента
            for (int j = 0; j < customers[i].services.size(); j++) {

                // Обращаемся к map, чтобы получить название услуги по id
                out << "\t" << services[customers[i].services[j]] << endl;
                cout << "\t" << services[customers[i].services[j]] << endl;
            }
        }
    }
    out.close();
}