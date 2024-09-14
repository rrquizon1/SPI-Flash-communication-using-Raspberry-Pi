This is a sample project that communicates to Raspberry Pi using Raspberry Pi 5. 

This example uses lgpiod library so make sure to install it: sudo apt-get install gpiod libgpiod-dev.

This project uses Windbond SPI flash W25Q128. You can check this device's datasheet [here](https://www.winbond.com/hq/product/code-storage-flash-memory/serial-nor-flash/?__locale=en&partNo=W25Q128FV).

The following commands from the datasheet are used for this example:

DeviceID read: 90h

Write Enable: 06h

Chip Erase: C7h

Read Status Register: 05h

Page Program: 02h

Read Data: 03h

Steps to run the project:
1. Compile the project by running the makefile
2. Run the executable generated ./rhodz_SPI


Keypoints to ensure that you have a successful write and read operation:
1. Always use write enable (06h) comamnd every after erase or page program command. This example did not use the nonvolatie bit for write enable. If you wish to use the nonvolatile bit, consult the datasheet.
2. Read status Register and check busy bit after Erase and Page Program command to make sure that the previous operation is finished.


This example uses Chip Erase(C7h) command which erases all the contents of the SPI flash. Sector Erase command could also be used to erase only parts of the SPI flash. To do this, consult the device datasheet.


You can modify the data to be written on the SPI flash by modifying g_pucDataArray at spi_data.c and changing g_iDataSize with the appropriate number of bytes in the array:
![image](https://github.com/user-attachments/assets/cfea8103-1a11-460e-89c4-1f1aca5ab67e)

See below for sample run:
![image](https://github.com/user-attachments/assets/0b2ddc8e-3e50-4efd-bc4e-47d47500cae2)

The console will print out if the verification is successful or if there are error in the verification. The error in the sample run above was a forced error by doing only verification and modifying the original array.
