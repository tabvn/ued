#include <iostream>

using namespace std;


class Date {

private:
    int day, month, year;

public:

    int getDay() const {
        return day;
    }

    int getMonth() const {
        return month;
    }

    int getYear() const {
        return year;
    }

    void setDay(int day) {
        this->day = day;
    }

    void setMonth(int month) {
        this->month = month;
    }

    void setYear(int year) {
        this->year = year;
    }

};

int main() {

    int day,month,year;

    Date d;

    cin >> day >> month >> year;
    
    d.setDay(day);
    d.setMonth(month);
    d.setYear(year);
    
    cout << d.getDay() << "/" << d.getMonth() << "/" << d.getYear();
    
    

    return 0;
}