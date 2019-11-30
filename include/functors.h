#ifndef UNTITLED1_FUNCTORS_H
#define UNTITLED1_FUNCTORS_H

#include "common_resources.h"

template <bypass_type _type, typename T>
class D_or_B_FS {
    T back(std::stack<T>& stack);

    T back(std::queue<T>& queue);

    template <typename U>
    std::vector<T> get_one_component(U data_structure, const std::unordered_map<T, std::unordered_set<T>>& vertex_table,
                                          const size_t& start, std::unordered_set<size_t>& visited);

public:
    std::vector<std::vector<T>> operator()(const std::unordered_map<T, std::unordered_set<T>>& vertex_table);
};

template <typename T>
class Kosaraju {
    static void dfs_for_ordering (const size_t& v, const std::unordered_map<T, std::unordered_set<T>>& vertex_table,
                                  std::unordered_set<size_t>& visited, std::vector<size_t>& order);

    static void dfs_for_searching (const size_t& v, const std::unordered_map<T, std::unordered_set<T>>& vertex_table,
                                   std::unordered_set<size_t>& visited, std::vector<size_t>& component);

public:
    std::vector<std::vector<T>> operator()(const std::unordered_map<T, std::unordered_set<T>>& vertex_table);
};

template <typename T>
class DSU_for_components {
public:
    std::vector<std::vector<T>> operator()(const std::unordered_map<T, std::unordered_set<T>>& vertex_table);
};

#endif //UNTITLED1_FUNCTORS_H

#include "functors_template_implementation.h"