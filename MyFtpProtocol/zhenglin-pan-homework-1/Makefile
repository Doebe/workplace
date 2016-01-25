all:	tcpclient tcpserver

tcpclient: tcpclient.c
	gcc $< -o $@

tcpserver: tcpserver.c
	gcc $< -o $@

clean:
	rm -f tcpclient tcpserver *.o *~ core *.txt