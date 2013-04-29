#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main(){
    int n;
    int a, b;
    vector<float> ret;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>a>>b;
        if(a%2 && b%2)
            ret.push_back(a*b + 0.41);
        else
            ret.push_back(a*b);
    }
    for(int i = 0; i < n; i++){
        cout<<"Scenario #"<<i+1<<':'<<endl;
        cout<<setiosflags(ios::fixed)<<setprecision(2)<<ret[i]<<'\n';
        cout<<endl;
    }
    return 0;
}
