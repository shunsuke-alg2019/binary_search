#include <stdio.h>

int n;
int k;
int A[100000];

// p returns whether x is too big
int p(int x) {
  int k1 = 0; // number of actual spears

  for (int i = 0; i < n; i++) k1 += A[i] / x;

  return k1 < k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = 0;
  ub = (int)1E9 + 1;

  while (ub - lb > 1) {
    int m = (lb + ub) / 2;
    if (p(m)) ub = m;
    else lb = m;
  }

  printf("%d\n", ub - 1);

  return 0;
}
