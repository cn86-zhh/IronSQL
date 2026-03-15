-- 联合用户表的所有数据为一张表数据: user_all
LINK TABLE FROM users.user_roles to users.permissions new user_0;
LINK TABLE FROM users.user_0 to users.notifications new user_1;
LINK TABLE FROM users.user_1 to users.login_logs new user_2;
LINK TABLE FROM users.user_2 to users.user_profile new user_3;
LINK TABLE FROM users.user_3 to users.user_account new user_all;
SELECT * FROM users.user_all;
USE users; 
SHOW TABLES;