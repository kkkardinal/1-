#include <iostream>
#include <fstream>
using namespace std;

struct Stack {
	char c; 
	Stack* next; 

};
int Prior(char);
	Stack* pop(Stack*, char);
	Stack* push(Stack*, char*);
int main()
{
	Stack* t, * Op = NULL; 
	char a, In[50], Out[50]; 
	int k = 0, l = 0;


	FILE* input;
	fopen_s(&input, "input.txt", "r");
	fgets(In, 50, input);
	fclose(input);

	while (In[k] != '\0') {
		
		if (In[k] >= '0' && In[k] <= '9') {

			
			if (In[k + 1] == '+' || In[k + 1] == '-' || In[k + 1] == '/' || In[k + 1] == '*' || In[k + 1] == '('
				|| In[k + 1] == ')')
			{
				Out[l++] = In[k];	
				Out[l++] = ' ';
				
			}
			else {
			Out[l++] = In[k];			
			}

		}

		
		if (In[k] == '(') {
			Op = pop(Op, In[k]);
		}
		
		if (In[k] == ')') {
			while ((Op->c) != '(') {
				
				Op = push(Op, &a);
				if (!Op) {
					a = '\0';
				}
				
				Out[l++] = a;
			}
			
			t = Op;
			Op = Op->next;
			delete t;
		}
		
		if (In[k] == '+' || In[k] == '-' || In[k] == '*' || In[k] == '/') {
			while (Op != NULL && Prior(Op->c) >= Prior(In[k])) {
				Op = push(Op, &a);
				Out[l++] = a;
			}
			Op = pop(Op, In[k]); 
		}
		k++;
	}
	while (Op != NULL) {//если стек не пуст, извлекаем и записываем операции в выходную строку
		Op = push(Op, &a);
		Out[l++] = a;
	}
	Out[l] = '\0';

	ofstream out("output.txt");
	out << Out << endl;
	out.close();
}


int Prior(char a) {
	switch (a) {
	case'*': case'/': return 3;
	case'+': case'-': return 2;
	case'(': return 1;
	}
	return 0;
}
Stack* pop(Stack* p, char s) { //принимает указатль на вершину стека и переменную которая будет записываться в ячейку
	Stack* t = new Stack; 
	t->c = s; 
	t->next = p; 
	return t;
}
Stack* push(Stack* p, char* s) {  
	Stack* t = p; 
	*s = p->c; 
	p = p->next; 
	delete t; 
	return p;
}