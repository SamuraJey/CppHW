#include <vector>
#include <cstdio>
#include <map>
#include <cassert>

using namespace std;

struct Scanner
{
    char buffer[1 << 16];
    int pos;
    int size;
    int c; // EOT == -1

    Scanner()
        : pos(0)
        , size(0)
    {
        nextChar();
    }

    void nextChar()
    {
        if (pos == size)
        {
            size = int(fread(buffer, sizeof(char), sizeof(buffer) / sizeof(char), stdin));
            pos = 0;
            if (size == 0)
            {
                c = -1;
                return;
            }
        }
        assert(pos < size);
        c = buffer[pos] & 0xFF;
        pos++;
    }

    int nextInt()
    {
        while (c == ' ' || c == '\n' || c == '\r' || c == '\t')
        {
            nextChar();
        }
        assert('0' <= c && c <= '9');
        int n = c - '0';
        nextChar();
        while ('0' <= c && c <= '9')
        {
            int d = c - '0';
            nextChar();
            n = n * 10 + d;
            assert(n <= 7500);
        }
        return n;
    }
};

int main()
{
    Scanner in;
    int len = in.nextInt();
    int nTemplates = in.nextInt();
    int nQ = in.nextInt();
    map<vector<int>, int> templateToId;
    for (int i = 0; i < nTemplates; i++)
    {
        int id = in.nextInt();
        vector<int> temp(len);
        for (auto &x : temp)
        {
            x = in.nextInt();
        }
        templateToId[temp] = id;
    }
    
    int ok = 0;
    int bad = 0;

    for (int i = 0; i < nQ; i++)
    {
        vector<int> q(len);
        for (auto &x : q)
        {
            x = in.nextInt();
        }
        auto it = templateToId.find(q);
        if (it == templateToId.end())
        {
            printf("-\n");
            bad++;
        }
        else
        {
            printf("%d\n", it -> second);
            ok++;
        }
    }
    printf("OK=%d BAD=%d\n", ok, bad);
    return 0;
}