#ifndef _BinarySearchTree_h
#define _BinarySearchTree_h

#include <iostream>
#include <string>

template<class T>
struct BinaryTreeNode
{
	T data;   					//데이터
	BinaryTreeNode<T>* left;	//왼쪽노드 - 작은값
	BinaryTreeNode<T>* right;	//오른쪽노드 - 큰값
};

template<typename T>
class BinarySearchTree
{
private:
	BinaryTreeNode<T>* root;	// 현재 가리키고 있는 노드 변수 선언

public:
	/**
	*	default constructor.
	*/
	BinarySearchTree();

	/**
	*	destructor.
	*/
	~BinarySearchTree();

	/**
	*	@brief	트리가 비어있는지 여부를 알려준다.
	*	@pre	None.
	*	@post	None.
	*	@return 비어있으면 true 아니면 false를 반환
	*/
	bool IsEmpty() const;

	/**
	*	@brief	트리가 꽉 찼는지 여부를 알려준다.
	*	@pre	None.
	*	@post	None.
	*	@return 꽉 차면 true 아니면 false를 반환
	*/
	bool IsFull() const;

	/**
	*	@brief	Initialize tree to empty state.
	*	@pre	None
	*	@post	Tree is empty.
	*/
	void MakeEmpty();

	/**
	*	@brief	Get number of elements in the tree.
	*	@pre	None.
	*	@post	Function value = number of elements in tree.
	*	@return	Number of elements in this tree.
	*/
	int GetLength() const;

	/**
	*	@brief	Add item into this tree.
	*	@pre	Tree is not full. item is not in tree.
	*	@post	Item is inserted in this tree.
	*/
	void InsertItem(T item);

	/**
	*	@brief	노드를 삭제한다.
	*	@pre	Tree is not full. item is not in tree.
	*	@post	Item is deleted in this tree.
	*/
	void DeleteItem(T item);

	/**
	*	@brief	노드자료를 수정한다.
	*	@pre	트리가 초기화 되어있어야 한다.
	*	@post	있으면 자료를 item에 복사하고 found를 true로 한다. 없는 경우 found를 false로 한다.
	*/
	void ReplaceItem(T& item, bool& found);

	/**
	*	@brief	자료의 PK를 비교하여 있는 경우 자료를 복사한다.
	*	@pre	트리가 초기화 되어있어야 한다.
	*	@post	있으면 자료를 item에 복사하고 found를 true로 한다. 없는 경우 found를 false로 한다.
	*/
	void RetrieveItem(T& item, bool& found) const;

	/**
	*	@brief	바이너리 서치를 이용해서 트리의 자료를 모두 보여준다.
	*	@pre	트리가 초기화 되어있어야 한다.
	*	@post	InOrder, PreOrder, PostOrder중 하나의 방법으로 자료를 출력
	*/
	void PrintTree(ostream &out) const;
};

// default constructor
template<typename T>
BinarySearchTree<T>::BinarySearchTree()
{
	root = NULL;		// root를 NULL로 초기화
}

// default destructor
template<typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
	MakeEmpty();
}

//빈 트리이면 1, 아니면 0을 반환한다.
template<typename T>
bool BinarySearchTree<T>::IsEmpty() const
{
	if (root == NULL)
		return true;
	else
		return false;
}

//꽉 차면 1, 아니면 0을 반환한다.
template<typename T >
bool BinarySearchTree<T>::IsFull() const
{
	BinaryTreeNode<T>* location;
	try
	{
		location = new BinaryTreeNode<T>;
		delete location;
		return false;
	}
	catch (std::bad_alloc exception)
	{
		return true;
	}
}

//리스트를 처음상태로 초기화한다.
template<typename T>
void BinarySearchTree<T>::MakeEmpty()
{
	return MakeEmptyTree(root);
}

/**
*	@brief	MakeEmpty에서 실제로 트리를 비우는 재귀함수
*	@pre	트리에 자료가 있다.
*	@post	트리에 자료가 없다.
*/
template<typename T>
void MakeEmptyTree(BinaryTreeNode<T>* root)
{
	//root가 NULL이 아닌 한 - 기저상태
	if (root != NULL)
	{
		MakeEmptyTree(root->left);
		MakeEmptyTree(root->right);
		delete root;
	}
}

