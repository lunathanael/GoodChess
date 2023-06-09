#ifndef PERFT_H_INCLUDED
#define PERFT_H_INCLUDED


/* HEADERS */
#include "types.h"
#include "movegen.h"


/* DEFINITIONS */
long long p_nodes;


/* MACROS */


/* FUNCTIONS */
static inline void perft_driver(int depth, BOARD*pos)
{
	if (depth == 0)
	{
		++p_nodes;
		return;
	}

	Moves_list list[1];
	generate_moves(list,pos);

	for (int move_count = 0; move_count < list->count; ++move_count)
	{
		copy_board(pos);
		if (!make_move(list->moves[move_count].move,pos))
		{
			continue;
		}
		perft_driver(depth - 1, pos);
		take_board(pos);
	}
}

static inline void perft_test(int depth, BOARD*pos)
{
    p_nodes = 0;
    printf("\n     Performance test\n\n");
    printf("\n     Move:    Nodes:\n");

    // create move list instance
    Moves_list move_list[1];

    // generate moves
    generate_moves(move_list, pos);

    // init start time
    long start = get_time_ms();

    // loop over generated moves
    for (int move_count = 0; move_count < move_list->count; move_count++)
    {
        // preserve board state
        copy_board(pos);

        // make move
        if (!make_move(move_list->moves[move_count].move, pos))
            // skip to the next move
            continue;

        // cummulative nodes
        long long cummulative_nodes = p_nodes;

        // call perft driver recursively
        perft_driver(depth - 1, pos);

        // old nodes
        long long old_nodes = p_nodes - cummulative_nodes;

        // take back
        take_board(pos);

        // print move
        printf("     %s    %lld\n", Pr_move(move_list->moves[move_count].move), old_nodes);
    }

    long time = get_time_ms() - start;
    // print results
    printf("\n    Depth: %d ply\n", depth);
    printf("    Nodes: %lld\n", p_nodes);
    printf("     Time: %ld ms\n", time);
    printf("      Nps: %dMN/s\n\n", (  (p_nodes / time) / 1000) );
}










#endif