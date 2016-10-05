#include <stdio.h>
#include <stdint.h>

int main()
{
	unsigned long long n, m ,a;
	scanf("%I64d%I64d%I64d", &n, &m, &a);
	unsigned long long w = 0, l = 0;
	if(n%a) w = n/a + 1;
	else w = n/a;
	if(m%a) l = m/a + 1;
	else l = m/a;

	printf("%I64d\n", w*l);
}
