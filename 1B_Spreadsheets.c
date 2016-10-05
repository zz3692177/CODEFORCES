#include <stdio.h>
#include <string.h>
#define STR_MAX 500
int main()
{
	int n;
	char a[STR_MAX];
	scanf("%d", &n);
	while(n--)
	{
		scanf("%s", a);
		int len = strlen(a);
		int cnt = 0;
		for(int i = 1; i < len; i++)
		{
			if((a[i-1] >= 'A' && a[i-1] <= 'Z')&&(a[i] >= '0' && a[i] <= '9'))
				cnt++;
		}
		if(cnt == 1)  //BC23
		{
			int r_val = 0,c_val = 0;
			for(int i = 0; i < len; i++)
			{
				if(a[i] >= 'A' && a[i] <= 'Z')
					c_val = c_val * 26 + (a[i] - 'A' + 1);
				else
					r_val = r_val * 10 + (a[i] - '0');
			}
			printf("R%dC%d\n", r_val, c_val);
		}
		else		//R23C55
		{
			int r_val = 0,c_val = 0;
			int record = 0;
			for(int i = 1; i < len; i++)
			{
				if(a[i] >= '0' && a[i] <= '9')
					r_val = r_val * 10 + (a[i] - '0');
				else
				{
					record = i++;
					break;
				}
			}
			for(int j = record; j < len; j++)
			{
				if(a[j] >= '0' && a[j] <= '9')
					c_val = c_val * 10 + (a[j] - '0');
			}
			char r_str[6], str[6]; // 用來記錄column字母
			int str_cnt = -1;
			int flag = 0;
			while(c_val)
			{
				flag = c_val%26;
				if(!flag)
				{
					r_str[++str_cnt] = 'Z';
					c_val--;
				}
				else
					r_str[++str_cnt] = flag - 1 + 'A';
				
				c_val /= 26;
			}

			for(int i = 0; i <= str_cnt; i++)
				str[i] = r_str[str_cnt - i];
			str[++str_cnt] = '\0';

			printf("%s%d\n", str, r_val);

		}
	}

	return 0;
}
