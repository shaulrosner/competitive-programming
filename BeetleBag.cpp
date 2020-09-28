#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t, c, n, w, f, v;
    cin >> t;
    while (t--){
        cin >> c >> n;
        int mat [n+1][c+1] = {};
        for (int i=1; i<= n; i++){
            cin >> w >> f;
            for (int j=1; j<= c; j++){
                v=0;
                if (j >= w){
                    v = f + mat[i-1][j - w];
                }
                mat[i][j] = max(v, mat[i-1][j]);
            }
        }
        cout << mat[n][c] << "\n";
        
    }
    return 0;
}