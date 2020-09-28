#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

double dist(double x, double y, int a, int b){
    double ans =  sqrt((x-a)*(x-a) + (y-b)*(y-b));
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, t, x1, y1, x2, y2, r;
    cin >> t;
    vector<int> el;
    for (int i=0; i<t;i++){
        cin >> n;
        for (int j=0;j<n;j++){
            cin >> x1 >> y1 >> x2 >> y2 >> r;
            el.push_back(x1);
            el.push_back(y1);
            el.push_back(x2);
            el.push_back(y2);
            el.push_back(r);
        }
        long long ins = 0;
        for (double x=-50; x<=50; x+= 0.1){
            for (double y=-50; y<=50; y += 0.1){
                for(unsigned long long j=0; j<el.size(); j+=5){
                   // cout << dist(x, y, el[j/5], el[j/5 + 1]) + dist(x, y, el[j/5+2], el[j/5 + 3]) << " ";
                   // cout << j << " ";
                   // cout << j/5 + 4 << " ";
                    //cout << el[j/5 + 4] << "\n";
                    if (dist(x, y, el[j], el[j + 1]) + dist(x, y, el[j+2], el[j + 3]) <= el[j + 4]){
                        ins += 1;
                        break;
                    }
                }
            }
            
        }
        el.clear();
        cout << (long)round((double)(1000000 - ins)/10000) << "%\n";
    }
    return 0;
}
