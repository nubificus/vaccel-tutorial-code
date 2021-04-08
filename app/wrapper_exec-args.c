#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <vaccel.h>

int vaccel_vector_add(int *A, int *B, int *C, int dimension)
{

	int ret = 0;
	struct vaccel_arg op_args[6];
	struct vaccel_session sess;

        ret = vaccel_sess_init(&sess, 0);
        if (ret != VACCEL_OK) {
                fprintf(stderr, "Could not initialize session\n");
                return 1;
        }

        printf("Initialized session with id: %u\n", sess.session_id);

	char *library = "/tmp/libvector_add.so";
	char *operation = "vector_add";

        memset(op_args, 0, sizeof(op_args));
        op_args[0].size = dimension * sizeof(int);
        op_args[0].buf = (uint8_t*)A;
        op_args[1].size = dimension * sizeof(int);
        op_args[1].buf = (uint8_t*)B;
        op_args[2].size = sizeof(int);
        op_args[2].buf = (uint8_t*)&dimension;

        op_args[3].size = dimension * sizeof(int);
        op_args[3].buf = (uint8_t*)C;

        ret = vaccel_exec(&sess, library, operation, &op_args[0], 3, &op_args[3], 1);
	if (ret) {
		fprintf(stderr, "Could not run op: %d\n", ret);
		goto close_session;
	}

close_session:
        if (vaccel_sess_free(&sess) != VACCEL_OK) {
                fprintf(stderr, "Could not clear session\n");
                return 1;
        }

	return ret;
}

int vector_add(int *A, int *B, int *C, int dimension)
{
	return vaccel_vector_add(A,B,C,dimension);
}
