#include <iostream>
#include <string>

bool isDivisible(const std::string &number, int divisor)
{
    int remainder = 0;
    for (char digit : number)
    {
        remainder = (remainder * 10 + (digit - '0')) % divisor;
    }
    return remainder == 0;
}

std::string findNumber(int N)
{
    if (N == 1)
    {
        return "2";
    }

    std::string number = "12"; // Начальное значение для N = 2
    for (int K = 3; K <= N; K++)
    {
        // Проверяем делимость числа на 2K
        if (isDivisible(number, 2 * K))
        {
            number = "1" + number;
        }
        else
        {
            number = "2" + number;
        }
    }
    return number;
}

int main()
{
    int N;
    std::cout << "Введите значение N: ";
    std::cin >> N;

    std::string result = findNumber(N);
    std::cout << "Число, состоящее из " << N << " цифр 1 или 2 и делящееся на 2N: " << result << std::endl;

    return 0;
}
