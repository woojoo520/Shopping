#ifndef PRODUCT_H
#define PRODUCT_H
/**
 * @file product.h
 * @author Meng Yeqing
 * @brief 
 * @version 0.1
 * @date 2019-12-15
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <QString>

class Product
{
public:
    Product();
    QString product_id;
    QString seller_name;
    int state;
    float price;
    QString description;
    QString src;
    QString tag;
};

#endif // PRODUCT_H
