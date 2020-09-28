#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t, k, n, m, total;
    long long x;
    vector<long long> d, inter;
    cin >> t;
    for (int i=0; i<t; i++){
        total = 0;
        cin >> n >> k;
        for (int j=0; j<n; j++){
            cin >> x;
            d.push_back(x);
        }
        sort(d.begin(), d.end());
        for (int j=1; j<n; j++){
            inter.push_back(d[j] - d[j-1]);
        }
        sort(inter.begin(), inter.end());
        for (int j=0; j<n-k; j++){
            total += inter[j];
        }
        d.clear();
        inter.clear();
        cout << total << "\n";
    }
    return 0;
}