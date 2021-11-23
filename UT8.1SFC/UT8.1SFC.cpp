#pragma warning(disable : 4996)
#include "pch.h"
#include "CppUnitTest.h"
#include "../PR8.1SFC/Lab_08_1_SFC.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UT81SFC
{
	TEST_CLASS(UT81SFC)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int t;

			t = Count("FFFFF");

			Assert::AreEqual(t, 0);
		}
	};
}