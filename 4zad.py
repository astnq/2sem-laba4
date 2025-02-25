import random

# Типы выбора
COOPERATE = True
BETRAY = False

# Подсчет очков
def calculate_scores(choiceA, choiceB):
    if choiceA == COOPERATE and choiceB == COOPERATE:
        return 24, 24
    elif choiceA == COOPERATE and choiceB == BETRAY:
        return 0, 20
    elif choiceA == BETRAY and choiceB == COOPERATE:
        return 20, 0
    else:  # BETRAY and BETRAY
        return 4, 4

# Алгоритм 1: Всегда сотрудничать
def always_cooperate(round_number, self_choices, enemy_choices):
    return COOPERATE

# Алгоритм 2: Всегда предавать
def always_betray(round_number, self_choices, enemy_choices):
    return BETRAY

# Алгоритм 3: Повторяет выбор противника из прошлого раунда
def tit_for_tat(round_number, self_choices, enemy_choices):
    if round_number == 0:
        return COOPERATE  # Первый ход всегда сотрудничество
    return enemy_choices[-1]

# Запуск игры между двумя алгоритмами
def play_game(algorithmA, algorithmB):
    rounds = random.randint(100, 200)  # Количество раундов от 100 до 200
    choicesA, choicesB = [], []
    scoreA, scoreB = 0, 0

    print(f"Игра началась! Количество раундов: {rounds}")

    for i in range(rounds):
        # Получение выбора обоих алгоритмов
        choiceA = algorithmA(i, choicesA, choicesB)
        choiceB = algorithmB(i, choicesB, choicesA)

        # Сохранение выборов
        choicesA.append(choiceA)
        choicesB.append(choiceB)

        # Подсчет очков
        scores = calculate_scores(choiceA, choiceB)
        scoreA += scores[0]
        scoreB += scores[1]

        print(f"Раунд {i + 1}: A выбрал {'Сотрудничество' if choiceA else 'Предательство'}, "
              f"B выбрал {'Сотрудничество' if choiceB else 'Предательство'}")

    print("Игра окончена!")
    print(f"Итоговый счет: A = {scoreA}, B = {scoreB}")

# Тестирование алгоритмов
if __name__ == "__main__":
    random.seed()  # Инициализация генератора случайных чисел

    # Запуск игр
    print("Игра 1: Всегда сотрудничает vs Всегда предает")
    play_game(always_cooperate, always_betray)

    print("\nИгра 2: Всегда предает vs Повторяет выбор противника")
    play_game(always_betray, tit_for_tat)

    print("\nИгра 3: Повторяет выбор противника vs Всегда сотрудничает")
    play_game(tit_for_tat, always_cooperate)
