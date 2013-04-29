/*
* ZOJ-1094 2012-8-15 23:56
* 不是矩阵链乘法，一道简单编译题
*/
#include <iostream>
#include <string>
#include <stack>
#include <stdio.h>
#define LOCAL

using namespace std;

typedef struct _matrix{
    int rows, columns;
}Matrix;

Matrix matrices[26];
stack<Matrix> result;
int multiTimes;
bool ok;

void compute(){
    Matrix m1, m2, ans;
    m1 = result.top(); result.pop();
    m2 = result.top(); result.pop();
    if(m2.columns != m1.rows){
        ok = false;
        return;
    }
    multiTimes += m2.rows * m2.columns * m1.columns;
    ans.rows = m2.rows;
    ans.columns = m1.columns;
    result.push(ans);
}

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    int n;
    char ch;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>ch;
        cin>>matrices[ch - 'A'].rows>>matrices[ch - 'A'].columns;
    }
    string str;
    while(cin>>str){
        multiTimes = 0;
        ok = true;
        for(int i = 0; ok && i < str.length(); i++){
            if(str[i] == ')')
                compute();
            else if(str[i] != '(')
                result.push(matrices[str[i] - 'A']);
        }
        if(ok){
            result.pop();
            cout<<multiTimes<<endl;
        } else {
            cout<<"error"<<endl;
        }
    }
    return 0;
}
