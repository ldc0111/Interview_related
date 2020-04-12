#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> A;
    unordered_map<int,int> mp;
    map<int,int> ans;
    unordered_map<int,int> temp;
    int n,tmp,cnt = 0,len = INT_MAX,X = 0;
    scanf("%d",&n);
    //cin >> n;
    A.push_back(0);
    for (int i = 1; i <= n; i++) {
        scanf("%d",&tmp);
        //cin >> tmp;
        A.push_back(tmp);
        mp[tmp] = 1;
    }
    queue<int> q;
    cnt = mp.size();
    if (cnt == 1) {
        printf("1 %d\n",A.size() - 1);
        for (int i = 1; i <= A.size(); i++) {
            printf("[%d,%d] ",i,i);
        }
        printf("\n");
        return 0;
    }
    for (int i = 1; i < A.size(); i++) {
        //统计当前区间内的元素个数
        if (i + 1 < A.size() && A[i] == A[i + 1]) continue;
        temp[A[i]] += 1;
        //cout << i << " " << temp.size() << endl;
        q.push(i);//统计区间
        if(temp.size() == cnt) {
            //统计区间
            int val = i;
            while(val >= 1 && A[val] == A[val-1]) val-=1;
            while(temp.size() == cnt) {
                int key = q.front();
                q.pop();
                ans[key] = val;
                temp[A[key]] -= 1;
                if (temp[A[key]] <= 0) temp.erase(A[key]);
                if (val-key < len) len = val-key,X = 1;
                else if (val-key == len) X++;
            }
        }
    }
    printf("%d %d\n",len + 1,X);
    for (auto x: ans) {
        if (x.second-x.first == len)
        printf("[%d,%d] ",x.first,x.second);
    }
    cout << endl;
    return 0;
}