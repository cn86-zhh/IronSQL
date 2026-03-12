#!/bin/bash

# Define file path

readonly BIN="bin"
readonly SRC="src"
readonly LOG="log"

# Define highlight color

readonly R="\033[1;31m"
readonly G="\033[1;32m"
readonly Y="\033[1;33m"
readonly B="\033[1;34m"
readonly M="\033[1;35m"
readonly C="\033[1;36m"
readonly W="\033[1;37m"
readonly w="\033[47m"
readonly E="\033[0m"

TIME=$(date "+%Y-%m-%d-%H-%M-%S")
readonly TIME

# Welcome prompt
function Welcome()
{
    local name0="${C}zhh${E}"
    local name1="${C}cn86-zhh${E}"
    
    readonly name0
    readonly name1
    
    echo -e "${R}${w}WELCOME TO USE 'makec++.sh' BASH SCRIPT COMPILE PROJECT 'IronSQL'${E}"
    echo -e "${C}Version${W}: ${G}0.0.1${E}"
    echo -e "${C}Author${W}: gitee(${name0}), github(${name1})"
    echo -e "${C}Time${W}: ${TIME}"
    echo -e "${M}Binary file${W}: ${B}./bin/ironsql${E}"
    echo -e "${M}Log    file${W}: ${B}./bin/compile.log${E}"
}

# Compile failed prompt
function CompileFailedPrompt()
{
    echo -e "${M}+--------------------------------------------+${E}"
    echo -e "${M}| ${R}COMPILE FAILED                             ${M}|${E}"
    echo -e "${M}| ${Y}Please check the log file for more details ${M}|${E}"
    echo -e "${M}+--------------------------------------------+${E}"
}

# Compile success prompt
function CompileSuccessPrompt()
{
    echo -e "${C}+--------------------------------------------+${E}"
    echo -e "${C}| ${G}COMPILE SUCCESS                            ${C}|${E}"
    echo -e "${C}| ${W}You can run binary program 'IronSQL' now   ${C}|${E}"
    echo -e "${C}+--------------------------------------------+${E}"
}

# Start compile IronSQL
function StartCompileIronSQL()
{
    local binary_file="${BIN}/ironsql"
    local log_file="${LOG}/compile.log"
    
    local header_include="${SRC}/include"
    local header_release="${SRC}/release"
    local header_kernel="${SRC}/kernel"
    local header_test="${SRC}/test"
    local header_logsystem="${SRC}/logsystem"
    local header_linux="${SRC}/linux"
    local header_windows="${SRC}/windows"
    local header_stdiostreams="${SRC}/stdiostreams"
    
    readonly binary_file
    readonly log_file
    readonly header_include
    readonly header_release
    readonly header_kernel
    readonly header_test
    
    # Define C++ source file array
    local cpp_file_array=(
        "${SRC}/iron_main.cpp"
        "${SRC}/test/iron_test.cpp"
        "${SRC}/library/iron_server.cpp"
        "${SRC}/library/iron_handle.cpp"
        "${SRC}/library/iron_status.cpp"
        "${SRC}/library/iron_fmtout.cpp"
        "${SRC}/library/iron_parser.cpp"
        "${SRC}/library/iron_help.cpp"
        "${SRC}/library/iron_pathfs.cpp"
        "${SRC}/release/iron_object.cpp"
        "${SRC}/kernel/iron_proces.cpp"
        "${SRC}/kernel/iron_keywds.cpp"
        "${SRC}/kernel/iron_verify.cpp"
        "${SRC}/kernel/iron_syntax.cpp"
        "${SRC}/logsystem/iron_logsystem.cpp"
        "${SRC}/stdiostreams/iron_stdost.cpp"
    )
    
    # Detect operating system
    # shellcheck disable=SC2155
    local os_type=$(uname -s)
    
    if [[ "$os_type" == MINGW* || "$os_type" == CYGWIN* || "$os_type" == MSYS* ]]; then
        # Windows system - compile with icon
        echo -e "${Y}Detected Windows system, compiling with icon...${E}"
        
        # Create resource file for icon
        # Use Windows-style path for windres
        local icon_path
        icon_path="$(pwd -W)/img/IronSQL_1.ico"
        cat > "${SRC}/resource.rc" << EOF
1 ICON "$icon_path"
EOF
        
        # Compile resource file
        windres "${SRC}/resource.rc" -o "${SRC}/resource.o"
        
        # Add resource object to compile command
        if g++ -std=c++20 -static -static-libgcc -static-libstdc++ \
        -I "${header_include}" \
        -I "${header_release}" \
        -I "${header_kernel}" \
        -I "${header_test}" \
        -I "${header_logsystem}" \
        -I "${header_windows}" \
        -I "${header_linux}" \
        -I "${header_stdiostreams}" \
        "${cpp_file_array[@]}" "${SRC}/resource.o" -o "${binary_file}" 2>"${log_file}"
        then
            # Clean up resource files
            rm -f "${SRC}/resource.rc" "${SRC}/resource.o"
            CompileSuccessPrompt
        else
            # Clean up resource files
            rm -f "${SRC}/resource.rc" "${SRC}/resource.o"
            CompileFailedPrompt
        fi
    else
        # Linux system - compile without icon
        echo -e "${Y}Detected Linux system, compiling without icon...${E}"
        
        if g++ -std=c++20 -static -static-libgcc -static-libstdc++ \
        -I "${header_include}" \
        -I "${header_release}" \
        -I "${header_kernel}" \
        -I "${header_test}" \
        -I "${header_logsystem}" \
        -I "${header_linux}" \
        -I "${header_windows}" \
        -I "${header_stdiostreams}" \
        "${cpp_file_array[@]}" -o "${binary_file}" 2>"${log_file}"
        then
            CompileSuccessPrompt
        else
            CompileFailedPrompt
        fi
    fi
}

# Main function
function Main()
{
    Welcome
    StartCompileIronSQL
}
Main