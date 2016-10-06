#include <stdio.h>
#include <math.h>
#define feq(a, b) (fabs(a - b) < 1e-6)
void sort(double angle[])
{
	for(int i = 2; i >= 0; i--)
	{
		double tmp = 0.0;
		for(int j = 1 ; j <= i ; j++)
		{
			if(angle[i-1] > angle[i])
			{
				tmp = angle[i - 1];
				angle[i-1] = angle[i];
				angle[i] = tmp;
			}
		}
	}
}

double GetR(double d[])
{
	double q = (d[0] + d[1] + d[2]) / 2;
	double S = sqrt (q * (q - d[0]) * (q - d[1]) * (q - d[2]));
	return d[0] * d[1] * d[2] / (4 * S);
}

double fgcd(double a, double b)
{
	if(feq(a, 0)) return b;
	if(feq(b, 0)) return a;
	return fgcd(b, fmod(a, b));
}
int main()
{
	double x[3], y[3], d[3];
	for(int i = 0; i < 3; i++)
		scanf("%lf%lf", &x[i], &y[i]);
	for(int i = 0; i < 3; i++)
		d[i] = sqrt(pow((x[i] - x[(i+1) % 3]), 2) + pow((y[i] - y[(i+1) %3]), 2));
	double R = GetR(d);
	double angle[4];
	for( int i = 0; i < 3; i++)
		angle[i] = acos((R*R + R*R - d[i]*d[i])/(2*R*R));
	
	sort(angle);
	angle[3] = fgcd(angle[2], fgcd(angle[1], angle[0]));
	
	printf("%.8lf\n",   R * R * sin(angle[3]) / 2.0 * (2.0 * M_PI / angle[3]));
}
