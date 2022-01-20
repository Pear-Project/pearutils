#include <stdio.h>
#include <stdlib.h>
#include <xdo.h>
#include <unistd.h>

int main() {
    xdo_t * x = xdo_new(":0.0");

    while(1) {
        printf("simulating Shift_L keypress\n");
        xdo_keysequence(x, CURRENTWINDOW, "Shift_L", 0);
        sleep(5);
    }

        return 0;
}
