#include <iostream>
using namespace std;

template <class T>

struct Element
{
	T data;
	Element* Next;
};

template <class T>
class List
{
	T* Head;
	T* Tail;
	int Count;

public:
	List();
	~List();
	void Add(T data);
	void Del();
	void DelAll();
	void Print();
	int GetCount();
};
template <class T>
List<T>::List()
{
	Head = Tail = NULL;
	Count = 0;
}
template <class T>
List<T>::~List()
{
	DelAll();
}

template <class T>
int List<T>::GetCount()
{
	return Count;
}

template <class T>
void List<T>::Add(T data)
{
	Element<T>* temp = new Element<T>;

	temp->data = data;
	temp->Next = NULL;
	if (Head != NULL) {
		Tail->Next = temp;
		Tail = temp;
	}
	else {
		Head = Tail = temp;
	}
}

template <class T>
void List<T>::Del()
{
	Element* temp = Head;
	Head = Head->Next;
	delete temp;
}

template <class T>
void List<T>::DelAll()
{
	while (Head != 0)
		Del();
}

template <class T>
void List<T>::Print()
{
	Element* temp = Head;
	while (temp != 0)
	{
		cout << temp->data << " ";
		temp = temp->Next;
	}
	cout << "\n\n";
}
template <class T>
void main()
{

	List<T> lst;

	char s[] = "Hello, World !!!\n";
	cout << s << "\n\n";
	int len = strlen(s);
	for (int i = 0; i < len; i++)
		lst.Add(s[i]);
	lst.Print();
	lst.Del();
	lst.Del();
	lst.Del();
	lst.Print();
}

