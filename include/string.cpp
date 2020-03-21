// Copyright 2020 Kavykin Andrey Kaviandr@yandex.ru
#include "string.hpp"

String::String() {
    Data = nullptr;
    size = 0;
}

String::~String() {
    delete[] Data;
}

String::String(const String &rhs) {
    size = rhs.size;
    Data = new char[size];
    for (size_t i = 0; i < size; ++i) {
        Data[i] = rhs.Data[i];
    }
}

String::String(const char *data) {
    size = 0;
    const char *str = data;
    unsigned int i = 0;
    while (str[i] != '\000') {
        ++size;
        ++i;
    }
    this->Data = new char[size];
    for (i = 0; i < size; i++)
        Data[i] = str[i];
}

String &String::operator=(const String &rhs) {
    if (&rhs != this) {
        size = rhs.size;
        Data = new char[size];
        for (unsigned int i = 0; i < size; ++i)
            Data[i] = rhs.Data[i];
    }
    return *this;
}

String &String::operator+=(const String &rhs) {
    char *new_data = new char[size];
    size_t new_size = size + rhs.size;
    for (unsigned int i = 0; i < size; ++i) {
        new_data[i] = Data[i];
    }
    delete[]Data;
    size = new_size;
    Data = new char[size];
    for (unsigned int i = 0; i < size - rhs.size; ++i) {
        Data[i] = new_data[i];
    }
    for (unsigned int i = size - rhs.size,
                 j = 0; i < size; ++i, ++j) {
        Data[i] = rhs.Data[j];
    }
    return (*this);
}

String &String::operator*=(unsigned int m) {
    String copy_str(*this);
    for (unsigned int i = 1; i < m; ++i)
        *this += copy_str;
    return *this;
}


bool String::operator==(const String &rhs) const {
    if (size != rhs.size)
        return false;
    else {
        for (unsigned int i = 0; i < size; ++i) {
            if (Data[i] != rhs.Data[i])
                return false;
        }
    }
    return true;
}

bool String::operator<(const String &rhs) const {
    if (size < rhs.size)
        return true;
    if (size > rhs.size)
        return false;
    for (unsigned int i = 0; i < size; ++i) {
        if (Data[i] < rhs.Data[i])
            return true;
    }
    return false;
}

size_t String::Find(const String &substr) const {
    unsigned int i = 0;
    unsigned int j = 0;
    while (i < size && j < substr.size) {
        while (Data[i] != substr.Data[0] && i < size) {
            ++i;
        }
        unsigned int t = i;
        while ((Data[i] == substr.Data[j]) && i < size) {
            ++i;
            ++j;
        }
        if (j == substr.size)
            return t;
        ++i;
        j = 0;
    }
    return -1;
}

void String::Replace(char oldSymbol, char newSymbol) {
    for (unsigned int i = 0; i < size; ++i) {
        if (Data[i] == oldSymbol)
            Data[i] = newSymbol;
    }
}

size_t String::Size() const {
    return size;
}

bool String::Empty() const {
    return (size == 0);
}

char String::operator[](size_t index) const {
    return Data[index];
}

char &String::operator[](size_t index) {
    return Data[index];
}

void String::RTrim(char symbol) {
    unsigned int i = 1;
    while (Data[size - i] == symbol)
        ++i;
    if (i > 0) {
        size_t new_size = size - i + 1;
        char *new_str = new char[new_size];
        for (unsigned int j = 0; j < new_size; ++j) {
            new_str[j] = Data[j];
        }
        delete[]Data;
        Data = new_str;
        size = new_size;
    } else return;
}

void String::LTrim(char symbol) {
    unsigned int i = 0;
    while (Data[i] == symbol)
        ++i;
    if (i > 0) {
        size_t new_size = size - i;
        char *new_str = new char[new_size];
        for (unsigned int j = 0; j < new_size; ++j) {
            new_str[j] = Data[j + i];
        }
        delete[]Data;
        Data = new_str;
        size = new_size;
    } else return;
}

void String::swap(String &oth) {
    char *copy_str = Data;
    size_t copy_size = size;
    size = oth.size;
    Data = oth.Data;
    oth.size = copy_size;
    oth.Data = copy_str;
}

std::ostream &operator<<(std::ostream &out, const String &str) {
    for (unsigned int i = 0; i < str.size; ++i)
        out << str[i];
    return out;
}

String operator+(const String &a, const String &b) {
    String str(a);
    str += b;
    return str;
}

String operator*(const String &a, unsigned int b) {
    String str(a);
    str *= b;
    return str;
}

bool operator!=(const String &a, const String &b) {
    if (a.Size() != b.Size()) {
        return true;
    }
    if (a.Size() == b.Size()) {
        for (unsigned int i = 0; i < a.Size(); ++i) {
            if (a[i] == b[i])
                return false;
        }
    }
    return true;
}

bool operator>(const String &a, const String &b) {
    for (unsigned int i = 0; i < a.Size() && i < b.Size(); ++i) {
        if (a[i] <= b[i])
            return false;
        if (a[i] > b[i])
            return true;
    }
    return a.Size() >= b.Size();
}
