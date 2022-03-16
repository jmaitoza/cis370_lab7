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

void partA(char *argv[]) {
  printf("[p] My PID is %d and my PPID is %d\n", getpid(), getppid());
  execlp("/Users/joshuamaitoza/repos/CIS370/cis370_lab7/myExec", argv[0],
         (char *)NULL);
}

void partB(char *argv[]) {
  int fd;
  char buff[SIZE];
  char buff2[SIZE];
  fd = open("pcb_file", O_RDWR | O_CREAT, 0644);
  int temp =
      sprintf(buff, "[p]THe PID is %d and the PPID is %d", getpid(), getppid());
  write(fd, buff, temp);
  sprintf(buff2, "%d", fd);
  execlp("/Users/joshuamaitoza/repos/CIS370/cis370_lab7/myExec", argv[0], buff2,
         (char *)NULL);
  close(fd);
}

void partC(char **envp, char **argv) {
  envp[1] = "Joshua Maitoza";
  printList(envp);
  execle("/Users/joshuamaitoza/repos/CIS370/cis370_lab7/myExec", argv[0],
         (char *)NULL, envp);
}

int main(int argc, char *argv[], char **envp) {
  int temp;
  partA(argv);
  // partB(argv);
  // partC(envp, argv);
  return 0;
}
