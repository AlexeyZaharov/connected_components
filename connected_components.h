#ifndef UNTITLED1_CONNECTED_COMPONENTS_H
#define UNTITLED1_CONNECTED_COMPONENTS_H

#include "common_resources.h"
#include "functors.h"

class connected_components {
public:
    std::vector<std::vector<size_t>> get_traversall(const bypass_type& type, const std::unordered_map<size_t, std::vector<size_t>>& vertex_table) {
        std::vector<std::vector<size_t>> connected_components;
        std::unordered_set<size_t> visited{};

        switch (type) {
            case bypass_type::DFS: {
                connected_components = D_or_B_FS<bypass_type::DFS>()(vertex_table);
                break;
            }
            case bypass_type::BFS: {
                connected_components = D_or_B_FS<bypass_type::BFS>()(vertex_table);
                break;
            }
            case bypass_type::DSU: {

                break;
            }
            case bypass_type::Kosaraju: {
                connected_components = Kosaraju()(vertex_table);
                break;
            }
        }

        return connected_components;
    }
};


#endif //UNTITLED1_CONNECTED_COMPONENTS_H
