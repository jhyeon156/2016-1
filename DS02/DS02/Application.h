#pragma once

#include "User.h"
#include "Seller.h"
#include "Product.h"
#include "Category.h"
#include "LinkedList.h"
#include  "BinarySearchTree.h"
#include "CategoryTitle.h"
#include <fstream>
#include <string>



class Application
{
public:
	Application();
	~Application();
public:
	void run();
private:
	void printMenu(int menu); //메뉴 출력
	void test(); //거래내역 출력 함수
	void shoppingManagement();//송금메뉴 출력
	void searchByCategory();//대출 메뉴 출력
	void searchById();//대출 메뉴 출력
	void printItemList();//상환 메뉴 출력
	void resetProductList();
	
	bool login(int uid, string Password);//로그인 함수 성공시 1 출력과 로그인유저 입력
	bool loginAdmin(int uid, string Password);//로그인 함수 성공시 1 출력과 로그인유저 입력
	bool logout(); //로그아웃 함수 로그인유저NULL
	
	void addItemToCart(int pid);

	void addItem();
	void deleteItem();
	void replaceItem();
	void replaceSeller();

	int countCategory();
	void load_user_file(); //유저정보 입력함수
	void load_product_file(); //거래내역 입력함수
	void load_category_file(); //대출내역 입력함수

	string inputString();
private:
	BinarySearchTree<User> userList;
	BinarySearchTree<Seller> sellerList;
	LinkedList<Product> productList;
	Category* categoryArray;
	title* categoryTitleArray;

	User* loginedUser;
	Seller* loginedSeller;
};

