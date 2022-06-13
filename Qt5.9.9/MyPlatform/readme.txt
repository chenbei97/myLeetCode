1. 在https://github.com/chenbei97/mySchoolCode中下载研究生时期写的代码

2. 这份代码存在一些问题
2.1 myPlatform.py第47行代码import time改为 from time import time
    同时需要更改的是
    1735-1750行
    2090-2107行
    这些代码中的time.time()都替换成time()
2.2 myPlatform.py关于取消训练异常退出的bug
    以下这些行的return改为break就可以
    1544
    1562
    1693
    1712
    1898
    1917
    2048
    2067
2.3 相对路径问题，这里去掉/MyPlatform，改为//xxx.csv或者//xxx.jpg
    648行
    1318行
    1415行
    1746行
    1768行
    2800行
    mySignWindow的27行
    mySignDialog的23行
2.4 qrc文件需要重新编译，因为很可能因为Qt版本的不同或者电脑不同导致原有的无法运行
编译的时候，其对应的images文件夹需要在场，在下载的代码里有
也就是Fault_Monitoring_Platform、signDialog、SignIn_Widget三个文件夹下的各自images文件夹
编译的时候最好这3个qrc分别在不同文件夹，各自带上images文件夹，这样就不会冲突了
或者images把所有需要的都放进去，共用一份最大份的images文件夹也可以，本工作目录下的./images文件夹就是

signDialog.qrc -> signDialog_rc.py
signWindow.qrc -> signWindow_rc.py
fault_platform.qrc -> fault_platform_rc.py

2.5 ui文件也需要重新编译，因为Qt5.9.9编译生成的命名是
faultPlatform.ui -> faultPlatform.py
signWindow.ui -> signDialog_rc.py
signWindow.ui -> signWindow_rc.py

相应的生成的2个rc.py文件尾部都做一些代码修改：
signDialog_rc.py     import signDialog_rc -> from MyPlatform import signDialog_rc
signWindow_rc.py     import signWindow_rc -> from MyPlatform import  signWindow_rc

faultPlatform.py
# 编译这样生成的有问题,用下方2段代码替换掉
# from QChartView import QChartView import fault_platform_rc
from PyQt5.QtChart import QChartView
from MyPlatform import fault_platform_rc

从前的手动编译资源文件和ui文件的命令：
cd C:\Users\chenbei\Documents\pythonProjects\PYQT5_UI文件夹\Demo12\Fault_Monitoring_Platform
pyuic5  -o  faultPlatform.py   faultPlatform.ui

cd C:\Users\chenbei\Documents\pythonProjects\PYQT5_UI文件夹\Demo12
pyrcc5 .\Fault_Monitoring_Platform\fault_platform_icon.qrc -o fault_platform_rc.py

从前要替换的代码：
from PyQt5.QtChart import QChartView
from MyPlatform import  fault_platform_rc

注：生成的资源文件因为比较大，所以fault_platform_rc、signDialog_rc、signWindow_rc删除了
完整的本文件夹，MyPlatform可在百度云下载。
链接：https://pan.baidu.com/s/1B-8WP_FDUk7O53u5jNLD9A 
提取码：iq4d
