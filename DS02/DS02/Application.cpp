#include <iostream>
#include <fstream>
#include <string>
#include "Application.h"

using namespace std;

Application::Application()
{

	User* loginedUser = NULL; //로그인 된 사용자
	Seller* loginedAdmin = NULL;

	int categorySize = countCategory();

	categoryArray = new Category[categorySize];
	categoryTitleArray = new title[categorySize];

	cout << "Loading..." << endl;
	load_user_file();
	load_product_file();
	load_category_file();
	
}

Application ::~Application()
{
	delete categoryArray;
	delete categoryTitleArray;
}

void Application::run()
{
	int m_Command;
	int menu = 0; //초기 로그인 상태
	int isAdmin = 0;

	bool isLogined; 
	int uid;
	string passwd;

	while (1)
	{
		
		if (menu == 0)
		{
			printMenu(menu);
			cin >> m_Command;
			cin.clear(); //문자열 입력 금지
			cin.ignore();
			while (m_Command < -1 || m_Command >2)
			{
				cout << "잘못된 값을 입력하였습니다.\n";
				printMenu(menu);
				cin >> m_Command;
				cin.clear(); //문자열 입력 금지
				cin.ignore();
			}
		}
			
		if (menu == 1)
		{
			while (1)
			{
				cout << "---------------------------------------------------" << endl;
				loginedUser->printUserInfo();
				cout << "---------------------------------------------------" << endl;
				printMenu(menu);
				m_Command = 0;
				cin >> m_Command; //1,2,3,4,5,6
				cin.clear(); //문자열 입력 금지
				cin.ignore();
				if (m_Command == 1 || m_Command == 2 || m_Command == 3 || m_Command == 4 || m_Command == 5 || m_Command == 6)
				{
					m_Command += 2;
					break;
				}

				else
				{
					cout << "잘못된 값을 입력하셨습니다." << endl;
				}
			}


		}
			
		if (menu == 2)
		{
			while (1)
			{
				cout << "---------------------------------------------------" << endl;
				loginedSeller->printSellerInfo();
				cout << "---------------------------------------------------" << endl;
				printMenu(menu);
				m_Command = 0;
				cin >> m_Command; //1,2,3,4
				cin.clear(); //문자열 입력 금지
				cin.ignore();
				if (m_Command == 1 || m_Command == 2 || m_Command == 3 || m_Command == 4 || m_Command == 5)
				{
					m_Command += 8;
					break;
				}

				else
				{
					cout << "잘못된 값을 입력하셨습니다." << endl;
				}
			}


		}

		switch (m_Command)
		{
		case 1:		// 로그인
			cout << "관리자입니까? : ";
			cin >> isAdmin;
			cout << "ID : ";
			cin >> uid;
			cin.clear(); //문자열 입력 금지
			cin.ignore();
			cout << "PW : ";
			cin >> passwd;

			if (isAdmin == 0)
			{
				if (uid == 0)
				{
					cout << "올바른 id가 입력되지 않았습니다." << endl;
				}
				if (isLogined = login(uid, passwd)) //로그인이 되면
				{
					menu = 1; //두번째 매뉴가 출력되게
				}
				else
				{
					cout << "로그인에 실패하였습니다." << endl;
				}
			}
			if (isAdmin == 1)
			{
				if (uid == 0)
				{
					cout << "올바른 id가 입력되지 않았습니다." << endl;
				}
				if (isLogined = loginAdmin(uid, passwd)) //로그인이 되면
				{
					menu = 2; //두번째 매뉴가 출력되게
				}
				else
				{
					cout << "로그인에 실패하였습니다." << endl;
				}
			}
			
			break;
		case 2:		//로그아웃
			isLogined = false;
			loginedUser = NULL;
			logout();
			break;
		case 3:		//입, 출금
			searchByCategory();
			break;
		case 4:		//송금
			searchById();
			break;
		case 5:		//대출
			shoppingManagement();
			break;
		case 6:		//대출금 반환
			printItemList();
			break;
		case 7:		//거래내역 조회
			test();
			break;
		case 8:		//이전 메뉴로
			menu = 0;
			break;
		case 9:
			addItem();
			break;
		case 10:
			replaceItem();
			break;
		case 11:
			deleteItem();
			break;
		case 12:
			replaceSeller();
		case 13:
			menu = 0;
			break;
		case 0:  //종료
			return;
		default:
			cout << "잘못된 값을 입력하였습니다.\n";
			break;
		}
	}
}
//메뉴 출력
void Application::printMenu(int menu)
{
	if (menu == 0)
	{
		cout << "1.로그인" << endl;
		cout << "2.로그아웃" << endl;
		cout << "0.종료" << endl;
		cout << "->";
		return;
	}
	if (menu == 1)
	{
		cout << "1.카테고리로 검색하기" << endl;
		cout << "2.ID로 검색하기" << endl;
		cout << "3.쇼핑관리" << endl;
		cout << "4.전체 상품 리스트" << endl;
		cout << "5.장바구니 테스트" << endl;
		cout << "6.이전 메뉴로" << endl;
		cout << "->";
		return;
	}
	if (menu == 2)
	{
		cout << "1. 상품등록" << endl;
		cout << "2. 상품변경" << endl;
		cout << "3. 상품삭제" << endl;
		cout << "4. 유저수정" << endl;
		cout << "5. 뒤로" << endl;
	}
}

