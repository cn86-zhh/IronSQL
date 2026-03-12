-- 创建 ecommerce 数据库
CREATE DATABASE ecommerce;

-- 使用 ecommerce 数据库
USE ecommerce;

-- 创建 customers 表
CREATE TABLE customers (id INT, username STRING, email STRING, phone STRING, address STRING, city STRING, country STRING, register_date STRING, status STRING);

-- 创建 categories 表
CREATE TABLE categories (id INT, category_name STRING, description STRING, parent_id INT, level INT);

-- 创建 suppliers 表
CREATE TABLE suppliers (id INT, company_name STRING, contact_person STRING, phone STRING, email STRING, address STRING, city STRING, country STRING, status STRING);

-- 创建 products 表
CREATE TABLE products (id INT, product_name STRING, description STRING, category_id INT, supplier_id INT, price DOUBLE, cost DOUBLE, sku STRING, stock_quantity INT, weight DOUBLE, status STRING, create_date STRING);

-- 创建 orders 表
CREATE TABLE orders (id INT, customer_id INT, order_date STRING, total_amount DOUBLE, status STRING, shipping_address STRING, shipping_city STRING, shipping_country STRING, payment_method STRING);

-- 创建 order_items 表
CREATE TABLE order_items (id INT, order_id INT, product_id INT, quantity INT, unit_price DOUBLE, discount DOUBLE, subtotal DOUBLE);

-- 创建 payments 表
CREATE TABLE payments (id INT, order_id INT, payment_date STRING, amount DOUBLE, payment_method STRING, transaction_id STRING, status STRING);

-- 创建 shipping 表
CREATE TABLE shipping (id INT, order_id INT, shipping_date STRING, tracking_number STRING, carrier STRING, status STRING, estimated_delivery STRING, actual_delivery STRING);

-- 创建 reviews 表
CREATE TABLE reviews (id INT, product_id INT, customer_id INT, rating INT, comment STRING, review_date STRING, status STRING);

-- 插入 categories 数据
INSERT INTO categories (id, category_name, description, parent_id, level) VALUES (1, 'Electronics', 'Electronic devices and accessories', 0, 1);
INSERT INTO categories (id, category_name, description, parent_id, level) VALUES (2, 'Clothing', 'Clothing and fashion items', 0, 1);
INSERT INTO categories (id, category_name, description, parent_id, level) VALUES (3, 'Computers', 'Computers and computer accessories', 1, 2);
INSERT INTO categories (id, category_name, description, parent_id, level) VALUES (4, 'Phones', 'Mobile phones and accessories', 1, 2);
INSERT INTO categories (id, category_name, description, parent_id, level) VALUES (5, 'Men Clothing', 'Clothing for men', 2, 2);
INSERT INTO categories (id, category_name, description, parent_id, level) VALUES (6, 'Women Clothing', 'Clothing for women', 2, 2);

-- 插入 suppliers 数据
INSERT INTO suppliers (id, company_name, contact_person, phone, email, address, city, country, status) VALUES (1, 'TechWorld Inc.', 'John Smith', '+1-555-0101', 'john@techworld.com', '123 Tech Street', 'San Francisco', 'USA', 'active');
INSERT INTO suppliers (id, company_name, contact_person, phone, email, address, city, country, status) VALUES (2, 'Fashion Forward', 'Emily Brown', '+1-555-0102', 'emily@fashion.com', '456 Fashion Ave', 'New York', 'USA', 'active');
INSERT INTO suppliers (id, company_name, contact_person, phone, email, address, city, country, status) VALUES (3, 'Global Electronics', 'Michael Johnson', '+1-555-0103', 'michael@global.com', '789 Electronics Blvd', 'Los Angeles', 'USA', 'active');

