#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int ans = 0;
    int i = 0;

    while (n != 0) {
        int bit = n & 1;

        int place = 1;
        for (int j = 0; j < i; j++) {
            place *= 10;
        }

        ans = (bit * place) + ans;

        n = n >> 1;
        i++;
    }

    cout << "The Binary representation of n is: " << ans;

    return 0;
}
