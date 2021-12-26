CFLAGS = -c -std=c++17 -g -I./reddy/ -Wall
LDFLAGS = -g ${shell pkg-config --libs sfml-graphics sfml-audio sfml-network sfml-window sfml-system}

SRC = ${wildcard reddy/*.cpp}
SRC += ${wildcard reddy/states/*.cpp}

HDR = ${wildcard reddy/*.hpp}
HDR += ${wildcard reddy/states/*.hpp}

OBJ = ${SRC:.cpp=.o}
EXEC = a.out

.PHONY: debug release clear clean

all: ${OBJ} ${EXEC} ${HDR}

debug: CFLAGS += -DDEBUG -O0
debug: all

release: CFLAGS += -O3
release: all

${EXEC}: ${OBJ}
	@g++ $^ -o $@ ${LDFLAGS}
	$(info [  LINKER  ] Linking finished.)

%.o: %.cpp
	@g++ ${CFLAGS} $^ -o $@
	$(info [ COMPILER ] $^)

clear: clean
clean:
	@rm -rf ${OBJ} ${EXEC}
	$(info [  REMOVE  ] Removed object files and executable (if available).)