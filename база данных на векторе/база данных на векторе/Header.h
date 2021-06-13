#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<windows.h>
#include<string>
#include<algorithm>
using namespace std;
struct Stadion
{
	string name;
	string vid;
	int year;
	string adres;
	int vmestimost;
	int col_vo;
	string vid_tab;
};
struct Data
{
	Stadion stad;
};
void Data_input(vector<Data> &vec);
void Data_out(vector<Data> vec);
void Data_change(vector<Data> &vec);
void Data_erase(vector<Data> &vec);
void Data_del_all(vector<Data> &vec);
void Data_save(vector<Data> vec);
void Data_read(vector<Data> &vec);
void Copy_for_sort(Data &(d_new), Data &(d_old));
void Data_sort(vector<Data> &vec);