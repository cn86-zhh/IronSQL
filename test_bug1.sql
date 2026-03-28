-- 测试 Bug 1: drop table 后表数量计数器未更新
show databases;
use users;
show tables;
get current database; get tables number;
drop table notifications;
show tables;
get current database; get tables number;
exit;
