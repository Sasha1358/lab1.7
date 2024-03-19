/// Payment.h
#pragma once

#include <string>
#include "Money.h"

class Payment {
private:
    std::string lastName;
    std::string firstName;
    std::string middleName;
    Money rate;
    int startYear;
    double bonusPercentage;
    double incomeTax;
    int workedDays;
    int workingDaysPerMonth;
    Money accruedAmount;
    Money withheldAmount;
    int yearsWorked;

public:
    Payment();

    void Init(const std::string& lastName, const std::string& firstName, const std::string& middleName,
        const Money& rate, int startYear, double bonusPercentage, double incomeTax,
        int workedDays, int workingDaysPerMonth);

    // Accessor methods
    std::string getLastName() const;
    void setLastName(const std::string& lastName);
    std::string getFirstName() const;
    void setFirstName(const std::string& firstName);
    std::string getMiddleName() const;
    void setMiddleName(const std::string& middleName);
    Money getRate() const;
    void setRate(const Money& rate);
    int getStartYear() const;
    void setStartYear(int startYear);
    double getBonusPercentage() const;
    void setBonusPercentage(double bonusPercentage);
    double getIncomeTax() const;
    void setIncomeTax(double incomeTax);
    int getWorkedDays() const;
    void setWorkedDays(int workedDays);
    int getWorkingDaysPerMonth() const;
    void setWorkingDaysPerMonth(int workingDaysPerMonth);
    Money getAccruedAmount() const;
    Money getWithheldAmount() const;
    int getYearsWorked() const;

    // Calculation methods
    void calculateAccruedAmount();
    void calculateWithheldAmount();
    void calculateNetAmount();
    void calculateYearsWorked();

    // Input and output methods
    void Read();
    void Display() const;
};
