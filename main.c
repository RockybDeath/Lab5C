#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "bmp_struct.h"

int main(){
    FILE* in, * out;
    struct image source_img;

    in = fopen("./lights.bmp", "rb");
    if(in == NULL) {
        puts("Can't open file");
        return 0;
    }
    else{
        enum read_status statusRead = from_bmp(in, &source_img);
        rotate(&source_img, 90);
        if(statusRead == READ_OK){
            out = fopen("./red.bmp", "wb");
            if(in == NULL) {
                puts("Can't open file");
                return 0;
            }
            enum write_status statusWrite = write_bmp(out, &source_img);
            print_error_write(statusWrite);
        } else{
            print_error_read(statusRead);
        }
    }
    fclose(in);
    fclose(out);
    return 0;
}
