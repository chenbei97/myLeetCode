## 介绍

参见学习链接：[MySQL哔哩哔哩](https://www.bilibili.com/video/BV1Kr4y1i7ru?p=3&vd_source=38010d445b9070a07a0579329536e2f7)。

DB：数据库DataBase

DBMS：数据库管理系统 Data Base Management System

SQL：结构化查询语言 Structure Quiery Language

DB由表组成，每个表由多个字段(列)组成，数据放在表里。

常见的DBMS有MySQL，Oracle、Server、Access等，这里MySQL使用的最多。其中MySQL，Oracle、Server是基于客户机-服务器的，Access是基于共享文件系统的。

SQL则是通用的语言，不依赖于软件提供商。

注意先配置环境，默认情况下地址在。

```powershell
C:\Program Files\MySQL\MySQL Server 8.0\bin
```

如果找不到可以使用win+r，输入services.msc，双击MYSQL80即可找到这个路径。此时输入下方命令进行测试。

```powershell
mysql -u root -p 
```



## 基本语法

SQL分类：

DDL，数据定义语言，用来定义数据库对象（数据库、表、字段）

DML，数据操作语言，用来对数据库表中的数据增删改查

DQL，数据查询语言，查询数据库表中的记录

DCL，数据控制语言，用来创建数据库用户、控制数据库访问权限

### 数据定义语言DDL

```mysql
SHOW DATABASES; # 查询所有数据库
SELECT DATABASE(); # 查询当前数据库
CREATE DATABASE [IF NOT EXISTS] 数据库名 [DEFAULT CHARSET 字符集] [COLLATE 排序规则];
# CREATE DATABASE CB DEFAULT CHARSET UTF8;
DROP DATABASE [IF EXISTS] 数据库名;
USE 数据库名;

SHOW TABLES; # 查询当前数据库所有表
DESC 表名; # 查询表结构
SHOW CREATE TABLE 表名; # 查询指定表的建表语句
CREATE TABLE 表名( # 创建表
    字段1 字段1类型 [COMMENT 字段1注释],
    ...
    字段n 字段n类型 [COMMENT 字段n注释]
)[COMMENT 表注释]

ALTER TABLE 表名 ADD 字段名 类型(长度) [COMMENT 注释] [约束]; # 添加字段
ALTER TABLE 表名 CHANGE 旧字段名 新字段名 类型(长度) [COMMENT 注释] [约束]; # 修改字段名和类型
ALTER TABLE 表名 DROP 字段名; # 删除字段
ALTER TABLE 表名 RENAME TO 新表名; # 修改表名
DROP TABLE [IF EXISTs] 表名; # 删除表
TRUNCATE TABLE 表名; # 删除指定表并重新创建该表
```

一个完整的例子：

```mysql
create table emp(
	id int comment '编号,纯数字',
    number varchar(10) comment '员工工号,字符串类型长度不超过10位',
    name varchar(10) comment '员工姓名,字符串类型长度不超过10位',
    gender char(1) comment '男/女,存储1个汉字',
    age tinyint unsigned comment '年龄,不能是负数',
    idcard char(18) comment '身份证号18位',
    entrydate date comment '入职时间'
) comment '员工表';
alter table emp add nickname varchar(20) comment '昵称';
alter table emp change nickname username varchar(10) comment '昵称';
alter table emp rename to employee; 
```

### 数据操作语言DML

添加数据：INSERT

修改数据：UPDATE

删除数据：DELETE

更改表以后，可以使用select查询。

```mysql
select  * from user;
```

**添加数据的常见命令格式：**

```mysql
# 插入的数据是字符串和日期类型数据要包含在引号内
INSERT INTO 表名(字段1,字段2,...) VALUES(值1,值2,...); # 给指定字段添加数据
INSERT INTO 表名 VALUES(值1,值2...); # 给全部字段添加数据
INSERT INTO 表名(字段1,...) VALUES(值1,...),(值1,...),(值1,...);#批量添加数据指定字段
INSERT INTO 表名 VALUES(值1,值2,...),(值;1,值2,...),(值1,值2,...);# 不指定字段批量添加数据
```

例子。

```mysql
INSERT INTO user(id,name) VALUES(1,'chen');
INSERT INTO  user VALUES (2,'cb',18); # 批量添加,那就必须对齐
INSERT INTO user (age) values (19),(20),(32);# age批量添加3个,注意小括号+逗号隔开
INSERT INTO  user VALUES (5,'c1b',18),(15,'c2b',118);#批量添加
```

**修改数据的命令格式：**

```mysql
UPDATE 表名 SET 字段名1 = 值1, 字段名2 = 值2,...[WHERE 条件];
```

例子。

```mysql
UPDATE user set id = 10, name = 'abc' , age = 60; # 会所有行都统一
UPDATE user set id = 1, name = 'ab' , age = 6 where age  <70; # 年龄小于60的修改
```

**删除数据的命令格式：**

```mysql
DELETE FROM 表名 [where 条件];
```

例子。

```mysql
DELETE from user where id <= 2;
```

### 数据查询语言DQL

关键字如下所示。

```mysql
SELECT; # 字段列表
FROM; # 表名列表
WHERE; # 条件列表
count,max,min,avg,sum; # 聚合函数
GROUP BY; # 分组字段列表
HAVING ; # 分组后条件列表
ORDER BY; # 排序字段列表
LIMIT; # 分页参数
```

执行顺序如下。

from->where->group by，聚合函数->having->select->orderby->limit

SELECT关键字：**

```mysql
SELECT 字段1,字段2,... FROM 表名; # 查询多个字段
SELECT * from 表名; # 查询所有字段
SELECT 字段1[AS 别名1],字段2[AS 别名2] FROM 表名; # 设置别名,要加引号，也可以省略as
SELECT DISTINCT 字段列表 FROM 表名; # 去除重复记录
```

例子。

```mysql
SELECT  id as 'name' from user;
SELECT  id 'name' from user; 
select name from user;

SELECT  DISTINCT id FROM user;
```

**条件查询：**

```mysql
SELECT 字段列表 FROM 表名 WHERE 条件列表;
# 常用的条件如下
>,>=,<,<=,=; # 大于小于等于
<>,!=; # 不等于
BETWEEN AND; # 在某个范围内,闭区间
IN(...); # in之后的列表值其中之一即可
LIKE ; #占位符,模糊匹配，下划线_匹配单个字符,而百分号%匹配任意个字符
IS NULL ;# 是NULL
AND , && ; # 与
OR , || ; # 或
NOT, ! # 非
```

例子：

```mysql
select * from user where age = 88; # 年龄88的
select * from user where age <> 22; # 年龄不等于22岁的
select * from user where age >=10 and age <= 20; # 范围
select * from user where age between 10 and 20 ;
select * from user where age >=10 && age <=20 ;
select * from user where idcard is not null; # idcard不是null的
select  age from user where name is null; # 选择name是空的但是只查看age
select * from user where age in (20,25,27); # 满足其一即可
select * from user where age like '___'; # 年龄是3位数的
```

**聚合函数：**

聚合函数都是针对某一列的数据，null值不参与计算。

```mysql
SELECT 聚合函数(字段列表) FROM 表名 [where 条件];
```

例子。

```mysql
SELECT  count(*) from user; # 整张表
SELECT  count(id) from user; # 某列总数
SELECT  avg(age) from user;
SELECT max(id) from user where age=118; # 条件下的项找到最大的id
```

**分组查询：**

where是分组前进行过滤，不满足where条件并不参与分组，而having是分组后对结果进行过滤。

where不能对聚合函数进行判断，而having可以。例如年龄字段的平均数不能用where判断，having可以继续判断平均数是否超过某个值。

执行顺序 where > 聚合函数 > having，分组之后查询的字段一般为聚合函数和分组字段，查询其他字段没有任何意义。

```mysql
select 字段列表 FROM [where 条件] group by 分组字段名 [having 分组后过滤条件];
```

例子：

```mysql
select count(*) from group by gender; # 根据性别分组统计男和女的数量，但不知道对应关系
select gender,count(*) from group by gender; # 根据性别分组统计男和女的数量,count(*)数量不需要指定字段
select gender,avg(age) from group by gender; # 根据性别分组统计男和女的平均年龄
# 查询年龄小于45的员工,并根据工作地址分组，要求分组后员工数量大于3的工作地址
select count(*) from user where age < 45 group by address;#能查到所有工作地址的员工数,但是不知道工作地址和数量的对应关系
select address,count(*) from user where age < 45 group by address;#进一步知道对应关系,例如北京5人,上海7人,南京1人
select address,count(*) from user where age < 45 group by address having count(*) >=3; # 进一步筛选只剩下北京5,上海7
select address,count(*) address_count from user where age < 45 group by address having count(*) >=3; # 再取个别名address_count,下次直接能用
```

**排序查询：**

ASC：升序(默认)

DESC：降序

如果是多字段排序，只有第1个字段相同时才会对第2个字段进行排序。

```mysql
select 字段列表 from 表名 order by 字段1 排序方式1, 字段2 排序方式2;
```

例子：

```mysql
select * from user order by age desc; # 年龄降序
select * from user order by age asc, id desc; # age升序,id降序
```

**分页查询：**

分页查询是数据库的方言，不同数据库可能不一样，mysql使用limit。如果查询的第一页数据，那么起始索引可以省略，直接写为 limit 10(查询10条记录)。

**起始索引从0开始，起始索引 = (查询页码-1) * 每页显示记录数。**例如每页有10条记录，第一页的起始索引是0，第二页是(2-1)*10也就是10，因为第一页的结束记录编号为9，也就是[0-9]。

```mysql
select 字段列表 from 表名 limit 起始索引,查询记录数;
```

例子：

```mysql
select * from user limit 0,10; # 查询第1页10条记录
select * from user limit 10,10; # 查询第2页,从10开始
```

总结案例：

```mysql
# 查询年龄20,21,22,23的女性员工信息
select * from user where gender = '女' and age in(20,21,22,23);
# 查询性别男，且年龄在20-40岁以内的姓名为3个字的员工
select * from user where gender = '男' and (age between20 and 40) and name like '___';
# 统计年龄小于60，男性和女性员工的人数
select gender,count(*) from user where age < 60 group by gender;# 注意where在分组前使用,用这个条件分组
# 查询所有年龄<=35岁员工的姓名和年龄，并对查询结果按年龄升序排序，如果年龄相同按照入职时间排序
select name,age from user where age<=35 order by age asc,time desc;
# 查询(性别男，年龄在[20,40]区间,条件)的前5个员工信息(排完序后再挑前5个不是先挑)，并对查询结果按年龄升序，若年龄相同按入职时间
select * from user where gender = '男' and (age between 20 and 40) order by age asc, time desc limit  0,5 ;
# 查询年龄大于15的员工姓名、年龄，并根据年龄进行升序
select name,age from user where age>15 order by age asc;
# 注意先执行from->where->groupby->having->select->orderby->limit
select u.name uname,u.age uage from user u where u.age>15 order by uage asc; # limit后可以使用select定义的别名uage，而select则可以使用from定义的别名u
```

### 数据控制语言DCL

**用户管理：**

主机名可以使用%通配，开发人员使用较少。

```mysql
# 查询用户
use mysql;  # 查询数据库mysql
select * from user; # 查询数据库的表user

# 创建用户
create user '用户名'@ '主机名' identified by '密码';

# 修改用户密码
alter user '用户名'@ '主机名' identified with oldpwd by 'newpwd';

# 删除用户
drop user '用户名'@ '主机名';
```

例子。

```mysql
# 只能在当前主机访问
create user 'abc'@'localhost' identified by '123456';
# 然后命令行输入mysql -u abc -p，就可以以该用户名启动客户端

# 可以在任意主机访问该数据库
create user 'dd'@'%' identified by '123456';

# 修改密码
alter user'dd'@'%' identified  with mysql_native_password by '123';

drop user'abc'@'localhost' ;
```

**权限控制：**

ALL，ALL PRIVILEGES ：所有权限

SELECT：查询数据

INSERT：插入数据

UPDATE：修改数据

DELETE：删除数据

ALTER：修改表

DROP：删除数据库/表/视图

CREATE：创建数据库/表

多个权限之间，使用逗号分割，授权时数据库名和表名可以使用 * 来通配表示所有。

```mysql
show grants for '用户名' @ '主机名'; # 查询权限
grant 权限列表 on 数据库名.表名 to '用户名' @ '主机名';# 授予权限
revoke 权限列表 on 数据库名.表名 from '用户名' @ '主机名'; # 撤销权限
```

例子。

```mysql
show grants for 'root'@'localhost';
grant  all on dd.* to 'root'@'localhost'; # root有权操作dd的所有表
revoke all on dd.* from 'root'@'localhost'; # 撤销
```



## 数据类型

数值类型：

| 类型         | 大小                                     | 范围（有符号）                                               | 范围（无符号）                                               | 用途            |
| :----------- | :--------------------------------------- | :----------------------------------------------------------- | :----------------------------------------------------------- | :-------------- |
| TINYINT      | 1 Bytes                                  | (-128，127)                                                  | (0，255)                                                     | 小整数值        |
| SMALLINT     | 2 Bytes                                  | (-32 768，32 767)                                            | (0，65 535)                                                  | 大整数值        |
| MEDIUMINT    | 3 Bytes                                  | (-8 388 608，8 388 607)                                      | (0，16 777 215)                                              | 大整数值        |
| INT或INTEGER | 4 Bytes                                  | (-2 147 483 648，2 147 483 647)                              | (0，4 294 967 295)                                           | 大整数值        |
| BIGINT       | 8 Bytes                                  | (-9,223,372,036,854,775,808，9 223 372 036 854 775 807)      | (0，18 446 744 073 709 551 615)                              | 极大整数值      |
| FLOAT        | 4 Bytes                                  | (-3.402 823 466 E+38，-1.175 494 351 E-38)，0，(1.175 494 351 E-38，3.402 823 466 351 E+38) | 0，(1.175 494 351 E-38，3.402 823 466 E+38)                  | 单精度 浮点数值 |
| DOUBLE       | 8 Bytes                                  | (-1.797 693 134 862 315 7 E+308，-2.225 073 858 507 201 4 E-308)，0，(2.225 073 858 507 201 4 E-308，1.797 693 134 862 315 7 E+308) | 0，(2.225 073 858 507 201 4 E-308，1.797 693 134 862 315 7 E+308) | 双精度 浮点数值 |
| DECIMAL      | 对DECIMAL(M,D) ，如果M>D，为M+2否则为D+2 | 依赖于M和D的值                                               | 依赖于M和D的值                                               | 小数值          |

使用的时候可以结合UNSIGNED或SIGNED关键字。

```mysql
age TINYINT UNSIGNED;
score DOUBLE(4,1);#表示四位长度和1位标度
```

日期和事件类型：

| 类型      | 大小 ( bytes) | 范围                                                         | 格式                | 用途                     |
| :-------- | :------------ | :----------------------------------------------------------- | :------------------ | :----------------------- |
| DATE      | 3             | 1000-01-01/9999-12-31                                        | YYYY-MM-DD          | 日期值                   |
| TIME      | 3             | '-838:59:59'/'838:59:59'                                     | HH:MM:SS            | 时间值或持续时间         |
| YEAR      | 1             | 1901/2155                                                    | YYYY                | 年份值                   |
| DATETIME  | 8             | '1000-01-01 00:00:00' 到 '9999-12-31 23:59:59'               | YYYY-MM-DD hh:mm:ss | 混合日期和时间值         |
| TIMESTAMP | 4             | '1970-01-01 00:00:01' UTC 到 '2038-01-19 03:14:07' UTC结束时间是第 **2147483647** 秒，北京时间 **2038-1-19 11:14:07**，格林尼治时间 2038年1月19日 凌晨 03:14:07 | YYYY-MM-DD hh:mm:ss | 混合日期和时间值，时间戳 |

字符串类型：

| 类型       | 大小                  | 用途                            |
| :--------- | :-------------------- | :------------------------------ |
| CHAR       | 0-255 bytes           | 定长字符串                      |
| VARCHAR    | 0-65535 bytes         | 变长字符串                      |
| TINYBLOB   | 0-255 bytes           | 不超过 255 个字符的二进制字符串 |
| TINYTEXT   | 0-255 bytes           | 短文本字符串                    |
| BLOB       | 0-65 535 bytes        | 二进制形式的长文本数据          |
| TEXT       | 0-65 535 bytes        | 长文本数据                      |
| MEDIUMBLOB | 0-16 777 215 bytes    | 二进制形式的中等长度文本数据    |
| MEDIUMTEXT | 0-16 777 215 bytes    | 中等长度文本数据                |
| LONGBLOB   | 0-4 294 967 295 bytes | 二进制形式的极大文本数据        |
| LONGTEXT   | 0-4 294 967 295 bytes | 极大文本数据                    |

**注意：**char(n) 和 varchar(n) 中括号中 n 代表字符的个数，并不代表字节个数，比如 CHAR(30) 就可以存储 30 个字符。CHAR 和 VARCHAR 类型类似，但它们保存和检索的方式不同，一般CHAR的性能更好。BINARY 和 VARBINARY 类似于 CHAR 和 VARCHAR，不同的是它们包含二进制字符串而不要非二进制字符串。BLOB 是一个二进制大对象，可以容纳可变数量的数据。有 4 种 BLOB 类型：TINYBLOB、BLOB、MEDIUMBLOB 和 LONGBLOB。它们区别在于可容纳存储范围不同。有 4 种 TEXT 类型：TINYTEXT、TEXT、MEDIUMTEXT 和 LONGTEXT。对应的这 4 种 BLOB 类型，可存储的最大长度不同，可根据实际情况选择。

















