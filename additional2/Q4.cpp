#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};
    int n = gas.size();
    
    int totalGas = 0, totalCost = 0;
    int currentGas = 0;
    int startStation = 0;
    
    for(int i = 0; i < n; i++){
        totalGas += gas[i];
        totalCost += cost[i];
        currentGas += gas[i] - cost[i];
        
        // If we can't reach next station, start from next station
        if(currentGas < 0){
            startStation = i + 1;
            currentGas = 0;
        }
    }
    
    // If total gas < total cost, no solution exists
    if(totalGas < totalCost){
        cout << -1 << endl;
    } else {
        cout << startStation << endl;
    }
    
    return 0;
}
