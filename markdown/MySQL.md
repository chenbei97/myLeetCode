## 介绍

参见学习链接：[MySQL哔哩哔哩](https://www.bilibili.com/video/BV1Kr4y1i7ru?p=3&vd_source=38010d445b9070a07a0579329536e2f7)。

DB：数据库DataBase

DBMS：数据库管理系统 Data Base Management System

SQL：结构化查询语言 Structure Quiery Language

DB由表组成，每个表由多个字段(列)组成，数据放在表里。

常见的DBMS有MySQL，Oracle、Server、Access等，这里MySQL使用的最多。其中MySQL，Oracle、Server是基于客户机-服务器的，Access是基于共享文件系统的。

SQL则是通用的语言，不依赖于软件提供商。

社区版下载地址：[MySQL :: Download MySQL Installer](https://dev.mysql.com/downloads/installer/)

安装：

![install_sql_1.jpg](install_sql_1.jpg)

点击安装全部。

![install_sql_2.jpg](install_sql_2.jpg)

![install_sql_3.jpg](install_sql_3.jpg)

端口号3306自动分配的。

然后设置密码，这里是199791。

![](C:\Users\Lenovo\Desktop\myLeetCode\markdown\install_sql_4.jpg)

设置完密码下一步，要记得这个Windows Service Details的名称是**MySQL80**，以后命令行启动的时候需要使用。

![install_sql_5.jpg](install_sql_5.jpg)

然后下一步，点击配置然后完成即可。

![install_sql_6.jpg](install_sql_6.jpg)

输入密码，然后核对下一步。

![install_sql_6.jpg](install_sql_6.jpg)

输入密码，下一步。

![](C:\Users\Lenovo\Desktop\myLeetCode\markdown\install_sql_7.jpg)

结束即可启动界面。

如果命令行启动数据库，可以使用cmd+ctrl+shift+enter，这样有权访问。

```powershell
net start mysql80
net stop mysql80
```

![](C:\Users\Lenovo\Desktop\myLeetCode\markdown\sql_start_command.jpg)

## 基本语法

SQL分类：

DDL，数据定义语言，用来定义数据库对象（数据库、表、字段）

DML，数据操作语言，用来对数据库表中的数据增删改查

DQL，数据查询语言，查询数据库表中的记录

DCL，数据控制语言，用来创建数据库用户、控制数据库访问权限