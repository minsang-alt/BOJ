#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 20000001

vector<pair<int, int>> graph[801];
int dist[801];


void dijkstra(int start)
{
	fill(dist, dist + 801, INF);
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));
	dist[start] = 0;

	while (!pq.empty())
	{
		int current = pq.top().second;
		int distance = -pq.top().first;

		pq.pop();
		if (distance > dist[current])continue;
		for (int i = 0; i < graph[current].size(); i++)
		{
			int cost = distance + graph[current][i].second;
			if (cost < dist[graph[current][i].first])
			{
				dist[graph[current][i].first] = cost;
				pq.push(make_pair(-cost, graph[current][i].first));
			}
		}
	}


}

int main()
{
	int N, E;
	cin >> N >> E;
	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
		graph[b].push_back(make_pair(a, c));

	}
	
	int v1, v2;
	cin >> v1 >> v2;
	int sum1 = 0;
	int sum2 = 0;

	dijkstra(1);
	sum1 += dist[v1];
	sum2 += dist[v2];


	dijkstra(v1);
	sum1+= dist[v2];
	
	sum2 += dist[v2];


	dijkstra(v2);
 	sum1+= dist[N];
	dijkstra(v1);
	sum2 += dist[N];

	sum1 = sum1 < sum2 ? sum1 : sum2;




	if (sum1 >= INF) cout << -1;
	else cout << sum1; 
}
