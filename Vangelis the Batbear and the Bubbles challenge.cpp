#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> adj[1000];
bool visited[1000];
bool dfs(int s, int prev){
    //cout << s << " ";
    if (visited[s]){
        return false;
    }
    visited[s] = true;
    bool d;
    d = false;
    for (auto u:adj[s]){
        if (u==prev and !d){
            d=true;
            continue;
        }
        if (!dfs(u, s)) {
            return false;
        }
    }
    return true;
}
int main() {
    int t, n, m, a, b;
    cin >> t;
    for (int i=0; i<t; i++){
        cin >> n >> m;
        for (int j=0; j<1000;j++){
            visited[j] = false;
            adj[j].clear();
        }
       
        for (int j=0;j<m;j++){
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for (int j=0; j<n; j++){
            if (visited[j]){
                continue;
            }
            if (!dfs(j, -1)){
                cout << 1 << "\n";
                goto cnt;
            }
        }
        cout << 0 << "\n";
        
        cnt:;
    }
    return 0;
}
    
