#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int parent[100000];
int depth[100000];
int val[100000];
    vector<int> adj[100000];
    bool visited[100000];
queue<int> q;
int main() {
    ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    int a, b;
    for (int i=0;i<n;i++){
        visited[i] = false;
        val[i] = 0;
        parent[i] = -1;
    }
    for (int i=0;i<n-1;i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int s;
    visited[0] = true;
    parent[0] = -1;
    depth[0] = 0;
    q.push(0);
    while (!q.empty()){
        s = q.front();
        q.pop();
        for (auto u:adj[s]){
            if (!visited[u]){
                parent[u] = s;
                depth[u] = depth[s] + 1;
                visited[u] = true;
                q.push(u);
            }
        }
    }
    int k;
    while(m--){
        cin >> a >> b >>k;
        while (a!=b){
            if (b==-1 || depth[a] > depth[b]){
                val[a] += k;
                a = parent[a];
            }
            else{
                val[b] += k;
                b = parent[b];
            }
        }
        if (a!= -1){
            val[a] += k;
        }
    }
    int best = -1;
    for (int i=0;i<n;i++){
        if (val[i] > best){
            best = val[i];
        }
    }
    cout << best << endl;
    return 0;
}