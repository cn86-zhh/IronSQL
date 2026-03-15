-- 创建第一个数据库：企业人力资源管理系统
CREATE DATABASE hr_management;

-- 使用hr_management数据库
USE hr_management;

-- 创建员工表
CREATE TABLE employees (
    id INT,
    employee_id STRING,
    first_name STRING,
    last_name STRING,
    email STRING,
    phone STRING,
    hire_date STRING,
    job_title STRING,
    department_id INT,
    manager_id INT,
    salary DOUBLE,
    status STRING
);

-- 创建部门表
CREATE TABLE departments (
    id INT,
    department_name STRING,
    location STRING,
    manager_id INT,
    created_date STRING
);

-- 创建职位表
CREATE TABLE job_titles (
    id INT,
    title STRING,
    description STRING,
    min_salary DOUBLE,
    max_salary DOUBLE
);

-- 创建员工考勤表
CREATE TABLE attendance (
    id INT,
    employee_id INT,
    date STRING,
    check_in_time STRING,
    check_out_time STRING,
    status STRING
);

-- 创建员工薪资表
CREATE TABLE salaries (
    id INT,
    employee_id INT,
    effective_date STRING,
    salary DOUBLE,
    bonus DOUBLE,
    tax DOUBLE
);

-- 创建员工培训表
CREATE TABLE training (
    id INT,
    employee_id INT,
    training_name STRING,
    start_date STRING,
    end_date STRING,
    completion_status STRING,
    score DOUBLE
);

-- 插入部门数据
INSERT INTO departments (id, department_name, location, manager_id, created_date) VALUES (1, '人力资源部', '总部', 1, '2026-01-01');
INSERT INTO departments (id, department_name, location, manager_id, created_date) VALUES (2, '技术部', '总部', 2, '2026-01-01');
INSERT INTO departments (id, department_name, location, manager_id, created_date) VALUES (3, '市场部', '总部', 3, '2026-01-01');
INSERT INTO departments (id, department_name, location, manager_id, created_date) VALUES (4, '销售部', '总部', 4, '2026-01-01');
INSERT INTO departments (id, department_name, location, manager_id, created_date) VALUES (5, '财务部', '总部', 5, '2026-01-01');

-- 插入职位数据
INSERT INTO job_titles (id, title, description, min_salary, max_salary) VALUES (1, '人力资源经理', '负责人力资源管理', 10000, 20000);
INSERT INTO job_titles (id, title, description, min_salary, max_salary) VALUES (2, '软件开发工程师', '负责软件开发生命周期', 8000, 15000);
INSERT INTO job_titles (id, title, description, min_salary, max_salary) VALUES (3, '市场专员', '负责市场推广活动', 6000, 10000);
INSERT INTO job_titles (id, title, description, min_salary, max_salary) VALUES (4, '销售经理', '负责销售团队管理', 9000, 18000);
INSERT INTO job_titles (id, title, description, min_salary, max_salary) VALUES (5, '财务主管', '负责财务管理', 8000, 16000);

-- 插入员工数据
INSERT INTO employees (id, employee_id, first_name, last_name, email, phone, hire_date, job_title, department_id, manager_id, salary, status) VALUES (1, 'EMP001', '张', '三', 'zhangsan@example.com', '13800138001', '2026-01-01', '人力资源经理', 1, NULL, 15000, 'active');
INSERT INTO employees (id, employee_id, first_name, last_name, email, phone, hire_date, job_title, department_id, manager_id, salary, status) VALUES (2, 'EMP002', '李', '四', 'lisi@example.com', '13800138002', '2026-01-02', '软件开发工程师', 2, 1, 12000, 'active');
INSERT INTO employees (id, employee_id, first_name, last_name, email, phone, hire_date, job_title, department_id, manager_id, salary, status) VALUES (3, 'EMP003', '王', '五', 'wangwu@example.com', '13800138003', '2026-01-03', '市场专员', 3, 1, 8000, 'active');
INSERT INTO employees (id, employee_id, first_name, last_name, email, phone, hire_date, job_title, department_id, manager_id, salary, status) VALUES (4, 'EMP004', '赵', '六', 'zhaoliu@example.com', '13800138004', '2026-01-04', '销售经理', 4, 1, 14000, 'active');
INSERT INTO employees (id, employee_id, first_name, last_name, email, phone, hire_date, job_title, department_id, manager_id, salary, status) VALUES (5, 'EMP005', '钱', '七', 'qianqi@example.com', '13800138005', '2026-01-05', '财务主管', 5, 1, 13000, 'active');
INSERT INTO employees (id, employee_id, first_name, last_name, email, phone, hire_date, job_title, department_id, manager_id, salary, status) VALUES (6, 'EMP006', '孙', '八', 'sunba@example.com', '13800138006', '2026-01-06', '软件开发工程师', 2, 2, 10000, 'active');
INSERT INTO employees (id, employee_id, first_name, last_name, email, phone, hire_date, job_title, department_id, manager_id, salary, status) VALUES (7, 'EMP007', '周', '九', 'zhoujiu@example.com', '13800138007', '2026-01-07', '市场专员', 3, 3, 7000, 'active');
INSERT INTO employees (id, employee_id, first_name, last_name, email, phone, hire_date, job_title, department_id, manager_id, salary, status) VALUES (8, 'EMP008', '吴', '十', 'wushi@example.com', '13800138008', '2026-01-08', '销售代表', 4, 4, 9000, 'active');

