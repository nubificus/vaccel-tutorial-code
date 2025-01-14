# Makefile for vaccel exec helper tutorial
#
CC=gcc
LD=gcc 
CFLAGS=-Wall
VACCEL_INSTALL_PATH=/  #Add here the <path> of vaccel meson setup --prefix option 
VACCEL_CFLAGS=-I${VACCEL_INSTALL_PATH}/include 
VACCEL_LDFLAGS=-L${VACCEL_INSTALL_PATH}/lib/x86_64-linux-gnu -lvaccel -ldl
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
