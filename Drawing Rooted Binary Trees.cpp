#include <iostream>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
map <int, int> infixmap;
map <int, int> prefixmap;
int x[30];
int y[30];

int parent[30];
int main() {
    string infix, prefix;
    while (getline(cin, infix)){
    getline(cin, prefix);
    infix.erase(remove_if(infix.begin(), infix.end(), [](char c) { return !isalpha(c); } ), infix.end());
    prefix.erase(remove_if(prefix.begin(), prefix.end(), [](char c) { return !isalpha(c); } ), prefix.end());
    int n = infix.size();
    int curr = 0;
    for (int i=0; i<n; i++){
        infixmap[infix[i]-'a'] = curr;
        prefixmap[prefix[i]-'a'] = curr;
        curr ++;
    }
    stack<int> s;
    stack<int> str;
    bool dirleft;
    y[prefix[0] - 'a'] = 0;
    curr = prefix[0] - 'a';
    for (int i=1; i<n;i++){
        //cout << curr << " " << y[curr] << "\n";
        if (infixmap[prefix[i] - 'a']<infixmap[curr]){
            //cout << "l\n";
            y[prefix[i] - 'a'] = 1 + y[curr];
            s.push(curr);
            curr = prefix[i] - 'a';
        }
        else{
            while (!s.empty()){
                //cout << "loop\n";
                if (infixmap[prefix[i] - 'a'] < infixmap[s.top()]){
                    //cout << "loop break\n";
                    y[prefix[i] - 'a'] = 1 + y[curr];
                    while (!str.empty()){
                        str.pop();
                    }
                    s.push(curr);
                    curr = prefix[i] - 'a';
                    goto nxt;
                }
                else{
                    str.push(curr);
                    curr = s.top();
                    s.pop();
                }
            }
            //cout << curr << "\n";
            while(!str.empty()){
                //cout << "emptied\n";
                if (infixmap[str.top()]> infixmap[curr]){
                curr = str.top();
                }
                str.pop();
            }
            //cout <<"final\n";
                y[prefix[i] - 'a'] = 1 + y[curr];
                s.push(curr);
                curr = prefix[i] - 'a';
                nxt:;
        }
    }
    for (int i=0; i<n;i++){
        x[infix[i] - 'a'] = i;
    }
    // for (int i=0; i<n;i++){
    //     cout << x[i] << " ";
    // }
    // cout << "\n";
    //     for (int i=0; i<n;i++){
    //     cout << y[i] << " ";
    // }
    // cout << "\n";
    curr = 0;
    bool p=false;
    for (int i=0; i<n;i++){
        curr = 0;
        p = false;
        for (int j=0;j<n;j++){
            if (y[infix[j]- 'a'] == i){
                while (curr < x[infix[j]- 'a']){
                    cout << " ";
                    curr ++;
                }
                cout << infix[j];
                p = true;
                curr ++ ;
            }
        }
        if (p){
        cout << "\n";
        }
    }
    }
    return 0;
}