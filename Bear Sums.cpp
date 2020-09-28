#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int t;
    long s, e;
    cin >> t;
    for (int i=0;i<t;i++){
        cin >> s >> e;
        int arr[e];
        for (int j=0; j<e; j++){
            cin >> arr[j];
        }
            for (int l=1; l<e; l++){
                for (int k=0;k<l;k++){
                    if (arr[k] + arr[l] == s){
                        cout << min(arr[k], arr[l]) << " " << max(arr[k], arr[l]) << "\n";
                        goto cnt;
                    }
                }
            }
        cout << "!OK\n";
        cnt:;
    }
    return 0;
}