#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n = 5;
    vector<int> deadline = {2, 1, 2, 1, 3};
    vector<int> profit = {100, 19, 27, 25, 15};
    
    // Create pairs of (profit, deadline, job_id)
    vector<tuple<int, int, int>> jobs;
    for(int i = 0; i < n; i++){
        jobs.push_back({profit[i], deadline[i], i+1});
    }
    
    // Sort by profit in descending order
    sort(jobs.begin(), jobs.end(), greater<tuple<int, int, int>>());
    
    // Track which slots are filled
    vector<int> result(n, -1);
    int totalProfit = 0;
    
    for(auto& job : jobs){
        int prof = get<0>(job);
        int dead = get<1>(job);
        int jobId = get<2>(job);
        
        // Try to schedule the job at the latest available slot before deadline
        for(int j = dead - 1; j >= 0; j--){
            if(result[j] == -1){
                result[j] = jobId;
                totalProfit += prof;
                break;
            }
        }
    }
    
    cout << "Selected Jobs: ";
    for(int i = 0; i < n; i++){
        if(result[i] != -1){
            cout << result[i] << " ";
        }
    }
    cout << endl;
    cout << "Maximum Profit = " << totalProfit << endl;
    
    return 0;
}
