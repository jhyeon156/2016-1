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
	string address;
	LinkedList<int> cartList;
	LinkedList<int> shoppingList;
	
public:
	User();
	User(User& user);
	~User();

	int getId(); // 아이디 리턴
	string getPW();  // 비밀번호 리턴
	string getName(); // 이름 리턴
	string getAddress();
	LinkedList<int>* getCartList(); //캐시 포인터 리턴
	LinkedList<int>* getShoppingList(); //캐시 포인터 리턴

	int addItemToCart(int pid);
	int addItemToShoppingList(int pid);
	void setUser(int _id, string _password, string _name, string _address);
	void printUserInfo();

	/**
	*	Compare two itemtypes.
	*	@brief	Compare two item types by item id.
	*	@pre	two item types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	현재의 자료가 data보다 작으면 LESS, 같으면 EQUAL, 크면 GREATER를 반환한다.
	*/
	RelationType CompareByID(const User &data);

	/**
	*	Compare two itemtypes.
	*	@brief	Compare two item types by item id.
	*	@pre	two item types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	왼쪽의 ID가 오른쪽보다 크면 false, 작으면 true를 반환한다.
	*/
	bool operator<(User data);

	/**
	*	Compare two itemtypes.
	*	@brief	Compare two item types by item id.
	*	@pre	two item types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	왼쪽의 ID가 오른쪽보다 크면 ture, 작으면 false를 반환한다.
	*/
	bool operator>(User data);

	/**
	*	Compare two itemtypes.
	*	@brief	Compare two item types by item id.
	*	@pre	two item types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	왼쪽과 오른쪽의 ID가 같으면 true 다르면 false를 반환한다.
	*/
	bool operator==(User data);
};