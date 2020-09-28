#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    std::ios_base::sync_with_stdio (false);
        cin.tie(NULL);
    cout.tie(NULL);
    int t;
    int s, d;
    cin >> t;
    string str;
    int per, bad;
    

    while (t--){
        int counter[26] = {0};
        cin >> d >> s;
        while (d--){
                int ccounter[26] = {0};
            cin >> str;
            for (auto c: str){
                ccounter[c-'a'] ++;
            }
            for (int i=0;i<26;i++){
                if (ccounter[i] > counter[i]){
                    counter[i] = ccounter[i];
                }
            }
        }
        while (s--){
            per = 0;
            bad = 0;
            int ccounter[26] = {0};
            cin >> str;
            for (auto c:str){
                ccounter[c- 'a'] ++;  
            }
            for (int i=0; i<26; i++){
                if (ccounter[i] < counter[i]){
                    bad += counter[i] - ccounter[i];
                }
                else if (ccounter[i] == counter[i]){
                    per ++;
                }
            }
            if (bad ==0){
                cout << "Yes ";
                if (per == 26){
                    cout << "Yes\n";
                }
                else{
                    cout << "No\n";
                }
            }
            else{
                cout << "No " << bad << "\n";
            }
        }
    }
    return 0;
}
