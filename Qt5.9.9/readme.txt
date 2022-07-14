这是一个简单复习Qt的文件夹，版本是5.9.9

结合书《C++Qt5.9开发》一书复习和继续学习

整理的笔记可见Qt概述.md

目前更新的子项目：

0. MyPlatform是重新配好环境后，再次运行成功的研究生时期写的软件

1. hello_world 一个开始版本

2. MetaObjectTest 元对象的测试实例

3. TestListTreeTabWidget 前四章的各类组件集中总结

4. TestFileSystemModel 在QTreeView上的应用,视图组件<=>数据模型的关系

5. TestSerialPortCommunication 公司上位机的串口通信简单测试程序

6. TestQStringListModel 在QListView上的应用,视图组件<=>数据模型的关系

7. TestQStandardItemModel 在QTableView上的应用,视图组件<=>数据模型的关系

8. TestQThread 线程的简单使用

9. TestDelegate 如何改变单元格默认编辑框的代理类,只需要继承和重写4个函数即可,然后使用view模型的setDelegate函数设置

10. TestStandardDialog 标准对话框的使用，包括文件对话框、颜色对话框、字体对话框、输入对话框和消息对话框

11. TestMultiDialog 展示了如何自定义对话框，使用信号与槽或者指针传递来实现对话框与主窗口或者主窗口和对话框之间的交互操作

12. TestMultiWindow 展示了如何定义多窗口，和11的例子一样的，只不过继承自QWidget和QMainWindow而不是QDialog，另外这2类窗口可以被tabWidget添加作为嵌入式显示
