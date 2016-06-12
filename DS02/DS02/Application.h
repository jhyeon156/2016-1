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
	void printMenu(int menu); //�޴� ���
	void test(); //�ŷ����� ��� �Լ�
	void shoppingManagement();//�۱ݸ޴� ���
	void searchByCategory();//���� �޴� ���
	void searchById();//���� �޴� ���
	void printItemList();//��ȯ �޴� ���
	void resetProductList();
	
	bool login(int uid, string Password);//�α��� �Լ� ������ 1 ��°� �α������� �Է�
	bool loginAdmin(int uid, string Password);//�α��� �Լ� ������ 1 ��°� �α������� �Է�
	bool logout(); //�α׾ƿ� �Լ� �α�������NULL
	
	void addItemToCart(int pid);

	void addItem();
	void deleteItem();
	void replaceItem();
	void replaceSeller();

	int countCategory();
	void load_user_file(); //�������� �Է��Լ�
	void load_product_file(); //�ŷ����� �Է��Լ�
	void load_category_file(); //���⳻�� �Է��Լ�

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

