#include<iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

enum { EX = 0,PRD_ADD,PRD_INFO};
enum { BOOK = 1,CD,CELLPHONE };


class Product
{
private:
	int price;
	string description;
public:
	Product(string description, int price) 
		:price(price),description(description)
	{}
	virtual void getProduct() {}	//	상품 출력함수

};

class Book : public Product
{
private:
	string title;
	string writer;
	string publisher;
	string description;
	int price;

	Product* pobj[100];
	static int idx;

public:
	Book(string title, string writer, string publisher, string description, int price)
		: title(title), writer(writer), publisher(publisher), Product(description,price)
	{	
		
	}

	Book(Book& ref) 
		: title(ref.title), writer(ref.writer), publisher(ref.publisher), Product(ref.description,ref.price)
	{	}

	void getProduct()
	{

	}

};
/*Cd cd1(, , , , );
//Cd cd2 = cd1;
//Cd cd2(cd1);
//cd2.Product::getProduct();
int n1,n2,n3;
n3 = n1+n2;

Cd c1,c2,c3;
c3 = c1+c2;

*/
class Cd : public Product
{
private:
	string title;
	string singer;
	string description;
	int price;

public:
	Cd(string title, string singer,string description, int price)
		: title(title), singer(singer), Product(description, price)
	{ 
		
	}
	Cd(Cd& ref) 
		: title(ref.title), singer(ref.singer), Product(ref.description, ref.price)
	{ }
	~Cd()
	{
		
	}


};

class Cellphone : public Product
{
	string phon_name;
	string description;
	int price;


public:
	Cellphone(string pname, string description, int price)
		:phon_name(pname), Product(description, price)
	{	}
};

class BookHandler
{
	Product* pobj[100];
	static int idx;

public:


	void Book_put()
	{
		string title;
		string writer;
		string publisher;
		string description;
		int price;

		cout << "Title : ";
		cin >> title;
		cout << endl;

		cout << "Writer : ";
		cin >> writer;
		cout << endl;

		cout << "Publisher : ";
		cin >> publisher;

		cout << "Price : ";
		cin >> price;
		cout << endl;

		cout << "Description : ";
		cin >> description;
		cout << endl;


		pobj[idx++] = new Book(title, writer, publisher, description, price);
		
		cout << idx << endl;
		//pobj[pnum++] = new Cd( writer, publisher, description, price);
	}


	/*void Cd_put()
	{
		string title;
		string singer;
		int price;
		cout << "Title : ";
		cin >> title;
		cout << endl;

		cout << "Singer : ";
		cin >> singer;
		cout << endl;

		cout << "Price : ";
		cin >> price;
		cout << endl;

		pobj[pnum++] = new Cd(title, singer,price);
	}

	void CPhone_Info()
	{
		string phon_name;
		int price;

		cout << "Product_code : ";
		cin >> phon_name;
		cout << endl;

		cout << "Price : ";
		cin >> price;
		cout << endl;


		pobj[pnum++] = new Cellphone(phon_name, price);
	}*/

};
int BookHandler::idx = 0;



//class ProductADD
//{
//	Product* pobj_add;
//public:
//	void Book_put()
//	{
//		string title;
//		string writer;
//		string publisher;
//		string description;
//		int price;
//
//		cout << "Title : ";
//		cin >> title;
//		cout << endl;
//
//		cout << "Writer : ";
//		cin >> writer;
//		cout << endl;
//
//		cout << "Publisher : ";
//		cin >> publisher;
//
//		cout << "Price : ";
//		cin >> price;
//		cout << endl;
//
//		cout << "Description : ";
//		cin >> description;
//		cout << endl;
//
//
//		pobj_add = new Book(title, writer, publisher, description, price);
//		//pobj[pnum++] = new Cd( writer, publisher, description, price);
//		
//
//	}
//
//
//
//};


int main()
{
	int choice ;
	int cho;
	BookAdd handle;
	while (1)
	{
		handle.Menu();
		cout << "->";
		cin>> choice;
		cout << endl;
		switch (choice)
		{
		case PRD_ADD:
			while (1)
			{
				cout << "상품 추가" << endl;
				handle.menu();
				cout << "->";
				cin >> cho;
				cout << endl;
				switch (cho)
				{
				case BOOK:
					handle.Book_put();
					break;
				case CD:
					break;
				case CELLPHONE:
					break;

				default:
					break;
				}
			}
			break;
		case PRD_INFO:
			cout << "상품 조회" << endl;
			handle.menu();
			break;
		case EX:
			exit(1);
		default:
			break;
		}
	}
	
	return 0;
}