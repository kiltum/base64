#include <stdio.h>
#include <string.h>
#include "base64.h"

int main (void) {

unsigned char input[]="lets look for back";

unsigned char output[256]="";

unsigned char test[256]="";

int res=0;


res=base64_encode_length( (unsigned char * )&input, strlen( (const char *) &input));
printf("Need for store at least %d bytes\n", res);

res=base64_encode( (unsigned char * )&input, strlen( (const char *) &input), (unsigned char *) &output );

printf("ENCODE: %d output bytes \n input: %s\noutput: %s\n",res,input,output);

res=base64_decode((unsigned char *) &output , res, (unsigned char *) &test );

printf("DECODE: %d output bytes\n input: %s\n output: %s\n", res, output, test);

return 0;
}