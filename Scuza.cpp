#include <bits/stdc++.h>
using namespace std;
#define ll long long int                      
int main(){

    int n;
    cin >> n;
    while (n--){
        int t, q;
        cin >> t >> q;
        vector<ll> a(t + 1, 0);
        for (int i = 1; i <= t; i++){
            cin >> a[i];
        }
        vector<ll> pre(t + 2, 0);
        for (int i = 1; i <= t; i++){
            pre[i] = (a[i] + pre[i - 1]);
        }
        vector<ll> ans(q);
        vector<pair<ll, int>> k(q);
        for (int i = 0; i < q; i++){
            cin >> k[i].first;
            k[i].second = i;
        }
        sort(k.begin(), k.end());
        int cnt = 0;
        for (int i = 0; i < q; i++){
            while (true){
                if (cnt == t or a[cnt + 1] > k[i].first)
                    break;
                cnt++;
            }
            ans[k[i].second] = pre[cnt];
        }

        for (int i = 0; i < q; i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}