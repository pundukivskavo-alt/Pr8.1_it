// Unit-тест до Завдання № 8.1, варіант 20 (ітераційний спосіб)
// Тип проєкту: Native Unit Test Project (Microsoft Visual Studio)
// Проєкт з програмою (Lab_8_1) має бути у тому ж рішенні (solution).


#include "pch.h"
#include "CppUnitTest.h"
#include "../Pr8.1_it/Pr8.1_it.cpp"   // шлях до файлу з Count() і Change()

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest81
{
    TEST_CLASS(UnitTest81)
    {
    public:

        // ---------- Count ----------

        TEST_METHOD(Count_TwoGroups)
        {
            char s[] = "a,b-c,d-e";
            Assert::AreEqual(2, Count(s));
        }

        TEST_METHOD(Count_NoGroups)
        {
            char s[] = "abc,-d";           // кома і тире сусідні, групи ",?-" немає
            Assert::AreEqual(0, Count(s));
        }

        TEST_METHOD(Count_ShortString)
        {
            char s[] = ",-";
            Assert::AreEqual(0, Count(s));
        }

        TEST_METHOD(Count_OverlappingGroups)
        {
            char s[] = ",,--,-";           // ",,-", ",--", ",-" – перекриваються
            Assert::AreEqual(2, Count(s));
        }

        TEST_METHOD(Count_GroupAtEnd)
        {
            char s[] = "x,y-";
            Assert::AreEqual(1, Count(s));
        }

        // ---------- Change ----------

        TEST_METHOD(Change_TwoGroups)
        {
            char s[] = "a,b-c,d-e";
            char* res = Change(s);
            Assert::AreEqual("a**c**e", res);
            Assert::AreEqual("a**c**e", s);   // параметр теж змінено
        }

        TEST_METHOD(Change_WholeStringIsGroup)
        {
            char s[] = ",x-";
            Assert::AreEqual("**", Change(s));
        }

        TEST_METHOD(Change_NoGroups)
        {
            char s[] = "hello, world";
            Assert::AreEqual("hello, world", Change(s));
        }

        TEST_METHOD(Change_ShortString)
        {
            char s[] = "ab";
            Assert::AreEqual("ab", Change(s));
        }

        TEST_METHOD(Change_GroupAtEnd)
        {
            char s[] = "x,y-";
            Assert::AreEqual("x**", Change(s));
        }

        TEST_METHOD(Change_AdjacentGroups)
        {
            char s[] = "a,b-,c-d";
            Assert::AreEqual("a****d", Change(s));
        }
    };
}