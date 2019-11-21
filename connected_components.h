#ifndef UNTITLED1_CONNECTED_COMPONENTS_H
#define UNTITLED1_CONNECTED_COMPONENTS_H

#include "functors.h"

#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <stack>
#include <queue>
#include <set>

//enum class traversall_type {DFS, BFS, DSU, Kosaraju};

class connected_components {

public:
    std::vector<std::vector<size_t>> get_traversall(const traversall_type& type, const std::unordered_map<size_t, std::vector<size_t>>& vertex_table) {
        std::vector<std::vector<size_t>> connected_components;
        std::unordered_set<size_t> visited{};

        switch (type) {
            case traversall_type::DFS: {
                connected_components = D_or_B_FS<traversall_type::DFS>()(vertex_table);
                break;
            }
            case traversall_type::BFS: {
                connected_components = D_or_B_FS<traversall_type::BFS>()(vertex_table);
                break;
            }
            case traversall_type::DSU: {

                break;
            }
            case traversall_type::Kosaraju: {
                connected_components = Kosaraju()(vertex_table);
                break;
            }
        }

        return connected_components;
    }
};


#endif //UNTITLED1_CONNECTED_COMPONENTS_H
