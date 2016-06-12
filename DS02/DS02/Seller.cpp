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

//판매자 정보 입력
void Seller::setSeller(int _id, string _password, string _name, string _phone, string _regitNum)
{
	id = _id; password = _password; name = _name; phone = _phone; regitNum = _regitNum;
}

//사용자 정보 출력
void Seller::printSellerInfo()
{
	cout << "사용자ID\t: " << id << endl;
	cout << "사용자이름\t: " << name << endl;
	cout << "사용자전화\t: " << phone << endl;
	cout << "사용자번호\t: " << regitNum << endl;
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
	// CompareByID메소드에서 this(저장되어있는값)가 data(입력하는값)보다 작을경우 LESS를 리턴
	// 이를 통한 연산자 오버로딩을 이용하여 대수비교를 한다.
	if (this->CompareByID(data) == LESS)
	{
		return true;
	}
	else
		return false;
}

bool Seller::operator >(Seller data)
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

bool Seller::operator ==(Seller data)
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