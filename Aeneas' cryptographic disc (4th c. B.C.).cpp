#include <iostream>
#include <map>
#include <math.h> 
#include <algorithm>
#define PI 3.14159265

using namespace std;

int main() {
    int d;
    double f, total=0, d1, d2, deg;
    char c;
    string s;
    cin >> d;
    map<char, double> m;
    for (int i=0; i<26; i++){
        cin >> c >> f;
        m[c] = f;
    }
    getline(cin, s);
    getline(cin, s);
    s.erase(remove_if(s.begin(), s.end(), [](char c) { return !isalpha(c); } ), s.end());
    transform(s.begin(), s.end(),s.begin(), ::toupper);
    total += d;
    for (int i=1; i<s.length(); i++){
        d1 = m[(char)s[i-1]];
        d2 = m[(char)s[i]];
        if (d1==d2){
            continue;
        }
        deg = min(abs(d1 - d2), min(d1, d2) + (double)360-max(d1, d2));
        total += sqrt((double)2*pow(d,2)*(1 - cos(((double)deg * PI)/180)));
        
    }
    cout << (long)ceil(total);
    return 0;
}