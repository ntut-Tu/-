#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define DEVICE "/dev/demo"

void control_led(int led_number, int state) {
    int fd = open(DEVICE, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device...");
        return;
    }

    // 假設IOCTL命令和LED控制的定義
    ioctl(fd, state, led_number);

    close(fd);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <LED number> <on/off>\n", argv[0]);
        return -1;
    }

    int led_number = atoi(argv[1]);
    int state = (strcmp(argv[2], "on") == 0) ? 1 : 0;

    control_led(led_number, state);

    return 0;
}
