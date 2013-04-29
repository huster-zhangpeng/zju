/*
* ZOJ-1074
* 发现max是一个宏，以后不能拿max随便定义变量了
*/
#include <iostream>
#include <cstring>
#include <stdio.h>
//#define LOCAL

using namespace std;

int N;
int array[100][100];
int sum[100];
int result;

void getMax(){
    int tmax, temp;
    tmax = sum[0];
    temp = 0;
    for(int i = 0; i < N; i++){
        temp += sum[i];
        if(temp > tmax) tmax = temp;
        if(temp < 0) temp = 0;
    }
    if(tmax > result) result = tmax;
}

int main(){
    int i, j, k;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    cin>>N;
    for(i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin>>array[i][j];
    result = array[0][0];
    for(i = 0; i < N; i++){
        memset(sum, 0, sizeof(sum));
        for(j = i; j < N; j++){
            for(k = 0; k < N; k++)
                sum[k] += array[j][k];
            getMax();
        }
    }
    cout<<result<<endl;
}
