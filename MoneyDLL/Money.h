#pragma once
#include <string>

#ifdef MONEYDLL_EXPORTS
#define MONEYDLL_API __declspec(dllexport)
#else
#define MONEYDLL_API __declspec(dllimport)
#endif

namespace MoneySpace
{
    class MONEYDLL_API Money
    {
    private:
        long long coin10;
        long long coin50;
        long long grn1;
        long long grn2;
        long long grn5;
        long long grn10;
        long long grn50;
        long long grn100;
        long long grn200;
        long long grn500;

        long long Totalcoins() const;
        void setFromTotalCoins(long long coins);

    public:
        Money();
        Money(long long coin10, long long coin50, long long grn1, long long grn2, long long grn5,
            long long grn10, long long grn50, long long grn100, long long grn200, long long grn500);
        Money(const Money& other);
        ~Money();

        bool Init(long long coin10, long long coin50, long long grn1, long long grn2, long long grn5,
            long long grn10, long long grn50, long long grn100, long long grn200, long long grn500);
        void Read();
        std::string toString() const;
        void Display() const;

        Money add(const Money& other) const;
        Money subtract(const Money& other) const;
        double divide(const Money& other) const;
        Money divideDouble(double value) const;
        Money multiplyDouble(double value) const;

        bool Equal(const Money& other) const;
        bool NotEqual(const Money& other) const;
        bool Greater(const Money& other) const;
        bool Less(const Money& other) const;

        Money operator+(const Money& other) const;
        Money operator-(const Money& other) const;
        double operator/(const Money& other) const;
        Money operator/(double value) const;
        Money operator*(double value) const;

        bool operator==(const Money& other) const;
        bool operator!=(const Money& other) const;
        bool operator>(const Money& other) const;
        bool operator<(const Money& other) const;
    };
}