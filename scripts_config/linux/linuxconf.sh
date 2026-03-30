#!/bin/bash

# ********************************************************************
# * recommend use path: ...IronSQL/"current version project"         *
# ********************************************************************

readonly SOURCED="../../src/.config"
readonly TARGETD="/etc/ironsql/.config"

ok() {
    echo -e "\033[42m\033[31m[ OK! ]\033[0m\033[37m:\033[0m ${1}"
}

ot() {
    echo -e "\033[41m\033[1;31m${1}\033[0m"
}

init_check() {
    
    if [[ "$(id -u)" -ne 0 ]]; then
        echo -e "[Error]: this script must be run as root!"
        return 1
    fi
    
    if [[ ! -d "${SOURCED}" ]]; then
        echo -e "[Error]: not found source directory: ${SOURCED}"
        return 1
    fi
    
    if [[ ! -d "${TARGETD}" ]]; then
        
        echo -e "[Error]: not found target directory: ${TARGETD}"
        if ! mkdir -p "${TARGETD}"; then
            echo -e "[Error]: failed to create target directory: ${TARGETD}"
            return 1
        else
            ok "created target directory: ${TARGETD}"
        fi
        
    fi
    
    return 0
}

init_delete() {
    
    # shellcheck disable=SC2115
    if ! /bin/rm -rf ${TARGETD}/*; then
        echo -e "[Error]: failed to delete config files in target directory all: ${TARGETD}"
        return 1
    fi
    
    ok "deleted config files in target directory all: ${TARGETD}"
    return 0
    
}

init_copy_new_files() {
    # shellcheck disable=SC2206
    local ArrayList=(
        $SOURCED/*.txt
        $SOURCED/*.conf
        $SOURCED/.syntax/*.txt
        $SOURCED/.syntax/zh_cn/*.txt
        $SOURCED/.syntax/en_us/*.txt
    )
    
    for fe in "${ArrayList[@]}"; do
        if ! /bin/cp -f "${fe}" "${TARGETD}"; then
            echo -e "[Error]: failed to copy config file: ${fe}"
            return 1
        fi
        ok "copied config file: ${fe}"
    done
    
    return 0
}

main() {
    # 0
    ot "This script suitable for linux bash!"
    ot "Start copy config files to ${TARGETD}"
    ot "attention: linux bash can not delete using rm -rf directory!"
    ot "config directory can not sub directory!"
    ot "run time: $(date '+%Y-%m-%d %H:%M:%S')"
    
    # 1
    if ! init_check; then
        return 1
    fi
    
    # 2
    if ! init_delete; then
        return 1
    fi
    
    # 3
    if ! init_copy_new_files; then
        return 1
    fi
    
    ok "copy config files to ${TARGETD} done"
    return 0
}

main
