#ifndef SYMMETRIC_H
#define SYMMETRIC_H

#include "params.h"
#include "fips202.h"

typedef struct {
  uint64_t s[25];
} keccak_state;

void PQCLEAN_KYBER768_CLEAN_kyber_shake128_absorb(keccak_state *s, const unsigned char *input, unsigned char x, unsigned char y);
void PQCLEAN_KYBER768_CLEAN_kyber_shake128_squeezeblocks(unsigned char *output, unsigned long long nblocks, keccak_state *s);
void PQCLEAN_KYBER768_CLEAN_shake256_prf(unsigned char *output, unsigned long long outlen, const unsigned char *key, const unsigned char nonce);

#define hash_h(OUT, IN, INBYTES) sha3_256(OUT, IN, INBYTES)
#define hash_g(OUT, IN, INBYTES) sha3_512(OUT, IN, INBYTES)
#define xof_absorb(STATE, IN, X, Y) PQCLEAN_KYBER768_CLEAN_kyber_shake128_absorb(STATE, IN, X, Y)
#define xof_squeezeblocks(OUT, OUTBLOCKS, STATE) PQCLEAN_KYBER768_CLEAN_kyber_shake128_squeezeblocks(OUT, OUTBLOCKS, STATE)
#define prf(OUT, OUTBYTES, KEY, NONCE) PQCLEAN_KYBER768_CLEAN_shake256_prf(OUT, OUTBYTES, KEY, NONCE)
#define kdf(OUT, IN, INBYTES) shake256(OUT, KYBER_SSBYTES, IN, INBYTES)

#define XOF_BLOCKBYTES 168

typedef keccak_state xof_state;

#endif /* SYMMETRIC_H */