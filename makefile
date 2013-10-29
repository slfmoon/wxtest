
MINGW_BITS=x86_64
MINGW_DR=debug
MINGW_PREFIX=$(MINGW_BITS)-w64-mingw32
MINGW_CXXFLAGS=-static-libgcc -static-libstdc++
CXX=$(MINGW_PREFIX)-g++
CXXFLAGS=$(MINGW_CXXFLAGS) -O2
LD=$(MINGW_PREFIX)-ld
WXCONFIG=/usr/local/wxWidgets/static/$(MINGW_BITS)-$(MINGW_DR)/bin/wx-config
WXCPPFLAGS=`$(WXCONFIG) --cppflags`
WXLIBS=`$(WXCONFIG) --libs`

TARGET=HelloWorld
OBJECTS=Main.o HelloWorld.o

RM=rm

all : $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET) $(WXLIBS)

HelloWorld.o : HelloWorld.h
	$(CXX) $(CXXFLAGS) -c HelloWorld.cpp $(WXCPPFLAGS)

Main.o : HelloWorld.h
	$(CXX) $(CXXFLAGS) -c Main.cpp $(WXCPPFLAGS)

clean:
	$(RM) -f *.o $(TARGET).exe

