#include <iostream>
#include <vector>

int answer = 0;

void dfs(int x, int vertex, int edge, int** graph, int* visited) {
	visited[x] = 1;
	for (int i = 1; i <= vertex; i++) {
		if (graph[x][i] == 1 && !visited[i]) {
			answer++;
			dfs(i, vertex, edge, graph, visited);
		}
	}
}

int main2606() {
	int vertex, edge;

	std::cin >> vertex;
	std::cin >> edge;

	int** graph = new int*[vertex+1];
	int* visited = new int[vertex+1];

	for (int i = 0; i < vertex+1; i++) {
		graph[i] = new int[vertex+1];
		visited[i] = 0;
	}

	for (int i = 0; i < vertex + 1; i++) {
		for (int j = 0; j < vertex + 1; j++) {
			graph[i][j] = -1;
		}
	}

	for (int i = 0; i < edge; i++) {
		int x, y;
		std::cin >> x >> y;
		graph[x-1][y-1] = graph[y-1][x-1] = 1;
	}
	
	dfs(0, vertex, edge, graph, visited);
	
	std::cout << answer << std::endl;

	return 0;
}
 