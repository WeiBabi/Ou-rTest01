cc =gcc
MAINC = moupuzi.c  ./sqlite3.c  sungtk_interface.c             
EXEC = moupuzi



CFLAGS = `pkg-config --cflags --libs gtk+-2.0 `  -lpthread -ldl -Wformat

main:
	$(cc) $(MAINC) -o $(EXEC) $(CFLAGS)
clean:
	rm $(EXEC)  my_fifo -rf






