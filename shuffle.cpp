#include <iostream>
#include<vector>
using namespace std;
int adj[200][200];
int n, m;
bool seen[200];
int match[200];
bool bpm(int u) 
{ 
    for (int v=0; v<n;v++)
    { 
        if (!adj[u][v]) continue;
        if (!seen[v])
        { 
            seen[v] = true;  
            if (match[v] < 0 || bpm(match[v])) 
            { 
                match[v] = u; 
                return true; 
            }
        }
    }
    return false; 
}
  
int maxBPM() 
{ 
    for (int i=0;i<m;i++){
        match[i] = -1;
    }
  
    // Initially all jobs are available 
    int result = 0;  
    for (int u = 0; u < n; u++) 
    { 
        for (int i=0; i<n;i++){
            seen[i] = false;
        }
        if (bpm(u)) 
            result++; 
    }
    return result; 
}

  
int main() {
    int a;
    cin >> n;
    m=n;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            adj[i][j] = 1;
        }
        adj[i][i] = 0;
    }
    for (int i=0; i<n; i++){
        do{
            scanf("%d", &a);
            adj[i][a] = 0;
        }while(getchar() != 10);
    }
    
    cout << n - maxBPM();
    return 0;
}