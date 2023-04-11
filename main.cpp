#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<ll>;

constexpr auto inf = int{ 987'654'321 };

int bfs(const map<int, int>& rs) {
	auto dist = vi(107, inf);
	dist[1] = 0;

	auto q = queue<int>{};
	q.push(1);

	while (!q.empty()) {
		auto f = q.front();
		q.pop();

		if (100 <= f) {
			break;
		}

		for (auto i = 1; i <= 6; ++i) {
			const auto& next = f + i;

			if (dist[f] + 1 < dist[next]) {
				dist[next] = dist[f] + 1;

				if (rs.contains(next)) {
					const auto& nn = rs.at(next);
					if (dist[f] + 1 < dist[nn]) {
						dist[nn] = dist[f] + 1;
						q.push(nn);
					}
				}
				else {
					q.push(next);
				}
			}
		}
	}

	return dist[100];
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	auto rs = map<int, int>{};
	for (auto i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		rs[x] = y;
	}
	for (auto i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		rs[x] = y;
	}

	const auto& ans = bfs(rs);
	cout << ans;

	return 0;
}