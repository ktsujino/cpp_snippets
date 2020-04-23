CPPFLAGS=-std=c++17
TARGET=bind decltype forward infer

all: $(TARGET)

bind.o: type_name.h
decltype.o: type_name.h
forward.o: type_name.h
infer.o: type_name.h

bind: bind.o
	$(LINK.cc) -o $@ $^

decltype: decltype.o
	$(LINK.cc) -o $@ $^

forward: forward.o
	$(LINK.cc) -o $@ $^

infer: infer.o
	$(LINK.cc) -o $@ $^

clean:
	rm -f $(TARGET) *~ *.o
