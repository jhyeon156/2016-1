#include <iostream>

using namespace std;

#define MAX_ITEMS 50

/**
*	@brief	Exception class thrown by Push when queue is full.
*/
class FullQueue
{
public:
	/**
	*	@brief	Display a message for full queue on screen.
	*/
	void print()
	{
		cout << "FullQueue exception thrown." << endl;
	}
};

/**
*	@brief	Exception class thrown by Dequeue when queue is empty.
*/
class EmptyQueue
{
public:
	/**
	*	@brief	Display a message for empty queue on screen.
	*/
	void print()
	{
		cout << "EmtpyQueue exception thrown." << endl;
	}
};

/**
*	@brief	Queue class.
*	@details	This class processes as First In, First Out (FIFO).
*/
template <class ItemType>
class CircularQueueType  
{
public:
	/**
	*	@brief	MAX_ITEMS max��ŭ�� ����� ���� ť�� �ʱ�ȭ�Ѵ�.
	*	@pre	The MAX_ITEMS is defined
	*	@post	Member of items points the allocated array.
	*/
	CircularQueueType();

	/**
	*	@brief	max��ŭ�� ����� ���� ť�� �ʱ�ȭ�Ѵ�.
	*	@pre	The max is defined
	*	@post	Member of items points the allocated array.
	*	@param	ť�� ������
	*/
	CircularQueueType(int max);

	/**
	*	@brief	Destruct the object. Free the array dynamically allocated.
	*	@pre	Release memory for stack pointer.
	*	@post	none.
	*/
	~CircularQueueType();

	/**
	*	@brief	Determines whether the queue is full.
	*	@pre	Queue has been initialized.
	*	@post	Function value = (Queue is full)
	*/
	bool IsFull();

	/**
	*	@brief	Determines whether the queue is empty.
	*	@pre	Queue has been initialized.
	*	@post	Function value = (Queue is empty)
	*/
	bool IsEmpty();

	/**
	*	@brief	ť���� ������ ��� �����Ѵ�.
	*	@pre	Queue has been initialized.
	*	@post	If (queue is full), FullQueue exception is thrown; otherwise, newItem is at the top of the queue.
	*/
	void MakeEmpty();

	/**
	*	@brief	ť�� ���ο� �ڷḦ �߰��Ѵ�.
	*	@pre	Queue has been initialized.
	*	@post	If (queue is full), FullQueue exception is thrown; otherwise, newItem is at the top of the queue.
	*/
	void EnQueue(ItemType newItem);

	/**
	*	@brief	ť�� ���� ���� ���� �ڷ���� ����Ѵ�.
	*	@pre	Queue has been initialized.
	*	@post	If (queue is empty), EmptyQueue exception is thrown; otherwise, bottom element has been removed from queue.
	*/
	void DeQueue(ItemType& item);

	/**
	*	@brief	Print all the items in the queue on screen
	*	@pre	Queue has been initialized.
	*	@post	None.
	*/
	void Print();

private:
	int m_iFront;			//ť�� ���� ��Ÿ���� �÷���
	int m_iRear;			//ť�� �ڸ� ��Ÿ���� �÷���
	int m_nMaxQueue;		//ť�� ������
	ItemType* m_pItems;		// ������Ÿ�� ������ ����

};


/***********************************************************************************************************************************************************/

// Allocate dynamic array whose size is MAX_ITEMS 8.
template <class ItemType>
CircularQueueType<ItemType>::CircularQueueType()
{
	m_nMaxQueue = MAX_ITEMS+1;		// ���� ť�� �ִ� ũ�⸦ MAX_ITEM +1�� �����ؼ� ��ĭ�� ����Ѵ�.
	m_iFront = m_nMaxQueue-1;		// ���� ť�� ���θ� �ִ�ũ�� -1 �� ����
	m_iRear = m_nMaxQueue-1;			// ���� ť�� �Ĺ̸� �ִ�ũ�� -1 �� ����
	m_pItems = new ItemType[m_nMaxQueue];  
}

// ť�� ����� �޾ƿ� ��ŭ �Ҵ����ش�.
template <class ItemType>
CircularQueueType<ItemType>::CircularQueueType(int max)
{
	m_nMaxQueue = max+1;			// ���� ť�� �ִ� ũ�⸦ max�� �����ؼ� ��ĭ�� ����Ѵ�.
	m_iFront =m_nMaxQueue-1;			// ���� ť�� ���θ� �ִ�ũ�� -1 �� ����
	m_iRear = m_nMaxQueue-1;			// ���� ť�� �Ĺ̸� �ִ�ũ�� -1 �� ����
	m_pItems = new ItemType[m_nMaxQueue];   
}

// Destruct the object. Free the array dynamically allocated.
template <class ItemType>
CircularQueueType<ItemType>::~CircularQueueType()
{
	delete [] m_pItems;
}

// Determines whether the queue is full.
template <class ItemType>
bool CircularQueueType<ItemType>::IsFull()
{
	if ((m_iRear + 1) % m_nMaxQueue == m_iFront)  // ���ο� �Ĺ��� ��ġ�� ���Ͽ� ť�� �����ִ��� Ȯ��. �Ĺ̰� ���θ� �����ϸ� �ȵ�.
		return true;
	else
		return false;
}

// Determines whether the queue is empty.
template <class ItemType>
bool CircularQueueType<ItemType>::IsEmpty()
{
	if (m_iFront == m_iRear) // ���ο� �Ĺ��� ��ġ�� ���Ͽ� ť�� ����ִ��� Ȯ��
		return true;
	else
		return false;
}

//ť�� ����ش�.
template <class ItemType>
void CircularQueueType<ItemType>::MakeEmpty()
{
	m_iFront = m_iRear;				// ���ο� �Ĺ��� ��ġ�� ���� �Ͽ� ť�� ���
}

// Adds newItem to the top of the queue.
template <class ItemType>
void CircularQueueType<ItemType>::EnQueue(ItemType newItem)
{
	if(IsFull())
	{
		throw FullQueue();
	}
	else
	{
		m_iRear = (m_iRear + 1) % m_nMaxQueue;		// ť�� ������ �ʾҴٸ� �Ĺ��� ��ġ�� �Ѵܰ� �ű��
		m_pItems[m_iRear] = newItem;				// �ű� ��ġ�� ���ο� ������ �迭�� �߰�
	}
}

// Removes top item from the queue.
template <class ItemType>
void CircularQueueType<ItemType>::DeQueue(ItemType& item)
{
	if(IsEmpty())
	{
		throw EmptyQueue();
	}
	else
	{
		m_iFront = (m_iFront+1) % m_nMaxQueue;		// ť�� ������� �ʴٸ� ������ ��ġ�� �Ѵܰ� �ű��
		item = m_pItems[m_iFront];					// �ű� ��ġ�� ������ �迭�� ����
	}
}

// Print all the items in the queue on screen
template <class ItemType>
void CircularQueueType<ItemType>::Print()
{
	cout << "Queue: ";
	// Stack ���� ��� element ���.
	for (int i = (m_iFront + 1) % m_nMaxQueue; i != (m_iRear + 1) % m_nMaxQueue; i = (i + 1) % m_nMaxQueue) //ť�� ó��+1���� ����ؼ� ť�� ���������� Ȯ���Ѵ�. ��� �˻��� mod�� ��ȯ�ϰ� �Ѵ�.
	{
		cout << m_pItems[i] << " - ";
	}
	cout << endl;
}