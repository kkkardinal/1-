#include <iostream>
#include <string>

using namespace std;

struct Node {
    string surname, street, number;
   
    Node* next;
    Node* prev;
};

Node* first(string surname, string street, string number);
void add(Node** pend, string surname, string street, string number);
Node* find(Node* const pbeg, string surname, string street, string number);
Node* insert(Node* const pbeg, Node** pend, string surname, string street, string number, string surname1, string street1, string number1);
Node* insertpered(Node** pbeg, Node* const pend, string surname, string street, string number, string surname1, string street1, string number1);
Node* find1(Node* const pend, string surname, string street, string number);
void add_sort(Node** pbeg, Node** pend, string surname, string street, string number);// добавляет в середину, исходя из упорядочивания фамилий по алфавиту
void seredina(struct Node* start, Node** pbeg, Node** pend, string surname, string street, string number, Node* pp);
bool remove(Node** pbeg, Node** pend, string surname, string street, string number);
bool remove1(Node** pend);
bool remove2(Node** pbeg);
Node* Remove3(Node*& pp, int n);
Node* removec(struct Node* start, Node*& pbeg);


void  display(struct Node* start) {
    while (start) {
        cout  << start->surname << " " << start->street << " " << start->number<< "\n";
       
        start = start->next;
    } 
}
int  kolichestvo(struct Node* start) {
    int kol = 0;
    while (start) {
        kol++;
        start = start->next;
    }
    return kol;
}
void menu() {
    cout << "Выберите действие:" << "\n";
    cout << "1. Новый элемент в конец списка" << endl << "2. Новый элемент на заданное место" << endl << "3. новый элемент после элемента с заданной нформацией" << endl
        << "4. новый элемент до элемента с заданной нформацией" << endl << "5. Добавить новый элемент в середину списка" << endl << "6. Исключить элемент из середины:" << endl
        << "7. Исключить элемент с заданной информацией" << endl << "8. Исключить элемент из конца списка" << endl
        << "9. Исключить элемент из заданного места списка" << endl << "10. Исключить элемент из начала списка" << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
  
    menu();
    Node* u = new Node;
    Node* pbeg = first("Petrov", "Chehova", "23");
    Node* pend = pbeg;
    int i;

    cin >> i;
    while (i != 12) {

        switch (i) {
        case 1:
            int kol;
            cout << "Введите количество элементов, которое хотите добавить:";
            cin >> kol;
            cout << endl;
            for (int j = 0; j < kol; j++) {
                string n1, s1, nu1;
                cin >> n1;
                cin >> s1;
                cin >> nu1;
                
                add(&pend, n1, s1, nu1);

            }
            display(pbeg);
            cout << endl << "(0) Назад в меню (12) Закрыть программу\n";
            cin >> i;
            break;
        case 2:
            
            cout << "Введите элемент: ";
            
            cout << endl;
            for (int j = 0; j < 1; j++) {
                string n1, s1, nu1;
                cin >> n1;
                cin >> s1;
                cin >> nu1;
                
                add_sort(&pbeg, &pend, n1, s1, nu1);
            }
            display(pbeg);
            cout << endl << "(0) Назад в меню (12) Закрыть программу\n";
            cin >> i;
            break;
        case 3:
            
            cout << "Введите элементы, после которых надо выполнить вставку, а затем вставляемые элементы: ";
         
            cout << endl;
            for (int j = 0; j < 1; j++) {
                string n1, s1, nu1, n2, s2, nu2;
                cin >> n1;
                cin >> s1;
                cin >> nu1;
                cin >> n2;
                cin >> s2;
                cin >> nu2;
                
                insert(pbeg, &pend, n1, s1, nu1, n2, s2, nu2);

            }
            display(pbeg);
            cout << endl << "(0) Назад в меню (12) Закрыть программу\n";
            cin >> i;
            break;
        case 4:
          
            cout << "Введите элементы, до которых надо выполнить вставку, а затем вставляемые элементы: ";
          
            cout << endl;
            for (int j = 0; j < 1; j++) {
                string n1, s1, nu1, n2, s2, nu2;
                cin >> n1;
                cin >> s1;
                cin >> nu1;
                cin >> n2;
                cin >> s2;
                cin >> nu2;
                
                 insertpered(&pbeg, pend, n1, s1, nu1, n2, s2, nu2);
            }
            display(pbeg);
            cout << endl << "(0) Назад в меню (12) Закрыть программу\n";
            cin >> i;
            break;
        case 5:
            cout << "Введите элемент: ";

            cout << endl;
            for (int j = 0; j < 1; j++) {
                string n1, s1, nu1;
                cin >> n1;
                cin >> s1;
                cin >> nu1;
              
                seredina(pbeg, &pbeg, &pend,n1, s1, nu1, pbeg); 
            }
            display(pbeg);
            cout << endl << "(0) Назад в меню (12) Закрыть программу\n";
            cin >> i;
            break;
        case 6:
            removec(pbeg, pbeg);
            display(pbeg);
            cout << endl << "(0) Назад в меню (12) Закрыть программу\n";
            cin >> i;
            break;
        case 7:
            cout << "Введите элемент: ";

            cout << endl;
            for (int j = 0; j < 1; j++) {
                string n1, s1, nu1;
                cin >> n1;
                cin >> s1;
                cin >> nu1;
                
               remove(&pbeg, &pend, n1, s1, nu1); 
            }
            display(pbeg);
            cout << endl << "(0) Назад в меню (12) Закрыть программу\n";
            cin >> i;
            break;
        case 8:
            remove1(&pend);
            display(pbeg);
            cout << endl << "(0) Назад в меню (12) Закрыть программу\n";
            cin >> i;
            break;
        case 9:
            int n;
            
            cout << "укажите номер строки, которую хотите удалить:" << endl;
            cin >> n;
            Remove3(pbeg, n);
            display(pbeg);
            cout << endl << "(0) Назад в меню (12) Закрыть программу\n";
            cin >> i;
            break;
        case 10:
            remove2(&pbeg);
            display(pbeg);
            cout << endl << "(0) Назад в меню (12) Закрыть программу\n";
            cin >> i;
            break;
            cout << endl << endl;
        case 0:
            menu();
            cin >> i;
            break;
        
      
            
            
        }
       Node* pv = pbeg;
        while (pv) {
            cout << pv->surname << " " << pv->street << " " << pv->number << "\n";
            pv = pv->next;
        }
        
    }
    return 0;
}

