#pragma once

class MyIterator {
protected:

public:
    bool has_next();
    void next();
    void* current();
};

class MyIterableDataStructure {
protected:

public:
    MyIterator get_iterator();
};
