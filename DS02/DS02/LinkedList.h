#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H


/**
*	Structure for NodeType to use in Linked structure.
*/
template <typename T>
struct NodeType
{
	T data;	///< A data for each node.
	NodeType* next;	///< A node pointer to point succeed node.
};


/**
*	Simple unsorted list class for managing items.
*/
template <typename T>
class LinkedList
{
public:
	/**
	*	default constructor.
	*/
	LinkedList();   

	/**
	*	default constructor.
	*/
	LinkedList(LinkedList<T>& list);

	/**
	*	destructor.
	*/
	~LinkedList();   
	
	/**
	*	@brief	Initialize list to empty state.
	*	@pre	None
	*	@post	List is empty.
	*/
	void MakeEmpty();

	/**
	*	@brief	Get number of elements in the list.
	*	@pre	None.
	*	@post	Function value = number of elements in list.
	*	@return	Number of elements in this list.
	*/
	int GetLength() const;

	/**
	*	@brief	Add item into this list.
	*	@pre	List is not full. item is not in list. 
	*	@post	Item is inserted in this list.
	*	@return	1 if this function works well, otherwise 0.
	*/
	int Add(T item);

	/**
	*	@brief	��带 �����Ѵ�.
	*	@pre	List is not full. item is not in list.
	*	@post	Item is deleted in this list.
	*	@return	1 if this function works well, otherwise 0.
	*/
	int Delete(T item);

	/**
	*	@brief	��带 �����Ѵ�.
	*	@pre	List is not full. item is not in list.
	*	@post	Item is replaced in this list.
	*	@return	1 if this function works well, otherwise 0.
	*/
	int Replace(T item);

	/**
	*	@brief	Retrieve list element whose key matches item's key (if present).
	*	@pre	Key member of item is initialized.
	*	@post	If there is an element whose key matches with item's key then the element's record is copied to the item.
	*	@return	1 if any element's primary key matches with item's, otherwise 0.
	*/
	int Get(T& item);

	/**
	*	@brief	Initialize current pointer for an iteration through the list.
	*	@pre	None.
	*	@post	current pointer is prior to list. current pointer has been initialized.
	*/
	void ResetList();

	/**
	*	@brief	Get the next element in list.
	*	@pre	current pointer is defined. Element at current pointer is not last in list.
	*	@post	current pointer is updated to next position. item is a copy of element at current pointer.
	*/
	void GetNextItem(T& item);
	
private:
	NodeType<T>* m_pList;	///< Pointer for pointing a first node.
	NodeType<T>* m_pCurPointer;	///< Node pointer for pointing current node to use iteration.
	int m_nLength;	///< Number of node in the list.
};


// Class constructor
template <typename T>
LinkedList<T>::LinkedList()
{
	m_nLength = 0;
	m_pList = NULL;
	m_pCurPointer = NULL;
}

// Class constructor
template <typename T>
LinkedList<T>::LinkedList(LinkedList<T>& list)
{
	m_nLength = list.m_nLength;
	m_pList = list.m_pList;
	m_pCurPointer = list.m_pCurPointer;
}

// Class destructor
template <typename T>
LinkedList<T>::~LinkedList()
{
	//����Ʈ���� ��� node ����
	MakeEmpty();
}


// Initialize list to empty state.
template <typename T>
void LinkedList<T>::MakeEmpty()
// Post: List is empty; all items have been deallocated.
{
	// ����Ʈ���� ��� ��� ���� �ϰ� ����Ʈ�� length�� �ʱ�ȭ
	NodeType<T>* tempPtr;
	
    while (m_pList != NULL)
    {
        tempPtr = m_pList;
        m_pList = m_pList->next;
        delete tempPtr;
    }
    
	m_nLength = 0;
}


// Get number of elements in the list.
template <typename T>
int LinkedList<T>::GetLength() const
{
	return m_nLength;
}


// Add item into this list.
template <typename T>
int LinkedList<T>::Add(T item)
{
	// ����Ʈ�� �߰��� ���ο� node ��ü�� ���� ��带 ����ų ������ ����
	NodeType<T> *node = new NodeType<T>;
	NodeType<T> *pre;
	T dummy;
	bool bFound = false;
	
	// node ��ü�� �Է¹��� ������ ���� �� �ʱ�ȭ
	node->data = item;									
	node->next = NULL;

	pre = m_pList;

	// ����Ʈ �ʱ�ȭ
	ResetList();

	if (Get(item))
	{
		return 0;
	}

	// list �� node �� �������� �ʴ� ���
	if( !m_nLength )
	{
		m_pList = node; //���۳�忡 �߰��ϰ��� �ϴ� ��� �߰�
	}
	// list �� node �� �ϳ� �̻� �����ϴ� ���
	else
	{
		GetNextItem(dummy); //�ϳ��̻� �����Ƿ� ������ �̵�
		while (m_pCurPointer != NULL) //���� �ƴ� ��
		{
			if (item < m_pCurPointer->data) //�������� ������ġ�� ������ �����鼭
			{
				if (m_pCurPointer == m_pList) //�������̸�
				{
					node->next = m_pList;
					m_pList = node; //���� �����Ͱ� ��带 ���ϰ� �Ѵ�.
					break;
				}
				else //�������� �ƴϸ�
				{
					node->next = m_pCurPointer;
					pre->next = node; //���������� ���� �����Ͱ� ���� ���ϰ� �Ѵ�.
					break;
				}
			}
			else //�������� ������ġ���� ũ�� ������ �� ���� �߰��ؾ��Ѵ�.
			{
				if (m_pCurPointer->next == NULL) //���� �������̸�
				{
					node->next = m_pCurPointer->next; //����� �������� ���������� NULL�̴�
					m_pCurPointer->next = node; //���� �������� ������ �߰����� ����Ű�� �Ѵ�.
					break;
				}
				else
				{
					pre = m_pCurPointer; //�������� �������
					GetNextItem(dummy); //�������ȣ��
				}
			}
		}
	}
	m_nLength++; //�߰��� ����̹Ƿ� ���� �߰�
	return 1;
}

