#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long ns = n*n;
    int p;
    cin >> p;
    long long positions[p];
    for (int i=0; i<p;i++){
        positions[i] = -1;
    }
    int s;
    map<long long, long long> board;
    cin >> s;
    int a, b, c, d;
    long long x, y;
    for (int i=0;i<s;i++){
        cin >> a >> b >> c >> d;
        a--;
        b--;
        c--;
        d--;
        if (b%2 == 0){
            x = 1LL * n*b + a; 
        }
        else{
            x = 1LL*n*(b+1) - a-1;
        }
        if (d%2 == 0){
            y = 1LL*n*d + c; 
        }
        else{
            y = 1LL*n*(d+1) - c-1;
        }
        //cout << x << " " << y << "\n";
        board[x] = y;
    }
    int l;
    cin >> l;
    for (int i=0;i<l;i++){
        cin >> a >> b >> c >> d;
        a--;
        b--;
        c--;
        d--;
        if (b%2 == 0){
            x = 1LL*n*b + a; 
        }
        else{
            x = 1LL*n*(b+1) - a-1;
        }
        if (d%2 == 0){
            y = 1LL*n*d + c; 
        }
        else{
            y = 1LL*n*(d+1) - c-1;
        }
        //cout << x << " " << y << "\n";
        board[x] = y;
    }
    int k;
    cin >> k;
    int curr=0, skipped=0;
    while (k--){
        cin >> a >>b;
        //cout << "rolled " << a << " " << b << "\n";
        skipped = 0;
        while (positions[curr] >= ns){
            curr = (curr + 1) % p;
            if (skipped == p){
                goto done;
            }
            skipped++;
        }
        positions[curr] +=1LL*a+b;
        //cout << "pos " << positions[curr] << "\n";
        if (positions[curr] >=ns){
            curr = (curr + 1) % p;
            continue;
        }
        while(board.count(positions[curr]) > 0){
            positions[curr] = board[positions[curr]];
        }
        //cout << curr << " " << positions[curr] << "\n";
        curr= (curr + 1) % p;
    }
    done:;
    for (int i=0;i<p;i++){
        cout << i+1 << " ";
        if (positions[i] >= ns){
            cout << "winner\n";
        }
        else{
            a = positions[i]/n;
            b = positions[i] - (a*n);
            if (a%2 == 0){
                b = b+1;
            }
            else{
                b = n-b;
            }
            cout << b << " " << a + 1<< "\n";
        }
    }
}