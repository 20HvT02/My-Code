#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >>b;
    if(a == b) 
        cout << a/2 << " " << a/2;
    else
        cout << (a + b)/2 << " " << (a-b)/2;
        system("pause");
    return 0;
}