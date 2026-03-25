# IronSQL - 轻量级类型安全数据管理系统

<div align="center">

![Version](https://img.shields.io/badge/version-0.0.1-blue.svg)
![License](https://img.shields.io/badge/license-MIT-green.svg)
![Platform](https://img.shields.io/badge/platform-Windows%20%7C%20Linux-lightgrey.svg)
![Language](https://img.shields.io/badge/language-C%2B%2B20-blue.svg)

**基于现代 C++20 构建的轻量级个人数据管理系统**

</div>

---

## 项目简介

IronSQL 是一个轻量级个人数据管理系统，采用现代 C++20 标准开发，为个人用户提供简洁、高效、类型安全的数据存储和查询解决方案。

### 项目定位

- **个人使用**：专为个人用户的数据管理需求设计
- **教学原理**：适合作为数据库原理和现代 C++ 编程的学习工具
- **非工业级**：不与工业级数据库系统对标，专注于简洁性和可理解性
- **学习资源**：提供清晰的代码结构和实现，便于理解数据库基本原理

### 核心特性

- **类型安全存储**：基于 `std::variant` 实现真正的类型安全，支持多种数据类型
- **格式化输出**：借鉴 MySQL 的美学设计，提供直观美观的数据可视化
- **跨平台支持**：原生支持 Windows 和 Linux/Unix 系统
- **交互友好**：支持交互式和非交互式两种运行模式
- **代码规范**：遵循严格的命名规范和代码组织原则

### 设计理念

> **"简洁胜于复杂，类型安全优先"**

IronSQL 专注于：

- ✅ 个人用户的真实需求
- ✅ 代码的可维护性和可扩展性
- ✅ 现代化的 C++ 编程实践
- ✅ 清晰的架构和职责划分

### 项目声明

- **个人项目**：IronSQL 是个人项目，无商业价值
- **开发承诺**：作者会尽全力做好，尽量靠近 C/C++ 工程标准化
- **维护状态**：仅一人开发与维护，更新迭代缓慢
- **版本管理**：目前只有一个分支
- **技术规划**：计划使用 B+ 树算法，磁盘数据载入将在基础功能完成后实现

---

## 技术架构

### 分层设计

```
┌─────────────────────────────────────────┐
│         Entry Layer (iron_main.cpp)     │  User Interaction, Main Loop
├─────────────────────────────────────────┤
│      Function Library Layer (library/)  │  Parsing, Processing, Formatting
│  ├─ SQL Parser (iron_parser)         │  ├─ Resolver: SQL Statement Parsing
│  ├─ String Processing (iron_handle)  │  ├─ Strings: String Tools
│  ├─ Status Management (iron_status)  │  ├─ Manage: Runtime Status
│  ├─ Formatted Output (iron_fmtout)   │  ├─ Printer: Table Output
│  └─ Help System (iron_help)          │  └─ ShowHelp: Help Information
├─────────────────────────────────────────┤
│      Core Processing Layer (kernel/)    │  Database Operation Core
│  ├─ Business Logic (iron_proces)     │  ├─ Core: Core Operations
│  ├─ Type Validation (iron_verify)    │  ├─ Inspector: Type Conversion
│  ├─ SQL Syntax (iron_syntax)         │  └─ Word: Keyword Definitions
│  └─ Keyword Definitions (iron_keywds)│
├─────────────────────────────────────────┤
│      Data Model Layer (release/)        │  Data Structure Definitions
│  ├─ Data Structures (iron_struct)    │  ├─ Database, Table, Field
│  └─ Global Objects (iron_object)     │  └─ Interface: Global Container
├─────────────────────────────────────────┤
│      Auxiliary System Layer             │  Logging, IO, File System
│  ├─ Logging System (logsystem)       │  ├─ LogOut: Debug Logging
│  ├─ IO Streams (stdiostreams)        │  ├─ OutStream: Input/Output
│  ├─ File System (fsystem)            │  ├─ HelpInfo: Help Information Reading
│  ├─ Path System (psystem)            │  ├─ PathSystem: Path Management
│  ├─ Cross-platform (include/.include)│  └─ Cross-platform Macro Definitions
└─────────────────────────────────────────┘
```

### 类型系统

使用 `std::variant` 实现编译时类型检查：

```cpp
using Value = std::variant<long long, long, int, char, std::string, double, float, bool>;
```

**支持的数据类型**：

- `MAXINT` - 超大整数
- `BIGINT` - 大整数
- `INT` - 整数
- `FLOAT` - 单精度浮点数
- `DOUBLE` - 双精度浮点数
- `STRING` - 字符串
- `CHAR` - 字符
- `BOOL` - 布尔值

### 命名规范

Follows strict code conventions (see `CODE-RULES.MD` for details):

| Type      | Private           | Public          |
| --------- | ----------------- | --------------- |
| Namespace | `_NamespaceName_` | `NamespaceName` |
| Class     | `_ClassName`      | `ClassName`     |
| Function  | `_functionName`   | `FunctionName`  |
| Struct    | `_StructName`     | `StructName`    |

---

## 功能特性

### 当前功能

#### 数据库管理

- ✅ 创建数据库 (`CREATE DATABASE`)
- ✅ 删除数据库 (`DROP DATABASE`)
- ✅ 切换数据库 (`USE DATABASE`)
- ✅ 显示数据库列表 (`SHOW DATABASES`)

#### 表管理

- ✅ 创建表 (`CREATE TABLE`)
- ✅ 删除表 (`DROP TABLE`)
- ✅ 显示表列表 (`SHOW TABLES`)
- ✅ 显示表结构 (`SHOW TABLE ... STRUCT`)
- ✅ 关联表 (`LINK TABLE ... TO ... NEW ...`) - 智能合并
- ✅ 显示多个表的合并数据 (`LINK SHOW TABLE FROM ...`) - 快速查看

#### 数据操作

- ✅ 插入数据 (`INSERT INTO ... VALUES`)
- ✅ 查询数据 (`SELECT * FROM ...`)
- ✅ 查询指定字段 (`SELECT field1, field2 FROM ...`)

#### 交互模式

- ✅ 交互式命令行（支持多行语句）
- ✅ 非交互式模式（管道/重定向输入）
- ✅ 实时帮助系统 (`help -s`, `help -p`)
- ✅ 调试日志系统 (`IRON_DEBUG`)

#### 特色功能

- ✅ **智能表关联**：基于共同字段自动合并表数据
- ✅ **多表联合显示**：直接查看多个表的合并数据，无需创建新表
- ✅ **格式化输出**：自动计算列宽，对齐美观
- ✅ **类型自动识别**：自动转换用户输入为适当类型
- ✅ **中文字符支持**：UTF-8 编码，正确显示中文
- ✅ **文件系统操作**：跨平台文件系统操作支持

---

## 更新记录

### 2026-03-19 - 多表联合显示功能

#### 新增功能

- **多表联合显示**：添加了 `LINK SHOW TABLE FROM` 语句，允许直接查看多个表的合并数据，无需创建新表
- **语法格式**：`link show table from database:table1,table2,...`
- **支持任意数量表**：可以同时查看两个或更多表的关联数据

#### 技术改进

- **修复字段宽度计算**：解决了 "field width and row width size not match" 错误
- **优化数据合并**：基于公共字段智能合并表数据，无公共字段时自动追加
- **提升性能**：无需创建临时表，节省内存，操作更高效

#### Comparison with Old Syntax

| Feature               | Old Syntax (LINK TABLE ... TO ... NEW ...)          | New Syntax (LINK SHOW TABLE FROM ...)         |
| --------------------- | --------------------------------------------------- | --------------------------------------------- |
| Operation Steps       | Multiple steps (Create new table + Query new table) | Single step (Directly view merged data)       |
| Memory Usage          | Creates temporary table, uses memory                | No temporary table, saves memory              |
| Syntax Complexity     | Complex, requires specifying target table name      | Simple, directly specify multiple table names |
| Supported Table Count | Maximum 2 tables                                    | Any number of tables                          |
| Result Persistence    | Result stored in new table                          | Result only displayed, not persisted          |
| Use Case              | When needing to save association results            | When quickly viewing associated data          |

#### Usage Examples

```sql
-- View merged data from two tables
link show table from users:user_roles,user_profile;

-- View merged data from three tables
link show table from users:user_roles,user_muxt,user_ooxx;
```

#### Implementation Details

For detailed implementation records, please refer to the file `recode-linkShowTable重大实现-2026-03-19-12-00.log` in the `.recode` directory.

---

## 快速开始

### 环境要求

- **编译器**：支持 C++20 的编译器（GCC 10+, Clang 10+）
- **操作系统**：Windows 10+, Linux (Ubuntu 20.04+), macOS 11+
- **构建工具**：Make

**重要说明**：本项目已放弃使用 CMakeLists.txt，不再兼容 MSVC 编译器。统一使用 GNU/MinGW 与 CNU/'C/C++' 标准进行跨平台编译，确保编译一致性和跨平台兼容性。

### 编译项目

```bash
# 克隆项目
git clone https://github.com/cn86-zhh/IronSQL.git
cd IronSQL

# 编译（使用提供的脚本）
./makec++.sh

# 编译成功后，可执行文件位于
# Windows: ./bin/ironsql.exe
# Linux: ./bin/ironsql
```

### 运行项目

#### 交互式模式

```bash
# 直接运行
./bin/ironsql.exe

# 查看帮助
IronSQL> help -s

# 创建数据库
IronSQL> create database mydb;

# 使用数据库
IronSQL> use mydb;

# 创建表
IronSQL> create table users (id int, name string, age int);

# 插入数据
IronSQL> insert into users (id, name, age) values (1, "Alice", 25);

# 查询数据
IronSQL> select * from users;

# 退出
IronSQL> exit;
```

#### 非交互式模式

```bash
# 从文件执行 SQL
./bin/ironsql.exe < commands.sql

# 通过管道执行命令
echo "select * from users;" | ./bin/ironsql.exe

# 执行多个命令
echo "create database test; use test; create table t (id int); insert into t (id) values (1);" | ./bin/ironsql.exe
```

---

## 项目结构

```
IronSQL/
├─ .vscode/                     # VS Code 配置
├─ src/                         # 源代码目录
│  ├─ kernel/                   # 核心处理层
│  ├─ library/                  # 功能库层
│  ├─ release/                  # 数据模型层
│  ├─ include/                  # 公共头文件
│  ├─ logsystem/                # 日志系统
│  ├─ stdiostreams/             # IO 流处理
│  ├─ loads/                    # 配置加载
│  ├─ fsystem/                  # 文件系统操作
│  ├─ psystem/                  # 路径系统
│  ├─ other/                    # 其他功能
│  ├─ .config/                  # 配置文件
│  │  └─ .syntax/               # 语法定义文件
│  ├─ .include/                 # 跨平台包含
│  ├─ .package/                 # 包管理
│  ├─ .path/                    # 路径管理
│  ├─ .ironfsystem/             # 文件系统操作
│  ├─ .windows/                 # Windows 平台代码
│  ├─ .linux/                   # Linux 平台代码
│  ├─ .recode/                  # 变更记录
│  ├─ network/                  # 网络功能
│  ├─ test/                     # 测试代码
│  ├─ writes/                   # 写入操作
│  ├─ iron_main.cpp             # 程序入口
│  ├─ resource.rc               # 资源文件
│  └─ resource.rc.in            # 资源文件模板
├─ syn/                         # 语法标准文档
├─ bin/                         # 可执行文件
│  └─ .config/                  # 运行时配置
│     └─ .syntax/               # 运行时语法定义
├─ test/                        # 测试脚本
│  └─ res/                      # 测试资源
├─ log/                         # 编译日志
├─ img/                         # 图标资源
├─ CMakeLists.txt               # CMake 配置文件
├─ CODE-RULES.MD                # 代码规范
├─ LICENSE                      # MIT 许可证
├─ Makefile                     # Make 构建文件
├─ makec++.sh                   # 编译脚本
└─ README.MD                    # 本文件
```

---

## 开发指南

### 语法标准

IronSQL 提供了详细的语法标准文档，位于 `syn/` 目录中：

- **IronSQL_Syntax_Readme.md**：语法标准说明文档
- **IronSQL_Syntax_zh_CN.txt**：中文语法标准文档

使用方法：

```bash
# 查看完整语法说明
IronSQL> help -syntax --all;
```

注意：由于项目由单人维护开发，进度较为缓慢，实际程序语法可能与标准文档存在差异。开发者承诺以标准语法文档为准，逐步完善程序实现。

### 代码规范

项目遵循严格的代码规范，详见 `CODE-RULES.MD`：

- 所有文件名以 `iron` 为前缀
- 命名空间以 `Iron` 为前缀
- 私有成员使用下划线前缀 `_`
- 公有成员使用大驼峰命名

### 贡献指南

IronSQL 目前由单人维护开发，但我们欢迎：

- 🐛 **Bug 报告**：发现问题请及时反馈
- 💡 **功能建议**：提出您的需求和建议
- 📖 **文档改进**：帮助完善项目文档
- 🧪 **测试用例**：提供测试用例覆盖更多场景

### 开发路线图

#### 短期目标（v0.1.0）

- [ ] 添加数据持久化（JSON/Binary 格式）
- [ ] 支持更多 SQL 语法（WHERE 子句）
- [ ] 实现数据导入导出功能
- [ ] 添加配置文件支持
- [ ] 完善 B+ 树算法实现

#### 中期目标（v0.2.0）

- [ ] 支持复杂查询（JOIN, GROUP BY, ORDER BY）
- [ ] 实现索引机制提高查询效率
- [ ] 添加事务支持（BEGIN, COMMIT, ROLLBACK）
- [ ] 支持视图（VIEW）
- [ ] 实现磁盘数据载入功能

#### 长期目标（v1.0.0）

- [ ] 多用户和权限管理
- [ ] 网络服务端模式
- [ ] SQL 标准兼容性提升
- [ ] 性能优化和基准测试
- [ ] 图形化用户界面

---

## 技术亮点

### 1. 类型安全

使用 `std::variant` 而非 `std::any` 实现编译时类型检查：

- ✅ 支持多种数据类型（long long, long, int, char, std::string, double, float, bool）
- ✅ 编译时类型检查，避免运行时类型错误
- ✅ 零开销抽象，提高性能

### 2. 高效索引

使用 `std::unordered_map` 实现 O(1) 查找：

- 数据库名 → 索引映射
- 表名 → 索引映射
- 字段名 → 索引/类型映射
- 支持快速的数据结构访问和操作

### 3. 智能表关联

实现了基于公共字段的智能表关联功能：

- 自动识别公共字段进行表连接
- 无公共字段时自动追加数据
- 支持任意数量表的联合显示

### 4. 跨平台

使用条件编译处理平台差异：

```cpp
#ifdef _WIN32
    SetConsoleOutputCP(65001);  // UTF-8 编码
    SetConsoleCP(65001);       // UTF-8 编码
#else
    // Linux/Unix 特定代码
#endif
```

### 5. 模块化设计

- 单一职责原则：每个模块只负责特定功能
- 开闭原则：支持扩展，不修改现有代码
- 依赖倒置原则：依赖抽象而非具体实现
- 接口隔离原则：接口精简，职责明确

### 6. 格式化输出

实现了类似 MySQL 的格式化输出：

- 自动计算列宽，对齐美观
- 支持中文等 UTF-8 字符
- 提供直观的数据可视化

---

## 常见问题

### Q: IronSQL 与 SQLite/MySQL 有什么区别？

**A**: IronSQL 是轻量级个人数据管理系统，专注于：

- 个人用户的简单需求
- 学习 SQL 语法的入门工具
- 展示现代 C++ 编程实践

SQLite/MySQL 是成熟的数据库引擎，功能更强大但也更复杂。

### Q: 数据会持久化到磁盘吗？

**A**: 目前版本数据仅存储在内存中，程序退出后数据会丢失。数据持久化功能正在开发中（v0.1.0 目标）。

### Q: 支持哪些 SQL 语法？

**A**: 当前支持基本的 CRUD 操作：

- CREATE, DROP, USE, SHOW
- INSERT, SELECT
- LINK（表关联）

更多复杂语法（WHERE, JOIN, GROUP BY 等）正在逐步添加中。

### Q: 如何参与项目开发？

**A**:

1. Fork 项目到您的 GitHub
2. 创建特性分支
3. 提交您的更改
4. 发起 Pull Request

由于项目由单人维护，我们会尽量及时回复和合并。

---

## 性能基准

### 测试环境

- CPU: Intel Core i7-10700K
- 内存: 32GB DDR4
- 操作系统: Windows 11 / Ubuntu 22.04
- 编译器: GCC 12.2 / MSVC 19.35

### 性能指标

| Operation       | Data Volume           | Time    |
| --------------- | --------------------- | ------- |
| Create Database | -                     | < 1ms   |
| Create Table    | -                     | < 5ms   |
| Insert Data     | 10,000 rows           | < 100ms |
| Query Data      | 10,000 rows           | < 50ms  |
| Link Tables     | 2 tables × 3,000 rows | < 200ms |

_Note: Performance data is based on memory operations, not including disk I/O_

**Performance Considerations:**

- Current performance metrics are derived from in-memory operations only
- Database persistence functionality is scheduled for final development phase, where design and implementation will be determined
- Performance is expected to decrease during disk I/O operations once persistence is implemented
- Memory-based operations provide optimal performance for current use cases

---

## 许可证

本项目采用 **MIT 许可证**，详见 [LICENSE](LICENSE) 文件。

---

## 联系方式

- **作者**: cn86-zhh (GitHub) / ch86-zhh (Gitee)
- **官方网站**: https://www.ironsql.org.com
- **GitHub 项目**: https://github.com/cn86-zhh/IronSQL
- **Gitee 项目**: https://gitee.com/ch86-zhh/IronSQL

---

## 致谢

感谢所有为 IronSQL 项目提供反馈、建议和贡献的用户和开发者。

特别感谢：

- C++ 标准委员会提供了优秀的语言特性
- MySQL 团队提供了格式化输出的美学参考
- 开源社区提供了宝贵的工具和库

---

<div align="center">

**如果 IronSQL 对您有帮助，请给我们一个 Star ⭐**

Made with ❤️ by cn86-zhh

</div>
