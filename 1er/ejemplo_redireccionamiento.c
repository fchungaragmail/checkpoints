#include <unistd.h>
#include <fcntl.h>

int main(void)
{
	int p[2];

	pipe(p);

	if(fork()==0)
	{
		close(0);
		dup(p[0]);
		close(1);
		open("fichero",O_CREAT|O_WRONLY|O_TRUNC);
		close(p[0]); close(p[1]);
		execlp("sort","sort",NULL);
	}
	
	if(fork()==0)
	{
		close(1);
		dup(p[1]);
		close(0);
		close(p[0]); close(p[1]);
		execlp("ls","ls",NULL);
	}
	
	return 0;
}