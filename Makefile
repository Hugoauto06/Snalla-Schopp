SRC_PATH=./src
OUT_PATH=./bin
OBJ_PATH=./obj
VPATH=${SRC_PATH}


RESOURCES=res/
SOURCES=Main.cpp Math.cpp RenderWindow.cpp Player.cpp Entity.cpp

CLIBS=-lSDL2 -lSDL2_image
CFLAGS=-Wall -Wextra -pedantic
CINCLUDE=\
		 -I./src/ \
		 -I./src/res \
		 -I./src/res/img \
		 -I./src/include

default: linux

#LINUX DEFINES
LNX_PLATFORM=linux
BINARIES=game
OBJS=$(SOURCES:%.cpp=$(OBJ_PATH)/$(LNX_PLATFORM)/%.o)
CC=g++

linux: ${OUT_PATH}/${LNX_PLATFORM} ${OBJ_PATH}/${LNX_PLATFORM} ${BINARIES} ${OUT_PATH}/${LNX_PLATFORM}/${RESOURCES}

${BINARIES}: ${OBJS}
	@echo Making binary output
	${CC} ${CFLAGS} $^ ${CLIBS} -o ${OUT_PATH}/${LNX_PLATFORM}/$@

${OBJ_PATH}/${LNX_PLATFORM}/%.o: %.cpp
	@${CC} -c $< -o $@ ${CFLAGS} ${CINCLUDE}

${OUT_PATH}/${LNX_PLATFORM}:
	mkdir -p ${OUT_PATH}/${LNX_PLATFORM}

${OBJ_PATH}/${LNX_PLATFORM}:
	mkdir -p ${OBJ_PATH}/${LNX_PLATFORM}

${OUT_PATH}/${LNX_PLATFORM}/${RESOURCES}:
	cp -r ${SRC_PATH}/${RESOURCES} ${OUT_PATH}/${LNX_PLATFORM}


#WINDOWS DEFINES
WIN_PLATFORM=win-x86
DLLS_PATH=/usr/x86_64-w64-mingw32/bin

BINARIES-WIN=game.exe

OBJS-WIN=$(SOURCES:%.cpp=$(OBJ_PATH)/$(WIN_PLATFORM)/%.o)
LIBRARIES=SDL2 SDL2_image zlib libjpeg libpng libtiff libwebp
DLLS-WIN=$(LIBRARIES:%=$(OUT_PATH)/$(WIN_PLATFORM)/%)

CC-WIN=x86_64-w64-mingw32-g++
WLIBS=-lmingw32 -lSDL2main

win-x86: ${OUT_PATH}/${WIN_PLATFORM} ${OBJ_PATH}/${WIN_PLATFORM} ${BINARIES-WIN} ${DLLS-WIN} ${OUT_PATH}/${WIN_PLATFORM}/${RESOURCES}

${BINARIES-WIN}: ${OBJS-WIN}
	@echo Making binary output
	${CC-WIN} ${CFLAGS} ${WLIBS} $^ ${CLIBS} -o ${OUT_PATH}/${WIN_PLATFORM}/$@
	
${OBJ_PATH}/${WIN_PLATFORM}/%.o: %.cpp
	@${CC-WIN} -c $< -o $@ ${CFLAGS} ${CINCLUDE}

${OUT_PATH}/${WIN_PLATFORM}/%: ${DLLS_PATH}/%*
	@cp $< ${OUT_PATH}/${WIN_PLATFORM}
	@echo Copied $($<:%/=$%)

${OUT_PATH}/${WIN_PLATFORM}:
	mkdir -p ${OUT_PATH}/${WIN_PLATFORM}

${OBJ_PATH}/${WIN_PLATFORM}:
	mkdir -p ${OBJ_PATH}/${WIN_PLATFORM}

${OUT_PATH}/${WIN_PLATFORM}/${RESOURCES}:
	cp -r ${SRC_PATH}/${RESOURCES} ${OUT_PATH}/${WIN_PLATFORM}
