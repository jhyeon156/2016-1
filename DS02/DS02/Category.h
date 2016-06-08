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
	int getSizeCat1(); //대분류개수
	int getSizeCat2(); //중분류개수
	int getSizeCat3(); //소분류개수
	int getSize(); //전체개수
	int getId();
	int getDep(); //단계구분
	string getName();
	int getPrev(); //자신의 위의 분류의 카테고리 id
	LinkedList<int>* getList();

	void setCategory(int _id, int _prev, string _name, int _dep);
	//해당 소분류의 item목록 캐싱
	void setList(LinkedList<Product>& list);
	//해당 카테고리의 다음 카테고리 출력
	int findNext(int id);
	void print();
};