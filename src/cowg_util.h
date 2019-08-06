/*
 * 
 * See COPYRIGHT notice in top-level directory.
 *
 */

#ifndef COWG_INCLUDE_H
#define COWG_INCLUDE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncptl/ncptl.h> 
#include <mpi.h> 

#define MAX_CONC_ARGV 128

typedef struct cowg_bench_param cowg_bench_param;

struct cowg_bench_param {
    char conc_program[MAX_CONC_ARGV];
    int conc_argc;
    char config_in[MAX_CONC_ARGV][MAX_CONC_ARGV];
    char *conc_argv[MAX_CONC_ARGV];
};

/* object structure */
struct cowg_conceptual_bench {
    char *program_name; /* name of the conceptual program */
    int (*conceptual_main)(int argc, char *argv[]);
};


void cowg_conc_add_bench(
        struct cowg_conceptual_bench const * method);


int cowg_conc_bench_load(
        const char* program,
        int argc, 
        char *argv[]);

void COWG_MPI_Comm_size (MPI_Comm comm, int *size);
void COWG_MPI_Comm_rank( MPI_Comm comm, int *rank );
void COWG_MPI_Finalize();
void COWG_Compute(long cycle_count);
void COWG_MPI_Send(const void *buf, 
            int count, 
            MPI_Datatype datatype, 
            int dest, 
            int tag,
            MPI_Comm comm);
void COWG_MPI_Recv(void *buf, 
            int count, 
            MPI_Datatype datatype, 
            int source, 
            int tag,
            MPI_Comm comm, 
            MPI_Status *status);
void COWG_MPI_Sendrecv(const void *sendbuf, 
            int sendcount, 
            MPI_Datatype sendtype,
            int dest, 
            int sendtag,
            void *recvbuf, 
            int recvcount, 
            MPI_Datatype recvtype,
            int source, 
            int recvtag,
            MPI_Comm comm, 
            MPI_Status *status);
void COWG_MPI_Barrier(MPI_Comm comm);
void COWG_MPI_Isend(const void *buf, 
            int count, 
            MPI_Datatype datatype, 
            int dest, 
            int tag,
            MPI_Comm comm, 
            MPI_Request *request);
void COWG_MPI_Irecv(void *buf, 
            int count, 
            MPI_Datatype datatype, 
            int source, 
            int tag,
            MPI_Comm comm, 
            MPI_Request *request);
void COWG_MPI_Wait(MPI_Request *request,
            MPI_Status *status);
void COWG_MPI_Waitall(int count, 
            MPI_Request array_of_requests[], 
            MPI_Status array_of_statuses[]);
void COWG_MPI_Reduce(const void *sendbuf, 
            void *recvbuf, 
            int count, 
            MPI_Datatype datatype,
            MPI_Op op, 
            int root, 
            MPI_Comm comm);
void COWG_MPI_Allreduce(const void *sendbuf, 
            void *recvbuf, 
            int count, 
            MPI_Datatype datatype,
            MPI_Op op, 
            MPI_Comm comm);
void COWG_MPI_Bcast(void *buffer, 
            int count, 
            MPI_Datatype datatype, 
            int root, 
            MPI_Comm comm);
void COWG_MPI_Alltoall(const void *sendbuf, 
            int sendcount, 
            MPI_Datatype sendtype, 
            void *recvbuf,
            int recvcount, 
            MPI_Datatype recvtype, 
            MPI_Comm comm);
void COWG_MPI_Alltoallv(const void *sendbuf, 
            const int *sendcounts, 
            const int *sdispls,
            MPI_Datatype sendtype, 
            void *recvbuf, 
            const int *recvcounts,
            const int *rdispls, 
            MPI_Datatype recvtype, 
            MPI_Comm comm);

#ifdef __cplusplus
}
#endif

#endif /* COWG_INCLUDE_H */
