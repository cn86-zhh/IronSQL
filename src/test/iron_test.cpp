#include "iron_proces.hpp"
#include "iron_test.hpp"
#include "iron_status.hpp"
#include "iron_keywds.hpp"

namespace IronTest
{

    /**
     * @brief Creates test databases for IronSQL.
     * 
     * This function creates several test databases including students, users, projects, task, systems, records, and ecommerce.
     */
    static void createTestDatabase()
    {
        std::string databases_array[]{
            "students",
            "users",
            "projects",
            "task",
            "systems",
            "records",
            "ecommerce"};

        for (const auto &database : databases_array)
        {
            IronProces::Core::createDatabase(database);
        }
    }

    /**
     * @brief Creates test tables for each database.
     * 
     * This function creates various tables for each test database, including:
     * - students database: student_info, courses, scores, teachers, classrooms, library
     * - users database: user_account, user_profile, login_logs, permissions, user_roles, notifications
     * - projects database: project_list, project_members, tasks, milestones, resources, project_documents
     * - task database: daily_tasks, task_categories, task_comments, recurring_tasks, task_attachments, task_reminders
     * - systems database: system_logs, configurations, backup_records, system_monitor, api_endpoints, scheduled_jobs
     * - records database: operation_records, financial_records, inventory_records, access_records, error_records, audit_records
     */
    static void createTestTables()
    {
        // students 数据库 - 学校管理系统
        IronProces::Core::useDatabase("students");
        IronProces::Core::createTable("student_info", {"id", "name", "age", "gender", "major", "enrollment_date"}, {"int", "string", "int", "string", "string", "string"});
        IronProces::Core::createTable("courses", {"id", "course_name", "credit", "teacher", "semester"}, {"int", "string", "int", "string", "string"});
        IronProces::Core::createTable("scores", {"id", "student_id", "course_id", "score", "exam_date"}, {"int", "int", "int", "double", "string"});
        IronProces::Core::createTable("teachers", {"id", "name", "title", "department", "hire_date"}, {"int", "string", "string", "string", "string"});
        IronProces::Core::createTable("classrooms", {"id", "room_number", "capacity", "building", "type"}, {"int", "string", "int", "string", "string"});
        IronProces::Core::createTable("library", {"id", "book_name", "author", "isbn", "borrow_status"}, {"int", "string", "string", "string", "string"});

        // users 数据库 - 用户管理系统
        IronProces::Core::useDatabase("users");
        IronProces::Core::createTable("user_account", {"id", "username", "password", "email", "phone", "register_date"}, {"int", "string", "string", "string", "string", "string"});
        IronProces::Core::createTable("user_profile", {"id", "user_id", "nickname", "avatar", "bio", "birthday"}, {"int", "int", "string", "string", "string", "string"});
        IronProces::Core::createTable("login_logs", {"id", "user_id", "ip_address", "login_time", "device"}, {"int", "int", "string", "string", "string"});
        IronProces::Core::createTable("permissions", {"id", "role_name", "permission_code", "description"}, {"int", "string", "string", "string"});
        IronProces::Core::createTable("user_roles", {"id", "user_id", "role_id", "assign_date"}, {"int", "int", "int", "string"});
        IronProces::Core::createTable("notifications", {"id", "user_id", "title", "content", "send_time", "is_read"}, {"int", "int", "string", "string", "string", "bool"});

        // projects 数据库 - 项目管理
        IronProces::Core::useDatabase("projects");
        IronProces::Core::createTable("project_list", {"id", "project_name", "description", "start_date", "end_date", "status", "manager_id"}, {"int", "string", "string", "string", "string", "string", "int"});
        IronProces::Core::createTable("project_members", {"id", "project_id", "user_id", "role", "join_date"}, {"int", "int", "int", "string", "string"});
        IronProces::Core::createTable("tasks", {"id", "project_id", "task_name", "priority", "deadline", "status", "assignee_id"}, {"int", "int", "string", "string", "string", "string", "int"});
        IronProces::Core::createTable("milestones", {"id", "project_id", "milestone_name", "target_date", "completion_rate"}, {"int", "int", "string", "string", "double"});
        IronProces::Core::createTable("resources", {"id", "resource_name", "type", "quantity", "unit", "cost"}, {"int", "string", "string", "int", "string", "double"});
        IronProces::Core::createTable("project_documents", {"id", "project_id", "doc_name", "doc_type", "upload_date", "file_size"}, {"int", "int", "string", "string", "string", "int"});

        // task 数据库 - 任务管理
        IronProces::Core::useDatabase("task");
        IronProces::Core::createTable("daily_tasks", {"id", "task_title", "description", "category", "due_date", "priority", "is_completed"}, {"int", "string", "string", "string", "string", "string", "bool"});
        IronProces::Core::createTable("task_categories", {"id", "category_name", "color_code", "icon"}, {"int", "string", "string", "string"});
        IronProces::Core::createTable("task_comments", {"id", "task_id", "user_id", "comment", "create_time"}, {"int", "int", "int", "string", "string"});
        IronProces::Core::createTable("recurring_tasks", {"id", "task_name", "frequency", "start_date", "end_date", "next_trigger"}, {"int", "string", "string", "string", "string", "string"});
        IronProces::Core::createTable("task_attachments", {"id", "task_id", "file_name", "file_path", "upload_time", "file_size"}, {"int", "int", "string", "string", "string", "int"});
        IronProces::Core::createTable("task_reminders", {"id", "task_id", "remind_time", "remind_type", "is_sent"}, {"int", "int", "string", "string", "bool"});

        // systems 数据库 - 系统管理
        IronProces::Core::useDatabase("systems");
        IronProces::Core::createTable("system_logs", {"id", "log_level", "module", "message", "create_time", "ip_address"}, {"int", "string", "string", "string", "string", "string"});
        IronProces::Core::createTable("configurations", {"id", "config_key", "config_value", "description", "update_time"}, {"int", "string", "string", "string", "string"});
        IronProces::Core::createTable("backup_records", {"id", "backup_name", "backup_type", "file_path", "file_size", "create_time", "status"}, {"int", "string", "string", "string", "int", "string", "string"});
        IronProces::Core::createTable("system_monitor", {"id", "metric_name", "metric_value", "unit", "record_time"}, {"int", "string", "double", "string", "string"});
        IronProces::Core::createTable("api_endpoints", {"id", "endpoint_path", "method", "description", "auth_required", "rate_limit"}, {"int", "string", "string", "string", "bool", "int"});
        IronProces::Core::createTable("scheduled_jobs", {"id", "job_name", "cron_expression", "last_run", "next_run", "status"}, {"int", "string", "string", "string", "string", "string"});

        // records 数据库 - 记录管理
        IronProces::Core::useDatabase("records");
        IronProces::Core::createTable("operation_records", {"id", "user_id", "operation_type", "target_table", "operation_time", "details"}, {"int", "int", "string", "string", "string", "string"});
        IronProces::Core::createTable("financial_records", {"id", "transaction_type", "amount", "currency", "transaction_date", "description", "balance"}, {"int", "string", "double", "string", "string", "string", "double"});
        IronProces::Core::createTable("inventory_records", {"id", "item_name", "quantity", "unit", "warehouse", "last_update"}, {"int", "string", "int", "string", "string", "string"});
        IronProces::Core::createTable("access_records", {"id", "user_id", "access_time", "access_location", "access_type", "result"}, {"int", "int", "string", "string", "string", "string"});
        IronProces::Core::createTable("error_records", {"id", "error_code", "error_message", "stack_trace", "occurrence_time", "resolved"}, {"int", "string", "string", "string", "string", "bool"});
        IronProces::Core::createTable("audit_records", {"id", "auditor_id", "audit_target", "audit_type", "findings", "audit_date"}, {"int", "int", "string", "string", "string", "string"});
    }

