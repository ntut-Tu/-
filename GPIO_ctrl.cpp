#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <iostream>
#include <cstring>
#include <thread>
#include <chrono>

using namespace std;



// unexport
int gpio_unexport(unsigned int gpio)
{
	int fd, len;
	char buf[64];

	fd = open("/sys/class/gpio/export", O_WRONLY);
	if (fd < 0)
	{
		perror("gpio/export");
		return fd;
	}

	len = snprintf(buf, sizeof(buf), "%d", gpio); // gpiobuf
	write(fd, buf, len);						// export (gpio)
	close(fd);									//
	return 0;
}

// export
int gpio_export(unsigned int gpio) // Xgpio
{
	int fd, len;
	char buf[64];
	fd = open("/sys/class/gpio/export", O_WRONLY);

	if (fd < 0)
	{
		perror("gpio/export");
		return fd;
	}
	len = snprintf(buf, sizeof(buf), "%d", gpio); // gpiobuf
	write(fd, buf, len);						  // export (gpio)
	close(fd);

	return 0;
}

// direcion
int gpio_set_dir(unsigned int gpio, string dirStatus) // gpiooutsin
{
	int fd;
	char buf[64];

	snprintf(buf, sizeof(buf), "/sys/class/gpio/gpio%d/direction", gpio);

	fd = open(buf, O_WRONLY);
	if (fd < 0)
	{
		perror("gpio/direction");
		return fd;
	}

	if (dirStatus == "out")
		write(fd, "out", 4);
	else
		write(fd, "in", 3);
	close(fd);

	return 0;
}

// value
int gpio_set_value(unsigned int gpio, int value)
{
	int fd;
	char buf[64];

	snprintf(buf, sizeof(buf), "/sys/class/gpio/gpio%d/value", gpio);

	fd = open(buf, O_WRONLY);
	if (fd < 0)
	{
		perror("gpio/direction");
		return fd;
	}

	if (value == 0)
		write(fd, "0", 2);
	else
		write(fd, "1", 2);

	close(fd);
	return 0;
}



int main(int argc,char *argv[]){
    freopen("output.txt", "a", stdout);
    fprintf(stdout,"Main START\n");
    if(strcmp(argv[1],"LED1")==0){
        if(strcmp(argv[2],"ON")==0){
            fprintf(stdout,"LED1 ON\n");
            gpio_export(466);
            gpio_set_dir(466,"out");
            gpio_set_value(466,1);
        }else if(strcmp(argv[2],"OFF")==0){
            fprintf(stdout,"LED1 OFF\n");
            gpio_set_value(466,0);
            gpio_unexport(466);
        }
    }
    if(strcmp(argv[1],"LED2")==0){
        if(strcmp(argv[2],"ON")==0){
            fprintf(stdout,"LED2 ON\n");
            gpio_export(397);
            gpio_set_dir(397,"out");
            gpio_set_value(397,1);
        }else if(strcmp(argv[2],"OFF")==0){
            fprintf(stdout,"LED2 OFF\n");
            gpio_set_value(397,0);
            gpio_unexport(397);
        }
    }
    if(strcmp(argv[1],"LED3")==0){
        if(strcmp(argv[2],"ON")==0){
            fprintf(stdout,"LED3 ON\n");
            gpio_export(255);
            gpio_set_dir(255,"out");
            gpio_set_value(255,1);
        }else if(strcmp(argv[2],"OFF")==0){
            fprintf(stdout,"LED3 OFF\n");
            gpio_set_value(255,0);
            gpio_unexport(255);
        }
    }
    if(strcmp(argv[1],"LED4")==0){
        if(strcmp(argv[2],"ON")==0){
            fprintf(stdout,"LED4 ON\n");
            gpio_export(481);
            gpio_set_dir(481,"out");
            gpio_set_value(481,1);
        }else if(strcmp(argv[2],"OFF")==0){
            fprintf(stdout,"LED4 OFF\n");
            gpio_set_value(481,0);
            gpio_unexport(481);
        }
    }
    if(strcmp(argv[1],"Mode_Shine")==0){
        int max = std::stoi(argv[2]);
        gpio_export(466);
        gpio_export(397);
        gpio_export(255);
        gpio_export(481);
        gpio_set_dir(466,"out");
        gpio_set_dir(397,"out");
        gpio_set_dir(255,"out");
        gpio_set_dir(481,"out");
        fprintf(stdout,"Mode_Shine START!\n");
        fprintf(stdout,"LED1 OFF\n");
        fprintf(stdout,"LED2 OFF\n");
        fprintf(stdout,"LED3 OFF\n");
        fprintf(stdout,"LED4 OFF\n");
        for(int i=0;i<max;i++){
            gpio_set_value(255,0);
            gpio_set_value(481,0);   
            gpio_set_value(466,1);
            gpio_set_value(397,1);
            fprintf(stdout,"LED1 ON\n");
            fprintf(stdout,"LED2 ON\n");
            fprintf(stdout,"LED3 OFF\n");
            fprintf(stdout,"LED4 OFF\n");
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            gpio_set_value(466,0);
            gpio_set_value(397,0);
            gpio_set_value(255,1);
            gpio_set_value(481,1);
            fprintf(stdout,"LED1 OFF\n");
            fprintf(stdout,"LED2 OFF\n");
            fprintf(stdout,"LED3 ON\n");
            fprintf(stdout,"LED4 ON\n");
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
        gpio_set_value(255,0);
        
        gpio_set_value(481,0);
        
        gpio_set_value(466,0);
        
        gpio_set_value(397,0);
        fprintf(stdout,"LED1 OFF\n");
        fprintf(stdout,"LED2 OFF\n");
        fprintf(stdout,"LED3 OFF\n");
        fprintf(stdout,"LED4 OFF\n");
        gpio_unexport(255);
        gpio_unexport(481);
        gpio_unexport(466);
        gpio_unexport(397);
        fprintf(stdout,"Mode_Shine END!\n");
    }
    fflush(stdout);
    return 0;
}
