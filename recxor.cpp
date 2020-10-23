#include <iostream>

using namespace std;
long long cxor(long long a) 
{ 

    if (a% 4 == 0) return a;
    if (a%4 == 1) return 1;
    if (a%4 == 2) return a+1;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long t, l, h, n, d1, d2;
    long long x, y;
    cin >> t;
    while(t--){
        cin >> l >> h >> n >> d1 >> d2;
        long long res = cxor(n-1)^cxor(n+l*h-1LL);
        if ((d1 - n) % l <= (d2 - n)%l){
            x = d1;
            y = d1 + (((d2 - d1) % l) + l) % l;
        }
        else{
            long long v = (((d1 - d2) % l + l) % l);
            x = d1 - v;
            y = d1;
            d2 += v;
        }
        while (y <= d2){
            res = res ^ cxor(x - 1LL) ^ cxor(y);
            //cout << x-1 << " " << y << "\n";
            y += l;
            x += l;
        }
        cout << res << "\n";
    }
}