#include <iostream>
using namespace std;

int main() {
    int n, sum = 0;
    cin >> n;
    while (n) {
        sum += n%2;
        n /= 2;
    }
    cout << sum << endl;
    return 0;
}
