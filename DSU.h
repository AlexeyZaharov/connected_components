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

        void make_set(const T& data) {
            node* new_node = new node{data};

            nodes[data] = new_node;
        }

        T& find_set (const T& data) {
            if (nodes[data]->parent == nodes[data]) {
                return nodes[data]->data;
            }

            nodes[data]->parent = nodes[ find_set ((nodes[data]->parent)->data) ];

            return (nodes[data]->parent)->data;
        }

        void union_sets (const T& data1, const T& data2) {
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

        std::vector<std::vector<T>> get_sets() {
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

        ~DSU() {
            for (auto node : nodes) {
                delete node.second;
            }
        }
    };

#endif //UNTITLED1_DSU_H
