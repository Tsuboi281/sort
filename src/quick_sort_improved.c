#include <stdio.h>

// 素数
#define N 2999

int A[N];

// *p と *q の値を入れ替える関数
void swap(int *p, int *q){
  int tmp;
  tmp = *p;
  *p = *q;
  *q = tmp;
}


/*
A[0], A[1], ..., A[n-1] をソートして昇順に書き換える関数
*/
void quick_sort(int A[], int n){
    if (n <= 0) {}
    else{
        int i,j,l,pivot;
        
 /*    
        pivot = A[0];
        for(i = j =1; i < n ; i++){
            if(A[i] <= pivot){
                swap(A+i,A+j);
                j++;
                }
            }
            swap(A , A+j-1);
            quick_sort(A  ,j - 1);
            quick_sort(A+j , n - j);




*/
        pivot = A[0];
        for(j = 0, i = l = 1; i < n ; i++){
            if(A[i] < pivot){
                swap(A+i,A+l);
                swap(A+l,A+j);
                j++;
                l++;
            }
            else if (A[i] == pivot){
                swap(A+l,A+i);
                l++;
            }
        }
        

        quick_sort(A  ,j );
        quick_sort(A+l , n - l);

    }
}

int main(){
  int i;
  A[0] = 0;
  A[1] = 17; //原始元
  for(i=2;i<N;i++){
    A[i] = (long long int) A[i-1] * A[1] % N;
    //printf("%d\n",A[i]);
  }
  quick_sort(A, N);
  //printf("\n");

// すべての要素が同じ場合でも計算が早く終わるか確認する

  for(i=0;i<N;i++){
    //printf("%d\n",A[i]);
    if(A[i] != i) printf("ERROR %dth element is %d\n", i, A[i]);
  }
}
