/*
*ZOJ-1016
*比较坑爹，最后在每个序列后面多输出一个空格就报了错误，汗。。
*/
#include <iostream>
#include <stdio.h>
#include <string>
#define LOCAL

using namespace std;

int k[10];
string s;
int ret[10][20];

void buildS(int line){
    int a, cur = 0, leftNo = 0;
    s.clear();
    s.append(2 * k[line], ' ');
    for(int i = 0; i < k[line]; i++){
        cin>>a;
        while(leftNo < a){
            s[ cur++ ] = '(';
            leftNo++;
        }
        s[ cur++ ] = ')';
    }
}

void generateW(int line){
    int top, total = 0, j, p = 0;
    for(unsigned i = 0; i < s.length(); i ++) if (s[i] == ')'){
        top = 1;
        total = 0;
        j = i - 1;
        while(top){
            if(s[j] == '('){
                ++ total;
                -- top;
            }
            else{
                ++ top;
            }
            j--;
        }
        ret[line][p++] = total;
    }
}

int main(){
    int n, i, j;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    cin>>n;
    for(i = 0; i < n; i++){
        cin>>k[i];
        buildS(i);
        generateW(i);
    }
    for(i = 0; i < n; i++){
        cout<<1;
        for(j = 1; j < k[i]; j++){
            cout<<" "<<ret[i][j];
        }
        cout<<endl;
    }
    return 0;
}
