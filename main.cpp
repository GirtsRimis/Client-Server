#include <iostream>

// UDP - fast, unprecise, does not wait for readiness
// TCP - creates a connections, checks package order with checksum, slower

// malloc() - function, c, no consturctor, retuns void* and NULL if error, manually need to calculate size
// new - class object, c++, has a consturctor, retuns exact data type and bad_alloc if error, size is calculated by compiler

// epoll - https://man7.org/linux/man-pages/man7/epoll.7.html for client-server file transfer
// https://medium.com/@chongye225/networking-with-c-cf15426cc270

// Low-Level Protocols:
// ICMP (Internet Control Message Protocol)
// ARP/RARP - a very silly protocol (Address Resolution Protocol) (Reverse Address Resolution Protocol)
// DNS (Domain Name System)
// RIP (Routing Information Protocol)
// OSPF (Open Shortest Path First)
// BGP (Border Gateway Protocol)
// DHCP (Dynamic Host Configuration Protocol)
// BootP (Bootstrap Protocol)
// TFTP (Trivial File Transfer Protocol) (UDP)
// PPP LCP --> TCP/IP (Point-to-Point Protocol) (Link Control Protocol)


bool is_big_endian(void)
{
    union {
        uint32_t i;
        char c[4];
    } bint = {0x01020304};

    return bint.c[0] == 1;
}

int main()
{
    std::cout << "Is big endian: " << is_big_endian() << " - 0 (false), 1 (true)\n";

    return 0;
}
