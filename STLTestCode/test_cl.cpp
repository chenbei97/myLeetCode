#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iterator>
using namespace std;
int main()
{
    vector<int> src = {5,4,3,2,1};
    sort(src.begin(),src.end());
    cout<<"src: ";
    copy(src.begin(), src.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    int sum = accumulate(src.begin(),src.end(),0);
    cout<<"sum: "<<sum<<endl;
    
    return 0;
}