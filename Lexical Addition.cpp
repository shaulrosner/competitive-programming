#include <iostream>
#include <algorithm>

using namespace std;
long long n, a, b;
int main() {
    
    cin >> n >> a >> b;
    long long missing = n%b;
    long long amount = n/b;
    long long am, diff;
    if (missing == 0){
        cout << "YES\n";
        while(amount--){
            cout << b << " ";
        }
    }
    else if (missing <a){
        if (b==a){
            cout << "NO\n";
            return 0;
        }
        am = (a - missing) / (b-a);
        diff = (a-missing) % (b-a);
        if (am > amount || (am == amount && diff >0) ){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
            cout << a << " ";
            for (int i=0; i<am; i++){
                cout << a << " ";
            }
            if (diff >0){
                cout << b - diff << " ";
                for (int i=0; i<amount-am-1;i++){
                    cout << b << " ";
                }
            }
            else{
                for (int i=0; i<amount-am;i++){
                    cout << b << " ";
                }
            }
        }
    }
    else{
        cout << "YES\n";
        cout << missing << " ";
        while(amount--){
            cout << b << " ";
        }
    }
    return 0;
}