#include <iostream>
#include <stack>
#include <string>

using namespace std;

int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
    }
    return -1;
}

string infixToPostfix(string infix) {
    stack<string> data;
    stack<char> op;

    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];
        if (isalnum(ch)) {
            string s = "";
            s += ch;
            data.push(s);
        } else if (ch == '(' || op.empty() || op.top() == '(') {
            op.push(ch);
        } else if (ch == ')') {
            while (!op.empty() && op.top() != '(') {
                string v2 = data.top();
                data.pop();
                string v1 = data.top();
                data.pop();
                char o = op.top();
                op.pop();
                string t = v1 + v2 + o;
                data.push(t);
            }
            op.pop(); // Remove the '('
        } else {
            while (!op.empty() && precedence(ch) <= precedence(op.top())) {
                string v2 = data.top();
                data.pop();
                string v1 = data.top();
                data.pop();
                char o = op.top();
                op.pop();
                string t = v1 + v2 + o;
                data.push(t);
            }
            op.push(ch);//if precedint coming is greator 
        }
    }

    while (!op.empty()) {
        string v2 = data.top();
        data.pop();
        string v1 = data.top();
        data.pop();
        char o = op.top();
        op.pop();
        string t = v1 + v2 + o;
        data.push(t);
    }

    return data.top();
}

int main() {
    string infix = "9-(5+3)*4/6";
    string postfix = infixToPostfix(infix);
    cout << postfix << endl;
    return 0;
}
