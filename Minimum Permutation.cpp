#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m,c =0;
    int input, ac=0, sc=0;
    cin >> n >> m;
    vector<int> a;
    vector<int> s;
    for (int i=0;i<n;i++){
        cin >> input;
        a.push_back(input);
    }
    for (int i=0;i<m;i++){
        cin >> input;
        s.push_back(input);
    }
    sort(s.begin(), s.end());
    while (sc<m && ac<n+c){
        if (a[ac]>s[sc]){
            a.insert(a.begin()+ac, s[sc]);
            sc += 1;
            c += 1;
        }
        else ac +=1;
    }
    while(sc <m){
        a.push_back(s[sc]);
        sc += 1;
    }
    for (int i=0; i<n+m;i++){
        cout<< a[i] << " ";
    }
    return 0;
}