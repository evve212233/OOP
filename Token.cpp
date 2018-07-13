#include "std_lib_facilities.h"
//A token is a sequence of characters that represents something we consider a unit, such 196 as a number or an operator
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
			//default value is default 0;
		case '0': case '1': case '2': case '3':case '4': case '5': case '6': case '7':case '8': case '9':
			cin.putback(ch);
			//putback
			double val;
			cin>>val;
			return Token{'8',val};
		default:
		    return Token{'x',double(ch)};
	}
};
vector <Token> tokens;
int main(){
//	Token t=get_token();
for(Token t=get_token(); t.kind!='q'; t=get_token()){
	tokens.push_back(t);
}
//	while (t.kind!='q'){
//		tokens.push_back(t);
//		t=get_token();
//	}

	for (Token tok:tokens){
		if(tok.kind=='8')
			cout<<"A number token with val = "<<tok.value<<"\n";
		else if (tok.kind=='x')
		    cout<<"we received an invalid token value of "<<char(tok.value)<<"\n";
		else
			cout<<"A token of kind "<<tok.kind<<"\n";
	}

}