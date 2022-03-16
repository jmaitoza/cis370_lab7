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

void fdMain() {
  int fd, waitRV, childstatus;
  char buff[SIZE];
  char buff2[SIZE];
  fd = open("pFile", O_RDWR | O_CREAT, 0644);
  if (fork() == 0) {
    int temp = sprintf(buff, "[c] this is process %d and my parent is %d",
                       getpid(), getppid());
    write(fd, buff, temp);
  } else {
    waitRV = wait(&childstatus);
    int temp2 = sprintf(buff2, "\n[p] this is process %d and my parent is %d",
                        getpid(), getppid());
    write(fd, buff2, temp2);
    close(fd);
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
  argvMain(argv);
  // envpMain(envp);
  // fdMain();
  return 0;
}
