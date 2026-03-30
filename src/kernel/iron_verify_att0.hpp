#pragma once

#ifndef IRON_VERIFY_ATT0_HPP
#define IRON_VERIFY_ATT0_HPP

#include "iron_attribute.hpp"

namespace IronVerifyAtt0
{
    class InspectorAtt0
    {

    private:
        InspectorAtt0() = delete;
        ~InspectorAtt0() = delete;

    public:
        static auto allow_permission_r(const std::string &permission) -> bool;
        static auto allow_permission_w(const std::string &permission) -> bool;
        static auto allow_permission_x(const std::string &permission) -> bool;
        static auto allow_permission_l(const std::string &permission) -> bool;
        static auto allow_attribute_vr(const std::string &attribute_) -> std::string;
    }; // InspectorAtt0
}

#endif // IRON_VERIFY_ATT0_HPP