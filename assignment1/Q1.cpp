#include <iostream>
#include <vector>
using namespace std;

int binRec(vector<int> &v, int s, int e, int k)
{

    if (s > e)
        return -1;
    int m = e + (s - e) / 2;

    if (v[m] == k)
        return m;

    else if (v[m] < k)
        return binRec(v, m + 1, e, k);

    else
        return binRec(v, s, m - 1, k);
}

int main()
{

    vector<int> v = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};

    cout << binRec(v, 0, v.size() - 1, 23);
}