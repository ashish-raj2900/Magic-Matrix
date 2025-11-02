//magic matrix(not for singly even order) 
#include <iostream>
#include <cmath>

using namespace std;

vector<vector<int>> make_mat(int n){
    if(n == 1) return {{1}};
    if(n == 2) return {{-1}};
    int elm = 1;
    vector<vector<int>> mat(n,vector<int>(n,0));
    if(n%2 == 1){
        int r = 0;
        int c = n/2;
        mat[r--][c++] = elm++;
        for(int i = 0;i<n*n-1;i++){
            if(c > n-1 && r < 0){
                c = 0;r = n-1;
            }
            else if(c > n-1){
                c = 0;
            }else if(r < 0){
                r = n-1;
            }
            if(mat[r][c] == 0){
                mat[r--][c++] = elm++;
            }
            else {
                r++;c--;r++;
                int temp = r-(n-1);
                if(r > n-1 && c < 0){
                    r = temp-1;c = n-1;
                }
                else if(r > n-1){
                    r = temp-1;
                }
                else if(c < 0){
                    c = n-1;
                }
                mat[r--][c++] = elm++;
            }
        }
    }
    else if(n%4 == 0){
        for(int i = 0;i<n;i++){
            for(int j=0;j<n;j++){
                mat[i][j] = elm++;
            }
        }
        for(int i=0;i<(n/2);i++){
            swap(mat[i][i],mat[n-1-i][n-1-i]);
            swap(mat[i][n-1-i],mat[n-1-i][i]);
        }
    }
    return mat;
}

void print_mat(vector<vector<int>>& mat){
    int n = mat.size();
    int space = log10(n*n);
    for(int i = 0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<(space-log10(mat[i][j]));k++){
                cout << " ";
            }
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int n;
    cout << "N = ";
    cin >> n;
    vector<vector<int>> mat = make_mat(n);
    print_mat(mat);
    return 0;
}