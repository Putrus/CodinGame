#include "pch.h"
#include "CppUnitTest.h"

#include "../MadPodRacing/include/Vec2.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MathUtilitiesTest
{
	TEST_CLASS(Vec2test)
	{
	public:
		
		TEST_METHOD(AddTwoVectorsTest)
		{
			Vec2 v1(5, 3);
			Vec2 v2(3, 4);
			Vec2 result = v1 + v2;
			Assert::AreEqual(result.x, 8);
			Assert::AreEqual(result.y, 7);
		}

		TEST_METHOD(SubstractTwoVectorsTest)
		{
			Vec2 v1(5, 3);
			Vec2 v2(3, 4);
			Vec2 result = v1 - v2;
			Assert::AreEqual(result.x, 2);
			Assert::AreEqual(result.y, -1);
		}
	};
}
