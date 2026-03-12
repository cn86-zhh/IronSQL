#include "iron_object.hpp"

namespace IronObject
{
    std::shared_mutex Interface::mtx;
    std::vector<IronStruct::Database> Interface::databases;
}
