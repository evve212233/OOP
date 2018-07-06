#include "std_lib_facilities.h"
int main(){
	int num_of_words=0;
	string previous=" ";
	string current;
	while (cin >> current){
		++num_of_words;
	    if (previous==current)
		    cout << "word number " << num_of_words <<" repeated: " << current;
	    previous=current;
	}
}