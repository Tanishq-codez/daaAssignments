#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int K = 3, N = 6;
    vector<int> compartments = {1, 1, 2, 1, 2, 3};
    vector<int> arrival = {1, 2, 3, 5, 4, 6};
    vector<int> departure = {4, 5, 2, 8, 9, 9};
    vector<int> preferred = {1, 2, 1, 2, 3, 1};
    
    // Create events: (time, type, customer_id)
    // type: 0 = arrival, 1 = departure
    vector<tuple<int, int, int>> events;
    
    for(int i = 0; i < N; i++){
        events.push_back({arrival[i], 0, i});
        events.push_back({departure[i], 1, i});
    }
    
    sort(events.begin(), events.end());
    
    vector<int> compartmentCapacity(K+1, 1); // each compartment can hold 1 customer
    vector<int> compartmentOccupied(K+1, -1); // -1 means empty
    int customersServed = 0;
    
    for(auto& event : events){
        int time = get<0>(event);
        int type = get<1>(event);
        int customerId = get<2>(event);
        
        if(type == 0){ // arrival
            int pref = preferred[customerId];
            if(compartmentOccupied[pref] == -1){
                // Place in preferred compartment
                compartmentOccupied[pref] = customerId;
                customersServed++;
            } else {
                // Find empty compartment
                bool placed = false;
                for(int c = 1; c <= K; c++){
                    if(compartmentOccupied[c] == -1){
                        compartmentOccupied[c] = customerId;
                        customersServed++;
                        placed = true;
                        break;
                    }
                }
                if(!placed){
                    // Customer cannot be served
                }
            }
        } else { // departure
            // Find which compartment this customer is in
            for(int c = 1; c <= K; c++){
                if(compartmentOccupied[c] == customerId){
                    compartmentOccupied[c] = -1;
                    break;
                }
            }
        }
    }
    
    cout << "Maximum number of customers that can dine = " << customersServed << endl;
    
    return 0;
}
