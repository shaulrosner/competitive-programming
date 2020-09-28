#include <iostream>
#include <math.h>
#include <queue>
using namespace std;
#define INF 1000000000
float run[600][600];
float el[600][600];
float distancex[600][600];
int n, m;
priority_queue<pair<float, pair<int, int>>> q;
bool processed[600][600];
float dist(int a1, int b1, int a2, int b2){
    if (a2<0 || b2 <0 || a2>=n || b2 >=m){
        return INF;
    }
    return (run[a1][b1] + run[a2][b2])/2 * exp(3.5 * abs((el[a2][b2] - el[a1][b1])/10 + 0.05));
}
float dij(int a, int b, int p1, int p2){
    q = priority_queue<pair<float, pair<int, int>>>();
    for (int k=0;k<n;k++){
        for (int l=0;l<m;l++){
            processed[k][l] = false;
            distancex[k][l] = INF;
        }
        
    } 
    distancex[a][b] = 0;
    q.push({0.0, {a,b}});
    while(!q.empty()){
        pair<int, int> x = q.top().second; q.pop();
        
        float w;
        int i=x.first, j=x.second;
        if (processed[i][j]) continue;
        processed[i][j] = true;
        if (i == p1 && j == p2){
            return distancex[p1][p2];
        }
        w = dist(i, j, i-1, j);
        if (w!=INF){
            if (distancex[i][j] + w < distancex[i-1][j]){
                distancex[i-1][j] = distancex[i][j] + w;
                q.push({-distancex[i-1][j], {i-1, j}});
            }
        }
        w = dist(i, j, i+1, j);
        if (w!=INF){
            if (distancex[i][j] + w < distancex[i+1][j]){
                distancex[i+1][j] = distancex[i][j] + w;
                q.push({-distancex[i+1][j], {i+1, j}});
            }
        }
        w = dist(i, j, i, j-1);
        if (w!=INF){
            if (distancex[i][j] + w < distancex[i][j-1]){
                distancex[i][j-1] = distancex[i][j] + w;
                q.push({-distancex[i][j-1], {i, j-1}});
            }
        }
        w = dist(i, j, i, j+1);
        if (w!=INF){
            if (distancex[i][j] + w < distancex[i][j+1]){
                distancex[i][j+1] = distancex[i][j] + w;
                q.push({-distancex[i][j+1], {i, j+1}});
            }
        }
        //for (int k=0;k<n;k++){
         //   for (int l=0;l<m;l++){
          //      cout << distancex[k][l] << " ";
        //    }
         //   cout << "\n";
        //}
    }
}
int main() {
    int p, a, b, p1, p2;
    cin >> n >> m;
    cin >> p;
    cin >> a >> b;
    float total = 0, t;
    vector<pair<int, int>> ps;
    for (int i=0;i<p;i++){
        cin >> p1 >> p2;
        ps.push_back({p1, p2});
    }
    for (int i=0;i<n;i++){
        for (int j=0; j<m; j++){
            cin >> run[i][j];
        }   
    }
    for (int i=0;i<n;i++){
        for (int j=0; j<m; j++){
            cin >> el[i][j];
        }   
    }
    for (int i=0; i<p; i++){
        p1 =ps[i].first;
        p2 =ps[i].second;
        t= dij(a, b, p1, p2);
        total += t;
        a = p1;
        b = p2;
    }
    cout << ceil(total);
    return 0;
}