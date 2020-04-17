/**
	ex4_2
	base64.h
	1427405017
	沈家赟
*/
#ifndef BASE64_H
#define BASE64_H

void encodeStrToBase64(char str[], char base64[]);
void decodeBase64ToStr(char base64[], char str[]);

const char b64arr[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";


void encodeStrToBase64(char str[], char base64[])
{
	unsigned int len = 0;
	int i;

	len = strlen(str);
	for (i = 0; i < len / 3; i++)
	{
		base64[i * 4 + 0] = b64arr[(str[i * 3 + 0] & 0xFC) >> 2];
		base64[i * 4 + 1] = b64arr[(str[i * 3 + 0] & 0x03) << 4 | (str[i * 3 + 1] & 0xF0) >> 4];
		base64[i * 4 + 2] = b64arr[(str[i * 3 + 1] & 0x0F) << 2 | (str[i * 3 + 2] & 0xC0) >> 6];
		base64[i * 4 + 3] = b64arr[(str[i * 3 + 2] & 0x3F)];
	}

	// if not triple len
	if (len % 3 == 1)
	{
		base64[i * 4 + 0] = b64arr[(str[i * 3 + 0] & 0xFC) >> 2];
		base64[i * 4 + 1] = b64arr[(str[i * 3 + 0] & 0x03) << 4];
		base64[i * 4 + 2] = b64arr[64];
		base64[i * 4 + 3] = b64arr[64];
		base64[i * 4 + 4] = 0;	// end of base64 string
	}
	else if (len % 3 == 2)
	{
		base64[i * 4 + 0] = b64arr[(str[i * 3 + 0] & 0xFC) >> 2];
		base64[i * 4 + 1] = b64arr[(str[i * 3 + 0] & 0x03) << 4 | (str[i * 3 + 1] & 0xF0) >> 4];
		base64[i * 4 + 2] = b64arr[(str[i * 3 + 1] & 0x0F) << 2];
		base64[i * 4 + 3] = b64arr[64];
		base64[i * 4 + 4] = 0;	// end of base64 string
	}
	else
	{
		base64[i * 4] = 0;	// end of base64 string
	}
}


void decodeBase64ToStr(char base64[], char str[])
{
	int i, j, len;
	int index[4];

	len = strlen(base64);
	for (i = 0; i < len / 4; i++)
	{
		// transform four base64 bytes to indexes per time
		for (j = 0; j < 4; j++)
		{
			index[j] = strchr(b64arr, base64[i * 4 + j]) - b64arr;	// index location of base64 charater
		}
		// merge four base64 indexes to three bytes
		// 00111111 0011'2222 002222'33 00333333
		str[i * 3 + 0] = ((index[0] & 0x3F) << 2) | ((index[1] & 0x30) >> 4);
		str[i * 3 + 1] = ((index[1] & 0x0F) << 4) | ((index[2] & 0x3C) >> 2);
		str[i * 3 + 2] = ((index[2] & 0x03) << 6) | (index[3] & 0x3F);
	}
	str[i * 3] = 0;		// end of string

	if (len % 4 != 0)
	{
		printf("Invalid Base64 encoding: this length is not quad multiple.");
	}
}

#endif