#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int main() {
    int n, m ,s;
    cin >> n>> m >> s;
    long long result = ceil(log2(n))*s + (n-1)*m;
    cout << result;
    return 0;
}