#ifndef UNTITLED1_GRAPH_TEMPLATE_IMPLEMENTATION_H
#define UNTITLED1_GRAPH_TEMPLATE_IMPLEMENTATION_H

#include "graph.h"
#include "connected_components.h"

template <typename T>
bool graph<T>::have_edje(const std::pair<T, T>& edje) {
    return vertex_table.find(edje.first) != vertex_table.end()
           ? vertex_table[edje.first].find(edje.second) != vertex_table[edje.first].end()
           : false;
}

template <typename T>
void graph<T>::add_edje(const std::pair<T, T>& edje) {
    if (vertex_table.find(edje.second) == vertex_table.end()) vertex_table.insert({edje.second, {}});
    vertex_table[edje.first].insert(edje.second);
}

template <typename T>
void graph<T>::delete_edje(const std::pair<T, T>& edje) {
    if (have_edje(edje)) {
        vertex_table[edje.first].erase(edje.second);
    }
}

template <typename T>
void graph<T>::add_vertex(const T& v) {
    vertex_table.insert({v, {} });
}

template <typename T>
void graph<T>::delete_vertex(const T& v) {
    vertex_table.erase(v);

    for (auto& elem : vertex_table) {
        delete_edje({elem.first, v});
    }
}

template <typename T>
void graph<T>::set_bypass_type(const bypass_type& type) {
    type_of_bypass = type;
}

template <typename T>
void graph<T>::set_directing_type(const bool& is_directed_){
    is_directed = is_directed_;
}

template <typename T>
std::vector<std::vector<T>> graph<T>::find_connected_components() const {
    return connected_components<T>::get_traversall(type_of_bypass, is_directed, vertex_table);
}

template <typename T>
graph<T> make_graph_from_istream(std::istream& data) {
    char ordered_type{};
    std::string searching_type{};
    std::string buf{};

    std::getline(data, buf, '\0');
    std::istringstream in(buf);
    graph<T> my_graph{};

    bool right_data = false;

    while (!right_data && in.good()) {
        if (in >> ordered_type && in.peek() != '\n' && in >> searching_type && in.peek() == '\n') {
            bool is_directed = ordered_type == 'd';
            my_graph.set_directing_type(is_directed);
            bypass_type type_of_bypass = get_bypass_type(searching_type, is_directed);

            if (type_of_bypass == bypass_type::bad_type) {
                continue;
            }
            else {
                right_data = true;
            }

            T from, to;
            my_graph.set_bypass_type(type_of_bypass);

            while (in.good() && in >> from) {
                my_graph.add_vertex(from);

                while (in.peek() != '\n' && in.good()) {
                    in >> to;

                    if (is_directed) {
                        my_graph.add_edje({from, to});
                    } else {
                        my_graph.add_edje({from, to});
                        my_graph.add_edje({to, from});
                    }
                }
            }
        }
        else {
            in.ignore(256, '\n');
        }
    }

    return my_graph;
}

#endif //UNTITLED1_GRAPH_TEMPLATE_IMPLEMENTATION_H
