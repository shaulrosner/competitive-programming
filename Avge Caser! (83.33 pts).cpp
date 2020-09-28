#include <iostream>
#include <cstring>
#include <string>
#include <map>
using namespace std;

string s;
map<long long, bool> mem;
bool valid(int a, int b){
    if (b-a == 1){
        return true;
    }
    if (mem.count(100000*a + b) > 0){
        return mem[100000*a + b];
    }
    for (int i = a+1; i<b;i++){
        bool res1 = valid(a, i);
        mem[100000*a + i] = res1;
        if (!res1){
            continue;
        }
        bool res2 = valid(i, b);
        mem[100000*i + b] = res2;
        if (!res2){
            continue;
        }
        if (string(s.begin() + a, s.begin() + i) <= string(s.begin() + i, s.begin() + b) && res1 && res2){
            return true;
        }
    }
    return false;
}
        
int main(){
    int n;
    bool ans;
    cin >> n;
    while (n--){
        cin >> s;
        mem.clear();
        ans = valid(0, s.size());
        if (ans){
            cout << 1;
        }
        else{
            cout << 0;
        }
    }
}