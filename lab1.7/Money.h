/// Money.h
#pragma once
#include <iostream>

class Money {
private:
    long hryvnia;
    unsigned char kopiyka;

public:
    Money(long hryvnia = 0, unsigned char kopiyka = 0);

    // Accessor methods
    long getHryvnia() const;
    void setHryvnia(long hryvnia);
    unsigned char getKopiyka() const;
    void setKopiyka(unsigned char kopiyka);

    // Initialization method
    void Init(long hryvnia, unsigned char kopiyka);

    // Input and output methods
    void Read();
    void Display() const;

    // Conversion to string method
    std::string toString() const;

    // Operator overloading
    Money operator+(const Money& other) const;
    Money operator-(const Money& other) const;
    Money operator*(double multiplier) const;
    Money operator/(double divisor) const;
    bool operator==(const Money& other) const;
    bool operator!=(const Money& other) const;
    bool operator<(const Money& other) const;
    bool operator>(const Money& other) const;
};