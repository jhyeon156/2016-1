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
	*	@brief	노드를 삭제한다.
	*	@pre	List is not full. item is not in list.
	*	@post	Item is deleted in this list.
	*	@return	1 if this function works well, otherwise 0.
	*/
	int Delete(T item);

	/**
	*	@brief	노드를 변경한다.
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
	//리스트내의 모든 node 제거
	MakeEmpty();
}


// Initialize list to empty state.
template <typename T>
void LinkedList<T>::MakeEmpty()
// Post: List is empty; all items have been deallocated.
{
	// 리스트내의 모든 노드 제거 하고 리스트의 length를 초기화
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
	// 리스트에 추가할 새로운 node 객체와 이전 노드를 가리킬 포인터 선언
	NodeType<T> *node = new NodeType<T>;
	NodeType<T> *pre;
	T dummy;
	bool bFound = false;
	
	// node 객체에 입력받은 데이터 설정 및 초기화
	node->data = item;									
	node->next = NULL;

	pre = m_pList;

	// 리스트 초기화
	ResetList();

	if (Get(item))
	{
		return 0;
	}

	// list 에 node 가 존재하지 않는 경우
	if( !m_nLength )
	{
		m_pList = node; //시작노드에 추가하고자 하는 노드 추가
	}
	// list 에 node 가 하나 이상 존재하는 경우
	else
	{
		GetNextItem(dummy); //하나이상 있으므로 앞으로 이동
		while (m_pCurPointer != NULL) //끝이 아닌 한
		{
			if (item < m_pCurPointer->data) //아이템이 현재위치의 값보다 작으면서
			{
				if (m_pCurPointer == m_pList) //시작점이면
				{
					node->next = m_pList;
					m_pList = node; //시작 포인터가 노드를 향하게 한다.
					break;
				}
				else //시작점이 아니면
				{
					node->next = m_pCurPointer;
					pre->next = node; //현재포인터 앞의 포인터가 앞을 향하게 한다.
					break;
				}
			}
			else //아이템이 현재위치보다 크면 앞으로 더 가서 추가해야한다.
			{
				if (m_pCurPointer->next == NULL) //만약 마지막이면
				{
					node->next = m_pCurPointer->next; //노드의 다음값은 실질적으로 NULL이다
					m_pCurPointer->next = node; //현재 포인터의 다음이 추가값을 가리키게 한다.
					break;
				}
				else
				{
					pre = m_pCurPointer; //이전값을 현재노드로
					GetNextItem(dummy); //다음노드호출
				}
			}
		}
	}
	m_nLength++; //추가된 경우이므로 길이 추가
	return 1;
}

//원하는 위치의 자료를 삭제하는 메소드 없는 자료는 0을 출력한다.
template <typename T>
int LinkedList<T>::Delete(T item)
{
	// 삭제하려는 노드 검색을 위해 새로운 포인터 변수를 선언
	NodeType<T>* pre;

	T dummy;//iterator를 돌리기 위한 빈노드

	pre = m_pList; //현재 가리키는 노드 앞의 노드

	if (!Get(item)) //없으면 검색이 되지 않는다.
	{
		return 0;
	}
	//있으면
	ResetList(); //iterator 리셋
	GetNextItem(dummy); //시작노드에서 출발
	while (m_pCurPointer != NULL) //리스트의 끝까지
	{
		// 시작노드의 경우는 따로 처리
		if (m_pCurPointer == m_pList)
		{
			// 만약 첫번째 노드가 삭제할 노드이면
			if (item == m_pCurPointer->data)
			{
				m_pCurPointer = m_pList; //현재 가리키는 포인터를 시작노드로 
				m_pList = m_pList->next; //첫번째 노드를 첫번째노드가 가리키는 노드(두번째)로
				delete m_pCurPointer;//메모리 해제
				m_nLength--; //길이 감소
				ResetList();
				return 1;
			}
			else //아닌경우
			{
				GetNextItem(dummy); //다음노드로
			}
		}
		// 삭제하려는 노드가 가장 앞의 노드가 아닐경우에
		else
		{
			if (item == m_pCurPointer->data) //해당노드가 삭제할 노드이면
			{
				pre->next = m_pCurPointer->next; //앞의 노드가 가리키는 노드를 현재노드의 next로
				delete m_pCurPointer;//메모리 해제
				m_nLength--;
				ResetList();
				return 1;
			}
			else
			{
				GetNextItem(dummy);
				pre = pre->next; //다음 노드로 넘어간다.
			}
		}
	}
	return 0;
}

//해당하는 노드를 변경해주고 없는 경우 0을 출력
template <typename T>
int LinkedList<T>::Replace(T item)
{
	T temp;
	T dummy;

	temp = item;

	if (!Get(temp)) //못 찾으면 변경을 실행하지 않는다.
	{
		return 0;
	}
	else //찾으면 해당 노드를 새로운 자료로
	{
		ResetList(); //iterator 리셋
		GetNextItem(dummy); //시작노드에서 출발
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
	// current pointer 초기화
	m_pCurPointer = NULL;
}


// Gets the next element in list.
template <typename T>
void LinkedList<T>::GetNextItem(T& item)
{
	// current pointer 이 NULL이라면 처음 node를 가리킴.
	if (m_pCurPointer == NULL)
	{
		m_pCurPointer = m_pList;
	}
	else
		//current position 을 다음 노드로 이동
		m_pCurPointer = m_pCurPointer->next;

	//item 에 current position 의 info 를 삽입
	item = m_pCurPointer->data;
}


#endif	// LINKED_LIST