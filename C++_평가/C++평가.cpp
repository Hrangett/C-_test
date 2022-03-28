/*
	C++ 평가.c
	created : 2022. 3. 28
	Author : 이은영
*/


#include<iostream>
#include<vector>
#include<Windows.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

//열거형으로 정의
enum { EX = 0,PRD_ADD,PRD_INFO, PRD_DELE};
enum { BOOK = 1,CD,CELLPHONE,ALL };

//부모클래스
class Product
{
private:
	int price;
	string description;
public:
	//Product 생성자
	Product(string description, int price) 
		:price(price),description(description)
	{}
	
	//	상품 출력함수
	virtual void getProduct() {
		cout << "price : " << price << endl;
		cout << "description" << description << endl;
	}	
	//각 상품 항목명 구분
	virtual string name() { return " "; }
};

//책 클래스
class Book : public Product
{
private:
	string title;
	string writer;
	string publisher;
	string description;
	int price;
	
public:
	// 생성자 초기화
	Book(string title, string writer, string publisher, string description, int price)
		: title(title), writer(writer), publisher(publisher), Product(description,price)
	{	}
	//복사생성자
	Book(Book& ref) 
		: title(ref.title), writer(ref.writer), publisher(ref.publisher), Product(ref.description,ref.price)
	{	}

	//항목구분 :: Book상품 조회시 사용
	string name()
	{
		return "Book";
	}
	
	//출력
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
	//항목구분 :: CD상품 조회시 사용
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

		//상품모델
		cout << "Model : " << model << endl;
		//manufacturer
		cout << "Manufacturer : " << manufacturer << endl;
		Product::getProduct();

	}

	//항목구분 :: Cellphone상품 조회시 사용
	string name()
	{
		return "Cellphone";
	}

};
//Product 다루는 구조체
class ProductHandler
{
	Product* pobj[100]; //추가할 product 저장할 구조체 포인터 선언
	static int idx;//product 인덱스
	
	vector<Product*> v;
	vector<Product*>::iterator iter;

public:
	ProductHandler()
	{	}

	//대메뉴
	void Menu()
	{
		cout << "~홈~" << endl;
		cout << "0. 종료" << endl;
		cout << "1. 상품 추가" << endl;
		cout << "2. 상품 조회" << endl;
		cout << "3. 상품 삭제" << endl;

	}

	//소메뉴
	void menu()
	{
		cout << "0. 홈" << endl;
		cout << "1. Book" << endl;
		cout << "2. CD" << endl;
		cout << "3. CellPhone" << endl;

	}
	//Book 추가
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

	//Book 조회
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

	//Cd 추가
	void Cd_put()
	{
		string title;
		string singer;
		string description;
		int price;
		cout << "===== ADD Cd Product ======" << endl;

		//제목
		cout << "Title : ";
		cin >> title;
		cout << endl;
		//가수
		cout << "Singer : ";
		cin >> singer;
		cout << endl;
		//가격
		cout << "Price : ";
		cin >> price;
		cout << endl;
		//상세정보
		cout << "Description : ";
		cin >> description;
		cout << endl;

		pobj[idx++] = new Cd(title, singer, description, price);
		v.push_back(pobj[(idx - 1)]);

	}

	//Cd 조회
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

	//CellPhone 추가
	void CPhone_put()
	{
		string model;
		string manufacturer;
		string description;
		int price;
		
		cout << "===== ADD CellPhone Product ======" << endl;
		//상품모델
		cout << "Model : ";
		cin >> model;
		cout << endl;
		//manufacturer
		cout << "Manufacturer : ";
		cin >> manufacturer;
		cout << endl;

		//가격
		cout << "Price : ";
		cin >> price;
		cout << endl;

		//상세정보
		cout << "Description : ";
		cin >> description;
		cout << endl;


		pobj[idx++] = new Cellphone(model, manufacturer, description, price);
		v.push_back(pobj[(idx-1)]);

	}

	//CellPhone 조회
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

	//모든 데이터 조회
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
			cout << " ID -> " << i + 1 << endl;	//	idx + 1로 id  부여
			pobj[i]->getProduct();
			cout << endl;
			
		}
	}

	//상품 삭제
	void Prod_dele(int id)
	{	//인덱스 읽어오기 :: 품목에 부여되는 인덱스 번호를 받아 삭제
		for (int i = 0; i < idx; i++)
		{
			if (i == (id-1))// 일치하면 :: id
			{
				for (iter = v.begin(); iter != v.end(); ++iter)
				{
					if (*iter == pobj[i])
					{
						v.erase(iter);
						copy(v.begin(), v.end(), pobj);
						idx--;
						cout << "삭제완료.." << endl << endl;
						Sleep(1000);
						break;
					}
				}
			}

		}




	}

	~ProductHandler()
	{
		//동적할당된 메모리 해제
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
	int choice ;//대메뉴 선택
	int cho;	//	소메뉴 선택

	ProductHandler handle; //구조체 변수 선언
	while (1)
	{
		system("cls");
		handle.Menu();
		cout << "->";
		cin>> choice;
		cout << endl;
		switch (choice)
		{
		//상품 추가
		case PRD_ADD:
			while (1)
			{
				system("cls");
				cout << "상품 추가" << endl;
				handle.menu();
				

				cout << "->";
				cin >> cho;
				cout << endl;
				if (cho == EX)	//0 입력시 다시 메인화면으로
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
		//상품 조회
		case PRD_INFO:
			while (1)
			{
				
				cout << "상품 조회" << endl;
				handle.menu();
				cout << "4. 전체상품" << endl;
				
				cout << "->";
				cin >> cho;
				cout << endl;
				if (cho == EX)	//0 입력시 다시 메인화면으로
					break;
				switch (cho)
				{
				case BOOK://책
					handle.Book_Info();
					break;
				case CD://씨디
					handle.Cd_Info();
					break;
				case CELLPHONE://폰
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
				//모든 제품 보여줌 :: 인덱스 + 1 순으로 ID 부여
				handle.ShowAllProduct();
				cout << "0 : 홈" << endl;
				cout << "Delete ID -->";	//삭제할 상품의 id 입력
				cin >> cho;
				cout << endl;
				if (cho == EX) //0 입력시 다시 메인화면으로
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