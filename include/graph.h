#ifndef UNTITLED1_GRAPH_H
#define UNTITLED1_GRAPH_H

#include "common_resources.h"

bypass_type get_bypass_type(const std::string& type, const bool& is_directed);

template <typename T>
class graph {
    std::unordered_map<T, std::unordered_set<T>> vertex_table;
    bool is_directed;
    bypass_type type_of_bypass;

    bool have_edje(const std::pair<T, T>& edje);

public:
    graph() : vertex_table{}, is_directed{}, type_of_bypass{} {};
    graph(const graph& another) = default;
    graph(graph&& another) = default;

    explicit graph(const bool& is_directed_) : vertex_table{}, is_directed{is_directed_}, type_of_bypass{} {};
    explicit graph(const std::unordered_map<T, std::unordered_set<T>>& table_, const bool& is_directed_,
            const bypass_type& type_of_bypass_ = bypass_type::DFS) : vertex_table{table_}, is_directed{is_directed_},
                                                                     type_of_bypass{type_of_bypass_} {};

    void add_edje(const std::pair<T, T>& edje);

    void delete_edje(const std::pair<T, T>& edje);

    void add_vertex(const T& v);

    void delete_vertex(const T& v);

    void set_bypass_type(const bypass_type& type);

    void set_directing_type(const bool& type);

    std::vector<std::vector<T>> find_connected_components() const;
};

template <typename T>
graph<T> make_graph_from_istream(std::istream& data);

#endif //UNTITLED1_GRAPH_H

#include "graph_template_implementation.h"