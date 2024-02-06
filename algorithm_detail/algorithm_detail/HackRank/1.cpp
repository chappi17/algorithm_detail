#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    
    int n,q;
    
    cin >> n >> q;
    
    vector<vector<int>> arr(n);
    
    for(int i=0; i < n; i++)
    {
        int k;
        cin >> k;
        arr[i].resize(k);
        for(int j=0; j < k; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    for(int i=0; i <q;i++)
    {
        int x, y;
        cin >> x>> y;
        cout << arr[x][y] << endl;
    }
    
        return 0;
}
