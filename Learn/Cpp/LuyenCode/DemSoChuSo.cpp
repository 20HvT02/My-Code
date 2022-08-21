#include<bits/stdc++.h>
using namespace std;

int main() {
    string n;
    cin >> n;
    if(n[0] == '-')
        cout << n.length()-1;
    else
    	cout << n.length();
    system("pause");
    return 0;
}