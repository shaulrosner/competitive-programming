#include <iostream>

using namespace std;

int main() {
    int t;
    int n;
    cin >> t;
    int a;
    int ord[20][501];
    int l[5001];
    while(t--){
        cin >> n;
        int counter[20];
        for (int i=0;i<20;i++){
            counter[i] = 0;
        }
        int changes = 0;
        int b[2]={-1, -1};
        for (int i=0;i<n;i++){
            cin >> a;
            a --;
            l[i] = a;
            ord[a][counter[a]] = i;
            counter[a]++;
        }
        int ncounter[20];
        for (int i=0;i<20;i++){
            ncounter[i] = -1;
        }
        for (int i=0;i<n;i++){
            ncounter[l[i]] ++;
            if (b[0] != l[i] && b[1] != l[i]){
                changes++;
                if (b[0] == -1){
                    b[0] = l[i];
                }
                else if(b[1] == -1){
                    b[1] = l[i];
                }
                else if(ncounter[b[0]] + 1 == counter[b[0]]){
                    b[0] = l[i];
                }
                else if (ncounter[b[1]] + 1== counter[b[1]]){
                    b[1] = l[i];
                }
                else if (ord[b[0]][ncounter[b[0]]+1] > ord[b[1]][ncounter[b[1]]+1]){
                    b[0] = l[i];
                }
                else{
                    b[1] = l[i];
                }
            }
        }
        cout << changes << "\n";
        
    }
}