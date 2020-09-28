#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
vector<int> adj[100000];
bool looping[100000];
bool visited[100000];
bool active[100000];
int starts[100000];
int c = 0;
stack<int> st;
void dfs(int s, int prev){
    starts[s] = c;
    c+= 1;
    if (visited[s]){
        return;
    }
    st.push(s);
    active[s] = true;
    visited[s] = true;
    for (auto u:adj[s]){
        if (u==prev){
            continue;
        }
        if (active[u]){
            int v=-1;
            while (!st.empty()){
                v = st.top();
                st.pop();
                if (starts[v]<starts[u]){
                    st.push(v);
                    break;
                }
                looping[v] = true;
            }
            
        }
        else{
            dfs(u, s);
        }
    }
    
    active[s] = false;
    if (!st.empty() && st.top() == s){
        st.pop();
    }
}
int main() {
    int n, m, a,b;
    cin >> n >> m;
    
    for (int i=0;i<m;i++){
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    for (int i=0;i<n;i++){
        looping[i] = false;
        visited[i] = false;
        active[i] = false;
    }
    for (int i=0;i<n;i++){
        if (visited[i]){
            continue;
        }
        dfs(i, -1);
    }
    for (int i=0; i<n; i++){
        if (!looping[i]){
            cout << i+ 1 << "\n";
        }
    }
    return 0;
}