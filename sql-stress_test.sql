-- 压力测试 SQL 文件
-- 创建压力测试数据库
CREATE DATABASE stress_test;

-- 使用压力测试数据库
USE stress_test;

-- 创建用户表（模拟 1000 个用户）
CREATE TABLE users (
    id INT,
    username STRING,
    email STRING,
    age INT,
    city STRING,
    country STRING,
    register_date STRING,
    is_active BOOL
);

-- 创建订单表（模拟 5000 个订单）
CREATE TABLE orders (
    id INT,
    user_id INT,
    product_name STRING,
    quantity INT,
    price DOUBLE,
    order_date STRING,
    status STRING
);

-- 创建产品表（模拟 500 个产品）
CREATE TABLE products (
    id INT,
    name STRING,
    category STRING,
    price DOUBLE,
    stock INT,
    description STRING
);

-- 创建日志表（模拟 10000 条日志）
CREATE TABLE logs (
    id INT,
    level STRING,
    message STRING,
    timestamp STRING,
    source STRING
);

-- 插入 100 个用户数据
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (1, 'user001', 'user001@test.com', 25, 'New York', 'USA', '2026-01-01', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (2, 'user002', 'user002@test.com', 30, 'Los Angeles', 'USA', '2026-01-02', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (3, 'user003', 'user003@test.com', 22, 'Chicago', 'USA', '2026-01-03', false);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (4, 'user004', 'user004@test.com', 28, 'Houston', 'USA', '2026-01-04', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (5, 'user005', 'user005@test.com', 35, 'Phoenix', 'USA', '2026-01-05', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (6, 'user006', 'user006@test.com', 27, 'Philadelphia', 'USA', '2026-01-06', false);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (7, 'user007', 'user007@test.com', 31, 'San Antonio', 'USA', '2026-01-07', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (8, 'user008', 'user008@test.com', 24, 'San Diego', 'USA', '2026-01-08', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (9, 'user009', 'user009@test.com', 29, 'Dallas', 'USA', '2026-01-09', false);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (10, 'user010', 'user010@test.com', 33, 'San Jose', 'USA', '2026-01-10', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (11, 'user011', 'user011@test.com', 26, 'Austin', 'USA', '2026-01-11', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (12, 'user012', 'user012@test.com', 32, 'Jacksonville', 'USA', '2026-01-12', false);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (13, 'user013', 'user013@test.com', 23, 'Fort Worth', 'USA', '2026-01-13', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (14, 'user014', 'user014@test.com', 36, 'Columbus', 'USA', '2026-01-14', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (15, 'user015', 'user015@test.com', 21, 'Charlotte', 'USA', '2026-01-15', false);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (16, 'user016', 'user016@test.com', 34, 'San Francisco', 'USA', '2026-01-16', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (17, 'user017', 'user017@test.com', 25, 'Indianapolis', 'USA', '2026-01-17', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (18, 'user018', 'user018@test.com', 30, 'Seattle', 'USA', '2026-01-18', false);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (19, 'user019', 'user019@test.com', 28, 'Denver', 'USA', '2026-01-19', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (20, 'user020', 'user020@test.com', 27, 'Washington', 'USA', '2026-01-20', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (21, 'user021', 'user021@test.com', 31, 'Boston', 'USA', '2026-01-21', false);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (22, 'user022', 'user022@test.com', 24, 'El Paso', 'USA', '2026-01-22', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (23, 'user023', 'user023@test.com', 29, 'Nashville', 'USA', '2026-01-23', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (24, 'user024', 'user024@test.com', 33, 'Detroit', 'USA', '2026-01-24', false);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (25, 'user025', 'user025@test.com', 26, 'Oklahoma City', 'USA', '2026-01-25', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (26, 'user026', 'user026@test.com', 32, 'Portland', 'USA', '2026-01-26', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (27, 'user027', 'user027@test.com', 23, 'Las Vegas', 'USA', '2026-01-27', false);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (28, 'user028', 'user028@test.com', 36, 'Louisville', 'USA', '2026-01-28', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (29, 'user029', 'user029@test.com', 21, 'Baltimore', 'USA', '2026-01-29', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (30, 'user030', 'user030@test.com', 34, 'Milwaukee', 'USA', '2026-01-30', false);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (31, 'user031', 'user031@test.com', 25, 'Albuquerque', 'USA', '2026-01-31', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (32, 'user032', 'user032@test.com', 30, 'Tucson', 'USA', '2026-02-01', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (33, 'user033', 'user033@test.com', 22, 'Fresno', 'USA', '2026-02-02', false);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (34, 'user034', 'user034@test.com', 28, 'Mesa', 'USA', '2026-02-03', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (35, 'user035', 'user035@test.com', 35, 'Sacramento', 'USA', '2026-02-04', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (36, 'user036', 'user036@test.com', 27, 'Atlanta', 'USA', '2026-02-05', false);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (37, 'user037', 'user037@test.com', 31, 'Kansas City', 'USA', '2026-02-06', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (38, 'user038', 'user038@test.com', 24, 'Colorado Springs', 'USA', '2026-02-07', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (39, 'user039', 'user039@test.com', 29, 'Omaha', 'USA', '2026-02-08', false);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (40, 'user040', 'user040@test.com', 33, 'Raleigh', 'USA', '2026-02-09', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (41, 'user041', 'user041@test.com', 26, 'Miami', 'USA', '2026-02-10', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (42, 'user042', 'user042@test.com', 32, 'Long Beach', 'USA', '2026-02-11', false);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (43, 'user043', 'user043@test.com', 23, 'Virginia Beach', 'USA', '2026-02-12', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (44, 'user044', 'user044@test.com', 36, 'Oakland', 'USA', '2026-02-13', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (45, 'user045', 'user045@test.com', 21, 'Minneapolis', 'USA', '2026-02-14', false);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (46, 'user046', 'user046@test.com', 34, 'Tulsa', 'USA', '2026-02-15', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (47, 'user047', 'user047@test.com', 25, 'Arlington', 'USA', '2026-02-16', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (48, 'user048', 'user048@test.com', 30, 'New Orleans', 'USA', '2026-02-17', false);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (49, 'user049', 'user049@test.com', 28, 'Wichita', 'USA', '2026-02-18', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (50, 'user050', 'user050@test.com', 27, 'Cleveland', 'USA', '2026-02-19', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (51, 'user051', 'user051@test.com', 31, 'Tampa', 'USA', '2026-02-20', false);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (52, 'user052', 'user052@test.com', 24, 'Bakersfield', 'USA', '2026-02-21', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (53, 'user053', 'user053@test.com', 29, 'Aurora', 'USA', '2026-02-22', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (54, 'user054', 'user054@test.com', 33, 'Anaheim', 'USA', '2026-02-23', false);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (55, 'user055', 'user055@test.com', 26, 'Honolulu', 'USA', '2026-02-24', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (56, 'user056', 'user056@test.com', 32, 'Santa Ana', 'USA', '2026-02-25', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (57, 'user057', 'user057@test.com', 23, 'Riverside', 'USA', '2026-02-26', false);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (58, 'user058', 'user058@test.com', 36, 'Corpus Christi', 'USA', '2026-02-27', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (59, 'user059', 'user059@test.com', 21, 'Lexington', 'USA', '2026-02-28', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (60, 'user060', 'user060@test.com', 34, 'Henderson', 'USA', '2026-03-01', false);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (61, 'user061', 'user061@test.com', 25, 'Stockton', 'USA', '2026-03-02', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (62, 'user062', 'user062@test.com', 30, 'Saint Paul', 'USA', '2026-03-03', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (63, 'user063', 'user063@test.com', 22, 'Cincinnati', 'USA', '2026-03-04', false);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (64, 'user064', 'user064@test.com', 28, 'St. Louis', 'USA', '2026-03-05', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (65, 'user065', 'user065@test.com', 35, 'Pittsburgh', 'USA', '2026-03-06', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (66, 'user066', 'user066@test.com', 27, 'Greensboro', 'USA', '2026-03-07', false);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (67, 'user067', 'user067@test.com', 31, 'Lincoln', 'USA', '2026-03-08', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (68, 'user068', 'user068@test.com', 24, 'Anchorage', 'USA', '2026-03-09', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (69, 'user069', 'user069@test.com', 29, 'Plano', 'USA', '2026-03-10', false);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (70, 'user070', 'user070@test.com', 33, 'Orlando', 'USA', '2026-03-11', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (71, 'user071', 'user071@test.com', 26, 'Irvine', 'USA', '2026-03-12', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (72, 'user072', 'user072@test.com', 32, 'Newark', 'USA', '2026-03-13', false);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (73, 'user073', 'user073@test.com', 23, 'Durham', 'USA', '2026-03-14', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (74, 'user074', 'user074@test.com', 36, 'Chula Vista', 'USA', '2026-03-15', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (75, 'user075', 'user075@test.com', 21, 'Toledo', 'USA', '2026-03-16', false);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (76, 'user076', 'user076@test.com', 34, 'Fort Wayne', 'USA', '2026-03-17', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (77, 'user077', 'user077@test.com', 25, 'St. Petersburg', 'USA', '2026-03-18', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (78, 'user078', 'user078@test.com', 30, 'Laredo', 'USA', '2026-03-19', false);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (79, 'user079', 'user079@test.com', 28, 'Jersey City', 'USA', '2026-03-20', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (80, 'user080', 'user080@test.com', 27, 'Chandler', 'USA', '2026-03-21', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (81, 'user081', 'user081@test.com', 31, 'Madison', 'USA', '2026-03-22', false);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (82, 'user082', 'user082@test.com', 24, 'Lubbock', 'USA', '2026-03-23', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (83, 'user083', 'user083@test.com', 29, 'Scottsdale', 'USA', '2026-03-24', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (84, 'user084', 'user084@test.com', 33, 'Reno', 'USA', '2026-03-25', false);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (85, 'user085', 'user085@test.com', 26, 'Buffalo', 'USA', '2026-03-26', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (86, 'user086', 'user086@test.com', 32, 'Gilbert', 'USA', '2026-03-27', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (87, 'user087', 'user087@test.com', 23, 'Glendale', 'USA', '2026-03-28', false);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (88, 'user088', 'user088@test.com', 36, 'North Las Vegas', 'USA', '2026-03-29', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (89, 'user089', 'user089@test.com', 21, 'Winston-Salem', 'USA', '2026-03-30', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (90, 'user090', 'user090@test.com', 34, 'Chesapeake', 'USA', '2026-03-31', false);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (91, 'user091', 'user091@test.com', 25, 'Norfolk', 'USA', '2026-04-01', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (92, 'user092', 'user092@test.com', 30, 'Fremont', 'USA', '2026-04-02', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (93, 'user093', 'user093@test.com', 22, 'Garland', 'USA', '2026-04-03', false);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (94, 'user094', 'user094@test.com', 28, 'Irving', 'USA', '2026-04-04', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (95, 'user095', 'user095@test.com', 35, 'Hialeah', 'USA', '2026-04-05', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (96, 'user096', 'user096@test.com', 27, 'Richmond', 'USA', '2026-04-06', false);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (97, 'user097', 'user097@test.com', 31, 'Boise', 'USA', '2026-04-07', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (98, 'user098', 'user098@test.com', 24, 'Spokane', 'USA', '2026-04-08', true);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (99, 'user099', 'user099@test.com', 29, 'Baton Rouge', 'USA', '2026-04-09', false);
INSERT INTO users (id, username, email, age, city, country, register_date, is_active) VALUES (100, 'user100', 'user100@test.com', 33, 'Des Moines', 'USA', '2026-04-10', true);

-- 插入 50 个订单数据
INSERT INTO orders (id, user_id, product_name, quantity, price, order_date, status) VALUES (1, 1, 'Laptop Pro', 1, 1299.99, '2026-03-01', 'completed');
INSERT INTO orders (id, user_id, product_name, quantity, price, order_date, status) VALUES (2, 2, 'Wireless Mouse', 2, 49.99, '2026-03-02', 'completed');
INSERT INTO orders (id, user_id, product_name, quantity, price, order_date, status) VALUES (3, 3, 'USB Cable', 5, 9.99, '2026-03-03', 'pending');
INSERT INTO orders (id, user_id, product_name, quantity, price, order_date, status) VALUES (4, 4, 'Monitor 4K', 1, 399.99, '2026-03-04', 'completed');
INSERT INTO orders (id, user_id, product_name, quantity, price, order_date, status) VALUES (5, 5, 'Keyboard', 1, 79.99, '2026-03-05', 'shipped');
INSERT INTO orders (id, user_id, product_name, quantity, price, order_date, status) VALUES (6, 6, 'Webcam HD', 1, 59.99, '2026-03-06', 'completed');
INSERT INTO orders (id, user_id, product_name, quantity, price, order_date, status) VALUES (7, 7, 'Headphones', 2, 129.99, '2026-03-07', 'pending');
INSERT INTO orders (id, user_id, product_name, quantity, price, order_date, status) VALUES (8, 8, 'SSD 1TB', 1, 89.99, '2026-03-08', 'completed');
INSERT INTO orders (id, user_id, product_name, quantity, price, order_date, status) VALUES (9, 9, 'RAM 32GB', 2, 149.99, '2026-03-09', 'shipped');
INSERT INTO orders (id, user_id, product_name, quantity, price, order_date, status) VALUES (10, 10, 'Graphics Card', 1, 699.99, '2026-03-10', 'completed');
INSERT INTO orders (id, user_id, product_name, quantity, price, order_date, status) VALUES (11, 11, 'Power Supply', 1, 119.99, '2026-03-11', 'pending');
INSERT INTO orders (id, user_id, product_name, quantity, price, order_date, status) VALUES (12, 12, 'CPU Cooler', 1, 79.99, '2026-03-12', 'completed');
INSERT INTO orders (id, user_id, product_name, quantity, price, order_date, status) VALUES (13, 13, 'Case Fan', 3, 15.99, '2026-03-13', 'shipped');
INSERT INTO orders (id, user_id, product_name, quantity, price, order_date, status) VALUES (14, 14, 'Thermal Paste', 2, 9.99, '2026-03-14', 'completed');
INSERT INTO orders (id, user_id, product_name, quantity, price, order_date, status) VALUES (15, 15, 'Cable Management', 1, 24.99, '2026-03-15', 'pending');
INSERT INTO orders (id, user_id, product_name, quantity, price, order_date, status) VALUES (16, 16, 'Desk Lamp', 1, 34.99, '2026-03-16', 'completed');
INSERT INTO orders (id, user_id, product_name, quantity, price, order_date, status) VALUES (17, 17, 'Phone Stand', 2, 12.99, '2026-03-17', 'shipped');
INSERT INTO orders (id, user_id, product_name, quantity, price, order_date, status) VALUES (18, 18, 'Tablet', 1, 499.99, '2026-03-18', 'completed');
INSERT INTO orders (id, user_id, product_name, quantity, price, order_date, status) VALUES (19, 19, 'Smart Watch', 1, 299.99, '2026-03-19', 'pending');
INSERT INTO orders (id, user_id, product_name, quantity, price, order_date, status) VALUES (20, 20, 'Earbuds', 2, 79.99, '2026-03-20', 'completed');
INSERT INTO orders (id, user_id, product_name, quantity, price, order_date, status) VALUES (21, 21, 'Charger', 3, 29.99, '2026-03-21', 'shipped');
INSERT INTO orders (id, user_id, product_name, quantity, price, order_date, status) VALUES (22, 22, 'Power Bank', 1, 49.99, '2026-03-22', 'completed');
INSERT INTO orders (id, user_id, product_name, quantity, price, order_date, status) VALUES (23, 23, 'Screen Protector', 4, 9.99, '2026-03-23', 'pending');
INSERT INTO orders (id, user_id, product_name, quantity, price, order_date, status) VALUES (24, 24, 'Phone Case', 2, 19.99, '2026-03-24', 'completed');
INSERT INTO orders (id, user_id, product_name, quantity, price, order_date, status) VALUES (25, 25, 'Car Mount', 1, 24.99, '2026-03-25', 'shipped');
INSERT INTO orders (id, user_id, product_name, quantity, price, order_date, status) VALUES (26, 26, 'Bluetooth Speaker', 1, 89.99, '2026-03-26', 'completed');
INSERT INTO orders (id, user_id, product_name, quantity, price, order_date, status) VALUES (27, 27, 'Projector', 1, 399.99, '2026-03-27', 'pending');
INSERT INTO orders (id, user_id, product_name, quantity, price, order_date, status) VALUES (28, 28, 'VR Headset', 1, 599.99, '2026-03-28', 'completed');
INSERT INTO orders (id, user_id, product_name, quantity, price, order_date, status) VALUES (29, 29, 'Drone', 1, 899.99, '2026-03-29', 'shipped');
INSERT INTO orders (id, user_id, product_name, quantity, price, order_date, status) VALUES (30, 30, 'Camera', 1, 1299.99, '2026-03-30', 'completed');
INSERT INTO orders (id, user_id, product_name, quantity, price, order_date, status) VALUES (31, 31, 'Lens', 2, 499.99, '2026-03-31', 'pending');
INSERT INTO orders (id, user_id, product_name, quantity, price, order_date, status) VALUES (32, 32, 'Tripod', 1, 79.99, '2026-04-01', 'completed');
INSERT INTO orders (id, user_id, product_name, quantity, price, order_date, status) VALUES (33, 33, 'Memory Card', 3, 29.99, '2026-04-02', 'shipped');
INSERT INTO orders (id, user_id, product_name, quantity, price, order_date, status) VALUES (34, 34, 'External HDD', 1, 79.99, '2026-04-03', 'completed');
INSERT INTO orders (id, user_id, product_name, quantity, price, order_date, status) VALUES (35, 35, 'NAS Drive', 1, 299.99, '2026-04-04', 'pending');
INSERT INTO orders (id, user_id, product_name, quantity, price, order_date, status) VALUES (36, 36, 'Router', 1, 149.99, '2026-04-05', 'completed');
INSERT INTO orders (id, user_id, product_name, quantity, price, order_date, status) VALUES (37, 37, 'Switch', 1, 49.99, '2026-04-06', 'shipped');
INSERT INTO orders (id, user_id, product_name, quantity, price, order_date, status) VALUES (38, 38, 'Access Point', 2, 89.99, '2026-04-07', 'completed');
INSERT INTO orders (id, user_id, product_name, quantity, price, order_date, status) VALUES (39, 39, 'Network Cable', 10, 4.99, '2026-04-08', 'pending');
INSERT INTO orders (id, user_id, product_name, quantity, price, order_date, status) VALUES (40, 40, 'Patch Panel', 1, 39.99, '2026-04-09', 'completed');
INSERT INTO orders (id, user_id, product_name, quantity, price, order_date, status) VALUES (41, 41, 'Server Rack', 1, 199.99, '2026-04-10', 'shipped');
INSERT INTO orders (id, user_id, product_name, quantity, price, order_date, status) VALUES (42, 42, 'UPS', 1, 249.99, '2026-04-11', 'completed');
INSERT INTO orders (id, user_id, product_name, quantity, price, order_date, status) VALUES (43, 43, 'Surge Protector', 2, 29.99, '2026-04-12', 'pending');
INSERT INTO orders (id, user_id, product_name, quantity, price, order_date, status) VALUES (44, 44, 'Desk', 1, 399.99, '2026-04-13', 'completed');
INSERT INTO orders (id, user_id, product_name, quantity, price, order_date, status) VALUES (45, 45, 'Chair', 1, 299.99, '2026-04-14', 'shipped');
INSERT INTO orders (id, user_id, product_name, quantity, price, order_date, status) VALUES (46, 46, 'Monitor Arm', 2, 89.99, '2026-04-15', 'completed');
INSERT INTO orders (id, user_id, product_name, quantity, price, order_date, status) VALUES (47, 47, 'Desk Mat', 1, 24.99, '2026-04-16', 'pending');
INSERT INTO orders (id, user_id, product_name, quantity, price, order_date, status) VALUES (48, 48, 'Pen Holder', 3, 9.99, '2026-04-17', 'completed');
INSERT INTO orders (id, user_id, product_name, quantity, price, order_date, status) VALUES (49, 49, 'Notebook', 5, 5.99, '2026-04-18', 'shipped');
INSERT INTO orders (id, user_id, product_name, quantity, price, order_date, status) VALUES (50, 50, 'Stapler', 1, 12.99, '2026-04-19', 'completed');

-- 插入 30 个产品数据
INSERT INTO products (id, name, category, price, stock, description) VALUES (1, 'Laptop Pro', 'Electronics', 1299.99, 50, 'High performance laptop');
INSERT INTO products (id, name, category, price, stock, description) VALUES (2, 'Wireless Mouse', 'Accessories', 49.99, 200, 'Ergonomic wireless mouse');
INSERT INTO products (id, name, category, price, stock, description) VALUES (3, 'USB Cable', 'Accessories', 9.99, 500, 'USB-C to USB-A cable');
INSERT INTO products (id, name, category, price, stock, description) VALUES (4, 'Monitor 4K', 'Electronics', 399.99, 30, '27 inch 4K display');
INSERT INTO products (id, name, category, price, stock, description) VALUES (5, 'Mechanical Keyboard', 'Accessories', 79.99, 100, 'RGB mechanical keyboard');
INSERT INTO products (id, name, category, price, stock, description) VALUES (6, 'Webcam HD', 'Electronics', 59.99, 150, '1080p webcam');
INSERT INTO products (id, name, category, price, stock, description) VALUES (7, 'Noise Cancelling Headphones', 'Audio', 129.99, 80, 'Over-ear headphones');
INSERT INTO products (id, name, category, price, stock, description) VALUES (8, 'SSD 1TB', 'Storage', 89.99, 200, 'NVMe SSD');
INSERT INTO products (id, name, category, price, stock, description) VALUES (9, 'RAM 32GB', 'Components', 149.99, 100, 'DDR4 memory');
INSERT INTO products (id, name, category, price, stock, description) VALUES (10, 'Graphics Card', 'Components', 699.99, 20, 'RTX 4070 GPU');
INSERT INTO products (id, name, category, price, stock, description) VALUES (11, 'Power Supply 750W', 'Components', 119.99, 60, 'Modular PSU');
INSERT INTO products (id, name, category, price, stock, description) VALUES (12, 'CPU Cooler', 'Components', 79.99, 80, 'Liquid cooling');
INSERT INTO products (id, name, category, price, stock, description) VALUES (13, 'Case Fan', 'Components', 15.99, 300, '120mm RGB fan');
INSERT INTO products (id, name, category, price, stock, description) VALUES (14, 'Thermal Paste', 'Components', 9.99, 500, 'High performance paste');
INSERT INTO products (id, name, category, price, stock, description) VALUES (15, 'Cable Management Kit', 'Accessories', 24.99, 150, 'Cable ties and organizers');
INSERT INTO products (id, name, category, price, stock, description) VALUES (16, 'LED Desk Lamp', 'Furniture', 34.99, 100, 'Adjustable desk lamp');
INSERT INTO products (id, name, category, price, stock, description) VALUES (17, 'Phone Stand', 'Accessories', 12.99, 400, 'Adjustable phone holder');
INSERT INTO products (id, name, category, price, stock, description) VALUES (18, 'Tablet Pro', 'Electronics', 499.99, 40, '12 inch tablet');
INSERT INTO products (id, name, category, price, stock, description) VALUES (19, 'Smart Watch', 'Wearables', 299.99, 60, 'Fitness tracker');
INSERT INTO products (id, name, category, price, stock, description) VALUES (20, 'Wireless Earbuds', 'Audio', 79.99, 150, 'Bluetooth earbuds');
INSERT INTO products (id, name, category, price, stock, description) VALUES (21, 'Fast Charger', 'Accessories', 29.99, 300, '65W USB-C charger');
INSERT INTO products (id, name, category, price, stock, description) VALUES (22, 'Power Bank 20000mAh', 'Accessories', 49.99, 200, 'Portable charger');
INSERT INTO products (id, name, category, price, stock, description) VALUES (23, 'Screen Protector', 'Accessories', 9.99, 1000, 'Tempered glass');
INSERT INTO products (id, name, category, price, stock, description) VALUES (24, 'Phone Case', 'Accessories', 19.99, 500, 'Protective case');
INSERT INTO products (id, name, category, price, stock, description) VALUES (25, 'Car Phone Mount', 'Accessories', 24.99, 300, 'Dashboard mount');
INSERT INTO products (id, name, category, price, stock, description) VALUES (26, 'Bluetooth Speaker', 'Audio', 89.99, 120, 'Portable speaker');
INSERT INTO products (id, name, category, price, stock, description) VALUES (27, 'Mini Projector', 'Electronics', 399.99, 25, '1080p projector');
INSERT INTO products (id, name, category, price, stock, description) VALUES (28, 'VR Headset', 'Electronics', 599.99, 15, 'Virtual reality');
INSERT INTO products (id, name, category, price, stock, description) VALUES (29, 'Drone 4K', 'Electronics', 899.99, 10, 'Camera drone');
INSERT INTO products (id, name, category, price, stock, description) VALUES (30, 'Digital Camera', 'Electronics', 1299.99, 20, 'Mirrorless camera');

-- 插入 100 条日志数据
INSERT INTO logs (id, level, message, timestamp, source) VALUES (1, 'INFO', 'System started successfully', '2026-03-06 08:00:00', 'main');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (2, 'INFO', 'Database connection established', '2026-03-06 08:01:00', 'db');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (3, 'WARN', 'High memory usage detected', '2026-03-06 08:05:00', 'monitor');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (4, 'ERROR', 'Failed to connect to external API', '2026-03-06 08:10:00', 'api');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (5, 'INFO', 'User login successful', '2026-03-06 08:15:00', 'auth');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (6, 'INFO', 'Data backup completed', '2026-03-06 08:20:00', 'backup');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (7, 'WARN', 'Disk space running low', '2026-03-06 08:25:00', 'monitor');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (8, 'INFO', 'Cache cleared', '2026-03-06 08:30:00', 'cache');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (9, 'ERROR', 'Database query timeout', '2026-03-06 08:35:00', 'db');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (10, 'INFO', 'New user registered', '2026-03-06 08:40:00', 'auth');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (11, 'INFO', 'Order processed', '2026-03-06 08:45:00', 'order');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (12, 'WARN', 'Slow query detected', '2026-03-06 08:50:00', 'db');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (13, 'INFO', 'Email sent successfully', '2026-03-06 08:55:00', 'email');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (14, 'ERROR', 'File upload failed', '2026-03-06 09:00:00', 'upload');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (15, 'INFO', 'Scheduled task completed', '2026-03-06 09:05:00', 'scheduler');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (16, 'INFO', 'Configuration reloaded', '2026-03-06 09:10:00', 'config');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (17, 'WARN', 'API rate limit approaching', '2026-03-06 09:15:00', 'api');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (18, 'INFO', 'User logout', '2026-03-06 09:20:00', 'auth');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (19, 'ERROR', 'Payment processing failed', '2026-03-06 09:25:00', 'payment');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (20, 'INFO', 'Report generated', '2026-03-06 09:30:00', 'report');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (21, 'INFO', 'System health check passed', '2026-03-06 09:35:00', 'health');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (22, 'WARN', 'Network latency high', '2026-03-06 09:40:00', 'network');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (23, 'INFO', 'Password changed', '2026-03-06 09:45:00', 'auth');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (24, 'ERROR', 'Invalid login attempt', '2026-03-06 09:50:00', 'security');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (25, 'INFO', 'Data export completed', '2026-03-06 09:55:00', 'export');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (26, 'INFO', 'New product added', '2026-03-06 10:00:00', 'product');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (27, 'WARN', 'Inventory low', '2026-03-06 10:05:00', 'inventory');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (28, 'INFO', 'Order shipped', '2026-03-06 10:10:00', 'shipping');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (29, 'ERROR', 'Shipping address invalid', '2026-03-06 10:15:00', 'shipping');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (30, 'INFO', 'Customer support ticket created', '2026-03-06 10:20:00', 'support');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (31, 'INFO', 'Database optimized', '2026-03-06 10:25:00', 'db');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (32, 'WARN', 'Concurrent users high', '2026-03-06 10:30:00', 'monitor');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (33, 'INFO', 'Newsletter sent', '2026-03-06 10:35:00', 'email');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (34, 'ERROR', 'Image processing failed', '2026-03-06 10:40:00', 'media');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (35, 'INFO', 'Review submitted', '2026-03-06 10:45:00', 'review');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (36, 'INFO', 'Promotion started', '2026-03-06 10:50:00', 'marketing');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (37, 'WARN', 'Coupon usage high', '2026-03-06 10:55:00', 'marketing');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (38, 'INFO', 'Refund processed', '2026-03-06 11:00:00', 'payment');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (39, 'ERROR', 'Transaction declined', '2026-03-06 11:05:00', 'payment');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (40, 'INFO', 'Wishlist updated', '2026-03-06 11:10:00', 'user');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (41, 'INFO', 'Search index rebuilt', '2026-03-06 11:15:00', 'search');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (42, 'WARN', 'Search query slow', '2026-03-06 11:20:00', 'search');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (43, 'INFO', 'Account verified', '2026-03-06 11:25:00', 'auth');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (44, 'ERROR', 'Account locked', '2026-03-06 11:30:00', 'security');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (45, 'INFO', 'Profile updated', '2026-03-06 11:35:00', 'user');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (46, 'INFO', 'Address added', '2026-03-06 11:40:00', 'user');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (47, 'WARN', 'Address validation failed', '2026-03-06 11:45:00', 'shipping');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (48, 'INFO', 'Gift card applied', '2026-03-06 11:50:00', 'payment');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (49, 'ERROR', 'Gift card expired', '2026-03-06 11:55:00', 'payment');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (50, 'INFO', 'Subscription renewed', '2026-03-06 12:00:00', 'subscription');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (51, 'INFO', 'Trial started', '2026-03-06 12:05:00', 'subscription');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (52, 'WARN', 'Trial expiring soon', '2026-03-06 12:10:00', 'subscription');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (53, 'INFO', 'Team member added', '2026-03-06 12:15:00', 'team');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (54, 'ERROR', 'Permission denied', '2026-03-06 12:20:00', 'security');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (55, 'INFO', 'Role assigned', '2026-03-06 12:25:00', 'team');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (56, 'INFO', 'Integration connected', '2026-03-06 12:30:00', 'integration');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (57, 'WARN', 'Integration sync delayed', '2026-03-06 12:35:00', 'integration');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (58, 'ERROR', 'Integration failed', '2026-03-06 12:40:00', 'integration');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (59, 'INFO', 'Webhook received', '2026-03-06 12:45:00', 'webhook');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (60, 'INFO', 'Webhook processed', '2026-03-06 12:50:00', 'webhook');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (61, 'WARN', 'Webhook retry', '2026-03-06 12:55:00', 'webhook');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (62, 'ERROR', 'Webhook failed', '2026-03-06 13:00:00', 'webhook');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (63, 'INFO', 'Mobile app login', '2026-03-06 13:05:00', 'mobile');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (64, 'INFO', 'Push notification sent', '2026-03-06 13:10:00', 'mobile');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (65, 'WARN', 'Push notification failed', '2026-03-06 13:15:00', 'mobile');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (66, 'INFO', 'SMS sent', '2026-03-06 13:20:00', 'sms');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (67, 'ERROR', 'SMS delivery failed', '2026-03-06 13:25:00', 'sms');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (68, 'INFO', 'Two factor enabled', '2026-03-06 13:30:00', 'security');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (69, 'INFO', 'Backup code used', '2026-03-06 13:35:00', 'security');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (70, 'WARN', 'Suspicious activity detected', '2026-03-06 13:40:00', 'security');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (71, 'INFO', 'IP whitelisted', '2026-03-06 13:45:00', 'security');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (72, 'ERROR', 'IP blocked', '2026-03-06 13:50:00', 'security');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (73, 'INFO', 'SSL certificate renewed', '2026-03-06 13:55:00', 'ssl');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (74, 'WARN', 'SSL expiring soon', '2026-03-06 14:00:00', 'ssl');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (75, 'INFO', 'Domain renewed', '2026-03-06 14:05:00', 'domain');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (76, 'INFO', 'DNS updated', '2026-03-06 14:10:00', 'dns');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (77, 'WARN', 'DNS propagation slow', '2026-03-06 14:15:00', 'dns');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (78, 'INFO', 'CDN cache purged', '2026-03-06 14:20:00', 'cdn');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (79, 'INFO', 'Load balancer updated', '2026-03-06 14:25:00', 'infrastructure');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (80, 'ERROR', 'Server unreachable', '2026-03-06 14:30:00', 'infrastructure');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (81, 'INFO', 'Auto scaling triggered', '2026-03-06 14:35:00', 'infrastructure');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (82, 'WARN', 'High CPU usage', '2026-03-06 14:40:00', 'monitor');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (83, 'INFO', 'Alert rule created', '2026-03-06 14:45:00', 'alert');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (84, 'INFO', 'Alert triggered', '2026-03-06 14:50:00', 'alert');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (85, 'WARN', 'Alert storm detected', '2026-03-06 14:55:00', 'alert');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (86, 'INFO', 'Dashboard created', '2026-03-06 15:00:00', 'analytics');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (87, 'INFO', 'Report scheduled', '2026-03-06 15:05:00', 'analytics');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (88, 'WARN', 'Data anomaly detected', '2026-03-06 15:10:00', 'analytics');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (89, 'INFO', 'A/B test started', '2026-03-06 15:15:00', 'experiment');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (90, 'INFO', 'Feature flag enabled', '2026-03-06 15:20:00', 'feature');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (91, 'WARN', 'Feature flag rollback', '2026-03-06 15:25:00', 'feature');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (92, 'INFO', 'Migration completed', '2026-03-06 15:30:00', 'migration');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (93, 'ERROR', 'Migration failed', '2026-03-06 15:35:00', 'migration');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (94, 'INFO', 'Rollback completed', '2026-03-06 15:40:00', 'migration');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (95, 'INFO', 'Maintenance started', '2026-03-06 15:45:00', 'maintenance');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (96, 'INFO', 'Maintenance completed', '2026-03-06 15:50:00', 'maintenance');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (97, 'WARN', 'Maintenance delayed', '2026-03-06 15:55:00', 'maintenance');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (98, 'INFO', 'Deployment started', '2026-03-06 16:00:00', 'deploy');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (99, 'INFO', 'Deployment successful', '2026-03-06 16:05:00', 'deploy');
INSERT INTO logs (id, level, message, timestamp, source) VALUES (100, 'ERROR', 'Deployment failed', '2026-03-06 16:10:00', 'deploy');

-- 显示所有表
SHOW TABLES;

-- 显示表结构
SHOW STRUCT users;
SHOW STRUCT orders;
SHOW STRUCT products;
SHOW STRUCT logs;

-- 显示数据统计
SHOW DATAS users;
SHOW DATAS orders;
SHOW DATAS products;
SHOW DATAS logs;

-- 获取当前数据库
GET CURRENT DATABASE;

-- 获取表数量
GET TABLES NUMBER;