#include <iostream>

using namespace std;
int myPow(int x, int p)
{
  if (p == 0) return 1;
  if (p == 1) return x;

  int tmp = myPow(x, p/2);
  if (p%2 == 0) return tmp * tmp;
  else return x * tmp * tmp;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, b;
    long long x;
    cin >> t;
    int count, item_ind, rem;
    long long prod;
    char c;
    for (int i=0; i<t; i++){
        cin >> b >> x;
        count = 1;
        prod = b;
        while (x > prod*count){
            x -= prod*count;
            prod = prod * b;
            count += 1;
        }
        item_ind = x / count;
        rem = x%count;
        c = 'a' + ((item_ind / myPow(b, count-1-rem))%b);
        cout << c << "\n";
    }
    return 0;
}