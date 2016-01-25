#include<stdlib.h>
#include<stdio.h>
#include <inttypes.h>

// Matrices
int s0[4][4] = {1, 0, 3, 2, 3, 2, 1, 0, 0, 2, 1, 3, 3, 1, 3, 2};
int s1[4][4] = {0, 1, 2, 3, 2, 0, 1, 3, 3, 0, 1, 0, 2, 1, 0, 3};

// Permutation on 10 bit key
void P10(unsigned char **key) {
	char tmp = (*key)[0];
	(*key)[0] = (*key)[2];
	(*key)[2] = (*key)[1];
	(*key)[1] = (*key)[4];
	(*key)[4] = (*key)[3];
	(*key)[3] = (*key)[6];
	(*key)[6] = tmp;
	tmp = (*key)[5];
	(*key)[5] = (*key)[9];
	(*key)[9] = tmp;
	tmp = (*key)[7];
	(*key)[7] = (*key)[8];
	(*key)[8] = tmp;
}

// Permutation on 8 bit key
void P8(unsigned char **dst_key, const unsigned char *src_key) {
	(*dst_key)[0] = src_key[5];
	(*dst_key)[1] = src_key[2];
	(*dst_key)[2] = src_key[6];
	(*dst_key)[3] = src_key[3];
	(*dst_key)[4] = src_key[7];
	(*dst_key)[5] = src_key[4];
	(*dst_key)[6] = src_key[9];
	(*dst_key)[7] = src_key[8];
}

// Do IP
void IPbit(unsigned char *input) {
	unsigned char output = 0;
	output |= ((*input) & (1 << 0)) << 2;
	output |= ((*input) & (1 << 1)) >> 1;
	output |= ((*input) & (1 << 2)) << 4;
	output |= ((*input) & (1 << 3)) >> 2;
	output |= ((*input) & (1 << 4)) >> 1;
	output |= ((*input) & (1 << 5)) << 0;
	output |= ((*input) & (1 << 6)) << 1;
	output |= ((*input) & (1 << 7)) >> 3;
	*input = output;
}

// Do IP reverse
void IPREVbit(unsigned char *input) {
	unsigned char output = 0;
	output |= ((*input) & (1 << 0)) << 1;
	output |= ((*input) & (1 << 1)) << 2;
	output |= ((*input) & (1 << 2)) >> 2;
	output |= ((*input) & (1 << 3)) << 1;
	output |= ((*input) & (1 << 4)) << 3;
	output |= ((*input) & (1 << 5)) << 0;
	output |= ((*input) & (1 << 6)) >> 4;
	output |= ((*input) & (1 << 7)) >> 1;
	*input = output;
}

// Do left shift
void LS(unsigned char **key) {
	char tmp0 = (*key)[0];
	char tmp5 = (*key)[5];
	int i;
	for (i = 1; i < 5; i++) {
		(*key)[i-1] = (*key)[i];
		(*key)[i+4] = (*key)[i+5];
	}
	(*key)[4] = tmp0;
	(*key)[9] = tmp5;
}

// Convert string to char
unsigned char stoc(const unsigned char *str) {
	int i;
	unsigned char ch = 0;
	for (i = 0; i < 8; i++)
		ch |= ((str[i]-'0') << (7-i));
	return ch;
}

// Function F
unsigned char F(unsigned char r, unsigned char sk) {
	unsigned char ep = 0;
	ep |= ((r & (1 << 0)) << 7);
	ep |= ((r & (1 << 3)) << 3);
	ep |= ((r & (1 << 2)) << 3);
	ep |= ((r & (1 << 1)) << 3);

	ep |= ((r & (1 << 2)) << 1);
	ep |= ((r & (1 << 1)) << 1);
	ep |= ((r & (1 << 0)) << 1);
	ep |= ((r & (1 << 3)) >> 3);
	ep ^= sk;
	unsigned char epl = (ep >> 4) & 0x0F;
	unsigned char epr = ep & 0x0F;
	int r0 = ((epl & 8) >> 2) | (epl & 1);
	int c0 = ((epl & 4) >> 1) | ((epl & 2) >> 1);
	int r1 = ((epr & 8) >> 2) | (epr & 1);
	int c1 = ((epr & 4) >> 1) | ((epr & 2) >> 1);
	int p4l = s0[r0][c0];
	int p4r = s1[r1][c1];
	ep = ((p4l << 2) | p4r) & 0x0F;
	unsigned char p4 = 0;
	p4 |= (ep & (1 << 0)) << 2;
	p4 |= (ep & (1 << 1)) << 0;
	p4 |= (ep & (1 << 2)) << 1;
	p4 |= (ep & (1 << 3)) >> 3;
	return p4;
}

