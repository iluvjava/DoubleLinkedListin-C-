#include "pch.h"
#include "CppUnitTest.h"

#include "../Ge/LinkedList.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace ArcaneScience;

void print(string& s)
{
	Logger::WriteMessage(&s[0]);
}

namespace Uranus
{
	TEST_CLASS(Uranus)
	{
	public:
		
		TEST_METHOD(Part1)
		{
			Logger::WriteMessage("Testing Append() and PopFirst() in Ge:LinkeList.cpp");
			IntDoubleLinkedList arr = *(new IntDoubleLinkedList());
			
			for (int I = 0; I < 1000; I++, arr.Append(I));
			
			Assert::IsTrue(arr.size() == 1000);
			print(arr.ToString());

			for (int I = 0; I < 1000; I++)
			{
				Assert::IsTrue(arr.PopFirst() == I + 1);
			}

			print(arr.ToString());
		}


		TEST_METHOD(Part2)
		{
			
		}


	};
}
