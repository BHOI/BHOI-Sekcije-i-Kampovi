#include <iostream>
#include <vector>
#include <cmath>

constexpr int MAX_N = 1000;

struct edge {
	size_t u, v, w;

	edge() { }
	edge(size_t _v, size_t _w) : v(_v), w(_w) { }
	edge(size_t _u, size_t _v, size_t _w) : u(_u), v(_v), w(_w) { }

	bool operator< (const edge &e) const {
		if (w != e.w)
			return w < e.w;
		if (v != e.v)
			return v < e.v;
		return u < e.u;
	}
};

template<class T>
using matrix =
	std::vector<std::vector<T>>;

using graph =
	matrix<edge>;

using ptt =
		std::pair<size_t, size_t>;

int main() {
	std::freopen("/Users/elvir/CLionProjects/BHOI-Sekcije-i-Kampovi/Januarski Kamp 2019/Napredna/Dan 4/in.txt", "r", stdin);
	size_t t;
	std::cin >> t;
	while (t--) {
		size_t v, e;
		std::cin >> v >> e;

		auto LIFT_DEPTH = (size_t) std::ceil(std::log2(v));
		matrix<ptt> lift(v, std::vector<ptt>(LIFT_DEPTH));
		size_t best, secondBest;
		graph g(v);
		graph mst(v);
		std::vector<bool> taken(v);
		std::vector<edge> edges;
		edges.reserve(e);

		std::vector<size_t> sz(v, 1);
		std::vector<size_t> parent(v);

		// union find
		std::function<size_t(size_t)> _find = [&](size_t x) -> size_t {
			if (parent[x] == x)
				return x;
			return parent[x] = _find(parent[x]);
		};

		auto _union = [&](size_t x, size_t y) -> bool {
			if (parent[x] == parent[y]) {
				return false;
			}

			size_t pX = _find(x), pY = _find(y);

			if (sz[pX] <= sz[pY]) {
				sz[pY] += sz[pX];
				parent[y] = pX;
			} else {
				sz[pX] += sz[pY];
				parent[x] = pY;
			}

			return true;
		};

		// init
		for (size_t i = 0; i < v; i++) {
			parent[i] = i;
			lift[i][0] = {i, 0};
		}

		// input
		for (int i = 0; i < e; i++) {
			size_t x, y, w;
			std::cin >> x >> y >> w;
			x--;
			y--;
			g[x].emplace_back(y, w);
			g[y].emplace_back(x, w);
			edges.emplace_back(x, y, w);
		}

		// krukal
		std::sort(edges.begin(), edges.end());

		size_t eid{};
		for (const auto &edge : edges) {
			if (_union(edge.u, edge.v)) {
				taken[eid] = true;
				best += edge.w;
				mst[edge.u].emplace_back(edge);
				mst[edge.v].emplace_back(edge);
			}
			eid++;
		}

		// binary lift
		std::vector<size_t> in(v), out(v);
		size_t time{};
		std::function<void(size_t)> dfs = [&](size_t v) {
			in[v] = ++time;

			for (size_t i = 1; i <= LIFT_DEPTH; i++) {
				size_t mx = lift[v][i - 1].second;
				mx = std::max(lift[lift[v][i - 1].first][i - 1].second, mx);
				lift[v][i] = {lift[lift[v][i - 1].first][i - 1].first, mx};
			}

			for (const auto& next : mst[v]) {
				if (!in[next.v]) {
					dfs(next.v);
				}
			}

			out[v] = ++time;
		};

		auto isAncestor = [&](size_t u, size_t v) -> bool {
			return in[u] <= in[v] && out[u] >= out[v];
		};

		std::function<ptt(size_t, size_t)> lca = [&](size_t u, size_t v) -> ptt {
			if (isAncestor(u, v)) {
				std::swap(u, v);
			}

			size_t mx{};
			for (size_t i = LIFT_DEPTH; i >= 1; i--) {
				if (!isAncestor(u, v)) {
					mx = std::max(lift[u][i].second, mx);
					u = lift[u][i].first;
				}
			}

			return {u, mx};
		};

		// second-best mst

		dfs(0);

		for (int i = 0; i < edges.size(); i++) {
			if (!taken[i]) {
				auto ans = lca(edges[i].u, edges[i].v);
				secondBest = std::min(best - ans.second + edges[i].w, secondBest);
			}
		}


		std::cout << best << ' ' << secondBest << '\n';
	}

	
	return 0;
}