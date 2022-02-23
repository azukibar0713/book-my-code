#include <pthread.h>
#include <unistd.h> // sleep
#include <stdlib.h> // NULL
#include <stdio.h>

int g_varA;
static int s_varC;

void *threadFunc(void *arg) {
  int n = (int)arg;
  int varB;

  varB = 4 * n;
  printf("threadFunc-%d-1: g_varA:%d, VarB=%d, s_varC\n", g_varA, varB, s_varC);
  g_varA = 5 * n;
  printf("threadFunc-%d-2: g_varA:%d, VarB=%d, s_varC\n", g_varA, varB, s_varC);
  sleep(2);
  printf("threadFunc-%d-3: g_varA:%d, VarB=%d, s_varC\n", g_varA, varB, s_varC);
  varB = 6 * n;
  printf("threadFunc-%d-4: g_varA:%d, VarB=%d, s_varC\n", g_varA, varB, s_varC);

  return NULL;
}

int main(void) {
  pthread_t thread1, thread2;
  int varB;

  g_varA = 1;
  varB = 2;

  if (pthread_create(&thread, NULL, threadFunc, (void *)n) != 0) {
    printf("Error: Failed to create new thread\n");
    exit(1);
  }

  for (i = 0; i < 5; i++) {
    printf("I'm main: %d\n", i);
    sleep(1);
  }

  if(pthread_join(thread, NULL) !=0){
    printf("Error : Failed to wait for the thread termination\n");
    exit(1);
  }

  return 0;
}
