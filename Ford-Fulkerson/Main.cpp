#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int MAXN=1e3+10;
const int INF=INT_MAX;
int n,s,t;
vector<int> Adj[MAXN];
int AdjM[MAXN][MAXN];
bool V[MAXN];
int dfs(int u,int k){
	V[u]=1;
	if (u==t) return k;
	for (int i=0;i<Adj[u].size();i++){
		int v=Adj[u][i],p=AdjM[u][v];
		if (!V[v]&&p>0){
			int flow=dfs(v,min(k,p));
			if (flow>0){
				AdjM[u][v]-=flow;
				AdjM[v][u]+=flow;
				return flow;
			}
		}
	}
	return 0;
}
int MaxFlow(){
	int flow=0;
	while(1){
		memset(V,0,sizeof V);
		int q=dfs(s,INF);
		if (q==0) break;
		flow+=q;
	}
	return flow;
}
int main(){
	int i,j,k=0,u,v,w,c;
	while(scanf("%d",&n)!=EOF){
		if (n==0) break;k++;
		memset(AdjM,0,sizeof AdjM);
		scanf("%d%d%d",&s,&t,&c);s--,t--;
		for (i=0;i<n;i++) Adj[i].clear();
		while(c--){
			scanf("%d%d%d",&u,&v,&w),u--,v--;
			Adj[u].pb(v);Adj[v].pb(u);
			AdjM[u][v]+=w;AdjM[v][u]+=w;
		}
		printf("Max Flow %d : %d\n",k,MaxFlow());
	}
	return 0;
}
