CC=gcc
CFLAGS=-mfloat-abi=hard
NEON_FLAGS=-mfpu=neon -mcpu=cortex-a72

neon: neon.c
	$(CC) $< -o $@ $(CFLAGS) $(NEON_FLAGS)

scalar: scalar.c
	$(CC) $< -o $@ $(CFLAGS)

clean:
	rm -f neon scalar *.o *~

.PHONY: clean
