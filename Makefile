CFLAGS = -c -std=c++17 -g
LDFLAGS = -g -I./src ${shell pkg-config --libs sfml-graphics sfml-audio sfml-network sfml-window sfml-system}

SRC = ${wildcard src/*.cpp}
# add more headers here with SRC += ${wildcard path/to/somewhere/*.cpp}

HDR = ${wildcard src/*.hpp}
# add more headers here with HDR += ${wildcard path/to/somewhere/*.hpp}

OBJ = ${SRC:.cpp=.o}
EXEC = reddy

all: folders ${OBJ} ${EXEC} ${HDR}

folders:
	@mkdir -p build/
	@mkdir -p build/objs/

debug: CFLAGS += -DDEBUG -O0
debug: all

release: CFLAGS += -O3
release: all

${EXEC}: ${OBJ}
	@g++ ${addprefix build/objs/,${notdir $^}} -o build/$@ ${LDFLAGS}
	$(info [  LINKER  ] Linking finished.)

%.o: %.cpp
	@g++ ${CFLAGS} $^ -o ${addprefix build/objs/,${notdir $@}}
	$(info [ COMPILER ] $^)

clear: clean
clean:
	@rm -rf build/ ${EXEC}
	$(info [  REMOVE  ] Removed object files and executable (if available).)