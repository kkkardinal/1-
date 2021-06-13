#include "Header.h"

void Data_input(vector<Data> &vec)
{
	Data Data1;
	int a=1;
	while (a == 1) {
		cout << "��� - "; 
		cin >> Data1.stad.name;
		cout << "��� - ";
		cin >> Data1.stad.vid;
		cout << "��� ��������� - ";
		cin >> Data1.stad.year;
		cout << "����� - ";
		cin >> Data1.stad.adres;
		cout << "����������� - ";
		cin >> Data1.stad.vmestimost;
		cout << "���������� �������� - ";
		cin >> Data1.stad.col_vo;
		int y;
		cout << "�������� ��� ����� 1-��������, 2-�������� - ";
			cin >> y;
		switch (y)
		{
		case 1:
			Data1.stad.vid_tab = "��������";
			break;
		case 2:
			Data1.stad.vid_tab = "��������";
			break;
		default:
			Data1.stad.vid_tab = "��������������_���";
			break;
		}
		//cin >> Data1.stad.vid_tab;
		vec.push_back(Data1);
		cout << "____________________________________________" << endl;
		cout << "���������� 1-�� 0-���"<<endl;
		cin >> a;
	}
}
void Data_out(vector<Data> vec)
{
	vec.shrink_to_fit();
	if (vec.size() != 0) {
		for (int i = 0; i < vec.size(); i++) {
			cout << "������� �(" << i + 1 << ") "<<endl;
			cout <<"��� - "<<vec[i].stad.name << endl;
			cout <<"��� - " <<vec[i].stad.vid << endl;
			cout <<"��� ��������� - "<< vec[i].stad.year << endl;
			cout <<"����� - "<< vec[i].stad.adres << endl;
			cout <<"����������� - "<< vec[i].stad.vmestimost << endl;
			cout <<"���������� �������� - "<< vec[i].stad.col_vo << endl;
			cout <<"��� ����� - "<< vec[i].stad.vid_tab << endl;
			cout << "____________________________________________" << endl;
		}
	}
	else
		cout << "������ ��������. �����!" << endl;
}
void Data_change(vector<Data> &vec)
{
	if (vec.size() != 0) {
		int t;
		cout << "������� � �������� ������ �� 1 �� (" << vec.size() << ")";
		cin >> t;
		if (t <= vec.size() && t > 0) {
			t = t - 1;
			//vec.erase(vec.begin() + t);
			cout << "��� - ";
			cin >> vec[t].stad.name;
			cout << "��� - ";
			cin >> vec[t].stad.vid;
			cout << "��� ��������� - ";
			cin >> vec[t].stad.year;
			cout << "����� - ";
			cin >> vec[t].stad.adres;
			cout << "����������� - ";
			cin >> vec[t].stad.vmestimost;
			cout << "���������� �������� - ";
			cin >> vec[t].stad.col_vo;
			cout << "��� ����� - ";
			cin >> vec[t].stad.vid_tab;
		}
		else cout << "������ �����" << endl;
	}
	else cout << "������ �����" << endl;
}
void Data_erase(vector<Data> &vec)
{
	if (vec.size() != 0) {
		int t;
		cout << "������� � �������� ��� �������� �� 1 �� (" << vec.size() << ")";
		cin >> t;
		if (t <= vec.size() && t > 0) {
			t = t - 1;
			vec.erase(vec.begin() + t);
		}
		else
			cout << "������ �����";
	}
	else
		cout << "������ �����"<<endl;
}
void Data_del_all(vector<Data> &vec)
{
	int t;
	cout << "�� �������? 1-��, 0-�����! - ";
	vec.shrink_to_fit();
	cin >> t;
	switch (t)
	{
	case 1:
		int m;
		m = vec.size();
		for (int i = 0; i < m; i++) {
			//1cout <<"������ - "<<vec.size()<<endl;
			vec.erase(vec.begin());
		}
		break;
	case 0:

		break;
	default:
		cout << "������ �����"<<endl;
		break;
	}
}
void Data_save(vector<Data> vec)
{
	cout << "����� ��� ����� ��� ���������� ������ � .txt";
	string filename;
	cin >> filename;
	ofstream save(filename, ios::out);
	vec.shrink_to_fit();
	save << vec.size();
	for (int i = 0; i < vec.size(); i++) {
		save << vec[i].stad.name << endl;
		save << vec[i].stad.vid << endl;
		save << vec[i].stad.year << endl;
		save << vec[i].stad.adres << endl;
		save << vec[i].stad.vmestimost << endl;
		save << vec[i].stad.col_vo << endl;
		if (i + 1 != vec.size()) {
			save << vec[i].stad.vid_tab << endl;
		}
		else
			save << vec[i].stad.vid_tab;
	}
	save.close();
}
void Data_read(vector<Data> &vec)
{
	string filename,f;
	cout << "����� ��� ����� � .txt _ ";
	cin >> filename;
	ifstream read(filename);
	int t;
	if (read) {
		read >> t;
		for (int i = 0; i < t; i++) {
			Data *data = new Data[t];
			read >> data[i].stad.name;
			read >> data[i].stad.vid;
			read >> data[i].stad.year;
			read >> data[i].stad.adres;
			read >> data[i].stad.vmestimost;
			read >> data[i].stad.col_vo;
			read >> data[i].stad.vid_tab;
			vec.push_back(data[i]);
			delete[]data;
		}
	}
	else
		cout << "������ ������ �����"<<endl;
}
void Copy_for_sort(Data &(d_new), Data &(d_old)) {
	d_new.stad.name = d_old.stad.name;
	d_new.stad.vid = d_old.stad.vid;
	d_new.stad.year = d_old.stad.year;
	d_new.stad.adres = d_old.stad.adres;
	d_new.stad.vmestimost = d_old.stad.vmestimost;
	d_new.stad.col_vo = d_old.stad.col_vo;
	d_new.stad.vid_tab = d_old.stad.vid_tab;
}
void Data_sort(vector<Data> &vec)
{
	if (vec.size() != 0) {
		Data NEW;
		int n;
		vec.shrink_to_fit();
		n = vec.size();
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (vec[i].stad.year > vec[j].stad.year) {
					Copy_for_sort(NEW, vec[j]);
					Copy_for_sort(vec[j], vec[i]);
					Copy_for_sort(vec[i], NEW);
				}
			}
		}
		cout << "������ �������������" << endl;
	}
	else
		cout << "������ �����" << endl;
}