//트리의 자료 개수를 가져온다.
template<typename T>
int BinarySearchTree<T>::GetLength() const
{
	return CountNodes(root);
}

/**
*	@brief	GetLength에서 실제로 개수를 파악하는 재귀함수
*	@pre	트리에 자료가 있다.
*	@post	재귀적으로 아래의 개수를 파악하는 함수 호출 후 합산한다.
*	@return	하부가 없으면 0, 하나만 있으면 1, 다른경우 재귀함수 호출후 더한다.
*/
template<typename T>
int CountNodes(BinaryTreeNode<T>* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	else if (root->left == NULL)
	{
		return CountNodes(root->right) + 1;
	}
	else if (root->right == NULL)
	{
		return CountNodes(root->left) + 1;
	}
	else
	{
		return CountNodes(root->left) + CountNodes(root->right) + 1;
	}
}

//트리에 새료운 자료를 추가한다.
template<typename T >
void BinarySearchTree<T>::InsertItem(T item)
{
	bool found;

	//중복여부 검사
	Retrieve(root, item, found);
	if (found == true) //찾으면
	{
		cout << "Data is already Existed" << endl;
	}
	Insert(root, item);
}

/**
*	@brief	실제로 값을 넣어주는 재귀함수
*	@pre	트리가 초기화 되어있다.
*	@post	트리의 올바른 위치에 자료가 들어간다.
*/
template<typename T>
void Insert(BinaryTreeNode<T>*& root, T item)
{
	if (root == NULL)
	{
		//없을 시 하나를 만들어 준다.
		root = new BinaryTreeNode<T>;
		root->right = NULL;
		root->left = NULL;
		root->data = item;
	}
	//작은경우
	else if (item < root->data)
	{
		Insert(root->left, item);
	}
	//큰경우
	else if (item > root->data)
	{
		Insert(root->right, item);
	}
}

//노드를 삭제한다.
template<typename T>
void BinarySearchTree<T>::DeleteItem(T item)
{
	Delete(root, item);
}

template<typename T>
void BinarySearchTree<T>::ReplaceItem(T & item, bool & found)
{
	RetrieveItem(item, found);
	if (found)
	{
		Replace(root, item, found);
		return;
	}
	else
	{
		return;
	}
}

/**
*	@brief	실제로 없앨 위치를 찾는 재귀함수
*	@pre	트리에 하나 이상의 자료가 있다.
*	@post	트리의 올바른 위치를 찾아 DeleteNode를 호출한다.
*/
template <typename T>
void Delete(BinaryTreeNode<T>*& root, T item)
{
	//지우고자 하는 값이 현재 노드보다 작은 경우
	if (item < root->data)
	{
		Delete(root->left, item);//왼쪽으로
	}
	//지우고자 하는 값이 현재 노드보다 큰 경우
	else if (item > root->data)
	{
		Delete(root->right, item);//오른쪽으로
	}
	else
	{
		DeleteNode(root);//해당위치이다.
	}
}

/**
*	@brief	실제로 노드를 없애는 함수
*	@pre	트리에 하나 이상의 자료가 있다.
*	@post	노드가 트리에서 삭제되면서 자료형태가 유지된다.
*/
template <typename T>
void DeleteNode(BinaryTreeNode<T>*& root)
{
	T data;
	BinaryTreeNode<T>* tempPtr;
	tempPtr = root;

	//삭제노드의 왼쪽이 빈 경우
	if (root->left == NULL)
	{
		//오른쪽 값을 붙여준다.
		root = root->right;
		delete tempPtr;
	}
	//삭제노드의 오른쪽이 빈 경우
	else if (root->right == NULL)
	{
		//왼쪽 값을 붙여준다.
		root = root->left;
		delete tempPtr;
	}
	else
	{
		
		GetPredecessor(root->left, data);	//해당노드보다 작으면서 그 중에서 제일 큰 값을 가져온다.
		root->data = data;	//해당 데이터로 대체
		Delete(root->left, data);	//노드의 왼쪽을 삭제한다.
	}
}

/**
*	@brief	노드의 오른쪽에서 빈 노드 나올 때 까지 데이터를 가져온다.
*	@pre	트리에 하나 이상의 자료가 있다.
*	@post	노드의 오른쪽에서 빈 노드 나올 때 까지 데이터를 data로 반환.
*/
template <typename T>
void GetPredecessor(BinaryTreeNode<T>* root, T data)
{
	{
		while (root->right != NULL)
		{
			root = root->right;
		}
		data = root->data;
	}
}

