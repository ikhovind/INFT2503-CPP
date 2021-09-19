//
// Created by ingebrigt on 02.09.2021.
//

#ifndef O3_COMMODITY_H
#define O3_COMMODITY_H
#pragma once
#include <string>

const double salesTax = 1.25;

class Commodity {
  private:
    std::string name;
    unsigned int id;
    double price;

  public:
    Commodity(const std::string &name, const unsigned int id, const double price);
    std::string get_name() const;
    unsigned int get_id() const;
    double get_price();
    double get_price(const double quantity);
    void set_price(double newPrice);
    double get_price_with_sales_tax();
    double get_price_with_sales_tax(const double quantity);
};

#endif // O3_COMMODITY_H