-- 插入 customers 数据
INSERT INTO customers (id, username, email, phone, address, city, country, register_date, status) VALUES (1, 'customer1', 'customer1@example.com', '+1-555-1001', '100 Main Street', 'Boston', 'USA', '2026-01-05', 'active');
INSERT INTO customers (id, username, email, phone, address, city, country, register_date, status) VALUES (2, 'customer2', 'customer2@example.com', '+1-555-1002', '200 Oak Avenue', 'Chicago', 'USA', '2026-01-10', 'active');
INSERT INTO customers (id, username, email, phone, address, city, country, register_date, status) VALUES (3, 'customer3', 'customer3@example.com', '+1-555-1003', '300 Pine Road', 'Seattle', 'USA', '2026-01-15', 'active');
INSERT INTO customers (id, username, email, phone, address, city, country, register_date, status) VALUES (4, 'customer4', 'customer4@example.com', '+1-555-1004', '400 Elm Street', 'Miami', 'USA', '2026-01-20', 'active');

-- 插入 products 数据
INSERT INTO products (id, product_name, description, category_id, supplier_id, price, cost, sku, stock_quantity, weight, status, create_date) VALUES (1, 'Laptop Pro 15', 'High performance laptop with 16GB RAM', 3, 1, 1299.99, 900.00, 'LAPTOP-PRO-15', 50, 2.5, 'active', '2026-01-01');
INSERT INTO products (id, product_name, description, category_id, supplier_id, price, cost, sku, stock_quantity, weight, status, create_date) VALUES (2, 'Smartphone X', 'Latest smartphone with 5G support', 4, 1, 799.99, 550.00, 'PHONE-X-001', 100, 0.3, 'active', '2026-01-02');
INSERT INTO products (id, product_name, description, category_id, supplier_id, price, cost, sku, stock_quantity, weight, status, create_date) VALUES (3, 'Wireless Headphones', 'Noise cancelling wireless headphones', 4, 3, 199.99, 120.00, 'HEADPHONE-WL-01', 200, 0.25, 'active', '2026-01-03');
INSERT INTO products (id, product_name, description, category_id, supplier_id, price, cost, sku, stock_quantity, weight, status, create_date) VALUES (4, 'Men T-Shirt', 'Cotton t-shirt for men', 5, 2, 29.99, 15.00, 'TSHIRT-MEN-001', 500, 0.2, 'active', '2026-01-04');
INSERT INTO products (id, product_name, description, category_id, supplier_id, price, cost, sku, stock_quantity, weight, status, create_date) VALUES (5, 'Women Dress', 'Elegant dress for women', 6, 2, 89.99, 45.00, 'DRESS-WOM-001', 150, 0.4, 'active', '2026-01-05');
INSERT INTO products (id, product_name, description, category_id, supplier_id, price, cost, sku, stock_quantity, weight, status, create_date) VALUES (6, 'Gaming Mouse', 'High precision gaming mouse', 3, 1, 49.99, 25.00, 'MOUSE-GAME-001', 300, 0.15, 'active', '2026-01-06');

-- 插入 orders 数据
INSERT INTO orders (id, customer_id, order_date, total_amount, status, shipping_address, shipping_city, shipping_country, payment_method) VALUES (1, 1, '2026-02-01', 1399.98, 'completed', '100 Main Street', 'Boston', 'USA', 'credit_card');
INSERT INTO orders (id, customer_id, order_date, total_amount, status, shipping_address, shipping_city, shipping_country, payment_method) VALUES (2, 2, '2026-02-05', 799.99, 'shipped', '200 Oak Avenue', 'Chicago', 'USA', 'paypal');
INSERT INTO orders (id, customer_id, order_date, total_amount, status, shipping_address, shipping_city, shipping_country, payment_method) VALUES (3, 3, '2026-02-10', 229.98, 'processing', '300 Pine Road', 'Seattle', 'USA', 'credit_card');
INSERT INTO orders (id, customer_id, order_date, total_amount, status, shipping_address, shipping_city, shipping_country, payment_method) VALUES (4, 1, '2026-02-15', 59.98, 'pending', '100 Main Street', 'Boston', 'USA', 'debit_card');

