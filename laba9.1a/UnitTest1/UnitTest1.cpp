#include "pch.h"
#include "CppUnitTest.h"
#include "../laba9.1a/laba9.1a.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
    TEST_CLASS(UnitTest2)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            int N = 1;
            Student* students = new Student[N];
            students->prizv = "Sofia";
            students->specialty = КН;
            students->physics = 3;
            students->math = 4;
            students->programming = 5;
            students->kurs = 2;
            double five_four = physics_five_four(students, N);
            Assert::AreEqual(0.0, five_four);
        }
    };
}