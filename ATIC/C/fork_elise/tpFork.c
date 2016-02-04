#include <stdlib.h>
#include <stdio.h>
#include <unistd.h> 
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <time.h>

void	exo0()
{
    int fd[2];
    pid_t pid;
    char tab[10];
    int i=0;

    pipe(fd); 
    pid = fork();
    if (pid == 0){
	printf("je suis dans le fils\n");
	read(fd[0],tab, 10);
	while(tab[i] != '\0'){
	    if ((tab[i]>'a')&&(tab[i]<'z')){
		printf("%c", tab[i]-32);
	    }
	    else{
		printf("%c", tab[i]);
	    }
	    i++;
	}
	printf("\n");
    }
    else {
	printf("je suis dans le pere\n");
	printf("Entrer une chaine de caracteres\n");
	scanf("%s",tab);
	write(fd[1],tab, 10);
	wait(0);
    }
}

/* tri à bulle */
int	*tri(int* tab, int deb, int fin)
{
    int i;
    int swap=1;
    int tmp;
    
    while(swap==1){
	swap=0;
	for(i=deb; i<fin-1; i++){
	    if(tab[i+1]<tab[i]){
		tmp=tab[i];
		tab[i]=tab[i+1];
		tab[i+1]=tmp;
		swap =1;
	    }
	}
    }
    return tab;
}

int	exo1()
{
    int fd[2];
    int fd2[2];
    pid_t pid;
    int *tab;
    int i;
    int n;

    i = 0;
    n = 0;
    if (pipe(fd) == -1)
      {
	fprintf(stderr,"ERROR pipe fail\n");
	exit(EXIT_FAILURE);
      }
    if (pipe(fd2) == -1)
      {
	fprintf(stderr,"ERROR pipe fail\n");
	exit(EXIT_FAILURE);
      }
    pid = fork();
    if (pid == 0){
	close(fd[1]); /* on ferme la partie écriture qui ne sert à rien au fils*/
	while(n == 0)
	  read(fd[0],&n, 1);
	printf("n dans fils = %d\n", n);
	tab = malloc(sizeof(int)*n/2);
	for(i=0; i != n/2; i++)
	  read(fd[0],&tab[i],n/2);
	tab = tri(tab,0,n/2);
	close(fd2[0]);
	for(i=0; i != n/2; i++)
	  write(fd2[1], &tab[i], sizeof(int));
	close(fd2[1]);
	return (EXIT_SUCCESS);
    }
    else {
      printf("Entrer un entier \n");
      scanf("%d",&n);
      close(fd[0]);
      write(fd[1],&n, 1);
      tab = malloc(sizeof(int)*n);
      for(i=0; i<n; i++){
	tab[i]=(int)(rand()%100);
	printf("%d ",tab[i]);
      }
      printf("\n");
      for(i=0; i != n/2; i++)
	write(fd[1],&tab[i], sizeof(int));
      close(fd[1]);
      close(fd2[1]);
      tab = tri(tab,n/2,n);
      for(i=0; i != n/2; i++)
	read(fd2[0], &tab[i], sizeof(int));
      close(fd2[1]);
      /*en vrai il faudrait profiter du read pour faire un
       * tri par fusion mais on a pas eu le temps de le faire 
       * donc du coup le tab final n'est trié qu'à moitié*/
      for(i=0; i != n; i++)
	printf("%d ",tab[i]);
      printf("\n");
    }    
    return EXIT_SUCCESS;
}

/* fd[0] => read, fd[1] => write
0 => stdin 1=>stdout  */
void	exo2()
{
   int fd[2];
    int fd2[2];
    pid_t pid;
    int *tab;
    int i;
    int n;

    i = 0;
    n = 0;
    if (pipe(fd) == -1)
      {
	fprintf(stderr,"ERROR pipe fail\n");
	exit(EXIT_FAILURE);
      }
    if (pipe(fd2) == -1)
      {
	fprintf(stderr,"ERROR pipe fail\n");
	exit(EXIT_FAILURE);
      }
    pid = fork();
    dup2(STDIN_FILENO, fd[1]);
    dup2(STDOUT_FILENO,fd2[0]);
    if (pid == 0){
      execl("/home/patate/Desktop/tp/fork_elise/tri", "/home/patate/Desktop/tp/fork_elise/tri", NULL);
    }
    else{
      scanf("%d",&n);
      close(fd[0]);
      write(fd[1],&n, sizeof(int));
      tab = malloc(sizeof(int)*n);
      for(i=0; i<n; i++){
	tab[i]=(int)(rand()%100);
	fprintf(stderr,"%d ",tab[i]);
      }
      fprintf(stderr,"\n");
      for(i=0; i != n; i++)
	write(fd[1],&tab[i], sizeof(int)*n);
      close(fd[1]);
      close(fd2[1]);
      for(i=0; i != n; i++){
	read(fd2[0], &tab[i], sizeof(int)*n);
	fprintf(stderr,"%d",tab[i]);
      }
      close(fd2[1]);
    }
}


int main()
{
srand(time(NULL));
//exo0();
//exo1();
 exo2();
   return EXIT_SUCCESS;
}
