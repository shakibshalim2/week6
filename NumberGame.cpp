#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0; i<n;i++)
        cin>>a[i];
        sort(a.begin(),a.end());
        auto canWin=[&](int mid){
            map<int,int>countMap;
            int cnt=0,m=0,tmp=n,k=0;
            for(int i=0;i<n;i++)
            countMap[a[i]]++;
            for(int i=1;i<=mid;i++){
                int res=mid-i+1;
                if(cnt>0&&countMap[res]>0){
                    cnt=0;
                    countMap[a[k]]--;
                    if(countMap[a[k]]==0)
                    k++;
                }
                if(countMap[res]>0&&cnt== 0){
                    m++;
                    countMap[res]--;
                    tmp--;
                    if(tmp==0)
                    break;
                    else cnt++;
                } 
                else{
                    int r=0;
                    for(int j=n-1;j>=0;j--){
                        if(a[j]<=res&&cnt>0&&countMap[a[j]]>0){
                            cnt=0;
                            countMap[a[k]]--;
                            if(countMap[a[k]]==0)
                            k++;
                        }
                        else if(cnt==0&&a[j]<=res&&countMap[a[j]]>0){
                            r=a[j];
                            break;
                        }
                    }
                    if(r&&countMap[r]>0){
                        m++;
                        countMap[r]--;
                        tmp--;
                        if(tmp==0)
                        break;
                        else
                        cnt++;
                    }
                    else 
                    break;
                }
            }
            return m==mid;
        };
        int l=1,r=100,mid,ans=0;
        while(l<=r){
            mid=(l+r)/2;
            if(canWin(mid)){
                ans=mid;
                l=mid+1;
            } 
            else{
                r=mid-1;
            }
        }
        cout<<ans<<"\n";
    }
}
