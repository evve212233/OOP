#include "std_lib_facilities.h"
class Token{
public:
	//two members
	char kind;
	//8 means float
	double value;
};
Token get_token(){
	char ch;
	cin>>ch;
	switch(ch){
		case ';': case 'q': case '(': case '+':case '-': case '*': case '/': case ')':
			return Token{ch};
			//value is default 0;
		case '0': case '1': case '2': case '3':case '4': case '5': case '6': case '7':case '8': case '9':
			cin.putback(ch);
			//putback
			double val;
			cin>>val;
			return Token{'8',val};
	}
};
vector <Token> tokens;
int main(){
	Token t=get_token();
	while (t.kind!='q'){
		tokens.push_back(t);
		t=get_token();
	}
	for (Token tok:tokens){
		if(tok.kind=='8')
			cout<<"a number with val is "<<tok.value<<"\n";
		else
			cout<<"an token with expression is "<<tok.kind<<"\n";
	}

}