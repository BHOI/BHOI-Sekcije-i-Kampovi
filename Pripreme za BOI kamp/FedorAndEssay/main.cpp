#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <map>

using namespace std;

#define WORD_COUNT 300000
#define DFS_WHITE 0
#define DFS_BLACK 1

long long int word_count = 0, n, m, lengths [WORD_COUNT], r_count[WORD_COUNT];

bool visited [WORD_COUNT];

vector <long long int> words;

vector <long long int> graph [WORD_COUNT];
vector <long long int> rev_graph[WORD_COUNT];
vector <long long int> order;

vector <pair <long long int, long long int> > edges;

long long int R [WORD_COUNT], L [WORD_COUNT];

struct mypair
{
    long long int r, l;

    mypair() { }
    mypair(long long int _r, long long int _l) { r = _r; l = _l; }

    bool operator< (const mypair &B) const
    {
        return (r == B.r) ? (l < B.l) : (r < B.r);
    }

    void print()
    {
        printf ("%d %d\n", r, l);
    }
};

mypair solution[WORD_COUNT];

struct bit
{
    long long int BIT;

    bit() { BIT = 0; }
    bit(long long int _BIT) { BIT = _BIT; }

    bool bit_at(long long int index)
    {
        return BIT & (1<<index);
    }

    void turn_on(long long int index)
    {
        if (!bit_at(index))
            BIT += (1<<index);
    }

    void turn_off(long long int index)
    {
        if (bit_at(index))
            BIT += (1<<index);
    }

    void flip(long long int index)
    {
        if (bit_at(index))
            turn_off(index);
        else
            turn_on(index);
    }
};

struct trie
{
    struct node
    {
        bit bits;
        bool word;
        node *next[29];
        long long int index, depth, length, r_count;

        node() { word = false; bits = bit(); index = -1; }

        void add(char c)
        {
            if (!bits.bit_at(c - 'a'))
            {
                bits.turn_on(c - 'a');
                next[c - 'a'] = new node();
            }
        }
    };

    node *root;

    trie()
    {
        root = new node();
    }

    long long int parse_input()
    {
        node *current_node = root;
        char c;
        long long int len = 0, r = 0;

        while (isalpha(c = getchar()))
        {
            len++;
            c = tolower(c);
            r += (c == 'R' || c == 'r');
            current_node->add(c);
            current_node = current_node->next [c - 'a'];
        }

        if (!current_node->word)
        {
            current_node->word = true;
            current_node->index = word_count;
            current_node->length = len;
            current_node->r_count = r;

            r_count [current_node->index] = r;
            lengths [current_node->index] = len;

            word_count++;

            return current_node->index;
        }
        else
        {
            r_count [current_node->index] = current_node->r_count;
            lengths [current_node->index] = current_node->length;

            return current_node->index;
        }
    }
};

trie _trie;

void dfs1(long long int current_node)
{
    if (visited[current_node])
        return;

    visited [current_node] = DFS_BLACK;

    for (long long int i = 0; i < graph[current_node].size(); i++)
        if (!visited [graph[current_node] [i]])
            dfs1(graph [current_node] [i]);

    order.push_back(current_node);
}

long long int current_component, component_index[WORD_COUNT];

void dfs2(long long int current_node)
{
    mypair mp = mypair(r_count [current_node], lengths [current_node]);

    visited [current_node] = DFS_BLACK;
    component_index[current_node] = current_component;

    if (!(solution [current_component] < mp))
        solution [current_component] = mp;

    for (long long int i = 0; i < rev_graph [current_node].size(); i++)
        if (!visited [rev_graph [current_node] [i]])
            dfs2(rev_graph [current_node] [i]);
}

mypair dfs3(long long int current_node)
{
    visited [current_node] = DFS_BLACK;

    mypair mp = mypair(WORD_COUNT + 5, WORD_COUNT + 5), candidate;

    for (long long int i = 0; i < graph [current_node].size(); i++)
    {
        if (!visited [graph [current_node] [i]])
        {
            candidate = dfs3(graph [current_node] [i]);

            if (candidate < mp)
                mp = candidate;
        }
        else
        {
            candidate = solution [component_index [graph [current_node] [i]]];
            if (candidate < mp)
                mp = candidate;
        }
    }

    visited [current_node] = DFS_BLACK;

    if (solution[component_index [current_node]] < mp)
        mp = solution[component_index [current_node]];
    else
        solution [component_index [current_node]] = mp;

    return mp;
}

int main()
{
    scanf ("%I64d", &n); getchar();

    for (long long int i = 0; i < WORD_COUNT; i++)
        solution [i] = mypair(WORD_COUNT + 5, WORD_COUNT + 5);

    for (long long int i = 0; i < n; i++)
        words.push_back (_trie.parse_input());

    scanf ("%I64d", &m); getchar();
    for (long long int i = 0; i < m; i++)
    {
        long long int X = _trie.parse_input();
        long long int Y = _trie.parse_input();

        graph [X].push_back(Y);
        rev_graph[Y].push_back(X);

        edges.push_back(make_pair(X, Y));
    }

    for (long long int i = 0; i < word_count; i++)
        if (!visited [i])
            dfs1(i);

    memset(visited, DFS_WHITE, sizeof visited);

    for (long long int i = order.size() - 1; i > -1; i--)
    {
        if (!visited [order [i]])
        {
            current_component = i;
            dfs2(order [i]);
        }
    }
    memset(visited, DFS_WHITE, sizeof visited);

    for (long long int i = 0; i < word_count; i++)
        if (visited [i] == DFS_WHITE)
            dfs3(i);

    long long int solution_r = 0, solution_l = 0;

    for (long long int i = 0; i < words.size(); i++)
    {
        solution_r += solution [component_index [words [i]]].r;
        solution_l += solution [component_index [words [i]]].l;
    }

    printf ("%I64d %I64d\n", solution_r, solution_l);

    return 0;
}
/*
5
aa bb cc ee ff
5
aa a
bb aa
cc bb
ee cc
ff bb

*/




//19:00
