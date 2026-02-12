#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s = "fooland";
    int k = 2;
    int n = s.length();
    
    if(k >= n){
        cout << "" << endl;
        return 0;
    }
    
    // Use stack to remove characters greedily
    string result = "";
    int toRemove = k;
    
    for(int i = 0; i < n; i++){
        // Remove characters from result if current character is smaller
        // and we still have characters to remove
        while(!result.empty() && result.back() > s[i] && toRemove > 0){
            result.pop_back();
            toRemove--;
        }
        result += s[i];
    }
    
    // If we still need to remove characters, remove from the end
    while(toRemove > 0){
        result.pop_back();
        toRemove--;
    }
    
    cout << "Output: " << result << endl;
    
    return 0;
}
