// BFS  http://lingyibin.iteye.com/blog/801225  
// poj 1222 EXTENDED LIGHTS OUT 枚举第一行，然后下一行，保证上一行全转为 0 即可。。
// 本题因为要求最小值，用BFS合适
#include "assert.h"
#include <iostream>
#include <queue>
using namespace std;

const int MAX_STATE = 65536;
const int ALL_WHILE_STATE = 0;
const int ALL_BLACK_STATE = 65535;
const int WIDTH_OF_BOARD = 4;
const int SIZE_OF_BOARD = WIDTH_OF_BOARD * WIDTH_OF_BOARD; // 4 * 4

int ConvertPieceColorToInt(char color)
{
    switch(color)
    {
    case 'b':
        return 1;
    case 'w':
        return 0;
    }
}

int FlipPiece(int state_id, int position)
{
    state_id ^= (1 << position);

    // up
    if(position - 4 >= 0)
        state_id ^= (1 << (position - 4));
    // down
    if(position + 4 < SIZE_OF_BOARD)
        state_id ^= (1 << (position + 4));
    // left
    if(position % 4 != 0)
        state_id ^= (1 << (position - 1));
    // right
    if(position % 4 != 3)
        state_id ^= (1 << (position + 1));

    return state_id;
}

int main()
{
    int current_state_id = 0;
    int state[MAX_STATE];
    queue<int> search_queue;

    memset(state, -1, sizeof(state));

    char color;

    for(int i = 0; i < SIZE_OF_BOARD; ++i)
    {
        cin >> color;
        current_state_id += ConvertPieceColorToInt(color) << i;
    }

    if(current_state_id == ALL_WHILE_STATE
        || current_state_id == ALL_BLACK_STATE)
    {
        cout << "0" << endl;
        return 0;
    }

    state[current_state_id] = 0;
    search_queue.push(current_state_id);

    int next_state_id;

    while(!search_queue.empty())
    {
        current_state_id = search_queue.front();
        search_queue.pop();

        for(int i = 0; i < SIZE_OF_BOARD; ++i)
        {
            next_state_id = FlipPiece(current_state_id, i);
            if(next_state_id == ALL_WHILE_STATE
                || next_state_id == ALL_BLACK_STATE)
            {
                cout << state[current_state_id] + 1 << endl;
                return 0;
            }
            assert(next_state_id < MAX_STATE);
            if(state[next_state_id] == -1 /* not visited */)
            {
                state[next_state_id] = state[current_state_id] + 1;
                search_queue.push(next_state_id);
            }
        }
    }

    cout << "Impossible" << endl;
    return 0;
}

