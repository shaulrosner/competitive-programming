#include <iostream>
#include <string>
using namespace std;
int n, m;
bool done[1000][1000];
bool chart[1000][1000];
void reset(){
    for (int i=0; i<n; i++){
            for (int j=0;j<m;j++){
                done[i][j]=chart[i][j];
            }
        }
}
void dfs_plus(int a, int b){
    if (a<0 || b < 0 || a >= n || b >=m){
        return;
    }
    if (done[a][b]){
        return;
    }
    done[a][b] = true;
    dfs_plus(a-1,b);
    dfs_plus(a+1, b);
    dfs_plus(a, b-1);
    dfs_plus(a,b + 1);
}
void dfs_x(int a, int b){
    if (a<0 || b < 0 || a >= n || b >=m){
        return;
    }
    if (done[a][b]){
        return;
    }
    done[a][b] = true;
    dfs_x(a-1,b-1);
    dfs_x(a+1, b+1);
    dfs_x(a+1, b-1);
    dfs_x(a-1,b + 1);
}
void dfs_all(int a, int b){
    if (a<0 || b < 0 || a >= n || b >=m){
        return;
    }
    if (done[a][b]){
        return;
    }
    done[a][b] = true;
    dfs_all(a-1,b);
    dfs_all(a+1, b);
    dfs_all(a, b-1);
    dfs_all(a,b + 1);
    dfs_all(a-1,b-1);
    dfs_all(a+1, b+1);
    dfs_all(a+1, b-1);
    dfs_all(a-1,b + 1);
}
int main() {
    int t;
    string s;
    cin >> t;
    while (t--){
        cin >> m >> n;
        for (int i=0;i<n;i++){
            cin >> s;
            for (int j=0;j<m;j++){
                if (s[j] == '0'){
                    chart[i][j] = true;
                }
                else{
                    chart[i][j] = false;
                }
            }
        }
        reset();
        int c1=0,c2=0,c3=0;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (done[i][j]){
                    continue;
                }
                c1+=1;
                dfs_plus(i, j);
            }
        }
        reset();
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (done[i][j]){
                    continue;
                }
                c2+=1;
                dfs_x(i, j);
            }
        }
        reset();
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (done[i][j]){
                    continue;
                }
                c3+=1;
                dfs_all(i, j);
            }
        }
        cout << c1 << " " << c2 << " " << c3 << "\n";
        
    }
    return 0;
}