//Problem- https://www.geeksforgeeks.org/problems/prefix-to-infix-conversion/1

// User function Template for C++

class Solution {
  private:
    bool isOperator(char c) {
        return (c=='+' || c=='-' || c=='*' || c=='/' || c=='^');
    }

  public:
    string preToInfix(string pre_exp) {
        stack<string> st;
        int n = pre_exp.size();

        // traverse from right to left
        for (int i = n-1; i >= 0; i--) {
            char c = pre_exp[i];

            if (isOperator(c)) {
                string op1 = st.top(); st.pop();
                string op2 = st.top(); st.pop();
                string exp = "(" + op1 + c + op2 + ")";
                st.push(exp);
            } else {
                st.push(string(1, c));
            }
        }
        return st.top();
    }
};
