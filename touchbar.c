// gcc -W -Wall -o touchbar touchbar.c 
// sudo ./touchbar 1

#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/usbdevice_fs.h>
#include <linux/usb/ch9.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void send_usb_control_message(int fd, struct usbdevfs_ctrltransfer* urb) {
    int rc = ioctl(fd, USBDEVFS_CONTROL, urb);
    if (rc < 0) {
        perror("sending usb-control");
        exit(-1);
    }
}

int usage(char *argv[]) {
    fprintf(stderr, "Usage: %s [-d <device>] <command>\n", argv[0]);
    fprintf(stderr, "    <device> defaults to /dev/bus/usb/001/002\n");
    fprintf(stderr, "    <command> is one of:\n");
    fprintf(stderr, "      0  - esc only\n");
    fprintf(stderr, "      1  - function keys\n");
    fprintf(stderr, "      2  - special keys\n");
    fprintf(stderr, "      3  - touchbar off\n");
    return EXIT_FAILURE;
}

int main(int argc, char *argv[]) {
    unsigned char cmd2Data[] = { 0 };
    char *dev_path = "/dev/bus/usb/001/002";
    int arg_off;
    int fd;
    int cmd;
    struct usbdevfs_ctrltransfer urb;

    // parse args: [-d <device>] <cmd>
    arg_off = 1;

    if (argc > arg_off + 1 && strcmp(argv[arg_off], "-d") == 0) {
        dev_path = argv[arg_off + 1];
        arg_off += 2;
    }

    if (argc < arg_off + 1) {
        return usage(argv);
    }

    cmd = atoi(argv[arg_off]);
    arg_off++;

    if (cmd < 0) {
        return usage(argv);
    }

    // open usb device
    fd = open(dev_path, O_RDWR);
    if (fd == -1) {
        perror(argv[1]);
        return EXIT_FAILURE;
    }

    // run command
    memset(&urb, 0, sizeof (urb));
    urb.timeout = 5000; /* in milliseconds */

    cmd2Data[0] = cmd;
    urb.bRequestType = USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE; // 0x40
    urb.bRequest = USB_REQ_SET_CONFIGURATION;
    urb.wValue = 0x0302;
    urb.wIndex = 0x0002;
    urb.data = cmd2Data;
    urb.wLength = sizeof(cmd2Data);

    send_usb_control_message(fd, &urb);

    // clean up
    close(fd);

    return EXIT_SUCCESS;
}
