CC=gcc
CFLAGS=-Wall -Werror -g -lrt -lpthread

PROG=eco
SHM_DIR=shm
SHM_EJ=shm_create shm_read shm_unlink shm_write
MQ_DIR=mq
MQ_EJ=mq_open mq_getattr mq_send mq_receive mq_unlink

BINARIES=$(PROG) $(addprefix $(SHM_DIR)/, $(SHM_EJ)) $(addprefix $(MQ_DIR)/, $(MQ_EJ)) $(addprefix $(SEM_DIR)/, $(SEM_EJ))

.PHONY: all
all: $(PROG) shm mq sem

.PHONY: shm
shm: $(addprefix $(SHM_DIR)/, $(SHM_EJ))

.PHONY: mq
mq: $(addprefix $(MQ_DIR)/, $(MQ_EJ))

#$(BIN)/%: %.c
#	$(CC) -o $@ $< $(CFLAGS)

%: %.c
	$(CC) -o $@ $< $(CFLAGS)

html: README.md
	pandoc README.md -f markdown_github -t html -s -o README.html

pdf: README.md
	pandoc README.md -f markdown_github -s -o README.pdf

.PHONY: clean
clean:
	rm -f $(BINARIES)

