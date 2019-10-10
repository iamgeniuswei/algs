//
// Created by developer on 2019/9/4.
//

#ifndef ALGS_ITEM_H
#define ALGS_ITEM_H

#include <iostream>
using namespace std;

enum class Color{
    normal,
    cmp,
    cur,
    swap,
    sorted
};
class Item {
private:
    Color color = Color::normal;
    int value = 0;
public:
    Item(int value);

    Color getColor() const;

    void setColor(Color color);

    int getValue() const;

    void setValue(int value);
    Item(const Item& other)
    {
        this->value = other.value;
        this->color = other.color;
    }

    Item& operator=(const Item& other)
    {
        this->value = other.value;
        this->color = other.color;
        return *this;
    }
    Item& operator=(const Item&& other)
    {
        this->value = other.value;
        this->color = other.color;
        return *this;
    }

    bool operator==(const Item& other)
    {
        return this->value == other.value;
    }
    bool operator >(const Item& other)
    {
        return this->value > other.value;
    }
    bool operator <(const Item& other)
    {
        return this->value < other.value;
    }

    bool operator >=(const Item& other)
    {
        return this->value >= other.value;
    }

    bool operator <=(const Item& other)
    {
        return this->value <= other.value;
    }
    friend ostream& operator <<(ostream& out, Item& item)
    {
        out << item.value;
    }
};


#endif //ALGS_ITEM_H
