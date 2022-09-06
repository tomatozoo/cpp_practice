#include <iostream>

void dfs(int start) {

}
void bfs(int start) {

}
int main() {
	int vertex, edge, start;
	std::cin >> vertex >> edge >> start;

	// 간선이 연결하는 두 정점의 번호
	int** graph = new int* [vertex + 1];
	for (int i = 0; i < edge; i++) {

	}
	// 두 정점 사이에 여러 개의 간선이 있을 수 있다 . 그냥 이거 생각 안하고 일단 해보자! 

	dfs(start);
	bfs(start);

	return 0;
}