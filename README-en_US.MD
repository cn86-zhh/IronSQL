# IronSQL - Lightweight Type-Safe Data Management System

<div align="center">

![Version](https://img.shields.io/badge/version-0.0.1-blue.svg)
![License](https://img.shields.io/badge/license-MIT-green.svg)
![Platform](https://img.shields.io/badge/platform-Windows%20%7C%20Linux-lightgrey.svg)
![Language](https://img.shields.io/badge/language-C%2B%2B20-blue.svg)

**A lightweight personal data management system built on modern C++20**

</div>

---

## Project Introduction

IronSQL is a lightweight personal data management system developed using modern C++20 standards, providing individual users with a concise, efficient, and type-safe data storage and query solution.

### Project Positioning

- **Personal Use**: Designed specifically for personal users' data management needs
- **Educational Principle**: Suitable as a learning tool for database principles and modern C++ programming
- **Non-Industrial Grade**: Not comparable to industrial-grade database systems, focusing on simplicity and understandability
- **Learning Resource**: Provides clear code structure and implementation, facilitating understanding of basic database principles

### Core Features

- **Type-Safe Storage**: Implements true type safety based on `std::variant`, supporting multiple data types
- **Formatted Output**: Draws inspiration from MySQL's aesthetic design, providing intuitive and visually appealing data visualization
- **Cross-Platform Support**: Native support for Windows and Linux/Unix systems
- **User-Friendly Interaction**: Supports both interactive and non-interactive operation modes
- **Code Standardization**: Follows strict naming conventions and code organization principles

### Design Philosophy

> **"Simplicity over complexity, type safety first"**

IronSQL focuses on:

- ✅ Real needs of individual users
- ✅ Code maintainability and extensibility
- ✅ Modern C++ programming practices
- ✅ Clear architecture and responsibility division

### Project Declaration

- **Personal Project**: IronSQL is a personal project with no commercial value
- **Development Commitment**: The author will do their best to align with C/C++ engineering standardization
- **Maintenance Status**: Developed and maintained by a single person, updates are iterative and slow
- **Technical Planning**: Plans to use B+ tree algorithm, disk data loading will be implemented after basic functionality is completed

---

## Technical Architecture

### Layered Design

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

### Type System

Implements compile-time type checking using `std::variant`:

```cpp
using Value = std::variant<long long, long, int, char, std::string, double, float, bool>;
```

**Supported Data Types**:

- `MAXINT` - Extra large integer
- `BIGINT` - Large integer
- `INT` - Integer
- `FLOAT` - Single-precision floating point
- `DOUBLE` - Double-precision floating point
- `STRING` - String
- `CHAR` - Character
- `BOOL` - Boolean

### Naming Conventions

Follows strict code conventions (see `CODE-RULES.MD` for details):

| Type      | Private           | Public          |
| --------- | ----------------- | --------------- |
| Namespace | `_NamespaceName_` | `NamespaceName` |
| Class     | `_ClassName`      | `ClassName`     |
| Function  | `_functionName`   | `FunctionName`  |
| Struct    | `_StructName`     | `StructName`    |

---

## Feature Set

### Current Features

#### Database Management

- ✅ Create database (`CREATE DATABASE`)
- ✅ Drop database (`DROP DATABASE`)
- ✅ Use database (`USE DATABASE`)
- ✅ Show database list (`SHOW DATABASES`)

#### Table Management

- ✅ Create table (`CREATE TABLE`)
- ✅ Drop table (`DROP TABLE`)
- ✅ Show table list (`SHOW TABLES`)
- ✅ Show table structure (`SHOW TABLE ... STRUCT`)
- ✅ Link tables (`LINK TABLE ... TO ... NEW ...`) - Intelligent merging
- ✅ Show merged data from multiple tables (`LINK SHOW TABLE FROM ...`) - Quick view

#### Data Operations

- ✅ Insert data (`INSERT INTO ... VALUES`)
- ✅ Query data (`SELECT * FROM ...`)
- ✅ Query specific fields (`SELECT field1, field2 FROM ...`)

#### Interaction Modes

- ✅ Interactive command line (supports multi-line statements)
- ✅ Non-interactive mode (pipe/redirect input)
- ✅ Real-time help system (`help -s`, `help -p`)
- ✅ Debug logging system (`IRON_DEBUG`)

#### Special Features

- ✅ **Intelligent Table Linking**: Automatically merges table data based on common fields
- ✅ **Multi-Table Joint Display**: Directly view merged data from multiple tables without creating new tables
- ✅ **Formatted Output**: Automatically calculates column widths for beautiful alignment
- ✅ **Type Auto-Recognition**: Automatically converts user input to appropriate types
- ✅ **Chinese Character Support**: UTF-8 encoding, correctly displays Chinese characters
- ✅ **File System Operations**: Cross-platform file system operation support

---

## Update History

### 2026-03-19 - Multi-Table Joint Display Feature

#### New Features

- **Multi-Table Joint Display**: Added `LINK SHOW TABLE FROM` statement, allowing direct viewing of merged data from multiple tables without creating new tables
- **Syntax Format**: `link show table from database:table1,table2,...`
- **Support for Any Number of Tables**: Can view associated data from two or more tables simultaneously

#### Technical Improvements

- **Fixed Field Width Calculation**: Resolved "field width and row width size not match" error
- **Optimized Data Merging**: Intelligently merges table data based on common fields, automatically appends when no common fields exist
- **Performance Enhancement**: No temporary table creation, saves memory, more efficient operation

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

## Quick Start

### Environment Requirements

- **Compiler**: C++20 compatible compiler (GCC 10+, Clang 10+)
- **Operating System**: Windows 10+, Linux (Ubuntu 20.04+), macOS 11+
- **Build Tool**: Make

**Important Note**: This project has abandoned the use of CMakeLists.txt and is no longer compatible with MSVC compiler. It now uses GNU/MinGW and CNU/'C/C++' standards for cross-platform compilation to ensure compilation consistency and cross-platform compatibility.

### Compile the Project

```bash
# Clone the project
git clone https://github.com/cn86-zhh/IronSQL.git
cd IronSQL

# Compile (using provided script)
./makec++.sh

# After successful compilation, the executable is located at
# Windows: ./bin/ironsql.exe
# Linux: ./bin/ironsql
```

### Run the Project

#### Interactive Mode

```bash
# Run directly
./bin/ironsql.exe

# View help
IronSQL> help -s

# Create database
IronSQL> create database mydb;

# Use database
IronSQL> use mydb;

# Create table
IronSQL> create table users (id int, name string, age int);

# Insert data
IronSQL> insert into users (id, name, age) values (1, "Alice", 25);

# Query data
IronSQL> select * from users;

# Exit
IronSQL> exit;
```

#### Non-Interactive Mode

```bash
# Execute SQL from file
./bin/ironsql.exe < commands.sql

# Execute commands via pipe
echo "select * from users;" | ./bin/ironsql.exe

# Execute multiple commands
echo "create database test; use test; create table t (id int); insert into t (id) values (1);" | ./bin/ironsql.exe
```

---

## Project Structure

```
IronSQL/
├─ .vscode/                     # VS Code configuration
├─ src/                         # Source code directory
│  ├─ kernel/                   # Core processing layer
│  ├─ library/                  # Function library layer
│  ├─ release/                  # Data model layer
│  ├─ include/                  # Public header files
│  ├─ logsystem/                # Logging system
│  ├─ stdiostreams/             # IO stream processing
│  ├─ loads/                    # Configuration loading
│  ├─ fsystem/                  # File system operations
│  ├─ psystem/                  # Path system
│  ├─ other/                    # Other functionality
│  ├─ .config/                  # Configuration files
│  │  └─ .syntax/               # Syntax definition files
│  ├─ .include/                 # Cross-platform includes
│  ├─ .package/                 # Package management
│  ├─ .path/                    # Path management
│  ├─ .ironfsystem/             # File system operations
│  ├─ .windows/                 # Windows platform code
│  ├─ .linux/                   # Linux platform code
│  ├─ .recode/                  # Change records
│  ├─ network/                  # Network functionality
│  ├─ test/                     # Test code
│  ├─ writes/                   # Write operations
│  ├─ iron_main.cpp             # Program entry point
│  ├─ resource.rc               # Resource file
│  └─ resource.rc.in            # Resource file template
├─ syn/                         # Syntax standard documents
├─ bin/                         # Executable files
│  └─ .config/                  # Runtime configuration
│     └─ .syntax/               # Runtime syntax definitions
├─ test/                        # Test scripts
│  └─ res/                      # Test resources
├─ log/                         # Compilation logs
├─ img/                         # Icon resources
├─ CMakeLists.txt               # CMake configuration file
├─ CODE-RULES.MD                # Code standards
├─ LICENSE                      # MIT license
├─ Makefile                     # Make build file
├─ makec++.sh                   # Compilation script
└─ README.MD                    # This file
```

---

## Development Guide

### Syntax Standards

IronSQL provides detailed syntax standard documents located in the `syn/` directory:

- **IronSQL_Syntax_Readme.md**: Syntax standard description document
- **IronSQL_Syntax_zh_CN.txt**: Chinese syntax standard document

Usage:

```bash
# View complete syntax description
IronSQL> help -syntax --all;
```

Note: Due to the project being maintained and developed by a single person, progress is relatively slow, and actual program syntax may differ from the standard documents. The developer commits to following the standard syntax documents and gradually improving program implementation.

### Code Standards

The project follows strict code standards, see `CODE-RULES.MD` for details:

- All filenames start with the `iron` prefix
- Namespaces start with the `Iron` prefix
- Private members use underscore prefix `_`
- Public members use PascalCase naming

### Contribution Guide

IronSQL is currently maintained and developed by a single person, but we welcome:

- 🐛 **Bug Reports**: Please provide timely feedback when issues are discovered
- 💡 **Feature Suggestions**: Submit your needs and suggestions
- 📖 **Documentation Improvements**: Help improve project documentation
- 🧪 **Test Cases**: Provide test cases to cover more scenarios

### Development Roadmap

#### Short-term Goals (v0.1.0)

- [ ] Add data persistence (JSON/Binary format)
- [ ] Support more SQL syntax (WHERE clause)
- [ ] Implement data import/export functionality
- [ ] Add configuration file support
- [ ] Complete B+ tree algorithm implementation

#### Mid-term Goals (v0.2.0)

- [ ] Support complex queries (JOIN, GROUP BY, ORDER BY)
- [ ] Implement indexing mechanism to improve query efficiency
- [ ] Add transaction support (BEGIN, COMMIT, ROLLBACK)
- [ ] Support views (VIEW)
- [ ] Implement disk data loading functionality

#### Long-term Goals (v1.0.0)

- [ ] Multi-user and permission management
- [ ] Network server mode
- [ ] SQL standard compatibility improvement
- [ ] Performance optimization and benchmarking
- [ ] Graphical user interface

---

## Technical Highlights

### 1. Type Safety

Implements compile-time type checking using `std::variant` instead of `std::any`:

- ✅ Supports multiple data types (long long, long, int, char, std::string, double, float, bool)
- ✅ Compile-time type checking, avoiding runtime type errors
- ✅ Zero-overhead abstraction, improving performance

### 2. Efficient Indexing

Implements O(1) lookup using `std::unordered_map`:

- Database name → index mapping
- Table name → index mapping
- Field name → index/type mapping
- Supports fast data structure access and operations

### 3. Intelligent Table Linking

Implements intelligent table linking functionality based on common fields:

- Automatically identifies common fields for table joins
- Automatically appends data when no common fields exist
- Supports joint display of any number of tables

### 4. Cross-Platform

Uses conditional compilation to handle platform differences:

```cpp
#ifdef _WIN32
    SetConsoleOutputCP(65001);  // UTF-8 encoding
    SetConsoleCP(65001);       // UTF-8 encoding
#else
    // Linux/Unix specific code
#endif
```

### 5. Modular Design

- Single Responsibility Principle: Each module is responsible for specific functionality
- Open/Closed Principle: Supports extension without modifying existing code
- Dependency Inversion Principle: Depends on abstractions rather than concrete implementations
- Interface Segregation Principle: Interfaces are concise and responsibilities are clear

### 6. Formatted Output

Implements MySQL-like formatted output:

- Automatically calculates column widths for beautiful alignment
- Supports UTF-8 characters such as Chinese
- Provides intuitive data visualization

---

## Frequently Asked Questions

### Q: What is the difference between IronSQL and SQLite/MySQL?

**A**: IronSQL is a lightweight personal data management system focused on:

- Simple needs of individual users
- Introductory tool for learning SQL syntax
- Demonstrating modern C++ programming practices

SQLite/MySQL are mature database engines with more powerful but complex features.

### Q: Will data be persisted to disk?

**A**: In the current version, data is only stored in memory and will be lost after program exit. Data persistence functionality is under development (v0.1.0 goal).

### Q: What SQL syntax is supported?

**A**: Currently supports basic CRUD operations:

- CREATE, DROP, USE, SHOW
- INSERT, SELECT
- LINK (table association)

More complex syntax (WHERE, JOIN, GROUP BY, etc.) is being gradually added.

### Q: How to participate in project development?

**A**:

1. Fork the project to your GitHub
2. Create a feature branch
3. Commit your changes
4. Submit a Pull Request

Since the project is maintained by a single person, we will try to respond and merge in a timely manner.

---

## Performance Benchmark

### Test Environment

- CPU: Intel Core i7-10700K
- Memory: 32GB DDR4
- Operating System: Windows 11 / Ubuntu 22.04
- Compiler: GCC 12.2 / MSVC 19.35

### Performance Metrics

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

## License

This project is licensed under the **MIT License**, see the [LICENSE](LICENSE) file for details.

---

## Contact

- **Author**: cn86-zhh (GitHub) / cn86-zhh (Gitee)
- **GitHub Project**: https://github.com/cn86-zhh/IronSQL
- **Gitee Project**: https://gitee.com/cn86-zhh/IronSQL (not currently pushed to Gitee)

---

## Acknowledgments

Thank you to all users and developers who have provided feedback, suggestions, and contributions to the IronSQL project.

Special thanks to:

- The C++ Standards Committee for providing excellent language features
- The MySQL team for providing aesthetic references for formatted output
- The open source community for providing valuable tools and libraries

---

<div align="center">

**If IronSQL has been helpful to you, please give us a Star ⭐**

Made with ❤️ by cn86-zhh

</div>
