# Bluetooth authentication PAM module

Simple, low effort PAM module to use a bluetooth device to authenticate.
No security implications have been considered. Tested on Ubuntu 24.04.

The device needs to be paired for this module to work.
The module will be ignored if the device is not found, and other authentication method can be used.
When device is paired, run command to make it trusted so it connects automatically.

Improvements are welcome.

# Usage

Enter the MAC address of the device within the double quotes on **pam_bluetooth.c**

Build the module using the following commands.

    gcc -fPIC -fno-stack-protector -c pam_bluetooth.c
    sudo ld -x --shared -o /usr/lib/x86_64-linux-gnu/security/pam_bluetooth.so pam_bluetooth.o
    sudo chmod 644 /usr/lib/x86_64-linux-gnu/security/pam_bluetooth.so

Add the following line at the top of the relevant config files in /etc/pam.d to use the module to authenticate.

    auth sufficient pam_bluetooth.so

For eg. /etc/pam.d/i3lock for i3 lockscreen, /etc/pam.d/sudo for sudo.


