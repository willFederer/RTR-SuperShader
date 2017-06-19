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
//������m�ֵƹ�Ȼ��n����Դ
int SingleCombination(int m, int n) {
	if (n < 1 || m < 1 || m > n) return 0;
	if (n == 1) return m;
	if (m == 1) return 1;
	if (m == n) return 1;
	//m�ֵƹ�϶�ռ��m����Դ��Ȼ����ʣ��n-m����Դ���m�ֵƹ�
	if (m < n) return TotalCombination(m, n - m);
}

//no more than m light type, n light source number
//������m�ֵƹ⣬n����Դ
int TotalCombination(int m, int n) {
	int Result = 0;
	for (int i = m; i > 0; i--) {
		//�Եƹ��������֣��ȱ���1-m�ֵƹ�Ȼ���ٵݹ�
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