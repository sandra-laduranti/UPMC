#ifndef __TPFORK_H__
#define __TPFORK_H__

 void	*xmalloc(unsigned int size);
int	xwrite(int fd, char *buffer, int size);
int	xread(int fd, char *buffer, int size);
int	xclose(const int fd);
void	exo0();
int	*tri(int* tab, int deb, int fin);
int	exo1();

#endif
