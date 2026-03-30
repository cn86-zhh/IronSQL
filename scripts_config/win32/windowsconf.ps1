#!/usr/bin/env pwsh

# ********************************************************************
# * recommend use path: ...IronSQL/"current version project"         *
# ********************************************************************

[CmdletBinding()]
param()

$ErrorActionPreference = "Stop"

if ($PSScriptRoot -eq $null -or $PSScriptRoot -eq "") {
    $ScriptPath = Split-Path -Parent $MyInvocation.MyCommand.Path
}
else {
    $ScriptPath = $PSScriptRoot
}

$SOURCED = Join-Path $ScriptPath "..\..\src\.config"
$TARGETD = "C:\Users\IronSQL\.Config"

function Write-Ok {
    param(
        [Parameter(Mandatory = $true)]
        [string]$Message
    )
    
    Write-Host "[ OK! ]: " -ForegroundColor Red -BackgroundColor Green -NoNewline
    Write-Host ": " -ForegroundColor White -NoNewline
    Write-Host $Message
}

function Write-Ot {
    param(
        [Parameter(Mandatory = $true)]
        [string]$Message
    )
    
    Write-Host $Message -ForegroundColor Red -BackgroundColor DarkRed
}

function Initialize-Check {
    if (-not (Test-Path -Path $SOURCED -PathType Container)) {
        Write-Host "[Error]: not found source directory: $SOURCED" -ForegroundColor Red
        return $false
    }
    
    if (-not (Test-Path -Path $TARGETD -PathType Container)) {
        Write-Host "[Error]: not found target directory: $TARGETD" -ForegroundColor Red
        
        try {
            New-Item -Path $TARGETD -ItemType Directory -Force | Out-Null
            Write-Ok "created target directory: $TARGETD"
        }
        catch {
            Write-Host "[Error]: failed to create target directory: $TARGETD" -ForegroundColor Red
            return $false
        }
    }
    
    return $true
}

function Initialize-Delete {
    try {
        if (Test-Path -Path $TARGETD -PathType Container) {
            Get-ChildItem -Path $TARGETD -Recurse -Force | Remove-Item -Force -Recurse -ErrorAction Stop
            Write-Ok "deleted config files in target directory all: $TARGETD"
        }
    }
    catch {
        Write-Host "[Error]: failed to delete config files in target directory all: $TARGETD" -ForegroundColor Red
        return $false
    }
    
    return $true
}

function Initialize-CopyNewFiles {
    $ArrayList = @(
        (Join-Path $SOURCED "*.txt"),
        (Join-Path $SOURCED "*.conf"),
        (Join-Path $SOURCED ".syntax\*.txt"),
        (Join-Path $SOURCED ".syntax\zh_cn\*.txt"),
        (Join-Path $SOURCED ".syntax\en_us\*.txt")
    )
    
    foreach ($pattern in $ArrayList) {
        try {
            $files = Get-ChildItem -Path $pattern -File -ErrorAction SilentlyContinue
            
            foreach ($file in $files) {
                Copy-Item -Path $file.FullName -Destination $TARGETD -Force -ErrorAction Stop
                Write-Ok "copied config file: $($file.FullName)"
            }
        }
        catch {
            Write-Host "[Error]: failed to copy config file: $pattern" -ForegroundColor Red
            return $false
        }
    }
    
    return $true
}

function Main {
    Write-Ot "+---------------------------------------------------------------------------+"
    Write-Ot "| This script suitable for windows powershell 5.1+!                         |"
    Write-Ot "| Start copy config files to $TARGETD                       |"
    Write-Ot "| attention: windows powershell can not delete using remove-item directory! |"
    Write-Ot "| config directory can not sub directory!                                   |"
    Write-Ot "| run time: $(Get-Date -Format 'yyyy-MM-dd HH:mm:ss')                                             |"
    Write-Ot "+---------------------------------------------------------------------------+"
    if (-not (Initialize-Check)) {
        exit 1
    }
    
    if (-not (Initialize-Delete)) {
        exit 1
    }
    
    if (-not (Initialize-CopyNewFiles)) {
        exit 1
    }
    
    Write-Ok "copy config files to $TARGETD done"
    exit 0
}

Main
