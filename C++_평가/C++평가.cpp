/*
	C++ ��.c
	created : 2022. 3. 28
	Author : ������
*/


#include<iostream>
#include<vector>
#include<Windows.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

//���������� ����
enum { EX = 0,PRD_ADD,PRD_INFO, PRD_DELE};
enum { BOOK = 1,CD,CELLPHONE,ALL };

//�θ�Ŭ����
class Product
{
private:
	int price;
	string description;
public:
	//Product ������
	Product(string description, int price) 
		:price(price),description(description)
	{}
	
	//	��ǰ ����Լ�
	virtual void getProduct() {
		cout << "price : " << price << endl;
		cout << "description" << description << endl;
	}	
	//�� ��ǰ �׸�� ����
	virtual string name() { return " "; }
};

//å Ŭ����
class Book : public Product
{
private:
	string title;
	string writer;
	string publisher;
	string description;
	int price;
	
public:
	// ������ �ʱ�ȭ
	Book(string title, string writer, string publisher, string description, int price)
		: title(title), writer(writer), publisher(publisher), Product(description,price)
	{	}
	//���������
	Book(Book& ref) 
		: title(ref.title), writer(ref.writer), publisher(ref.publisher), Product(ref.description,ref.price)
	{	}

	//�׸񱸺� :: Book��ǰ ��ȸ�� ���
	string name()
	{
		return "Book";
	}
	
	//���
	void getProduct()
	{

		cout <<"Title : "<< title << endl;
		cout << "writer : "<<writer << endl;
		cout <<"publisher : "<< publisher << endl;
		Product::getProduct();

	}

};

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
		//this->v.push_back(idx);

	}
	Cd(Cd& ref) 
		: title(ref.title), singer(ref.singer), Product(ref.description, ref.price)
	{ }
	//�׸񱸺� :: CD��ǰ ��ȸ�� ���
	string name()
	{
		return "Cd";
	}
	void getProduct()
	{

		cout << "Title : " << title << endl;
		cout << "singer : " << singer << endl;
		Product::getProduct();

	}
	~Cd()
	{
		
	}

};

class Cellphone : public Product
{
	string model;
	string manufacturer;
	string description;

	int price;

public:
	Cellphone(string model, string manufacturer, 	string description,int price)
		:model(model), manufacturer(manufacturer),Product(description, price)
	{
		
	}
	void getProduct()
	{

		//��ǰ��
		cout << "Model : " << model << endl;
		//manufacturer
		cout << "Manufacturer : " << manufacturer << endl;
		Product::getProduct();

	}

	//�׸񱸺� :: Cellphone��ǰ ��ȸ�� ���
	string name()
	{
		return "Cellphone";
	}

};
//Product �ٷ�� ����ü
class ProductHandler
{
	Product* pobj[100]; //�߰��� product ������ ����ü ������ ����
	static int idx;//product �ε���
	
	vector<Product*> v;
	vector<Product*>::iterator iter;

public:
	ProductHandler()
	{	}

	//��޴�
	void Menu()
	{
		cout << "~Ȩ~" << endl;
		cout << "0. ����" << endl;
		cout << "1. ��ǰ �߰�" << endl;
		cout << "2. ��ǰ ��ȸ" << endl;
		cout << "3. ��ǰ ����" << endl;

	}

	//�Ҹ޴�
	void menu()
	{
		cout << "0. Ȩ" << endl;
		cout << "1. Book" << endl;
		cout << "2. CD" << endl;
		cout << "3. CellPhone" << endl;

	}
	//Book �߰�
	void Book_put()
	{
		string title;
		string writer;
		string publisher;
		string description;
		int price;
		cout << "===== ADD BooK Product ======" << endl;
		cout << "Title : ";
		cin >> title;
		cout << endl;

		cout << "Writer : ";
		cin >> writer;
		cout << endl;

		cout << "Publisher : ";
		cin >> publisher;
		cout << endl;

		cout << "Price : ";
		cin >> price;
		cout << endl;

		cout << "Description : ";
		cin >> description;
		cout << endl;

		pobj[idx++] = new Book(title, writer, publisher, description, price);
		v.push_back(pobj[(idx - 1)]);

	}

	//Book ��ȸ
	void Book_Info()
	{
		cout << "===== Book Product ======" << endl;

		for (int i = 0; i < idx; i++)
		{
			if (pobj[i]->name() == "Book")
			{
				pobj[i]->getProduct();
				cout << endl;
			}
			cout << endl;
		}
		
	}

	//Cd �߰�
	void Cd_put()
	{
		string title;
		string singer;
		string description;
		int price;
		cout << "===== ADD Cd Product ======" << endl;

		//����
		cout << "Title : ";
		cin >> title;
		cout << endl;
		//����
		cout << "Singer : ";
		cin >> singer;
		cout << endl;
		//����
		cout << "Price : ";
		cin >> price;
		cout << endl;
		//������
		cout << "Description : ";
		cin >> description;
		cout << endl;

		pobj[idx++] = new Cd(title, singer, description, price);
		v.push_back(pobj[(idx - 1)]);

	}

