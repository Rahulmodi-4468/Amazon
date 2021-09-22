#include<iostream>
#include <string>
#include<fstream>
using namespace std;
class SubCategory
{

	string SubCat_Name;
public:
	void Add_SubCategory();
	void Delete_SubCategory(string name);
	void Print();
};
void SubCategory::Add_SubCategory() {

	cout << "List of Category : \n";
	ifstream read("Category.txt");
	string temp;
	while (getline(read, temp)) {
		cout << temp << endl;
	}
	read.close();

	cout << "\nEnter Your Choice : ";
	int take;
	cin >> take;

	cin.ignore();
	cout << "\nEnter Sub-Category Name : ";
	getline(cin, SubCat_Name);

	ifstream read1("SubCategory.txt");
	int count = 1;
	string line;
	while (getline(read1, line))
		count++;
	read1.close();

	ofstream write;
	write.open("SubCategory.txt", ios::app);
	write << "SC" << count << " " << SubCat_Name << " " << "C" << take << endl;
	write.close();

}
void SubCategory::Delete_SubCategory(string name) {
	ifstream read("SubCategory.txt");
	string s, s1;
	while (!read.eof())
	{
		read >> s >> s1;
		if (s1 == name) {
		}
	}
}
void SubCategory::Print() {
	//cout<<Brand_ID<<" "<<Brand_Name;

	ifstream read("SubCategory.txt");
	string temp;
	while (getline(read, temp)) {
		cout << temp << endl;
	}
	read.close();
}
