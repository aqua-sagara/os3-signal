#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


/* #define NDISKS 5 */

int *naA; //棒A
int *naB; //棒B
int *naC; //棒C
int nMoves = 0;  //総移動回数
int nDisks = 0; //円盤数

void Initialize();
void Solve(int*, int*, int*, int);
void Display(int);

int main(int argc, char *argv[], char *envv[]) {
  nDisks=atoi(argv[1]);
  naA=(int*)malloc((int)argv[1]*sizeof(int));
  naB=(int*)malloc((int)argv[1]*sizeof(int));
  naC=(int*)malloc((int)argv[1]*sizeof(int));
  Initialize();

  Display(getpid());

  Solve(naA, naB, naC, nDisks);
  Display(getpid());
  free(naA);
  free(naB);
  free(naC);
}

void Initialize() {
  int i;

  for(i=0; i<nDisks; i++){
    naA[i] = nDisks-i;
    naB[i] = 0;
    naC[i] = 0;
  }

}

void Solve(int *_naA, int *_naB, int *_naC, int n) {

  if (n) {

    Solve(_naA+1, _naC, _naB, n-1);
  
    *_naB = *_naA;
    *_naA = 0;

    ++nMoves;

    Solve(_naC, _naB+1, _naA, n-1);
  }

}

/* show the Tower of Hanoi */
void Display(int pid){
  int i;

  printf("%s","\033[H\033[2J\n\n");
  printf("Move: %d pid:%d\n", nMoves, pid);
  for(i=nDisks-1; i>=0; i--){
    printf("|%2d|   |%2d|   |%2d|\n", naA[i], naB[i], naC[i]);
  }
  printf("----   ----   ----\n");
  printf("  A      B      C\n");
  printf("Number of Moves: %d\n", nMoves);
  printf("Numer of Disks: %d\n", nDisks);
}
