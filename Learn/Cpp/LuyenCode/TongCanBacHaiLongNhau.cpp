#include<bits/stdc++.h>
#define N 10000
using namespace std;

int main() {
    int T, n;
    cin >> T;
    double Total[N];
    Total[1] = sqrt(2);
    for (int i = 2; i < N; ++i){
        Total[i] = sqrt(2 + Total[i - 1]);
    }
    for (int i = 0; i < T; ++i){
        cin >> n;
        cout << setprecision(5) << fixed << Total[n] << '\n';
    }
    return 0;
}

// float sum(int n) {
//     float a = 0;
//     for(int i = 0; i < n; i++) {
//         a = sqrt(a+2);
//     }
//     return a;
// }

// int main() {
//     int n;
//     cin >> n;
//     int a[n];
//     for(int i = 0; i < n; i++) {
//         cin >> a[i];
//     }
//     for(int i = 0; i < n; i++) {
//             cout << round(sum(a[i]) * 100000) / 100000 << endl;
//     }
//     system("pause");
//     return 0;
// }