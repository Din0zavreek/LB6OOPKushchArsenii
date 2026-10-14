#include "Money.h"
#include <iostream>
#include <cmath>

using namespace std;

namespace MoneySpace
{
    Money::Money() {
        Init(5, 3, 4, 2, 1, 3, 5, 8, 1, 6);
    }

    Money::Money(long long c10, long long c50, long long g1, long long g2, long long g5,
        long long g10, long long g50, long long g100, long long g200, long long g500) {
        if (!Init(c10, c50, g1, g2, g5, g10, g50, g100, g200, g500)) {
            Init(0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        }
    }

    Money::Money(const Money& other) {
        this->coin10 = other.coin10;
        this->coin50 = other.coin50;
        this->grn1 = other.grn1;
        this->grn2 = other.grn2;
        this->grn5 = other.grn5;
        this->grn10 = other.grn10;
        this->grn50 = other.grn50;
        this->grn100 = other.grn100;
        this->grn200 = other.grn200;
        this->grn500 = other.grn500;
    }

    Money::~Money() {}

    long long Money::Totalcoins() const {
        return coin10 * 10 + coin50 * 50 + grn1 * 100 + grn2 * 200 + grn5 * 500 +
            grn10 * 1000 + grn50 * 5000 + grn100 * 10000 + grn200 * 20000 + grn500 * 50000;
    }

    void Money::setFromTotalCoins(long long coins) {
        if (coins < 0) coins = 0;
        grn500 = coins / 50000; coins %= 50000;
        grn200 = coins / 20000; coins %= 20000;
        grn100 = coins / 10000; coins %= 10000;
        grn50 = coins / 5000;  coins %= 5000;
        grn10 = coins / 1000;  coins %= 1000;
        grn5 = coins / 500;   coins %= 500;
        grn2 = coins / 200;   coins %= 200;
        grn1 = coins / 100;   coins %= 100;
        coin50 = coins / 50;    coins %= 50;
        coin10 = coins / 10;
    }

    bool Money::Init(long long c10, long long c50, long long g1, long long g2, long long g5,
        long long g10, long long g50, long long g100, long long g200, long long g500) {
        if (c10 < 0 || c50 < 0 || g1 < 0 || g2 < 0 || g5 < 0 ||
            g10 < 0 || g50 < 0 || g100 < 0 || g200 < 0 || g500 < 0) {
            cout << "Помилка: кількість монет та купюр не може бути від'ємною. Спробуйте ще раз." << endl;
            return false;
        }

        this->coin10 = c10;
        this->coin50 = c50;
        this->grn1 = g1;
        this->grn2 = g2;
        this->grn5 = g5;
        this->grn10 = g10;
        this->grn50 = g50;
        this->grn100 = g100;
        this->grn200 = g200;
        this->grn500 = g500;

        return true;
    }

    void Money::Read() {
        long long c10, c50, g1, g2, g5, g10, g50, g100, g200, g500;
        do {
            cout << "Введіть кількість купюр та монет: " << endl;
            cout << "Монети 10 коп: "; cin >> c10;
            cout << "Монети 50 коп: "; cin >> c50;
            cout << "Купюри 1 грн: "; cin >> g1;
            cout << "Купюри 2 грн: "; cin >> g2;
            cout << "Купюри 5 грн: "; cin >> g5;
            cout << "Купюри 10 грн: "; cin >> g10;
            cout << "Купюри 50 грн: "; cin >> g50;
            cout << "Купюри 100 грн: "; cin >> g100;
            cout << "Купюри 200 грн: "; cin >> g200;
            cout << "Купюри 500 грн: "; cin >> g500;
        } while (!Init(c10, c50, g1, g2, g5, g10, g50, g100, g200, g500));
    }

    std::string Money::toString() const {
        long long coins = Totalcoins();
        long long grn = coins / 100;
        long long remaingcoins = coins % 100;
        return std::to_string(grn) + "," + std::to_string(remaingcoins) + " грн";
    }

    void Money::Display() const {
        std::cout << toString() << std::endl;
    }

    Money Money::add(const Money& other) const {
        Money result;
        result.setFromTotalCoins(this->Totalcoins() + other.Totalcoins());
        return result;
    }

    Money Money::subtract(const Money& other) const {
        Money result;
        long long diff = this->Totalcoins() - other.Totalcoins();
        result.setFromTotalCoins(diff < 0 ? 0 : diff);
        return result;
    }

    double Money::divide(const Money& other) const {
        if (other.Totalcoins() == 0) {
            cout << "Помилка: ділення на нуль." << endl;
            return 0.0;
        }
        return double(this->Totalcoins()) / other.Totalcoins();
    }

    Money Money::divideDouble(double value) const {
        Money result;
        if (value == 0.0) {
            cout << "Помилка: ділення на нуль." << endl;
            result.setFromTotalCoins(0);
            return result;
        }
        long long newCoins = round(this->Totalcoins() / value);
        result.setFromTotalCoins(newCoins);
        return result;
    }

    Money Money::multiplyDouble(double value) const {
        Money result;
        if (value < 0) value = 0;
        long long newCoins = round(this->Totalcoins() * value);
        result.setFromTotalCoins(newCoins);
        return result;
    }

    bool Money::Equal(const Money& other) const { return this->Totalcoins() == other.Totalcoins(); }
    bool Money::NotEqual(const Money& other) const { return !Equal(other); }
    bool Money::Greater(const Money& other) const { return this->Totalcoins() > other.Totalcoins(); }
    bool Money::Less(const Money& other) const { return this->Totalcoins() < other.Totalcoins(); }

    Money Money::operator+(const Money& other) const { return add(other); }
    Money Money::operator-(const Money& other) const { return subtract(other); }
    double Money::operator/(const Money& other) const { return divide(other); }
    Money Money::operator/(double value) const { return divideDouble(value); }
    Money Money::operator*(double value) const { return multiplyDouble(value); }

    bool Money::operator==(const Money& other) const { return Equal(other); }
    bool Money::operator!=(const Money& other) const { return NotEqual(other); }
    bool Money::operator>(const Money& other) const { return Greater(other); }
    bool Money::operator<(const Money& other) const { return Less(other); }
}