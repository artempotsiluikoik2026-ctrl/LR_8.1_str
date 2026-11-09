#include "pch.h"
#include "CppUnitTest.h"
#include "../8.1 str/8.1 str.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test81str
{
	TEST_CLASS(test81str)
	{
	public:

		TEST_METHOD(TestExist_OGO)
		{
			Assert::IsTrue(Exist("xOGOy"));
		}

		TEST_METHOD(TestExist_AGA)
		{
			Assert::IsTrue(Exist("zAGAz"));
		}

		TEST_METHOD(TestExist_None)
		{
			Assert::IsFalse(Exist("OGAGO"));
		}

		TEST_METHOD(TestChange_One)
		{
			string s = "xOGOy";
			string result = Change(s);
			Assert::IsTrue(s == "x**y");
			Assert::IsTrue(result == "x**y");
		}

		TEST_METHOD(TestChange_Both)
		{
			string s = "AGAOGO";
			Change(s);
			Assert::IsTrue(s == "****");
		}

		TEST_METHOD(TestChange_NoTriple)
		{
			string s = "hello";
			Change(s);
			Assert::IsTrue(s == "hello");
		}
	};
}