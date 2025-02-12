#include <bits/stdc++.h>
using namespace std;

// #define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'
#define pb push_back
#define rm pop_back
#define f first
// #define s second
#define sz size
// #define in insert

typedef pair<int, int> p;
typedef long long ll;
const int MAX = 0x3f3f3f3f;
const ll LMAX = 0x3f3f3f3f3f3f3f3f;

typedef pair<int, int> p;
typedef long long ll;
const int MAX = 1e5 + 10;



int floydWarshalminmax(vector<vector<int>> &g, int s, int d){
    for (int k = 0; k < g.sz(); k++){
        for (int i = 0; i < g.sz(); i++){
            for (int j = 0; j < g.sz(); j++){
                g[i][j] = max(g[i][j], min(g[i][k], g[k][j]));
            }
        }
    }
    return g[s][d];
}

int main(){
    int n, m; cin >> m >> n;
    int dist[m][n];

    for (int k = 0; k < n; k++){
        // Pick all vertices as source one by one
        for (int i = 0; i < n; i++){
            // Pick all vertices as destination for the
            // above picked source
            for (int j = 0; j < n; j++){
                // If vertex k is on the shortest path from
                // i to j, then update the value of
                // dist[i][j]
                if (dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[k][j] != INF && dist[i][k] != INF))
                    dist[i][j] = dist[i][k] + dist[k][j];
                // or
                 dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    return 0;
}