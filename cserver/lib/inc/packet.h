#ifndef INTERFACE_H
#define INTERFACE_H

struct packet {
    int placeholder;
};

// TODO: Doc
struct packet packet_generate(int placeholder);
void packet_print(const struct packet *p);

#endif // INTERFACE_H