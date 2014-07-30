#include "stdafx.h"
#include "LineOfElement.h"
#include "StackOfElement.h"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace	Microsoft::VisualStudio::TestTools::UnitTesting;

namespace TestSimpleDataStructures
{
	[TestClass]
	public ref class TestSimpleDataStructures
	{
	public: 
		[TestMethod]
		void EmptyLineTrue()
		{
			LineOfElement Line1;
			Assert::AreEqual (true, Line1.isEmpty());
		}

		[TestMethod]
		void EmptyLineFalse()
		{
			LineOfElement Line1;
			Line1.push (20);
			Assert::AreEqual (false, Line1.isEmpty());
		}

		[TestMethod]
		void EmptyStackTrue()
		{
			StackOfElement Stack1;
			Assert::AreEqual (true, Stack1.isEmpty());
		}

		[TestMethod]
		void EmptyStackFalse()
		{
			StackOfElement Stack1;
			Stack1.push (20);
			Assert::AreEqual (false, Stack1.isEmpty());
		}

		[TestMethod]
		void CleanLineWithOneElement()
		{
			LineOfElement Line1;
			Line1.push (20);
			Line1.clear();
			Assert::AreEqual (true, Line1.isEmpty());
		}

		[TestMethod]
		void CleanLineWithFewElements()
		{
			LineOfElement Line1;
			Line1.push (10);
			Line1.push (5);
			Line1.push (3);
			Line1.clear();
			Assert::AreEqual (true, Line1.isEmpty());
		}

		[TestMethod]
		void CleanStackWithOneElement()
		{
			StackOfElement Stack1;
			Stack1.push (20);
			Stack1.clear();
			Assert::AreEqual (true, Stack1.isEmpty());
		}

		[TestMethod]
		void CleanStackWithFewElements()
		{
			StackOfElement Stack1;
			Stack1.push (10);
			Stack1.push (5);
			Stack1.push (3);
			Stack1.clear();
			Assert::AreEqual (true, Stack1.isEmpty());
		}

		[TestMethod]
		void SizeOfEmptyLine()
		{
			LineOfElement Line1;
			Assert::AreEqual (0, Line1.size());
		}

		[TestMethod]
		void SizeLineWithFewElements()
		{
			LineOfElement Line1;
			Line1.push (2);
			Line1.push (10);
			Line1.push (1);
			Line1.push (120);
			Assert::AreEqual (4, Line1.size());
		}

		[TestMethod]
		void SizeOfEmptyStack()
		{
			StackOfElement Stack1;
			Assert::AreEqual (0, Stack1.size());
		}

		[TestMethod]
		void SizeOfStackWithFewElements()
		{
			StackOfElement Stack1;
			Stack1.push (20);
			Stack1.push (2);
			Stack1.push (0);
			Assert::AreEqual (3, Stack1.size());
		}

		[TestMethod]
		void ValueOfFirstElementInLineWithOneElement()
		{
			LineOfElement Line1;
			Line1.push (2);
			Assert::AreEqual (2, Line1.top());
		}

		[TestMethod]
		void ValueOfFirstElementInLineWithFewElements()
		{
			LineOfElement Line1;
			Line1.push (2);
			Line1.push (10);
			Line1.push (1);
			Line1.push (120);
			Assert::AreEqual (2, Line1.top());
		}

		[TestMethod]
		void ValueOfFirstElementInStackWithOneElement()
		{
			StackOfElement Stack1;
			Stack1.push (20);
			Assert::AreEqual (20, Stack1.top());
		}

		[TestMethod]
		void ValueOfFirstElementInStackWithFewElement()
		{
			StackOfElement Stack1;
			Stack1.push (20);
			Stack1.push (2);
			Stack1.push (0);
			Assert::AreEqual (0, Stack1.top());
		}

		[TestMethod]
		void DeleteFirstElementInLineWithOneElement()
		{
			LineOfElement Line1;
			Line1.push (2);
			Line1.pop();
			Assert::AreEqual (true, Line1.isEmpty());
		}

		[TestMethod]
		void DeleteFirstElementInLineWithFewElements()
		{
			LineOfElement Line1;
			Line1.push (2);
			Line1.push (10);
			Line1.push (1);
			Line1.push (120);
			Line1.pop();
			Assert::AreEqual (10, Line1.top());
		}

		[TestMethod]
		void DeleteFirstElementInStackWithOneElement()
		{
			StackOfElement Stack1;
			Stack1.push (20);
			Stack1.pop();
			Assert::AreEqual (true, Stack1.isEmpty());
		}

		[TestMethod]
		void DeleteFirstElementInStackWithFewElements()
		{
			StackOfElement Stack1;
			Stack1.push (20);
			Stack1.push (2);
			Stack1.push (0);
			Stack1.pop();
			Assert::AreEqual (2, Stack1.top());
		}

		[TestMethod]
		void AddManyElementsInLine()
		{
			LineOfElement Line1;
			Line1.push (12);
			Line1.push (140);
			Line1.push (13);
			Line1.push (120);
			Line1.push (29);
			Line1.push (27);
			Line1.push (106);
			Line1.push (3);
			Line1.push (10);
			Line1.push (23);
			Line1.push (4);
			Line1.push (0);
			Line1.push (11);
			Line1.push (1);
			Line1.push (2);
			Assert::AreEqual (15, Line1.size());
		}

		[TestMethod]
		void AddManyElementsInStack()
		{
			StackOfElement Stack1;
			Stack1.push (20);
			Stack1.push (2);
			Stack1.push (3);
			Stack1.push (25);
			Stack1.push (5);
			Stack1.push (0);
			Stack1.push (270);
			Stack1.push (26);
			Stack1.push (30);
			Stack1.push (202);
			Stack1.push (42);
			Stack1.push (90);
			Stack1.push (20);
			Stack1.push (27);
			Stack1.push (500);			
			Assert::AreEqual (15, Stack1.size());
		}

		[TestMethod]
		void CopyLineInNewLine()
		{
			LineOfElement Line1;
			Line1.push (12);
			Line1.push (140);
			Line1.push (13);
			LineOfElement Line2 (Line1);
			Assert::AreEqual (3, Line2.size());
			Assert::AreEqual (12, Line2.top());
			Line2.pop();
			Assert::AreEqual (140, Line2.top());
			Line2.pop();
			Assert::AreEqual (13, Line2.top());
		}

		[TestMethod]
		void AssignLineToEmptyLine()
		{
			LineOfElement Line1;
			Line1.push (12);
			Line1.push (140);
			Line1.push (13);
			LineOfElement Line2 = Line1;
			Assert::AreEqual (3, Line2.size());
			Assert::AreEqual (12, Line2.top());
			Line2.pop();
			Assert::AreEqual (140, Line2.top());
			Line2.pop();
			Assert::AreEqual (13, Line2.top());
		}

		[TestMethod]
		void AssignLineToNotEmptyLine()
		{
			LineOfElement Line1;
			Line1.push (12);
			Line1.push (140);
			Line1.push (13);
			LineOfElement Line2;
			Line2.push (14);
			Line2.push (1);
			Line2 = Line1;
			Assert::AreEqual (3, Line2.size());
			Assert::AreEqual (12, Line2.top());
			Line2.pop();
			Assert::AreEqual (140, Line2.top());
			Line2.pop();
			Assert::AreEqual (13, Line2.top());
		}

		[TestMethod]
		void AssignStackToEmptyStack()
		{
			StackOfElement Stack1;
			Stack1.push (20);
			Stack1.push (2);
			Stack1.push (3);
			StackOfElement Stack2 = Stack1;			
			Assert::AreEqual (3, Stack2.size());
			Assert::AreEqual (3, Stack2.top());
			Stack2.pop();
			Assert::AreEqual (2, Stack2.top());
			Stack2.pop();
			Assert::AreEqual (20, Stack2.top());
		}

		[TestMethod]
		void AssignStackToNotEmptyStack()
		{
			StackOfElement Stack1;
			Stack1.push (20);
			Stack1.push (2);
			Stack1.push (3);
			StackOfElement Stack2;
			Stack2.push (6);
			Stack2.push (10);
			Stack2 = Stack1;
			Assert::AreEqual (3, Stack2.size());
			Assert::AreEqual (3, Stack2.top());
			Stack2.pop();
			Assert::AreEqual (2, Stack2.top());
			Stack2.pop();
			Assert::AreEqual (20, Stack2.top());
		}

		[TestMethod]
		void CopyStackInNewStack()
		{
			StackOfElement Stack1;
			Stack1.push (20);
			Stack1.push (2);
			Stack1.push (3);
			StackOfElement Stack2 (Stack1);
			Assert::AreEqual (3, Stack2.size());
			Assert::AreEqual (3, Stack2.top());
			Stack2.pop();
			Assert::AreEqual (2, Stack2.top());
			Stack2.pop();
			Assert::AreEqual (20, Stack2.top());
		}
	};
}
