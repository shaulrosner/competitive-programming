#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, h, st, v, v2;
    string s;
    cin >> n;
    vector<pair<int, string>> p;
    for (int i=0; i<n; i++){
        cin >> s >> h;
        p.push_back(pair<int, string>(h, s));
    }
    sort(p.begin(), p.end());
    v= get<0>(p[0]);
    cout << get<1>(p[0]) << " ";
    st = 1;
    for (int i=1; i<n; i++){
        v2 = get<0>(p[i]);
        if (v2 != v){
            cout << st << " " << i << "\n";
            v = v2;
            st = i+1;
        }
        cout << get<1>(p[i]) << " ";
    }
    cout << st << " " << n << "\n";
    return 0;    
}