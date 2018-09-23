CXX = g++ -std=c++11
CXXFLAGS = 
LIB = 
TARGET = string_parse write_to_file read_from_file file_string_parse
SOURCE = $(wildcard ./lib_json/*.cpp)

all:$(TARGET)

$(TARGET):$(SOURCE)

.PHONY:clean
clean:
	find . -name "*.o" | xargs rm -rf
	find . -name "*~" | xargs rm -rf
	find . -name "*#" | xargs rm -rf
	rm -rf $(TARGET)

