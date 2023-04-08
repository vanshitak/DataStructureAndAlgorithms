#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MOD 1000000007
#define lld long long int



bool solveRat(vector<string> arr, vector<vector<int>> &mat, int i, int j, int n, int m){
    //base case
    if(i==n-1 && j==m-1){
        mat[i][j] = 1;
        return true;
    }
    
    if(i<0 || j<0 || i>n || j>m || mat[i][j] == 1){
        return false;
    }
    
    if(arr[i][j] == 'O'){
        mat[i][j] = 1;
        if(solveRat(arr,mat,i,j+1,n,m)){
            return true;
        }
        if(solveRat(arr,mat,i+1,j,n,m)){
            return true;
        }
        if(solveRat(arr,mat,i,j-1,n,m)){
            return true;
        }
        if(solveRat(arr,mat,i-1,j,n,m)){
            return true;
        }
        mat[i][j] = 0;
    }
    return false;
}

vector<vector<int>> ratAndMice(vector<string> &arr) {
    int n = arr.size();
    int m = arr[0].size();
    vector<vector<int>> mat(n,vector<int>(m,0));
    solveRat(arr,mat,0,0,n,m);
    return mat;
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
 
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif


    vector<string> arr = {"OXOO","OOOX","XOXO","XOOX","XXOO","OXOO"};
    vector<vector<int>> ans;
    ans = ratAndMice(arr);

    for(auto x:ans){
        for(auto y:x){
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}
