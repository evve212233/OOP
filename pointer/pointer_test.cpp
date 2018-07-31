#include "std_lib_facilities.h"
int main(){
	char c='a';
	int i=4092;
	double d=3.14;
	char*cp=&c;
	int*ip=&i;
	double*dd=&d;

	cout<<"cp="<<cp<<" and its value is "<<*cp<<"\n";
	cout<<"ip="<<ip<<" and its value is "<<*ip<<"\n";
	cout<<"dd="<<dd<<" and its value is "<<*dd<<"\n";

	cout<<"size of cp is "<<sizeof(cp)<<", size of c is "<<sizeof(c)<<"\n";
	cout<<"size of ip is "<<sizeof(ip)<<", size of i is "<<sizeof(i)<<"\n";
	cout<<"size of dd is "<<sizeof(dd)<<", size of d is "<<sizeof(d)<<"\n";
}
