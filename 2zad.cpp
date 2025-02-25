// VAR 8 
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <Windows.h>

using namespace std;

vector<int> generateArray(int n, int minChis, int maxChis) { // Ôóíêöèÿ äëÿ ãåíåðàöèè ñëó÷àéíîãî ìàññèâà >= 10
    vector<int> arr(n);
    for (int &num : arr) {
        num = minChis + rand() % (maxChis - minChis + 1);
    }
    return arr;
}

int findMinIndex(vector<int> &arr) { // Ôóíêöèÿ äëÿ íàõîæäåíèÿ èíäåêñà ìèíèìàëüíîãî ýëåìåíòà
    return min_element(arr.begin(), arr.end()) - arr.begin();
}

int findMaxSecondIndex(vector<int> &arr) { // Ôóíêöèÿ äëÿ íàõîæäåíèÿ èíäåêñà âòîðîãî ìàêñèìàëüíîãî ýëåìåíòà
    int maxVal = *std::max_element(arr.begin(), arr.end());
        int secondMaxIndex = -1;
        bool found = false;
        for (size_t i = 0; i < arr.size(); ++i) { // Óñëîâèÿ äëÿ ïîèñêà âòîðîãî ìàêñèìàëüíîãî ýëåìåíòà
            if (arr[i] < maxVal) {
                if (!found || arr[i] > arr[secondMaxIndex]) {
                    secondMaxIndex = i;
                    found = true;
                }
            }
        }
    return secondMaxIndex;
}

void modArray(vector<int> &arr) { // Ôóíêöèÿ äëÿ ìîäèôèêàöèè ìàññèâà
    if (!arr.empty()) { // Ïðîâåðêà åñëè ìàññèâ íå ïóñòîé
        int first = arr[0];
        arr.erase(arr.begin());
        arr.push_back(first);
    }
}

void printArray(vector<int> &arr ,int N) { // Ôóíêöèÿ äëÿ âûâîäà ìàññèâà
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 10; ++j) { // Ìàññèâ äîëæåí áûòü íå ìåíüøå 10
            cout << setw(3) << arr[i * 10 + j] << " ";
        }
        cout << endl;
    }
}

int main() {
    SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    srand(time(0)); // Èíèöèàëèçèðóåì ãåíåðàòîð ñëó÷àéíûõ ÷èñåë

    int n; // Ãåíåðàöèÿ ìàññèâà
    cout << "Ââåäèòå ðàçìåð ìàññèâà (n >= 10): ";
    cin >> n;
    if (n < 10) { // Ïðîâåðêà ðàçìåðà ìàññèâà
        cerr << "Îøèáêà! Ðàçìåð ìàññèâà íå óäîâëåòâîðÿåò óñëîâèþ!" << endl;
        return 1;
    }

    vector<int> arr = generateArray(n, 0, 100);
    cout << "Èñõîäíûé ìàññèâ: " << endl;
    for (int num : arr) cout << num << " "; // Âûâîä ìàññèâà
    cout << endl;

    int minIndex = findMinIndex(arr);
    int secMaxIndex = findMaxSecondIndex(arr);
    if (secMaxIndex != -1) { // Îáìåí ìèíèìàëüíîãî è âòîðîãî ìàêñèìàëüíîãî ýëåìåíòîâ
        swap(arr[minIndex], arr[secMaxIndex]);
    }

    cout << "Ìàññèâ ïîñëå èçìåíåíèÿ: " << endl;
    for (int num : arr) cout << num << " "; // Âûâîä èçìåíåííîãî ìàññèâà
    cout << endl;

    modArray(arr); // Ìîäèôèêàöèÿ ìàññèâà

    cout << "Ìàññèâ ïîñëå ìîäèôèêàöèè: " << endl;
    for (int num : arr) cout << num << " "; // Âûâîä ìîäèôèöèðîâàííîãî ìàññèâà
    cout << endl;

    int N; // Êîëè÷åñòâî ñòðîê
    cout << "Ââåäèòå êîëè÷åñòâî ñòðîê äëÿ âûâîäà ìàññèâà ôîðìàòà N x 10: ";
    cin >> N;
    if (N <= 0) {
        cerr << "Îøèáêà! Êîëè÷åñòâî ñòðîê N äîëæíî áûòü ïîëîæèòåëüíûì ÷èñëîì!";
        return 1;
    }
    vector<int> outputArray(N * 10);
    for (int i = 0; i < N * 10; ++i) {
        outputArray[i] = 10 + i;
    }

    cout << "Âûâîä ìàññèâà (" << N << " x 10):\n";
    printArray(outputArray, N);

    return 0;
}
