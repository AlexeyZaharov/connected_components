#ifndef UNTITLED1_FUNCTORS_H
#define UNTITLED1_FUNCTORS_H

#include "common_resources.h"

template <bypass_type _type>
class D_or_B_FS {
    size_t back(std::stack<size_t>& stack) {
        return stack.top();
    }

    size_t back(std::queue<size_t>& queue) {
        return queue.front();
    }

    template <typename T>
    std::vector<size_t> get_one_component(T data_structure, const std::unordered_map<size_t, std::vector<size_t>>& vertex_table,
                               const size_t& start, std::unordered_set<size_t>& visited) {
        std::unordered_set<size_t> in_structure;
        std::vector<size_t> component{};

        data_structure.push(start);
        in_structure.insert(start);

        while (!data_structure.empty()) {
            size_t vertex = back(data_structure);
            data_structure.pop();

            if (visited.find(vertex) == visited.end()) {
                for (auto& elem : vertex_table.at(vertex)) {
                    if (in_structure.find(elem) == in_structure.end()) {
                        data_structure.push(elem);
                        in_structure.insert(elem);
                    }
                }
            }

            visited.insert(vertex);
            component.push_back(vertex);
        }

        return component;
    }

public:
    std::vector<std::vector<size_t>> operator()(const std::unordered_map<size_t, std::vector<size_t>>& vertex_table) {
        std::vector<std::vector<size_t>> connected_components{};

        std::unordered_set<size_t> visited{};

        for (auto& v : vertex_table) {
            if (visited.find(v.first) == visited.end()) {
                connected_components.push_back(
                        _type == bypass_type::DFS
                        ? get_one_component(std::stack<size_t>(), vertex_table, v.first, visited)
                        : get_one_component(std::queue<size_t>(), vertex_table, v.first, visited));
            }
        }

        return connected_components;
    }
};

class Kosaraju {

    void dfs_for_ordering (const size_t& v, const std::unordered_map<size_t, std::vector<size_t>>& vertex_table,
            std::unordered_set<size_t>& visited, std::vector<size_t>& order) {
        visited.insert(v);

        for (auto& neighbor : vertex_table.at(v)) {
            if (visited.find(neighbor) == visited.end())
                dfs_for_ordering (neighbor, vertex_table, visited, order);
        }

        order.push_back (v);
    }

    void dfs_for_searching (const size_t& v, const std::unordered_map<size_t, std::vector<size_t>>& vertex_table,
                            std::unordered_set<size_t>& visited, std::vector<size_t>& component) {
        visited.insert(v);
        component.push_back(v);

        for (auto& neighbor : vertex_table.at(v)) {
            if (visited.find(neighbor) == visited.end())
                dfs_for_searching(neighbor, vertex_table, visited, component);
        }
    }

public:

    std::vector<std::vector<size_t>> operator()(const std::unordered_map<size_t, std::vector<size_t>>& vertex_table) {
        std::vector<std::vector<size_t>> connected_components{};

        std::vector<size_t> order{};
        std::vector<size_t> component{};

        std::unordered_map<size_t, std::vector<size_t>> invert_vertex_table{};
        std::unordered_set<size_t> visited{};

        for (auto& elem : vertex_table) {
            invert_vertex_table.insert({elem.first, {}});
            for (auto& vertex : elem.second) {
                invert_vertex_table[vertex].push_back(elem.first);
            }
        }

        for (auto& elem : invert_vertex_table) {
            if (visited.find(elem.first) == visited.end()) {
                dfs_for_ordering(elem.first, invert_vertex_table, visited, order);
            }
        }

        visited.clear();

        for (auto it = order.rbegin(); it != order.rend(); ++it) {
            if (visited.find(*it) == visited.end()) {
                dfs_for_searching(*it, vertex_table, visited, component);

                connected_components.push_back(component);
                component.clear();
            }
        }

        return connected_components;
    }
};

#endif //UNTITLED1_FUNCTORS_H
