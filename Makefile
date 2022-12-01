CXX = g++
CXXFLAGS = -g -Wall

OBJECTS1 = sud2sat.o
EXEC1 = sud2sat

OBJECTS2 = sat2sud.o
EXEC2 = sat2sud

OBJECTS = ${OBJECTS1} ${OBJECTS2}
DEPENDS = ${OBJECTS:.o=.d}
EXECS = ${EXEC1} ${EXEC2}

############################################################

.PHONY : all clean

all: ${EXECS}

${EXEC1} : ${OBJECTS1}
	${CXX} ${CXXFLAGS} $^ -o $@

${EXEC2} : ${OBJECTS2}
	${CXX} ${CXXFLAGS} $^ -o $@

-include ${DEPENDS}

clean :
	rm -f *.d *.o ${EXECS}
