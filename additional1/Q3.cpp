#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> arr = {1, 2, 3, 4};
    int n = arr.size();
    int sumLeft = 0;

    // For each contiguous subarray of odd size > 2, find median and remove
    // Repeat N-2 times
    for (int op = 0; op < n - 2; op++)
    {
        if (arr.size() <= 2)
            break;

        int minMedian = INT_MAX;
        int minIdx = -1;

        // Find odd-sized subarray with size > 2 with minimum median
        for (int i = 0; i + 2 < arr.size(); i += 2)
        {
            int subarraySize = 3; // minimum odd size > 2
            if (i + subarraySize - 1 < arr.size())
            {
                vector<int> sub(arr.begin() + i, arr.begin() + i + subarraySize);
                sort(sub.begin(), sub.end());
                int median = sub[subarraySize / 2];
                if (median < minMedian)
                {
                    minMedian = median;
                    minIdx = i;
                }
            }
        }

        if (minIdx != -1)
        {
            // Remove first element of this subarray
            arr.erase(arr.begin() + minIdx);
        }
    }

    // Calculate sum of remaining elements
    int sum = 0;
    for (int x : arr)
    {
        sum += x;
    }

    cout << "Sum of remaining numbers = " << sum << endl;

    return 0;
}
