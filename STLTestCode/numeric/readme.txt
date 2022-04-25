cd STLTestCode\\numeric\\source
/*
g++ -o ..\output\m m.cpp
..\output\m.exe
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <iterator>
using namespace std;
int main()
{
    vector<int> src = {};
    ostream_iterator<int> out(cout," ");
    return 0;
}



