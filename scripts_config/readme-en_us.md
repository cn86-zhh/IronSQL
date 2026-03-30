# IronSQL Scripts Config Directory

## Overview

This directory contains IronSQL configuration deployment scripts for copying necessary configuration files to system-specified locations.

### Included Files

| File                    | Platform | Description                                                     |
| ----------------------- | -------- | --------------------------------------------------------------- |
| `linux/linuxconf.sh`    | Linux    | Bash script, deploys config to `/etc/ironsql/.config`           |
| `win32/windowsconf.sh`  | Windows  | Bash script, deploys config to `C:\Users\IronSQL\.Config`       |
| `win32/windowsconf.ps1` | Windows  | PowerShell script, deploys config to `C:\Users\IronSQL\.Config` |

### Usage

#### Windows Platform

**Method 1: PowerShell (Recommended)**

```powershell
# Execute in project root directory
powershell .\scripts_config\win32\windowsconf.ps1
```

**Method 2: Git Bash**

```bash
# Execute in project root directory
./scripts_config/win32/windowsconf.sh
```

#### Linux Platform

```bash
# Execute in project root directory, requires root privileges
sudo ./scripts_config/linux/linuxconf.sh
```

### Configuration File List

The scripts will copy the following configuration files:

| File Type          | Path                              | Description                      |
| ------------------ | --------------------------------- | -------------------------------- |
| Text Files         | `src/.config/*.txt`               | Help documents, welcome messages |
| Config Files       | `src/.config/*.conf`              | Program settings                 |
| Syntax Definitions | `src/.config/.syntax/*.txt`       | SQL syntax definitions           |
| Chinese Syntax     | `src/.config/.syntax/zh_cn/*.txt` | Chinese syntax definitions       |
| English Syntax     | `src/.config/.syntax/en_us/*.txt` | English syntax definitions       |

### Notes

- **Windows**: Ensure write permission to `C:\Users\IronSQL\.Config` directory
- **Linux**: Must run with `sudo` or as root user
- Missing configuration files may cause IronSQL to crash or malfunction
