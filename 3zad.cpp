#include <iostream>
#include <Windows.h>
#include <random>
#include <vector>
using namespace std;
const int n1 = 50, n2 = 100, n3 = 1000;
void generateRandomNumber(int* arr, int n) {
    random_device rd;
    ranlux48 engine(rd());
    uniform_int_distribution<int> dist(1, 100); // Çàäàâàòü äèàïàçîí äëÿ ãåíåðàöèè ÷èñåë
    for (int i = 0; i < n; i++) {
		arr[i] = dist(engine);
	}
}

int X2(int arr[], int n) {
	const int iter = 25;
	int sum[iter] = { 0 };
	int mat = 0;
	for (int i = 0; i < n;i++) {
		//Äåëèì èíòåðâàëû è ïîäñ÷èòûâàåì êîëëè÷åñòâî â íèõ
		sum[arr[i] * iter / 101]++;
		mat += arr[i];
	}
	float x = 0;
	cout << "Êîë-âî i ýëåìåíòîâ â 25 èíòåðâàëàõ" << endl;
	for (int i : sum) {
		cout << i << " ";
		// i êîë ýëåì â èíòåðâàëîâ
		// n1 / iter - îæèäàåìî
		x += float((i - (n / iter)) * (i - (n / iter))) / (n / iter);
	}
	cout << endl<<"Ìàò îæèäàíèå îæèäàíèå: 50,5 ðåàëüíîñòü: "<<mat/n<<endl;
	return x;
}
int main() {
	system ("chcp 65001");
	int arr1[n1];
	generateRandomNumber(arr1, n1);
	int arr2[n2];
	generateRandomNumber(arr2, n2);
	int arr3[n3];
	generateRandomNumber(arr3, n3);
	float krit = 44.314;
	cout << " Äëÿ ìàññèâà íà 50 ýëåìåíòîâ " << endl;
	//Ðåçóëüòàò ïðîâðêè ãèïîòåçû 
	int x = X2(arr1, n1);
	cout << " x^2 : " << x<< endl;
	if (x < krit) {
		cout << "Ãèïîòåçà î íîðìàëüíîì ðàñïðåäåëåíèè ïðèíèìàåòñÿ."<<endl;
	}
	else {
		cout << "Ãèïîòåçà î íîðìàëüíîì ðàñïðåäåëåíèè îòêëîíÿåòñÿ." << endl;
	}
	cout << " Äëÿ ìàññèâà íà 100 ýëåìåíòîâ " << endl;
	x = X2(arr2, n2);
	cout << " x^2 : " << x << endl;
	if (x < krit) {
		cout << "Ãèïîòåçà î íîðìàëüíîì ðàñïðåäåëåíèè ïðèíèìàåòñÿ." << endl;
	}
	else {
		cout << "Ãèïîòåçà î íîðìàëüíîì ðàñïðåäåëåíèè îòêëîíÿåòñÿ." << endl;
	}
	cout << " Äëÿ ìàññèâà íà 1000 ýëåìåíòîâ " << endl;
	x = X2(arr3, n3);
	cout << " x^2 : " << x << endl;
	if (x < krit) {
		cout << "Ãèïîòåçà î íîðìàëüíîì ðàñïðåäåëåíèè ïðèíèìàåòñÿ." << endl;
	}
	else {
		cout << "Ãèïîòåçà î íîðìàëüíîì ðàñïðåäåëåíèè îòêëîíÿåòñÿ." << endl;
	}
}
