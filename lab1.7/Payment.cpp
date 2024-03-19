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
    time(&currentTime); // Отримуємо поточний час у секундах з початку епохи
    struct tm timeinfo;
    localtime_s(&timeinfo, &currentTime); // Конвертуємо поточний час у структуру tm

    int currentYearInt = timeinfo.tm_year + 1900; // Отримуємо поточний рік
    yearsWorked = currentYearInt - startYear;
}

void Payment::Read() {
    std::cout << "Введіть прізвище: ";
    std::cin >> lastName;
    std::cout << "Введіть ім'я: ";
    std::cin >> firstName;
    std::cout << "Введіть по батькові: ";
    std::cin >> middleName;
    std::cout << "Введіть ставку (гривня копійка): ";
    int hryvnia, kopiyka;
    std::cin >> hryvnia >> kopiyka;
    rate.Init(hryvnia, kopiyka);
    std::cout << "Введіть рік початку роботи: ";
    std::cin >> startYear;
    std::cout << "Введіть відсоток надбавки: ";
    std::cin >> bonusPercentage;
    std::cout << "Введіть податок на прибуток: ";
    std::cin >> incomeTax;
    std::cout << "Введіть кількість відпрацьованих днів: ";
    std::cin >> workedDays;
    std::cout << "Введіть кількість робочих днів у місяці: ";
    std::cin >> workingDaysPerMonth;
}

void Payment::Display() const {
    std::cout << "Прізвище: " << lastName << " " << firstName << " " << middleName << std::endl;
    std::cout << "Ставка: " << rate.toString() << std::endl;
    std::cout << "Рік початку роботи: " << startYear << std::endl;
    std::cout << "Відсоток надбавки: " << bonusPercentage << std::endl;
    std::cout << "Податок на прибуток: " << incomeTax << std::endl;
    std::cout << "Кількість відпрацьованих днів: " << workedDays << std::endl;
    std::cout << "Кількість робочих днів у місяці: " << workingDaysPerMonth << std::endl;
    std::cout << "Нарахована сума: " << accruedAmount.toString() << std::endl;
    std::cout << "Утримана сума: " << withheldAmount.toString() << std::endl;
    std::cout << "Стаж роботи: " << yearsWorked << " років" << std::endl;
}