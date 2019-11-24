#include "connected_components.h"
#include "functors.cpp"

template <typename T>
std::vector<std::vector<T>> connected_components<T>::get_traversall(const bypass_type& type, const std::unordered_map<T,
        std::unordered_set<T>>& vertex_table) {

    std::vector<std::vector<T>> connected_components{};

    switch (type) {
        case bypass_type::bad_type: {
            break;
        }
        case bypass_type::DFS: {
            connected_components = D_or_B_FS<bypass_type::DFS, T>()(vertex_table);
            break;
        }
        case bypass_type::BFS: {
            connected_components = D_or_B_FS<bypass_type::BFS, T>()(vertex_table);
            break;
        }
        case bypass_type::DSU_for_unordered: {
            connected_components = DSU_for_components<T>()(vertex_table);
            break;
        }
        case bypass_type::DSU_for_ordered: {
            connected_components = DSU_for_components<T>()(vertex_table);
            break;
        }
        case bypass_type::Kosaraju: {
            connected_components = Kosaraju<T>()(vertex_table);
            break;
        }
    }

    return connected_components;
}