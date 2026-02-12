#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N = 6;
    vector<int> startDay = {1, 2, 4, 6, 5, 8};
    vector<int> endDay = {3, 5, 6, 7, 9, 10};
    int Q = 3; // number of tentative plans
    
    // Create pairs of (endDay, startDay, index) for sorting
    vector<tuple<int, int, int>> courses;
    for(int i = 0; i < N; i++){
        courses.push_back({endDay[i], startDay[i], i});
    }
    
    // Sort by end day
    sort(courses.begin(), courses.end());
    
    // For each query/plan, find maximum non-overlapping courses
    vector<int> queryStartDay = {1, 2, 4};
    vector<int> queryEndDay = {1, 2, 4};
    
    // Example queries - using first Q courses as separate plans
    cout << "For each study plan:" << endl;
    
    int totalCourses = 0;
    vector<vector<int>> selectedPlans;
    
    for(int plan = 0; plan < Q; plan++){
        vector<int> selected;
        int lastEnd = 0;
        
        for(auto& course : courses){
            int end = get<0>(course);
            int start = get<1>(course);
            int idx = get<2>(course);
            
            // For each plan, chef attends at most one course per day
            if(start >= lastEnd){
                selected.push_back(idx + 1);
                lastEnd = end;
            }
        }
        
        selectedPlans.push_back(selected);
        totalCourses += selected.size();
        
        cout << "Plan " << (plan+1) << ": " << selected.size() << " courses - ";
        for(int s : selected){
            cout << s << " ";
        }
        cout << endl;
    }
    
    cout << "Total courses across all plans: " << totalCourses << endl;
    
    return 0;
}
