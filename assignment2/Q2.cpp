#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[]={900,910,920,1100,1120};
    int dep[]={940,1200,950,1130,1140};
    int n=5;
    sort(arr,arr+n);
    sort(dep,dep+n);

    int plat=1,res=1,i=1,j=0;
    while(i<n && j<n){
        if(arr[i]<=dep[j]){
            plat++; i++;
        } else {
            plat--; j++;
        }
        res=max(res,plat);
    }
    cout<<res;
}
