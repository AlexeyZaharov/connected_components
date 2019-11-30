#include <iostream>
#include <fstream>

#include "graph.h"

int main(int argc, char* argv[]) {
    if(argc > 2) {
        std::ifstream fin(argv[1]);
        std::ofstream fout(argv[2]);

        if (fin.is_open() && fout.is_open()) {
            graph<size_t> graph = make_graph_from_istream<size_t>(fin);
            auto sets = graph.find_connected_components();

            for (auto& vec : sets) {
                for (size_t i = 0; i < vec.size(); ++i) {
                    fout << vec[i] << (i == vec.size() - 1 ? '\n' : ' ');
                }
            }
        }
    }

    return 0;
}