#include <iostream>

using namespace std;
bool arr[100][100];
int root[10000];
int coun[10000];
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
    if (a==b){
        return;
    }
    if (coun[a] < coun[b]) swap(a,b);
    coun[a] += coun[b];
    root[b] = a;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i=0; i<n;i++){
        for (int j=0; j<m-(i%2); j++){
            root[100*i + j] = 100*i + j;
            coun[100*i + j] = 6;
        }
    }
    int inp;
    for (int i=0; i<n;i++){
        for (int j=0; j<m-(i%2); j++){
            cin >> inp;
            arr[i][j] = false;
            if (inp == 1){
                arr[i][j] = true;
            }
        }
    }
    for (int i=0; i<n;i++){
        for (int j=0; j<m - (i%2);j++){
            if (arr[i][j]){
                if (j< m - 1 - (i%2) && arr[i][j+1]){
                    unite(100*i + j, 100*i + j + 1);
                    if (same(100*i + j, 100*i + j + 1)){
                        coun[find(100*i + j)] -= 2;
                    }
                }
                if (i < n-1){
                    if ((i%2 == 1 || j<m-1) && arr[i+1][j]){
                        unite(100*i + j, 100*i + 100 + j);
                        if (same(100*i + j, 100*i + 100 + j)){
                        coun[find(100*i + j)] -= 2;
                    }
                    }
                    if (i%2 == 0 && j > 0 && arr[i+1][j-1]){
                        unite(100*i +j, 100*i + 100 + j - 1);
                        if (same(100*i + j, 100*i + 100 + j - 1)){
                        coun[find(100*i + j)] -= 2;
                    }
                    }
                    else if (i%2 == 1 && j < m - 1 && arr[i+1][j+1]){
                        unite(100*i +j, 100*i + 100 + j + 1);
                        if (same(100*i + j, 100*i + 100 + j + 1)){
                        coun[find(100*i + j)] -= 2;
                    }
                    }
                }
            }
        }
    }
    // for (int i=0; i<n; i++){
    //     for (int j=0; j<m - i%2; j++){
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // for (int i=0; i<n; i++){
    //     for (int j=0; j<m - i%2; j++){
    //         cout << coun[100*i + j] << " ";
    //     }
    //     cout << "\n";
    // }
    int q;
    cin >> q;
    char c;
    int a, b;
    int share = 0;
    while (q--){
        cin >> c >> a >> b;
        a--;
        b--;
        if (c=='a'){
            arr[a][b] = true;
                if (b< m - 1 - (a%2) && arr[a][b+1]){
                    unite(100*a + b, 100*a + b + 1);
                    if (same(100*a + b, 100*a + b + 1)){
                        coun[find(100*a + b)] -= 2;
                    }
                }
                if (b> 0 && arr[a][b-1]){
                    unite(100*a + b, 100*a + b - 1);
                    if (same(100*a + b, 100*a + b - 1)){
                        coun[find(100*a + b)] -= 2;
                    }
                }
                if (a < n-1){
                    if ((a%2 == 1 || b<m-1) && arr[a+1][b]){
                        unite(100*a + b, 100*a + 100 + b);
                        if (same(100*a + b, 100*a + 100 + b)){
                        coun[find(100*a + b)] -= 2;
                    }
                    }
                    if (a%2 == 0 && b > 0 && arr[a+1][b-1]){
                        unite(100*a +b, 100*a + 100 + b - 1);
                        if (same(100*a + b, 100*a + 100 + b - 1)){
                        coun[find(100*a + b)] -= 2;
                    }
                    }
                    else if (a%2 == 1 && b < m - 1 && arr[a+1][b+1]){
                        unite(100*a +b, 100*a + 100 + b + 1);
                        if (same(100*a + b, 100*a + 100 + b + 1)){
                        coun[find(100*a + b)] -= 2;
                    }
                    }
                }
                if (a>0){
                    if ((a%2 == 1 || b<m-1) && arr[a-1][b]){
                        unite(100*a + b, 100*a - 100 + b);
                        if (same(100*a + b, 100*a - 100 + b)){
                        coun[find(100*a + b)] -= 2;
                    }
                    }
                    if (a%2 == 0 && b > 0 && arr[a-1][b-1]){
                        unite(100*a +b, 100*a - 100 + b - 1);
                        if (same(100*a + b, 100*a - 100 + b - 1)){
                        coun[find(100*a + b)] -= 2;
                    }
                    }
                    else if (a%2 == 1 && b < m - 1 && arr[a-1][b+1]){
                        unite(100*a +b, 100*a - 100 + b + 1);
                        if (same(100*a + b, 100*a - 100 + b + 1)){
                        coun[find(100*a + b)] -= 2;
                    }
                    }
                }
        }
        else{
            if (arr[a][b]){
            cout << coun[find(100*a + b)] << "\n";
            }
            else{
                cout << 0 << "\n";
            }
        }
    }
    return 0;
}