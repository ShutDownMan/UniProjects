#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/// Frequency Tree API

#define SYMBOL_MAX_LEN 8
#define DEFAULT_SAMPLE_LEN 256

typedef struct FreqTree
{
    /// frequency of that chain of symbols
    size_t count;

    /// symbol children for the ASCII table
    struct FreqTree *symbols[256];

    /// parent symbol
    struct FreqTree *parent;

    /// if counting for that symbol is locked
    char locked;
} FreqTree;

FreqTree *createFreqTree()
{
    FreqTree *ft = (FreqTree *)malloc(sizeof(FreqTree));

    ft->count = 0;
    bzero((void *)ft->symbols, sizeof(FreqTree *) * 256);
    ft->parent = NULL;
    ft->locked = 0;

    return ft;
}

FreqTree *constructFreqTree(FILE *f)
{
    FreqTree *ft = createFreqTree();

    char *s = (char *)malloc(sizeof(char) * DEFAULT_SAMPLE_LEN + 1);
    fread(s, sizeof(char), DEFAULT_SAMPLE_LEN, f);
    s[DEFAULT_SAMPLE_LEN] = '\0';
    size_t s_len = strlen(s);

    s = (char *)realloc(s, s_len);

    FreqTree *ft_streak_symbol = NULL;
    char streak = 0;

    for (size_t i = 0; i < s_len; i++)
    {
        /// if the symbol wasn't tested
        if (!ft->symbols[s[i]])
        {
            ft_streak_symbol = ft->symbols[s[i]] = createFreqTree();
            ft->symbols[s[i]]->parent = ft;
            ft->symbols[s[i]]->count = 1;
        }

        for (size_t j = i + 1; j < s_len; j++)
        {
            ft_streak_symbol = ft;

            // ft_streak_symbol->count++;

            streak = 1;
            for (size_t off = 0; j + off < s_len && streak && i + off < j && off < SYMBOL_MAX_LEN; off++)
            {
                unsigned char curr_symbol = (unsigned char)s[i + off];

                /// if current test substring symbol matches
                if (s[j + off] == curr_symbol)
                {
                    /// if there's a count there already, update streak
                    if (ft_streak_symbol->symbols[curr_symbol])
                    {
                        ft_streak_symbol = ft_streak_symbol->symbols[curr_symbol];
                    }
                    else //< if no count, then create one
                    {
                        ft_streak_symbol->symbols[curr_symbol] = createFreqTree();
                        ft_streak_symbol->symbols[curr_symbol]->parent = ft_streak_symbol;
                        ft_streak_symbol = ft_streak_symbol->symbols[curr_symbol];
                        ft_streak_symbol->count = 1;
                    }

                    /// if current symbol count is not locked
                    if (!ft_streak_symbol->locked)
                    {
                        /// increment count on symbol
                        ft_streak_symbol->count++;
                    }
                }
                else //< end streak
                {
                    streak = 0;
                }
            }
        }
        /// lock entire substring as counted
        ft_streak_symbol = ft;
        for (size_t off = 0; i + off < s_len && ft_streak_symbol; off++)
        {
            char curr_symbol = s[i + off];

            ft_streak_symbol = ft_streak_symbol->symbols[curr_symbol];

            if (ft_streak_symbol)
            {
                ft_streak_symbol->locked = 1;
            }
        }
    }

    return ft;
}

void printFreqTreeRec(FreqTree *ft, char symbol, short level)
{
    for (size_t i = 0; i < level; i++)
    {
        printf("-");
    }

    switch (symbol)
    {
    case '\n':
        printf("[!] %d%s\n", ft->count, (ft->locked) ? "*" : " ");
        break;

    default:
        printf("[%c] %d%s\n", symbol, ft->count, (ft->locked) ? "*" : " ");
        break;
    }

    for (size_t i = 0; i < 256; i++)
    {
        if (ft->symbols[i])
        {
            printFreqTreeRec(ft->symbols[i], (char)i, level + 1);
        }
    }
}

