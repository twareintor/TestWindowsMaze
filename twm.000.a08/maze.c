
#include <windows.h>
#include "maze.h"


int getMaze(char* sz, size_t const len, int const w, int const h)
{
	int M[9999] = { 2 }, *u = M, N[9999], R = h, a[4], l[] = { 0, -1, w - 1, -1 },
	    m[] = { 1, -w, -1, w }, *b = N, *d = N, c, e, f, g, i, j, k, s;

#ifdef USE_MTWISTER	
	MTRand r = seedRand(time(NULL)); ///<== ADDED (CC)
#else
    srand(time(0)); ///<== ADDED (CC)
#endif
    for (M[i = w * R - 1] = 24; f | d >= b;)
    {
        c = M[g = i];
        i = e;
        for (s = f = 0; s < 4; s++)
            if ((k = m[s] + g) >= 0 && k < w * R && l[s] != k % w
                && (!M[k] || !j && c >= 16 != M[k] >= 16))
                a[f++] = s;
        if (f)
        {
#ifdef USE_MTWISTER				
			f = M[e = m[s = a[genRand(&r)*(float)INT_MAX/(1 + 2147483627/f)]] + g];
#else
			f = M[e = m[s = a[rand()*INT_MAX/(1 + 2147483627/f)]] + g];
#endif
            j = j < f ? f : j;
            f += c & -16 * !j;
            M[g] = c|1<< s;
            M[*d++ = e] = f | 1<<(s + 2)%4;
        }
        else
            e = d > b++ ? b[-1] : e;
    }
    P(" ");
    for (s = w; --s; P("_"))
        P(" ");
    for (; P("\n"), R--; P("|"))
        for (e = w; e--; P("_ " + (*u++ / 8) % 2))
            P("| " + (*u / 4) % 2);
    return (int)strlen(sz);
}

