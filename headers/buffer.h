#ifndef BUFFER_H
#define BUFFER_H
#include <QString>

class Buffer{
public:
    Buffer() = default;
    QString age;
    QString full_name;
    QString salary;
    ssize_t n{0};
};

extern Buffer bf;

#endif // BUFFER_H
