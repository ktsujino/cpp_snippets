CPPFLAGS=-std=c++17
TARGET=infer forward

all: $(TARGET)

infer: infer.o
	$(LINK.cc) -o $@ $^

forward: forward.o
	$(LINK.cc) -o $@ $^

clean:
	rm -f $(TARGET) *~ *.o
