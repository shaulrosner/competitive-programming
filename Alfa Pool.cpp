#include <iostream>
#include <vector>
using namespace std;
#define mod 1000000007
vector<long long> pows;
long long mem[1000001];
int k, b, a;
int main() {
    int n;
    cin >> n;
    
    long long curr = 2;
    while (curr<=2000001){
        pows.push_back(curr-1);
        curr *= 2LL;
    }
    k = pows.size();
    mem[0] = 1;
    for(int i=1;i<100001; i++){
        
        mem[i] = 0;
        for (int j=0; pows[j] <= i; j++){
            mem[i] = (mem[i] + mem[i-pows[j]]) % mod;
        }
    }
    for(int i=1;i<100001; i++){
        
        mem[i] = (1LL * mem[i]*2)%mod;
    }
    long long res;
    while (n--){
        cin >> a >> b;
        cout << mem[b] << endl;
    }
}