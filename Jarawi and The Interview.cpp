#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q, val;
    string s, p;
    cin >> s;
    cin >> q;
    int trie[26][1000000+1];
    int counter[26] = {0};
    int n = s.length();
    for (int i=0; i < n; i++){
        trie[s[i] - 'a'][counter[s[i] - 'a']] = i;
        counter[s[i] - 'a'] += 1;
    }
    for (int i=0; i< q; i++){
        cin >> p;
        n = p.length();
        int c = 1e8;
        int le;
        //int ccounter[26] = {0};
        int *idxptr = nullptr;
        int x;
        for (x=n - 1; x>=0; x--){
            le = p[x] - 'a';
            idxptr = upper_bound(trie[le], trie[le] + counter[le], c-1);
            if (idxptr == trie[le]){
                break;
            }
            c = *(--idxptr);
        
                }
                cout << n - x - 1 << "\n";
            }
            return 0;
        }
