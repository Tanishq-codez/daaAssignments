#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n = 3;
    vector<int> value = {100, 60, 120};
    vector<int> weight = {20, 10, 40};
    int W = 50;
    
    // Create pairs of (value/weight ratio, value, weight)
    vector<tuple<double, int, int>> items;
    for(int i = 0; i < n; i++){
        double ratio = (double)value[i] / weight[i];
        items.push_back({ratio, value[i], weight[i]});
    }
    
    // Sort by value/weight ratio in descending order
    sort(items.begin(), items.end(), greater<tuple<double, int, int>>());
    
    double totalValue = 0;
    int remainingCapacity = W;
    
    for(auto& item : items){
        int itemValue = get<1>(item);
        int itemWeight = get<2>(item);
        
        if(itemWeight <= remainingCapacity){
            // Take entire item
            totalValue += itemValue;
            remainingCapacity -= itemWeight;
        } else {
            // Take fraction of item
            double fraction = (double)remainingCapacity / itemWeight;
            totalValue += fraction * itemValue;
            remainingCapacity = 0;
            break;
        }
    }
    
    cout << "Maximum value = " << fixed << setprecision(1) << totalValue << endl;
    
    return 0;
}
