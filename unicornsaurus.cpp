#include <iostream>
#include <bits/stdc++.h> 
#include <algorithm>
using namespace std; 
#define INF 1000000000000000000LL
struct SEG {

    long long n,sz;

    vector<long long> a;

    SEG(long long _n){

        n=_n;

        for(sz=1;sz<n;sz<<=1);

        a.resize(sz*2,0);

    }

    void update(long long i, long long val){

        i+=sz;

        a[i] = val;

        for(i>>=1;i;i>>=1){

            a[i] = min(a[i*2], a[i*2+1]);

        }

    }

    int query(int l, int r){

        long long ans=INF;

        for(l+=sz,r+=sz;l<=r;l>>=1,r>>=1){

            if (l%2){
                ans = min(ans, a[l++]);
            } 

            if (r%2==0) {
                ans = min(ans, a[r--]);
            }
            if (l>r) break;
        }

        return ans;

    }

};
bool needed[100001];
int main() 
{ 
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);
	int n,m,s;
		cin >> n >> m >> s;
	for (int i=0;i<s+1;i++){
	    needed[i] = false;
	}
	int l, r;
	while (n--){
	    cin >> l >> r;
	    for (int i=l;i<=r;i++){
	        needed[i] = true;
	    }
	}
	vector<pair<int, pair<int, int>>> powers;
    int a, b, c;
	for(int i=0;i<m;i++){
	    cin >> a >> b >> c;
	    powers.push_back({b, {a, c}});
	}
	sort(powers.begin(), powers.end());
	long long dp[s+1];
	for (int i=0;i<s+1;i++){
	    dp[i] = INF;
	}
	dp[0] = 0LL;
	SEG tree(s+1);
	int last = 1;
	for (int i=0;i<m;i++){
	    int e = powers[i].first;
	    while (last<e){
	        if (!needed[last]){
	            dp[last] = min(dp[last], dp[last-1]);
	        }
	        tree.update(last, dp[last]);
	        last ++;
	    }
	    dp[e] = 1LL*min(dp[e], powers[i].second.second +1LL* tree.query(powers[i].second.first - 1, e-1));
	}
   while(last<=s) {

        if(!needed[last]) {
            dp[last] = 1LL*min(dp[last], dp[last-1]);
        };

        tree.update(last, dp[last]);

        last++;

    }
	if (dp[s] == INF) {
	    cout << -1 << endl;
	}
	else{
	    cout <<1LL*dp[s] << endl;
	}
	return 0; 
} 
