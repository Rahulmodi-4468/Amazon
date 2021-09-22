#include<iostream>
#include <string>
#include<fstream>
using namespace std;
class Product
{
	string Pro_Name;
	string Pro_DESC;
	int Pro_Price;
	int Pro_Stock;
public:
	void Add_Product();
	void Delete_Product(string name);
	void Print();
};

void Product::Add_Product() {

	cout << "Enter Product Name : ";
	cin >> Pro_Name;
	//cin.ignore();
	cout << "Enter Product Description : ";
	cin >> Pro_DESC;
	//cin.ignore();
	cout << "Enter Product Price : ";
	cin >> Pro_Price;

	cout << "Enter Product Stock : ";
	cin >> Pro_Stock;

	ifstream read("Product.txt");
	int count = 1;
	string line;
	while (getline(read, line))
		count++;
	read.close();

	ofstream write;
	write.open("Product.txt", ios::app);
	write << "P" << count << " " << Pro_Name << " " << Pro_DESC << " " << Pro_Price << " " << Pro_Stock << endl;
	write.close();

}
void Product::Delete_Product(string name) {
	ifstream read("Product.txt");
	string s, s1;
	while (!read.eof())
	{
		read >> s >> s1;
		if (s1 == name) {
		}
	}
}
void Product::Print() {
	//cout<<Brand_ID<<" "<<Brand_Name;

	ifstream read("Product.txt");
	string temp;
	while (getline(read, temp)) {
		cout << temp << endl;
	}
	read.close();
}
/*
class Product
{
	string Pro_Name;
	string Pro_DESC;
	int Pro_Price;
	int Pro_Stock;
	int Brand_ID;
	public:
		void Add_Product();
		void Delete_Product(string name);
		void Print();
};
void Product :: Add_Product(){

	cout<< "Enter Product Name : ";
	getline(cin,Pro_Name);
	//cin.ignore();
	cout<< "Enter Product Description : ";
	getline(cin,Pro_DESC);
	//cin.ignore();
	cout<< "Enter Product Price : ";
	cin>>Pro_Price;
	//cin.ignore();
	cout<< "Enter Product Stock : ";
	cin>>Pro_Stock;
	cout<< "Enter Brand ID : ";

	ifstream read("Brand.txt");

	string temp;
	while(getline(read, temp)){
		cout<<temp<<endl;
	}
	read.close();

	cin>>Brand_ID;
	//cin.ignore();

	ifstream read1("Product.txt");
	int count=1;
	string line;
	while (getline(read1, line))
		count++;
	read1.close();

	ofstream write;
	write.open("Product.txt", ios::app);
	write<<"P"<<count<<" "<<Pro_Name<<" "<<Pro_DESC<<" "<<Pro_Price<<" "<<Pro_Stock<<"B"<<Brand_ID<<endl;
	write.close();

}
void Product :: Delete_Product(string name){
	ifstream read("Product.txt");
	string s,s1;
	while(!read.eof())
	{
		read>>s>>s1;
		if(s1 == name){
		}
	}
}
void Product :: Print(){
	//cout<<Brand_ID<<" "<<Brand_Name;

	ifstream read("Product.txt");
	string temp;
	while(getline(read, temp)){
		cout<<temp<<endl;
	}
	read.close();
}

int main(){
	Product p;
	for(int i=0;i<2;i++){
		Product p;
		p.Add_Product();
	}
	p.Print();
}*/