//장바구니 입력
void Application::addItemToCart(int pid)
{
	char YN;

	//상품정보 출력
	Product temp;
	bool found = false;

	temp.setProduct(pid, 0, 0, 0, 0, 0, 0, "", "");
	productList.RetrieveItem(temp,found);
	if (found)
	{
		temp.printProductInfo(categoryTitleArray);

		cout << "상품을 카트에 담으시겠습니까?" << endl;
		cout << "Y/N->";
		cin >> YN;

		loginedUser->addItemToShoppingList(pid);
		if (YN == 'Y')
		{
			loginedUser->addItemToCart(pid);
			return;
		}
		else
		{
			return;
		}
	}
}

//아이템 추가
void Application::addItem()
{
	int command = 0;
	int dep = 0;
	bool found = false;

	Product temp;
	int id=0;
	int price=0;
	string name="";
	string picPath="";
	int amount=0;
	int sellerId = loginedSeller->getId();
	int cat[3] = {0};

	cout << "ID : ";
	cin >> id;
	cout << "NAME : ";
	cin >> name;
	cout << "사진 : ";
	cin >> picPath;
	cout << "PRICE : ";
	cin >> price;
	cout << "AMOUNT : ";
	cin >> amount;

	while (dep < 3)
	{
		int i = 0;
		for (i = 0; i < categoryArray[0].getSize(); i++)
		{
			if (categoryArray[i].getPrev() == command)
			{
				categoryArray[i].print();
			}
		}
		dep++;
		cout << endl;
		cin >> command;
		cat[dep-1] = command;
	}
	
	temp.setProduct(id, price, amount, sellerId, cat[0], cat[1], cat[2], name, picPath);
	productList.InsertItem(temp);
	cout << "입력이 완료되었습니다." << endl;
	return;
}
//아이템 변경
void Application::replaceItem()
{
	int command = 0;
	int dep = 0;

	Product temp;
	bool found = false;
	int id = 0;
	int price = 0;
	string name = "";
	string picPath = "";
	int amount = 0;
	int sellerId = loginedSeller->getId();
	int cat[3] = { 0 };

	Product dummy;

	cout << "ID\t이름\t가격\t수량\t사진" << endl;
	productList.PrintTree(cout);

	cout << "수정할 상품ID를 입력해 주십시오. : ";
	cin >> id;
	cout << "NAME : ";
	cin >> name;
	cout << "사진 : ";
	cin >> picPath;
	cout << "PRICE : ";
	cin >> price;
	cout << "AMOUNT : ";
	cin >> amount;

	while (dep < 3)
	{
		int i = 0;
		for (i = 0; i < categoryArray[0].getSize(); i++)
		{
			if (categoryArray[i].getPrev() == command)
			{
				categoryArray[i].print();
			}
		}
		dep++;
		cout << endl;
		cin >> command;
		cat[dep - 1] = command;
	}

	temp.setProduct(id, price, amount, sellerId, cat[0], cat[1], cat[2], name, picPath);
	productList.ReplaceItem(temp,found);
	cout << "입력이 완료되었습니다." << endl;
	return;
}
void Application::replaceSeller()
{
	string name;
	string phone;
	string regitNum;
	bool found;

	Seller temp;

	cout << "상호명 : ";
	cin >> name;
	cout << "전화번호 : ";
	cin >> phone;
	cout << "상호번호 : ";
	cin >> regitNum;

	temp.setSeller(loginedSeller->getId(), loginedSeller->getPW(), name, phone, regitNum);
	sellerList.ReplaceItem(temp, found);
}
//아이템 삭제
void Application::deleteItem()
{
	int command = 0;
	int dep = 0;
	bool found = false;

	Product temp;
	int id = 0;
	int price = 0;
	string name = "";
	string picPath = "";
	int amount = 0;
	int sellerId = loginedSeller->getId();
	int cat[3] = { 0 };

	Product dummy;

	cout << "ID\t이름\t가격\t수량\t사진" << endl;
	productList.PrintTree(cout);

	cout << "삭제할 상품ID를 입력해 주십시오. : ";
	cin >> id;

	temp.setProduct(id, 0, 0, 0, 0, 0, 0, "", "");
	productList.DeleteItem(temp);
	cout << "입력이 완료되었습니다." << endl;
	return;
}
//쇼핑관리
void Application::shoppingManagement()
{
	int command;
	LinkedList<int>* userCart;
	Product dummy;
	bool found = false;
	int i_dummy;

	cout << "1. 장바구니 보기" << endl;
	cout << "2. 쇼핑내역 보기" << endl;
	cout << "3. 구매하기" << endl;
	cout << "4. 유저수정" << endl;
	cout << "->";
	cin >> command;
	
	if (command == 1)
	{
		userCart = loginedUser->getCartList();
		userCart->ResetList();
		
		cout << "장바구니 목록" << endl;
		for (int i = 0; i < userCart->GetLength(); i++)
		{
			userCart->GetNextItem(i_dummy);
			dummy.setId(i_dummy);
			productList.RetrieveItem(dummy,found);
			dummy.printProductList();
		}
	}
	if (command == 2)
	{
		userCart = loginedUser->getShoppingList();
		userCart->ResetList();

		cout << "쇼핑 목록" << endl;
		for (int i = 0; i < userCart->GetLength(); i++)
		{
			userCart->GetNextItem(i_dummy);
			dummy.setId(i_dummy);
			productList.RetrieveItem(dummy, found);
			dummy.printProductList();
		}
	}
	if (command == 3)
	{
		userCart = loginedUser->getCartList();
		userCart->ResetList();

		cout << "구매 목록" << endl;
		for (int i = 0; i < userCart->GetLength(); i++)
		{
			userCart->GetNextItem(i_dummy);
			dummy.setId(i_dummy);
			productList.RetrieveItem(dummy, found);
			//개수 1개 이하 예외처리
			dummy.setAmount(dummy.getAmount() - 1);
			productList.ReplaceItem(dummy,found);
		}
		printItemList();
	}
}