void printFreqTree(FreqTree *ft)
{
    if (ft)
    {
        for (size_t i = 0; i < 256; i++)
        {
            if (ft->symbols[i])
            {
                printFreqTreeRec(ft->symbols[i], (char)i, 0);
                // printf("\n");
            }
        }
    }
}

/// Huffman Tree API

/// Huffman tree node struct
typedef struct HuffTree
{
    double score;
    size_t uses_count;

    unsigned short level;

    char is_symbol;

    FreqTree *symbol;

    struct HuffTree *left_child;
    struct HuffTree *right_child;

    short symbol_code_len;
    short *symbol_code;

    char symbol_char;
} HuffTree;

/// Queue needed for tree construction
typedef struct HuffQueue
{
    HuffTree *treeNode;

    struct HuffQueue *next;
} HuffQueue;

HuffTree *createHuffTree()
{
    HuffTree *ht = (HuffTree *)malloc(sizeof(HuffTree));

    ht->score = 0;
    ht->uses_count = 0;

    ht->level = 0;

    ht->is_symbol = 0;

    ht->symbol = NULL;

    ht->left_child = NULL;
    ht->right_child = NULL;

    ht->symbol_code = NULL;
    ht->symbol_char = '\0';

    return ht;
}

HuffQueue *createHuffQ()
{
    HuffQueue *hq = (HuffQueue *)malloc(sizeof(HuffQueue));

    hq->treeNode = NULL;
    hq->next = NULL;

    return hq;
}

HuffQueue *pushHuffQueue(HuffQueue *qHead, HuffQueue *newNode)
{
    /// insert in queue, trivial case
    if (!qHead)
    {
        return newNode;
    }

    /// test head
    if (newNode->treeNode->score > qHead->treeNode->score)
    {
        newNode->next = qHead;
        return newNode;
    }

    /// iterate through queue in order to insert
    HuffQueue *iter = qHead;
    for (; iter != NULL; iter = iter->next)
    {
        // printf("%p\n", iter);
        if ((!iter->next || newNode->treeNode->score < iter->next->treeNode->score) || (newNode->treeNode->score == iter->next->treeNode->score && newNode->treeNode->level < iter->next->treeNode->level))
        {
            newNode->next = iter->next;
            iter->next = newNode;
            return qHead;
        }
    }

    return qHead;
}

void freeFreqTree(FreqTree *ft)
{
    for (size_t i = 0; i < 256; i++)
    {
        if (ft->symbols[i])
        {
            freeFreqTree(ft->symbols[i]);
        }
    }
    free(ft);
}

HuffQueue *pushFreqTreeToHuffQRec(HuffQueue *qHead, FreqTree *ft, size_t level, char symbol_char)
{
    /// create queue node
    HuffQueue *newNode = createHuffQ();
    newNode->treeNode = createHuffTree();

    newNode->treeNode->is_symbol = 1;
    newNode->treeNode->symbol = ft;
    newNode->treeNode->symbol_char = symbol_char;
    newNode->treeNode->level = level;
    newNode->treeNode->score = (ft->count) ? (level + 1) * ft->count - level : 0;

    qHead = pushHuffQueue(qHead, newNode);

    for (size_t i = 0; i < 256; i++)
    {
        if (ft->symbols[i])
        {
            if (ft->symbols[i]->count * (level + 1) - (level + 1) >= newNode->treeNode->score)
            {
                qHead = pushFreqTreeToHuffQRec(qHead, ft->symbols[i], level + 1, (char)i);
            }
            else
            {
                freeFreqTree(ft->symbols[i]);
                // free(ft);
                ft->symbols[i] = NULL;
            }
        }
    }

    return qHead;
}

