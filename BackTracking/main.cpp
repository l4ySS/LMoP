#include <iostream>

#include <vector>
using namespace std;

vector < vector <bool> > used(101, std::vector<bool>(101, 0));
int number;

void backtracking(int first, int second, int third, int mark[], int M, int j, int i) {
    if (used[first][second]){
      
        return;
    }
    else {
            used[first][second] = true;
            std::cout << "\n------\n" << number << "\t" << first << "\t" << second << "\t" << third << "\t";
            number++;
            if ((first == 1) || (second == 1) || (third == 1)) cout << " <--";
    }

  

    for (int k = 0; k < M; k++) {
        
        if ((j < M)) {
            int _j = j;
            if (third + first - mark[_j] >= 0)backtracking(mark[_j], second, third + first - mark[_j], mark, M, ++j, i);
        }
        

        if ((i < M)) {
            int _i = i;
             if  (third + second - mark[_i] >= 0 )backtracking(first, mark[_i], third + second - mark[_i], mark, M, j, ++i);
        }


        if (second > 0)   backtracking(first + second, 0, third, mark, M, j, 0);

        if (third > 0) {
            backtracking(first + third, second, 0, mark, M, j, i);
            backtracking(first, second + third, 0, mark, M, j, i);
        }

        if (first > 0) backtracking(0, second + first, third, mark, M, 0, i);
    } 
    
       
   }
 




void main() {
    vector < vector <bool> > used(100, std::vector<bool>(100, 0));
    const int N = 3;


    const int M = 4;
    int mark[M];
    mark[0] = 4;
    mark[1] = 44;
    mark[2] = 55;
    mark[3] = 95;
   /* const int M = 2;
 int mark[M];
 mark[0] = 1;
 mark[1] = 50;*/



    int first = 0;
    int second = 0;
    int third = 100;
    
    backtracking(first, second, third, mark, 4, 0, 0);
    std::cout << "End" << '\n';
    
}