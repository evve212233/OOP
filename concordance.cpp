#include "std_lib_facilities.h"
int main(){
	vector<string> text;
	cout<<"Please enter word by word: (press ctrl D to exit) \n";
	//prof says press ctrl D to exit
	for(string word; cin>>word;){
		text.push_back(word);
	}
	sort(text);
	cout<<"\nThe sorted text is:\n";
	for (string w:text){
		cout<<w<<" ";
	}
	cout<<"\n";
	int count=1;
	for (int wd=1;wd<text.size();wd++){
		if (text[wd]==text[wd-1]){
			count++;
		}
		else{
			cout<<text[wd-1]<<" has "<< count<<" words\n";
			count=1;
		}
	}
	cout<<text[text.size()-1]<<" has "<<count<<" words\n";
	return 0;
}