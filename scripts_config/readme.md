# IronSQL Scripts Config Directory

## zh_CN

### 目录说明

此目录用于快速配置 IronSQL 的相关文件，包括：

- **配置加载文件**
- **设置文件**
- **帮助文档**
- **其他必要的配置文件**

### 重要性

**请注意：** 缺失这些配置文件可能导致 IronSQL 程序崩溃或功能异常。

### 目录结构

```
scripts_config/
├── linux/          # Linux 平台配置脚本
│   └── linuxconf.sh
├── win32/          # Windows 平台配置脚本
│   ├── windowsconf.ps1
│   └── windowsconf.sh
└── readme.md       # 此说明文件
```

### 使用方法

#### Windows 平台

1. 运行 `windowsconf.ps1` PowerShell 脚本
2. 或运行 `windowsconf.sh` Bash 脚本 (需要 Git Bash 或 WSL)

#### Linux 平台

1. 运行 `linuxconf.sh` Bash 脚本

这些脚本会将必要的配置文件复制到系统指定位置，确保 IronSQL 能够正常运行。

## en_US

### Directory Description

This directory is used for quickly configuring IronSQL-related files, including:

- **Configuration loading files**
- **Settings files**
- **Help documents**
- **Other necessary configuration files**

### Importance

**Please note:** Missing these configuration files may cause IronSQL program to crash or function abnormally.

### Directory Structure

```
scripts_config/
├── linux/          # Linux platform configuration scripts
│   └── linuxconf.sh
├── win32/          # Windows platform configuration scripts
│   ├── windowsconf.ps1
│   └── windowsconf.sh
└── readme.md       # This description file
```

### Usage

#### Windows Platform

1. Run `windowsconf.ps1` PowerShell script
2. Or run `windowsconf.sh` Bash script (requires Git Bash or WSL)

#### Linux Platform

1. Run `linuxconf.sh` Bash script

These scripts will copy the necessary configuration files to the system's specified location to ensure IronSQL can run normally.
