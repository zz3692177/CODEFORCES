#include <stdio.h>

void d_to_a(int digit)
{
	if(digit)
	{
		d_to_a((digit-1)/26);
		putchar(65 + (digit-1)%26);
	}
}


int main()
{
	int n, x, y;
	char s[20] , *p;
	for(scanf("%d ", &n); n--;)
	{
		gets(s);
		if(sscanf(s, "%*c%d%*c%d", &x, &y) == 2)  //R23C55
		{
			d_to_a(y);
			printf("%d\n", x);
		}
		else
		{
			for(x = 0, p = s; *p > 64; ++p)
				x = x*26 + *p - 64;
			printf("R%sC%d\n", p, x);
		}
	}
}
