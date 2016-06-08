#include <iostream>
#include <string>
#include <fstream>
#include "Category.h"

using namespace std;

Category::Category()
{
	sizeCat1 = 3;
	sizeCat2 = 10;
	sizeCat3 = 20;
}

int Category::getSizeCat1()
{
	return sizeCat1;
}

int Category::getSizeCat2()
{
	return sizeCat2;
}
int Category::getSizeCat3()
{
	return sizeCat3;
}

int Category::getSize()
{
	return sizeCat1+sizeCat2+sizeCat3;
}

int Category::getId()
{
	return id;
}

int Category::getDep()
{
	return dep;
}

string Category::getName()
{
	return name;
}

int Category::getPrev()
{
	return prev;
}

LinkedList<int>* Category::getList()
{
	return &cateProductList;
}

void Category::setCategory(int _id, int _prev, string _name, int _dep)
{
	id = _id; prev = _prev; name = _name; dep = _dep;
}

void Category::setList(LinkedList<Product>& list)
{
	Product temp;

	list.ResetList();

	for (int i = 0; i < list.GetLength(); i++)
	{
		list.GetNextItem(temp);
		if (temp.getCat_3() == id)
		{
			cateProductList.Add(temp.getId());
		}
	}
}

int Category::findNext(int _id)
{
	if (prev == _id)
		return id;
	else
		return -1;
}

void Category::print()
{
	cout << "카테고리명 : " << name << " - " << id << endl;
}