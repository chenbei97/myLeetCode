/*
cd STLTestCode\\yushiqi
g++ -o goto goto.cpp
./goto
*/
#include <iostream>
using namespace std;
float mySquare(float val){
    if (val<=0.0f || val >=1.0f){
        cerr<<"Error: value must be between in (0,1)"<<endl;
        goto EXIT_ERROR;
    }
    return val*val;
    EXIT_ERROR: // 跳转做一些事情
        return 0.0f;
}
int main()
{
    // 使用goto语句
    float input1 = 0.0f;
    float res;
    res = mySquare(input1);
    cout << "res = " << res << endl;
    float input2 = 0.5f;
    res = mySquare(input2);
    cout << "res = " << res << endl;
    // 避免使用goto语句,使用switch语句替代
    unsigned char input_char = 0;
    cout<<"please input a char:"<<endl;
    cin>>input_char;
    while (input_char != 'q')
    {
        cout<<"please input a char:"<<endl;
        cin>>input_char;
        switch (input_char)
        {
            case 'l':
                cout<<"left"<<endl;
                break;
            case 'r':
                cout<<"right"<<endl;
                break;
            case 'u':
                cout<<"up"<<endl;
                break;
            case 'd':
                cout<<"down"<<endl;
                break;
            default:
                cout<<"wrong input"<<endl;
                break;
        }
    }
    return 0;
}