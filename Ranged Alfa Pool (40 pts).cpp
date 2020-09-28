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
        pows.push_back((long long)curr-1LL);
        curr *= 2LL;
    }
    k = pows.size();
    mem[0] = 1;
    for(int i=1;i<1000001; i++){
        
        mem[i] = 0;
        for (int j=0; pows[j] <= i; j++){
            mem[i] = ((long long)mem[i] + mem[i-pows[j]]) % mod;
        }
    }
    for(int i=1;i<100001; i++){
        
        mem[i] = (((1LL * mem[i]) % mod)*2)%mod;
    }
    for (int i=1; i<100001; i++){
        mem[i] = ((long long)mem[i] + mem[i-1]) % mod;
    }
    while (n--){
        cin >> a >> b;
        if (a==0){
            cout << ((long long)mem[b]) % mod<< "\n";
        }
        else{
        cout << (((long long)mem[b] - (long long)mem[a-1])+ mod) % mod<< "\n";
        }
        //(mem[b] - ((a-1)? mem[a - 1]: 0) + mod) % mod << endl;
    }
}