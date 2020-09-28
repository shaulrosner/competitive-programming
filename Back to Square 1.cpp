#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    double t;
    cin >> n;
    double probs[1001];
    while (n != 0){
        if (n==1){
            cout << 1 << "\n";
            cin >> n;
            continue;
        }
        double ans = 1;
        double curr = 1;
        for (int j=1; j<n;j++){
            cin >> t;
            probs[j-1] = t;
        }
        for (int j=n-2; j>=0; j--){
            curr = curr * 1.0/probs[j];
            ans += curr;
        }
        cout << (long)round(ans) << "\n";
        cin >> n;
    }
    return 0;
}
