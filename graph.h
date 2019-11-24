#ifndef UNTITLED1_GRAPH_H
#define UNTITLED1_GRAPH_H

#include "common_resources.h"

template <typename T>
class graph {
    std::unordered_map<T, std::unordered_set<T>> vertex_table;
    bypass_type type_of_bypass;

    bool have_edje(const std::pair<T, T>& edje);

public:
    graph() : vertex_table{}, type_of_bypass{} {};
    graph(const graph& another) = default;
    graph(graph&& another) = default;

    explicit graph(const std::unordered_map<T, std::unordered_set<T>>& table_,
            const bypass_type& type_of_bypass_ = bypass_type::DFS) : vertex_table{table_},
                                                                     type_of_bypass{type_of_bypass_} {};

    void add_edje(const std::pair<T, T>& edje);

    void delete_edje(const std::pair<T, T>& edje);

    void add_vertex(const T& v);

    void delete_vertex(const T& v);

    void set_bypass_type(const bypass_type& type);

    std::vector<std::vector<T>> find_connected_components() const;
};

#endif //UNTITLED1_GRAPH_H
