#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

string getInfix(string exp) {
    stack<string> s;
    for (char c : exp) {
        if (isalnum((unsigned char)c)) {
            s.push(string(1, c));
        } else {
            string b = s.top(); s.pop();
            string a = s.top(); s.pop();
            s.push("(" + a + c + b + ")");
        }
    }
    return s.top();
}

int main() {
    string exp;
    if (cin >> exp) {
        cout << getInfix(exp) << "\n";
    }
    return 0;
}

