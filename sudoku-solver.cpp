#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MOD 1000000007
#define lld long long int

bool CanPlace(int mat[][9], int i, int j, int k){

	for(int z=0; z<9; z++){
		if(mat[z][j] == k || mat[i][z] == k){
			return false;
		}
	}

	int sx = (i/3)*3;
	int sy = (j/3)*3;

	for(int x=sx; x<sx+3; x++){
		for(int y=sy; y<sy+3; y++){
			if(mat[x][y] == k){
				return false;
			}
		}
	}

	return true;
}

bool solveSudoku(int mat[][9], int i, int j, int n){
	//base case
	if(i==n){
		for(int a=0; a<n; a++){
			for(int b=0; b<n; b++){
				cout << mat[a][b] << " ";
			}
			cout << endl;
		}
		return true;
	}

	//recursive case
	if(j==n){
		return solveSudoku(mat,i+1,0,n);
	}

	if(mat[i][j]!=0){
		return solveSudoku(mat,i,j+1,n);
	}

	for(int k=0; k<=n; k++){
		if(CanPlace(mat,i,j,k)){
			mat[i][j] = k;
			bool success = solveSudoku(mat,i,j+1,n);
			if(success){
				return true;
			}
		}
	}

	mat[i][j] = 0;
	return false;
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
 
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n=9;
    int mat[9][9] = 
       {{5,3,0,0,7,0,0,0,0},
    	{6,0,0,1,9,5,0,0,0},
    	{0,9,8,0,0,0,0,6,0},
    	{8,0,0,0,6,0,0,0,3},
    	{4,0,0,8,0,3,0,0,1},
    	{7,0,0,0,2,0,0,0,6},
    	{0,6,0,0,0,0,2,8,0},
    	{0,0,0,4,1,9,0,0,5},
    	{0,0,0,0,8,0,0,7,9}};

    solveSudoku(mat,0,0,n);

    return 0;
}
