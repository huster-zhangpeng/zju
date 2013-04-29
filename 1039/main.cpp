#include <iostream>
#include <stdio.h>
#include <cstring>
#define LOCAL

using namespace std;

int A[20];
bool available[20];
int N;
int path[20];
int top;

int search(int* a, int l, int player){
    int i, j, k;
    bool ok, win;
    int remain[17], length;
    cout<<"A:";
    for(i = 0; i < l; i++)cout<<a[i]<<" ";cout<<endl;
    top++;
    for(i = 0; i < l; i++){
        path[top] = a[i];
        available[ a[i] ] = false;
        if(player > 0)cout<<"I select:"<<a[i]<<endl;
        else cout<<"You select:"<<a[i]<<endl;
        length = 0;
        for(j = 0; j < l; j++) if(j != i){
            ok = true;
            for(k = a[i]; k < a[j]; k += a[i]){
                if( !available[ a[j]-k ] ){
                    ok = false;
                    available[ a[j] ] = false;
                    break;
                }
            }
            if(ok) remain[length++] = a[j];
        }
        cout<<"remain:";
        for(j = 0; j < length; j++) cout<<remain[j]<<" ";
        cout<<endl;
        win = search(remain, length, -1 * player);
        for(j = 0; j < l; j++) available[ a[j] ] = true;
        if(!win){
            top--;
            if(player > 0)cout<<"I Win"<<endl;
            else cout<<"You Win"<<endl;
            return true;
        }
    }
    top--;
    if(player > 0)cout<<"I Lost"<<endl;
    else cout<<"You Lost"<<endl;
    return false;
}

int main(){
    int T, i, j, k;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin>>T;
    for(i = 0; i < T; i++){
        cin>>N;
        memset(available, 0, sizeof(available));
        available[1] = true;
        for(j = 0; j < N; j++){
            cin>>A[j];
            available[ A[j] ] = true;
        }
        top = -1;
        cout<<"Scenario #"<<i+1<<":"<<endl;
        if(search(A, N, 1)){
            for(k = 0; k < N; k += 2)
                cout<<path[k]<<" ";
            cout<<endl;
        }else{
            cout<<"There is no winning move."<<endl;
        }
        cout<<endl;
    }
    return 0;
}
