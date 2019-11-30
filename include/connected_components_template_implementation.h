#ifndef UNTITLED1_CONNECTED_COMPONENTS_TEMPLATE_IMPLEMENTATION_H
#define UNTITLED1_CONNECTED_COMPONENTS_TEMPLATE_IMPLEMENTATION_H

#include "connected_components.h"
#include "functors.h"

template <typename T>
std::unordered_map<T, std::unordered_set<T>> make_vertex_table_for_unordered_graph(const std::unordered_map<T,
        std::unordered_set<T>>& vertex_table) {
    std::unordered_map<T, std::unordered_set<T>> unordered_vertex_table{vertex_table};

    for (auto& elem : unordered_vertex_table) {
        for (auto& vertex : elem.second) {
            unordered_vertex_table[vertex].insert(elem.first);
        }
    }

    return unordered_vertex_table;
}

template <typename T>
std::vector<std::vector<T>> connected_components<T>::get_traversall(const bypass_type& type, const bool& is_directed,
                                                                    const std::unordered_map<T, std::unordered_set<T>>& vertex_table) {

    std::vector<std::vector<T>> connected_components{};

    switch (type) {
        case bypass_type::bad_type: {
            break;
        }
        case bypass_type::DFS: {
            if (!is_directed) {
                connected_components = D_or_B_FS<bypass_type::DFS, T>()(vertex_table);
            }
            else {
                auto unordered_vertex_table = make_vertex_table_for_unordered_graph(vertex_table);
                connected_components = D_or_B_FS<bypass_type::DFS, T>()(unordered_vertex_table);
            }

            break;
        }
        case bypass_type::BFS: {
            if (!is_directed) {
                connected_components = D_or_B_FS<bypass_type::BFS, T>()(vertex_table);
            }
            else {
                auto unordered_vertex_table = make_vertex_table_for_unordered_graph(vertex_table);
                connected_components = D_or_B_FS<bypass_type::DFS, T>()(unordered_vertex_table);
            }
            break;
        }
        case bypass_type::DSU: {
            if (!is_directed) {
                connected_components = DSU_for_components<T>()(vertex_table);
            }
            else {
                auto unordered_vertex_table = make_vertex_table_for_unordered_graph(vertex_table);
                connected_components = DSU_for_components<T>()(unordered_vertex_table);
            }
            break;
        }
        case bypass_type::Kosaraju: {
            connected_components = Kosaraju<T>()(vertex_table);
            break;
        }
    }

    return connected_components;
}

#endif //UNTITLED1_CONNECTED_COMPONENTS_TEMPLATE_IMPLEMENTATION_H
