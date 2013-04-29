/*
* ZOJ-1029
* 贪心法可解，与1025有类似之处
*/
#include <iostream>
#include <stdio.h>
#include <algorithm>
#define LOCAL

using namespace std;

typedef struct trans{
    int from, to;
}Trans;

Trans trans[200];
bool wasMoved[200];
int N;

bool cmp(const Trans& t1, const Trans& t2){
    if(t1.from == t2.from){
        return t1.to < t2.to;
    }
    return t1.from < t2.from;
}

void solve(){
    int sum = 0, count = 0, i, last;
    while(count < N){
        i = 0;
        while(wasMoved[i]) i++;
        last = trans[i].to;
        wasMoved[i] = true;
        count++;
        sum++;
        for(++i; i < N; i++) if(!wasMoved[i] && last < trans[i].from){
            wasMoved[i] = true;
            last = trans[i].to;
            count++;
        }
    }
    cout<<sum*10<<endl;
}

int main(){
    int T, i, tmp;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    cin>>T;
    while(T--){
        cin>>N;
        for(i = 0; i < N; i++){
            cin>>tmp;
            trans[i].from = (tmp + 1) / 2;
            cin>>tmp;
            trans[i].to = (tmp + 1) / 2;
            if(trans[i].from > trans[i].to){
                tmp = trans[i].from;
                trans[i].from = trans[i].to;
                trans[i].to = tmp;
            }
            wasMoved[i] = false;
        }
        sort(trans, trans + N, cmp);
        solve();
    }
    return 0;
}
