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

//���� ���� �Է�
void User::setUser(int _id, string _password, string _name)
{
	id = _id; password = _password; name = _name;
}

//����� ���� ���
void User::printUserInfo()
{
	cout << "�����ID\t: " << id << endl;
	cout << "������̸�\t: " << name << endl;
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
	// CompareByID�޼ҵ忡�� this(����Ǿ��ִ°�)�� data(�Է��ϴ°�)���� ������� LESS�� ����
	// �̸� ���� ������ �����ε��� �̿��Ͽ� ����񱳸� �Ѵ�.
	if (this->CompareByID(data) == LESS)
	{
		return true;
	}
	else
		return false;
}

bool User::operator >(User data)
{
	// CompareByID�޼ҵ忡�� this(����Ǿ��ִ°�)�� data(�Է��ϴ°�)���� Ŭ��� GREATER�� ����
	// �̸� ���� ������ �����ε��� �̿��Ͽ� ����񱳸� �Ѵ�.
	if (this->CompareByID(data) == GREATER)
	{
		return true;
	}
	else
		return false;
}

bool User::operator ==(User data)
{
	// CompareByID�޼ҵ忡�� this(����Ǿ��ִ°�)�� data(�Է��ϴ°�)�� ������� EQUAL�� ����
	// �̸� ���� ������ �����ε��� �̿��Ͽ� ����񱳸� �Ѵ�.
	if (this->CompareByID(data) == EQUAL)
	{
		return true;
	}
	else
		return false;
}

#include <string>
#include <iostream>
#include "Seller.h"

using namespace std;

Seller::Seller()
{
}

Seller::Seller(Seller& user)
{
	id = user.getId();
	name = user.getName();
	password = user.getPW();
}

Seller::~Seller() {}


int Seller::getPhone()
{
	return phone;
}

int Seller::getRegitNum()
{
	return regitNum;
}

LinkedList<int>* Seller::getItemList()
{
	return &itemList;
}

int Seller::addItemToList(int pid)
{
	itemList.Add(pid);
	return 1;
}

int Seller::deleteItemToList(int pid)
{
	itemList.Delete(pid);
	return 1;
}

int Seller::replaceItemToList(int pid)
{
	itemList.Replace(pid);
	return 1;
}

//�Ǹ��� ���� �Է�
void Seller::setSeller(int _id, string _password, string _name, int _phone, int _regitNum)
{
	id = _id; password = _password; name = _name; phone = _phone; regitNum = _regitNum;
}

//����� ���� ���
void Seller::printSellerInfo()
{
	cout << "�����ID\t: " << id << endl;
	cout << "������̸�\t: " << name << endl;
}