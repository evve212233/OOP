#include "std_lib_facilities.h"
enum class Month {
    jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

enum class Day {
    monday, tuesday, wednesday, thursday, friday, saturday, sunday
};

const vector<int> last_day{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const vector<int> leap_last_day{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class Date{
public:
    class Invalid{};
    Date(int y, Month m, int d);
    Date();
    void add_day(int n);
    void add_month(int n);
    void add_year(int n);
    int month() const{ return int(m);}
    int year() const{ return y;}
    int day() const{ return d;}
private:
    int y,d;
    Month m;
    bool isValid();
};

ostream& operator << (ostream& os, const Date& d); //allow chaining of ostream eg. cout << x << y << z;

istream& operator >> (istream& is, Date& dd); // allow user input y,m,d

bool operator == (const Date& d1, const Date& d2);
bool operator != (const Date& d1, const Date& d2);
bool leapYear(int y);
