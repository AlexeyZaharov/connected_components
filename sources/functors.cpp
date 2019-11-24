#ifndef UNTITLED1_FUNCTORS_CPP
#define UNTITLED1_FUNCTORS_CPP

#include "common_resources.h"
#include "DSU.cpp"

template <bypass_type _type, typename T>
class D_or_B_FS {
    T back(std::stack<T>& stack) {
        return stack.top();
    }

    T back(std::queue<T>& queue) {
        return queue.front();
    }

    template <typename U>
    std::vector<size_t> get_one_component(U data_structure, const std::unordered_map<T, std::unordered_set<T>>& vertex_table,
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
    std::vector<std::vector<size_t>> operator()(const std::unordered_map<T, std::unordered_set<T>>& vertex_table) {
        std::vector<std::vector<size_t>> connected_components{};

        std::unordered_set<size_t> visited{};

        for (auto& v : vertex_table) {
            if (visited.find(v.first) == visited.end()) {
                connected_components.push_back(
                        _type == bypass_type::DFS
                        ? get_one_component(std::stack<T>(), vertex_table, v.first, visited)
                        : get_one_component(std::queue<T>(), vertex_table, v.first, visited));
            }
        }

        return connected_components;
    }
};

template <typename T>
class Kosaraju {

    static void dfs_for_ordering (const size_t& v, const std::unordered_map<T, std::unordered_set<T>>& vertex_table,
            std::unordered_set<size_t>& visited, std::vector<size_t>& order) {
        visited.insert(v);

        for (auto& neighbor : vertex_table.at(v)) {
            if (visited.find(neighbor) == visited.end())
                dfs_for_ordering (neighbor, vertex_table, visited, order);
        }

        order.push_back (v);
    }

    static void dfs_for_searching (const size_t& v, const std::unordered_map<T, std::unordered_set<T>>& vertex_table,
                            std::unordered_set<size_t>& visited, std::vector<size_t>& component) {
        visited.insert(v);
        component.push_back(v);

        for (auto& neighbor : vertex_table.at(v)) {
            if (visited.find(neighbor) == visited.end())
                dfs_for_searching(neighbor, vertex_table, visited, component);
        }
    }

public:

    std::vector<std::vector<T>> operator()(const std::unordered_map<T, std::unordered_set<T>>& vertex_table) {
        std::vector<std::vector<T>> connected_components{};

        std::vector<T> order{};
        std::vector<T> component{};

        std::unordered_map<T, std::unordered_set<T>> invert_vertex_table{};
        std::unordered_set<T> visited{};

        for (auto& elem : vertex_table) {
            invert_vertex_table.insert({elem.first, {}});
            for (auto& vertex : elem.second) {
                invert_vertex_table[vertex].insert(elem.first);
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

template <typename T>
class DSU_for_components {
public:
    std::vector<std::vector<size_t>> operator()(const std::unordered_map<T, std::unordered_set<T>>& vertex_table) {
        DSU<T> dsu;

        for (auto& elem : vertex_table) {
            dsu.make_set(elem.first);
        }

        for (auto& elem : vertex_table) {
            for (auto& edje : elem.second) {
                dsu.union_sets(elem.first, edje);
            }
        }

        return dsu.get_sets();
    }
};

#endif //UNTITLED1_FUNCTORS_CPP
