#pragma once

#include "CircularQueue.h"
#include "Stack.h"

#define SIZE 20

template <typename T>
class Graph
{
public:
	/**
	*	@brief	SIZE만큼의 사이즈를 가진 그래프를 초기화한다.
	*	@pre	SIZE is defined
	*	@post	그래프안의 배열들이 SIZE만큼 초기화
	*/
	Graph();

	/**
	*	@brief	maxVertices만큼의 사이즈를 가진 그래프를 초기화한다.
	*	@pre	maxVertices is defined
	*	@post	그래프안의 배열들이 maxVertices만큼 초기화
	*	@param	그래프의 사이즈
	*/
	Graph(int maxVertices); 

	/**
	*	@brief	소멸자.
	*	@pre	none.
	*	@post	메모리에서 객체 반환
	*/
	~Graph(); 

	/**
	*	@brief	사용한 모든 동적할당을 반환한다.
	*	@pre	none.
	*	@post	메모리에서 객체 반환
	*/
	void MakeEmpty(); 

	/**
	*	@brief	그래프가 비었는지 확인한다.
	*	@pre	그래프 초기화
	*	@post	none.
	*	@return	비었으면 true을 반환한다. 그렇지 않으면 false 반환
	*/
	bool IsEmpty(); 

	/**
	*	@brief	그래프가 꽉 찼는지 확인한다.
	*	@pre	그래프 초기화
	*	@post	none.
	*	@return	꽉 찼으면 true을 반환한다. 그렇지 않으면 false 반환
	*/
	bool IsFull(); 

	/**
	*	@brief	노드하나를 추가한다.
	*	@pre	그래프 초기화
	*	@post	노드하나 추가된다.
	*	@param	추가하고자 하는 T
	*	@return	추가되면 1을 반환한다. 그렇지 않으면 0 반환
	*/
	int AddVertex(T vertex); 

	/**
	*	@brief	가중치 하나를 추가한다.
	*	@pre	그래프 초기화
	*	@post	가중치 하나 추가된다.
	*	@param	출발노드, 도착노드, 가중치
	*	@return	추가되면 1을 반환한다. 그렇지 않으면 0 반환
	*/
	void AddEdge(T fromVertex, T toVertex, int weight);  

	/**
	*	@brief	출발노드에서 도착노드까지의 가중치를 반환하는 함수
	*	@pre	그래프 초기화
	*	@post	none.
	*	@param	출발노드, 도착노드
	*	@return	해당하는 배열의 가중치를 반환.
	*/
	int WeightIs(T fromVertex, T toVertex);  

	/**
	*	@brief	vertex 의 인접 vertex 를 queue 에 삽입
	*	@pre	그래프 초기화되어있고 연결된 노드가 있어야 한다.
	*	@post	큐에 해당 노드가 들어간다.
	*	@param	출발노드, 노드를 넣게될 큐
	*/
	void GetToVertices(T vertex, CircularQueueType<T>& adgVertices);  

	/**
	*	@brief	mark 정보를 해제 
	*	@pre	그래프 초기화
	*	@post	isMark배열이 모두 0으로 설정.
	*/
	void ClearMarks();

	/**
	*	@brief	vertex에 두번 조회되지 않게 설정을 해준다.
	*	@pre	그래프 초기화
	*	@post	isMark배열의 해당 위치에 1로 설정
	*	@param	해당 노드
	*/
	void MarkVertex(T vertex); 

	/**
	*	@brief	vertex가 이미 조회되었는지 확인해준다.
	*	@pre	그래프 초기화
	*	@post	isMark배열의 해당 위치에 1로 설정
	*	@param	해당 노드
	*/
	bool IsMarked(T vertex); 

	/**
	*	@brief	모든 vertex를 출력한다.
	*	@pre	그래프 초기화
	*	@post	none.
	*/
	void PrintVertices(); 

	/**
	*	@brief	모든 edge를 출력한다.
	*	@pre	그래프 초기화
	*	@post	none.
	*/
	void PrintEdges(); 
private:
	int numvertices; // 저장 노드 개수 
	int maxVertices; // 최대 저장 개수 
	T* vertices; // vertex 저장 공간을 가리키는 포인터 
	int** edges; // weighted edge 저장 공간을 가리키는 포인터 
	bool* marks; // mark 저장 공간을 가리키는 포인터
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

// graph 를 비움
template<typename T>
void Graph<T>::MakeEmpty()
{
	numvertices = 0;
}

// vertices 가 비어 있는지 확인 
template<typename T>
bool Graph<T>::IsEmpty()
{
	if (numvertices == 0)
		return true;
	else
		return false;
}

// vertices 가 가득 찼는지 확인 
template<typename T>
bool Graph<T>::IsFull()
{
	if (numvertices == maxVertices)
		return true;
	else
		return false;
}

// 새로운 vertex 를 추가 
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

// 두 vertex 를 연결하는 weighted edge 추가 
template<typename T>
void Graph<T>::AddEdge(T fromVertex, T toVertex, int weight)
{
	//M-ij에서 i가 from j가 to
	int fromIndex = IndexIs(vertices, fromVertex, numvertices);
	int toIndex = IndexIs(vertices, toVertex, numvertices);
	edges[fromIndex][toIndex] = weight;
	return;
}

// fromVertex 에서 toVertex 에 해당하는 edge weight 
template<typename T>
int Graph<T>::WeightIs(T fromVertex, T toVertex)
{
	int fromIndex = IndexIs(vertices, fromVertex, numvertices);
	int toIndex = IndexIs(vertices, toVertex, numvertices);
	return edges[fromIndex][toIndex];
}

// vertex 의 인접 vertex 를 queue 에 삽입
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

// mark 정보를 해제 
template<typename T>
void Graph<T>::ClearMarks()
{
	for (int i = 0; i < numvertices; i++)
	{
		marks[i] = false;
	}
	return;
}

// vertex 에 mark
template<typename T>
void Graph<T>::MarkVertex(T vertex)
{
	int index = IndexIs(vertices, vertex, numvertices);
	marks[index] = true;
	return;
}

// vertex 의 mark 여부 확인 
template<typename T>
 bool Graph<T>::IsMarked(T vertex)
{
	int index = IndexIs(vertices, vertex, numvertices);
	return marks[index];
}

 // 노드 출력 함수 
template<typename T>
void Graph<T>::PrintVertices()
{
	for (int i = 0; i < numvertices; i++)
	{
		cout << vertices[i] << " - ";
	}
	return;
}

// Weight 출력 함수
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


/////////////////////////////////전역함수////////////////////////////////////////


/**
*	@brief	Vertex의 index 리턴 함수
*	@pre	노드가 하나이상 있어야한다.
*	@post	none.
*	@param	노드배열, 찾고자 하는 노드, 전체 노드 개수.
*	@return	해당하는 노드의 인덱스 출력, 없으면 -1리턴
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
*	@brief	BFS경로 탐색함수
*	@pre	노드가 하나이상 있어야 하며 이어져 있어야 한다.
*	@post	경로를 출력한다.
*	@param	경로 검색할 그래프, 출발 노드, 도착 개수.
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
*	@brief	DFS경로 탐색함수
*	@pre	노드가 하나이상 있어야 하며 이어져 있어야 한다.
*	@post	경로를 출력한다.
*	@param	경로 검색할 그래프, 출발 노드, 도착 개수.
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