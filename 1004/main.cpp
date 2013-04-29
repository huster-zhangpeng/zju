/*
* ZOJ-1004
* 栈深度优先搜索遍历
* by zp on 7/24/2012
* 另：发现了string对象全局变量的一些独特特性
*/
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

string str1, str2;
string stack;
string result;

void print_r(){
    cout<<endl;
    for(unsigned i = 0; i < result.length(); i ++){
        cout<<result[i]<<' ';
    }
}

void find(int m, int n, int rk, int si){
    if(n < str2.length()){
        if(m < str1.length()){
            result[ rk ] = 'i';
            stack[ si ] = str1[ m ];
            find(m + 1, n, rk + 1, si + 1);
        }else if(stack[si - 1] != str2[n]){
            stack[si - 1] = ' ';
            return;
        }
        if(si > 0 && stack[si - 1] == str2[n]){
            result[ rk ] = 'o';
            char ch = stack[si - 1];
            stack[si - 1] = ' ';
            find(m, n + 1, rk + 1, si - 1);
            stack[si - 1] = ch;
        }
    } else {
        print_r();
        return;
    }
}

int main(){
#define LOCAL
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    while(cin>>str1>>str2){
        result.clear();
        stack.clear();
        result.append(2 * str1.length(), ' ');
        stack.append(str1.length(), ' ');
        cout<<'[';
        find(0, 0, 0, 0);
        cout<<'\n'<<']'<<endl;
    }
    return 0;
}
