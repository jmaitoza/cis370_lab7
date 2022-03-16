#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int printList(char **someList) {
  int index = 0;
  while (someList[index] != NULL) {
    printf("%s\n", someList[index]);
    index++;
  }
  return index;
}

void argvMain(char **argv) {
  pid_t child;
  int waitRV, childstatus;

  if (fork() == 0) {
    printf("Child argv\n\n");
    printList(argv);
  } else {
    waitRV = wait(&childstatus);
    printf("Parent argv\n\n");
    printList(argv);
  }
}

void envpMain(char **envp) {
  int waitRV, childstatus;
  if (fork() == 0) {
    printf("Child envp\n\n");
    printList(envp);
  } else {
    waitRV = wait(&childstatus);
    printf("-----------------------------------------------------\n");
    printf("Parent envp\n\n");
    printList(envp);
  }
}

int main(int argc, char **argv, char **envp) {
  pid_t child;
  int waitRV, childstatus;
  // argvMain(argv);
  envpMain(envp);
  return 0;
}
