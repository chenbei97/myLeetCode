cd STLTestCode\\algorithms\\source
/*
g++ -o ..\output\m m.cpp
..\output\m.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    vector<int> src = {1,2,3,4,5,6,7,8,9,10};
    ostream_iterator<int> out(cout," ");
    return 0;
}
g++.exe -g C:\Users\chenbei\VscodeItems\myLeetCode\STLTestCode\algorithms\source\all_of.cpp -std=c++20 -I C:/msys64/mingw64/include -I C:/msys64/mingw64/lib -l libboost_unit_test_framework-vc143-mt-gd-x64-1_79 -o C:\Users\chenbei\VscodeItems\myLeetCode\STLTestCode\algorithms\source\all_of.exe
-l libboost_atomic-vc143-mt-gd-x64-1_79 
-l libboost_atomic-vc143-mt-x64-1_79 
-l libboost_chrono-vc143-mt-gd-x64-1_79
-l libboost_chrono-vc143-mt-x64-1_79 
-l libboost_container-vc143-mt-gd-x64-1_79
-l libboost_container-vc143-mt-x64-1_79
g++ -o mismatch mismatch.cpp
.\mismatch.exe

g++ -o equal_range equal_range.cpp
.\equal_range.exe

g++ -o equal_to equal_to.cpp
.\equal_to.exe

g++ -o equal equal.cpp
.\equal.exe

g++ -o iota  iota.cpp
.\iota.exe

g++ -o copy_backward  copy_backward.cpp
.\copy_backward.exe

g++ -o copy_n  copy_n.cpp
.\copy_n.exe

g++ -o copy_if  copy_if.cpp
.\copy_if.exe

g++ -o is_permutation  is_permutation.cpp
.\is_permutation.exe

g++ -o is_partitioned  is_partitioned.cpp
.\is_partitioned.exe

g++ -o any_of  any_of.cpp
.\any_of.exe

g++ -o none_of  none_of.cpp
.\none_of.exe

g++ -o is_sorted  is_sorted.cpp
.\is_sorted.exe

