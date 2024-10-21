#include "pch.h"
#include "CppUnitTest.h"
#include "../PR7.1(REC).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestCalc)
        {
            const int rowCount = 3;
            const int colCount = 3;
            int** z = new int* [rowCount];
            for (int i = 0; i < rowCount; i++)
                z[i] = new int[colCount];

            // Тестові дані
            z[0] = new int[3] { 26, 14, 15 };
            z[1] = new int[3] { 30, 39, 12 };
            z[2] = new int[3] { 10, 6, 13 };

            int S = 0;
            int k = 0;
            Calc(z, rowCount, colCount, S, k);

            // Перевірки
            Assert::AreEqual(S, 139); // 15 + 39 + 10 + 6 + 13 = 83
            Assert::AreEqual(k, 8);  // Кількість значень, які враховані

            for (int i = 0; i < rowCount; i++)
                delete[] z[i];
            delete[] z;
        }
    };
}