//���ϴ� ��ġ�� �ڷḦ �����ϴ� �޼ҵ� ���� �ڷ�� 0�� ����Ѵ�.
template <typename T>
int LinkedList<T>::Delete(T item)
{
	// �����Ϸ��� ��� �˻��� ���� ���ο� ������ ������ ����
	NodeType<T>* pre;

	T dummy;//iterator�� ������ ���� ����

	pre = m_pList; //���� ����Ű�� ��� ���� ���

	if (!Get(item)) //������ �˻��� ���� �ʴ´�.
	{
		return 0;
	}
	//������
	ResetList(); //iterator ����
	GetNextItem(dummy); //���۳�忡�� ���
	while (m_pCurPointer != NULL) //����Ʈ�� ������
	{
		// ���۳���� ���� ���� ó��
		if (m_pCurPointer == m_pList)
		{
			// ���� ù��° ��尡 ������ ����̸�
			if (item == m_pCurPointer->data)
			{
				m_pCurPointer = m_pList; //���� ����Ű�� �����͸� ���۳��� 
				m_pList = m_pList->next; //ù��° ��带 ù��°��尡 ����Ű�� ���(�ι�°)��
				delete m_pCurPointer;//�޸� ����
				m_nLength--; //���� ����
				ResetList();
				return 1;
			}
			else //�ƴѰ��
			{
				GetNextItem(dummy); //��������
			}
		}
		// �����Ϸ��� ��尡 ���� ���� ��尡 �ƴҰ�쿡
		else
		{
			if (item == m_pCurPointer->data) //�ش��尡 ������ ����̸�
			{
				pre->next = m_pCurPointer->next; //���� ��尡 ����Ű�� ��带 �������� next��
				delete m_pCurPointer;//�޸� ����
				m_nLength--;
				ResetList();
				return 1;
			}
			else
			{
				GetNextItem(dummy);
				pre = pre->next; //���� ���� �Ѿ��.
			}
		}
	}
	return 0;
}

//�ش��ϴ� ��带 �������ְ� ���� ��� 0�� ���
template <typename T>
int LinkedList<T>::Replace(T item)
{
	T temp;
	T dummy;

	temp = item;

	if (!Get(temp)) //�� ã���� ������ �������� �ʴ´�.
	{
		return 0;
	}
	else //ã���� �ش� ��带 ���ο� �ڷ��
	{
		ResetList(); //iterator ����
		GetNextItem(dummy); //���۳�忡�� ���
		while (m_pCurPointer != NULL)
		{
			if (m_pCurPointer->data == item)
			{
				m_pCurPointer->data = item;
				break;
			}
			else
			{
				GetNextItem(dummy);
			}
		}
		return 1;
	}

}

// Retrieve list element whose key matches item's key (if present).
template <typename T>
int LinkedList<T>::Get(T& item)
{
	bool moreToSearch, found;
	NodeType<T>* location;

	location = m_pList;
	found = false;
	moreToSearch = (location != NULL);

	while (moreToSearch && !found)
	{
		if (item == location->data)
		{
			found = true;
			item = location->data;
		}
		else
		{
			location = location->next;
			moreToSearch = (location != NULL);
		}
	}

	if(found)
		return 1;
	else
		return 0;
}


// Initializes current pointer for an iteration through the list.
template <typename T>
void LinkedList<T>::ResetList()
{	
	// current pointer �ʱ�ȭ
	m_pCurPointer = NULL;
}


// Gets the next element in list.
template <typename T>
void LinkedList<T>::GetNextItem(T& item)
{
	// current pointer �� NULL�̶�� ó�� node�� ����Ŵ.
	if (m_pCurPointer == NULL)
	{
		m_pCurPointer = m_pList;
	}
	else
		//current position �� ���� ���� �̵�
		m_pCurPointer = m_pCurPointer->next;

	//item �� current position �� info �� ����
	item = m_pCurPointer->data;
}


#endif	// LINKED_LIST