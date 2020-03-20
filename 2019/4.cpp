#include <bits/stdc++.h>
#include <cmath>
using namespace std;
const int N = 1000000;
int dp[N + 5];
int main() {
    int n;
    cin>> n;
    cout << pow(64,1/3) << endl;
    //有一个结论要证明，是２７　＋ 7 = 34 8个;  4 ×　８　＋ 2 =34  6个；
    //dp[i]  i值组成的最小立方数个数
    dp[1] = 1;
    for (int i = 2;i <= n; i++) {
        int d = pow((double)i,(double)1/3);
        cout << i << " " << d << endl;
        dp[i] = dp[i - 1] + 1;
        for (int j = 2; j <= d; j++) {
            dp[i] = min(dp[i - j * j *j] + 1,dp[i]);
        }
    }
    cout << dp[n] << endl;
    return 0;
}