-- 插入 order_items 数据
INSERT INTO order_items (id, order_id, product_id, quantity, unit_price, discount, subtotal) VALUES (1, 1, 1, 1, 1299.99, 0, 1299.99);
INSERT INTO order_items (id, order_id, product_id, quantity, unit_price, discount, subtotal) VALUES (2, 1, 3, 1, 199.99, 0, 199.99);
INSERT INTO order_items (id, order_id, product_id, quantity, unit_price, discount, subtotal) VALUES (3, 2, 2, 1, 799.99, 0, 799.99);
INSERT INTO order_items (id, order_id, product_id, quantity, unit_price, discount, subtotal) VALUES (4, 3, 3, 1, 199.99, 0, 199.99);
INSERT INTO order_items (id, order_id, product_id, quantity, unit_price, discount, subtotal) VALUES (5, 3, 6, 1, 49.99, 20, 29.99);
INSERT INTO order_items (id, order_id, product_id, quantity, unit_price, discount, subtotal) VALUES (6, 4, 4, 2, 29.99, 0, 59.98);

-- 插入 payments 数据
INSERT INTO payments (id, order_id, payment_date, amount, payment_method, transaction_id, status) VALUES (1, 1, '2026-02-01', 1399.98, 'credit_card', 'TXN-20260201-001', 'completed');
INSERT INTO payments (id, order_id, payment_date, amount, payment_method, transaction_id, status) VALUES (2, 2, '2026-02-05', 799.99, 'paypal', 'TXN-20260205-001', 'completed');
INSERT INTO payments (id, order_id, payment_date, amount, payment_method, transaction_id, status) VALUES (3, 3, '2026-02-10', 229.98, 'credit_card', 'TXN-20260210-001', 'pending');

-- 插入 shipping 数据
INSERT INTO shipping (id, order_id, shipping_date, tracking_number, carrier, status, estimated_delivery, actual_delivery) VALUES (1, 1, '2026-02-02', 'TRK-20260202-001', 'FedEx', 'delivered', '2026-02-05', '2026-02-04');
INSERT INTO shipping (id, order_id, shipping_date, tracking_number, carrier, status, estimated_delivery, actual_delivery) VALUES (2, 2, '2026-02-06', 'TRK-20260206-001', 'UPS', 'in_transit', '2026-02-10', 'NULL');
INSERT INTO shipping (id, order_id, shipping_date, tracking_number, carrier, status, estimated_delivery, actual_delivery) VALUES (3, 3, '2026-02-11', 'TRK-20260211-001', 'FedEx', 'processing', '2026-02-15', 'NULL');

-- 插入 reviews 数据
INSERT INTO reviews (id, product_id, customer_id, rating, comment, review_date, status) VALUES (1, 1, 1, 5, 'Excellent laptop, very fast and reliable', '2026-02-05', 'approved');
INSERT INTO reviews (id, product_id, customer_id, rating, comment, review_date, status) VALUES (2, 2, 2, 4, 'Great phone, battery life could be better', '2026-02-08', 'approved');
INSERT INTO reviews (id, product_id, customer_id, rating, comment, review_date, status) VALUES (3, 3, 3, 5, 'Best headphones I have ever owned', '2026-02-12', 'approved');
INSERT INTO reviews (id, product_id, customer_id, rating, comment, review_date, status) VALUES (4, 4, 1, 4, 'Good quality t-shirt, fits well', '2026-02-15', 'approved');
INSERT INTO reviews (id, product_id, customer_id, rating, comment, review_date, status) VALUES (5, 6, 2, 5, 'Perfect gaming mouse, very responsive', '2026-02-18', 'approved');

-- 显示所有表
SHOW TABLES;

-- 显示所有表数据
SHOW DATAS customers;
SHOW DATAS categories;
SHOW DATAS suppliers;
SHOW DATAS products;
SHOW DATAS orders;
SHOW DATAS order_items;
SHOW DATAS payments;
SHOW DATAS shipping;
SHOW DATAS reviews;