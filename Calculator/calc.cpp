#include "std_lib_facilities.h"
#include "token.h"
#include "vars.h"
#include "funcs.h"

const string prompt = "> ";
const string result = "= ";

double expon(Token_stream& ts);
double statement(Token_stream& ts);
double expression(Token_stream& ts);
double term(Token_stream& ts);
double primary(Token_stream& ts);

Token_stream ts;

void clean_up_mess()
{
    ts.ignore(print);
}

vector<Token> tokens;

double statement(Token_stream& ts){
    Token t = ts.get();
    if(t.kind == name) {
        Token var = t;
        t = ts.get();
        if(t.kind == '=') {
            double d = expression(ts);
            set_value(var.name, d);
            return d;
        }
        else if(t.kind == print) {
            ts.putback(t);
            return get_value(var.name);
        }
        ts.putback(t);
        ts.putback(var);
        return expression(ts);
    }
    ts.putback(t);
    return expression(ts);
}

double expon(Token_stream& ts)
{
/* grammar recognized:
Exp:
    Primary
    Primary "^" Primary
*/
    double left = primary(ts);
    Token t = ts.get();
    if(t.kind == power) {
        double d = primary(ts);
        return pow(left, d);
    }
    else {
        ts.putback(t);     // put t back into the token stream
        return left;
    }
}

double primary(Token_stream& ts){
    Token t = ts.get();
    //print_token(t); to check what value is stored in token
    switch (t.kind){
        case '(':    // handle '(' expression ')'
        {
            double d = expression(ts);
            t = ts.get();
            if (t.kind != ')') error("')' expected");
            return d;
        }
        case number:
            return t.value;  // return the number's value
        case name:{
            Token next_t = ts.get();
            if(next_t.kind == '(') {
                double d = expression(ts);
                next_t = ts.get();
                if (next_t.kind != ')') error("')' expected");
                d=exec_func(t.name,d);
                return d;
            }
            else {
                ts.putback(next_t);
                return get_value(t.name);
            }
        }
        case '-':
            return -primary(ts);
        case '+':
            return primary(ts);
        case invalid:
            error("Received Invalid Token");
        default:
            error("primary expected");
    }
    return 0.0;
}
double term(Token_stream& ts)
{
    double left = expon(ts);
    Token t = ts.get();        // get the next token from token stream

    while(true) {
        switch (t.kind) {
        case '*':
            left *= expon(ts);
            t = ts.get();
            break;
        case '/':
            {
                double d = expon(ts);
                if (d == 0) error("divide by zero");
                left /= d;
                t = ts.get();
                break;
            }
        case '%':
            {
                double d = expon(ts);
                if (d == 0) error("divide by zero");
                left = fmod(left, d);
                t = ts.get();
                break;
            }
        default:
            ts.putback(t);     // put t back into the token stream
            return left;
        }
    }

}
double expression(Token_stream& ts){
    double left = term(ts);
    Token t = ts.get();
    while(true){
        switch(t.kind){
            case '+': {
                left += term(ts);
                t = ts.get();
                break;
            }
            case '-':{
                left -= term(ts);
                t = ts.get();
                break;
            }default:
                ts.putback(t);
                return left;
        }
    }
//    t = ts.get();
}

void calculate(Token_stream& ts)
{
    while(cin) {
        try {
            cout << prompt;
            Token t = ts.get();
            //this output is for debugging:
            //cout << "in main(), got token: " << t.kind
            //<< " with val of " << t.value << '\n';
            while(t.kind == print){
                t = ts.get();
            }
            if(t.kind == quit){
                return;
            }
            ts.putback(t);
            cout<<setprecision(10)<< result << statement(ts) << '\n';
        }catch(exception& e) {
            cerr << e.what() << '\n';
            clean_up_mess();
        }
    }

}

int main()
{
    try {
        calculate(ts);
        // keep_window_open();   // only if needed!
        return 0;
    }
    catch(...) {
        cerr << "unknown exception \n";
        return 2;
    }
}
