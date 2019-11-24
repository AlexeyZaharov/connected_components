#include <iostream>
#include <fstream>
#include <sstream>

#include "graph.cpp"

bypass_type get_bypass_type(const std::string& type, const bool& is_directed) {
    if (type == "dfs" && !is_directed) {
        return bypass_type::DFS;
    }
    if (type == "bfs" && !is_directed) {
        return bypass_type::BFS;
    }
    if (type == "dsu" && !is_directed) {
        return bypass_type::DSU_for_unordered;
    }
    if (type == "dsu" && is_directed) {
        return bypass_type::DSU_for_ordered;
    }
    if (type == "kos" && is_directed) {
        return bypass_type::Kosaraju;
    }
    return bypass_type::bad_type;
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
            bypass_type type_of_bypass = get_bypass_type(searching_type, is_directed);

            if (type_of_bypass == bypass_type::bad_type) {
                continue;
            }
            else {
                right_data = true;
            }

            T from, to;
            my_graph.set_bypass_type(type_of_bypass);

            while (in >> from && in.good()) {
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