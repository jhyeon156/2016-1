#pragma once
#include <string>
#include "LinkedList.h"
#include "Product.h"

using namespace std;

class Category {
private:
	int sizeCat1;
	int sizeCat2;
	int sizeCat3;
	int size;
	int id;
	int dep;
	string name;
	int prev;
	LinkedList<int> cateProductList;
public:
	Category();
	int getSizeCat1(); //��з�����
	int getSizeCat2(); //�ߺз�����
	int getSizeCat3(); //�Һз�����
	int getSize(); //��ü����
	int getId();
	int getDep(); //�ܰ豸��
	string getName();
	int getPrev(); //�ڽ��� ���� �з��� ī�װ� id
	LinkedList<int>* getList();

	void setCategory(int _id, int _prev, string _name, int _dep);
	//�ش� �Һз��� item��� ĳ��
	void setList(LinkedList<Product>& list);
	//�ش� ī�װ��� ���� ī�װ� ���
	int findNext(int id);
	void print();
};