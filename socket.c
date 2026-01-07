#include <stdio.h>
#include <ifaddrs.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <unistd.h>
#include <string.h>

int main() {
    struct ifaddrs *ifaddr, *ifa;
    int sock;
    struct ifreq ifr;


 sock = socket(AF_INET, SOCK_DGRAM, 0);// Create socket 


    getifaddrs(&ifaddr);// Get network interfaces
    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr == NULL)
            continue;


        if (ifa->ifa_addr->sa_family == AF_INET) {// Check for IPv4 address
            struct sockaddr_in *sa;
            sa = (struct sockaddr_in *)ifa->ifa_addr;
            printf("Interface Name : %s\n", ifa->ifa_name);
            printf("IP Address     : %s\n", inet_ntoa(a->sin_addr));


            strcpy(ifr.ifr_name, ifa->ifa_name);// Get MAC address
            ioctl(sock, SIOCGIFHWADDR, &ifr);
            printf("MAC Address    : ");
            for (int i = 0; i < 6; i++) {
                printf("%02X", (unsigned char)ifr.ifr_hwaddr.sa_data[i]);
                if (i != 5) printf(":");
            }
            printf("\n\n");
        }
    }
    freeifaddrs(ifaddr);
    close(sock);
    return 0;
}

