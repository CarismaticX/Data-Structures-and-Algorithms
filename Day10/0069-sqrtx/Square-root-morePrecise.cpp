//A more precise answer of the sqaure root problem , upto decimal places 
#include <iostream>
using namespace std;



int squareRoot(int n) {
        int s = 0;
        int e = n;
        int ans = 0;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            long long square = (long long)mid * mid;  // use long long to avoid overflow

            if (square == n) {
                return mid;
            } else if (square > n) {
                e = mid - 1;
            } else {
                ans = mid;
                s = mid + 1;
            }
        }
        return ans;
    }

    double morePrecision(int n, int precision, int tempsol){

        double factor =1;
        double ans = tempsol;

        for(int i =0; i<precision; i++){
            factor = factor/10;

            for(double j = ans; j*j<n; j = j+ factor){
                ans = j;
            }
        }
        return ans;
    }


    int main() {

        int n;
        cin>>n;

        int tempsol = squareRoot(n);

        cout<<"The more precise answer is "<<morePrecision(n,3,tempsol)<<endl;
    

    return 0;
}