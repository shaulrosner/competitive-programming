#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define INF 1e18
int main() {
    int t;
    cin >> t;
    ll c, h, o;
    ll lc, lh, lo;
    ll curr;
    while (t--){
        cin >> c >> h >> o;
        ll best = INF;
        for (ll i=0;i<1000000;i++){
            curr = 0;
            lc = c - 6LL*i;
            lh = h - 12LL*i;
            lo = o - 6LL*i;
            if (lh <= 0){
                curr -= lh;
            }
            else{
                lo -= lh / 2;
                lh -= 2*(lh/2);
                curr += abs(lh)% 2;
            }
            if (lo <= 0){
                curr -= lo;
            }
            else{
                lc -= lo/2;
                lo -= 2*(lo/2);
                curr += abs(lo) % 2;
            }
            curr += abs(lc);
            if (lo>0 && lh >0){
                curr -= 1;
                lo -=1;
            }
            if (lo > 0 && lc >0){
                curr -=1;
            }
            if (curr < best){
                //cout << "mem " << i << "\n";
                best = curr;
            }
        }
        cout << best << "\n";
    }
}