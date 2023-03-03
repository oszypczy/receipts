#pragma once
#include <string>

class Product {
    private:
        std::string productName;
        int productQuantity;
    public:
        Product(std::string name, int quantity);
        std::string getProductName();
        int getProductQuantity();
        void setProductName(std::string newName);
        void setProductQuantity(int newQuantity);
};