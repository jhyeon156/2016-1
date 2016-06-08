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

	int getId(); // 아이디 리턴
	int getPrice();
	int getAmount();
	int getSellerId();
	int getCat_1();
	int getCat_2();
	int getCat_3();
	string getPicPath();
	string getName(); // 이름 리턴

	void setId(int _id);
	void setAmount(int _amount);
	void setProduct(int _id, int _price, int _amount, int _sellerId, int _cat1, int _cat2, int _cat3, string _name, string _picPath);
	//목록형으로 출력
	void printProductList();
	//상세정보 출력
	void printProductInfo(title* title);

	RelationType CompareByID(Product &data);

	/**
	*	Compare two itemtypes.
	*	@brief	Compare two item types by item id.
	*	@pre	two item types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	왼쪽의 ID가 오른쪽보다 크면 false, 작으면 true를 반환한다.
	*/
	bool operator<(Product data);

	/**
	*	Compare two itemtypes.
	*	@brief	Compare two item types by item id.
	*	@pre	two item types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	왼쪽의 ID가 오른쪽보다 크면 ture, 작으면 false를 반환한다.
	*/
	bool operator>(Product data);

	/**
	*	Compare two itemtypes.
	*	@brief	Compare two item types by item id.
	*	@pre	two item types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	왼쪽과 오른쪽의 ID가 같으면 true 다르면 false를 반환한다.
	*/
	bool operator==(Product data);
};

