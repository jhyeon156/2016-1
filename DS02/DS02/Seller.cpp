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

int Seller::getId()
{
	return id;
}

string Seller::getPW()
{
	return password;
}

string Seller::getName()
{
	return name;
}

string Seller::getPhone()
{
	return phone;
}

string Seller::getRegitNum()
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
void Seller::setSeller(int _id, string _password, string _name, string _phone, string _regitNum)
{
	id = _id; password = _password; name = _name; phone = _phone; regitNum = _regitNum;
}

//����� ���� ���
void Seller::printSellerInfo()
{
	cout << "�����ID\t: " << id << endl;
	cout << "������̸�\t: " << name << endl;
	cout << "�������ȭ\t: " << phone << endl;
	cout << "����ڹ�ȣ\t: " << regitNum << endl;
}

// Compare two itemtypes by ID.
RelationType Seller::CompareByID(const Seller &data)
{
	if (this->id > data.id)
		return GREATER;
	else if (this->id < data.id)
		return LESS;
	else
		return EQUAL;
}

bool Seller::operator <(Seller data)
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

bool Seller::operator >(Seller data)
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

bool Seller::operator ==(Seller data)
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