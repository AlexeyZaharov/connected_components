#include "graph.h"
#include "connected_components.cpp"

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
std::vector<std::vector<T>> graph<T>::find_connected_components() const {
        return connected_components<T>::get_traversall(type_of_bypass, vertex_table);
    }