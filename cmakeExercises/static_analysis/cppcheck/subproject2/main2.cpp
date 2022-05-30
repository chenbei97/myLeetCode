/*** 
 * @Author: chenbei
 * @Date: 2022-05-30 09:01:42
 * @LastEditTime: 2022-05-30 09:04:18
 * @Description: /subproject2/main2.cpp
 * @FilePath: \myLeetCode\cmakeExercises\static_analysis\cppcheck\subproject2\main2.cpp
 * @Signature: A boy without dreams
 */
#include <iostream>
int main(int argc, char *argv[])
{
   std::cout << "Hello Main2!" << std::endl;
   char tmp[10];
   tmp[11] = 's'; // 故意写越界的错误
   return 0;
}