#include "std_lib_facilities.h"
#include "date.h"
int main(){
	Date today{2018,Month::feb,20};
	Date tomorrow{2018,Month::feb,21};
//	cout<<"Year="<<today.year()<<"\n"<<"Month= "<<today.month()<<"\n"<<"Day="<<today.day()<<endl;
	cout<<"Today is "<<today<<"\n";
	cout<<"Tomorrow is "<<tomorrow<<"\n";
	cout<<"If same day:"<<(today==tomorrow)<<"\n";
	cout<<"If different day:"<<(today!=tomorrow)<<"\n";//check bool op
	cout<<"leap year: "<<leapYear(2012)<<"\n";//check leap year
	today.add_day(400);
	cout<<"Add 400 days to today:"<<today<<"\n";
	Date new_date;
	cout<<"Please enter a new date in format (YYYY,MM,DD)\n>>";
	while(cin){
        try{
            cin >> new_date;
            break;
        }catch(exception e){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Enter again: \n";
        }catch(Date::Invalid){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Enter again: \n";
        }
    }
	cout<<"New date in long form: "<<longForm(new_date)<<"\n";
	return 0;
}