//카테고리 검색기능
void Application::searchByCategory()
{
	int command = 0;
	int dep = 0;
	bool found = false;

	LinkedList<int>* tempList;

	while (dep < 3)
	{
		for (int i = 0; i < categoryArray[0].getSize(); i++)
		{
			if (categoryArray[i].getPrev() == command)
			{
				categoryArray[i].print();
			}
		}
		dep++;
		cout << endl;
		cin >> command;
	}
	//categoryArray[command - 1].setList(productList);
	tempList = categoryArray[command - 1].getList();
	
	int p=-1;
	Product dummy;
	tempList->ResetList();	// 리스트 초기화
	
	// list의 모든 데이터를 화면에 출력
	cout << "ID\t이름\t가격\t수량\t사진" << endl;
	for (int i = 0; i < tempList->GetLength(); i++)
	{
		tempList->GetNextItem(p);
		dummy.setId(p);
		productList.RetrieveItem(dummy,found);
		dummy.printProductList();
	}
	if (found = false)
	{
		cout << "해당 카테고리에 상품이 없습니다." << endl;
	}
	else
	{
		cout << "상품을 선택하여 주십시오" << endl;
		cout << "->";
		cin >> command;
		if (command == 0)
			return;
		else
			addItemToCart(command);
	}
}
//ID검색기능
void Application::searchById()
{
	int command = 0;
	
	cout << "찾고자 하는 ID를 입력하여 주십시오.";
	cout << "->";
	cin >> command;

	Product temp;
	bool found;

	temp.setProduct(command, 0, 0, 0, 0, 0, 0, "", "");
	productList.RetrieveItem(temp,found);
	if (found)
		addItemToCart(temp.getId());
	else
	{
		cout << "해당 ID의 제품이 없습니다." << endl;
		return;
	}
}

//상환 메뉴 출력
void Application::printItemList()
{
	Product dummy;

	productList.PrintTree(cout);
}

void Application::test()
{
	loginedUser->addItemToCart(1);
	loginedUser->addItemToCart(2);
	loginedUser->addItemToCart(3);
	loginedUser->addItemToCart(4);
	loginedUser->addItemToCart(5);
}

