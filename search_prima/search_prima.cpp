#include <iostream>
#include <limits>
#include "vector"
#include "algorithm"
#include "set"
#include "search_prima.h"

using namespace std;

void Graph::print_list() {
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << i << ":";
        for (const auto& v : vec[i]) {
            cout << v << " ";
        }
        cout << endl;
    }
}

void Graph::search_prima() {
    if (vec.empty()) throw "No MST!";

    rezult.clear();
    rezult.reserve(vec.size());
    for (size_t i = 0; i < vec.size(); ++i) {
        rezult.emplace_back(-1, -1);
    }

    set<pair<int, int>> q;

    const int INF = numeric_limits<int>::max();
    vector<int> min_e(vec.size(), INF);
    min_e[0] = 0;

    q.insert({0, 0});

    for (size_t i = 0; i < vec.size(); ++i) {
        const int v = q.begin()->second;
        q.erase(q.begin());

        rezult[v].first = v;

        for (size_t z = 0; z + 1 < vec[v].size(); z += 2) {
            auto it = vec[v].begin();
            advance(it, static_cast<long>(z));
            const int to = *it;

            ++it;
            const int weight = *it;

            if (weight < min_e[to] && i != vec.size() - 1) {
                q.erase({min_e[to], to});
                min_e[to] = weight;
                rezult[to].second = v;
                q.insert({min_e[to], to});
            }
        }
    }

    sum = 0;
    for (size_t i = 0; i < vec.size(); ++i) {
        if (min_e[i] < INF) {
            sum += min_e[i];
        }
    }

    rezult.erase(
        remove_if(rezult.begin(), rezult.end(),
                  [](const auto& p) { return p.second == -1; }),
        rezult.end()
    );
}

