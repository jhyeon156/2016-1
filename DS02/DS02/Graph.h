#pragma once

#include "CircularQueue.h"
#include "Stack.h"

#define SIZE 20

template <typename T>
class Graph
{
public:
	/**
	*	@brief	SIZE��ŭ�� ����� ���� �׷����� �ʱ�ȭ�Ѵ�.
	*	@pre	SIZE is defined
	*	@post	�׷������� �迭���� SIZE��ŭ �ʱ�ȭ
	*/
	Graph();

	/**
	*	@brief	maxVertices��ŭ�� ����� ���� �׷����� �ʱ�ȭ�Ѵ�.
	*	@pre	maxVertices is defined
	*	@post	�׷������� �迭���� maxVertices��ŭ �ʱ�ȭ
	*	@param	�׷����� ������
	*/
	Graph(int maxVertices); 

	/**
	*	@brief	�Ҹ���.
	*	@pre	none.
	*	@post	�޸𸮿��� ��ü ��ȯ
	*/
	~Graph(); 

	/**
	*	@brief	����� ��� �����Ҵ��� ��ȯ�Ѵ�.
	*	@pre	none.
	*	@post	�޸𸮿��� ��ü ��ȯ
	*/
	void MakeEmpty(); 

	/**
	*	@brief	�׷����� ������� Ȯ���Ѵ�.
	*	@pre	�׷��� �ʱ�ȭ
	*	@post	none.
	*	@return	������� true�� ��ȯ�Ѵ�. �׷��� ������ false ��ȯ
	*/
	bool IsEmpty(); 

	/**
	*	@brief	�׷����� �� á���� Ȯ���Ѵ�.
	*	@pre	�׷��� �ʱ�ȭ
	*	@post	none.
	*	@return	�� á���� true�� ��ȯ�Ѵ�. �׷��� ������ false ��ȯ
	*/
	bool IsFull(); 

	/**
	*	@brief	����ϳ��� �߰��Ѵ�.
	*	@pre	�׷��� �ʱ�ȭ
	*	@post	����ϳ� �߰��ȴ�.
	*	@param	�߰��ϰ��� �ϴ� T
	*	@return	�߰��Ǹ� 1�� ��ȯ�Ѵ�. �׷��� ������ 0 ��ȯ
	*/
	int AddVertex(T vertex); 

	/**
	*	@brief	����ġ �ϳ��� �߰��Ѵ�.
	*	@pre	�׷��� �ʱ�ȭ
	*	@post	����ġ �ϳ� �߰��ȴ�.
	*	@param	��߳��, �������, ����ġ
	*	@return	�߰��Ǹ� 1�� ��ȯ�Ѵ�. �׷��� ������ 0 ��ȯ
	*/
	void AddEdge(T fromVertex, T toVertex, int weight);  

	/**
	*	@brief	��߳�忡�� ������������ ����ġ�� ��ȯ�ϴ� �Լ�
	*	@pre	�׷��� �ʱ�ȭ
	*	@post	none.
	*	@param	��߳��, �������
	*	@return	�ش��ϴ� �迭�� ����ġ�� ��ȯ.
	*/
	int WeightIs(T fromVertex, T toVertex);  

	/**
	*	@brief	vertex �� ���� vertex �� queue �� ����
	*	@pre	�׷��� �ʱ�ȭ�Ǿ��ְ� ����� ��尡 �־�� �Ѵ�.
	*	@post	ť�� �ش� ��尡 ����.
	*	@param	��߳��, ��带 �ְԵ� ť
	*/
	void GetToVertices(T vertex, CircularQueueType<T>& adgVertices);  

	/**
	*	@brief	mark ������ ���� 
	*	@pre	�׷��� �ʱ�ȭ
	*	@post	isMark�迭�� ��� 0���� ����.
	*/
	void ClearMarks();

	/**
	*	@brief	vertex�� �ι� ��ȸ���� �ʰ� ������ ���ش�.
	*	@pre	�׷��� �ʱ�ȭ
	*	@post	isMark�迭�� �ش� ��ġ�� 1�� ����
	*	@param	�ش� ���
	*/
	void MarkVertex(T vertex); 

