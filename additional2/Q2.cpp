#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int m = 3, n = 3;
    vector<int> horizontalCosts = {2, 1};
    vector<int> verticalCosts = {3, 1};

    // Sort costs in descending order (greedy approach: merge with highest cost last = minimum cost)
    sort(horizontalCosts.begin(), horizontalCosts.end(), greater<int>());
    sort(verticalCosts.begin(), verticalCosts.end(), greater<int>());

    long long totalCost = 0;
    int hIdx = 0, vIdx = 0;
    int horizontalPieces = 1, verticalPieces = 1;

    while (hIdx < horizontalCosts.size() && vIdx < verticalCosts.size())
    {
        if (horizontalCosts[hIdx] >= verticalCosts[vIdx])
        {
            // Make horizontal cut
            totalCost += horizontalCosts[hIdx] * verticalPieces;
            horizontalPieces++;
            hIdx++;
        }
        else
        {
            // Make vertical cut
            totalCost += verticalCosts[vIdx] * horizontalPieces;
            verticalPieces++;
            vIdx++;
        }
    }

    // Process remaining horizontal cuts
    while (hIdx < horizontalCosts.size())
    {
        totalCost += horizontalCosts[hIdx] * verticalPieces;
        hIdx++;
    }

    // Process remaining vertical cuts
    while (vIdx < verticalCosts.size())
    {
        totalCost += verticalCosts[vIdx] * horizontalPieces;
        vIdx++;
    }

    cout << "Minimum cost = " << totalCost << endl;

    return 0;
}
