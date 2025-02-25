#include <iostream>
#include <vector>
#include <Windows.h>
#include <ctime>
#include <cstdlib>

using namespace std;

// Òèïû âûáîðà
const bool COOPERATE = true;
const bool BETRAY = false;

// Ïîäñ÷åò î÷êîâ
pair<int, int> calculateScores(bool choiceA, bool choiceB) {
    if (choiceA == COOPERATE && choiceB == COOPERATE) {
        return {24, 24};
    } else if (choiceA == COOPERATE && choiceB == BETRAY) {
        return {0, 20};
    } else if (choiceA == BETRAY && choiceB == COOPERATE) {
        return {20, 0};
    } else { // BETRAY && BETRAY
        return {4, 4};
    }
}

// Àëãîðèòì 1: Âñåãäà ñîòðóäíè÷àòü
bool alwaysCooperate(int round_number, const vector<bool>& self_choices, const vector<bool>& enemy_choices) {
    return COOPERATE;
}

// Àëãîðèòì 2: Âñåãäà ïðåäàâàòü
bool alwaysBetray(int round_number, const vector<bool>& self_choices, const vector<bool>& enemy_choices) {
    return BETRAY;
}

// Àëãîðèòì 3: Ïîâòîðÿåò âûáîð ïðîòèâíèêà èç ïðîøëîãî ðàóíäà)
bool titForTat(int round_number, const vector<bool>& self_choices, const vector<bool>& enemy_choices) {
    if (round_number == 0) {
        return COOPERATE; // Ïåðâûé õîä âñåãäà ñîòðóäíè÷åñòâî
    }
    return enemy_choices.back();
}

// Çàïóñê èãðû ìåæäó äâóìÿ àëãîðèòìàìè
void playGame(bool (*algorithmA)(int, const vector<bool>&, const vector<bool>&),
              bool (*algorithmB)(int, const vector<bool>&, const vector<bool>&)) {
    int rounds = 100 + rand() % 101; // Êîëè÷åñòâî ðàóíäîâ îò 100 äî 200
    vector<bool> choicesA, choicesB;
    int scoreA = 0, scoreB = 0;

    cout << "Èãðà íà÷àëàñü! Êîëè÷åñòâî ðàóíäîâ: " << rounds << endl;

    for (int i = 0; i < rounds; ++i) {
        // Ïîëó÷åíèå âûáîðà îáîèõ àëãîðèòìîâ
        bool choiceA = algorithmA(i, choicesA, choicesB);
        bool choiceB = algorithmB(i, choicesB, choicesA);

        // Ñîõðàíåíèå âûáîðîâ
        choicesA.push_back(choiceA);
        choicesB.push_back(choiceB);

        // Ïîäñ÷åò î÷êîâ
        auto scores = calculateScores(choiceA, choiceB);
        scoreA += scores.first;
        scoreB += scores.second;

        cout << "Ðàóíä " << i + 1 << ": A âûáðàë " << (choiceA ? "Ñîòðóäíè÷åñòâî" : "Ïðåäàòåëüñòâî")
             << ", B âûáðàë " << (choiceB ? "Ñîòðóäíè÷åñòâî" : "Ïðåäàòåëüñòâî") << endl;
    }

    cout << "Èãðà îêîí÷åíà!" << endl;
    cout << "Èòîãîâûé ñ÷åò: A = " << scoreA << ", B = " << scoreB << endl;
}

// Òåñòèðîâàíèå àëãîðèòìîâ
int main() {
    SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    srand(time(0)); // Èíèöèàëèçàöèÿ ãåíåðàòîðà ñëó÷àéíûõ ÷èñåë

    // Çàïóñê èãð
    cout << "Èãðà 1: Âñåãäà ñîòðóäíè÷àåò vs Âñåãäà ïðåäàåò" << endl;
    playGame(alwaysCooperate, alwaysBetray);

    cout << "\nÈãðà 2: Âñåãäà ïðåäàåò vs Ïîâòîðÿåò âûáîð ïðîòèâíèêà" << endl;
    playGame(alwaysBetray, titForTat);

    cout << "\nÈãðà 3: Ïîâòîðÿåò âûáîð ïðîòèâíèêà vs Âñåãäà ñîòðóäíè÷àåò" << endl;
    playGame(titForTat, alwaysCooperate);

    return 0;
}
