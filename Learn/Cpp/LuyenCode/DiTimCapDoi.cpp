#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) 
        cin >> a[i];
    int b = a[n-1],c = a[0];
    int max = b + c;
    for(int i = 0; i < n-1; i++) {
        if(max < (a[i] + a[i+1])) {
            b = a[i];
            c = a[i+1];
            max = b + c;
        }
    }
    cout << b << " " << c;
    system("pause");
    return 0;
}