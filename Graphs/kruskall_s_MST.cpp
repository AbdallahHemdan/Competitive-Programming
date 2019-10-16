const int N = 1e5+5;

vector< pair< int, pair<int,int> > edges; // {cost, {u,v}}

int par[N];
int num[N];
 
for(int i=0;i<N;i++) // Initialization in main
{  
	par[i] = i;
	num[i] = 1;
}

int FindSet(int n) // Use FindSet instead of par
{
	if(par[n] == n)
		return n;
	return par[n] = find_set(par[n]);
}
 
void Union(int x,int y)
{
	x = find_set(x);
	y = find_set(y);
	if(x==y)
		return;
	par[x]=y;
	num[y] += num[x]; // num holds number of elements in a group
}

int getMST() // Returns summation of edges of Minimum Spanning Tree and builds the tree in DSU
{
    int sum = 0;
    sort(edges.begin(),edges.end());
    //reverse(edges.begin(), edges().end());  // Uncomment for Max. spanning tree
    for(auto &e : edges)
    {
        int u = e.second.first; int v = e.second.second;
		// u <-- source		|	v <-- dest
        if(FindSet(u) == FindSet(v))
            continue;
        Union(u,v);
        sum+=e.f;
    }
    return sum;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
class edge {
public:
	int u, v, index;
	int w;
	bool deleted;
	edge(int from, int to, int wieght, int idx) {
		u = from, v = to, w = wieght, index = idx, deleted = 0;
	}
	bool operator < (const edge& x)const {
		return w > x.w;
	}
	bool operator == (const edge& x)const {
		return (w == x.w && u == x.u && v == x.v);
	}
};
vector <edge> edges;
pair<int, vector<edge>> getMST() {
	pair<int, vector<edge>> ans;
	DisjointSet dis(n);
	priority_queue<edge> pq;
	for (auto& e : edges) {
		if (!e.deleted) {
			pq.push(e);
		}
	}
	while (!pq.empty()) {
		edge curr = pq.top();
		pq.pop();
		if (dis.Union(curr.u, curr.v)) {
			ans.first += curr.w;
			ans.second.push_back(curr);
		}
	}
	if (sz(ans.second) != n - 1)
		return { infl,vector<edge>() };
	return ans;
}
// to get more than one MST
void getmanyMSTs() {
	pair<int, vector<edge>> res = getMST();
	int secondMST = infl;

	lop(i, 0, res.second.size()) {
		edges[res.second[i].index].deleted = 1;

		pair<int, vector<edge>> res2 = getMST();
		secondMST = min(secondMST, res2.first);

		edges[res.second[i].index].deleted = 0;
	}
	cout << res.first << ' ' << secondMST << endl;
}