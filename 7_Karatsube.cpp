#include <iostream>

using namespace std;

enum{BASE = 10, 
	 MIN_LENGTH_FOR_KARATSUBE = 4,
     A_SIZE = 8, // change it
     B_SIZE = A_SIZE};

typedef int digit;
typedef unsigned long int size_length;

struct long_number{
	digit *values;
	size_length length;
};

long_number sum(long_number a, long_number b)
{
	long_number s;//otvet
	s.length = a.length + 1;
	s.values = new digit[s.length];

	s.values[a.length - 1] = a.values[a.length - 1];
	s.values[a.length] = 0;
	for (size_length i = 0; i < b.length; ++i)
		s.values[i] = a.values[i] + b.values[i];
	return s;
}

long_number &sub(long_number &a, long_number b)
{
	for (size_length i = 0; i < b.length; ++i)
	{
		a.values[i] -= b.values[i];
	}
	return a;
}

void normalize(long_number a)
{
	for (size_length i = 0; i < a.length - 1; ++i)
	{
		if (a.values[i] >= BASE)
		{
			digit carryover = a.values[i] / BASE;
			a.values[i + 1] += carryover;
			a.values[i] -= carryover * BASE;
		}
		else
		{
			if (a.values[i] < 0)
			{
				digit carryover = (a.values[i] + 1) / BASE - 1;
				a.values[i + 1] += carryover;
				a.values[i] -= carryover * BASE;
			}
		}
	}
}

long_number karatsube(long_number a, long_number b)
{
	long_number product;
	product.length = a.length + b.length;
	product.values = new digit[product.length];
	if (a.length < MIN_LENGTH_FOR_KARATSUBE)
	{
		memset(product.values, 0, sizeof(digit) * product.length);
		for (size_length i = 0; i < a.length; ++i)
			for (size_length j = 0; j < b.length; ++j)
				product.values[i + j] += a.values[i] * b.values[j];
	}
	else
	{
		long_number a_part1;
		a_part1.values = a.values;
		a_part1.length = (a.length + 1) / 2;

		long_number a_part2;
		a_part2.values = a.values + a_part1.length;
		a_part2.length = a.length / 2;

		long_number b_part1;
		b_part1.values = b.values;
		b_part1.length = (b.length + 1) / 2;

		long_number b_part2;
		b_part2.values = b.values + b_part1.length;
		b_part2.length = b.length / 2;

		//(A0 + A1), (B0 + B1)
		long_number sum_of_a_parts = sum(a_part1, a_part2);
		normalize(sum_of_a_parts);
		long_number sum_of_b_parts = sum(b_part1, b_part2);
		normalize(sum_of_b_parts);

		long_number product_of_sums_of_parts = karatsube(sum_of_a_parts, sum_of_b_parts); // (A0 + A1) * (B0 + B1)
		long_number product_of_first_parts = karatsube(a_part1, b_part1); // A0 * B0
		long_number product_of_second_parts = karatsube(a_part2, b_part2); // A1 * B1
		long_number product_in_brackets = sub(sub(product_of_sums_of_parts, product_of_first_parts), product_of_second_parts); 
		// (A0 + A1) * (B0 + B1) - (A0 * B0) - (A1 * B1)
		
		memcpy(product.values, product_of_first_parts.values,
			product_of_first_parts.length * sizeof(digit));
		memcpy(product.values + product_of_first_parts.length,
			product_of_second_parts.values, product_of_second_parts.length
			* sizeof(digit));
		for (size_length i = 0; i < product_in_brackets.length; ++i)
			product.values[a_part1.length + i] += product_in_brackets.values[i];

		delete[] sum_of_a_parts.values;
		delete[] sum_of_b_parts.values;
		delete[] product_of_sums_of_parts.values;
		delete[] product_of_first_parts.values;
		delete[] product_of_second_parts.values;
	}
	normalize(product);
	return product;
}

int main()
{
	long_number a, b;
	a.length = A_SIZE;
	a.values = new digit[A_SIZE];
	//
	a.values[A_SIZE - 1] = 1;
	for (int i = 0; i < A_SIZE - 1; i++)
		a.values[i] = (i * 999) % 10;

	b.length = B_SIZE;
	b.values = new digit[B_SIZE];
	///
	b.values[B_SIZE - 1] = 1;
	for (int i = 0; i < B_SIZE - 1; i++)
		b.values[i] = (i * 1003) % 10;
	///
	long_number c = karatsube(a, b);
	for (int i = A_SIZE- 1; i >= 0; i--)
		cout << a.values[i];
	cout << '\n';
	for (int i = B_SIZE - 1; i >= 0; i--)
		cout << b.values[i];
	cout << '\n';
	if (c.values[c.length - 1] != 0){
		for (int i = c.length - 1; i >= 0; i--)
			cout << c.values[i];
	}
	else
		for (int i = c.length - 2; i >= 0; i--)
			cout << c.values[i];
	cout << '\n';
	system("pause>>void");
	EXIT_SUCCESS;
}