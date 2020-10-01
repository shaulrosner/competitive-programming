#include <iostream>
#include <queue>
#include <list>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class LRUCache { 
    // store keys of cache 
    list<int> dq; 
  
    // store references of key in cache 
    unordered_map<int, list<int>::iterator> ma; 
    int csize; // maximum capacity of cache 
  
public: 
    LRUCache(int); 
    bool refer(int); 
}; 
  
// Declare the size 
LRUCache::LRUCache(int n) 
{ 
    csize = n; 
} 
  
// Refers key x with in the LRU cache 
bool LRUCache::refer(int x) 
{ 
    // not present in cache 
    bool erased = true;
    if (ma.find(x) == ma.end()) { 
        // cache is full 
        if (dq.size() == csize) { 
            // delete least recently used element 
            int last = dq.back(); 
  
            // Pops the last elmeent 
            dq.pop_back(); 
  
            // Erase the last 
            ma.erase(last); 
            erased = false;
        } 
    } 
  
    // present in cache 
    else
        dq.erase(ma[x]); 
  
    // update reference 
    dq.push_front(x); 
    ma[x] = dq.begin(); 
    return erased;
} 
  
int main() {
    int t;
    int p, s, n;
    int add, page, npage;
    cin >> t;
    while (t--){
        int fc=0, lc=0;
        queue<int> fifoqueue;
        unordered_set<int> used;
        cin >> p >> s >> n;
        LRUCache lru(p);
        while (n--){
            cin >> add;
            page = add/s;
            if (used.count(page) == 0){
                fifoqueue.push(page);
                used.insert(page);
                if (used.size() > p){
                    npage = fifoqueue.front();
                    fifoqueue.pop();
                    used.erase(npage);
                    fc += 1;
                }
            }
            if (!lru.refer(page)){
                lc ++;
            }
        }
        if (fc > lc){
            cout << "yes ";
        }
        else{
            cout << "no ";
        }
        cout << fc << " " << lc << "\n";
    }
}