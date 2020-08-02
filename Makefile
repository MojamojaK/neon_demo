CC=gcc
CFLAGS=
NEON_FLAGS=-mfpu=neon

neon: neon.c
	$(CC) $< -o $@ $(CFLAGS) $(NEON_FLAGS)

scalar: scalar.c
	$(CC) $< -o $@ $(CFLAGS)

clean:
	rm -f neon scalar *.o *~

.PHONY: clean
