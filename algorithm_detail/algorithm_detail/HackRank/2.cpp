#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int n;
    vector<int> a;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        a.emplace_back(k);
    }

    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i];
    }
    reverse(a.begin(), a.end());
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i];
    }
    
    return 0;
}
