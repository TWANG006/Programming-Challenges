/*
It’s hard to construct a problem that’s so easy that everyone will get it, yet still difficult enough to be
worthy of some respect. Usually, we err on one side or the other. How simple can a problem really be?
Here, as in Celebrity Jepoardy, questions and answers are a bit confused, and, because the participants
are celebrities, there’s a real need to make the challenges simple. Your program needs to prepare
a question to be solved — an equation to be solved — given the answer. Specifically, you have to
write a program which finds the simplest possible equation to be solved given the answer, considering
all possible equations using the standard mathematical symbols in the usual manner. In this context,
simplest can be defined unambiguously several different ways leading to the same path of resolution.
For now, find the equation whose transformation into the desired answer requires the least effort.
For example, given the answer X = 2, you might create the equation 9 − X = 7. Alternately, you
could build the system X > 0; X2 = 4. These may not be the simplest possible equations. Solving
these mind-scratchers might be hard for a celebrity.

Input
Each input line contains a solution in the form < symbol > = < value >

Output
For each input line, print the simplest system of equations which would to lead to the provided solution,
respecting the use of space exactly as in the input.

Sample Input
Y = 3
X=9

Sample Output
Y = 3
X=9
*/

#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int main()
{
	char c[10000];

	freopen("input.txt", "r", stdin);
	freopen("output_mine.txt", "w", stdout);

	/* Notice that gets is quite different from fgets: not only gets uses stdin as source,
	but it does not include the ending newline character in the resulting string and 
	does not allow to specify a maximum size for str*/

	while (gets_s(c) != NULL)
	{
		printf("%s\n", c);
	}	
}