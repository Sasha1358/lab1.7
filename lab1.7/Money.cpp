// Money.cpp
#include "Money.h"
#include <string>

Money::Money(long hryvnia, unsigned char kopiyka) : hryvnia(hryvnia), kopiyka(kopiyka) {}

long Money::getHryvnia() const {
    return hryvnia;
}

void Money::setHryvnia(long hryvnia) {
    this->hryvnia = hryvnia;
}

unsigned char Money::getKopiyka() const {
    return kopiyka;
}

void Money::setKopiyka(unsigned char kopiyka) {
    this->kopiyka = kopiyka;
}

void Money::Init(long hryvnia, unsigned char kopiyka) {
    this->hryvnia = hryvnia;
    this->kopiyka = kopiyka;
}

void Money::Read() {
    std::cout << "Enter Hryvnia: ";
    std::cin >> hryvnia;
    std::cout << "Enter Kopiyka: ";
    std::cin >> kopiyka;
}

void Money::Display() const {
    std::cout << hryvnia << "," << (int)kopiyka;
}

std::string Money::toString() const {
    return std::to_string(hryvnia) + "," + std::to_string(kopiyka);
}

Money Money::operator+(const Money& other) const {
    long sumHryvnia = hryvnia + other.hryvnia;
    int sumKopiyka = kopiyka + other.kopiyka;
    sumHryvnia += sumKopiyka / 100;
    sumKopiyka %= 100;
    return Money(sumHryvnia, sumKopiyka);
}

Money Money::operator-(const Money& other) const {
    long differenceHryvnia = hryvnia - other.hryvnia;
    int differenceKopiyka = kopiyka - other.kopiyka;
    if (differenceKopiyka < 0) {
        differenceHryvnia -= 1;
        differenceKopiyka += 100;
    }
    return Money(differenceHryvnia, differenceKopiyka);
}

Money Money::operator*(double multiplier) const {
    long totalKopiyka = hryvnia * 100 + kopiyka;
    totalKopiyka *= multiplier;
    long newHryvnia = totalKopiyka / 100;
    unsigned char newKopiyka = totalKopiyka % 100;
    return Money(newHryvnia, newKopiyka);
}

Money Money::operator/(double divisor) const {
    long totalKopiyka = hryvnia * 100 + kopiyka;
    totalKopiyka /= divisor;
    long newHryvnia = totalKopiyka / 100;
    unsigned char newKopiyka = totalKopiyka % 100;
    return Money(newHryvnia, newKopiyka);
}

bool Money::operator==(const Money& other) const {
    return hryvnia == other.hryvnia && kopiyka == other.kopiyka;
}

bool Money::operator!=(const Money& other) const {
    return !(*this == other);
}

bool Money::operator<(const Money& other) const {
    if (hryvnia != other.hryvnia)
        return hryvnia < other.hryvnia;
    return kopiyka < other.kopiyka;
}

bool Money::operator>(const Money& other) const {
    return !(*this < other || *this == other);
}
