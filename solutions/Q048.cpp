#include <iostream>
#include <stack>
#include <string>
#include <cstring>
using namespace std;

bool isOperator(char x) {
    return strchr("+-/*^", x) != NULL;
}

string postToPre(string post_exp) {
    stack<string> s;
    int len = post_exp.size();
    for (int i = 0; i < len; i++) {
        if (isOperator(post_exp[i])) {
            string op2 = s.top(); s.pop();
            string op1 = s.top(); s.pop();
            s.push(post_exp[i] + op1 + op2);
        } else {
            s.push(string(1, post_exp[i]));
        }
    }
    return s.top();
}

int main() {
    string post_exp;
    if (cin >> post_exp) {
        cout << postToPre(post_exp) << "\n";
    }
    return 0;
}

