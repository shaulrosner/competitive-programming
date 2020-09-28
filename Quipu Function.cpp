#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int main() {
    int t;
    long long a, b, d;
    cin >> t >> a >> b;
    for(int i=0; i<t; i++){
        cin >> d;
        long long sqrb = sqrt(b);
        long long total = 0;
        for (long long i=1; i<=sqrb;i++){
            for (long long j =max(i, (long long)ceil(a/i)); j*i <= b; j++){
                if (i*j < a){
                    continue;
                }
                if (i % d !=0){
                    total ++;
                }
                if (j!=i && j%d != 0){
                    total ++;
                }
            }
        }
        cout << total << "\n";
    }
    return 0;
}