void seredina(struct Node* start, Node** pbeg, Node** pend, string surname, string street, string number, Node* pp) {

    int kol = kolichestvo(start);
    int n = (kol / 2);
    Node* pv = new Node;
    Node* toInsert = new Node();

    // Указатель на текущий элемент
    for (pv = pp; pv != NULL && n != 0; pv = pv->next, n--); // Отсчитать n -ый

    toInsert->surname = surname;
    toInsert->street = street;
    toInsert->number = number;
    toInsert->next = pv->next;
    toInsert->prev = pv;
    pv->next->prev = toInsert;
    pv->next = toInsert;

}
  

Node* first(string surname, string street, string number) {
    Node* pv = new Node;
    pv->surname = surname;
    pv->street = street;
    pv->number = number;
  
    pv->next = 0;
    pv->prev = 0;
    return pv;
}
//добавление в конец списка
void add(Node** pend, string surname, string street, string number) {
    Node* pv = new Node;
   

    pv->surname = surname;
    pv->street = street;
    pv->number = number;
    cout << "\n";
    pv->next = 0;
    pv->prev = *pend;
    (*pend)->next = pv;
    *pend = pv;
   
}

//поиск элемента по ключу

Node* find(Node* const pbeg, string surname, string street, string number) {
    Node* pv = pbeg;
    while (pv) {
        if (pv->surname == surname) break;
        if (pv->street == street) break;
        if (pv->number == number) break;
        pv = pv->next;
    }
    return pv;
}
Node* find1(Node* const pend, string surname, string street, string number) {
    Node* pv = pend;
    while (pv) {
        if (pv->surname == surname) break;
        if (pv->street == street) break;
        if (pv->number == number) break;
        pv = pv->prev;
    }
    return pv;
}

