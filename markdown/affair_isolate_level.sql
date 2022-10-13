
## 事务
create table account(
    id int auto_increment primary key comment '主键ID',
    name varchar(10) comment '姓名',
    money int comment  '余额'
) comment '账户表';

insert into account(id,name,money) values (null,'张三',2000),(null,'李四',2000);

## 恢复数据
update account set money = 2000 where name ='张三' or name = '李四';

## 转账操作 张三给李四转账1000
# 1. 查询张三余额
select money from account where name = '张三';
# 2. 张三余额-1000
update account set money = money - 1000 where name = '张三';
# 3. 李四+1000
update account set money = money + 1000 where name = '李四';



select @@autocommit;

set @@autocommit = 0; # 手动

start transaction ;

# 1. 查询张三余额
select money from account where name = '张三';
# 2. 张三余额-1000
update account set money = money - 1000 where name = '张三';
# 3. 李四+1000
update account set money = money + 1000 where name = '李四';

commit ;

rollback ;

## 事务隔离级别
select @@transaction_isolation;

set session transaction isolation level read committed ;

