#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string postToInfix(string post_exp) {
    stack<string> st;
    for (int i = 0; i < post_exp.length(); i++) {
        char c = post_exp[i];

        // If operand, push as string
        if (!isOperator(c)) {
            st.push(string(1, c));
        }
        // If operator, pop two and combine
        else {
            string op2 = st.top(); st.pop();
            string op1 = st.top(); st.pop();
            string temp = "(" + op1 + c + op2 + ")";
            st.push(temp);
        }
    }
    return st.top();
}

int main() {
    string postfix = "ab+c*";
    cout << "Postfix Expression: " << postfix << endl;
    cout << "Infix Expression: " << postToInfix(postfix) << endl;
    return 0;
}