//вставка элемента
Node* insert(Node* const pbeg, Node** pend, string surname, string street, string number, string surname1, string street1, string number1) {
    if (Node* pkey = find(pbeg, surname, street, number)) {
        Node* pv = new Node;

        pv->surname = surname1;
        pv->street = street1;
        pv->number = number1;
        pv->next = pkey->next;

        pv->prev = pkey;

        pkey->next = pv;

        if (pkey != *pend) (pv->next)->prev = pv;

        else *pend = pv;
        return pv;
    }
    return 0;
}
Node* insertpered(Node** pbeg, Node* const pend, string surname, string street, string number, string surname1, string street1, string number1) {
    if (Node* pkey = find1(pend, surname, street, number)) {
        Node* pv = new Node;
        pv->surname = surname1;
        pv->street = street1;
        pv->number = number1;
        pv->prev = pkey->prev;
        pv->next = pkey;

        pkey->prev = pv;


        if (pkey != *pbeg) (pv->prev)->next = pv;

        else *pbeg = pv;
        return pv;
    }
    return 0;
}
//заданное место



 void add_sort(Node** pbeg, Node** pend, string surname, string street, string number) {//surname
     Node* pv = new Node;
     pv->surname = surname;
     pv->street = street;
     pv->number = number;
     Node* pt = *pbeg;
     while (pt) {
         if (surname < pt->surname) {
             pv->next = pt;
             if (pt == *pbeg) {
                 pv->prev = 0;
                 *pbeg = pv;
             }
             else {
                 (pt->prev)->next = pv;
                 pv->prev = pt->prev;
             }
             pt->prev = pv;
             return;
         }
         pt = pt->next;
     }
     pv->next = 0;
     pv->prev = *pend;
     (*pend)->next = pv;
     *pend = pv;
 }
//удаление элемента

bool remove(Node** pbeg, Node** pend, string surname, string street, string number) {
    if (Node* pkey = find(*pbeg, surname, street, number)) {
        if (pkey == *pbeg) {
            *pbeg = (*pbeg)->next;
            (*pbeg)->prev = 0;
        }
        else if (pkey == *pend) {
            *pend = (*pend)->prev;
            (*pend)->next = 0;
        }

        else {
            (pkey->prev)->next = pkey->next;
            (pkey->next)->prev = pkey->prev;
        }

        delete pkey;
        return true;
    }
    return false;
}
bool remove1( Node** pend) {
    if (Node* pkey = *pend) {
         if (pkey == *pend) {
            *pend = (*pend)->prev;
            (*pend)->next = 0;
        }

        delete pkey;
        return true;
    }
    return false;
}
bool remove2(Node** pbeg) {
    if (Node* pkey = *pbeg) {
        if (pkey == *pbeg) {
            *pbeg = (*pbeg)->next;
            (*pbeg)->prev = 0;
        }

        delete pkey;
        return true;
    }
    return false;
}
Node* Remove3(Node*& pp, int n)

{
    Node* q;                                                            // Указатель на текущий элемент
    for (q = pp; q != NULL && n != 0; q = q->next, n--);   // Отсчитать n -ый
    if (q == NULL) return NULL;                                  // нет элемента с таким номером
    if (q->prev == NULL)                                           // удаление первого -
        pp = q->next;                                           // коррекция заголовка
    else     q->prev->next = q->next;                        // следующий для предыдущего  =                     // следующий за текущим
    if (q->next != NULL)                                            // удаление не последнего 
    q->next->prev = q->prev;             // предыдущий для следующего  =                 
    return q;
}
Node* removec(struct Node* start, Node*& pbeg) {
    int kol = kolichestvo(start);
    int n = (kol / 2);
    Remove3(pbeg, n);
    return 0;
}