// Ge.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "LinkedList.h"
using namespace std;
using namespace ArcaneScience;

int const TEST_ERROR = 300; 

void Test1() // Append, Popfirst, Pop last. 
{
    // Append, Pop last 
    {
        IntDoubleLinkedList arr = IntDoubleLinkedList();
        // this is static, no delete?! Destructor automatically evoked. 
        for (int I = 0; I < 10; I++, arr.Append(I));
        cout << arr.ToString() << endl;
        while (arr.size() != 0)
        {
            arr.PopFirst();
            cout << arr.ToString() << endl;
        }
    }

    // Append, Pop first. 
    {
        IntDoubleLinkedList arr = IntDoubleLinkedList();

        for (int I = 0; I < 10; I++, arr.Append(I));
        cout << arr.ToString() << endl;
        while (arr.size() != 0)
        {
            arr.PopLast();
            cout << arr.ToString() << endl;
        }
    }
}

// Testing Indexer
void Test2()
{

    cout << "Testing Indexer: " << endl; 

    IntDoubleLinkedList arr = IntDoubleLinkedList();
    for (int I = 0; I < 10; I++, arr.Append(I));
    
    for (int I = 0; I < arr.size(); I++)
    {
        arr[I] = -1;
    }
    cout << arr.ToString() << endl;

    for (int I = 0; I < arr.size(); I+=2)
    {
        arr[I] = 1;
    }
    cout << arr.ToString() << endl;
}

// Testing Append and push 
void Test3()
{
    IntDoubleLinkedList arr = IntDoubleLinkedList();

    for (int I = 0; I < 10; I++)
    {
        arr.Append(I);
        arr.Push(I); 
    }
    cout << arr.ToString() << endl;
}

// Test the Iterator. 
void Test4()
{
    IntDoubleLinkedList arr = IntDoubleLinkedList();
    for (int I = 0; I < 10; I++)arr.Append(I);

    arr.ResetToHead();
    {
        int I = 0; 
        while (arr.HasNext())
        {
            if (I != *arr.PeekNext())
            {
                cout << "Expect: " << I << " But: " << *arr.PeekNext() << endl;
                throw TEST_ERROR; 
            }
            I++;
            ++arr;
        }
    }
    arr.RestToTail(); 
    {
        int I = arr.size() - 1;
        while (arr.HasPre())
        {
            --arr;
            if (I != *arr.PeekCurrent())
            {
                cout << "Expect: " << I << " But: " << *arr.PeekCurrent() << endl;
                throw TEST_ERROR;
            }
            --I;
        }
    }
}

// Test Delete with iterator. 
void Test5()
{

}

void MemoryLeakTest()
{

}

int main()
{
    cout << "Executing..." << endl;
    cout << "Creates and delete the object." << endl; 
    
    {
        IntDoubleLinkedList* arr = new IntDoubleLinkedList();
        delete arr;
    }

    cout << "Ok, now we run the tests" << endl; 

    try {

        Test1();
        Test2();
        Test3();
        Test4();
    }
    catch (int TEST_ERROR)
    {
        cout << "Test Failed" << endl; 
        exit(-1);
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file