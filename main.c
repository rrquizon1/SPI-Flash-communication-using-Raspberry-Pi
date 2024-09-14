#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <linux/spi/spidev.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <gpiod.h>
#include "spi_data.h"
#include "spi.h"




struct gpiod_line *cs;



int main() {
    unsigned char data_read[g_iDataSize];
    unsigned int start_address = 0x000000; //start address where to write

	
    spi_init(3000,&cs);// 3000 means 3 MHz

    //Device ID read 	
    device_id();

  
    printf("\n");
    
    usleep(1);
    //Write Enable//
    write_enable();

    usleep(100);
    
    //Chip Erase

    chip_erase();
    usleep(100); 
       
    //busy checking
    SR_check();
    printf("Finished Erasing\n");

    
    usleep(1);
   
    //Write Sample Data
    printf("Writing Data....\n");
    write_data(g_pucDataArray,g_iDataSize,start_address );
    SR_check();
    
    //Read Sample Data Read
    read_data(data_read,g_iDataSize,start_address);

    
    verify_data(data_read, g_pucDataArray, g_iDataSize);
	

    rbpi_exit();
	
	
}
