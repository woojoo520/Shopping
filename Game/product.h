#ifndef PRODUCT_H
#define PRODUCT_H
/**
 * @file
 * @brief Created a product class, including id, name, seller's name, price, description, image src and tag
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
