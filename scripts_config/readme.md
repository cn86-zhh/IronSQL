# IronSQL Scripts Config Directory

## 目录说明

此目录包含 IronSQL 的配置文件部署脚本，用于将必要的配置文件复制到系统指定位置。

### 包含文件

| 文件                    | 平台    | 说明                                                   |
| ----------------------- | ------- | ------------------------------------------------------ |
| `linux/linuxconf.sh`    | Linux   | Bash 脚本，部署配置到 `/etc/ironsql/.config`           |
| `win32/windowsconf.sh`  | Windows | Bash 脚本，部署配置到 `C:\Users\IronSQL\.Config`       |
| `win32/windowsconf.ps1` | Windows | PowerShell 脚本，部署配置到 `C:\Users\IronSQL\.Config` |

### 使用方法

#### Windows 平台

**方式一：PowerShell（推荐）**

```powershell
# 在项目根目录执行
powershell .\scripts_config\win32\windowsconf.ps1
```

**方式二：Git Bash**

```bash
# 在项目根目录执行
./scripts_config/win32/windowsconf.sh
```

#### Linux 平台

```bash
# 在项目根目录执行，需要 root 权限
sudo ./scripts_config/linux/linuxconf.sh
```

### 配置文件清单

脚本会复制以下配置文件：

| 文件类型 | 路径                              | 说明               |
| -------- | --------------------------------- | ------------------ |
| 文本文件 | `src/.config/*.txt`               | 帮助文档、欢迎信息 |
| 配置文件 | `src/.config/*.conf`              | 程序设置           |
| 语法定义 | `src/.config/.syntax/*.txt`       | SQL 语法定义       |
| 中文语法 | `src/.config/.syntax/zh_cn/*.txt` | 中文语法定义       |
| 英文语法 | `src/.config/.syntax/en_us/*.txt` | 英文语法定义       |

### 注意事项

- **Windows**：确保有写入 `C:\Users\IronSQL\.Config` 目录的权限
- **Linux**：必须使用 `sudo` 或以 root 用户运行脚本
- 缺失配置文件可能导致 IronSQL 程序崩溃或功能异常
