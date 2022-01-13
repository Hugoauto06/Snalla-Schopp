SRC_PATH=./src
OUT_PATH=./bin
OBJ_PATH=${OUT_PATH}/obj
VPATH=${SRC_PATH}

BINARIES=game.exe
FILES=Main.cpp Math.cpp RenderWindow.cpp Player.cpp Entity.cpp
OBJS=$(FILES:%.cpp=$(OBJ_PATH)/%.o)

CC=g++
CLIBRARIES=-lSDL2 -lSDL2_image
CFLAGS=-Wall -Wextra -pedantic

all: ${OUT_PATH} ${BINARIES}

${BINARIES}: ${OBJS}
	@echo Making binary output
	@${CC} ${CFLAGS} $^ ${CLIBRARIES} -o ${OUT_PATH}/$@

${OBJ_PATH}/%.o: %.cpp
	@${CC} -c $< -o $@ ${CFLAGS} -I${SRC_PATH}

${OUT_PATH}:
	mkdir -p ${OBJ_PATH}
