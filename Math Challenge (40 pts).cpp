#include <iostream>
using namespace std;
// Returns factorial of n 
#define m 1000000007LLU
unsigned long long fac[1000001];
unsigned long long power(unsigned long long a, unsigned long long b, unsigned long long p) 
{ 
    unsigned long long res = 1LLU;
  
    a= a % p; 
  
    while (b > 0) { 
        if (b & 1) 
            res = (res * a) % p; 
        b = b >> 1;
        a = (a * a) % p; 
    } 
    return res; 
} 
unsigned long long modinv(unsigned long long n, unsigned long long p) 
{ 
    return power(n, p - 2, p); 
}
unsigned long long ncrmodp(unsigned long long n, unsigned long long k, unsigned long long p){
    if (k==0){
        return 1;
    }
    
    return (((fac[n]*modinv(fac[k], p)) % p) * (modinv(fac[n-k], p) % p)) % p;
}


int main() {
    unsigned long long a, b, c;
    unsigned long long t;
    unsigned long long n;
    cin >> t;
    fac[0] = 1;
    for (unsigned long long i=1; i<=1000000;i++){
        fac[i] = (fac[i-1] * i) % (m);
    }

    for (unsigned long long i=0;i<t; i++){
        cin >> a >> b >> c;
        n = ncrmodp(b, c, m);
        cout << power(a, n, m) << "\n";
    }
    return 0;
}