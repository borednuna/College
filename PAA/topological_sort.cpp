#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool dfs(int v, vector<vector<int>>& adjacency_list, vector<bool>& visited, vector<bool>& rec_stack, stack<int>& topological_order) {
    visited[v] = true;
    rec_stack[v] = true;

    for (int u : adjacency_list[v]) {
        if (!visited[u]) {
            if (dfs(u, adjacency_list, visited, rec_stack, topological_order)) {
                return true;
            }
        } else if (rec_stack[u]) {
            return true;
        }
    }

    rec_stack[v] = false;
    topological_order.push(v);
    return false;
}

bool topologicalSort(int n, vector<vector<int>>& adjacency_list, vector<int>& result) {
    vector<bool> visited(n + 1, false);
    vector<bool> rec_stack(n + 1, false);
    stack<int> topological_order;

    for (int v = 1; v <= n; v++) {
        if (!visited[v]) {
            if (dfs(v, adjacency_list, visited, rec_stack, topological_order)) {
                return false; // Graph contains a cycle
            }
        }
    }

    while (!topological_order.empty()) {
        result.push_back(topological_order.top());
        topological_order.pop();
    }

    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjacency_list(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjacency_list[u].push_back(v);
    }

    vector<int> result;
    if (topologicalSort(n, adjacency_list, result)) {
        for (int vertex : result) {
            cout << vertex << " ";
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
