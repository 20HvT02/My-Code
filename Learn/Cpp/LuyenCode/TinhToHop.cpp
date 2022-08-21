#include<bits/stdc++.h>
using namespace std;

float giaiThua (float a) {
    if(a==1) return 1;
    return a * giaiThua(a-1);
}

float tinhToHop (float a, float b) {
    return giaiThua(a) / giaiThua(b) / giaiThua(a - b);
}

int main() {
    float a, b;
    cin >> a >> b;
    cout << tinhToHop(a, b);
    return 0;
}