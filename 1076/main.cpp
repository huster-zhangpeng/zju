#include <iostream>
#include <algorithm>
#include <stdio.h>
#define LOCAL

using namespace std;

typedef struct _Exon{
    int start, end, pos;
}Exon;
Exon exon[1000];
int length[1000];
int parent[1000];

int N;

bool cmp(const Exon& e1, const Exon& e2){
    if(e1.start == e2.start)
        return e1.end < e2.end;
    return e1.start < e2.start;
}

void printPos(int i){
    if(i == -1) return;
    printPos(parent[i]);
    cout<<exon[i].pos<<" ";
}

void solve(){
    int maxLen = 0, pos;
    length[0] = 1;
    for(int i = 1; i < N; i++){
        length[i] = 1;
        for(int j = 0; j < i; j++)if(exon[j].end <= exon[i].start){
            if(length[i] < length[j] + 1){
                length[i] = length[j] + 1;
                parent[i] = j;
            }
        }
        if(length[i] > maxLen){
            maxLen = length[i];
            pos = i;
        }
    }
    int stack[1000], top = -1;
    while(pos >= 0){
        stack[++top] = exon[pos].pos;
        pos = parent[pos];
    }
    while(top > 0){
        cout<<stack[top--]<<' ';
    }
    cout<<stack[top]<<endl;
}

int main(){
    int i;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    while(cin>>N && N){
        for(i = 0; i < N; i++){
            cin>>exon[i].start>>exon[i].end;
            exon[i].pos = i + 1;
            length[i] = 0;
            parent[i] = -1;
        }
        sort(exon, exon+N, cmp);
        solve();
    }
    return 0;
}
