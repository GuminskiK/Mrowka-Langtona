CC := gcc
CFLAGS := -ggdb
BIN_DIR := bin

all: ${BIN_DIR}/mrowka

${BIN_DIR}/mrowka: ./*.c ./*.h
	mkdir -p bin
	${CC} ${CFLAGS} $^ -o $@

clean:
	rm -f ./*.o
	rm -f ./*.gch
	rm -rf ./bin