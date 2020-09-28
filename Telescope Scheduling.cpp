#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {
    long long n, s, f, d, start;
    cin >> n;
    vector<tuple<int, int, int>> a;
    int p[n];
    for (int i=0; i<n;i++){
        cin >> s >> f >> d;
        a.push_back(tuple<int, int, int>(f,s,d));
    }
    a.sort(a.begin(), a.end());
    int j;
    p[0] = get<2>(a[0]);
    for (int i=1; i<n; i++){
        j=0;
        start = get<1>(a[i]);
        for (; j<i; j++){
            if (get<0>(a[j]) >=  start){
                break;
            }
        }
        p[i] = max(p[i-1], get<2>(a[i]) + p[j-1]);
        //cout <<i << " " << p[i-1] << " " <<  get<2>(a[i]) + p[j-1] << " " << p[i] << "\n";
    }
    
    
    cout << p[n-1];
    return 0;
}