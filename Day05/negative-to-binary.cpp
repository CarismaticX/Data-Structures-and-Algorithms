//convert negative decimal number to binary 



#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    unsigned int num = static_cast<unsigned int>(n); // handle negatives
    string ans = "";
    int i = 0;

    while (num != 0 || i < 32) {  // print full 32-bit representation
        int bit = num & 1;
        ans = char('0' + bit) + ans;
        num = num >> 1;
        i++;
    }

    cout << "The Binary representation of n is :" << ans;

    return 0;
}