-- 插入考勤数据
INSERT INTO attendance (id, employee_id, date, check_in_time, check_out_time, status) VALUES (1, 1, '2026-03-01', '09:00', '18:00', '正常');
INSERT INTO attendance (id, employee_id, date, check_in_time, check_out_time, status) VALUES (2, 2, '2026-03-01', '09:00', '18:30', '加班');
INSERT INTO attendance (id, employee_id, date, check_in_time, check_out_time, status) VALUES (3, 3, '2026-03-01', '09:15', '18:00', '迟到');
INSERT INTO attendance (id, employee_id, date, check_in_time, check_out_time, status) VALUES (4, 4, '2026-03-01', '09:00', '17:30', '早退');
INSERT INTO attendance (id, employee_id, date, check_in_time, check_out_time, status) VALUES (5, 5, '2026-03-01', '09:00', '18:00', '正常');

-- 插入薪资数据
INSERT INTO salaries (id, employee_id, effective_date, salary, bonus, tax) VALUES (1, 1, '2026-01-01', 15000, 3000, 3000);
INSERT INTO salaries (id, employee_id, effective_date, salary, bonus, tax) VALUES (2, 2, '2026-01-01', 12000, 2400, 2400);
INSERT INTO salaries (id, employee_id, effective_date, salary, bonus, tax) VALUES (3, 3, '2026-01-01', 8000, 1600, 1600);
INSERT INTO salaries (id, employee_id, effective_date, salary, bonus, tax) VALUES (4, 4, '2026-01-01', 14000, 2800, 2800);
INSERT INTO salaries (id, employee_id, effective_date, salary, bonus, tax) VALUES (5, 5, '2026-01-01', 13000, 2600, 2600);

-- 插入培训数据
INSERT INTO training (id, employee_id, training_name, start_date, end_date, completion_status, score) VALUES (1, 2, 'Java高级开发', '2026-02-01', '2026-02-15', '完成', 95);
INSERT INTO training (id, employee_id, training_name, start_date, end_date, completion_status, score) VALUES (2, 6, 'Python数据分析', '2026-02-01', '2026-02-15', '完成', 90);
INSERT INTO training (id, employee_id, training_name, start_date, end_date, completion_status, score) VALUES (3, 3, '市场营销策略', '2026-02-01', '2026-02-15', '完成', 85);
INSERT INTO training (id, employee_id, training_name, start_date, end_date, completion_status, score) VALUES (4, 8, '销售技巧', '2026-02-01', '2026-02-15', '完成', 88);

-- 创建第二个数据库：企业客户关系管理系统
CREATE DATABASE crm_system;

-- 使用crm_system数据库
USE crm_system;

-- 创建客户表
CREATE TABLE customers (
    id INT,
    customer_id STRING,
    company_name STRING,
    contact_name STRING,
    contact_title STRING,
    phone STRING,
    email STRING,
    address STRING,
    city STRING,
    country STRING,
    status STRING,
    create_date STRING
);

-- 创建联系人表
CREATE TABLE contacts (
    id INT,
    customer_id INT,
    contact_name STRING,
    contact_title STRING,
    phone STRING,
    email STRING,
    notes STRING
);

-- 创建商机表
CREATE TABLE opportunities (
    id INT,
    opportunity_id STRING,
    customer_id INT,
    title STRING,
    description STRING,
    amount DOUBLE,
    probability DOUBLE,
    stage STRING,
    expected_close_date STRING,
    sales_rep_id INT,
    create_date STRING
);

-- 创建活动表
CREATE TABLE activities (
    id INT,
    activity_type STRING,
    related_to STRING,
    related_id INT,
    subject STRING,
    description STRING,
    start_date STRING,
    end_date STRING,
    assigned_to INT,
    status STRING
);

