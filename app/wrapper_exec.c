#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <vaccel.h>

int vaccel_vector_add()
{

	int ret = 0;
	struct vaccel_session sess;

        ret = vaccel_sess_init(&sess, 0);
        if (ret != VACCEL_OK) {
                fprintf(stderr, "Could not initialize session\n");
                return 1;
        }

        printf("Initialized session with id: %u\n", sess.session_id);

	char *library = "libvector_add.so";
	char *operation = "vector_add";

        ret = vaccel_exec(&sess, library, operation, NULL, 0, NULL, 0);
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

int vector_add()
{
	vaccel_vector_add();

	return 0;
}


