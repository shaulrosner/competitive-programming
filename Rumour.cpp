#include <iostream>

using namespace std;

int main() {
    int q, ca, cb;
    long long  a, b;
    cin >> q;
    for (int i=0;i<q;i++){
        cin >> a >> b;
        ca = 0;
        cb = 0;
        while (a != b){
            if (a>b){
               ca += 1; 
               a = a >> 1;
            }
            else{
                cb += 1;
                b = b>>1;
            }
        }
        cout << ca + cb << "\n";
    }
    
    return 0;
}