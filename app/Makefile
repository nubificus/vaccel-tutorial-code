# Makefile for vaccel exec helper tutorial
#
CC=gcc
LD=gcc 
CFLAGS=-Wall
VACCEL_CFLAGS=-I../vaccelrt/src/include -I../vaccelrt/third-party/slog/src
VACCEL_LDFLAGS=-L../vaccelrt/build/src -lvaccel -ldl
VADD_LDFLAGS=-L${PWD}/opencl_examples/build/vector_add -lvector_add
OCL_LDFLAGS=-L/usr/lib/x86_64-linux-gnu/ -lOpenCL


all: wrapper wrapper-args wrapper-vaccel wrapper-args-vaccel

wrapper: wrapper.c
	@$(CC) $< -o $@ ${CFLAGS} ${VADD_LDFLAGS} ${OCL_LDFLAGS}

wrapper-args: wrapper-args.c
	@$(CC) $< -o $@ ${CFLAGS} ${VADD_LDFLAGS} ${OCL_LDFLAGS}

libwrapper.so: wrapper_exec.c
	@$(CC) $< -o $@ ${CFLAGS} ${VACCEL_LDFLAGS} ${VACCEL_CFLAGS} -fPIC -shared

libwrapper-args.so: wrapper_exec-args.c
	@$(CC) $< -o $@ ${CFLAGS} ${VACCEL_LDFLAGS} ${VACCEL_CFLAGS} -fPIC -shared -g

wrapper-vaccel: wrapper.c libwrapper.so
	@$(CC) $< -o $@ ${CFLAGS} ${VACCEL_LDFLAGS} ${VACCEL_CFLAGS} -lwrapper -L .

wrapper-args-vaccel: wrapper-args.c libwrapper-args.so
	@$(CC) $< -o $@ ${CFLAGS} ${VACCEL_LDFLAGS} ${VACCEL_CFLAGS} -lwrapper-args -L . -g

clean:
	-rm -f wrapper-args wrapper libwrapper*.so wrapper-vaccel wrapper-args-vaccel
