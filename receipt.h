#pragma once
#include <vector>
#include "product.h"

class Receipt {
    private:
        std::vector<Product> productList;
    public:
        Receipt(std::vector<Product> newProductList);
        std::vector<Product> getProductList();
        std::string getDate();
};