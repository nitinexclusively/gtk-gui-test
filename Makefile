CC=gcc
CFLAGS=-I.
INC=-L.
DEPS = Errordialog.h
OBJ = Errordialog.o 

%.o: %.c $(DEPS)
		$(CC) -c `pkg-config --cflags gtk+-3.0` -o $@ $< $(CFLAGS) `pkg-config --libs gtk+-3.0`

test_gui: $(OBJ)
		$(CC) `pkg-config --cflags gtk+-3.0` -o $@ $^ $(CFLAGS) $(INC) -Wl,--no-as-needed -ldl -lpthread `pkg-config --libs gtk+-3.0`

clean:
		rm $(OBJ)