//자료를 검색하고 있는 경우 복사해온다.
template<typename T>
void BinarySearchTree<T>::RetrieveItem(T& item, bool& found) const
{
	Retrieve(root, item, found);
}


/**
*	@brief	자료의 PK와 일치하는 노드를 찾기 위한 재귀함수
*	@pre	트리가 초기화 되어있다.
*	@post	자료의 PK와 일치하는 노드가 나올 때까지 재귀함수를 호출한다.
*/
template<typename T>
void Retrieve(BinaryTreeNode<T>* root, T& item, bool& found)
{
	if (root == NULL)
	{
		found = false;
	}
	else if (item < root->data)
	{
		Retrieve(root->left, item, found);
	}
	else if (item > root->data)
	{
		Retrieve(root->right, item, found);
	}
	else
	{
		item = root->data;
		found = true;
	}
}

/**
*	@brief	자료의 PK와 일치하는 노드를 찾기 위한 재귀함수
*	@pre	트리가 초기화 되어있다.
*	@post	자료의 PK와 일치하는 노드가 나올 때까지 재귀함수를 호출한다.
*/
template<typename T>
void Replace(BinaryTreeNode<T>* root, T& item, bool& found)
{
	if (root == NULL)
	{
		found = false;
		return;
	}
	else if (item < root->data)
	{
		Retrieve(root->left, item, found);
	}
	else if (item > root->data)
	{
		Retrieve(root->right, item, found);
	}
	else
	{
		found = true;
		root->data = item;
		return;
	}
}

/**
*	@brief	바이너리서치를 이용해서 트리안의 자료를 모두 출력한다.
*	@post	커맨드를 입력받는다.
*/
template<typename T>
void BinarySearchTree<T>::PrintTree(ostream& outFile) const
{
		PrintInOrderTraversal(root, outFile);
}

/**
*	@brief	중위 순회(Inorder Traversal)은 다음의 순서로 진행된다.
			1. 왼쪽 서브 트리를 중위 순회한다.
			2. 노드를 방문한다.
			3. 오른쪽 서브 트리를 중위 순회한다.
			이 순서대로 데이터를 출력한다.
*	@pre	트리가 초기화 되어있다.
*	@post	순회의 순서대로 재귀함수를 호출한다.
*/
template<typename T>
void PrintInOrderTraversal(BinaryTreeNode<T>* root, std::ostream& outFile)
{
	if (root != NULL)
	{
		PrintInOrderTraversal(root->left, outFile);
		outFile << root->data;
		PrintInOrderTraversal(root->right, outFile);
	}
}

/**
*	@brief	전위 순회(preorder)는 다음과 같은 방법으로 진행한다. 루트 노드에서 시작해서,
			1. 노드를 방문한다.
			2. 왼쪽 서브 트리를 전위 순회한다.
			3. 오른쪽 서브 트리를 전위 순회한다.
			이 순서대로 데이터를 출력한다.
*	@pre	트리가 초기화 되어있다.
*	@post	순회의 순서대로 재귀함수를 호출한다.
*/
template<typename T>
void PrintPreOrderTraversal(BinaryTreeNode<T> *root, ostream &out)
{
	if (root != NULL)
	{
		out << root->data;
		PrintPreOrderTraversal(root->left, out);
		PrintPreOrderTraversal(root->right, out);
	}
}

/**
*	@brief	후위 순회(postorder)는 다음과 같은 방법으로 진행한다.
			1. 왼쪽 서브 트리를 후위 순회한다.
			2. 오른쪽 서브 트리를 후위 순회한다.
			3. 노드를 방문한다.
			이 순서대로 데이터를 출력한다.
*	@pre	트리가 초기화 되어있다.
*	@post	순회의 순서대로 재귀함수를 호출한다.
*/
template<typename T>
void PrintPostOrderTraversal(BinaryTreeNode<T> *root, ostream &out)
{
	if (root != NULL)
	{
		PrintPostOrderTraversal(root->left, out);
		PrintPostOrderTraversal(root->right, out);
		out << root->data;
	}
}
#endif