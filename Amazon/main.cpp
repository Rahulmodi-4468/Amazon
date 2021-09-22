#include<iostream>
#include <string>
#include<fstream>
#include "Category.h"
#include "SubCategory.h"
#include "Product.h"
using namespace std;

int main() {
	cout << "\n-------------------------------Wellcome---------------------------------" << endl;
	cout << "------------------------------------------------------------------------" << endl;
	cout << "UserSide  - Display Categories->Sub Categories->Product's : Press D|d  " << endl;
	cout << "AdminSide - Manipulate Category-->Sub Category-->Products : Press M|m  " << endl;
	cout << "Registeration | Login : Press R|r : " << endl;
	cout << "------------------------------------------------------------------------" << endl;
	char ch;
	cout << "Enter Your Choice : ";
	cin >> ch;
	if (ch == 'D' || ch == 'd')
	{
	comb:
		cout << "\n-------------------------------------------\n";
		cout << "            Display Categories : ";
		cout << "\n-------------------------------------------\n";
		Category c;
		c.Print();

		cout << "Choose Any One : ";
		string choice;
		cin >> choice;
		ifstream ifs("SubCategory.txt");

		string line;
		bool flag = false;

		while (getline(ifs, line))
		{
			size_t pos = line.find(choice);
			if (pos != string::npos)
			{
				cout << line << endl;
				//ask = true;
			}
			else {
				flag = true;
			}
		}
		if (flag == true)
		{
			cout << "Record Not Found " << endl;
		}


		cout << "Choose Any One : ";
		string choice1;
		cin >> choice1;
		ifstream ifs1("Product.txt");

		string line1;
		bool flg1 = false;
		bool ask = false;
		while (getline(ifs1, line1))
		{
			size_t pos = line1.find(choice1);
			if (pos != string::npos)
			{
				cout << line1 << endl;
				ask = true;
			}
			else {
				flg1 = true;
				ask = true;
			}
		}
		if (flg1 == true)
		{
			cout << "Record Not Found" << endl;
		}
		if (ask == true) {
			cout << "\n-------------------------------------------\n";
			cout << "   Press p|P for Previous Menu " << endl;
			cout << "   Press Any Key to Return to main Menu";
			cout << "\n-------------------------------------------\n";

			char ch;
			cin >> ch;
			if (ch == 'P' || ch == 'p')
				goto comb;
			else
				main();
		}

	}
	else if (ch == 'M' || ch == 'm') {
	ManipulatBack:
		cout << "\n-------------------------------------------\n";
		cout << "   Manipulate Category Press C|c : " << endl;
		cout << "   Manipulate Sub-Category Press S|s : " << endl;
		cout << "   Manipulate Product Press P|p : ";
		cout << "\n-------------------------------------------\n";
		cout << " Enter Your Choice : ";
		char ch;
		cin >> ch;
		if (ch == 'C' || ch == 'c')
		{
		CatBack:
			cout << "\n-------------------------------------------\n";
			cout << "   Add New Category - Press A|a : " << endl;
			cout << "   Delete Category - Press D|d : " << endl;
			cout << "   View Category - Press V|v : ";
			cout << "\n-------------------------------------------\n";
			cout << " Enter Your Choice : ";
			char ch;
			cin >> ch;
			if ((ch == 'A') || (ch == 'a')) {

				char ch;
				do {
					Category c;
					c.Add_Category();
					cout << "\n-------------------------------------------\n";
					cout << "   You Want Add More Category Press Y|y : " << endl;;
					cout << "   Previous Menu -Press N|n : ";
					cout << "\n-------------------------------------------\n";
					cin >> ch;
				} while (ch == 'y' || ch == 'Y');

				if (ch == 'N' || ch == 'n') {
					goto CatBack;
				}

			}
			else if (ch == 'D' || ch == 'd') {
				char ch;
				do {
					cout << "\n-------------------------------------------\n";
					cout << "  Delete Category - Press Y|y : " << endl;
					cout << "  Previous Menu - Press N|n : ";
					cout << "\n-------------------------------------------\n";
					cin >> ch;
					Category c;
					//c.Delete_Product(string name);
				} while (ch == 'Y' || ch == 'y');


				if (ch == 'N' || ch == 'n') {
					goto CatBack;
				}
			}
			else if ((ch == 'V') || (ch == 'v')) {
				Category c;
				cout << "\nDisplay Available Categories " << endl;
				cout << "--------------------------------" << endl;
				cout << "CID CategoryName" << endl;
				c.Print();
				char ch;
				cout << "\n-------------------------------------------\n";
				cout << "   Previous Menu - Press Y|y : " << endl;
				cout << "   Main Menu - Press Any Key except Y|y : ";
				cout << "\n-------------------------------------------\n";
				cout << "Enter Your Choice : ";
				cin >> ch;
				if (ch == 'Y' || ch == 'y') {
					goto CatBack;
				}
				else {
					goto ManipulatBack;
				}
			}
			else {
				cout << "Enter Valid Choice ";
				goto CatBack;
			}
		}
		else if ((ch == 'S') || (ch == 's'))
		{
		SubCatBack:
			cout << "\n-------------------------------------------\n";
			cout << "   Add New Sub-Category - Press A|a : " << endl;
			cout << "   Delete Sub-Category - Press D|d : " << endl;
			cout << "   View Sub-Categories - Press V|v : ";
			cout << "\n-------------------------------------------\n";
			cout << "  Enter Your Choice : ";
			char ch;
			cin >> ch;
			if ((ch == 'A') || (ch == 'a')) {

				char ch;
				do {
					SubCategory s;
					s.Add_SubCategory();
					cout << "\n-------------------------------------------\n";
					cout << "  You Want Add More Sub-Category - Press Y|y : " << endl;;
					cout << "  Previous Menu - Press N|n : ";
					cout << "\n-------------------------------------------\n";
					cin >> ch;
				} while ((ch == 'y') || (ch == 'Y'));

				if ((ch == 'N') || (ch == 'n')) {
					goto SubCatBack;
				}
			}
			else if ((ch == 'D') || (ch == 'd')) {

				char ch;
				do {
					cout << "\n-------------------------------------------\n";
					cout << "   Delete Sub-Category - Press Y|y : " << endl;
					cout << "   Previous Menu - Press N|n : ";
					cout << "\n-------------------------------------------\n";
					cin >> ch;
					SubCategory s;
					//s.Delete_SubCategory(string name);
				} while ((ch == 'Y') || (ch == 'y'));


				if (ch == 'N' || ch == 'n') {
					goto SubCatBack;
				}
			}
			else if ((ch == 'V') || (ch == 'v')) {
				SubCategory s;
				cout << "\nDisplay Available Sub-Categories " << endl;
				cout << "--------------------------------" << endl;
				cout << "SID SubCategoryName CID" << endl;
				s.Print();

				char ch;
				cout << "\n-------------------------------------------\n";
				cout << "    Previous Menu - Press Y|y : " << endl;
				cout << "    Main Menu - Press Any Key except Y|y : ";
				cout << "\n-------------------------------------------\n";
				cin >> ch;
				if (ch == 'Y' || ch == 'y') {
					goto SubCatBack;
				}
				else {
					goto ManipulatBack;
				}
			}
			else {
				cout << "Enter Valid Choice ";
				goto SubCatBack;
			}
		}
		else if ((ch == 'P') || (ch == 'p'))
		{
		ProBack:
			cout << "\n-------------------------------------------\n";
			cout << "   Add New Product - Press A|a : " << endl;
			cout << "   Delete Product - Press D|d : " << endl;
			cout << "   View Product's - Press V|v : " << endl;
			cout << "   Main Menu Press Any Key except Above : ";
			cout << "\n-------------------------------------------\n";
			cout << " Enter Your Choice : ";
			char ch;
			cin >> ch;
			if ((ch == 'A') || (ch == 'a')) {

				char ch;
				do {
					Product p;
					p.Add_Product();
					cout << "\n-------------------------------------------\n";
					cout << "  You Want Add More Product - Press Y|y : " << endl;;
					cout << "  Previous Menu - Press N|n : ";
					cout << "\n-------------------------------------------\n";
					cin >> ch;
				} while ((ch == 'y') || (ch == 'Y'));

				if ((ch == 'N') || (ch == 'n')) {
					goto ProBack;
				}
			}
			else if ((ch == 'D') || (ch == 'd')) {
				char ch;
				do {
					cout << "\n-------------------------------------------\n";
					cout << "   Delete Product - Press Y|y : " << endl;
					cout << "   Previous Menu - Press N|n : ";
					cout << "\n-------------------------------------------\n";
					cin >> ch;
					Product p;
					//p.Delete_Product(string name);
				} while ((ch == 'Y') || (ch == 'y'));


				if ((ch == 'N') || (ch == 'n')) {
					goto ProBack;
				}
			}
			else if ((ch == 'V') || (ch == 'v')) {
				Product p;
				p.Print();

				char ch;
				cout << "\n-------------------------------------------\n";
				cout << "   Previous Menu - Press Y|y : " << endl;
				cout << "   Main Menu - Press Any Key except Y|y : ";
				cout << "\n-------------------------------------------\n";
				cin >> ch;
				if ((ch == 'Y') || (ch == 'y')) {
					goto ProBack;
				}
				else {
					goto ManipulatBack;
				}
			}
			else {
				cout << "Enter Valid Choice ";
				goto ProBack;
			}
		}
		else {
			cout << "\nEnter Valid Choice " << endl;
			goto ManipulatBack;
		}
	}
	else if ((ch == 'R') || (ch == 'r')) {
		cout << "Register Press 1 : " << endl;
		cout << "Login Press 2 : " << endl;
	}
	else {
		cout << "LogOut.......\nExiting........";
		exit(0);
	}
}
