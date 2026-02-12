#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> arr = {1, 5, 3, 8, 2, 9};
    int k = 3;
    int n = arr.size();
    
    // For each element, find if there's a contiguous subarray where
    // exactly k numbers are strictly greater than this element
    int specialCount = 0;
    
    for(int i = 0; i < n; i++){
        // Check all contiguous subarrays containing position i
        for(int start = 0; start <= i; start++){
            for(int end = i; end < n; end++){
                int count = 0;
                for(int j = start; j <= end; j++){
                    if(arr[j] > arr[i]){
                        count++;
                    }
                }
                if(count == k){
                    specialCount++;
                    break;
                }
            }
        }
    }
    
    cout << "Speciality of sequence = " << specialCount << endl;
    
    return 0;
}
