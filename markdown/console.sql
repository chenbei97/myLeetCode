show databases ;

show tables ;

desc user;

INSERT INTO user(id,name) VALUES(1,'chen');

INSERT INTO  user VALUES (2,'cb',18);

INSERT INTO user (age) values (19),(20),(32);

INSERT INTO  user VALUES (5,'c1b',32),(15,'c2b',54);


UPDATE user set id = 10, name = 'abc' , age = 60 ;

UPDATE user set id = 1, name = 'ab' , age = 6 where age  <70;

DELETE from user where id <= 2;

SELECT  id from user;

SELECT  id as 'name' from user;

select name from user;

SELECT  DISTINCT id FROM user;

select  * from user where name is null;

select  age from user where name is null;

select * from user where age in (19,32);

select * from user where age like '___';

SELECT  count(*) from user;

SELECT  avg(age) from user;

select  * from user;

SELECT max(id) from user where age=118;

create user 'abc'@'localhost' identified by '123456';

create user 'dd'@'%' identified by '123456';

alter user 'dd'@'%' identified  with mysql_native_password by '123';

drop user'abc'@'localhost' ;

show grants for 'root'@'localhost';

grant  all on dd.* to 'root'@'localhost';

revoke all on dd.* from 'root'@'localhost';

select concat('hello','mysql');

select lower('HELLO');
select upper('hello');
select lpad('B',5,'CA');
select substring('hello',1,2);

select lpad(round(rand()*1000000,0),6,'0');

select month('2022-10-12');
select day('2022/11/12');
select year('2021.9.12');

select date_add(now(),INTERVAL 70 day);
select datediff(now(),'2015-9-1');

select if(false,'ok','err');
select ifnull(null,'def');

create table info(
	id int primary key auto_increment comment '主键自动增长',
    name varchar(10) not null unique comment '姓名不为空且唯一',
    age int check(age > 0 and age <= 120) comment '年龄在(0,120]',
    status char(1) default '1' comment '状态默认1',
    gender char(1) comment '性别'
) comment '用户信息';

insert into info
	(name,age,status,gender) values
	('cb',25,'1','男'),
	('chenbei',30,'0','男'),
	('guxiaoting',25,'1','女');

create table dept(
	id int auto_increment comment 'ID' primary key,
    name varchar(50) not null comment '部门名称'
) comment '部门表';
insert into dept (name) values
	('研发部'),('市场部'),('财务部'),('销售部'),('总经办');

create table emp(
    id int auto_increment comment 'ID' primary key,
    name varchar(50) not null comment '姓名',
    age int comment '年龄',
    job varchar(20) comment  '职位',
    salary float comment '薪资',
    entrydate date comment '入职时间',
    manager_id int comment '直属领导部门',
    depart_id int comment '所属部门'
) comment '员工表';

insert into emp(name,age,job,salary,entrydate,manager_id,depart_id) values
	('A',66,'总裁',2.5,'2000-01-01',null,5),
	('B',28,'项目经理',1.8,'2005-12-29',1,1),
	('C',33,'开发',1.3,'2008-06-05',2,1),
	('D',45,'开发',1.2,'2009-03-16',2,1),
	('E',24,'开发',1.1,'2022-10-21',3,1);

alter table emp
    add constraint emp_depart
    foreign key (depart_id)
    references dept(id);

alter table emp drop foreign key emp_depart;

alter table emp add constraint emp_dept foreign key (depart_id)
    references dept(id) on update cascade on delete cascade;


create table student(
    id int auto_increment primary key comment 'ID',
    name varchar(20) comment '姓名'
)comment '学生表';
insert into student values (null,'A'),(null,'B');

create table department(
	id int auto_increment primary key comment 'ID',
    name varchar(10) comment '姓名'
)comment '部门表';
insert into department values (null,'matlab'),(null,'sql'),(null,'python'),
                              (null,'c++'),(null,'java');

create table student_department(
	id int auto_increment primary key comment 'ID',
    studentid int not null comment '学生ID',
    classid int not null comment '课程ID',
    constraint fk_studentid foreign key (studentid) references student(id),
    constraint fk_classid foreign key (classid) references department(id)
) comment '学生课程表';
insert into student_department values (null,1,1),(null,1,2),(null,1,3),(null,2,4),(null,2,5);

create table user_basic(
   id int auto_increment primary key comment 'ID',
   name varchar(10) comment '姓名',
   age int comment '年龄',
   gender char(1) comment '1: 男, 2: 女',
   phone char(11) comment '手机号'
)comment '用户基本信息';
insert into user_basic values (null,'A',18,'男','19801279790'),
                           (null,'B',19,'男','19801279791'),
                           (null,'C',82,'女','19801279792'),
                           (null,'D',28,'女','19801279793');

create table user_more(
    id int auto_increment primary key comment 'ID',
    degree varchar(20) comment '学历',
    major varchar(20) comment '专业',
    primarySchool varchar(50) comment '小学',
    university varchar(50) comment '大学',
    address varchar(50) comment '住址',
    userid int unique comment '用户ID',
    constraint fk_userid foreign key (userid) references user_basic(id) # 设置外键
) comment '用户详细信息';

insert into user_more values (null,'本科','电气','七小','北交','北京',1),
                             (null,'博士','电气','六小','上交','上海',2),
                             (null,'大专','电气','八小','西交','西安',3),
                             (null,'硕士','电气','九小','西南交','成都',4);

select * from user , dept; # 无效的笛卡尔积

create table salgrade(
	grade int ,
    losal int ,
    hisal int
);

insert into salgrade values (1,0,3000),(2,3001,5000),(3,5001,8000),
                            (5,8001,10000),(6,15001,20000),(7,20001,25000),(8,25001,30000);


