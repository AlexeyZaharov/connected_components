#ifndef UNTITLED1_GRAPH_H
#define UNTITLED1_GRAPH_H

#include <vector>
#include <unordered_set>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <set>

#include "connected_components.h"

//enum traversall_type {DFS, BFS, DSU, Kosaraju};

class graph {
    std::unordered_map<size_t, std::vector<size_t>> table;
    traversall_type type_of_traversall;

public:
    graph(){
        table.insert({1, {1,2}});
    }

};


#endif //UNTITLED1_GRAPH_H

/*class graph {
private:
    bool is_directed, is_DFS;
    std::unordered_map<std::string, std::vector<std::string>> table;


public:
    explicit graph (std::istringstream&& data) {
        char type, searching;

        data >> type >> start_vertex >> searching;

        is_directed = type == 'd';
        is_DFS = searching == 'd';

        std::string from, to;

        while (data >> from >> to) {
            //array_of_vertex.insert(from);
            //array_of_vertex.insert(to);

            if(is_directed) {
                table[from].push_back(to);
            }
            else {
                table[from].push_back(to);
                table[to].push_back(from);
            }
        }
    }

    std::string traversal() {
        return is_DFS ? traversal(std::stack<std::string>())
                      : traversal(std::queue<std::string>());
    }
};*/