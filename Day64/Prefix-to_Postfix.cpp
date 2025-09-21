//Problem - https://www.geeksforgeeks.org/problems/prefix-to-postfix-conversion/1



class Solution {
  public:
    string preToPost(string pre_exp) {
        stack<string> st;
        
        // Traverse prefix expression from right to left
        for (int i = pre_exp.size() - 1; i >= 0; i--) {
            char c = pre_exp[i];
            
            // If operand → push
            if (isalnum(c)) {
                st.push(string(1, c));
            }
            // If operator → pop two operands and combine
            else {
                string op1 = st.top(); st.pop();
                string op2 = st.top(); st.pop();
                
                string temp = op1 + op2 + c;
                st.push(temp);
            }
        }
        
        return st.top();
    }
};
