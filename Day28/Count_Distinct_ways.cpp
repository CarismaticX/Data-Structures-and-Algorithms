//Problem - https://www.naukri.com/code360/problems/count-ways-to-reach-the-n-th-stairs_798650

//This Problem was done using recursion so it will give a TLE error , will learn DP and optimize it in future
//Did this to Practice recursion 



#include <bits/stdc++.h> 
int countDistinctWays(int nStairs) {
    //  Write your code here.
    if(nStairs<0){
        return 0;
    }
    if(nStairs ==0){
        return 1;
    }


    int ans = countDistinctWays(nStairs-1) + countDistinctWays(nStairs-2);


    return ans;
}