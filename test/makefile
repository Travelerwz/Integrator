.SUFFIXES:.o .cpp
vpath %.h ../include
vpath %.cpp ../src

CXX = g++ -g -std=c++11 -w
LIB = ../lib/liblog4cplus.so
INCLUDEDIR = -I../include 
TARGET = test

OBJ = test_log4cpp.cpp CMyLogger.cpp

$(TARGET):$(OBJ)
	$(CXX) $(INCLUDEDIR) -o $@ $^ $(LIB)

clean:
	-rm -f $(TARGET)

