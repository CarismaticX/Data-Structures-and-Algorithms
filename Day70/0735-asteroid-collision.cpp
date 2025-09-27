class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int a : asteroids) {
            bool destroyed = false;

            // Check collisions
            while (!st.empty() && a < 0 && st.top() > 0) {
                if (abs(st.top()) < abs(a)) {
                    st.pop();       // top asteroid destroyed
                    continue;       // current asteroid may still collide
                } 
                else if (abs(st.top()) == abs(a)) {
                    st.pop();       // both destroyed
                    destroyed = true;
                    break;
                } 
                else {
                    destroyed = true; // current asteroid destroyed
                    break;
                }
            }

            if (!destroyed) {
                st.push(a);
            }
        }

        // Convert stack -> vector
        vector<int> res(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            res[i] = st.top();
            st.pop();
        }
        return res;
    }
};
