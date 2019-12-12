.SUFFIXES:.o .cpp

vpath %.h ./include
vpath %.cpp ./src

CFLAG = -g -std=c++11 
MYSQL = `mysql_config --cflags --libs`
CLIB = -lhiredis ./lib/libjson_linux-gcc-5.4.0_libmt.so -L./lib -lssl -lcrypto
CXX := g++ 
INCLUDEDIR = -I./include 
TARGET = ./target/test
OBJ = Cmysql.o main.o Credis.o Cjson.o CMD5.o CBase64.o Catomic.o CEpoll.o CMysqlPool.o


$(TARGET):$(OBJ)
	$(CXX)  $(CFLAG) $(INCLUDEDIR) -o  $@ $^ $(MYSQL) $(CLIB)

.cpp.o:
	$(CXX) $(CFLAG)  $(INCLUDEDIR) -c $^ $(MYSQL) $(CLIB)

clean:
	rm -f $(OBJ) $(TARGET)