HuffQueue *pushFreqTreeToHuffQ(FreqTree *ft)
{
    HuffQueue *qHead = NULL;
    if (ft)
    {
        for (size_t i = 0; i < 256; i++)
        {
            if (!ft->symbols[i])
            {
                ft->symbols[i] = createFreqTree();
                ft->symbols[i]->parent = ft;
                ft->symbols[i]->count = 0;
            }

            qHead = pushFreqTreeToHuffQRec(qHead, ft->symbols[i], 1, (char)i);
            // printf("\n");
        }
    }

    return qHead;
}

HuffQueue *popHuffQueue(HuffQueue **qHead)
{
    HuffQueue *popped = (*qHead);

    if (popped)
    {
        (*qHead) = popped->next;

        // popped->next = NULL;
    }

    return popped;
}

void printHuffQueue(HuffQueue *queue)
{
    HuffQueue *iter = queue;
    for (; iter; iter = iter->next)
    {
        if (iter->treeNode->score > 0)
        {
            switch (iter->treeNode->symbol_char)
            {
            case '\n':
                printf("[%.2lf] '@'\n", iter->treeNode->score);
                break;

            default:
                printf("[%.2lf] '%c'\n", iter->treeNode->score, iter->treeNode->symbol_char);
                break;
            }
        }
    }
    // printf("{!}\n");
}

HuffTree *treefyHuffQueue(HuffQueue *qHead)
{
    HuffQueue *popped1, *popped2;

    do
    {
        popped1 = popHuffQueue(&qHead);
        popped2 = popHuffQueue(&qHead);

        if (popped1)
        {
            if (popped2)
            {
                HuffQueue *newNode = createHuffQ();
                newNode->treeNode = createHuffTree();

                newNode->treeNode->is_symbol = 0;
                newNode->treeNode->score = popped1->treeNode->score + popped2->treeNode->score;
                newNode->treeNode->level = fmax(popped1->treeNode->level, popped2->treeNode->level);

                newNode->treeNode->left_child = popped1->treeNode;
                newNode->treeNode->right_child = popped2->treeNode;

                qHead = pushHuffQueue(qHead, newNode);

                free(popped1);
                free(popped2);
            }
        }
    } while (popped2);

    return popped1->treeNode;
}

void printHuffTree(HuffTree *tree)
{
    if (!tree)
        return;

    // char *symbol_char[tree->level + 2];
    // HuffTree *tracer = tree;
    // symbol_char[tree->level + 1] = '\0';
    // for (size_t i = tree->level + 1; i >= 0 && tracer; --i, tracer = tracer.parent)
    // {
    //     symbol_char[i] = tree->symbol_char;
    // }

    if (tree->score > 0)
    {
        switch (tree->symbol_char)
        {
        case '\n':
            printf("(lvl %hu, score %g, '@') ", tree->level, tree->score);
            break;

        default:
            if (tree->symbol_char)
            {
                printf("(lvl %hu, score %g, '%c') ", tree->level, tree->score, tree->symbol_char);
            }
            else
            {
                printf("(lvl %hu, score %g) ", tree->level, tree->score);
            }
            break;
        }
    }

    printHuffTree(tree->left_child);
    printHuffTree(tree->right_child);
}

HuffTree *constructHuffTree(FreqTree *ft)
{
    HuffQueue *qHead = pushFreqTreeToHuffQ(ft);

    printHuffQueue(qHead);
    printf("-------\n");

    HuffTree *ht = treefyHuffQueue(qHead);

    return ht;
}

/// main

int main(int argc, char const *argv[])
{
    FILE *f = fopen("./arquivo_de_entrada.txt", "r");

    FreqTree *ft = constructFreqTree(f);

    printFreqTree(ft);
    printf("-------\n");

    HuffTree *ht = constructHuffTree(ft);

    printHuffTree(ht);
    printf("\n-------\n");

    // print("%c\n", '?');

    return 0;
}

/*

    short tam_cod;  // tamanho do c¢digo em bits
    short *cod;     // array com bytes contendo o c¢digo do simbolo

*/