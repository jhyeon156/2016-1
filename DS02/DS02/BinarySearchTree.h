#ifndef _BinarySearchTree_h
#define _BinarySearchTree_h

#include <iostream>
#include <string>

template<class T>
struct BinaryTreeNode
{
	T data;   					//������
	BinaryTreeNode<T>* left;	//���ʳ�� - ������
	BinaryTreeNode<T>* right;	//�����ʳ�� - ū��
};

template<typename T>
class BinarySearchTree
{
private:
	BinaryTreeNode<T>* root;	// ���� ����Ű�� �ִ� ��� ���� ����

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
	*	@brief	Ʈ���� ����ִ��� ���θ� �˷��ش�.
	*	@pre	None.
	*	@post	None.
	*	@return ��������� true �ƴϸ� false�� ��ȯ
	*/
	bool IsEmpty() const;

	/**
	*	@brief	Ʈ���� �� á���� ���θ� �˷��ش�.
	*	@pre	None.
	*	@post	None.
	*	@return �� ���� true �ƴϸ� false�� ��ȯ
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
	*	@brief	��带 �����Ѵ�.
	*	@pre	Tree is not full. item is not in tree.
	*	@post	Item is deleted in this tree.
	*/
	void DeleteItem(T item);

	/**
	*	@brief	����ڷḦ �����Ѵ�.
	*	@pre	Ʈ���� �ʱ�ȭ �Ǿ��־�� �Ѵ�.
	*	@post	������ �ڷḦ item�� �����ϰ� found�� true�� �Ѵ�. ���� ��� found�� false�� �Ѵ�.
	*/
	void ReplaceItem(T& item, bool& found);

	/**
	*	@brief	�ڷ��� PK�� ���Ͽ� �ִ� ��� �ڷḦ �����Ѵ�.
	*	@pre	Ʈ���� �ʱ�ȭ �Ǿ��־�� �Ѵ�.
	*	@post	������ �ڷḦ item�� �����ϰ� found�� true�� �Ѵ�. ���� ��� found�� false�� �Ѵ�.
	*/
	void RetrieveItem(T& item, bool& found) const;

	/**
	*	@brief	���̳ʸ� ��ġ�� �̿��ؼ� Ʈ���� �ڷḦ ��� �����ش�.
	*	@pre	Ʈ���� �ʱ�ȭ �Ǿ��־�� �Ѵ�.
	*	@post	InOrder, PreOrder, PostOrder�� �ϳ��� ������� �ڷḦ ���
	*/
	void PrintTree(ostream &out) const;
};

// default constructor
template<typename T>
BinarySearchTree<T>::BinarySearchTree()
{
	root = NULL;		// root�� NULL�� �ʱ�ȭ
}

// default destructor
template<typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
	MakeEmpty();
}

//�� Ʈ���̸� 1, �ƴϸ� 0�� ��ȯ�Ѵ�.
template<typename T>
bool BinarySearchTree<T>::IsEmpty() const
{
	if (root == NULL)
		return true;
	else
		return false;
}

//�� ���� 1, �ƴϸ� 0�� ��ȯ�Ѵ�.
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

//����Ʈ�� ó�����·� �ʱ�ȭ�Ѵ�.
template<typename T>
void BinarySearchTree<T>::MakeEmpty()
{
	return MakeEmptyTree(root);
}

/**
*	@brief	MakeEmpty���� ������ Ʈ���� ���� ����Լ�
*	@pre	Ʈ���� �ڷᰡ �ִ�.
*	@post	Ʈ���� �ڷᰡ ����.
*/
template<typename T>
void MakeEmptyTree(BinaryTreeNode<T>* root)
{
	//root�� NULL�� �ƴ� �� - ��������
	if (root != NULL)
	{
		MakeEmptyTree(root->left);
		MakeEmptyTree(root->right);
		delete root;
	}
}

//Ʈ���� �ڷ� ������ �����´�.
template<typename T>
int BinarySearchTree<T>::GetLength() const
{
	return CountNodes(root);
}

/**
*	@brief	GetLength���� ������ ������ �ľ��ϴ� ����Լ�
*	@pre	Ʈ���� �ڷᰡ �ִ�.
*	@post	��������� �Ʒ��� ������ �ľ��ϴ� �Լ� ȣ�� �� �ջ��Ѵ�.
*	@return	�Ϻΰ� ������ 0, �ϳ��� ������ 1, �ٸ���� ����Լ� ȣ���� ���Ѵ�.
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

//Ʈ���� ����� �ڷḦ �߰��Ѵ�.
template<typename T >
void BinarySearchTree<T>::InsertItem(T item)
{
	bool found;

	//�ߺ����� �˻�
	Retrieve(root, item, found);
	if (found == true) //ã����
	{
		cout << "Data is already Existed" << endl;
	}
	Insert(root, item);
}

/**
*	@brief	������ ���� �־��ִ� ����Լ�
*	@pre	Ʈ���� �ʱ�ȭ �Ǿ��ִ�.
*	@post	Ʈ���� �ùٸ� ��ġ�� �ڷᰡ ����.
*/
template<typename T>
void Insert(BinaryTreeNode<T>*& root, T item)
{
	if (root == NULL)
	{
		//���� �� �ϳ��� ����� �ش�.
		root = new BinaryTreeNode<T>;
		root->right = NULL;
		root->left = NULL;
		root->data = item;
	}
	//�������
	else if (item < root->data)
	{
		Insert(root->left, item);
	}
	//ū���
	else if (item > root->data)
	{
		Insert(root->right, item);
	}
}

