#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\User\Desktop\Політех\АТП\7 тема\7.3\7.3\7.3\7.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest73
{
	TEST_CLASS(UnitTest73)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int c;
			int colNumber = -1;
			int rowNumber = 0;
			int a[2][2] = { {2,1},{-1,2} };
			int* arr[2] = { a[0], a[1] };
			c = first((int**)arr, 2, 2);
			Assert::AreEqual(c, 2);
		}
	};
}
