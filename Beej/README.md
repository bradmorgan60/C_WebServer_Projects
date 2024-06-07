Socket
- a way to speak to other programs using standard Unix file descriptors

File Descriptor
- an integer associated with an open file
- the file can be anything...from a network connection, FIFO, pipe, terminal, on-the-disk file, etc

- How do get the file descriptor
    - socket calls
        - socket() - the call to the socket system routine...returns socket descriptor
        - send() - send through socket descriptor
        - recv() - receive through socket descriptor
    - these calls are how we communicate through a socket

Types of Sockets
- Stream Sockets
    - Transmission Control Protocol (TCP) - enables all internet packets to be sent to the destination and in sequential order
    - used for web browsers and/or scenarios involving mission critical transmission of data
    - For reliable connection...connection-oriented protocol
- Datagram Sockets
    - User Datagram Protocol (UDP) - packets are not guaranteed
    - connectionless protocol...meaning that an open connection does not have to be maintained

Data Encapsulation
- How are packets handled when they traverse the internet?
- How is the OSI 7-Layer model utilized when a packet is moving from point A to B?
- How is a packet constructed? Why are these segments that make up a packet important? What is their use?


My Questions:
- How do DNS lookups work from a programming perspecitve?
    - Resolver Server
    - Root Servers
    - TLD Servers
    - Nameservers



