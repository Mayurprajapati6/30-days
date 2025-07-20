#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin>>n;
 
    vector<int> vec(n-1);
 
    for(int i=0;i<n-1;i++){
        int ele;
        cin>> ele;
        vec[i] = ele;
    }
 
    long long total_sum = (1LL * n * (n+1)) / 2;
 
    for(size_t i=0;i<vec.size();i++){
        total_sum -= vec[i];
    }
 
    cout<< total_sum <<endl;
    return 0;
}
