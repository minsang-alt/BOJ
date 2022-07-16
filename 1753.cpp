#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define INF 100000000
#define endl '\n'
vector<pair<int, int>> vec[20001];
int dis[20001];
void djikstra(int V,int start)
{
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));
	dis[start] = 0;

	while (!pq.empty())
	{
		int current = pq.top().second;
		int distance = -pq.top().first;
		pq.pop();
		if (distance > dis[current]) continue;
		for (int i = 0; i < vec[current].size(); i++)
		{
			int cost = distance + vec[current][i].second;
			if (distance + vec[current][i].second < dis[vec[current][i].first]) {
				dis[vec[current][i].first] = distance + vec[current][i].second;
				pq.push(make_pair(-cost, vec[current][i].first));

			}
		}
	}
}
int main()
{
	int V, E;
	cin >> V >> E;
	int K;
	cin >> K;
	for (int i = 0; i < E; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		vec[u].push_back(make_pair(v, w));
	}
	fill(dis, dis + 20001, INF);
	djikstra(V, K);
	for (int i = 1; i <= V; i++)
	{
		if (dis[i] == INF) cout << "INF" << endl;
		else {
			cout << dis[i] << endl;
		}
	}

}
