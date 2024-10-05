#ifndef __BIT_OPS_H_
#define __BIT_OPS_H_

/*
 * Bitwise and integer operations in C
 */

/*
 * Extract a bitfield
 */
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
extern uint64_t extract_bits( uint64_t word, size_t first, size_t size );

/*
 * Determine if any odd-numbered bit is set
 */
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
extern int odd_bit_set( uint32_t word );

/*
 * Count the bits set in a word
 */
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
extern size_t count_bits( int64_t word );

/*
 * 32-bit add with carry
 */
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
extern uint32_t add32_carry( uint32_t a, uint32_t b, int * carry );

/*
 * Bitwise left rotate
 */
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
extern uint64_t rotate_left( uint64_t word, size_t count );

#endif // __BIT_OPS_H_
