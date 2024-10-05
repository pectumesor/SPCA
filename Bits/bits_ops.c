/*
 * Answer the exam question by filling in the function bodies here.
 *
 * You can run your own tests (in custom_tests.c) by selecting "run".
 *
 * You can also run our open tests (if we have provided any in
 * open_tests.c) by selecting "test".
 */
#include <stdint.h>
#include <stddef.h>

#include "bit_ops.h"
#include <stdio.h>

/*
 * Extract a set of bits from a 64-bit word.
 *
 * Points: 2
 *
 * Arguments:
 * - word: the 64-bit word to extract a field from
 * - size: width of bit field (in bits)
 * - first: the least-significant bit to extract (starting at zero).
 *
 * Return value:
 * - the extracted bit field
 *
 */

uint64_t extract_bits( uint64_t word, size_t first, size_t size )
{
    uint64_t result = 0;

    // Fill your answer in here
    if (word == 0){
      return 0;
    }

    int size_mask = (~(1L << 63)) >> (63-size);

    result = (word >> first) & size_mask;

    return result;
}

/*
 * Determine if any odd-numbered bit in 'word' is set to 1.
 *
 * Points: 2
 *
 * Arguments:
 * - word: the number to be tested.
 *
 * Return value:
 * - true if and only if 'word' has an odd-numbered bit set.
 */
int odd_bit_set( uint32_t word )
{
    int result = 0;

    // Fill your answer in here
    int mask = 0x55555555;
    result = !!(mask & word);

    return result;
}

/*
 * Count the number of bits set in a word.
 *
 * Points: 3
 *
 * Arguments:
 * - word: the value to be tested.
 *
 * Return value:
 * - the number of '1' bits in the word
 */
size_t count_bits( int64_t word )
{
    size_t result = 0;

    // Fill your answer in here
    // Be careful: the argument is signed.  We need to shift logical.
    for (int i = 0; i<64;i++){
      result += (word >> i) & 1L;
    }
    return result;
}

/*
 * 32-bit unsigned add with carry
 *
 * Points: 3
 *
 * Arguments:
 * - a, b: Two 32-bit unsigned integers to be added.
 * - carry: the carry flag from a previous add, passed by reference.
 *
 * Return value:
 * - a + b + carry
 *
 * In addition, the carry flag is set to the new carry value.
 */
uint32_t add32_carry( uint32_t a, uint32_t b, int *carry )
{
    uint32_t result = 0;

    // Fill your answer in here
    // One easy way is to use 64 bits for the exact result.
    // result = a + b + (*carry);
    // if (result >= a && result >= b){
    //   *carry = 0;
    // }

    uint64_t tmp = a + b + (*carry);
    result = tmp;
    *carry = (result < a || result < b) ? 1 : 0;
    return result;
}

/*
 * 64-bit left rotate without carry
 *
 * Points: 3
 *
 * Arguments:
 * - word: a 64-bit number
 * - count: a number of bits to rotate by
 *
 * Return value:
 * - "word" rotated *left* by "count" bits.
 */
uint64_t rotate_left(uint64_t word, size_t count)
{
    uint64_t result = 0;

    // Fill your answer in here
    // Make it execute in reasonable time
    if (count == 0 || word == 0){
      return word;
    }
    count = count % 64;

    uint64_t mask_MSB = (1L << 63) >> (count-1);
    mask_MSB = (mask_MSB & word) >> (64-count);
    result = (word << count) | mask_MSB;

    return result;
}

