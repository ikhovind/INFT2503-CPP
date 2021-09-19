#include "commodity.hpp"

Commodity::Commodity(const std::string &name, unsigned int id, const double price) {
  this->name = name;
  this->id = id;
  this->price = price;
}

unsigned int Commodity::get_id() const {
  return id;
}

std::string Commodity::get_name() const {
  return this->name;
}

double Commodity::get_price() {
  return this->price;
}

double Commodity::get_price(double quantity) {
  return this->get_price() * quantity;
}

void Commodity::set_price(double newPrice) {
  this->price = newPrice;
}

double Commodity::get_price_with_sales_tax() {
  return this->get_price() * salesTax;
}

double Commodity::get_price_with_sales_tax(double quantity) {
  return this->get_price_with_sales_tax() * quantity;
}
