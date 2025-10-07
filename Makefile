CC := gcc
CFLAGS := -c -Wall
LDFLAGS := -lm
SOURCES := main.c commands.c vecmath.c
OBJECTS := $(SOURCES:.c=.o)
EXECUTABLE := veclab
TEST_SOURCES := testSuite.c
TEST_OBJECTS := $(TEST_SOURCES:.c=.o)
TEST_EXECUTABLE := testSuite

all: $(SOURCES) $(EXECUTABLE)

tests: $(TEST_SOURCES) $(TEST_EXECUTABLE)

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE) $(TEST_OBJECTS) $(TEST_EXECUTABLE) *.d

# pull in dependency info for *existing* .o files
-include $(OBJECTS:.o=.d)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

$(TEST_EXECUTABLE): $(TEST_OBJECTS)
	$(CC) $(TEST_OBJECTS) -o $@

%.o : %.c
	$(CC) $(CFLAGS) $< -o $@
	$(CC) -MM $< > $*.d