-- 创建销售订单表
CREATE TABLE sales_orders (
    id INT,
    order_id STRING,
    customer_id INT,
    order_date STRING,
    total_amount DOUBLE,
    status STRING,
    sales_rep_id INT
);

-- 插入客户数据
INSERT INTO customers (id, customer_id, company_name, contact_name, contact_title, phone, email, address, city, country, status, create_date) VALUES (1, 'CUST001', '阿里巴巴集团', '马云', 'CEO', '0571-88888888', 'info@alibaba.com', '杭州市余杭区文一西路969号', '杭州', '中国', 'active', '2026-01-01');
INSERT INTO customers (id, customer_id, company_name, contact_name, contact_title, phone, email, address, city, country, status, create_date) VALUES (2, 'CUST002', '腾讯控股', '马化腾', 'CEO', '0755-86013388', 'info@tencent.com', '深圳市南山区科技园', '深圳', '中国', 'active', '2026-01-02');
INSERT INTO customers (id, customer_id, company_name, contact_name, contact_title, phone, email, address, city, country, status, create_date) VALUES (3, 'CUST003', '百度公司', '李彦宏', 'CEO', '010-59928888', 'info@baidu.com', '北京市海淀区百度大厦', '北京', '中国', 'active', '2026-01-03');
INSERT INTO customers (id, customer_id, company_name, contact_name, contact_title, phone, email, address, city, country, status, create_date) VALUES (4, 'CUST004', '京东集团', '刘强东', 'CEO', '010-88888888', 'info@jd.com', '北京市朝阳区京东大厦', '北京', '中国', 'active', '2026-01-04');
INSERT INTO customers (id, customer_id, company_name, contact_name, contact_title, phone, email, address, city, country, status, create_date) VALUES (5, 'CUST005', '小米科技', '雷军', 'CEO', '010-60606666', 'info@xiaomi.com', '北京市海淀区小米科技园', '北京', '中国', 'active', '2026-01-05');

-- 插入联系人数据
INSERT INTO contacts (id, customer_id, contact_name, contact_title, phone, email, notes) VALUES (1, 1, '蔡崇信', 'CFO', '0571-88888889', 'caicx@alibaba.com', '阿里巴巴集团CFO');
INSERT INTO contacts (id, customer_id, contact_name, contact_title, phone, email, notes) VALUES (2, 2, '刘胜义', 'COO', '0755-86013389', 'liusy@tencent.com', '腾讯控股COO');
INSERT INTO contacts (id, customer_id, contact_name, contact_title, phone, email, notes) VALUES (3, 3, '陆奇', 'CTO', '010-59928889', 'luqi@baidu.com', '百度公司CTO');
INSERT INTO contacts (id, customer_id, contact_name, contact_title, phone, email, notes) VALUES (4, 4, '沈皓瑜', 'COO', '010-88888889', 'shenhy@jd.com', '京东集团COO');
INSERT INTO contacts (id, customer_id, contact_name, contact_title, phone, email, notes) VALUES (5, 5, '林斌', '联合创始人', '010-60606667', 'linbin@xiaomi.com', '小米科技联合创始人');

-- 插入商机数据
INSERT INTO opportunities (id, opportunity_id, customer_id, title, description, amount, probability, stage, expected_close_date, sales_rep_id, create_date) VALUES (1, 'OPP001', 1, '阿里巴巴云计算服务', '提供企业级云计算服务', 1000000, 0.8, '谈判中', '2026-03-31', 1, '2026-02-01');
INSERT INTO opportunities (id, opportunity_id, customer_id, title, description, amount, probability, stage, expected_close_date, sales_rep_id, create_date) VALUES (2, 'OPP002', 2, '腾讯云存储服务', '提供云存储解决方案', 800000, 0.7, '提案中', '2026-04-15', 2, '2026-02-02');
INSERT INTO opportunities (id, opportunity_id, customer_id, title, description, amount, probability, stage, expected_close_date, sales_rep_id, create_date) VALUES (3, 'OPP003', 3, '百度搜索推广', '提供搜索推广服务', 500000, 0.9, '已成交', '2026-03-15', 3, '2026-02-03');
INSERT INTO opportunities (id, opportunity_id, customer_id, title, description, amount, probability, stage, expected_close_date, sales_rep_id, create_date) VALUES (4, 'OPP004', 4, '京东物流服务', '提供企业物流解决方案', 1200000, 0.6, '初步接触', '2026-05-01', 4, '2026-02-04');
INSERT INTO opportunities (id, opportunity_id, customer_id, title, description, amount, probability, stage, expected_close_date, sales_rep_id, create_date) VALUES (5, 'OPP005', 5, '小米智能硬件', '提供智能硬件解决方案', 600000, 0.75, '提案中', '2026-04-30', 5, '2026-02-05');

