/**
	ex4_3
	ex4_3.h
	1427405017
	Éò¼ÒÚS
*/


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "base64.h"

#define BASE64_BUFFER_SIZE 4
#define BYTES_BUFFER_SIZE 3

static const char help[] = 
"This program functions as a Base64 encoder/decoder.\n\
command [options] [inputFilePath] [outputFilePath]\n\
e.g.\n\
	-e --encode\t//encode inputFile to encoded outputFile\n\
	-d --decode\t//decode inputFile to decoded outputFile\n";

int main(const int argc, const char *args[])
{

	FILE *pfin, *pfout;
	uint8_t bytes[BYTES_BUFFER_SIZE];
	char b64[BASE64_BUFFER_SIZE];
	char *ptrBase64Buf;
	uint8_t *ptrBytesBuf;
	unsigned int bytesLen, b64Len;
	int ret;



	if(argc != 4)	// cmd option inFile outFile => 4 essential entries
	{
		printf("%s\n", help);
		return 0;
	}
	else
	{
		/*
			open inFile and outFile
		*/
		pfin = fopen(args[2], "rb");
		if (pfin == NULL)
		{
			printf("ERROR: can not open file %s\n", args[2]);
			return 0;
		}
		pfout = fopen(args[3], "wb");
		if (pfout == NULL)
		{
			printf("ERROR: can not open file %s\n", args[3]);
			return 0;
		}


		/*
			process according to option
		*/
		if (strcmp(args[1], "-e") == 0 || strcmp(args[1], "--encode") == 0)	// -e or --encode
		{
			printf("encoding %s to %s ...\n", args[2], args[3]);

			while (!feof(pfin))
			{
				// read 3 bytes
				bytesLen = fread(bytes, sizeof(uint8_t), BYTES_BUFFER_SIZE, pfin);
				if (bytesLen <= 0)
				{
					break;
				}

				// encode 3 bytes to 4 base64 chars
				ptrBase64Buf = encodeBytesToBase64(bytes, bytesLen, &b64Len);


				// write 4 base64 chars
				ret = fwrite(ptrBase64Buf, sizeof(char), b64Len, pfout);
				if (ret <= 0)
				{
					printf("Error: can not write to file %s!\n", args[3]);
					break;
				}

				// WARNING: free malloced buffer mannually! [AVOID memory leakage]
				free(ptrBase64Buf);
			}
			printf("Encoding done!\n");
		}
		else if (strcmp(args[1], "-d") == 0 || strcmp(args[1], "--decode") == 0)	// -d or --decode
		{
			printf("decoding %s to %s ...\n", args[2], args[3]);

			while (!feof(pfin))
			{
				// read 4 base64 chars
				b64Len = fread(b64, sizeof(char), BASE64_BUFFER_SIZE, pfin);
				if (b64Len <= 0)
				{
					break;
				}

				// decode 4 base64 chars to 3 bytes
				ptrBytesBuf = decodeBase64ToBytes(b64, b64Len, &bytesLen);

				// write 3 bytes
				ret = fwrite(ptrBytesBuf, sizeof(uint8_t), bytesLen, pfout);
				if (ret <= 0)
				{
					printf("Error: can not write to file %s!\n", args[3]);
					break;
				}
				
				// WARNING: free malloced buffer mannually! [AVOID memory leakage]
				free(ptrBytesBuf);
			}

			printf("Decoding done!\n");
		}
		else
		{
			printf("%s\n", help);
		}


		/*
			close inFile and outFile
		*/
		fclose(pfin);
		fclose(pfout);

	}

	return 0;
}