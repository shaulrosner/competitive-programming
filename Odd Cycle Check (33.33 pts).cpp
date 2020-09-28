#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// functions used to comunicate with the interactor (the other program)
// use this to get the position of the other player.
// after using it you must do your own move
// TL;DR GetEdge() GetEdge() is invalid
pair<int, int> GetEdge() {
    int a, b; 
    cin >> a >> b;
    return {a, b};
}

// use this to set your answer
void SetAnswer(int s) {
    cout << s << endl;
    if (s == 0) {
        exit(0);
    }
}

int main() {
    // use this to pass the first example
    int n, a, b; 
    cin >> n;
    bool evens[n][n];
    bool odds[n][n];
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            evens[i][j] = false;
            odds[i][j] = false;
        }
        evens[i][i] = true;
    }
    pair<int, int> p;
    while(true){
        p = GetEdge();
        a = p.first-1;
        b = p.second-1;
        for (int i=0;i<n;i++){
            for (int j=0; j<n;j++){
                    if ((evens[i][a] && odds[b][j]) || 
                    (odds[i][a] && evens[b][j]) ||
                    (evens[i][b] && odds[a][j]) ||
                    (odds[i][b] && evens[a][j])
                    ){
                        evens[i][j] = true;
                         evens[j][i] = true;
                    }  
                    if ((odds[i][a] && odds[b][j]) ||
                    (evens[i][a] && evens[b][j]) ||
                    (evens[i][b] && evens[a][j]) ||
                    (odds[i][b] && odds[a][j])
                    ){
                        odds[i][j] = true;
                        odds[j][i] = true;
                    }   
            }
        }
        for (int i=0;i<n;i++){
            if (odds[i][i]){
                SetAnswer(0);
                return 0;
            }
        }
        SetAnswer(1);
    }
    
    return 0;
}
