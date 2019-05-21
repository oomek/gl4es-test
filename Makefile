CC = g++
INCPATH = include
OBJS = test.o include/screen.o include/shader.o include/texture.o
SOURCE = test.cpp include/screen.cpp include/shader.cpp include/texture.cpp
OUT = test

INCLUDES = -I/opt/vc/include

LDPATH = -L/opt/vc/lib

LIBS = -lbrcmGLESv2 \
       -lbrcmEGL \
       -lbcm_host

all: test

test: $(OBJS)
	$(CC) $(INCLUDES) $(LDPATH) -o $@ $^ $(LIBS)

%.o: %.cpp
	$(CC) $(INCLUDES) -c -o $@ $<

clean:
	rm -f $(INCPATH)/*.o $(OUT) $(OUT).o