-- 插入活动数据
INSERT INTO activities (id, activity_type, related_to, related_id, subject, description, start_date, end_date, assigned_to, status) VALUES (1, '会议', 'customer', 1, '阿里巴巴合作洽谈', '讨论云计算服务合作', '2026-02-10', '2026-02-10', 1, '已完成');
INSERT INTO activities (id, activity_type, related_to, related_id, subject, description, start_date, end_date, assigned_to, status) VALUES (2, '电话', 'customer', 2, '腾讯云服务跟进', '跟进云存储服务需求', '2026-02-11', '2026-02-11', 2, '已完成');
INSERT INTO activities (id, activity_type, related_to, related_id, subject, description, start_date, end_date, assigned_to, status) VALUES (3, '邮件', 'opportunity', 3, '百度搜索推广方案', '发送推广方案', '2026-02-12', '2026-02-12', 3, '已完成');
INSERT INTO activities (id, activity_type, related_to, related_id, subject, description, start_date, end_date, assigned_to, status) VALUES (4, '会议', 'opportunity', 4, '京东物流方案讨论', '讨论物流解决方案', '2026-02-13', '2026-02-13', 4, '已完成');
INSERT INTO activities (id, activity_type, related_to, related_id, subject, description, start_date, end_date, assigned_to, status) VALUES (5, '电话', 'customer', 5, '小米智能硬件需求', '了解智能硬件需求', '2026-02-14', '2026-02-14', 5, '已完成');

-- 插入销售订单数据
INSERT INTO sales_orders (id, order_id, customer_id, order_date, total_amount, status, sales_rep_id) VALUES (1, 'SO001', 3, '2026-03-01', 500000, '已完成', 3);
INSERT INTO sales_orders (id, order_id, customer_id, order_date, total_amount, status, sales_rep_id) VALUES (2, 'SO002', 1, '2026-03-10', 1000000, '处理中', 1);
INSERT INTO sales_orders (id, order_id, customer_id, order_date, total_amount, status, sales_rep_id) VALUES (3, 'SO003', 2, '2026-03-15', 800000, '处理中', 2);

-- 创建第三个数据库：企业项目管理系统
CREATE DATABASE project_management;

-- 使用project_management数据库
USE project_management;

-- 创建项目表
CREATE TABLE projects (
    id INT,
    project_id STRING,
    project_name STRING,
    description STRING,
    start_date STRING,
    end_date STRING,
    status STRING,
    budget DOUBLE,
    manager_id INT
);

-- 创建任务表
CREATE TABLE tasks (
    id INT,
    task_id STRING,
    project_id INT,
    task_name STRING,
    description STRING,
    start_date STRING,
    end_date STRING,
    status STRING,
    assigned_to INT,
    priority STRING
);

-- 创建资源表
CREATE TABLE resources (
    id INT,
    resource_id STRING,
    resource_name STRING,
    resource_type STRING,
    availability STRING,
    cost DOUBLE
);

-- 创建项目资源分配表
CREATE TABLE project_resources (
    id INT,
    project_id INT,
    resource_id INT,
    allocation_date STRING,
    quantity INT,
    cost DOUBLE
);

-- 创建项目团队表
CREATE TABLE project_team (
    id INT,
    project_id INT,
    employee_id INT,
    role STRING,
    join_date STRING,
    leave_date STRING
);

-- 插入项目数据
INSERT INTO projects (id, project_id, project_name, description, start_date, end_date, status, budget, manager_id) VALUES (1, 'PROJ001', '企业官网重构', '对企业官网进行全面重构', '2026-01-01', '2026-03-31', '进行中', 500000, 1);
INSERT INTO projects (id, project_id, project_name, description, start_date, end_date, status, budget, manager_id) VALUES (2, 'PROJ002', '移动应用开发', '开发企业移动应用', '2026-02-01', '2026-06-30', '进行中', 800000, 2);
INSERT INTO projects (id, project_id, project_name, description, start_date, end_date, status, budget, manager_id) VALUES (3, 'PROJ003', '数据分析平台', '构建企业数据分析平台', '2026-03-01', '2026-09-30', '进行中', 1000000, 3);

