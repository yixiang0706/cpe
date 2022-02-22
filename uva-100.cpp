#include<iostream>
using namespace std;
int main()
{
	int i, j, k, cyclelength, max, replacei, ii,jj;
	while (cin >> i >> j) {
		if (i > j)
		{
			ii = j;
			jj = i;
		}
		else {
			ii = i;
			jj = j;
		}
		max = 0;
		replacei = ii;
		k = replacei;
		while (k <= jj) {
			cyclelength = 1;
			while (k != 1) {
				if (k % 2 == 1) {
					k = 3 * k + 1;
					cyclelength++;
				}
				else {
					k = k / 2;
					cyclelength++;
				}
			}
			if (cyclelength > max) {
				max = cyclelength;
			}
			replacei++;
			k = replacei;
		}
		cout << i << " " << j << " " << max << endl;
	}
	return 0;
}