all: snd rcv

snd: gbnsender.c
	gcc -pthread $< -o $@

rcv: gbnreceiver.c
	gcc $< -o $@

clean:
	rm -f snd rcv *.o *~ core *.txt
