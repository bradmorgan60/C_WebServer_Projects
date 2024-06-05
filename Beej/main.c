#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

/* 
 Node -> host name to connect to - an IP address
 Service -> port number...found on IANA port list
 Hints -> parameter that points to a struct addrinfo that was 
*/

int getaddrinfo(const char *node,
                const char *service,
                const struct addrinfo *hints,
                struct addrinfo **res
                ); 

int main() {
    return 0;
}