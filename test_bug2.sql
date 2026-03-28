-- 测试 Bug 2: drop database 后索引映射未正确更新
show databases;
drop database students;
show databases;
use users;
show datas user_roles;
select * from user_roles;
get current database; get tables number;
use systems;
select * from users.user_roles;
show tables;
exit;
