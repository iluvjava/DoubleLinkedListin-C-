#pragma once
#include <string>

namespace ArcaneScience // gonna learn how to use namespaces.
{
	class Node
	{
	private:
		Node* pre;
		Node* next;
		int data;
	public:
		Node(Node* pre, int data, Node* next);

		friend class IntDoubleLinkedList;
	};

	class IntDoubleLinkedList
	{
	protected:
		Node* dummy_head = nullptr;
		Node* dummy_tail = nullptr;
		Node* stray_pointer = nullptr;
		int stray_index = 0;
		unsigned int len = 0;

	public:
		IntDoubleLinkedList();
		virtual ~IntDoubleLinkedList();
		void Append(int n);
		void Push(int n);
		int PopFirst(); // reset stray pointer.
		int PopLast();
		int PeekFirst() const;
		std::string ToString() const;
		int size() const;
		int& operator[](int i); // return by reference is important, stray index will be updated.
		IntDoubleLinkedList& operator++(); // Pre-fix increment, moving up the stray pointer.
		IntDoubleLinkedList& operator--(); // pre-fix increment, moving down the stray pointer.
		void DeletNext(); // remove next node comes after the stray pointer. 
		int* PeekCurrent() const; // peek current element; null return if uninitialized or empty.
		int* PeekNext() const; // Peek next element, nullptr if there isn't any.
		bool HasNext() const;
		bool HasPre() const;
		void ResetToHead(); // rest stray pointer to dummy head.
		void RestToTail(); // Rest stray pointer to dummy tail.

	protected:
		Node* GetNodeAtIndex(int i); // straying index and pointer will change.
	};
}