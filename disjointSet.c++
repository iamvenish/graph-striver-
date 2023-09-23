#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vii vector<vector<int>>
#define mii map<int,int>
#define int long long
#define pi  3.14159265358979323846264338327950288419
#define pii pair<int,int> 
#define f first
#define s second
#define vpii vector<pair<int , int>>
#define pb push_back
class DisjointSet{
   vector<int>rank , parent , size;
public:
    DisjointSet(int n){
        rank.resize(n+1 , 0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0 ; i<=n ; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUltimateParent(int node){
        if(node == parent[node]){
            return node;
        }

        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionByRank(int u , int v){
        int ult_u= findUltimateParent(u);
        int ult_v = findUltimateParent(v);

        if(ult_u == ult_v)return;

        if(rank[ult_u] < rank[ult_v]){
            parent[ult_u] = ult_v;
        }
        else if(rank[ult_v] < rank[ult_u]){
            parent[ult_v] = ult_u;
        }
        else {
            parent[ult_u] = ult_v;
            rank[ult_u]++;
        }
    }

    void unionBySize(int u , int v){
        int ult_u= findUltimateParent(u);
        int ult_v = findUltimateParent(v);

        if(ult_u == ult_v)return;

        if(size[ult_u] < size[ult_v]){
            parent[ult_u] = ult_v;
        }
        else if(size[ult_v] < size[ult_u]){
            parent[ult_v] = ult_u;
        }
        else{
            parent[ult_u] = ult_v;
            size[ult_u]+=size[ult_v];
        }
    }
};
int32_t main()
{
 ios_base:: sync_with_stdio();
 cin.tie(0);
 cout.tie(0);
      DisjointSet ds(7);
      ds.unionBySize(1,2);
      ds.unionBySize(2,3);
      ds.unionBySize(4,5);
      ds.unionBySize(6,7);
      ds.unionBySize(5,6);
    //   if 3 and 7 are in same component or not 
      if(ds.findUltimateParent(3) == ds.findUltimateParent(7)){
        cout << "the same parent " << endl;
      }
      else{
        cout <<"NO way" << endl;
      }

      ds.unionBySize(3,7);

            if(ds.findUltimateParent(3) == ds.findUltimateParent(7)){
        cout << "the same parent " << endl;
      }
      else{
        cout <<"NO way" << endl;
      }
      


    return 0;
}