#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int const size = 1000000;
	int temp=0;
	int* array = new int[size];
	ofstream fout1("input.txt");
	for (int i = 0; i < size; i++) {
		array[i] = rand()%5000;
		fout1 << array[i] << "\t";
	}
	fout1.close();

	for (int i = 0; i < size; i++) {

		for (int j = 0; j < size-1; j++) {
			if (array[j] > array[j + 1]) {
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
	
	
	ofstream fout("output.txt");
	for (int i = 0; i < size; i++) {
		fout << array[i] << "\t";
	}
	fout.close();
	return 0;
}

