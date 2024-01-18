CC := gcc
CFLAGS := -ggdb
BIN_DIR := bin

all: ${BIN_DIR}/mrowka
clean_build: clean all

${BIN_DIR}/mrowka: ./*.c ./*.h
	mkdir -p ${BIN_DIR}
	${CC} ${CFLAGS} $^ -o $@

clean:
	rm -f ./*.o
	rm -f ./*.gch
	rm -rf ${BIN_DIR}

check: ${BIN_DIR}/mrowka
	./testuj.sh
.PHONY: clean test