	/**
	*	@brief	vertex�� �̹� ��ȸ�Ǿ����� Ȯ�����ش�.
	*	@pre	�׷��� �ʱ�ȭ
	*	@post	isMark�迭�� �ش� ��ġ�� 1�� ����
	*	@param	�ش� ���
	*/
	bool IsMarked(T vertex); 

	/**
	*	@brief	��� vertex�� ����Ѵ�.
	*	@pre	�׷��� �ʱ�ȭ
	*	@post	none.
	*/
	void PrintVertices(); 

	/**
	*	@brief	��� edge�� ����Ѵ�.
	*	@pre	�׷��� �ʱ�ȭ
	*	@post	none.
	*/
	void PrintEdges(); 
private:
	int numvertices; // ���� ��� ���� 
	int maxVertices; // �ִ� ���� ���� 
	T* vertices; // vertex ���� ������ ����Ű�� ������ 
	int** edges; // weighted edge ���� ������ ����Ű�� ������ 
	bool* marks; // mark ���� ������ ����Ű�� ������
};

// constructor 
template <typename T>
Graph<T>::Graph()
{
	numvertices = 0;
	maxVertices = SIZE;
	vertices = new T[SIZE];
	marks = new bool[SIZE];

	edges = new int* [SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		edges[i] = new int[SIZE];
	}

	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			edges[i][j] = 0;
}

// constructor 
template <typename T>
Graph<T>::Graph(int maxVertices)
{
	numvertices = 0;
	this.maxVertices = maxVertices;
	vertices = new T[maxVertices];
	marks = new bool[maxVertices];

	edges = new int[maxVertices];
	for (int i = 0; i < maxVertices; i++)
	{
		edges[i] = new int[maxVertices];
	}
}

// destructor
template <typename T>
Graph<T>::~Graph()
{
	delete[] vertices;
	delete[] marks;
	for (int i = 0; i<maxVertices; i++)
	{
		delete[] edges[i];
	}
	delete[] edges;
}

// graph �� ���
template<typename T>
void Graph<T>::MakeEmpty()
{
	numvertices = 0;
}

// vertices �� ��� �ִ��� Ȯ�� 
template<typename T>
bool Graph<T>::IsEmpty()
{
	if (numvertices == 0)
		return true;
	else
		return false;
}

// vertices �� ���� á���� Ȯ�� 
template<typename T>
bool Graph<T>::IsFull()
{
	if (numvertices == maxVertices)
		return true;
	else
		return false;
}

// ���ο� vertex �� �߰� 
template<typename T>
int Graph<T>::AddVertex(T vertex)
{
	if (!IsFull())
	{
		vertices[numvertices] = vertex;
		numvertices++;
		return 1;
	}
	else
		return 0;
}

// �� vertex �� �����ϴ� weighted edge �߰� 
template<typename T>
void Graph<T>::AddEdge(T fromVertex, T toVertex, int weight)
{
	//M-ij���� i�� from j�� to
	int fromIndex = IndexIs(vertices, fromVertex, numvertices);
	int toIndex = IndexIs(vertices, toVertex, numvertices);
	edges[fromIndex][toIndex] = weight;
	return;
}

// fromVertex ���� toVertex �� �ش��ϴ� edge weight 
template<typename T>
int Graph<T>::WeightIs(T fromVertex, T toVertex)
{
	int fromIndex = IndexIs(vertices, fromVertex, numvertices);
	int toIndex = IndexIs(vertices, toVertex, numvertices);
	return edges[fromIndex][toIndex];
}

// vertex �� ���� vertex �� queue �� ����
template<typename T>
void Graph<T>::GetToVertices(T vertex, CircularQueueType<T>& adgVertices)
{
	int index = IndexIs(vertices, vertex, numvertices);
	for (int i = 0; i < numvertices; i++)
	{
		if (edges[index][i] > 0)
		{
			adgVertices.EnQueue(vertices[i]);
		}
	}
	return;
}

// mark ������ ���� 
template<typename T>
void Graph<T>::ClearMarks()
{
	for (int i = 0; i < numvertices; i++)
	{
		marks[i] = false;
	}
	return;
}

