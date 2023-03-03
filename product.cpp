#include "product.h"
#include <map>
#include <vector>

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

int Product::getProductPrice(){
    std::map<std::string, int> productsDatabase;
    productsDatabase["Bananas"] = 499;
    productsDatabase["Oranges"] = 800;
    productsDatabase["Milk"] = 315;
    if (productsDatabase.count(productName)>=1) {
        return productQuantity * productsDatabase[productName];
    } else {
        ::srand(time(nullptr));
        productsDatabase[productName] = (::rand() % 1000) + 1;
        return productQuantity * productsDatabase[productName];
    }
}
