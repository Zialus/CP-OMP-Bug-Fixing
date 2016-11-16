#include <omp.h>
#include <stdio.h>

#define NTHREADS 4
#define N 40

int main (int argc, char *argv[]) {
  int i, tid;
  long a[N], b[N], c[N];

  #pragma omp parallel num_threads(NTHREADS)
  {
    tid = omp_get_thread_num();
    #pragma omp for
    for (i = 0; i < N; i++)
      a[i] = b[i] = i;
    #pragma omp for
    for (i = 0; i < N; i++) {
      c[i] = a[i] + b[i];
      printf("Thread %d: c[%d] = %ld\n", tid, i, c[i]);
    }
  }
  return 0;
}
