#ifndef UNTITLED1_DSU_TEMPLATE_IMPLEMENTATION_H
#define UNTITLED1_DSU_TEMPLATE_IMPLEMENTATION_H

#include "DSU.h"

template <typename T>
void DSU<T>::make_set(const T& data) {
    node* new_node = new node{data};

    nodes[data] = new_node;
}

template <typename T>
T& DSU<T>::find_set (const T& data) {
    if (nodes[data]->parent == nodes[data]) {
        return nodes[data]->data;
    }

    nodes[data]->parent = nodes[ find_set ((nodes[data]->parent)->data) ];

    return (nodes[data]->parent)->data;
}

template <typename T>
void DSU<T>::union_sets (const T& data1, const T& data2) {
    node* a = nodes[find_set (data1)];
    node* b = nodes[find_set (data2)];
    if (a != b) {
        if (a->rank < b->rank){
            std::swap (a, b);
        }

        b->parent = a;

        if (a->rank == b->rank)
            ++(a->rank);
    }
}

template <typename T>
std::vector<std::vector<T>> DSU<T>::get_sets() {
    std::unordered_map<T, std::vector<T>> temp_sets{};
    std::vector<std::vector<T>> set_of_sets{};

    for (auto node : nodes) {
        temp_sets[find_set(node.first)].push_back(node.first);
    }

    for (auto set : temp_sets) {
        set_of_sets.push_back(set.second);
    }

    return set_of_sets;
}

template <typename T>
DSU<T>::~DSU() {
    for (auto node : nodes) {
        delete node.second;
    }
}

#endif //UNTITLED1_DSU_TEMPLATE_IMPLEMENTATION_H
