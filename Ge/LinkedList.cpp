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

void IntDoubleLinkedList::Insert(int i)
{

}

void IntDoubleLinkedList::MarkCurrentDelete()
{
}

int IntDoubleLinkedList::Peek() const
{
	return 0;
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



