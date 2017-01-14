#include <bits/stdc++.h>
#define di pair<double,int>
using namespace std;
struct Point{
    double x,y;
	Point(double u ,double v){
		x=u;y=v;
	}
	bool operator<(Point p){
		return x<p.x || (x==p.x && y<p.y);
	}
};
int n,t;
double dist(Point A,Point B){
	return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}
double ClosestPair(vector<Point> P){
	double ans=DBL_MAX;
	sort(P.begin(),P.end());
	int j=0;
	set<di> S;
	for(int i=0;i<P.size();i++){
		while(P[i].x-P[j].x>ans){
			S.erase(di(P[j].y,j));
			j++;
		}
		set<di>::iterator it,low,up;
		low=S.lower_bound(di(P[i].y-ans,0));
		up=S.upper_bound(di(P[i].y+ans,0));
		for(it=low;it!=up;it++)
			ans=min(ans,dist(P[i],P[(*it).second]));
		S.insert(di(P[i].y,i));
	}
	return ans;
}
int main(){
	scanf("%d",&t);
	while(t--){
	    scanf("%d",&n);
		vector<Point> P;
		for(int i=0;i<n;i++){
			double u,v;
			scanf("%lf%lf",&u,&v);
			P.push_back(Point(u,v));
		}
		printf("%.6lf\n",ClosestPair(P));
	}
	return 0;
}
