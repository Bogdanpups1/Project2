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
	Element<T>* Head;
	Element<T>* Tail;
	int Count;

public:
	List();
	~List();
	void Add(T data);
	void Del();
	void DelAll();
	void Print();
	int GetCount();
	void AddByPos(T data, int posit);
	void DeleteByPos(int posit);
	int Search(T element);
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
template<class T>
void List<T>::AddByPos(T data, int posit)
{
	if (posit < 0 || posit > Count)
	{
		cout << "Nuh huh,incorrect position" << endl;
		return;
	}
	Element<T>* temp = new Element<T>;
	temp->data = data;

	if (posit == 0)
	{
		temp->Next = Head;
		Head = temp;
	}
	else if (posit == Count)
	{
		Tail->Next = temp;
		temp->Next = NULL;
		Tail = temp;
	}
	else
	{
		Element<T>* current = Head;
		for (int i = 0; i < posit - 1; i++)
		{
			current = current->Next;
		}
		temp->Next = current->Next;
		current->Next = temp;
	}
	Count++;
}
template<class T>
void List<T>::DeleteByPos(int posit)
{
	if (posit < 0 || posit > Count)
	{
		cout << "Nuh huh,incorrect position" << endl;
		return;
	}

	Element<T>* temp = NULL;

	if (posit == 0)
	{
		Del();
	}
	else
	{
		Element<T>* current = Head;
		for (int i = 0; i < posit - 1; i++)
		{
			current = current->Next;
		}
		temp = current->Next;
		current->Next = temp->Next;
	}
	delete temp;
	Count--;
}
template<class T>
int List<T>::Search(T element)
{
	Element<T>* current = Head;
	int posit = 0;
	while (current != NULL)
	{
		if (current->data == element)
		{
			return posit;
		}
		current = current->Next;
		posit++;
	}
	return -1;
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
	Count++;
}
template <class T>
void List<T>::Del()
{
	Element<T>* temp = Head;
	Head = Head->Next;
	delete temp;
	Count--;
}
template <class T>
void List<T>::DelAll()
{
	while (Head != 0)
		Del();
	Count--;
}
template <class T>
void List<T>::Print()
{
	Element<T>* temp = Head;
	while (temp != 0)
	{
		cout << temp->data << " ";
		temp = temp->Next;
	}
	cout << "\n\n";
}
template <class T>
ostream& operator<<(ostream& os, List<T>& obj)
{
	obj.Print();
	return os;
}

int main()
{
	srand(unsigned(time(0)));

	List<int> lst;

	for (int i = 0; i < 5; i++)
		lst.Add(rand() % 10);

	lst.Print();
	lst.Del();
	lst.Del();
	lst.Del();
	lst.Print();
	lst.AddByPos(15, 1);
	lst.Print();
	lst.AddByPos(67, 3);
	lst.Print();
	cout << lst.GetCount() << "\n" << endl;
	cout << lst.Search(52) << "\n" <<  endl;
	lst.DeleteByPos(1);
	lst.Print();
	lst.DeleteByPos(2);
	lst.Print();
	lst.AddByPos(1112, 1);
	lst.Print();
}
