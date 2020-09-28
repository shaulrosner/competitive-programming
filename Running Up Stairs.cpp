#include <iostream>

using namespace std;

int main() {
    int t, n;
    unsigned long long count1, count2, temp;
    cin >> t;
    for (int i=0;i<t;i++){
        cin >> n;
        count1 =0;
        count2 = 1;
        for (int j=0;j<n;j++){
            temp = count2;
            count2 = count1 + count2;
            count1 = temp;
        }
        cout << count2;
        cout << "\n";
    }
    return 0;
}