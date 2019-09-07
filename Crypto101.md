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

  * DES is no longer secure mainly due to its tiny key size of 56 bits
  * The DES algorithm actually takes a 64 bit key input, but the remaining 8 bits are only used for parity checking, and are discarded immediately
  * on modern hardware, DES can be brute forced in less than a day.
  * 3DES: input is first encrypted, then decrypted, then encrypted again
    * $C = E_{DES}(k_1, D_{DES}(k_2, E_{DES}(k_3, p)))$
    * The three keys could all be chosen independently (168 key bits), or $k_3 = k_1$ (112 bits), or $k_1 = k_2 = k_3$, which is just plain old DES---for backwards compatibility
  * Use AES instead of 3DES, more secure, and much faster

* Remaining problems

  * we can only send messages of a very limited length: the block length of the block cipher
  * we'd like to be able to send much larger messages, or, ideally, streams of indeterminate size. --- addressed with a **stream cipher**
  * though key size has been reduced, it still needs a way to be shared and agreed on, potentially over an insecure channel. --- addressed with a **key exchange protocol**

## CHAPTER 7. Stream ciphers

* a symmetric-key encryption algorithm that **encrypts a stream of bits**, as long as we like.

* A naive attempt with block ciphers: **ECB**(Electronic Code Book)
  
  * Visual inspection of an encrypted stream
    * simulate block ciphers of various block sizes and apply it to an image --- to visually inspect the problem
    * AES is the workhorse of modern block ciphers ---- it can't be at fault, certainly **not because of an insufficient block size**
    * with an idealized encryption, the picture would look like **random noise**
  * Encryption oracle attack
    * oracle: $C=ECB(E_k, A||S)$
    * one bit at a time
  
* many ways that **block ciphers** can be used to **construct stream ciphers**

* CBC(cipher block chaining) mode:

  * plaintext blocks are XORed with the previous ciphertext block before being encrypted by the block cipher.

  * pick an **initialization vector (IV)** to XOR with the first plaintext block

  * IV will be cryptographically random, typically just added to ciphertext messages.

  * it's important to remember that an attacker must not be able to predict ahead of time what a give IV will be. ---- **an attack on predictable CBC IVs**

    * > While CBC mode itself is not inherently insecure, its paticular use in TLS 1.0 was. This eventually led to the **Browser Exploit Against SSL/TLS (BEAST)** attack

  * **Attacks on CBC mode with predictable IVs**

  * **Attacks on CBC mode with the key as the IV**

  * **CBC bit flipping attacks**

  * Padding

  * **CBC padding attacks**

  * Native stream ciphers

  * RC4

  * Salsa20

  * Native stream ciphers versus modes of operation

* CTR mode (counter mode)



