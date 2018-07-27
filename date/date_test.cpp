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
	today.add_day(20);
	cout<<"Add 20 days to today:"<<today<<"\n";
	Date new_date;
	cout<<"Please enter new date\n>>";
	cin>>new_date;
	cout<<"New date: "<<new_date<<"\n";
	return 0;
}