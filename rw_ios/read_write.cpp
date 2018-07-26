#include "std_lib_facilities.h"
struct Reading{
	int hour;
	double temp;
	double pressure;
};

int main()
{
    cout << "Please enter input file name: ";
    string iname;
    cin >> iname;
    ifstream ist {iname}; // ist reads from the file named iname
    if (!ist) error("can't open input file ",iname);

    string oname;
    cout << "Please enter name of output file: ";
    cin >> oname;
    ofstream ost {oname}; // ost writes to a file named oname
    if (!ost) error("can't open output file ",oname);

    vector<Reading> temps; // store the readings here
	int hour;
	char sep1;
	double temp;
	char sep2;
	double pressure;
    while (ist >> hour >>sep1>>temp>>sep2>>pressure) {
        temps.push_back(Reading{hour,temp,pressure});
    }
    for (int i=0; i<temps.size(); ++i)
        ost << temps[i].hour << " "
              << temps[i].temp <<" "<<temps[i].pressure<<"\n";
}