#include <iostream>
#include <stdio.h>
#define LOCAL

using namespace std;

int main(){
    int s, p, y, j, d = 12;
    int sAge, pAge, yAge;
    int temp;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    while(cin>>s>>p>>y>>j){
        temp = (d+j-y-p) % 3;
        yAge = (d+j-y-p) / 3;
        if(y == s + p){
            if(temp == 2){
                sAge = y + 1 + yAge;
                pAge = p + 1 + yAge;
            }else if(temp == 1){
                sAge = y + 1 + yAge;
                pAge = p + yAge;
            }else{
                sAge = y + yAge;
                pAge = p + yAge;
            }
        }else if(y == s + p + 1){
            if(temp == 2){
                sAge = y + 1 + yAge;
                pAge = p + 1 + yAge;
            }else if(temp == 1){
                sAge = y + yAge;
                pAge = p + 1 + yAge;
            }else{
                sAge = y + yAge;
                pAge = p + yAge;
            }
        }else if(y == s + p + 2){
            sAge = y + yAge;
            pAge = p + 1 + yAge;
        }else if(y + 1 == s + p){
            sAge = y + 1 + yAge;
            pAge = p + yAge;
        }
        cout<<sAge<<' '<<pAge<<' '<<yAge<<endl;
    }
    return 0;
}
