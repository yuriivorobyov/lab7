#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\User\Desktop\Політех\АТП\7 тема\7.2R\7.2R\7.2R\7.2R.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest72R
{
	TEST_CLASS(UnitTest72R)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			int** a = new int* [0];
			int c;
			int i = 2;
			c = findIndex(a, i, 0, 0, 1, 0);
			Assert::AreEqual(c, 0);
		}
	};
}