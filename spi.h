// data.h
#ifndef SPI_H
#define SPI_H

#define PAGE_SIZE 256 // Define the page size as 256 bytes

int configure_output(struct gpiod_line *line, const char *consumer, int value);
int spi_init(int spi_speed,struct gpiod_line **cs);
static int rbpi_ioctl(unsigned char *tx_buf, unsigned char *rx_buf, int len);
int rbpi_tx(unsigned char *buf, int bytes);
int rbpi_rx(unsigned char *buf, int bytes);
int rbpi_exit();
void SR_check();
void chip_erase();
void read_data(unsigned char *read_data, size_t data_size, unsigned int start_address);
void write_enable();
void write_data(const unsigned char *data, size_t length, unsigned int start_address);
void verify_data(const unsigned char *data_read,const unsigned char *data_written,int size);
void device_id();



#endif
