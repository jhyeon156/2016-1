#include <string>
#include <iostream>
#include "Product.h"

using namespace std;

Product::Product()
{
}

Product::Product(Product& product)
{
	id = product.getId();
	name = product.getName();
	picPath = product.getPicPath();
	price = product.getPrice();
	amount = product.getAmount();
	sellerId = product.getSellerId();
	cat_1 = product.getCat_1();
	cat_2 = product.getCat_2();
	cat_3 = product.getCat_3();
}

Product::~Product() {}

int Product::getId()
{
	return id;
}

string Product::getName()
{
	return name;
}

string Product::getPicPath()
{
	return picPath;
}

int Product::getPrice()
{
	return price;
}
int Product::getAmount()
{
	return amount;
}
int Product::getSellerId()
{
	return sellerId;
}
int Product::getCat_1()
{
	return cat_1;
}
int Product::getCat_2()
{
	return cat_2;
}
int Product::getCat_3()
{
	return cat_3;
}

void Product::setId(int _id)
{
	id = _id;
}

void Product::setAmount(int _amount)
{
	amount = _amount;
}

//���� ���� �Է�
void Product::setProduct(int _id, int _price, int _amount, int _sellerId, int _cat1, int _cat2, int _cat3, string _name, string _picPath)
{
	id = _id; price = _price; amount = _amount; sellerId = _sellerId; cat_1 = _cat1; cat_2 = _cat2; cat_3 = _cat3; name = _name; picPath = _picPath;
}

void Product::printProductList()
{
	cout << id  << "\t" << name << "\t" << price <<  "\t" << amount <<  "\t" << picPath << endl;
}

//����� ���� ���
void Product::printProductInfo(title* title)
{
	cout << "ID\t: " << id << endl;
	cout << "�̸�\t: " << name << endl;
	cout << "����\t: " << picPath << endl;
	cout << "����\t: " << price << endl;
	cout << "����\t: " << amount << endl;
	cout << "�Ǹ���\t: " << sellerId << endl;
	cout << "��з�\t: " << (title + cat_1 - 1)->category_title << endl;
	cout << "�ߺз�\t: " << (title + cat_2 - 1)->category_title << endl;
	cout << "�Һз�\t: " << (title + cat_3 - 1)->category_title << endl;
}

// Compare two itemtypes by ID.
RelationType Product::CompareByID(Product &data)
{
	if (this->id > data.getId())
		return GREATER;
	else if (this->id > data.getId())
		return LESS;
	else
		return EQUAL;
}

bool Product::operator <(Product data)
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

bool Product::operator >(Product data)
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

bool Product::operator ==(Product data)
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