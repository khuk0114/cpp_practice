#include <iostream>

using namespace std;

int main() {
	int n, m, sum = 0;
	cin >> n >> m;
	int* arr = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n - 2; i++) {
		for (int j = 1; j < n - 1; j++) {
			for (int k = 2; k < n; k++) {
				if (arr[i] == arr[j] || arr[j] == arr[k] || arr[i] == arr[k]) continue;
				else if (arr[i] + arr[j] + arr[k] > m) continue;
				else if (sum > arr[i] + arr[j] + arr[k]) continue;
				else sum = arr[i] + arr[j] + arr[k];

			}
		}
	}
	cout << sum;

	delete[] arr;
	return 0;
}
//vertor로도 풀 수 있다.