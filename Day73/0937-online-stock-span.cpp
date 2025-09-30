#include <bits/stdc++.h>
using namespace std;

class StockSpanner {
private:
    stack<pair<int,int>> st; // {price, span}

public:
    StockSpanner() {}

    int next(int price) {
        int span = 1;

        // Pop all smaller or equal prices and accumulate their spans
        while(!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }

        // Push current {price, span}
        st.push({price, span});
        return span;
    }
};



/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */