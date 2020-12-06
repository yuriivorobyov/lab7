#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\User\Desktop\Політех\АТП\7 тема\7.2\7.2\7.2\7.2.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest72
{
	TEST_CLASS(UnitTest72)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			int** a = new int* [8, 8, 2, 23, 3];
			int c;
			int low = 0;
			int i = 0;
			c = findMax(a, 0, i, low);
			Assert::AreEqual(c, 0);
		}
	};
}