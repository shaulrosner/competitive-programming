#include <iostream>

#include <algorithm>
#include<vector>
using namespace std;

int main() {
    long long n, t;
    long long first;
    long long curr;
    vector<long long> s;
    cin >> n >> t;
    long long arr[1000000];
    cin >> first;
    arr[0] = 0;
    for (long long i=1;i<n;i++){
        cin >> curr;
        arr[i] = curr - first;
    }
    // for (int i=0;i<n;i++){
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    long long n2 = 2*n;
    for (long long i=0;i<n2;i++){
        s.push_back((arr[(i+1)%n] - arr[i%n] + t)%t);
    }
    // for (int i=0;i<n2;i++){
    //     cout << s[i] << " ";
    // }
    // cout << endl;
  vector<long long> z(n2);
  long long x=0, y=0;
  for (int i=1; i<n2; i++){
      z[i] = max(0LL, min(z[i-x], y-i+1));
      while(i+z[i] < n2 && s[z[i]] == s[i+z[i]]){
          x = i;
          y = i+z[i];
          z[i] ++;
      }
  }
  long long best = -1LL;
//   for (int i=0;i<n2;i++){
//       cout << z[i] << " ";
//   }
//   cout << endl;
  for (long long i=1; i<n ;i++){
      if (t%(t-arr[i]) == 0 && z[i] >= n){
          best = t-arr[i];
      }
  }
  if (best == -1){
    cout << t-1;   
  }
  else{
    cout << best - 1;
  }
    return 0;
}