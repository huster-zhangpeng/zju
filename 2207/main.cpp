#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <stdio.h>

using namespace std;

int rank[100][5];
int map[5];
int result[5];
int minValue;

int diff(int *array){
    int ret = 0;
    for(int i = 1; i < 5; i++)
        for(int j = 0; j < i; j++) if(array[j] > array[i])
            ret++;
    return ret;
}

int main(){
    int T, sum;
    char ch;
    freopen("input.txt", "r", stdin);
    while(cin>>T && T){
        for(int i = 0; i < T; i++)
            for(int j = 0; j < 5; j++){
                cin>>ch;
                rank[i][j] = ch - 'A';
            }
        minValue = INT_MAX;
        int p[] = {0, 1, 2, 3, 4};
        int temp[5];
        do{
            for(int i = 0; i < 5; i++)
                map[ p[i] ] = i;
            sum = 0;
            for(int i = 0; i < T; i++){
                for(int j = 0; j < 5; j++){
                    temp[j] = map[ rank[i][j] ];
                }
                sum += diff(temp);
            }
            if(sum < minValue){
                minValue = sum;
                memcpy(result, p, 5*sizeof(int));
            }
        }while(next_permutation(p, p+5));
        for(int i = 0; i < 5; i++){
            ch = result[i] + 'A';
            cout<<ch;
        }
        cout<<" is the median ranking with value "<<minValue<<endl;
    }
    return 0;
}

