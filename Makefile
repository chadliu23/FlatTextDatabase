CC=g++
CFLAGS=-c -Wall -pthread
LDFLAGS=
SOURCES=main.cpp FlatTextDatabase.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=FlatTextDatabase

all: $(SOURCES) $(EXECUTABLE) 
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE)
