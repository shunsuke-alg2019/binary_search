#include <stdio.h>

int n;
int k;
int A[100000];

// p returns whether x is sufficient
int p(int x) {
  int k1 = 1, // necessary number of workers
    t = 0; // someone's work time

  for (int i = 0; i < n; i++) {
    if (A[i] > x) {
      return 0;
    } else if (t + A[i] > x) {
      k1++;
      t = A[i];
    } else {
      t += A[i];
    }
  }

  return k1 <= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = 0;
  ub = (int)1E9;

  while (ub - lb > 1) {
    int m = (lb + ub) / 2;
    if (p(m)) ub = m;
    else lb = m;
  }

  printf("%d\n", ub);

  return 0;
}
