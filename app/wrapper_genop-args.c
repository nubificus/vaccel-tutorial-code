#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <vaccel.h>
#include <vaccel_ops.h>

struct vector_arg {
        size_t len;
        uint8_t *buf;
} __attribute__ ((packed));


int vaccel_vector_add(int *A, int *B, int *C, int dimension)
{

	int ret = 0;
	struct vector_arg op_args[6];
	struct vaccel_session sess;

        ret = vaccel_sess_init(&sess, 0);
        if (ret != VACCEL_OK) {
                fprintf(stderr, "Could not initialize session\n");
                return 1;
        }

        printf("Initialized session with id: %u\n", sess.session_id);

	char *operation = "vector-add";
	size_t oplen = strlen(operation);

        memset(op_args, 0, sizeof(op_args));

        op_args[0].len = oplen;
        op_args[0].buf = (uint8_t*)operation;
        op_args[1].len = dimension * sizeof(int);
        op_args[1].buf = (uint8_t*)A;
        op_args[2].len = dimension * sizeof(int);
        op_args[2].buf = (uint8_t*)B;
        op_args[3].len = sizeof(int);
        op_args[3].buf = (uint8_t*)&dimension;

        op_args[4].len = dimension * sizeof(int);
        op_args[4].buf = (uint8_t*)C;

        ret = vaccel_genop(&sess, &op_args[4], &op_args[0], 1, 4);
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
