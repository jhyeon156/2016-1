#pragma once
#pragma once

#include <string>
#include <iostream>
#include "RelationType.h"
#include "LinkedList.h"

using namespace std;

class Seller
{
private:
	int id;
	string password;
	string name;
	string phone;
	string regitNum;
	LinkedList<int> itemList;

public:
	Seller();
	Seller(Seller& seller);
	~Seller();

	int getId(); // ���̵� ����
	string getPW();  // ��й�ȣ ����
	string getName(); // �̸� ����
	string getPhone();
	string getRegitNum();
	LinkedList<int>* getItemList(); //ĳ�� ������ ����

	int addItemToList(int pid);
	int deleteItemToList(int pid);
	int replaceItemToList(int pid);
	void setSeller(int _id, string _password, string _name, string _phone, string _regitNum);
	void printSellerInfo();

	/**
	*	Compare two itemtypes.
	*	@brief	Compare two item types by item id.
	*	@pre	two item types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	������ �ڷᰡ data���� ������ LESS, ������ EQUAL, ũ�� GREATER�� ��ȯ�Ѵ�.
	return LESS if this.id < data.id,
	*			return GREATER if this.id > data.id then,
	*			otherwise return EQUAL.
	*/
	RelationType CompareByID(const Seller &data);

	/**
	*	Compare two itemtypes.
	*	@brief	Compare two item types by item id.
	*	@pre	two item types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	������ ID�� �����ʺ��� ũ�� false, ������ true�� ��ȯ�Ѵ�.
	*/
	bool operator<(Seller data);

	/**
	*	Compare two itemtypes.
	*	@brief	Compare two item types by item id.
	*	@pre	two item types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	������ ID�� �����ʺ��� ũ�� ture, ������ false�� ��ȯ�Ѵ�.
	*/
	bool operator>(Seller data);

	/**
	*	Compare two itemtypes.
	*	@brief	Compare two item types by item id.
	*	@pre	two item types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	���ʰ� �������� ID�� ������ true �ٸ��� false�� ��ȯ�Ѵ�.
	*/
	bool operator==(Seller data);
};

