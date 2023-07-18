#include <bits/stdc++.h>
using namespace std;

int main(){
    char grid[100][100];

    int size;
    cout<<"Enter Playground size: ";
    cin>>size;

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            grid[i][j]='*';
        }
    }

    int rowStart[100],colStart[100],direcRow[100],direcCol[100];
    int verify =0;

    for (int i = 0; i < size; ++i)
        rowStart[verify] = i, colStart[verify] = 0, direcRow[verify]= 0,direcCol[verify++] = 1;
    for (int i = 0; i < size; ++i)
        rowStart[verify]=0 , colStart[verify] = i, direcRow[verify]= 1,direcCol[verify++] = 0;

    rowStart[verify] = 0 , colStart[verify]= 0 ,direcRow[verify] = 1,direcCol[verify++]=1;
    rowStart[verify] = 0 , colStart[verify]= size-1 ,direcRow[verify] = 1,direcCol[verify++]=-1;

    int steps =0;
    for (int z = 1; z <= size*size; ++z) {
        if(steps == size*size){
            cout<<"Tie\n";
            break;
        }
        char symbol;
        if(z % 2 != 0)
            symbol = 'X';
        else
            symbol = 'O';
        cout<<"Player "<<symbol<<" turn. Enter empty location (r,c): ";
        int r,c;
        cin>>r>>c;
        r--,c--;
        if(r<0 || r>= size || c<0 || c>=size || grid[r][c] != '*'){
            cout<<"Invalid input. Try again\n";
            z--;
            continue;
        }
        grid[r][c] = symbol;

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                cout<<grid[i][j]<<' ';
            }
            cout<<'\n';
        }
        for (int i = 0; i < verify; ++i) {
            r = rowStart[i],c = colStart[i];
            int rd = direcRow[i], cd = direcCol[i];
            int cnt = 0;
            char first = grid[r][c];
            if(first == '*')
                continue;
            for (int j = 0; j < size; ++j,r+=rd,c+= cd) {
                cnt += grid[r][c] == first;
            }
            if(cnt == size){
                cout<<"Player "<<symbol <<" won\n";
                return 0;
            }
            steps++;
        }
    }
}