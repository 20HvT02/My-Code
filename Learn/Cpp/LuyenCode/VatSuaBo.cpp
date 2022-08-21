#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int temp;
    for (int i = 0; i < n; i++) 
        for(int j = n-1; j > i; j--) {
            if(a[j-1] < a[j]) {
                temp = a[j-1];
                a[j-1] = a[j];
                a[j] = temp;
            }
        }
    int sum = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] > 0)
            sum += a[i];
        else break;
        for(int j = i+1; j < n; j++)
            a[j] -= 1;
    }
    cout << sum;
    system("pause");
    return 0;
}