//
// Created by developer on 2019/9/4.
//

#include "Item.h"

Color Item::getColor() const {
    return color;
}

void Item::setColor(Color color) {
    Item::color = color;
}

int Item::getValue() const {
    return value;
}

void Item::setValue(int value) {
    Item::value = value;
}

Item::Item(int value) : value(value) {}