-- 插入任务数据
INSERT INTO tasks (id, task_id, project_id, task_name, description, start_date, end_date, status, assigned_to, priority) VALUES (1, 'TASK001', 1, '需求分析', '分析官网重构需求', '2026-01-01', '2026-01-15', '已完成', 1, '高');
INSERT INTO tasks (id, task_id, project_id, task_name, description, start_date, end_date, status, assigned_to, priority) VALUES (2, 'TASK002', 1, '设计阶段', '设计官网UI/UX', '2026-01-16', '2026-02-15', '已完成', 2, '高');
INSERT INTO tasks (id, task_id, project_id, task_name, description, start_date, end_date, status, assigned_to, priority) VALUES (3, 'TASK003', 1, '开发阶段', '开发官网前端', '2026-02-16', '2026-03-15', '进行中', 3, '高');
INSERT INTO tasks (id, task_id, project_id, task_name, description, start_date, end_date, status, assigned_to, priority) VALUES (4, 'TASK004', 2, '需求分析', '分析移动应用需求', '2026-02-01', '2026-02-15', '已完成', 4, '高');
INSERT INTO tasks (id, task_id, project_id, task_name, description, start_date, end_date, status, assigned_to, priority) VALUES (5, 'TASK005', 2, '设计阶段', '设计移动应用UI/UX', '2026-02-16', '2026-03-15', '进行中', 5, '高');

-- 插入资源数据
INSERT INTO resources (id, resource_id, resource_name, resource_type, availability, cost) VALUES (1, 'RES001', '服务器', '硬件', '可用', 10000);
INSERT INTO resources (id, resource_id, resource_name, resource_type, availability, cost) VALUES (2, 'RES002', '数据库', '软件', '可用', 5000);
INSERT INTO resources (id, resource_id, resource_name, resource_type, availability, cost) VALUES (3, 'RES003', '开发工具', '软件', '可用', 2000);
INSERT INTO resources (id, resource_id, resource_name, resource_type, availability, cost) VALUES (4, 'RES004', '测试环境', '环境', '可用', 3000);

-- 插入项目资源分配数据
INSERT INTO project_resources (id, project_id, resource_id, allocation_date, quantity, cost) VALUES (1, 1, 1, '2026-01-01', 2, 20000);
INSERT INTO project_resources (id, project_id, resource_id, allocation_date, quantity, cost) VALUES (2, 1, 2, '2026-01-01', 1, 5000);
INSERT INTO project_resources (id, project_id, resource_id, allocation_date, quantity, cost) VALUES (3, 2, 1, '2026-02-01', 3, 30000);
INSERT INTO project_resources (id, project_id, resource_id, allocation_date, quantity, cost) VALUES (4, 2, 3, '2026-02-01', 5, 10000);
INSERT INTO project_resources (id, project_id, resource_id, allocation_date, quantity, cost) VALUES (5, 3, 1, '2026-03-01', 4, 40000);

-- 插入项目团队数据
INSERT INTO project_team (id, project_id, employee_id, role, join_date, leave_date) VALUES (1, 1, 1, '项目经理', '2026-01-01', NULL);
INSERT INTO project_team (id, project_id, employee_id, role, join_date, leave_date) VALUES (2, 1, 2, 'UI设计师', '2026-01-01', NULL);
INSERT INTO project_team (id, project_id, employee_id, role, join_date, leave_date) VALUES (3, 1, 3, '前端开发', '2026-01-01', NULL);
INSERT INTO project_team (id, project_id, employee_id, role, join_date, leave_date) VALUES (4, 2, 4, '项目经理', '2026-02-01', NULL);
INSERT INTO project_team (id, project_id, employee_id, role, join_date, leave_date) VALUES (5, 2, 5, 'UI设计师', '2026-02-01', NULL);

-- 在hr_management数据库中进行表链接操作
USE hr_management;

-- 链接员工表和部门表
LINK TABLE FROM hr_management.employees to hr_management.departments new emp_dept;

-- 链接结果表和薪资表
LINK TABLE FROM hr_management.emp_dept to hr_management.salaries new emp_dept_salary;

-- 链接结果表和考勤表
LINK TABLE FROM hr_management.emp_dept_salary to hr_management.attendance new emp_all;

-- 显示所有数据库
SHOW DATABASES;

-- 显示hr_management数据库中的所有表
USE hr_management;
SHOW TABLES;

-- 显示表结构
SHOW STRUCT FROM  hr_management.employees;
SHOW STRUCT FROM  hr_management.departments;
SHOW STRUCT FROM  hr_management.salaries;
SHOW STRUCT FROM  hr_management.attendance;

-- 显示表数据

SELECT * FROM hr_management.employees;
SELECT * FROM hr_management.departments;
SELECT * FROM hr_management.salaries;
SELECT * FROM hr_management.attendance;

-- 显示链接后的表数据
SELECT * FROM hr_management.emp_all;