// vertex �� mark
template<typename T>
void Graph<T>::MarkVertex(T vertex)
{
	int index = IndexIs(vertices, vertex, numvertices);
	marks[index] = true;
	return;
}

// vertex �� mark ���� Ȯ�� 
template<typename T>
 bool Graph<T>::IsMarked(T vertex)
{
	int index = IndexIs(vertices, vertex, numvertices);
	return marks[index];
}

 // ��� ��� �Լ� 
template<typename T>
void Graph<T>::PrintVertices()
{
	for (int i = 0; i < numvertices; i++)
	{
		cout << vertices[i] << " - ";
	}
	return;
}

// Weight ��� �Լ�
template<typename T>
void Graph<T>::PrintEdges()
{
	for (int from = 0; from < numvertices; from++)
	{
		for (int to = 0; to < numvertices; to++)
		{
			if (from != to && edges[from][to] != NULL)
			{
				cout << "\n\t";
				cout << vertices[from] << " -> " << vertices[to] << " : ";
				cout << edges[from][to] << endl;
			}
		}
	}
	return;
}


/////////////////////////////////�����Լ�////////////////////////////////////////


/**
*	@brief	Vertex�� index ���� �Լ�
*	@pre	��尡 �ϳ��̻� �־���Ѵ�.
*	@post	none.
*	@param	���迭, ã���� �ϴ� ���, ��ü ��� ����.
*	@return	�ش��ϴ� ����� �ε��� ���, ������ -1����
*/
template<class T>
int IndexIs(T* vertices, T vertex, int vertexNum)
{
	for (int i = 0; i < vertexNum; i++)
	{
		if (vertices[i] == vertex)
			return i;
	}
	return -1;
}

/**
*	@brief	BFS��� Ž���Լ�
*	@pre	��尡 �ϳ��̻� �־�� �ϸ� �̾��� �־�� �Ѵ�.
*	@post	��θ� ����Ѵ�.
*	@param	��� �˻��� �׷���, ��� ���, ���� ����.
*/
template<class T>
void BreadthFirstSearch(Graph<T>& graph, T startVertex, T endVertex)
{
	CircularQueueType<T> queue;
	CircularQueueType<T> vertexQ;

	bool found = false;
	T vertex;
	T item;

	graph.ClearMarks();
	queue.EnQueue(startVertex);

	do
	{
		queue.DeQueue(vertex);

		if (vertex == endVertex)
		{
			cout << vertex << " - ";
			found = true;
		}
		else
		{
			if (!graph.IsMarked(vertex))
			{
				graph.MarkVertex(vertex);
				cout << vertex << " - ";
				graph.GetToVertices(vertex, vertexQ);

				while (!vertexQ.IsEmpty())
				{
					vertexQ.DeQueue(item);
					if (!graph.IsMarked(item))
						queue.EnQueue(item);
				}
			}
		}
	} while (!queue.IsEmpty() && !found);

	if (!found)
		cout << "\tPath not found." << endl;
}

/**
*	@brief	DFS��� Ž���Լ�
*	@pre	��尡 �ϳ��̻� �־�� �ϸ� �̾��� �־�� �Ѵ�.
*	@post	��θ� ����Ѵ�.
*	@param	��� �˻��� �׷���, ��� ���, ���� ����.
*/
template<class T>
void DepthFirstSearch(Graph<T>& graph, T startVertex, T endVertex)
{
	Stack<T> stack;
	CircularQueueType<T> vertexQ;

	bool found = false;
	T vertex;
	T item;

	graph.ClearMarks();
	stack.Push(startVertex);
	do
	{
		vertex = stack.Pop();
		if (vertex == endVertex)
		{
			cout << vertex << " - ";
			found = true;
		}
		else
		{
			if (!graph.IsMarked(vertex))
			{
				graph.MarkVertex(vertex);
				cout << vertex << " - ";
				graph.GetToVertices(vertex, vertexQ);

				while (!vertexQ.IsEmpty())
				{
					vertexQ.DeQueue(item);
					if (!graph.IsMarked(item))
						stack.Push(item);
				}
			}
		}
	} while (!stack.IsEmpty() && !found);

	if (!found)
		cout << "\tPath not found." << endl;
}