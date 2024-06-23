My network:
DHCP Configuration
IP address: 192.168.1.69  // IP address that was issued by the ISP (AT&T)
Subnet mask: 255.255.255.0
Router: 192.168.1.254
Client ID: 
IPv6: Automatic
IPv6 IP address: none
IPv6 Router: none
Wi-Fi ID: ac:bc:32:98:88:9d


Essential Header Files:
<sys/types.h>
Contains definitions for data types used in system calls. Often included implicitly by other headers, but good practice to include explicitly.

<sys/socket.h>
Defines socket functions and data structures, such as socket(), bind(), connect(), listen(), accept(), and the sockaddr structure.

<netinet/in.h>
Contains constants and structures needed for internet domain addresses, such as the sockaddr_in structure and address family constants like AF_INET.

<arpa/inet.h>
Provides functions for manipulating numeric IP addresses, such as inet_pton() and inet_ntop().

<unistd.h>
Declares miscellaneous symbolic constants and types, and declares miscellaneous functions, including close() for closing sockets.


Layer 3 - Network Layer
- Requires the Physical and Data Link layer in order to operate
- This layer is responsible for transmitting packets from source to destination
- Layer 3 provides the ability to span multiple layer 2 networks
- Inter-networking is the process of spanning transmitting information between multiple layer 2 networks. Layer 3 performs this

Capabilities
- IP (Internet Protocol)
- IP Addresses / cross-networking addresses assigned to devices
- routing
- server has an IP addresses. Requests are sent via internet
- IP packets are moved step by step from source to destination via intermediate networks
- These IP packets are encapsulated in different frames along the way

IPv4 and IPv6 addresses
- IPv4 -> 192.0.2.111
each IPv4 address is made of of 32-bits, 4 octets. Each octet has 8 bits
2^32 is a little of 4 billion addresses

IPv6 addresses were created to solve the problem of the growing shortage of IPv4 addresses
Vince Cerf is credited for the creation of the IPv6 address

- IPv6 -> 2001:0db8:c9d2:aee5:73e3:934a:a5ae:9551
- 128 bits make up an IPv6 address


Subnets
Ports
- a 16-bit number that's like the local address for a connection
- IP address -> street number of a hotel
- Port -> the room number
- Another example:
    - I have one IP address
        - My role
            - Handle incoming mail
            - web services
        - different services on the internet have different well-known port numbers
    Ports:
        - HTTP - 80
        - HTTPS - 443
        - Telnet - 23
    Research "Big IANA Port List"

Network Classes
- Class A
- Class B
- Class C


Terms:
- Loopback address
