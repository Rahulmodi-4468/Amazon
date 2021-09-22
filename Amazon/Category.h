#include<iostream>
#include <string>
#include<fstream>
using namespace std;
class Category
{
	string Cat_Name;
public:
	void Add_Category();
	void Delete_Category(string name);
	void Print();
};
void Category::Add_Category() {

	cout << "Enter Category Name : ";
	cin >> Cat_Name;
	//getline(cin,Cat_Name);
	//cin.ignore();
	ifstream read("Category.txt");
	int count = 1;
	string line;
	while (getline(read, line))
		count++;
	read.close();

	ofstream write;
	write.open("Category.txt", ios::app);
	write << "C" << count << " " << Cat_Name << endl;
	write.close();

}
void Category::Delete_Category(string name) {
	ifstream read("Category.txt");
	string s, s1;
	while (!read.eof())
	{
		read >> s >> s1;
		if (s1 == name) {
		}
	}
}
void Category::Print() {
	//cout<<Brand_ID<<" "<<Brand_Name;

	ifstream read("Category.txt");
	string temp;
	while (getline(read, temp)) {
		cout << temp << endl;
	}
	read.close();
}

