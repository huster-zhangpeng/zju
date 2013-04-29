#include <iostream>
#include <stdio.h>
//#define LOCAL

using namespace std;

typedef struct square{
    int left, top, right, bottom;
}Square;
Square squares[25];
int result[5][5];
int count[25];
int top;
int N;

bool search(int cur){
    if(cur == N * N) return true;
    int p, q;
    p = cur / N;
    q = cur % N;
    for(int i = 0; i < top; i++)if(count[i] > 0){
        if(p && squares[ result[p-1][q] ].bottom != squares[i].top) continue;
        if(q && squares[ result[p][q-1] ].right != squares[i].left) continue;
        result[p][q] = i;
        count[i] --;
        if(search(cur + 1)) return true;
        count[i] ++;
    }
    return false;
}

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    int i, j, T = 0;
    Square s;
    while(cin>>N && N){
        top = 0;
        for(i = 0; i < N * N; i++){
            cin>>s.top>>s.right>>s.bottom>>s.left;
            for(j = 0; j < top; j++){
                if(s.top == squares[j].top && s.right == squares[j].right
                   && s.bottom == squares[j].bottom && s.left == squares[j].left){
                    count[j]++; break;
                }
            }
            if(j == top){
                squares[top] = s;
                count[top] = 1;
                top++;
            }
        }
        if(T) cout<<"\n";
        if(search(0)){
            cout<<"Game "<<T+1<<": Possible"<<endl;
        }else{
            cout<<"Game "<<T+1<<": Impossible"<<endl;
        }
        T++;
    }
    return 0;
}
