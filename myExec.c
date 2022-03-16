#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#define SIZE 512

int printList(char **someList) {
  int index = 0;
  while (someList[index] != NULL) {
    printf("%s\n", someList[index]);
    index++;
  }
  return index;
}

void partA() { printf("My PID is %d and my PPID is %d", getpid(), getppid()); }

void partB(char *argv[]) {
  int fd;
  char buff[SIZE];

  int temp =
      sprintf(buff, "THe PID is %d and the PPID is %d", getpid(), getppid());
  int at = atoi(argv[1]);
  write(at, buff, temp);
}

void partC(char **envp, char **argv) {
  printf("\n\n");
  printList(envp);
}

int main(int argc, char *argv[], char **envp) {
  partA();
  // partB(argv);
  // partC(envp, argv);
  return 0;
}
