#ifndef _BMP_STRUCT_H_
#define _BMP_STRUCT_H_

#include <stdint.h>
#include <stdio.h>

struct __attribute__((packed)) bmp_header {
    uint16_t bfType;
    uint32_t bfileSize;
    uint32_t bfReserved;
    uint32_t bOffBits;
    uint32_t biSize;
    uint32_t biWidth;
    uint32_t biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    uint32_t biXPelsPerMeter;
    uint32_t biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
};

struct image {
    uint32_t width, height;
    struct pixel *data;
};

struct __attribute__((packed)) pixel {
    unsigned char b, g, r;
};

enum read_status {
    READ_OK = 0,
    READ_INVALID_BITS,
    READ_INVALID_HEADER,
    READ_ERR
};

enum write_status {
    WRITE_OK = 0,
    WRITE_ERR
};

enum read_status from_bmp(FILE* in, struct image *read);
enum write_status write_bmp(FILE* out, struct image *write);
struct image* rotate(struct image* const in, int32_t parameter);
struct bmp_header create_bmp_header(struct image *img);
void print_error_read(enum read_status status);
void print_error_write(enum write_status status);
size_t calculate_offset(uint64_t img_width);

#endif
