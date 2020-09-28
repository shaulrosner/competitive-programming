#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int t, n, p_count;
long long pows[24];
long long total, product, s, comb;

int main() {
    pows[0] = 1;
    for (int i=1; i< 24; i++) pows[i] = 2LL*pows[i-1];
    cin >> t;
    for(int x=0;x<t;x++){
        total =0;
        cin >> s >> n;
        long long p[n];
        for (int i=0;i<n;i++) cin >> p[i];
        comb = 1 << n;
        for(int i =1; i<comb;i++){
            p_count = 0;
            product = 1;
            for (int j=0; j<n; j++){
                if ((i>>j) % 2 == 1){
                    p_count += 1;
                    product *= p[j];
                }
                if (product > s || product<0) goto cnt;
            }
            if (p_count % 2 == 1) total += (s/product) * pows[p_count - 1];
            else total -= (s/product) * pows[p_count - 1];
            cnt:;
        }
        cout << total << "\n";
    }
}
