FILE1 = src/TCP_Server.c
PROG1 = build/TCP_Server

FILE2 = src/TCP_Client.c
PROG2 = build/TCP_Client

FILE3 = src/UDP_Server.c
PROG3 = build/UDP_Server

FILE4 = src/UDP_Client.c
PROG4 = build/UDP_Client

CC = gcc
CFLAGS = -Wall -O -o

${PROG1}: ${FILE1}
	${CC} ${CFLAGS} ${PROG1} ${FILE1}

${PROG2}: ${FILE2}
	${CC} ${CFLAGS} ${PROG2} ${FILE2}

${PROG3}: ${FILE3}
	${CC} ${CFLAGS} ${PROG3} ${FILE3}

${PROG4}: ${FILE4}
	${CC} ${CFLAGS} ${PROG4} ${FILE4}

tcpserver: ${PROG1}
	./${PROG1}

tcpclient: ${PROG2}
	./${PROG2}

udpserver: ${PROG3}
	./${PROG3}

udpclient: ${PROG4}
	./${PROG4}

clean: ${PROG}
	rm ${PROG}