// Function fk
void fk(unsigned char *ch, const unsigned char sk) {
	unsigned char l, r;
	unsigned char fkch;
	l = ((*ch) >> 4) & 0x0F;
	r = (*ch) & 0x0F;
	fkch = F(r, sk);
	*ch = ((l ^ fkch) << 4) | r;
}

// Switch
void sw(unsigned char *ch) {
	unsigned char chl = ((*ch) >> 4) & 0x0F;
	*ch = ((*ch) << 4) | chl;
}

// Preparation
void prep(unsigned char *init_key, unsigned char *key1, unsigned char *key2) {
	unsigned char *key1bit, *key2bit;
	key1bit = (char*)malloc(8);
	key2bit = (char*)malloc(8);

	P10(&init_key);				// permute 10 bit initial key
	LS(&init_key);				// circular left shift
	P8(&key1bit, init_key);		// permute last 8 bit of result key to create key1bit
	LS(&init_key);				// circular left shift
	LS(&init_key);				// circular left shift
	P8(&key2bit, init_key);		// permute last 8 bit of result key to create key2bit
	*key1 = stoc(key1bit);		// convert key1bit to key1
	*key2 = stoc(key2bit);		// convert key2bit to key2
}

// Entry
void start(unsigned char *init_key, unsigned char *init_vector, unsigned char *original_file, unsigned char *result_file, int doEncrypt) {
	unsigned char key1, key2, vector, newvector, *buffer;
	FILE *org_file, *rst_file;
	uint32_t filelen;

	/* initialize variables */
	prep(init_key, &key1, &key2);
	vector = stoc(init_vector);

	org_file = fopen(original_file, "rb"); fseek(org_file, 0, SEEK_END);
	filelen = ftell(org_file); rewind(org_file);
	buffer = (unsigned char*)malloc((filelen+1) * sizeof(char));
	fread(buffer, filelen, 1, org_file);
	fclose(org_file);
	buffer[filelen] = '\0';

	/* encrypt or decrypt */
	int i;
	for (i = 0; i < filelen; i++) {
		unsigned char tmp = buffer[i];

		/* update vector */
		if (doEncrypt) tmp ^= vector;
		else newvector = tmp;

		IPbit(&tmp);
		doEncrypt ? fk(&tmp, key1) : fk(&tmp, key2);
		sw(&tmp);
		doEncrypt ?	fk(&tmp, key2) : fk(&tmp, key1);
		IPREVbit(&tmp);

		/* update vector */
		if (doEncrypt) vector = tmp;
		else {
			tmp ^= vector;
			vector = newvector;
		}

		buffer[i] = tmp;
	}
	rst_file = fopen(result_file, "wb");
	fwrite(buffer, filelen, 1, rst_file);
	fclose(rst_file);

}

int main(int argc, char**argv) {
	int doEncrypt = 1;
	unsigned char *init_key, *init_vector, *original_file, *result_file;

	/* check and read input */
	if (argc == 5) {
		init_key = argv[1];
		init_vector = argv[2];
		original_file = argv[3];
		result_file = argv[4];
	} else if (argc == 6) {
		doEncrypt = 0;
		init_key = argv[2];
		init_vector = argv[3];
		original_file = argv[4];
		result_file = argv[5];
	} else {
		fprintf(stderr, "Usage: %s [-d] <init_key> <init_vector> <original_file> <result_file>\n", argv[0]);
		return 1;
	}
	start(init_key, init_vector, original_file, result_file, doEncrypt);
	return 0;
}

