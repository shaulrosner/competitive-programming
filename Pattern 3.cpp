#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;
    cin >> t;
    string s;
    while (t--){
        cin >> s;
         int n = s.size();
        vector<int> z(n);
        int x=0, y=0;
        for (int i=1; i<n; i++){
        z[i] = max(0, min(z[i-x], y-i+1));
        while(i+z[i] < n && s[z[i]] == s[i+z[i]]){
          x = i;
          y = i+z[i]; 
          z[i] ++;
        }
        }
          for (int i=0; i<n;i++){
      if (z[i] == n-i){
        cout << i << "\n";
          goto done;
      }
  }
        cout << n << "\n";
        done:;
    }
    return 0;
}
