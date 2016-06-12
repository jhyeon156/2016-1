#pragma once

#include <string>
#include <iostream>
#include "RelationType.h"
#include "LinkedList.h"

using namespace std;

class User
{
private:
	int id;
	string password;
	string name;
	LinkedList<int> cartList;
	LinkedList<int> shoppingList;
	
public:
	User();
	User(User& user);
	~User();

	int getId(); // ���̵� ����
	string getPW();  // ��й�ȣ ����
	string getName(); // �̸� ����
	LinkedList<int>* getCartList(); //ĳ�� ������ ����
	LinkedList<int>* getShoppingList(); //ĳ�� ������ ����

	int addItemToCart(int pid);
	int addItemToShoppingList(int pid);
	void setUser(int _id, string _password, string _name);
	void printUserInfo();

	/**
	*	Compare two itemtypes.
	*	@brief	Compare two item types by item id.
	*	@pre	two item types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	������ �ڷᰡ data���� ������ LESS, ������ EQUAL, ũ�� GREATER�� ��ȯ�Ѵ�.
	*/
	RelationType CompareByID(const User &data);

	/**
	*	Compare two itemtypes.
	*	@brief	Compare two item types by item id.
	*	@pre	two item types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	������ ID�� �����ʺ��� ũ�� false, ������ true�� ��ȯ�Ѵ�.
	*/
	bool operator<(User data);

	/**
	*	Compare two itemtypes.
	*	@brief	Compare two item types by item id.
	*	@pre	two item types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	������ ID�� �����ʺ��� ũ�� ture, ������ false�� ��ȯ�Ѵ�.
	*/
	bool operator>(User data);

	/**
	*	Compare two itemtypes.
	*	@brief	Compare two item types by item id.
	*	@pre	two item types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	���ʰ� �������� ID�� ������ true �ٸ��� false�� ��ȯ�Ѵ�.
	*/
	bool operator==(User data);
};