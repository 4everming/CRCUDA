#include <crcuda_server.h>

void* cuda_handle;

void load_cuda_lib(){

  cuda_handle = dlopen(CUDA_LIB_PATH,RTLD_LAZY);

  crcuda.crcudaDeviceReset= (cudaError_t (*)(void)) (cudaError_t*)dlsym(cuda_handle,"cudaDeviceReset");
  crcuda.crcudaDeviceSynchronize= (cudaError_t (*)(void)) (cudaError_t*)dlsym(cuda_handle,"cudaDeviceSynchronize");
  crcuda.crcudaDeviceSetLimit= (cudaError_t (*)(enum cudaLimit limit,  size_t value)) (cudaError_t*)dlsym(cuda_handle,"cudaDeviceSetLimit");
  crcuda.crcudaDeviceGetLimit= (cudaError_t (*)(size_t *pValue,  enum cudaLimit limit)) (cudaError_t*)dlsym(cuda_handle,"cudaDeviceGetLimit");
  crcuda.crcudaDeviceGetCacheConfig= (cudaError_t (*)(enum cudaFuncCache *pCacheConfig)) (cudaError_t*)dlsym(cuda_handle,"cudaDeviceGetCacheConfig");
  crcuda.crcudaDeviceSetCacheConfig= (cudaError_t (*)(enum cudaFuncCache cacheConfig)) (cudaError_t*)dlsym(cuda_handle,"cudaDeviceSetCacheConfig");
  crcuda.crcudaDeviceGetSharedMemConfig= (cudaError_t (*)(enum cudaSharedMemConfig *pConfig)) (cudaError_t*)dlsym(cuda_handle,"cudaDeviceGetSharedMemConfig");
  crcuda.crcudaDeviceSetSharedMemConfig= (cudaError_t (*)(enum cudaSharedMemConfig config)) (cudaError_t*)dlsym(cuda_handle,"cudaDeviceSetSharedMemConfig");
  crcuda.crcudaDeviceGetByPCIBusId= (cudaError_t (*)(int *device,  char *pciBusId)) (cudaError_t*)dlsym(cuda_handle,"cudaDeviceGetByPCIBusId");
  crcuda.crcudaDeviceGetPCIBusId= (cudaError_t (*)(char *pciBusId,  int len,  int device)) (cudaError_t*)dlsym(cuda_handle,"cudaDeviceGetPCIBusId");
  crcuda.crcudaIpcGetEventHandle= (cudaError_t (*)(cudaIpcEventHandle_t *handle,  cudaEvent_t event)) (cudaError_t*)dlsym(cuda_handle,"cudaIpcGetEventHandle");
  crcuda.crcudaIpcOpenEventHandle= (cudaError_t (*)(cudaEvent_t *event,  cudaIpcEventHandle_t handle)) (cudaError_t*)dlsym(cuda_handle,"cudaIpcOpenEventHandle");
  crcuda.crcudaIpcGetMemHandle= (cudaError_t (*)(cudaIpcMemHandle_t *handle,  void *devPtr)) (cudaError_t*)dlsym(cuda_handle,"cudaIpcGetMemHandle");
  crcuda.crcudaIpcOpenMemHandle= (cudaError_t (*)(void **devPtr,  cudaIpcMemHandle_t handle,  unsigned int flags)) (cudaError_t*)dlsym(cuda_handle,"cudaIpcOpenMemHandle");
  crcuda.crcudaIpcCloseMemHandle= (cudaError_t (*)(void *devPtr)) (cudaError_t*)dlsym(cuda_handle,"cudaIpcCloseMemHandle");
  crcuda.crcudaThreadExit= (cudaError_t (*)(void)) (cudaError_t*)dlsym(cuda_handle,"cudaThreadExit");
  crcuda.crcudaThreadSynchronize= (cudaError_t (*)(void)) (cudaError_t*)dlsym(cuda_handle,"cudaThreadSynchronize");
  crcuda.crcudaThreadSetLimit= (cudaError_t (*)(enum cudaLimit limit,  size_t value)) (cudaError_t*)dlsym(cuda_handle,"cudaThreadSetLimit");
  crcuda.crcudaThreadGetLimit= (cudaError_t (*)(size_t *pValue,  enum cudaLimit limit)) (cudaError_t*)dlsym(cuda_handle,"cudaThreadGetLimit");
  crcuda.crcudaThreadGetCacheConfig= (cudaError_t (*)(enum cudaFuncCache *pCacheConfig)) (cudaError_t*)dlsym(cuda_handle,"cudaThreadGetCacheConfig");
  crcuda.crcudaThreadSetCacheConfig= (cudaError_t (*)(enum cudaFuncCache cacheConfig)) (cudaError_t*)dlsym(cuda_handle,"cudaThreadSetCacheConfig");
  crcuda.crcudaGetLastError= (cudaError_t (*)(void)) (cudaError_t*)dlsym(cuda_handle,"cudaGetLastError");
  crcuda.crcudaPeekAtLastError= (cudaError_t (*)(void)) (cudaError_t*)dlsym(cuda_handle,"cudaPeekAtLastError");
  crcuda.crcudaGetErrorString= (const char* (*)(cudaError_t error)) (const char**)dlsym(cuda_handle,"cudaGetErrorString");
  crcuda.crcudaGetDeviceCount= (cudaError_t (*)(int *count)) (cudaError_t*)dlsym(cuda_handle,"cudaGetDeviceCount");
  crcuda.crcudaGetDeviceProperties= (cudaError_t (*)(struct cudaDeviceProp *prop,  int device)) (cudaError_t*)dlsym(cuda_handle,"cudaGetDeviceProperties");
  crcuda.crcudaDeviceGetAttribute= (cudaError_t (*)(int *value,  enum cudaDeviceAttr attr,  int device)) (cudaError_t*)dlsym(cuda_handle,"cudaDeviceGetAttribute");
  crcuda.crcudaChooseDevice= (cudaError_t (*)(int *device,  const struct cudaDeviceProp *prop)) (cudaError_t*)dlsym(cuda_handle,"cudaChooseDevice");
  crcuda.crcudaSetDevice= (cudaError_t (*)(int device)) (cudaError_t*)dlsym(cuda_handle,"cudaSetDevice");
  crcuda.crcudaGetDevice= (cudaError_t (*)(int *device)) (cudaError_t*)dlsym(cuda_handle,"cudaGetDevice");
  crcuda.crcudaSetValidDevices= (cudaError_t (*)(int *device_arr,  int len)) (cudaError_t*)dlsym(cuda_handle,"cudaSetValidDevices");
  crcuda.crcudaSetDeviceFlags= (cudaError_t (*)( unsigned int flags )) (cudaError_t*)dlsym(cuda_handle,"cudaSetDeviceFlags");
  crcuda.crcudaStreamCreate= (cudaError_t (*)(cudaStream_t *pStream)) (cudaError_t*)dlsym(cuda_handle,"cudaStreamCreate");
  crcuda.crcudaStreamCreateWithFlags= (cudaError_t (*)(cudaStream_t *pStream,  unsigned int flags)) (cudaError_t*)dlsym(cuda_handle,"cudaStreamCreateWithFlags");
  crcuda.crcudaStreamDestroy= (cudaError_t (*)(cudaStream_t stream)) (cudaError_t*)dlsym(cuda_handle,"cudaStreamDestroy");
  crcuda.crcudaStreamWaitEvent= (cudaError_t (*)(cudaStream_t stream,  cudaEvent_t event,  unsigned int flags)) (cudaError_t*)dlsym(cuda_handle,"cudaStreamWaitEvent");
  crcuda.crcudaStreamAddCallback= (cudaError_t (*)(cudaStream_t stream, cudaStreamCallback_t callback,  void *userData,  unsigned int flags)) (cudaError_t*)dlsym(cuda_handle,"cudaStreamAddCallback");
  crcuda.crcudaStreamSynchronize= (cudaError_t (*)(cudaStream_t stream)) (cudaError_t*)dlsym(cuda_handle,"cudaStreamSynchronize");
  crcuda.crcudaStreamQuery= (cudaError_t (*)(cudaStream_t stream)) (cudaError_t*)dlsym(cuda_handle,"cudaStreamQuery");
  crcuda.crcudaEventCreate= (cudaError_t (*)(cudaEvent_t *event)) (cudaError_t*)dlsym(cuda_handle,"cudaEventCreate");
  crcuda.crcudaEventCreateWithFlags= (cudaError_t (*)(cudaEvent_t *event,  unsigned int flags)) (cudaError_t*)dlsym(cuda_handle,"cudaEventCreateWithFlags");
  crcuda.crcudaEventRecord= (cudaError_t (*)(cudaEvent_t event,  cudaStream_t stream )) (cudaError_t*)dlsym(cuda_handle,"cudaEventRecord");
  crcuda.crcudaEventQuery= (cudaError_t (*)(cudaEvent_t event)) (cudaError_t*)dlsym(cuda_handle,"cudaEventQuery");
  crcuda.crcudaEventSynchronize= (cudaError_t (*)(cudaEvent_t event)) (cudaError_t*)dlsym(cuda_handle,"cudaEventSynchronize");
  crcuda.crcudaEventDestroy= (cudaError_t (*)(cudaEvent_t event)) (cudaError_t*)dlsym(cuda_handle,"cudaEventDestroy");
  crcuda.crcudaEventElapsedTime= (cudaError_t (*)(float *ms,  cudaEvent_t start,  cudaEvent_t end)) (cudaError_t*)dlsym(cuda_handle,"cudaEventElapsedTime");
  crcuda.crcudaConfigureCall= (cudaError_t (*)(dim3 gridDim,  dim3 blockDim,  size_t sharedMem ,  cudaStream_t stream )) (cudaError_t*)dlsym(cuda_handle,"cudaConfigureCall");
  crcuda.crcudaSetupArgument= (cudaError_t (*)(const void *arg,  size_t size,  size_t offset)) (cudaError_t*)dlsym(cuda_handle,"cudaSetupArgument");
  crcuda.crcudaFuncSetCacheConfig= (cudaError_t (*)(const void *func,  enum cudaFuncCache cacheConfig)) (cudaError_t*)dlsym(cuda_handle,"cudaFuncSetCacheConfig");
  crcuda.crcudaFuncSetSharedMemConfig= (cudaError_t (*)(const void *func,  enum cudaSharedMemConfig config)) (cudaError_t*)dlsym(cuda_handle,"cudaFuncSetSharedMemConfig");
  crcuda.crcudaLaunch= (cudaError_t (*)(const void *func)) (cudaError_t*)dlsym(cuda_handle,"cudaLaunch");
  crcuda.crcudaFuncGetAttributes= (cudaError_t (*)(struct cudaFuncAttributes *attr,  const void *func)) (cudaError_t*)dlsym(cuda_handle,"cudaFuncGetAttributes");
  crcuda.crcudaSetDoubleForDevice= (cudaError_t (*)(double *d)) (cudaError_t*)dlsym(cuda_handle,"cudaSetDoubleForDevice");
  crcuda.crcudaSetDoubleForHost= (cudaError_t (*)(double *d)) (cudaError_t*)dlsym(cuda_handle,"cudaSetDoubleForHost");
  crcuda.crcudaMalloc= (cudaError_t (*)(void **devPtr,  size_t size)) (cudaError_t*)dlsym(cuda_handle,"cudaMalloc");
  crcuda.crcudaMallocHost= (cudaError_t (*)(void **ptr,  size_t size)) (cudaError_t*)dlsym(cuda_handle,"cudaMallocHost");
  crcuda.crcudaMallocPitch= (cudaError_t (*)(void **devPtr,  size_t *pitch,  size_t width,  size_t height)) (cudaError_t*)dlsym(cuda_handle,"cudaMallocPitch");
  crcuda.crcudaMallocArray= (cudaError_t (*)(cudaArray_t *array,  const struct cudaChannelFormatDesc *desc,  size_t width,  size_t height ,  unsigned int flags )) (cudaError_t*)dlsym(cuda_handle,"cudaMallocArray");
  crcuda.crcudaFree= (cudaError_t (*)(void *devPtr)) (cudaError_t*)dlsym(cuda_handle,"cudaFree");
  crcuda.crcudaFreeHost= (cudaError_t (*)(void *ptr)) (cudaError_t*)dlsym(cuda_handle,"cudaFreeHost");
  crcuda.crcudaFreeArray= (cudaError_t (*)(cudaArray_t array)) (cudaError_t*)dlsym(cuda_handle,"cudaFreeArray");
  crcuda.crcudaFreeMipmappedArray= (cudaError_t (*)(cudaMipmappedArray_t mipmappedArray)) (cudaError_t*)dlsym(cuda_handle,"cudaFreeMipmappedArray");
  crcuda.crcudaHostAlloc= (cudaError_t (*)(void **pHost,  size_t size,  unsigned int flags)) (cudaError_t*)dlsym(cuda_handle,"cudaHostAlloc");
  crcuda.crcudaHostRegister= (cudaError_t (*)(void *ptr,  size_t size,  unsigned int flags)) (cudaError_t*)dlsym(cuda_handle,"cudaHostRegister");
  crcuda.crcudaHostUnregister= (cudaError_t (*)(void *ptr)) (cudaError_t*)dlsym(cuda_handle,"cudaHostUnregister");
  crcuda.crcudaHostGetDevicePointer= (cudaError_t (*)(void **pDevice,  void *pHost,  unsigned int flags)) (cudaError_t*)dlsym(cuda_handle,"cudaHostGetDevicePointer");
  crcuda.crcudaHostGetFlags= (cudaError_t (*)(unsigned int *pFlags,  void *pHost)) (cudaError_t*)dlsym(cuda_handle,"cudaHostGetFlags");
  crcuda.crcudaMalloc3D= (cudaError_t (*)(struct cudaPitchedPtr* pitchedDevPtr,  struct cudaExtent extent)) (cudaError_t*)dlsym(cuda_handle,"cudaMalloc3D");
  crcuda.crcudaMalloc3DArray= (cudaError_t (*)(cudaArray_t *array,  const struct cudaChannelFormatDesc* desc,  struct cudaExtent extent,  unsigned int flags )) (cudaError_t*)dlsym(cuda_handle,"cudaMalloc3DArray");
  crcuda.crcudaMallocMipmappedArray= (cudaError_t (*)(cudaMipmappedArray_t *mipmappedArray,  const struct cudaChannelFormatDesc* desc,  struct cudaExtent extent,  unsigned int numLevels,  unsigned int flags )) (cudaError_t*)dlsym(cuda_handle,"cudaMallocMipmappedArray");
  crcuda.crcudaGetMipmappedArrayLevel= (cudaError_t (*)(cudaArray_t *levelArray,  cudaMipmappedArray_const_t mipmappedArray,  unsigned int level)) (cudaError_t*)dlsym(cuda_handle,"cudaGetMipmappedArrayLevel");
  crcuda.crcudaMemcpy3D= (cudaError_t (*)(const struct cudaMemcpy3DParms *p)) (cudaError_t*)dlsym(cuda_handle,"cudaMemcpy3D");
  crcuda.crcudaMemcpy3DPeer= (cudaError_t (*)(const struct cudaMemcpy3DPeerParms *p)) (cudaError_t*)dlsym(cuda_handle,"cudaMemcpy3DPeer");
  crcuda.crcudaMemcpy3DAsync= (cudaError_t (*)(const struct cudaMemcpy3DParms *p,  cudaStream_t stream )) (cudaError_t*)dlsym(cuda_handle,"cudaMemcpy3DAsync");
  crcuda.crcudaMemcpy3DPeerAsync= (cudaError_t (*)(const struct cudaMemcpy3DPeerParms *p,  cudaStream_t stream )) (cudaError_t*)dlsym(cuda_handle,"cudaMemcpy3DPeerAsync");
  crcuda.crcudaMemGetInfo= (cudaError_t (*)(size_t *free,  size_t *total)) (cudaError_t*)dlsym(cuda_handle,"cudaMemGetInfo");
  crcuda.crcudaArrayGetInfo= (cudaError_t (*)(struct cudaChannelFormatDesc *desc,  struct cudaExtent *extent,  unsigned int *flags,  cudaArray_t array)) (cudaError_t*)dlsym(cuda_handle,"cudaArrayGetInfo");
  crcuda.crcudaMemcpy= (cudaError_t (*)(void *dst,  const void *src,  size_t count,  enum cudaMemcpyKind kind)) (cudaError_t*)dlsym(cuda_handle,"cudaMemcpy");
  crcuda.crcudaMemcpyPeer= (cudaError_t (*)(void *dst,  int dstDevice,  const void *src,  int srcDevice,  size_t count)) (cudaError_t*)dlsym(cuda_handle,"cudaMemcpyPeer");
  crcuda.crcudaMemcpyToArray= (cudaError_t (*)(cudaArray_t dst,  size_t wOffset,  size_t hOffset,  const void *src,  size_t count,  enum cudaMemcpyKind kind)) (cudaError_t*)dlsym(cuda_handle,"cudaMemcpyToArray");
  crcuda.crcudaMemcpyFromArray= (cudaError_t (*)(void *dst,  cudaArray_const_t src,  size_t wOffset,  size_t hOffset,  size_t count,  enum cudaMemcpyKind kind)) (cudaError_t*)dlsym(cuda_handle,"cudaMemcpyFromArray");
  crcuda.crcudaMemcpyArrayToArray= (cudaError_t (*)(cudaArray_t dst,  size_t wOffsetDst,  size_t hOffsetDst,  cudaArray_const_t src,  size_t wOffsetSrc,  size_t hOffsetSrc,  size_t count,  enum cudaMemcpyKind kind )) (cudaError_t*)dlsym(cuda_handle,"cudaMemcpyArrayToArray");
  crcuda.crcudaMemcpy2D= (cudaError_t (*)(void *dst,  size_t dpitch,  const void *src,  size_t spitch,  size_t width,  size_t height,  enum cudaMemcpyKind kind)) (cudaError_t*)dlsym(cuda_handle,"cudaMemcpy2D");
  crcuda.crcudaMemcpy2DToArray= (cudaError_t (*)(cudaArray_t dst,  size_t wOffset,  size_t hOffset,  const void *src,  size_t spitch,  size_t width,  size_t height,  enum cudaMemcpyKind kind)) (cudaError_t*)dlsym(cuda_handle,"cudaMemcpy2DToArray");
  crcuda.crcudaMemcpy2DFromArray= (cudaError_t (*)(void *dst,  size_t dpitch,  cudaArray_const_t src,  size_t wOffset,  size_t hOffset,  size_t width,  size_t height,  enum cudaMemcpyKind kind)) (cudaError_t*)dlsym(cuda_handle,"cudaMemcpy2DFromArray");
  crcuda.crcudaMemcpy2DArrayToArray= (cudaError_t (*)(cudaArray_t dst,  size_t wOffsetDst,  size_t hOffsetDst,  cudaArray_const_t src,  size_t wOffsetSrc,  size_t hOffsetSrc,  size_t width,  size_t height,  enum cudaMemcpyKind kind )) (cudaError_t*)dlsym(cuda_handle,"cudaMemcpy2DArrayToArray");
  crcuda.crcudaMemcpyToSymbol= (cudaError_t (*)(const void *symbol,  const void *src,  size_t count,  size_t offset ,  enum cudaMemcpyKind kind )) (cudaError_t*)dlsym(cuda_handle,"cudaMemcpyToSymbol");
  crcuda.crcudaMemcpyFromSymbol= (cudaError_t (*)(void *dst,  const void *symbol,  size_t count,  size_t offset ,  enum cudaMemcpyKind kind )) (cudaError_t*)dlsym(cuda_handle,"cudaMemcpyFromSymbol");
  crcuda.crcudaMemcpyAsync= (cudaError_t (*)(void *dst,  const void *src,  size_t count,  enum cudaMemcpyKind kind,  cudaStream_t stream )) (cudaError_t*)dlsym(cuda_handle,"cudaMemcpyAsync");
  crcuda.crcudaMemcpyPeerAsync= (cudaError_t (*)(void *dst,  int dstDevice,  const void *src,  int srcDevice,  size_t count,  cudaStream_t stream )) (cudaError_t*)dlsym(cuda_handle,"cudaMemcpyPeerAsync");
  crcuda.crcudaMemcpyToArrayAsync= (cudaError_t (*)(cudaArray_t dst,  size_t wOffset,  size_t hOffset,  const void *src,  size_t count,  enum cudaMemcpyKind kind,  cudaStream_t stream )) (cudaError_t*)dlsym(cuda_handle,"cudaMemcpyToArrayAsync");
  crcuda.crcudaMemcpyFromArrayAsync= (cudaError_t (*)(void *dst,  cudaArray_const_t src,  size_t wOffset,  size_t hOffset,  size_t count,  enum cudaMemcpyKind kind,  cudaStream_t stream )) (cudaError_t*)dlsym(cuda_handle,"cudaMemcpyFromArrayAsync");
  crcuda.crcudaMemcpy2DAsync= (cudaError_t (*)(void *dst,  size_t dpitch,  const void *src,  size_t spitch,  size_t width,  size_t height,  enum cudaMemcpyKind kind,  cudaStream_t stream )) (cudaError_t*)dlsym(cuda_handle,"cudaMemcpy2DAsync");
  crcuda.crcudaMemcpy2DToArrayAsync= (cudaError_t (*)(cudaArray_t dst,  size_t wOffset,  size_t hOffset,  const void *src,  size_t spitch,  size_t width,  size_t height,  enum cudaMemcpyKind kind,  cudaStream_t stream )) (cudaError_t*)dlsym(cuda_handle,"cudaMemcpy2DToArrayAsync");
  crcuda.crcudaMemcpy2DFromArrayAsync= (cudaError_t (*)(void *dst,  size_t dpitch,  cudaArray_const_t src,  size_t wOffset,  size_t hOffset,  size_t width,  size_t height,  enum cudaMemcpyKind kind,  cudaStream_t stream )) (cudaError_t*)dlsym(cuda_handle,"cudaMemcpy2DFromArrayAsync");
  crcuda.crcudaMemcpyToSymbolAsync= (cudaError_t (*)(const void *symbol,  const void *src,  size_t count,  size_t offset,  enum cudaMemcpyKind kind,  cudaStream_t stream )) (cudaError_t*)dlsym(cuda_handle,"cudaMemcpyToSymbolAsync");
  crcuda.crcudaMemcpyFromSymbolAsync= (cudaError_t (*)(void *dst,  const void *symbol,  size_t count,  size_t offset,  enum cudaMemcpyKind kind,  cudaStream_t stream )) (cudaError_t*)dlsym(cuda_handle,"cudaMemcpyFromSymbolAsync");
  crcuda.crcudaMemset= (cudaError_t (*)(void *devPtr,  int value,  size_t count)) (cudaError_t*)dlsym(cuda_handle,"cudaMemset");
  crcuda.crcudaMemset2D= (cudaError_t (*)(void *devPtr,  size_t pitch,  int value,  size_t width,  size_t height)) (cudaError_t*)dlsym(cuda_handle,"cudaMemset2D");
  crcuda.crcudaMemset3D= (cudaError_t (*)(struct cudaPitchedPtr pitchedDevPtr,  int value,  struct cudaExtent extent)) (cudaError_t*)dlsym(cuda_handle,"cudaMemset3D");
  crcuda.crcudaMemsetAsync= (cudaError_t (*)(void *devPtr,  int value,  size_t count,  cudaStream_t stream )) (cudaError_t*)dlsym(cuda_handle,"cudaMemsetAsync");
  crcuda.crcudaMemset2DAsync= (cudaError_t (*)(void *devPtr,  size_t pitch,  int value,  size_t width,  size_t height,  cudaStream_t stream )) (cudaError_t*)dlsym(cuda_handle,"cudaMemset2DAsync");
  crcuda.crcudaMemset3DAsync= (cudaError_t (*)(struct cudaPitchedPtr pitchedDevPtr,  int value,  struct cudaExtent extent,  cudaStream_t stream )) (cudaError_t*)dlsym(cuda_handle,"cudaMemset3DAsync");
  crcuda.crcudaGetSymbolAddress= (cudaError_t (*)(void **devPtr,  const void *symbol)) (cudaError_t*)dlsym(cuda_handle,"cudaGetSymbolAddress");
  crcuda.crcudaGetSymbolSize= (cudaError_t (*)(size_t *size,  const void *symbol)) (cudaError_t*)dlsym(cuda_handle,"cudaGetSymbolSize");
  crcuda.crcudaPointerGetAttributes= (cudaError_t (*)(struct cudaPointerAttributes *attributes,  const void *ptr)) (cudaError_t*)dlsym(cuda_handle,"cudaPointerGetAttributes");
  crcuda.crcudaDeviceCanAccessPeer= (cudaError_t (*)(int *canAccessPeer,  int device,  int peerDevice)) (cudaError_t*)dlsym(cuda_handle,"cudaDeviceCanAccessPeer");
  crcuda.crcudaDeviceEnablePeerAccess= (cudaError_t (*)(int peerDevice,  unsigned int flags)) (cudaError_t*)dlsym(cuda_handle,"cudaDeviceEnablePeerAccess");
  crcuda.crcudaDeviceDisablePeerAccess= (cudaError_t (*)(int peerDevice)) (cudaError_t*)dlsym(cuda_handle,"cudaDeviceDisablePeerAccess");
  crcuda.crcudaGraphicsUnregisterResource= (cudaError_t (*)(cudaGraphicsResource_t resource)) (cudaError_t*)dlsym(cuda_handle,"cudaGraphicsUnregisterResource");
  crcuda.crcudaGraphicsResourceSetMapFlags= (cudaError_t (*)(cudaGraphicsResource_t resource,  unsigned int flags)) (cudaError_t*)dlsym(cuda_handle,"cudaGraphicsResourceSetMapFlags");
  crcuda.crcudaGraphicsMapResources= (cudaError_t (*)(int count,  cudaGraphicsResource_t *resources,  cudaStream_t stream )) (cudaError_t*)dlsym(cuda_handle,"cudaGraphicsMapResources");
  crcuda.crcudaGraphicsUnmapResources= (cudaError_t (*)(int count,  cudaGraphicsResource_t *resources,  cudaStream_t stream )) (cudaError_t*)dlsym(cuda_handle,"cudaGraphicsUnmapResources");
  crcuda.crcudaGraphicsResourceGetMappedPointer= (cudaError_t (*)(void **devPtr,  size_t *size,  cudaGraphicsResource_t resource)) (cudaError_t*)dlsym(cuda_handle,"cudaGraphicsResourceGetMappedPointer");
  crcuda.crcudaGraphicsSubResourceGetMappedArray= (cudaError_t (*)(cudaArray_t *array,  cudaGraphicsResource_t resource,  unsigned int arrayIndex,  unsigned int mipLevel)) (cudaError_t*)dlsym(cuda_handle,"cudaGraphicsSubResourceGetMappedArray");
  crcuda.crcudaGraphicsResourceGetMappedMipmappedArray= (cudaError_t (*)(cudaMipmappedArray_t *mipmappedArray,  cudaGraphicsResource_t resource)) (cudaError_t*)dlsym(cuda_handle,"cudaGraphicsResourceGetMappedMipmappedArray");
  crcuda.crcudaGetChannelDesc= (cudaError_t (*)(struct cudaChannelFormatDesc *desc,  cudaArray_const_t array)) (cudaError_t*)dlsym(cuda_handle,"cudaGetChannelDesc");
  crcuda.crcudaCreateChannelDesc= (struct cudaChannelFormatDesc (*)(int x,  int y,  int z,  int w,  enum cudaChannelFormatKind f)) (struct cudaChannelFormatDesc*)dlsym(cuda_handle,"cudaCreateChannelDesc");
  crcuda.crcudaBindTexture= (cudaError_t (*)(size_t *offset,  const struct textureReference *texref,  const void *devPtr,  const struct cudaChannelFormatDesc *desc,  size_t size )) (cudaError_t*)dlsym(cuda_handle,"cudaBindTexture");
  crcuda.crcudaBindTexture2D= (cudaError_t (*)(size_t *offset,  const struct textureReference *texref,  const void *devPtr,  const struct cudaChannelFormatDesc *desc,  size_t width,  size_t height,  size_t pitch)) (cudaError_t*)dlsym(cuda_handle,"cudaBindTexture2D");
  crcuda.crcudaBindTextureToArray= (cudaError_t (*)(const struct textureReference *texref,  cudaArray_const_t array,  const struct cudaChannelFormatDesc *desc)) (cudaError_t*)dlsym(cuda_handle,"cudaBindTextureToArray");
  crcuda.crcudaBindTextureToMipmappedArray= (cudaError_t (*)(const struct textureReference *texref,  cudaMipmappedArray_const_t mipmappedArray,  const struct cudaChannelFormatDesc *desc)) (cudaError_t*)dlsym(cuda_handle,"cudaBindTextureToMipmappedArray");
  crcuda.crcudaUnbindTexture= (cudaError_t (*)(const struct textureReference *texref)) (cudaError_t*)dlsym(cuda_handle,"cudaUnbindTexture");
  crcuda.crcudaGetTextureAlignmentOffset= (cudaError_t (*)(size_t *offset,  const struct textureReference *texref)) (cudaError_t*)dlsym(cuda_handle,"cudaGetTextureAlignmentOffset");
  crcuda.crcudaGetTextureReference= (cudaError_t (*)(const struct textureReference **texref,  const void *symbol)) (cudaError_t*)dlsym(cuda_handle,"cudaGetTextureReference");
  crcuda.crcudaBindSurfaceToArray= (cudaError_t (*)(const struct surfaceReference *surfref,  cudaArray_const_t array,  const struct cudaChannelFormatDesc *desc)) (cudaError_t*)dlsym(cuda_handle,"cudaBindSurfaceToArray");
  crcuda.crcudaGetSurfaceReference= (cudaError_t (*)(const struct surfaceReference **surfref,  const void *symbol)) (cudaError_t*)dlsym(cuda_handle,"cudaGetSurfaceReference");
  crcuda.crcudaCreateTextureObject= (cudaError_t (*)(cudaTextureObject_t *pTexObject,  const struct cudaResourceDesc *pResDesc,  const struct cudaTextureDesc *pTexDesc,  const struct cudaResourceViewDesc *pResViewDesc)) (cudaError_t*)dlsym(cuda_handle,"cudaCreateTextureObject");
  crcuda.crcudaDestroyTextureObject= (cudaError_t (*)(cudaTextureObject_t texObject)) (cudaError_t*)dlsym(cuda_handle,"cudaDestroyTextureObject");
  crcuda.crcudaGetTextureObjectResourceDesc= (cudaError_t (*)(struct cudaResourceDesc *pResDesc,  cudaTextureObject_t texObject)) (cudaError_t*)dlsym(cuda_handle,"cudaGetTextureObjectResourceDesc");
  crcuda.crcudaGetTextureObjectTextureDesc= (cudaError_t (*)(struct cudaTextureDesc *pTexDesc,  cudaTextureObject_t texObject)) (cudaError_t*)dlsym(cuda_handle,"cudaGetTextureObjectTextureDesc");
  crcuda.crcudaGetTextureObjectResourceViewDesc= (cudaError_t (*)(struct cudaResourceViewDesc *pResViewDesc,  cudaTextureObject_t texObject)) (cudaError_t*)dlsym(cuda_handle,"cudaGetTextureObjectResourceViewDesc");
  crcuda.crcudaCreateSurfaceObject= (cudaError_t (*)(cudaSurfaceObject_t *pSurfObject,  const struct cudaResourceDesc *pResDesc)) (cudaError_t*)dlsym(cuda_handle,"cudaCreateSurfaceObject");
  crcuda.crcudaDestroySurfaceObject= (cudaError_t (*)(cudaSurfaceObject_t surfObject)) (cudaError_t*)dlsym(cuda_handle,"cudaDestroySurfaceObject");
  crcuda.crcudaGetSurfaceObjectResourceDesc= (cudaError_t (*)(struct cudaResourceDesc *pResDesc,  cudaSurfaceObject_t surfObject)) (cudaError_t*)dlsym(cuda_handle,"cudaGetSurfaceObjectResourceDesc");
  crcuda.crcudaDriverGetVersion= (cudaError_t (*)(int *driverVersion)) (cudaError_t*)dlsym(cuda_handle,"cudaDriverGetVersion");
  crcuda.crcudaRuntimeGetVersion= (cudaError_t (*)(int *runtimeVersion)) (cudaError_t*)dlsym(cuda_handle,"cudaRuntimeGetVersion");
  crcuda.crcudaGetExportTable= (cudaError_t (*)(const void **ppExportTable,  const cudaUUID_t *pExportTableId)) (cudaError_t*)dlsym(cuda_handle,"cudaGetExportTable");
  crcuda.__crcudaRegisterVar = (void (*)(void **fatCubinHandle,char *hostVar,char *deviceAddress,const char *deviceName,int ext,int size,int constant,int global))(void*)dlsym(cuda_handle,"__cudaRegisterVar");
  crcuda.__crcudaRegisterTexture = (void (*)(void **fatCubinHandle,const struct textureReference *hostVar,const void **deviceAddress,const char *deviceName,int dim,int norm,int ext))(void*)dlsym(cuda_handle,"__cudaRegisterTexture");
  crcuda.__crcudaRegisterSurface = (void (*)(void **fatCubinHandle,const struct surfaceReference  *hostVar,const void **deviceAddress,const char *deviceName,int dim,int ext))(void*)dlsym(cuda_handle,"__cudaRegisterSurface");
  crcuda.__crcudaRegisterFunction = (void (*)(void **fatCubinHandle,const char *hostFun,char *deviceFun,const char *deviceName,int thread_limit,uint3 *tid,uint3 *bid,dim3 *bDim,dim3 *gDim,int *wSize))(void*)dlsym(cuda_handle,"__cudaRegisterFunction");
  crcuda.__crcudaRegisterShared = (void (*)(void **fatCubinHandle,void **devicePtr))(void*)dlsym(cuda_handle,"__cudaRegisterShared");
  crcuda.__crcudaRegisterSharedVar = (void (*)(void **fatCubinHandle,void **devicePtr,size_t size,size_t alignment, int storage))(void *)dlsym(cuda_handle,"__cudaRegisterSharedVar");
  crcuda.__crcudaSynchronizeThreads = (int (*)(void** one,void* two))(int *)dlsym(cuda_handle,"__cudaSynchronizeThreads");
  crcuda.__crcudaTextureFetch = (void (*)(const void* tex,void* index,int integer,void* val))(void *)dlsym(cuda_handle,"__cudaTextureFetch");
  crcuda.__crcudaMutexOperation = (void (*)(int lock))(void *)dlsym(cuda_handle,"__cudaMutexOperation");
  crcuda.__crcudaRegisterDeviceFunction = (cudaError_t (*)())(cudaError_t *)dlsym(cuda_handle,"__cudaRegisterDeviceFunction");
  crcuda.__crcudaRegisterFatBinary = (void** (*)(void*))(void ***)dlsym(cuda_handle,"__cudaRegisterFatBinary");
  crcuda.__crcudaUnregisterFatBinary = (void (*)(void**))(void *)dlsym(cuda_handle,"__cudaUnregisterFatBinary");
}

int dlclose_cuda(){
  int res;

  res = dlclose(cuda_handle);
    
  return res;
}