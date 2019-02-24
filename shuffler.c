#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define  THESIZE 500

int		main()
{
int size = THESIZE;
int	i;
int *elements = malloc(sizeof(int)*size);

// inizialize
for (int i = 0; i < size; ++i)
  elements[i] = i + 1;

for (int i = size - 1; i > 0; --i) {
  // generate random index
  srand(time(NULL));
  int w = rand() % i;
  // swap items
  int t = elements[i];
  elements[i] = elements[w];
  elements[w] = t;
}
i = 0;
while (i < size)
	printf("%d ", elements[i++]);

return (0);
}
