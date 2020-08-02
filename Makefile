CC=gcc
CFLAGS=

neon: neon.c
	$(CC) $< -o $@ $(CFLAGS)

clean:
	rm -f neon *.o *~

.PHONY: clean
