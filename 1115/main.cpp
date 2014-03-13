#include <iostream>
#include <sstream>

using namespace std;

int main() {
    int sum, length;
    string s;
    while(cin>>s && s != "0") {
        while(s.size() > 1) {
            sum = 0;
            length = s.size();
            for(int i = 0; i < length; i++) {
                sum += s[i] - '0';
            }
            stringstream ss;
            ss << sum;
            ss >> s;
        }
        cout<<s<<endl;
    }
    return 0;
}
