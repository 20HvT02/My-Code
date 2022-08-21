#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    long a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long sum = 0;
    for(int i = 0; i < k; i++) {
        sum += a[i];
    }
    long count = 0;
    for(int i = 1; i <= n-k; i++) {
        sum = sum + a[i+k-1] - a[i-1];
        if(count < sum)
            count = sum;
    }
    cout << count;
    return 0;
}