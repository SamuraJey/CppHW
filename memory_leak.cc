int main(int argc, char const *argv[])
{
    while (true)
    {
        void *memory = new char[100];
        // Не делаем delete [] memory
        // И растекись биты по оперативке...
    }
    return 0;
}
