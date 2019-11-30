#include "graph.h"

bypass_type get_bypass_type(const std::string& type, const bool& is_directed) {
    if (type == "dfs") {
        return bypass_type::DFS;
    }
    if (type == "bfs") {
        return bypass_type::BFS;
    }
    if (type == "dsu") {
        return bypass_type::DSU;
    }
    if (type == "kos") {
        return bypass_type::Kosaraju;
    }
    return bypass_type::bad_type;
}