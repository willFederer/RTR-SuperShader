#include <iostream>

using namespace std;

int C(int i, int j);
int SingleCombination(int m, int n);
int TotalCombination(int m, int n);

//calculate C(i, j)
int C(int i, int j) {
	if (i > j) return 0;
	int Result = 1;
	int nLoop = i;
	while (nLoop) {
		nLoop--;
		Result *= (j - nLoop);
	}

	int Factor = i;
	while (Factor) {
		Result /= Factor;
		Factor--;
	}
	return Result;
}

//exactly m light type, n light source number
//正好是m种灯光然后n个光源
int SingleCombination(int m, int n) {
	if (n < 1 || m < 1 || m > n) return 0;
	if (n == 1) return m;
	if (m == 1) return 1;
	if (m == n) return 1;
	//m种灯光肯定占了m个光源，然后往剩余n-m个光源填充m种灯光
	if (m < n) return TotalCombination(m, n - m);
}

//no more than m light type, n light source number
//不多于m种灯光，n个光源
int TotalCombination(int m, int n) {
	int Result = 0;
	for (int i = m; i > 0; i--) {
		//以灯光种类来分，先遍历1-m种灯光然后再递归
		Result += C(i, m) * SingleCombination(i, n);
	}
	return Result;
}

void main() {
	int m = 0;
	int n = 0;
	while (1) {
		cin >> m >> n;
		cout << TotalCombination(m, n) << endl;
		//system("pause");
	}
}