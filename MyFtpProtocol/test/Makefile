all:	peer tracker

peer: Peer.c
	gcc $< -o $@ -pthread

tracker: Tracker.c
	gcc $< -o $@ -pthread

clean:
	rm -f peer tracker *.o *~ core *.txt
