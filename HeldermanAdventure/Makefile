CFLAGS=-g -Wall -std=c99
RFLAGS=rm -rf *.o
cfiles = object.c reach.c openclose.c toggle.c parsexec.c location.c noun.c misc.c match.c move.c inventory.c inventory2.c main.c 
hfiles = object.h reach.h openclose.h toggle.h parsexec.h location.h noun.h misc.h match.h move.h inventory.h inventory2.h
txtpath = txt_files
awkpath = awk_files
dotpath = dot_files
imgpath = images

all: main map.png
main: $(cfiles) $(hfiles)
	cc $(CFLAGS) $(cfiles) -o $@
object.h: $(awkpath)/object.awk $(txtpath)/object.txt
	awk -v pass=h -v RS='\r\n' -f $(awkpath)/object.awk $(txtpath)/object.txt > $@
object.c: $(awkpath)/object.awk $(txtpath)/object.txt
	awk -v pass=c1 -v RS='\r\n' -f $(awkpath)/object.awk $(txtpath)/object.txt > $@
	awk -v pass=c2 -v RS='\r\n' -f $(awkpath)/object.awk $(txtpath)/object.txt >> $@
map.png: map.gv
	dot -Tpng -o $(imgpath)/map.png $(dotpath)/$<
map.gv: $(awkpath)/map.awk $(txtpath)/object.txt
	awk -v RS='\r\n' -f $(awkpath)/map.awk $(txtpath)/object.txt > $(dotpath)/$@
clean:
	$(RFLAGS) main object.c object.h $(imgpath)/map.png $(dotpath)/map.gv