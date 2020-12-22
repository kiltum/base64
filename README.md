# base64
Simple base64 library for using in MCU

- No malloc and other synamic allocations
- Small memory footprint (but increased flash footprint)

## How to use

- input - array of unsigned chars
- len - lenght of input
- output - place for encoded or decoded data. 

### Get amount of storage for base64 encoding

```
unsigned char input[]="Text String";

int res=0;

res=base64_encode_length( (unsigned char * )&input, strlen( (const char *) &input));
printf("Need for store at least %d bytes\n", res);
```

### Encode

```
unsigned char input[]="Text String";

unsigned char output[256]="";

int res=0;

res=base64_encode( (unsigned char * )&input, strlen( (const char *) &input), (unsigned char *) &output );

printf("ENCODE: %d output bytes \n input: %s\noutput: %s\n",res,input,output);
```

### Decode

```
res=base64_decode((unsigned char *) &output , res, (unsigned char *) &test );

printf("DECODE: %d output bytes\n input: %s\n output: %s\n", res, output, test);
```

## Example

```
$ gcc test.c base64.c && ./a.out
Need for store at least 17 bytes
ENCODE: 16 output bytes 
 input: Text String
output: VGV4dCBTdHJpbmc=
DECODE: 11 output bytes
 input: VGV4dCBTdHJpbmc=
 output: Text String
```

