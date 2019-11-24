#ifndef UNTITLED1_CONNECTED_COMPONENTS_H
#define UNTITLED1_CONNECTED_COMPONENTS_H

#include "common_resources.h"

template <typename T>
class connected_components {
public:
    static std::vector<std::vector<T>> get_traversall(const bypass_type& type, const std::unordered_map<T,
            std::unordered_set<T>>& vertex_table);
};

#endif //UNTITLED1_CONNECTED_COMPONENTS_H