//��带 �����Ѵ�.
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
*	@brief	������ ���� ��ġ�� ã�� ����Լ�
*	@pre	Ʈ���� �ϳ� �̻��� �ڷᰡ �ִ�.
*	@post	Ʈ���� �ùٸ� ��ġ�� ã�� DeleteNode�� ȣ���Ѵ�.
*/
template <typename T>
void Delete(BinaryTreeNode<T>*& root, T item)
{
	//������� �ϴ� ���� ���� ��庸�� ���� ���
	if (item < root->data)
	{
		Delete(root->left, item);//��������
	}
	//������� �ϴ� ���� ���� ��庸�� ū ���
	else if (item > root->data)
	{
		Delete(root->right, item);//����������
	}
	else
	{
		DeleteNode(root);//�ش���ġ�̴�.
	}
}

/**
*	@brief	������ ��带 ���ִ� �Լ�
*	@pre	Ʈ���� �ϳ� �̻��� �ڷᰡ �ִ�.
*	@post	��尡 Ʈ������ �����Ǹ鼭 �ڷ����°� �����ȴ�.
*/
template <typename T>
void DeleteNode(BinaryTreeNode<T>*& root)
{
	T data;
	BinaryTreeNode<T>* tempPtr;
	tempPtr = root;

	//��������� ������ �� ���
	if (root->left == NULL)
	{
		//������ ���� �ٿ��ش�.
		root = root->right;
		delete tempPtr;
	}
	//��������� �������� �� ���
	else if (root->right == NULL)
	{
		//���� ���� �ٿ��ش�.
		root = root->left;
		delete tempPtr;
	}
	else
	{
		
		GetPredecessor(root->left, data);	//�ش��庸�� �����鼭 �� �߿��� ���� ū ���� �����´�.
		root->data = data;	//�ش� �����ͷ� ��ü
		Delete(root->left, data);	//����� ������ �����Ѵ�.
	}
}

/**
*	@brief	����� �����ʿ��� �� ��� ���� �� ���� �����͸� �����´�.
*	@pre	Ʈ���� �ϳ� �̻��� �ڷᰡ �ִ�.
*	@post	����� �����ʿ��� �� ��� ���� �� ���� �����͸� data�� ��ȯ.
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

//�ڷḦ �˻��ϰ� �ִ� ��� �����ؿ´�.
template<typename T>
void BinarySearchTree<T>::RetrieveItem(T& item, bool& found) const
{
	Retrieve(root, item, found);
}


/**
*	@brief	�ڷ��� PK�� ��ġ�ϴ� ��带 ã�� ���� ����Լ�
*	@pre	Ʈ���� �ʱ�ȭ �Ǿ��ִ�.
*	@post	�ڷ��� PK�� ��ġ�ϴ� ��尡 ���� ������ ����Լ��� ȣ���Ѵ�.
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
*	@brief	�ڷ��� PK�� ��ġ�ϴ� ��带 ã�� ���� ����Լ�
*	@pre	Ʈ���� �ʱ�ȭ �Ǿ��ִ�.
*	@post	�ڷ��� PK�� ��ġ�ϴ� ��尡 ���� ������ ����Լ��� ȣ���Ѵ�.
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
*	@brief	���̳ʸ���ġ�� �̿��ؼ� Ʈ������ �ڷḦ ��� ����Ѵ�.
*	@post	Ŀ�ǵ带 �Է¹޴´�.
*/
template<typename T>
void BinarySearchTree<T>::PrintTree(ostream& outFile) const
{
		PrintInOrderTraversal(root, outFile);
}

/**
*	@brief	���� ��ȸ(Inorder Traversal)�� ������ ������ ����ȴ�.
			1. ���� ���� Ʈ���� ���� ��ȸ�Ѵ�.
			2. ��带 �湮�Ѵ�.
			3. ������ ���� Ʈ���� ���� ��ȸ�Ѵ�.
			�� ������� �����͸� ����Ѵ�.
*	@pre	Ʈ���� �ʱ�ȭ �Ǿ��ִ�.
*	@post	��ȸ�� ������� ����Լ��� ȣ���Ѵ�.
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
*	@brief	���� ��ȸ(preorder)�� ������ ���� ������� �����Ѵ�. ��Ʈ ��忡�� �����ؼ�,
			1. ��带 �湮�Ѵ�.
			2. ���� ���� Ʈ���� ���� ��ȸ�Ѵ�.
			3. ������ ���� Ʈ���� ���� ��ȸ�Ѵ�.
			�� ������� �����͸� ����Ѵ�.
*	@pre	Ʈ���� �ʱ�ȭ �Ǿ��ִ�.
*	@post	��ȸ�� ������� ����Լ��� ȣ���Ѵ�.
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
*	@brief	���� ��ȸ(postorder)�� ������ ���� ������� �����Ѵ�.
			1. ���� ���� Ʈ���� ���� ��ȸ�Ѵ�.
			2. ������ ���� Ʈ���� ���� ��ȸ�Ѵ�.
			3. ��带 �湮�Ѵ�.
			�� ������� �����͸� ����Ѵ�.
*	@pre	Ʈ���� �ʱ�ȭ �Ǿ��ִ�.
*	@post	��ȸ�� ������� ����Լ��� ȣ���Ѵ�.
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