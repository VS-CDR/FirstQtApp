#ifndef BUFFER_H
#define BUFFER_H
#include <QString>

class Buffer{
public:
    Buffer();
    QString age;
    QString full_name;
    QString salary;
    unsigned n;
};
extern Buffer bf;
#endif // BUFFER_H
