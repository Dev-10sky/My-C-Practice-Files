
CFLAGS=-g -Wall -Wextra -Wpedantic -Werror
RFLAGS=rm -rf *.o
cfiles = object.c reach.c openclose.c toggle.c parsexec.c location.c noun.c misc.c damage.c turn.c match.c talk.c expand.c move.c inventory.c inventory2.c onoff.c attack.c social.c tcp.c client.c telnet.c print.c outbuf.c break.c server.c main.c 
hfiles = object.h reach.h openclose.h toggle.h parsexec.h location.h noun.h misc.h damage.h turn.h match.h talk.h expand.h move.h inventory.h inventory2.h onoff.h attack.h social.h tcp.h client.h telnet.h print.h outbuf.h break.h server.h
txtpath = txt_files
awkpath = awk_files
dotpath = dot_files
imgpath = images
testpath = testing
autopath = automation_outputs

all: main map.png
main: $(cfiles) $(hfiles)
	cc $(CFLAGS) $(cfiles) -o $@
object.h: $(awkpath)/object.awk $(txtpath)/object.txt
	awk -v pass=h -f $(awkpath)/object.awk $(txtpath)/object.txt > $@
#	awk -v pass=h -v RS='\r\n' -f $(awkpath)/object.awk $(txtpath)/object.txt > $@
object.c: $(awkpath)/object.awk $(txtpath)/object.txt
	awk -v pass=c1 -f $(awkpath)/object.awk $(txtpath)/object.txt > $@
	awk -v pass=c2 -f $(awkpath)/object.awk $(txtpath)/object.txt >> $@
#	awk -v pass=c1 -v RS='\r\n' -f $(awkpath)/object.awk $(txtpath)/object.txt > $@
#	awk -v pass=c2 -v RS='\r\n' -f $(awkpath)/object.awk $(txtpath)/object.txt >> $@
map.png: map.gv
	dot -Tpng -o $(imgpath)/map.png $(dotpath)/$<
map.gv: $(awkpath)/map.awk $(txtpath)/object.txt
	awk -v RS='\r\n' -f $(awkpath)/map.awk $(txtpath)/object.txt > $(dotpath)/$@
success.txt: main $(testpath)/testscript.txt $(autopath)/baseline.txt
	./main $(testpath)/testscript.txt > $(autopath)/transcript.txt
	cmp $(autopath)/baseline.txt $(autopath)/transcript.txt
	mv -f $(autopath)/transcript.txt $(autopath)/success.txt

clean:
	$(RFLAGS) main object.c object.h $(imgpath)/map.png $(dotpath)/map.gv
