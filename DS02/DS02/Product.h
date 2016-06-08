#pragma once

#include <string>
#include <iostream>
#include "RelationType.h"
#include "LinkedList.h"
#include "CategoryTitle.h"

using namespace std;

class Product
{
private:
	int id;
	int price;
	int amount;
	int sellerId;
	int cat_1;
	int cat_2;
	int cat_3;
	string picPath;
	string name;

public:
	Product();
	Product(Product& product);
	~Product();

	int getId(); // ���̵� ����
	int getPrice();
	int getAmount();
	int getSellerId();
	int getCat_1();
	int getCat_2();
	int getCat_3();
	string getPicPath();
	string getName(); // �̸� ����

	void setId(int _id);
	void setAmount(int _amount);
	void setProduct(int _id, int _price, int _amount, int _sellerId, int _cat1, int _cat2, int _cat3, string _name, string _picPath);
	//��������� ���
	void printProductList();
	//������ ���
	void printProductInfo(title* title);

	RelationType CompareByID(Product &data);

	/**
	*	Compare two itemtypes.
	*	@brief	Compare two item types by item id.
	*	@pre	two item types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	������ ID�� �����ʺ��� ũ�� false, ������ true�� ��ȯ�Ѵ�.
	*/
	bool operator<(Product data);

	/**
	*	Compare two itemtypes.
	*	@brief	Compare two item types by item id.
	*	@pre	two item types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	������ ID�� �����ʺ��� ũ�� ture, ������ false�� ��ȯ�Ѵ�.
	*/
	bool operator>(Product data);

	/**
	*	Compare two itemtypes.
	*	@brief	Compare two item types by item id.
	*	@pre	two item types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	���ʰ� �������� ID�� ������ true �ٸ��� false�� ��ȯ�Ѵ�.
	*/
	bool operator==(Product data);
};

