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
void segmentTree(int index , int low , int high , int arr1[] , int seg1[]){
    if(low == high){
        seg1[index] = arr1[low];
        return;
    }

    int mid = low + (high - low)/2;

    segmentTree(2*index+1 , low , mid , arr1 , seg1);
    segmentTree(2*index+2 , mid+1 , high , arr1 , seg1);

    seg1[index] = min(seg1[2*index+1] , seg1[2*index+2]);
}
// void template2(int index , int low , int high , int arr2[] , int seg2[]){
//     if(low == high){
//         seg2[index] = arr2[low];
//         return;
//     }

//     int mid = low + (high - low)/2;

//     template1(2*index+1 , low , mid , arr2, seg2);
//     template1(2*index+2 , mid+1 , high , arr2 , seg2);

//     seg2[index] = min(seg2[2*index+1] , seg2[2*index+2]);
// }
int query(int index , int low , int high , int l , int r , int arr1[] , int seg1[]){
     // three condition in the query range 
    //  1) range is out of the bound it means (l<low  && high<r)

    if(r<low || high<l){
        return INT_MAX;
    }
    else if(low>=l && high<=r){
          return seg1[index];
    }
    else{
          int mid = low + (high-low)/2;
          int left = query(2*index+1 , low , mid , l , r , arr1 , seg1);
          int right = query(2*index+2 , mid+1 , high , l , r , arr1 , seg1);

          return min(left , right);
    } 
}
void update(int index , int low , int high , int pos , int val , int seg1[]){
      
       // basse case 
       if(low == high){
         seg1[index] = val;
         return;
       }

       int mid = low + (high-low)/2;

       if(pos<=mid){
        update(2*index+1 , low , mid , pos , val , seg1);
       }
        else{
            update(2*index+2 , mid+1 , high , pos , val , seg1);
        }

        seg1[index] = min(seg1[2*index+1] , seg1[2*index+2]);
}
int32_t main()
{
 ios_base:: sync_with_stdio();
 cin.tie(0);
 cout.tie(0);
      
         int n ;
         cin >> n ;

         int arr1[n];
        //  int arr2[m];

         for(int i=0 ; i<n ; i++){
            cin >> arr1[i];
         }
         int seg1[4*n];
         segmentTree(0 ,0 , n-1 , arr1 , seg1);
         int q;
         cin >> q;
         while(q--){
            int type;
            cin >> type;
            if(type == 1){
                int l , r;
                cin >> l >> r;
                cout << query(0 , 0 , n-1 , l , r , arr1 , seg1) << endl;
            }
            else{
                int pos , val;
                cin >> pos  >> val;
                update(0 , 0 , n-1 , pos , val , seg1);
                arr1[pos] = val;
            }
         }
        //  for(int j=0 ; j<m ; j++){
        //     cin >> arr2[j];
        //  }
        //  int seg2[4*m];

        //    template2(0 , low2 , high2 , arr2 , seg2);
           
    return 0;
}