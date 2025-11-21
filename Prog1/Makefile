.PHONY: all debug release clean
RELEASE_FLAGS = -O2 -Wall -DNDEBUG -std=c++11
DEBUG_FLAGS   = -g -O0 -Wall -std=c++11
RELEASE_EXEC  = modAlphaCipher
DEBUG_EXEC    = modAlphaCipher-dbg
SOURCES       = modAlphaCipher.cpp main.cpp
all: debug release
debug: $(DEBUG_EXEC)
$(DEBUG_EXEC): $(SOURCES)
	g++ $(DEBUG_FLAGS) $(SOURCES) -o $(DEBUG_EXEC)
release: $(RELEASE_EXEC)
$(RELEASE_EXEC): $(SOURCES)
	g++ $(RELEASE_FLAGS) $(SOURCES) -o $(RELEASE_EXEC)
clean:
	rm -f $(RELEASE_EXEC) $(DEBUG_EXEC)
