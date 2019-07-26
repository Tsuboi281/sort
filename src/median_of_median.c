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

int quick_select(int A[], int n, int k){
  int i, j,l, pivot;

// 真ん中の要素をピボットとする
  pivot = A[n/2];
  A[n/2] = A[0];
  A[0] = pivot;
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

if(j <= k && k <= l-1) return pivot;
else if(l <= k) return quick_select(A+l, n-l, k-l);
else return quick_select(A, j, k);
}



int m(int A[],int n){//median_of_medianのpivotを求める補助関数
    int X[N];
    if (n > 5) {
        int i;
        for(i = 0;i < (n/5);i++){
            X[i] = quick_select(A+5*i,5,2);//中央値をquick_selectを用いて求める
        }
        if (n%5 == 0){
            return m(X,n/5);
        }
        else{
            X[n/5] = m(A+(n - (n%5)),n%5);
            return m(X,n/5+1);
        }
    }
    else {
        return quick_select(A,n,n/2);
    }
}



int median_of_median(int A[],int n,int k){
    int i,j,l,pivot;
    pivot = m(A,n);
    for(i = j = l = 0;i < n;i++){
        if (A[i] < pivot){
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
    if(j <= k && k <= l-1) return pivot;
    else if(l <= k) return median_of_median(A+l, n-l, k-l);
    else return median_of_median(A, j, k);
}




int main(){
  int i;
  A[0] = 0;
  A[1] = 17; //原始元
  for(i=2;i<N;i++){
    A[i] = (long long int) A[i-1] * A[1] % N;
  }
  
  
  
  for(i=0;i<N;i++){
    if(median_of_median(A, N, i) != i) printf("ERROR %d %d\n", i, median_of_median(A, N, i));
//    printf("%d th element is %d\n", i, quick_select(A, N, i));
  }
  
  

  
  
}
