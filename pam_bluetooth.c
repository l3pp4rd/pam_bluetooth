#include <stdio.h>
#include <stdlib.h>
#include <security/pam_appl.h>
#include <security/pam_modules.h>

PAM_EXTERN int pam_sm_setcred( pam_handle_t *pamh, int flags, int argc, const char **argv ) {
  return PAM_SUCCESS;
}

PAM_EXTERN int pam_sm_acct_mgmt(pam_handle_t *pamh, int flags, int argc, const char **argv) {
  printf("Acct mgmt\n");
  return PAM_SUCCESS;
}

PAM_EXTERN int pam_sm_authenticate( pam_handle_t *pamh, int flags,int argc, const char **argv ) {
  char* mac = ""; // enter mac address of device, example: 80:82:2K:7D:B8:67
  char cmd[100] = "";
  snprintf(cmd, sizeof(cmd), "bluetoothctl connect %s > /dev/null 2>&1", mac);
  int status = system(cmd);
  if (status != 0) {
    // if we are able to connect means the mobile is near the laptop
    return PAM_IGNORE;
  } else {
    // disconnect since do not want to use mobile audio on laptop
    snprintf(cmd, sizeof(cmd), "bluetoothctl disconnect %s > /dev/null 2>&1", mac);
    system(cmd);
    return PAM_SUCCESS;
  }
}


