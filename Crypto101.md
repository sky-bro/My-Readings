## CHAPTER 5. EXCLUSIVE OR

## CHAPTER 6. BLOCK CIPHERS

* A **Block Cipher** is an algorithm that allows us to encrypt blocks of fixed length

* plaintext and ciphertext blocks are always the same size as one another, and that size if fixed by the block cipher (called a block cipher's **block size**)

* a block cipher is a keyed-permutation (one-to-one)

* Real, modern block ciphers have much larger block sizes, such as 128 bits. There are n! different permutations of an n element set.

* Common key sizes are only in the range of 128 to 256 bits, so there are only between 2^128 and 2^256 permutations a cipher can perform. That's just tiny fraction of all possible permutations of the blocks, but that tiny fraction is stll nowhere near small enough for an attacker to just try them all.

* **AES**

  * Selected through a public, peer-reviewed competition following an open call for proposals
  * Prior to being chosen as the Advanced Encryption Standard, the algorithm was known as Rijndael (from two Belgian cryptographers/designers: Vincent Rijmen and Joan Daemen)
  * the Rijndael algorithm defined a family of block ciphers
    * block sizes and key sizes could be any multiple of 32 bits between 128 bits and 256 bits
    * after becoming AES, the parameters were restricted to a block size of 128 bits and keys sizes of 128, 192 and 256 bits
  * Attacks
    * no practical attacks but have some developments
    * most involve related-key attacks: odds of selecting two such related keys by accident is nonexistent
    * some of them only on reduced-round versions of AES

* Closer look at Rijndael (How it works)

  * at a high level, AES is a **substitution-permutation network**

  * **Key schedule**

    * AES requires separate keys for each round in the next steps
    * use key schedule to derive 128-bit keys for each round from one master key

    1. key is separated into 4 byte columns
    2. The key is rotated and then each byte is run through an S-box (substitution box) that maps it to something else.
    3. Each column is then XORed with a round constant.
    4. The last step is to XOR the result with the previous round key.
    5. The other columns ? are then XORed with the previous round key to produce the remaining columns

  * **SubBytes**

    * is the S-box in AES
    * resistant to linear attacks, unlike the earlier DES algorithm, whose fifth S-box caused serious security problems

  * **ShiftRows**

    * After having applied the SubBytes step to the 16 bytes of the block
    * AES shifts the rows in the 4*4 array

  * **MixColumns**

    * multiplies each column of the state with a fixed polynomial

  * **AddRoundKey**

    * adds the bytes from the round key produced by the key schedule to the state of the cipher

* DES and 3DES

* Remaining problems

## CHAPTER 5. EXCLUSIVE OR

