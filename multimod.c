#include <stdint.h>
uint64_t Multiply(uint64_t a, uint64_t b) 
{
	uint64_t a1 = a > 0 ? a :~a + 1;
	uint64_t b1 = b > 0 ? b :~b + 1;
	uint64_t sum = 0;
	while (b1) 
		{
		if (b1 & 0x1) {
			sum += a1;
		}
		a1 = a1 << 1;
		b1 = b1 >> 1;
	}
	if ((a ^ b) < 0)
		return ~sum + 1;
	else return sum;
}

uint64_t mod(uint64_t a, uint64_t b)
{
	a -= b;
	while (a >= b)
	{
		a -= b;
	}
	return a;
}

uint64_t multimod(uint64_t a, uint64_t b, uint64_t m)
{
		if (a > m && b > m)
		{
			uint64_t d = Multiply(mod(a, m), mod(b, m));
			while (d >= m)
			{
				d = mod(d, m);
			}
			return d;
		}
		else if (a > m && b <= m)
		{
			uint64_t d = Multiply((a-m), (m - b));
			d = m - mod(d, m);
			return d;
		}
		else if (a <= m && b > m)
		{
			uint64_t d = Multiply((m-a), (m-b));
			d = m - mod(d, m);
			return d;
		}
		else if (a <= m && b <= m)
		{
			uint64_t d = Multiply((m-a),(m-b));
			while (d >= m)
			{
				d = mod(d, m);
			}
			return d;
		}
}