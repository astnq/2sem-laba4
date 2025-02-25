import random

# Функция для генерации случайного массива
def generate_array(n, min_val, max_val):
    return [random.randint(min_val, max_val) for _ in range(n)]

# Функция для нахождения индекса минимального элемента
def find_min_index(arr):
    return arr.index(min(arr))

# Функция для нахождения индекса второго максимального элемента
def find_second_max_index(arr):
    max_val = max(arr)
    second_max = float('-inf')
    second_max_index = -1
    for i, num in enumerate(arr):
        if num < max_val and num > second_max:
            second_max = num
            second_max_index = i
    return second_max_index

# Функция для модификации массива
def modify_array(arr):
    if arr:
        first = arr.pop(0)
        arr.append(first)

# Функция для вывода массива
def print_array(arr, N):
    for i in range(N):
        print(" ".join(f"{arr[i * 10 + j]:3}" for j in range(10)))

# Главная функция
def main():
    n = int(input("Введите размер массива (n >= 10): "))
    if n < 10:
        print("Ошибка! Размер массива должен быть не меньше 10!")
        return

    arr = generate_array(n, 0, 100)
    print("Исходный массив:")
    print(" ".join(map(str, arr)))

    # Обмен минимального и второго максимального элементов
    min_index = find_min_index(arr)
    second_max_index = find_second_max_index(arr)
    if second_max_index != -1:
        arr[min_index], arr[second_max_index] = arr[second_max_index], arr[min_index]

    print("\nМассив после изменения:")
    print(" ".join(map(str, arr)))

    # Модификация массива
    modify_array(arr)
    print("\nМассив после модификации:")
    print(" ".join(map(str, arr)))

    # Формат вывода N x 10
    N = int(input("\nВведите количество строк для вывода массива формата N x 10: "))
    if N <= 0:
        print("Ошибка! Количество строк N должно быть положительным числом!")
        return

    output_array = [10 + i for i in range(N * 10)]
    print("\nВывод массива ({} x 10):".format(N))
    print_array(output_array, N)

if __name__ == "__main__":
    main()
