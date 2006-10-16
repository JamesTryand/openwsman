//
// CimResource_data.h
//
// This file is intended to be eventually generated by a codegen tool
//
#ifndef __CIM_DATA_H__
#define __CIM_DATA_H__



// The resource is modeled as a struct
struct __CimResource
{
	char* xml;
};
typedef struct __CimResource CimResource;


// Service endpoint declaration

int CimResource_Enumerate_EP(WsContextH cntx, WsEnumerateInfo* enumInfo, WsmanStatus *status);
int CimResource_Release_EP(WsContextH cntx, WsEnumerateInfo* enumInfo, WsmanStatus *status);
int CimResource_Pull_EP(WsContextH cntx, WsEnumerateInfo* enumInfo, WsmanStatus *status);
int CimResource_Get_EP(SoapOpH op, void* appData);
int CimResource_Custom_EP(SoapOpH op, void* appData);
int  CimResource_Put_EP(SoapOpH op, void* appData);

SER_DECLARE_TYPE(CimResource);
SER_DECLARE_EP_ARRAY(CimResource);

void get_endpoints(void *self, void **data);
int init (void *self, void **data );
void cleanup( void *self, void *data );
void set_config( void *self, dictionary *config );
char *get_cim_namespace(void);
hash_t* get_vendor_namespaces(void);

#endif // __CIM_DATA_H__