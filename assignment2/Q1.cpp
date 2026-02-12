#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<pair<int,int>> act={{1,2},{3,4},{0,6},{5,7},{8,9},{5,9}};
    sort(act.begin(),act.end(),
         [](auto a,auto b){return a.second<b.second;});

    int cnt=1, last=act[0].second;
    for(int i=1;i<act.size();i++){
        if(act[i].first>=last){
            cnt++;
            last=act[i].second;
        }
    }
    cout<<"Maximum Activities = "<<cnt;
}
