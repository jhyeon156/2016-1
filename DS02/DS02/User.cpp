#include <string>
#include <iostream>
#include "User.h"

using namespace std;

User::User()
{
}

User::User(User& user)
{
	id = user.getId();
	name = user.getName();
	password = user.getPW();
}

User::~User() {}

int User::getId()
{
	return id;
}

string User::getPW()
{
	return password;
}

string User::getName()
{
	return name;
}

LinkedList<int>* User::getCartList()
{
	return &cartList;
}

LinkedList<int>* User::getShoppingList()
{
	return &shoppingList;
}

int User::addItemToCart(int pid)
{
	cartList.Add(pid);
	return 1;
}

int User::addItemToShoppingList(int pid)
{
	shoppingList.Add(pid);
	return 1;
}

//유저 정보 입력
void User::setUser(int _id, string _password, string _name)
{
	id = _id; password = _password; name = _name;
}

//사용자 정보 출력
void User::printUserInfo()
{
	cout << "구매자ID\t: " << id << endl;
	cout << "구매자이름\t: " << name << endl;
}

// Compare two itemtypes by ID.
RelationType User::CompareByID(const User &data)
{
	if (this->id > data.id)
		return GREATER;
	else if (this->id < data.id)
		return LESS;
	else
		return EQUAL;
}

bool User::operator <(User data)
{
	// CompareByID메소드에서 this(저장되어있는값)가 data(입력하는값)보다 작을경우 LESS를 리턴
	// 이를 통한 연산자 오버로딩을 이용하여 대수비교를 한다.
	if (this->CompareByID(data) == LESS)
	{
		return true;
	}
	else
		return false;
}

bool User::operator >(User data)
{
	// CompareByID메소드에서 this(저장되어있는값)가 data(입력하는값)보다 클경우 GREATER를 리턴
	// 이를 통한 연산자 오버로딩을 이용하여 대수비교를 한다.
	if (this->CompareByID(data) == GREATER)
	{
		return true;
	}
	else
		return false;
}

bool User::operator ==(User data)
{
	// CompareByID메소드에서 this(저장되어있는값)가 data(입력하는값)과 같은경우 EQUAL을 리턴
	// 이를 통한 연산자 오버로딩을 이용하여 대수비교를 한다.
	if (this->CompareByID(data) == EQUAL)
	{
		return true;
	}
	else
		return false;
}