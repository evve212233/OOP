#include "std_lib_facilities.h"
#include "date.h"

Date::Date(int yy, Month mm, int dd): y{yy}, m{mm}, d{dd}{
    if(!isValid()) throw Invalid{};
}

//construct default date
const Date& default_day(){
    static Date dd{2000, Month::jan, 1};
    return dd;
}

Date::Date() //set to default
    :y{default_day().year()},
    m{Month(default_day().month())},
    d{default_day().day()}{}

void Date::add_day(int n)
{
    if (n<0) error("Invalid: cannot handle negative number");
    if (!leapYear(y)){
    int curr=int(m);//current month
    add_year(n/365);
    n=n%365;
    d+=n;
    for (int i=1;i<13;i++){
        if (curr==i){
            if (last_day[i]<d){
                add_month(1);
                d-=last_day[i];
                curr+=1;
            }
        }
    }
    }
    else{
    int curr=int(m);//current month
    add_year(n/365);
    n=n%365;
    d+=n;
    for (int i=1;i<13;i++){
        if (curr==i){
            if (leap_last_day[i]<d){
                add_month(1);
                d-=leap_last_day[i];
                curr+=1;
            }
        }
    }
    }
}
void Date::add_month(int n){
    if (n<0) error("Invalid: Cannot handle negative number");
    m=Month(n+int(m));
    if (int(m)>=12){
        y+=(int(m)/12);
        m=Month(int(m)%12);
    }

}

void Date::add_year(int n){
    if (n<0) error("Invalid: Cannot handle negative number");
    if(int(m)==2 && d==29 && !leapYear(y+n)){
        m=Month(3);
        d=1;
    }
    y+=n;
}

//checking valid date
bool Date::isValid(){
    if(int(m) < 1 || int(m) > 12)return false;
    if(y < 0)return false;
    if(d < 0 || d > 31) return false;
    else{
        if(int(m) ==2){
            if (leapYear(y)) {
                if(d > 29) return false;
            }else{
                if(d > 28) return false;
            }
        }
        switch(int(m)){
            case 4: case 6: case 9: case 11:
                if(d > 30) return false;
        }
    }
    return true;
}

ostream& operator << (ostream& os, const Date& d){
    return os << '(' << d.year() << ',' << d.month() << ',' << d.day() << ')';
}

istream& operator >> (istream& is, Date& dd){
    int y, m, d;
    char ch1, ch2, ch3, ch4;
    is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
    if(!is) return is;
    if(ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')'){
        is.clear(ios_base::failbit);
        return is;
    }
    dd = Date{y, Month(m), d};
    return is;
}

string longForm(Date d){
    string res= '('+month_names[d.month()]+','+to_string(d.day())+','+to_string(d.year())+')';
    return res;
}

bool operator == (const Date& d1, const Date& d2){
    if(d1.year() == d2.year() && int(d1.month()) == int(d2.month()) && d1.day() == d2.day()) return true;
    else return false;
}

bool operator != (const Date& d1, const Date& d2){
    return !(d1 == d2);
}


bool leapYear(int y){
    return ((((y % 4) == 0) && (y % 100) != 0) || (y % 400) == 0);
}
