#include <bits/stdc++.h>
using namespace std;

//<-----------------------Edit below this line------------------------------------------->

class Solution{
  public:
    vector<int> solution(vector<int>& A){
      radixSort(A);
      return A;
    }
    void radixSort(vector<int>& A){
      for(int i{0}; i < 10; i++){
        countSort(A, i);
      }
    }
    //A is out parameter
    //digit: Digit at which to apply count sort, Unit's place -> 0 and so on
    void countSort(vector<int>& A, int digit){
      vector<vector<int>> countArr(10);
      vector<int> store{A};

      for(int i{0}; i < A.size(); i++){
        int idx{A[i]};
        int exponent{0};
        while(exponent < digit){
          idx = idx / 10;
          exponent++;
        }
        idx = idx % 10;
        countArr[idx].push_back(i);
      }

      int counter{0};
      for(int i{0}; i < countArr.size(); i++){
        vector<int>& C{countArr[i]}; 
        for(int j{0}; j < C.size(); j++){
          A[counter] = store[C[j]];
          counter++;
        }
      }
    }
};


//<-----------------------Edit above this line------------------------------------------->



























