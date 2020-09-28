#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int r, c, cell;
    cin >> r >> c;
    int arr[r][c], s[r][c];
   for (int i=0; i<r; i++){
       for (int j=0; j<c; j++){
           cin >> cell;
           arr[i][j] = cell;
       }
   }
   int mi = 1, ma = 50000000, cen, best, bval, lval;
   while(true){
       cen = (ma + mi) / 2;
       s[0][0] = cen;
       for (int j=1; j<c;j++){
           if (s[0][j-1] < 0){
               s[0][j] = -1;
           }
           else{
               s[0][j] = s[0][j-1] + arr[0][j];
           }
       }
       for (int i=1; i<r; i++){
       for (int j=0; j<c; j++){
           bval = s[i-1][j];
           if (j > 0 && s[i][j-1] > bval){
               bval = s[i][j-1];
           }
           if (bval > 0){
               s[i][j] = arr[i][j] + bval;
               if (s[i][j] <0){
                   s[i][j] = -1;
               }
           }
           else{
               s[i][j] = -1;
           }
       }
   }
   if (s[r-1][c-1] >0){
        ma = cen;
       
   }
   else{
      mi = cen + 1;
   }
   if (mi == ma){
       break;
   }
   }
    
    cout << mi;
    return 0;
}