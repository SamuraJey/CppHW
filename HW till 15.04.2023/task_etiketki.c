#include <stdio.h>
#include <stdlib.h>

int compare_int(const void* a, const void* b) // функция сравнения для qsort
{
    return *(int*)b - *(int*)a; // сортировка по убыванию
}

int main() 
{
    int n;
    scanf("%d", &n);

    int* albums = malloc(n * sizeof(int)); // выделение памяти для массива
    int capacity = 0;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &albums[i]);
        capacity += albums[i]; // считаем общую вместимость
    }

    qsort(albums, n, sizeof(int), compare_int); // сортируем по убыванию

    int labels = 0;
    int currentCapacity = 0;

    for (int i = 0; i < n; i++) 
    {
        if (currentCapacity >= capacity / 2) // если вместимость уже больше половины, то выходим
        {
            break;
        }

        if (currentCapacity + albums[i] <= capacity / 2) // если вместимость меньше половины, то добавляем альбом
        {
            currentCapacity += albums[i];
            labels += albums[i];
        } 
        else // если вместимость больше половины, то добавляем разницу
        {
            labels += (capacity / 2 - currentCapacity); // добавляем разницу
            break;
        }
    }

    printf("%d\n", labels);
    free(albums); // освобождаем память
    return 0;
}
