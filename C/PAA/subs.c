#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// https://stackoverflow.com/questions/30674821/frequency-of-all-substrings

typedef struct SymbolQ
{
    char *symbol;
    double score;
    struct SymbolQ *next;
} SymbolQ;

SymbolQ *insertSymbolSorted(SymbolQ *queue, int sym_len, char *symbol, double score)
{
    /// Creating node
    SymbolQ *symbolQ = (SymbolQ *)malloc(sizeof(SymbolQ));

    symbolQ->symbol = memcpy((char *)malloc(sym_len), symbol, sym_len);
    symbolQ->score = score;
    symbolQ->next = NULL;

    /// trivial case
    if (!queue)
    {
        return symbolQ;
    }

    /// test head
    if (score > queue->score)
    {
        symbolQ->next = queue;
        return symbolQ;
    }

    /// iterate through queue in order to insert
    SymbolQ *iter = queue;
    for (; iter != NULL; iter = iter->next)
    {
        // printf("%p\n", iter);
        if (!iter->next || score > iter->next->score)
        {
            symbolQ->next = iter->next;
            iter->next = symbolQ;
            iter = symbolQ;
        }
    }

    return queue;
}

void printQueue(SymbolQ *queue)
{
    SymbolQ *iter = queue;
    for (; iter; iter = iter->next)
    {
        printf("[%.2lf] '%s'\n", iter->score, iter->symbol);
    }
    // printf("{!}\n");
}

/* Find the number of matching substrings in the string s and returns a list of symbols by score */
SymbolQ *sub(char *s)
{
    size_t s_len = strlen(s);
    short *matches = (short *)calloc(s_len, sizeof(short));
    short *dups = (short *)calloc(s_len, sizeof(short));
    size_t n = s_len * sizeof(short); /* used by bzero() */
    size_t len, i, j, stop;
    double bytes_saved;

    SymbolQ *symbolQ = NULL;

    /* Find all substrings of length s_len..1 */
    for (len = s_len; len >= 1; --len)
    {
        bzero((void *)matches, n); /* zero out the number of matches */
        bzero((void *)dups, n);    /* zero out the duplicates */
        stop = s_len - len + 1;
        for (i = 0; i < stop; ++i)
        {
            if (dups[i]) /* this is a duplicate (was already counted) */
                continue;
            for (j = i + 1; j < stop; ++j)
            {
                if (memcmp(s + i, s + j, len)) /* substring comparison */
                    continue;                  /* not a match? continue */
                matches[i]++;
                dups[j] = 1;
            }
            bytes_saved = (int)len * (matches[i] + 1) - (int)len;
            // if (matches[i])
            if (bytes_saved)
            {
            }
            printf("%d: [%lf] %.*s \n", matches[i] + 1, bytes_saved, (int)len, s + i);
            if (bytes_saved)
                symbolQ = insertSymbolSorted(symbolQ, (int)len, s + i, bytes_saved);
        }
        printf("------------------\n");
    }

    return symbolQ;
}

int main()
{
    // sub("baobab");
    SymbolQ *symbols = sub("baobab");
    // ba - 0
    // b - 10
    // o - 11
    // 0 11 0 10

    // b - 0
    // a - 10
    // o - 11
    // 0 10 11 0 10 0

    printQueue(symbols);

    return 0;
}

/*
 * symbol size * symbol frequency - symbol size
 * */