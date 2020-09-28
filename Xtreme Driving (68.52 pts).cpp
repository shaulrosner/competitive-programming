#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define mod 1000000007;
void mult(long long a[][4], long long b[][4], long long c[][4]){
    for (int i=0; i<4; i++){
        for (int j=0;j<4; j++){
            long long curr = 0;
            for (int k=0; k<4; k++){
                curr = (curr + a[i][k] * b[k][j]) % mod;
            }
            c[i][j] = curr;
        }
    }
}
void power(long long a[][4], long long b[][4], long long c[][4], int k){
    if (k==0){
        for (int i=0; i<4; i++){
            for (int j=0;j<4; j++){
                b[i][j] = i == j;
            }
        }
        return;
    }
    if (k%2 == 0){
        power(a, c, b, k/2);
        mult(c, c, b);
    }
    else{
        power (a, b, c, k/2);
        mult(b, b, c);
        mult(c, a, b);
    }
}

int main() {
    static long long b[4][4], c[4][4];
    long long rr, x, y;
    long long mvarr[4][4] = {
        {1,1,0,0},
        {1,1,1,0},
        {0,1,1,1},
        {0,0,1,1},
    };
    int n;
    cin >> rr >> n;
    vector<pair<long long, long long>> cows;
    for (int i=0; i< n; i++){
        cin >> x >> y;
        cows.push_back({y-1, x-1});
    }
    sort(cows.begin(), cows.end());
    long long total[4] = {1, 0, 0, 0};
    long long outtotal[4] = {0, 0, 0, 0};
    long long last = 0; 
    bool bad[4] = {false, false, false, false};
    for (int i=0; i<n; i++){
        y= cows[i].first;
        x = cows[i].second;
        bad[x] = true;
        if (i+1<n && cows[i+1].first == y){
            continue;
        }
        if (y - last > 0){
            power(mvarr, b, c, y-last);
            for (int u =0; u<4;u++){
                long long s = 0;
                for (int l=0;l<4;l++){
                    s = (s + total[l]*b[l][u]) % mod;
                }
                outtotal[u] = s % mod;
            }
            for (int u=0; u<4; u++){
                if (bad[u]){
                    total[u] = 0;
                }
                else{
                    total[u] = outtotal[u];
                }
            }
        }
        for (int l=0;l<4;l++){
            bad[l] = false;
        }
        last = y;
    }
        power(mvarr, b, c, rr - last -1);
        for (int u =0; u<4;u++){
            long long s = 0;
            for (int l=0;l<4;l++){
                s = (s + total[l]*b[l][u]) % mod;
            }
            outtotal[u] = s % mod;
        }

    cout << outtotal[0];
    return 0;
}
