#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
vector<pair<int, pair<int, int>>> edges;
int usize[100000];
int link[100000];
int find(int x){
    while (x != link[x]) x = link[x];
    return x;
}
bool same(int a, int b){
    return find(a) == find(b);
}
void unite(int a, int b){
    a = find(a);
    b = find(b);
    if (usize[a] < usize[b]) swap(a, b);
    usize[a] += usize[b];
    link[b] = a;
}
bool visited[100000];
int disc[100000];
int low[100000];
int parent[100000];
int n, m;
int currtime;
int bridges;
void dfs(int u, vector<int> new_edges[]){
    visited[u] = true;
    disc[u] = low[u] = ++currtime;
    for (auto v: new_edges[u]){
        if (!visited[v]){
            parent[v] = u;
            dfs(v, new_edges);
            low[u] = min(low[u], low[v]);
            if (low[v] > disc[u]){
                if (count(new_edges[u].begin(), new_edges[u].end(), v) <=1){
                    bridges += 1;
                }
            }
        }
        else if (v != parent[u]){
            low[u] = min(low[u], disc[v]);
        }
    }
}
int get_crit(vector<pair<int, pair<int, int>>> edge_list){
    if (edge_list.size() == 0){
        return 0;
    }
    currtime = 0;
    bridges = 0;

    int a, b;
    vector<pair<int, int>> added;
    vector<int> new_edges[n];
    set<int> act;
    for (auto edg:edge_list){
        a = edg.second.first;
        b = edg.second.second;
        if (same(a,b)){
            continue;
        }
        a = find(a);
        b = find(b);
        new_edges[a].push_back(b);
        new_edges[b].push_back(a);
        act.insert(a);
        act.insert(b);
    }
    if (act.size() == 0){
        return 0;
    }
    for (auto i:act){
        visited[i] = false;
        disc[i] = 0;
        low[i] = 0;
        parent[i] = -1;
    }
    for (auto i: act){
        if (!visited[i]){
            dfs(i, new_edges);
        }   
    }
    for (auto edg:edge_list){
        a = edg.second.first;
        b = edg.second.second;
        if (!same(a, b)){
            unite(a, b);
        }
    }
    return bridges;
}

int main() {
    int a, b, c;
    cin >> n >> m;
    for (int i=0; i<m;i++){
        cin >> a >> b >> c;
        edges.push_back({c, {a, b}});
    }
    sort(edges.begin(), edges.end()); 
    for (int i=0;i<n;i++){
        link[i] = i;
        usize[i] = 1;
    }
    int curr_cost = -1, total = 0;
    vector<pair<int, pair<int, int>>> edge_list;
    for (int i=0; i<m; i++){
        if (edges[i].first != curr_cost){
            curr_cost = edges[i].first;
            total += get_crit(edge_list);
            edge_list.clear();
            
        }
        edge_list.push_back(edges[i]);
    }
    total += get_crit(edge_list);
    cout << total;
    return 0;
}