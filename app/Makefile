# Makefile for vaccel genop helper tutorial
#
CFLAGS=-Wall
VACCEL_CFLAGS=-I../vaccelrt/src
VACCEL_LDFLAGS=-L../vaccelrt/build/src -lvaccel -ldl
VADD_LDFLAGS=-L${PWD}/opencl_examples/build/vector_add -lvector_add
OCL_LDFLAGS=-L/usr/lib/x86_64-linux-gnu/ -lOpenCL

CC	=	gcc
LD	=	gcc 

#all: wrapper wrapper-args

wrapper: wrapper.c
	$(CC) $< -o $@ ${CFLAGS} ${VADD_LDFLAGS} ${OCL_LDFLAGS}

wrapper-args: wrapper-args.c
	$(CC) $< -o $@ ${CFLAGS} ${VADD_LDFLAGS} ${OCL_LDFLAGS}

libwrapper.so: wrapper_genop.c
	$(CC) $< -o $@ ${CFLAGS} ${VACCEL_LDFLAGS} ${VACCEL_CFLAGS} -fPIC -shared

libwrapper-args.so: wrapper_genop-args.c
	$(CC) $< -o $@ ${CFLAGS} ${VACCEL_LDFLAGS} ${VACCEL_CFLAGS} -fPIC -shared

wrapper-vaccel: wrapper.c
	$(CC) $< -o $@ ${CFLAGS} ${VACCEL_LDFLAGS} ${VACCEL_CFLAGS} -lwrapper -L .

wrapper-args-vaccel: wrapper-args.c
	$(CC) $< -o $@ ${CFLAGS} ${VACCEL_LDFLAGS} ${VACCEL_CFLAGS} -lwrapper-args -L .

clean:
	rm -f wrapper-args wrapper libwrapper*.so wrapper-vaccel wrapper-args-vaccel
