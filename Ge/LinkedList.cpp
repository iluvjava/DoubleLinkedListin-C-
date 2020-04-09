#include "LinkedList.h"


using namespace std;
using namespace ArcaneScience;

#pragma region Node
Node::Node(Node* p, int d, Node* n)
{
	next = n;
	pre = p;
	data = d;
}
#pragma endregion

#pragma region IntDoubleLinkedlist 


IntDoubleLinkedList::IntDoubleLinkedList()
{
	Node* n1 = new Node(nullptr, 0, nullptr);
	Node* n2 = new Node(nullptr, 0, nullptr);
	n1->next = n2; 
	n2->pre = n1;
	stray_index = 0;
	stray_pointer = dummy_head;
	dummy_head = n1;
	dummy_tail = n2;
}

void IntDoubleLinkedList::Append(int n)
{
	Node* beforeTail = dummy_tail->pre;
	Node* newNode = new Node(beforeTail, n, dummy_tail);
	beforeTail->next = newNode;
	dummy_tail->pre = newNode;
	len++;
}

void ArcaneScience::IntDoubleLinkedList::Push(int n)
{
	// TODO: IMPLEMENT THIS 
}

int IntDoubleLinkedList::PopFirst()
{
	if (len == 0)throw 333; 
	Node* toReturn = dummy_head->next;
	Node* nextToThat = toReturn->next;
	int res = toReturn->data;
	dummy_head->next = toReturn->next;
	nextToThat->pre = toReturn->pre;
	delete toReturn;
	len--;
	stray_pointer = dummy_head->next;
	stray_index = 0; 
	return res;
}

// TODO: Test it. 
int IntDoubleLinkedList::PopLast()
{
	if (len == 0) throw 333; 
	Node* toReturn = dummy_tail->pre;
	Node* toReturnPre = toReturn->pre;
	dummy_tail->pre = toReturnPre;
	toReturnPre->next = dummy_tail;
	int res = toReturn->data;
	len--;
	delete toReturn;
	return res;
}

int IntDoubleLinkedList::PeekFirst() const
{
	return dummy_head->next->data;
}

string IntDoubleLinkedList::ToString() const
{
	if (len == 0)return "[]";
	string s = string("[");
	Node* p = dummy_head->next;
	while (p->next != dummy_tail)
	{
		s += to_string(p->data) + ", ";
		p = p->next;
	}
	s += to_string(p->data) + "]";
	return s;
}

int IntDoubleLinkedList::size() const
{
	return len;
}

int& IntDoubleLinkedList::operator[](int i)
{
	Node* n = GetNodeAtIndex(i);
	if (n == nullptr)throw 334;
	return n->data;
}

IntDoubleLinkedList& IntDoubleLinkedList::operator++()
{

	// TODO: Test this method. 
	if (!HasNext()) throw 222;
	stray_index++;
	stray_pointer = stray_pointer->next;
	return *this;
}

IntDoubleLinkedList& IntDoubleLinkedList::operator--()
{
	// TODO: test
	if (!HasPre()) throw 222;
	stray_index--;
	stray_pointer = stray_pointer->pre;
	return *this;
}

void IntDoubleLinkedList::DeletNext()
{	// TODO: Test it. 
	if (!HasNext()) throw 222; 
	Node* toDel = stray_pointer->next;
	stray_pointer = toDel->next;
	delete toDel;
	len--;
}

//TODO: Test
int* IntDoubleLinkedList::PeekCurrent() const
{
	if ( stray_pointer == dummy_head || stray_pointer == dummy_tail)
		return nullptr;

	return &(stray_pointer->data);
}

int* ArcaneScience::IntDoubleLinkedList::PeekNext() const
{
	// TODO: test this 
	if (!HasNext()) return nullptr;

	return &(stray_pointer->next->data);
}

bool IntDoubleLinkedList::HasNext() const
{

	// TODO: Test this
	return stray_pointer != dummy_tail;
}

bool IntDoubleLinkedList::HasPre() const
{
	//TODO: Test this 
	return stray_pointer != dummy_head;
}

void IntDoubleLinkedList::ResetToHead()
{
	// TODO: test this
	stray_pointer = dummy_head;
	stray_index = 0;
}

void ArcaneScience::IntDoubleLinkedList::RestToTail()
{
	// TODO: Test this. 
	stray_pointer = dummy_tail;
	stray_index = len - 1;
}


// nullptr return if there input invalid. 
Node* IntDoubleLinkedList::GetNodeAtIndex(int i)
{
	if (i < 0 || i >= len)return nullptr;
	//head and tail. 
	
	if (i == 0)return dummy_head->next;
	if (i == len - 1)return dummy_tail->pre;
	if (i == stray_index) return stray_pointer;

	int start = 0; 
	Node* closestPointer = dummy_head->next;
	if (i > abs(stray_index - i))
	{
		start = stray_index;
		closestPointer = stray_pointer;
	}
	if (abs(i - stray_index) > len - 1 - i)
	{
		start = len - 1;
		closestPointer = dummy_tail->pre;
	}
	int delta = i - start > 0 ? +1 : -1;
	while (start != i)
	{
		if (delta == 1)closestPointer = closestPointer->next;
		else closestPointer = closestPointer->pre;
		start += delta;
	}
	stray_index = start;
	this->stray_pointer = closestPointer;

	return closestPointer;
}

#pragma endregion



