#include <iostream>

using namespace std;

int main() {
    int n, cb, cp;
    cin >> n>>cb>>cp;
    int tb=0, tp=0;
    int c1, c2;
    for (int i=0;i<n;i++){
        cin >> c1 >> c2;
        tb += c1;
        tp += c2;
    }
    cout << ((tb+9)/10)*cb + ((tp+9)/10)*cp;
}