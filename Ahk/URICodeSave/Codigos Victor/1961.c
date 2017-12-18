#include <stdio.h>
#include <math.h>

int main()
{
	int jump, cases, ii, pipe[2], fail = 1;
	scanf("%d %d", &jump, &cases);
	scanf("%d", &pipe[0]);
	for ( ii = 0; ii < cases; ++ii)
	{
		scanf("%d", &pipe[1]);
		if(fabs(pipe[0]-pipe[1]) > jump) fail = 0;
		pipe[0] = pipe[1];
	}
	fail ? printf("YOU WIN\n") : printf("GAME OVER\n");
}