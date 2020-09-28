#include <iostream>

using namespace std;

int main() {
    long long j, k, a, b;
    cin >>k >> j;
    a = max(j, k);
    b = min(j, k);
    if (a > 2*b) cout << b;
    else cout << (a + b) / 3;
}