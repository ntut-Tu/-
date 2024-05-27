#include <stdio.h>
#include <string>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define DEVICE "/dev/demo"

void control_led(unsigned int led_number, std::string state) {
    int fd = open(DEVICE, O_WRONLY);
    if (fd < 0) {
        perror("gpio error");
        return;
    }
    char buf[10]={0};
    if(state == "on"){
        strcpy(buf,(to_string(led_number)+"1").c_str());
    }else{
        strcpy(buf,(to_string(led_number)+"0").c_str());
    }
    printf("%s\n",buf);
    // 假設IOCTL命令和LED控制的定義
    write(fd,buf,5);
    close(fd);
    return;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <LED number> <on/off>\n", argv[0]);
        return -1;
    }
    unsigned int led_number = atoi(argv[1]);

    control_led(led_number, argv[2]);

    return 0;
}