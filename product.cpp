#include "product.h"

Product::Product(std::string name, int quantity) {
    productName = name;
    productQuantity = quantity;
}

std::string Product::getProductName() {
    return productName;
}

int Product::getProductQuantity() {
    return productQuantity;
}

void Product::setProductName(std::string newName) {
    productName = newName;
}

void Product::setProductQuantity(int newQuantity) {
    productQuantity = newQuantity;
}
