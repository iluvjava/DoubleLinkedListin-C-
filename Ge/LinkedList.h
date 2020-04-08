#pragma once
#include <string>

namespace ArcaneScience // gonna learn how to use namespaces. 
{
	class Node
	{
	private:
		Node* pre;
		Node* next;
		bool to_remove;
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
		int len = 0;

	public:
		
		IntDoubleLinkedList();
		void Append(int n);
		int PopFirst();
		int PeekFirst() const;
		std::string ToString() const;
		int size() const;
		int& operator[](int i); // return by reference is important, stray index will be updated. 
		void Insert(int i); // stray index will be updated. 
		void MarkCurrentDelete();
		int Peek() const; // peek current element. 

	protected:
		Node* GetNodeAtIndex(int i); // straying index and pointer will change. 

	};

}