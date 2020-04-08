#include "pch.h"
#include "CppUnitTest.h"
#include "../Ge/LinkedList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


// Learn more here: 
// https://docs.microsoft.com/en-us/visualstudio/test/microsoft-visualstudio-testtools-cppunittestframework-api-reference?view=vs-2019

namespace Tests
{
	TEST_CLASS(Tests)
	{
	public:
		
		

		TEST_METHOD(TestMethod1)
		{
			Logger::WriteMessage("Testing Append()");
			ArcaneScience::IntDoubleLinkedList arr = *(new ArcaneScience::IntDoubleLinkedList());
			
			/*for (int i = 0; i < 1000; i++)
			{
				arr.Append(i);
			}

			Logger::WriteMessage("1000 elements are logged into the linked list");*/
			
			

		}

		TEST_METHOD(TestMethod2)
		{
		
		}
	};
}
