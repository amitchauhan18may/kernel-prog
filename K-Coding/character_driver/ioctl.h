enum
{
	MY_WRITE,
	MY_READ
};

#define WR_VAL _IOW(MAGIC_KEY, MY_WRITE, int32_t *)
#define RD_VAL _IOR(MAGIC_KEY, MY_READ, int32_t *)
