#include "stackarr.cpp"
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

#define _Maxname 20

double Calcul(char* postfix);  //this is function which calculate postfix
bool IsOperator(char C);
double PerformOperation(char operation, double operand1, double operand2);
bool IsNumber(char C);
int main(void)
{
    char post[_Maxname];                //this is array that allocated the character of postfix

    do {
      cout << "This is calculator" << endl;
      cout << "Please input the postfix: ";
      cin >> post;                         //save the postfix on post array

      cout << "result: " << Calcul(post) << endl;   //Show the result
    } while (post[0] != 'Q'  &&  post[0] != 'q');
}

double Calcul(char* postfix)
{
    Stack<double> S;

    for(int i = 0;i< strlen(postfix);i++) {

        if(postfix[i] == ' ' || postfix[i] == ',') continue;

        else if(IsOperator(postfix[i])) {
            double operand2 = S.topElement(); S.pop();
            double operand1 = S.topElement(); S.pop();
            double result = PerformOperation(postfix[i], operand1, operand2);
            S.push(result);
        }
        else if(IsNumber(postfix[i])){
            S.push(postfix[i] - '0');
        }
    }
    return S.topElement();
}

bool IsOperator(char C)
{
    if(C == '+' || C == '-' || C == '*' || C == '/')
        return true;

    return false;
}

bool IsNumber(char C)
{
    if(C >= '0' && C <= '9') return true;
    return false;
}

double PerformOperation(char operation, double operand1, double operand2)
{
    if(operation == '+') return operand1 +operand2;
    else if(operation == '-') return operand1 - operand2;
    else if(operation == '*') return operand1 * operand2;
    else if(operation == '/') return operand1 / (double)operand2;

    else cout<<"Unexpected Error \n";
    return -1;
}
