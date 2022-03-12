const int N = 5e5 + 5;
int parent[N], Rank[N];

void init () {
	fr (i, 0, N) {
		parent[i] = i;
		Rank[i] = 0;
	}
}

int Find (int x) {
	if (parent[x] != x) {
		parent[x] = Find (parent[x]);
	}
	return parent[x];
}

void Union (int x, int y) {
	int x_id = Find (x);
	int y_id = Find (y);
	if (x_id == y_id) return;

	if (Rank[x_id] > Rank[y_id]) {
		parent[y_id] = x_id;
	} else {
		parent[x_id] = y_id;
		if (Rank[x_id] == Rank[y_id]) Rank[y_id]++;
	}
}