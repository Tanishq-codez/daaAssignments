#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Puzzle story problem - finding minimum square size
    // Kaneki has N rectangles of width W and height H
    // Need to find minimum size of square that can contain all N rectangles

    int T = 1; // number of test cases

    while (T--)
    {
        int N;
        cin >> N;

        vector<long long> widths(N), heights(N);

        for (int i = 0; i < N; i++)
        {
            cin >> widths[i] >> heights[i];
        }

        // Binary search on the side length of the square
        long long left = 1, right = 2e9;
        long long answer = right;

        while (left <= right)
        {
            long long mid = (left + right) / 2;
            long long area = mid * mid;

            // Check if all rectangles can fit in square of side mid
            long long totalArea = 0;
            for (int i = 0; i < N; i++)
            {
                totalArea += widths[i] * heights[i];
            }

            if (totalArea <= area)
            {
                // This is possible, try smaller
                answer = mid;
                right = mid - 1;
            }
            else
            {
                // Need larger square
                left = mid + 1;
            }
        }

        cout << "Minimum square size = " << answer << endl;
    }

    return 0;
}
