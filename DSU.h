#ifndef UNTITLED1_DSU_H
#define UNTITLED1_DSU_H

#include "common_resources.h"

template <typename T>
class DSU {
        struct node {
            T data;
            size_t rank;
            node* parent;

            node() : data{}, rank{}, parent{nullptr} {}

            explicit node(const T& data_) : data{data_}, rank{}, parent{this} {}
        };

        std::unordered_map<T, node*> nodes;

    public:
        DSU() : nodes{} {}

        void make_set(const T& data);

        T& find_set (const T& data);

        void union_sets (const T& data1, const T& data2);

        std::vector<std::vector<T>> get_sets();

        ~DSU();
    };

#endif //UNTITLED1_DSU_H