    /**
     * @brief Inserts test data into the created tables.
     * 
     * This function inserts sample data into various tables across different databases, including:
     * - task database: task_categories, daily_tasks, task_comments, recurring_tasks, task_attachments, task_reminders
     * - users database: user_account, user_profile, login_logs, permissions, user_roles, notifications
     * - records database: operation_records, financial_records, inventory_records, access_records, error_records, audit_records
     */
    static void insertTestData()
    {
        // task database - Task Management
        IronProces::Core::useDatabase("task");

        // Insert task_categories data
        IronProces::Core::insertData("task_categories", {"id", "category_name", "color_code", "icon"}, {"1", "Work", "#3498db", "briefcase"});
        IronProces::Core::insertData("task_categories", {"id", "category_name", "color_code", "icon"}, {"2", "Personal", "#e74c3c", "user"});
        IronProces::Core::insertData("task_categories", {"id", "category_name", "color_code", "icon"}, {"3", "Study", "#2ecc71", "book"});
        IronProces::Core::insertData("task_categories", {"id", "category_name", "color_code", "icon"}, {"4", "Health", "#f39c12", "heart"});

        // Insert daily_tasks data
        IronProces::Core::insertData("daily_tasks", {"id", "task_title", "description", "category", "due_date", "priority", "is_completed"}, {"1", "Complete Project Report", "Complete Q1 project summary report", "Work", "2026-03-10", "High", "false"});
        IronProces::Core::insertData("daily_tasks", {"id", "task_title", "description", "category", "due_date", "priority", "is_completed"}, {"2", "Buy Groceries", "Buy weekly food supplies", "Personal", "2026-03-07", "Medium", "false"});
        IronProces::Core::insertData("daily_tasks", {"id", "task_title", "description", "category", "due_date", "priority", "is_completed"}, {"3", "Learn C++", "Learn C++ standard library", "Study", "2026-03-15", "Low", "false"});
        IronProces::Core::insertData("daily_tasks", {"id", "task_title", "description", "category", "due_date", "priority", "is_completed"}, {"4", "Gym", "Do 30 minutes of aerobic exercise", "Health", "2026-03-08", "Medium", "false"});

        // Insert task_comments data
        IronProces::Core::insertData("task_comments", {"id", "task_id", "user_id", "comment", "create_time"}, {"1", "1", "1", "Need to add project budget section", "2026-03-06 10:00:00"});
        IronProces::Core::insertData("task_comments", {"id", "task_id", "user_id", "comment", "create_time"}, {"2", "2", "1", "Remember to buy milk and eggs", "2026-03-06 11:30:00"});

        // Insert recurring_tasks data
        IronProces::Core::insertData("recurring_tasks", {"id", "task_name", "frequency", "start_date", "end_date", "next_trigger"}, {"1", "Team Meeting", "Every Monday", "2026-03-02", "2026-12-31", "2026-03-09"});
        IronProces::Core::insertData("recurring_tasks", {"id", "task_name", "frequency", "start_date", "end_date", "next_trigger"}, {"2", "Backup Data", "Every Sunday", "2026-03-01", "2026-12-31", "2026-03-08"});

        // Insert task_attachments data
        IronProces::Core::insertData("task_attachments", {"id", "task_id", "file_name", "file_path", "upload_time", "file_size"}, {"1", "1", "Project Report Template.docx", "/uploads/templates/report.docx", "2026-03-05 14:20:00", "20480"});

        // Insert task_reminders data
        IronProces::Core::insertData("task_reminders", {"id", "task_id", "remind_time", "remind_type", "is_sent"}, {"1", "1", "2026-03-09 17:00:00", "email", "false"});
        IronProces::Core::insertData("task_reminders", {"id", "task_id", "remind_time", "remind_type", "is_sent"}, {"2", "3", "2026-03-14 20:00:00", "notification", "false"});

        // users database - User Management System
        IronProces::Core::useDatabase("users");

        // Insert user_account data
        IronProces::Core::insertData("user_account", {"id", "username", "password", "email", "phone", "register_date"}, {"1", "admin", "admin123", "admin@example.com", "13800138000", "2026-01-01"});
        IronProces::Core::insertData("user_account", {"id", "username", "password", "email", "phone", "register_date"}, {"2", "user1", "password123", "user1@example.com", "13900139000", "2026-01-10"});
        IronProces::Core::insertData("user_account", {"id", "username", "password", "email", "phone", "register_date"}, {"3", "user2", "password456", "user2@example.com", "13700137000", "2026-01-15"});

        // Insert user_profile data
        IronProces::Core::insertData("user_profile", {"id", "user_id", "nickname", "avatar", "bio", "birthday"}, {"1", "1", "Administrator", "/avatars/admin.jpg", "System Administrator", "1990-01-01"});
        IronProces::Core::insertData("user_profile", {"id", "user_id", "nickname", "avatar", "bio", "birthday"}, {"2", "2", "Test User 1", "/avatars/user1.jpg", "Regular User", "1995-05-15"});
        IronProces::Core::insertData("user_profile", {"id", "user_id", "nickname", "avatar", "bio", "birthday"}, {"3", "3", "Test User 2", "/avatars/user2.jpg", "Regular User", "1998-08-20"});

        // Insert login_logs data
        IronProces::Core::insertData("login_logs", {"id", "user_id", "ip_address", "login_time", "device"}, {"1", "1", "192.168.1.100", "2026-03-05 09:00:00", "PC"});
        IronProces::Core::insertData("login_logs", {"id", "user_id", "ip_address", "login_time", "device"}, {"2", "2", "192.168.1.101", "2026-03-05 10:30:00", "Mobile"});

        // Insert permissions data
        IronProces::Core::insertData("permissions", {"id", "role_name", "permission_code", "description"}, {"1", "admin", "ALL", "All Permissions"});
        IronProces::Core::insertData("permissions", {"id", "role_name", "permission_code", "description"}, {"2", "user", "READ", "Read Only Permissions"});

        // Insert user_roles data
        IronProces::Core::insertData("user_roles", {"id", "user_id", "role_id", "assign_date"}, {"1", "1", "1", "2026-01-01"});
        IronProces::Core::insertData("user_roles", {"id", "user_id", "role_id", "assign_date"}, {"2", "2", "2", "2026-01-10"});
        IronProces::Core::insertData("user_roles", {"id", "user_id", "role_id", "assign_date"}, {"3", "3", "2", "2026-01-15"});

        // Insert notifications data
        IronProces::Core::insertData("notifications", {"id", "user_id", "title", "content", "send_time", "is_read"}, {"1", "1", "System Update", "System has been updated to the latest version", "2026-03-01 00:00:00", "true"});
        IronProces::Core::insertData("notifications", {"id", "user_id", "title", "content", "send_time", "is_read"}, {"2", "2", "Welcome Registration", "Welcome to use our system", "2026-01-10 10:00:00", "true"});

        // records database - Record Management
        IronProces::Core::useDatabase("records");

        // Insert operation_records data
        IronProces::Core::insertData("operation_records", {"id", "user_id", "operation_type", "target_table", "operation_time", "details"}, {"1", "1", "CREATE", "user_account", "2026-01-01 00:00:00", "Create admin account"});
        IronProces::Core::insertData("operation_records", {"id", "user_id", "operation_type", "target_table", "operation_time", "details"}, {"2", "1", "CREATE", "task_categories", "2026-01-02 10:00:00", "Create task categories"});

        // Insert financial_records data
        IronProces::Core::insertData("financial_records", {"id", "transaction_type", "amount", "currency", "transaction_date", "description", "balance"}, {"1", "Income", "10000", "CNY", "2026-01-01", "Salary", "10000"});
        IronProces::Core::insertData("financial_records", {"id", "transaction_type", "amount", "currency", "transaction_date", "description", "balance"}, {"2", "Expense", "2000", "CNY", "2026-01-05", "Shopping", "8000"});

        // Insert inventory_records data
        IronProces::Core::insertData("inventory_records", {"id", "item_name", "quantity", "unit", "warehouse", "last_update"}, {"1", "Laptop", "50", "unit", "Warehouse A", "2026-03-01"});
        IronProces::Core::insertData("inventory_records", {"id", "item_name", "quantity", "unit", "warehouse", "last_update"}, {"2", "Mouse", "200", "unit", "Warehouse B", "2026-03-02"});

        // Insert access_records data
        IronProces::Core::insertData("access_records", {"id", "user_id", "access_time", "access_location", "access_type", "result"}, {"1", "1", "2026-03-05 09:00:00", "Office", "Login", "Success"});
        IronProces::Core::insertData("access_records", {"id", "user_id", "access_time", "access_location", "access_type", "result"}, {"2", "2", "2026-03-05 10:30:00", "Home", "Login", "Success"});

        // Insert error_records data
        IronProces::Core::insertData("error_records", {"id", "error_code", "error_message", "stack_trace", "occurrence_time", "resolved"}, {"1", "404", "Page Not Found", "File not found", "2026-03-01 14:00:00", "true"});
        IronProces::Core::insertData("error_records", {"id", "error_code", "error_message", "stack_trace", "occurrence_time", "resolved"}, {"2", "500", "Internal Server Error", "Internal server error", "2026-03-02 15:00:00", "true"});

        // Insert audit_records data
        IronProces::Core::insertData("audit_records", {"id", "auditor_id", "audit_target", "audit_type", "findings", "audit_date"}, {"1", "1", "user_account", "Security Audit", "No anomalies found", "2026-02-01"});
        IronProces::Core::insertData("audit_records", {"id", "auditor_id", "audit_target", "audit_type", "findings", "audit_date"}, {"2", "1", "financial_records", "Financial Audit", "No anomalies found", "2026-02-01"});
    }

    /**
     * @brief Runs all test functions to initialize test data.
     * 
     * This function calls createTestDatabase(), createTestTables(), and insertTestData() to set up the test environment.
     * It also resets the current database name to none.
     */
    void test()
    {
        createTestDatabase();
        createTestTables();
        insertTestData();
        IronStatus::Manage::settingDatabaseName(IronKeywds::Kw::none_());
    }
};