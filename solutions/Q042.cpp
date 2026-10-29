#include <iostream>
#include <stack>
#include <string>
#include <cstring>
using namespace std;

bool isOperator(char x) {
    return strchr("+-/*^", x) != NULL;
}

string preToPost(string pre_exp) {
    stack<string> s;
    int len = pre_exp.size();
    for (int i = len - 1; i >= 0; i--) {
        if (isOperator(pre_exp[i])) {
            string op1 = s.top(); s.pop();
            string op2 = s.top(); s.pop();
            s.push(op1 + op2 + pre_exp[i]);
        } else {
            s.push(string(1, pre_exp[i]));
        }
    }
    return s.top();
}

int main() {
    string pre_exp;
    if (cin >> pre_exp) {
        cout << "Postfix:" << preToPost(pre_exp) << "\n";
    }
    return 0;
}

