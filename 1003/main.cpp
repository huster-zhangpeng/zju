/*
*深度优先搜索
*其中，smallWasValid是记录小的那个数是否可以合法的标志位
*/
#include <iostream>

using namespace std;

bool smallWasValid;

bool challenge(int small, int big, int n){
    int i;
    for(i = n; i > 1; i--){
        if(small % i == 0){
            if(challenge(small / i, big, i - 1))
                return true;
        }
        if(big % i == 0){
            if(challenge(small, big / i, i - 1))
                return true;
        }
    }
    if(small == 1){
        smallWasValid = true;
        if(big == 1) return true;
        else return false;
    } else {
        return !smallWasValid;
    }
}

int main(){
    int a, b;
    int min, max;
    while(cin>>a>>b){
        min = (a < b) ? a : b;
        max = (a > b) ? a : b;
        smallWasValid = false;
        if(challenge(min, max, 100)){
            cout<<max<<endl;
        } else {
            cout<<min<<endl;
        }
    }
    return 0;
}
