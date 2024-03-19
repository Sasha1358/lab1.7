#include "pch.h"
#include "CppUnitTest.h"
#include "../lab1.7/Payment.h"
#include "../lab1.7/Payment.cpp"
#include "../lab1.7/Money.cpp"
#include "../lab1.7/Money.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest17
{
    TEST_CLASS(UnitTest17)
    {
    public:

        TEST_METHOD(TestInit)
        {
            // Arrange
            Payment payment;
            std::string lastName = "Doe";
            int startYear = 2020; // Наприклад, встановлюємо рік початку роботи

            // Act
            payment.Init(lastName, "John", "Smith", Money(100, 50), startYear, 5.0, 15.0, 20, 22);

            // Assert
            Assert::AreEqual(lastName, payment.getLastName());
            Assert::AreEqual(startYear, payment.getStartYear());
        }
    };
}
