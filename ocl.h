#ifndef __OCL_H__
#define __OCL_H__

#include "config.h"

#include <stdbool.h>
#ifdef __APPLE_CC__
#include <OpenCL/opencl.h>
#else
#include <CL/cl.h>
#endif

#include "miner.h"

#ifdef USE_CPU_OPENCL
#define CL_DEVICE_TYPE_ CL_DEVICE_TYPE_ALL
#else
#define CL_DEVICE_TYPE_ CL_DEVICE_TYPE_GPU
#endif

typedef struct {
	cl_context context;
	cl_kernel kernels[20];
	size_t numkernels;
	cl_command_queue commandQueue;
	cl_program program;
	cl_mem outputBuffer;
	cl_mem CLbuffer0;
	cl_mem padbuffer8;
	size_t padbufsize;
	cl_mem signbuffer;
	size_t signbufsize;
	cl_mem hwbbuffer;
	size_t hwbbufsize;
	unsigned char cldata[80];
	bool hasBitAlign;
	bool hasOpenCL11plus;
	bool hasOpenCL12plus;
	bool goffset;
	cl_uint vwidth;
	size_t max_work_size;
	size_t wsize;
	size_t compute_shaders;
	enum cl_kernels chosen_kernel;
} _clState;

extern char *file_contents(const char *filename, int *length);
extern int clDevicesNum(void);
extern _clState *initCl(unsigned int gpu, char *name, size_t nameSize);
#endif /* __OCL_H__ */
