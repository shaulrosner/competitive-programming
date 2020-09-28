#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <queue>
using namespace std;
int n;
vector<int> adj[20];
int dists[7][20];
bool used[7] = {false};
int rec(int d1, int d2, int prev1, int prev2){
    int best = 0;
    int worst = 8;
    for (int i=0;i<7;i++){
        if (used[i]){
            continue;
        }
        if (d1 + dists[i][prev1] <= d2 + dists[i][prev2]){
            used[i] = true;
            best = max(best, 1 + rec(d1 + dists[i][prev1], d2, n-i- 1, prev2));
            used[i] = false;
        }
        else{
            used[i] = true;
            worst = min(worst, rec(d1, d2 + dists[i][prev2], prev1, n-i-1));
            used[i] = false;
        }
    }
    if (worst==8){
        worst = 0;
    }
    return max(best, worst);
}
int main() {
    int k;
    cin >> n;
    string s;
    getline(cin, s);
    for (int i=0; i<n;i++){
        getline(cin, s);
        stringstream stream(s);
        while(1) {
            stream >> k;
            if(!stream)
                break;
                adj[k].push_back(i);
        }
    }
    for (int i=0; i<7; i++){
        queue<int> q;
        bool visited[n] = {false};
        visited[n-i-1] = true;
        dists[i][n-i-1] = 0;
        q.push(n-i-1);
        while (!q.empty()){
            int st = q.front(); q.pop();
            for (auto u:adj[st]){
                if (visited[u]){
                    continue;
                } 
                visited[u] = true;
                dists[i][u] = dists[i][st] + 1;
                q.push(u);
            }
        }
    }

    
    cout << rec(0, 0, 0, 0);
}