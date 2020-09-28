#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define mod 1000000007
int n;
int root[1000000];
int coun[1000000];
vector<pair<long long, pair<int,int>>> adj;
int find(int x){
    while ( x != root[x]) x = root[x];
    return x;
}
bool same(int a, int b){
    return find(a) == find(b);
}
void unite(int a, int b){
    a = find(a);
    b = find(b);
    if (coun[a] < coun[b]) swap(a,b);
    coun[a] += coun[b];
    root[b] = a;
}
int main() {
    int a, b;
    long long  w;
    cin >> n;
    for (int i=0; i<n;i++){
        root[i] = i;
        coun[i] = 1;
    }
    for (int i=0;i<n-1; i++){
        cin >> a >> b >> w;
        adj.push_back({w,{a, b}});
    }
    sort(adj.begin(), adj.end());
    long long total = 0;
    for (auto p:adj){
        w = p.first;
        a = p.second.first;
        b = p.second.second;
        total = (total + 1ll * w * coun[find(a)]%mod * coun[find(b)]%mod)%mod;
        unite(a, b);
    }
    cout << total;
}