//로그인 함수
bool Application::login(int uid, string Password)
{
	User temp;
	string dummy = "";
	bool found;

	temp.setUser(uid, Password, dummy);
	userList.RetrieveItem(temp,found);

	if (!found)
	{
		cout << "유저 없음" << endl;
		return false;
	}
	else
	{
		if (temp.getPW() == Password)
		{
			loginedUser = new User(temp);
			return true;
		}
		else
		{
			cout << "비밀번호 오류" << endl;
			return false;
		}
	}
}

bool Application::loginAdmin(int uid, string Password)
{
	Seller temp;
	string dummy = "";
	bool found;

	temp.setSeller(uid, Password, dummy, "", "");
	sellerList.RetrieveItem(temp,found);

	if (!found)
	{
		cout << "유저 없음" << endl;
		return false;
	}
	else
	{
		if (temp.getPW() == Password)
		{
			loginedSeller = new Seller(temp);
			return true;
		}
		else
		{
			cout << "비밀번호 오류" << endl;
			return false;
		}
	}
}

bool Application::logout()
{
	//saveFiles(); //DB저장
	loginedUser = NULL; //로그인 정보 초기화
	cout << "LOGOUT!" << endl;
	return true;
}


int Application::countCategory()
{
	fstream ifs;
	ifs.open("category.txt");

	if (!ifs) //파일없는 경우 예외처리
	{
		cerr << "카테고리 DB를 불러오지 못했습니다." << endl;
		cerr << "프로그램을 종료합니다." << endl;
		exit(100);
	}

	int index = 0;

	int id = 0;
	int dep = 0;
	int prev = 0;
	string name = "";

	//끝까지
	while (!ifs.eof()) {
		ifs >> id >> prev >> name >> dep;
		index++;
	}
	ifs.close();

	return index;
}

void Application::load_user_file()
{
	fstream ifs;
	ifs.open("users.txt");

	if (!ifs) //파일없는 경우 예외처리
	{
		cerr << "사용자 DB를 불러오지 못했습니다." << endl;
		cerr << "프로그램을 종료합니다." << endl;
		exit(100);
	}

	int index = 0;
	int isAdmin = 0;
	//변수 초기화
	int id=0;
	string password="";
	string name="";
	string regitNum ="";
	string phone = "";
	User temp;
	Seller temp2;

	//끝까지
    while(!ifs.eof()){
		ifs >> isAdmin;
		if (isAdmin == 0)
		{
			ifs >> id >> password >> name;
			temp.setUser(id, password, name);
			userList.InsertItem(temp);
			index++;
		}
		else
		{
			ifs >> id >> password >> name >> phone >> regitNum;
			temp2.setSeller(id, password, name, phone, regitNum);
			sellerList.InsertItem(temp2);
			index++;
		}
    }
    ifs.close();
    return;
}
void Application::load_product_file()
{
	fstream ifs;
	ifs.open("products.txt");  

	if (!ifs)//파일없는 경우 예외처리
	{
		cerr << "거래내역 DB를 불러오지 못했습니다." << endl;
		cerr << "프로그램을 종료합니다." << endl;
		exit(100);
	}

	int index = 0;
	//변수 초기화
	int id = 0;
	int price = 0;
	int amount = 0;
	int sellerId = 0;
	int cat_1 = 0;
	int cat_2 = 0;
	int cat_3 = 0;
	string name = "";
	string picPath = "";
	Product temp;

	//끝까지
	while (!ifs.eof()) {
		ifs >> id >> name >> price >> amount >> sellerId >> cat_1 >> cat_2 >> cat_3 >> picPath;
		temp.setProduct(id, price, amount, sellerId, cat_1, cat_2, cat_3, name, picPath);
		productList.InsertItem(temp);
		index++;
	}

	ifs.close();

	return;
}
void Application::load_category_file()
{
	fstream ifs;
	ifs.open("category.txt");

	if (!ifs) //파일없는 경우 예외처리
	{
		cerr << "카테고리 DB를 불러오지 못했습니다." << endl;
		cerr << "프로그램을 종료합니다." << endl;
		exit(100);
	}

	int index = 0;
	//변수 초기화
	int id = 0;
	int dep = 0;
	int prev = 0;
	string name = "";

	//끝까지
	while (!ifs.eof()) {
		ifs >> id >> prev >> name >> dep;
		categoryArray[index].setCategory(id, prev, name, dep);
		categoryTitleArray[index].category_id = id;
		categoryTitleArray[index].category_title = name;
		index++;
	}
	ifs.close();
	return;
}

string Application::inputString()
{
	char ch[1024];
	string input;
	cin.getline(ch, 1023);  //cin사용시 입력값과 변수를 잘 살펴야한다.
	cin.clear();

	getline(cin, input);
	return input;
}
