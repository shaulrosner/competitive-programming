#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
int main() {
    int t;
    ll m,n,k;
    ll a;
    cin >> t;
    while(t--){
        ll total = 0;
        cin >> m >> n >> k;
        vector<ll> v;
        for (int i=0;i<m;i++){
            cin >> a;   
            v.push_back(a);
        }
        sort(v.begin(), v.end());
        for (int i=0;i<k;i++){
            total += n-v[i];
        }
        for (int i=k;i<m;i++){
            total += v[i];
        }
        cout << total << "\n";
    }
}
