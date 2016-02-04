#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>


int	main()
{
  int	tab[5];
  int	i;
  pid_t pid;
  int	fd[2];

  pid = fork();
  srand(time(NULL));
  while (i < 5){
    tab[i] = (int)(rand()%100);
    i++;
  }
  pipe(fd);
  if (pid == 0){
    printf("je suis dans le fils %d\n",pid);
    close(fd[1]);

    sleep(2);
  }
  else{
    printf("je suis dans le pere %d\n",pid);
    wait (0);
  }
  return (EXIT_SUCCESS);
}
