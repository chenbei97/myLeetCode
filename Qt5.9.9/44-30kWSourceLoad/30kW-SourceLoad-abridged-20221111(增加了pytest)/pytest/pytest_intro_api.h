#ifndef PYTEST_INTRO_API_H
#define PYTEST_INTRO_API_H
#include <Python.h>
#include <QDebug>

// 引入测试：引入python、引入python且引入第三方库
/*
 * 要在object.h中添加2行代码,因为python定义的slots和qt定义的slots重合了
typedef struct{
    const char* name;
    int basicsize;
    int itemsize;
    unsigned int flags;
    #undef slots 添加
    PyType_Slot *slots;
    #define slots Q_SLOTS 添加
} PyType_Spec;
**/

// 引入python的测试
int test_python()
{
    Py_Initialize();
    if(!Py_IsInitialized())
    {
        qDebug()<<"Python init fail!"; // python初始化失败
        return -1;
    }
//    PyRun_SimpleString("import os,sys,numpy");
    PyRun_SimpleString("import os,sys");
//    PyRun_SimpleString("print(os.getcwd())");
//    PyRun_SimpleString("import numpy as np");
//    PyRun_SimpleString("print(np.linspace(0,10,11))");
    PyRun_SimpleString("sys.argv = ['python.py']");
    PyRun_SimpleString("sys.path.append('../pytest')"); // 如果用./,python脚本要放在debug目录下,如果用../，那么脚本可以放在main.cpp同级，这里放在同级的文件夹下
    PyRun_SimpleString("print(os.getcwd())"); // 测试当前路径 C:\Users\Lenovo\Desktop\30kW-SourceLoad-abridged\build-30kW-SourceLoad-Debug

    PyObject* pModule = PyImport_ImportModule("test_python");//自定义的py文件名称
    if (!pModule)
     {
         qDebug()<<"Cant open python file!\n"; // 找不到自定义的python脚本
         return -1;
     }

    PyObject* pFunshow= PyObject_GetAttrString(pModule,"show"); // 调用脚本的show函数
    if(!pFunshow){
        qDebug()<<"Get show function hello failed";
        return -1;
    }
    PyObject_CallFunction(pFunshow,Q_NULLPTR);
    qDebug()<<"pFunshow is called";
    PyObject* pFunsum= PyObject_GetAttrString(pModule,"sum"); // 调用脚本的show函数
    if(!pFunsum){
        qDebug()<<"Get sum function hello failed";
        return -1;
    }
    PyObject_CallFunction(pFunsum,"ii",1,9); // 传参的规则可见 https://blog.csdn.net/Windgs_YF/article/details/91431282
    qDebug()<<"pFunsum is called";

    //结束，释放python
    Py_Finalize();

    return 0;
}

// 引入第三方库的测试
int test_plot()
{
    //Py_SetPythonHome((wchar_t *)(L"C:\\Users\\Lenovo\\AppData\\Local\\Programs\\Python\\Python37-32")); // 注释掉好像也没事
    Py_Initialize();
    wchar_t * str = Py_GetPythonHome();
    qDebug()<<QString::fromWCharArray(str);
    if ( !Py_IsInitialized() )
    {
        printf("Cant Py_IsInitialized !\n");return -1 ;
    }
    PyRun_SimpleString("import os,sys");
    PyRun_SimpleString("sys.path.append('../pytest')");
    PyRun_SimpleString("print(os.getcwd())");

    PyObject* pModule = PyImport_ImportModule("test_plot");
    if (!pModule)
     {
         qDebug()<<"Cant open python file!\n";
         return -1;
     }
    PyObject* pFunshow= PyObject_GetAttrString(pModule,"main"); // 调用函数
    if(!pFunshow){
        qDebug()<<"Get main function hello failed";
        return -1;
    }
    PyObject_CallFunction(pFunshow,Q_NULLPTR);
    Py_Finalize();
    return 0;
}

#endif // PYTEST_INTRO_API_H