	//Cd ��ȸ
	void Cd_Info()
	{
		cout << "===== Cd Product ======" << endl;

		for (int i = 0; i < idx; i++)
		{
			if (pobj[i]->name() == "Cd")
			{
				pobj[i]->getProduct();
				cout << endl;
			}
		}
		cout << endl;
	}

	//CellPhone �߰�
	void CPhone_put()
	{
		string model;
		string manufacturer;
		string description;
		int price;
		
		cout << "===== ADD CellPhone Product ======" << endl;
		//��ǰ��
		cout << "Model : ";
		cin >> model;
		cout << endl;
		//manufacturer
		cout << "Manufacturer : ";
		cin >> manufacturer;
		cout << endl;

		//����
		cout << "Price : ";
		cin >> price;
		cout << endl;

		//������
		cout << "Description : ";
		cin >> description;
		cout << endl;


		pobj[idx++] = new Cellphone(model, manufacturer, description, price);
		v.push_back(pobj[(idx-1)]);

	}

	//CellPhone ��ȸ
	void CPhone_Info()
	{
		cout << "===== CellPhone Product ======" << endl;

		for (int i = 0; i < idx; i++)
		{
			if (pobj[i]->name() == "Cellphone")
			{
				pobj[i]->getProduct();
				cout << endl;
			}
		}
		cout << endl;
	}

	//��� ������ ��ȸ
	void ShowAllProduct()
	{
		for (int i = 0; i < idx; i++)
		{
			if (pobj[i]->name() == "Book")
			{
				cout << "Book " << endl; 
			}
			else if (pobj[i]->name() == "Cd")
			{
				cout << "Cd "  << endl;  
			}
			else if (pobj[i]->name() == "Cellphone")
			{
				cout << "Cellphone " << endl;  
			}
			cout << " ID -> " << i + 1 << endl;	//	idx + 1�� id  �ο�
			pobj[i]->getProduct();
			cout << endl;
			
		}
	}

	//��ǰ ����
	void Prod_dele(int id)
	{	//�ε��� �о���� :: ǰ�� �ο��Ǵ� �ε��� ��ȣ�� �޾� ����
		for (int i = 0; i < idx; i++)
		{
			if (i == (id-1))// ��ġ�ϸ� :: id
			{
				for (iter = v.begin(); iter != v.end(); ++iter)
				{
					if (*iter == pobj[i])
					{
						v.erase(iter);
						copy(v.begin(), v.end(), pobj);
						idx--;
						cout << "�����Ϸ�.." << endl << endl;
						Sleep(1000);
						break;
					}
				}
			}

		}




	}

	~ProductHandler()
	{
		//�����Ҵ�� �޸� ����
		for(iter = v.begin();	iter != v.end(); ++iter) 
		{
			delete *iter ; 
		}

		v.clear();
	}
};
int ProductHandler::idx = 0;

int main()
{
	int choice ;//��޴� ����
	int cho;	//	�Ҹ޴� ����

	ProductHandler handle; //����ü ���� ����
	while (1)
	{
		system("cls");
		handle.Menu();
		cout << "->";
		cin>> choice;
		cout << endl;
		switch (choice)
		{
		//��ǰ �߰�
		case PRD_ADD:
			while (1)
			{
				system("cls");
				cout << "��ǰ �߰�" << endl;
				handle.menu();
				

				cout << "->";
				cin >> cho;
				cout << endl;
				if (cho == EX)	//0 �Է½� �ٽ� ����ȭ������
					break;
				switch (cho)
				{
				case BOOK:
					handle.Book_put();
					break;
				case CD:
					handle.Cd_put();
					break;
				case CELLPHONE:
					handle.CPhone_put();
					break;

				default:
					break;
				}
			}
			break;
		//��ǰ ��ȸ
		case PRD_INFO:
			while (1)
			{
				
				cout << "��ǰ ��ȸ" << endl;
				handle.menu();
				cout << "4. ��ü��ǰ" << endl;
				
				cout << "->";
				cin >> cho;
				cout << endl;
				if (cho == EX)	//0 �Է½� �ٽ� ����ȭ������
					break;
				switch (cho)
				{
				case BOOK://å
					handle.Book_Info();
					break;
				case CD://����
					handle.Cd_Info();
					break;
				case CELLPHONE://��
					handle.CPhone_Info();
					break;
				case ALL:
					handle.ShowAllProduct();
					break;
				default:
					break;
				}
			}
			
			break;

		case PRD_DELE:
			while (1)
			{
				system("cls");
				//��� ��ǰ ������ :: �ε��� + 1 ������ ID �ο�
				handle.ShowAllProduct();
				cout << "0 : Ȩ" << endl;
				cout << "Delete ID -->";	//������ ��ǰ�� id �Է�
				cin >> cho;
				cout << endl;
				if (cho == EX) //0 �Է½� �ٽ� ����ȭ������
					break;
				handle.Prod_dele(cho);
			}

			break;
		case EX:
			exit(1);
		default:
			break;
		}
	}
	
	return 0;
}