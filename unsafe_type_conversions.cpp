#include "std_lib_facilities.h"
int main(){
	cout<<"\nSafe Conversions:\n";
	bool b1=true;
	char c1=b1;
	cout << "\nbool b1=" << b1 <<"\nbool b1 to char c1="<<c1<<"\n";
	int i1=b1;
	cout << "\nbool b1=" << b1 <<"\nbool b1 to int i1="<<i1<<"\n";
	double d1=b1;
	cout << "\nbool b1=" << b1 <<"\nbool b1 to double d1="<<d1<<"\n";
	char c2='a';
	int i2=c2;
	cout << "\nchar c2=" << c2 <<"\nchar c2 to int i2="<<i2<<"\n";
	double d2=c2;
	cout << "\nchar c2=" << c2 <<"\nchar c2 to double d2="<<d2<<"\n";
	double d3=i2;
	cout << "\nint i2=" << i2 <<"\nint i2 to double d2="<<d2<<"\n";


    cout<<"\nUnsafe Conversions:\n";
	int i=3000000;
	char c=i;
	cout << "\nint i=" << i <<"\ninto i to char c="<<c<<"\n";
	bool bl=i;
	cout << "\nint i=" << i <<"\nint i to bool bl="<<bl<<"\n";
	bool bc=c;
	cout << "\nchar c=" << c <<"\nchar c to bool bc="<<bc<<"\n";
	double d=1.5423;
	int id=d;
	cout << "\ndouble d=" << d <<"\ndouble d to int id ="<<id<<"\n";
	char dc=d;
	cout << "\ndouble d=" << d <<"\ndouble d to char dc="<<dc<<"\n";
	bool db=d;
	cout << "\ndouble d=" << d <<"\ndouble d to bool db="<<db<<"\n";
}