#include <bits/stdc++.h>
using namespace std;

bool canDivide(vector<int> &A, int M, int maxOR)
{
    int segments = 1, currOR = 0;
    for (int x : A)
    {
        if ((currOR | x) <= maxOR)
            currOR |= x;
        else
        {
            segments++;
            currOR = x;
        }
    }
    return segments <= M;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    // binary search
    int low = *max_element(A.begin(), A.end());
    int high = 0;
    for (int x : A)
        high |= x;

    int ans = high;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (canDivide(A, M, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    cout << ans << "\n";
    return 0;
}
