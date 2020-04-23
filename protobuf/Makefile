CPPFLAGS=-std=c++17
TARGET=write read

all: $(TARGET)

clean:
	rm -f addressbook.pb.h addressbook.pb.cc $(TARGET) *.o *~

write: addressbook.pb.o write.o
	$(LINK.cc) -o $@ $^ /usr/local/lib/libprotobuf.a

read: addressbook.pb.o read.o
	$(LINK.cc) -o $@ $^ /usr/local/lib/libprotobuf.a

addressbook.pb.h: addressbook.proto
	protoc -I=. --cpp_out=. ./addressbook.proto

addressbook.pb.cc: addressbook.proto
	protoc -I=. --cpp_out=. ./addressbook.proto
