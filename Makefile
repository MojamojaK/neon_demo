CC=gcc
CFLAGS=

neon: neon.c
	$(CC) $< -o $@ $(CFLAGS)
