**File compressor based on bzip2**

Default block size: 900000 bytes

**Compression steps:**

1. Burrows-Wheeler Transform

2. Move-to-front

3. Haffman

4. Run-Length Encoding

5. Head block and concatenation of blocks

**Restore steps:**

1. Get blocks of data

2. Haffman restore

3. Run-Length decoding

4. Move-to-Front restore

5. Burrows-Wheeler Transform restore

