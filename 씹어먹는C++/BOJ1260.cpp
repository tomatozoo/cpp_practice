#include <iostream>

void dfs(int start) {

}
void bfs(int start) {

}
int main() {
	int vertex, edge, start;
	std::cin >> vertex >> edge >> start;

	// ������ �����ϴ� �� ������ ��ȣ
	int** graph = new int* [vertex + 1];
	for (int i = 0; i < edge; i++) {

	}
	// �� ���� ���̿� ���� ���� ������ ���� �� �ִ� . �׳� �̰� ���� ���ϰ� �ϴ� �غ���! 

	dfs(start);
	bfs(start);

	return 0;
}