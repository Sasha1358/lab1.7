// Payment.cpp
#include "Payment.h"
#include <ctime>

Payment::Payment() {
    // Initialize member variables with default values
    lastName = "";
    firstName = "";
    middleName = "";
    rate = Money();
    startYear = 0;
    bonusPercentage = 0.0;
    incomeTax = 0.0;
    workedDays = 0;
    workingDaysPerMonth = 0;
    accruedAmount = Money();
    withheldAmount = Money();
    yearsWorked = 0;
}

void Payment::Init(const std::string& lastName, const std::string& firstName, const std::string& middleName,
    const Money& rate, int startYear, double bonusPercentage, double incomeTax,
    int workedDays, int workingDaysPerMonth) {
    // Initialize member variables with provided values
    this->lastName = lastName;
    this->firstName = firstName;
    this->middleName = middleName;
    this->rate = rate;
    this->startYear = startYear;
    this->bonusPercentage = bonusPercentage;
    this->incomeTax = incomeTax;
    this->workedDays = workedDays;
    this->workingDaysPerMonth = workingDaysPerMonth;
}

std::string Payment::getLastName() const {
    return lastName;
}

void Payment::setLastName(const std::string& lastName) {
    this->lastName = lastName;
}

std::string Payment::getFirstName() const {
    return firstName;
}

void Payment::setFirstName(const std::string& firstName) {
    this->firstName = firstName;
}

std::string Payment::getMiddleName() const {
    return middleName;
}

void Payment::setMiddleName(const std::string& middleName) {
    this->middleName = middleName;
}

Money Payment::getRate() const {
    return rate;
}

void Payment::setRate(const Money& rate) {
    this->rate = rate;
}

int Payment::getStartYear() const {
    return startYear;
}

void Payment::setStartYear(int startYear) {
    this->startYear = startYear;
}

double Payment::getBonusPercentage() const {
    return bonusPercentage;
}

void Payment::setBonusPercentage(double bonusPercentage) {
    this->bonusPercentage = bonusPercentage;
}

double Payment::getIncomeTax() const {
    return incomeTax;
}

void Payment::setIncomeTax(double incomeTax) {
    this->incomeTax = incomeTax;
}

int Payment::getWorkedDays() const {
    return workedDays;
}

void Payment::setWorkedDays(int workedDays) {
    this->workedDays = workedDays;
}

int Payment::getWorkingDaysPerMonth() const {
    return workingDaysPerMonth;
}

void Payment::setWorkingDaysPerMonth(int workingDaysPerMonth) {
    this->workingDaysPerMonth = workingDaysPerMonth;
}

Money Payment::getAccruedAmount() const {
    return accruedAmount;
}

Money Payment::getWithheldAmount() const {
    return withheldAmount;
}

int Payment::getYearsWorked() const {
    return yearsWorked;
}

void Payment::calculateAccruedAmount() {
    Money baseAmount = (rate / workingDaysPerMonth) * workedDays;
    Money bonus = baseAmount * (bonusPercentage / 100.0);
    accruedAmount = baseAmount + bonus;
}

void Payment::calculateWithheldAmount() {
    Money pensionFund = accruedAmount * 0.01;
    Money incomeTaxAmount = (accruedAmount - pensionFund) * (incomeTax / 100.0);
    withheldAmount = pensionFund + incomeTaxAmount;
}

void Payment::calculateNetAmount() {
    Money netAmount = accruedAmount - withheldAmount;
}

void Payment::calculateYearsWorked() {
    time_t currentTime;
    time(&currentTime); // �������� �������� ��� � �������� � ������� �����
    struct tm timeinfo;
    localtime_s(&timeinfo, &currentTime); // ���������� �������� ��� � ��������� tm

    int currentYearInt = timeinfo.tm_year + 1900; // �������� �������� ��
    yearsWorked = currentYearInt - startYear;
}

void Payment::Read() {
    std::cout << "������ �������: ";
    std::cin >> lastName;
    std::cout << "������ ��'�: ";
    std::cin >> firstName;
    std::cout << "������ �� �������: ";
    std::cin >> middleName;
    std::cout << "������ ������ (������ ������): ";
    int hryvnia, kopiyka;
    std::cin >> hryvnia >> kopiyka;
    rate.Init(hryvnia, kopiyka);
    std::cout << "������ �� ������� ������: ";
    std::cin >> startYear;
    std::cout << "������ ������� ��������: ";
    std::cin >> bonusPercentage;
    std::cout << "������ ������� �� ��������: ";
    std::cin >> incomeTax;
    std::cout << "������ ������� ������������� ���: ";
    std::cin >> workedDays;
    std::cout << "������ ������� ������� ��� � �����: ";
    std::cin >> workingDaysPerMonth;
}

void Payment::Display() const {
    std::cout << "�������: " << lastName << " " << firstName << " " << middleName << std::endl;
    std::cout << "������: " << rate.toString() << std::endl;
    std::cout << "г� ������� ������: " << startYear << std::endl;
    std::cout << "³������ ��������: " << bonusPercentage << std::endl;
    std::cout << "������� �� ��������: " << incomeTax << std::endl;
    std::cout << "ʳ������ ������������� ���: " << workedDays << std::endl;
    std::cout << "ʳ������ ������� ��� � �����: " << workingDaysPerMonth << std::endl;
    std::cout << "���������� ����: " << accruedAmount.toString() << std::endl;
    std::cout << "�������� ����: " << withheldAmount.toString() << std::endl;
    std::cout << "���� ������: " << yearsWorked << " ����" << std::endl;
}