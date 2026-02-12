#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> arr = {5, 10, 3, 2, 8, 1, 9};
    int n = arr.size();

    int maxLen = 0;

    // For each starting position, find the longest good subsequence
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            // Check if subsequence [i..j] is good
            bool isGood = true;
            for (int p = i; p <= j && isGood; p++)
            {
                for (int q = p + 1; q <= j; q++)
                {
                    if (abs(arr[p] - arr[q]) > 10)
                    {
                        isGood = false;
                        break;
                    }
                }
            }
            if (isGood)
            {
                maxLen = max(maxLen, j - i + 1);
            }
        }
    }

    cout << "Maximum length of good subsequence = " << maxLen << endl;

    return 0;
}
