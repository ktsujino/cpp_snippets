CPPFLAGS=-std=c++17
TARGET=test

all: $(TARGET)

test: test.o
	$(LINK.cc) -o $@ $^ /usr/local/lib/libgflags.dylib

clean:
	rm -f $(TARGET) *.o *~
