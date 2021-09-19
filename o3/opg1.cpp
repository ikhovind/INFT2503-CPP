const double pi = 3.141592;

class Circle {

public:
  //referanse som parameter, ikke nødvendig, men tenkte det var fint
  //Circle med stor C som i klassenavnet
  Circle(const double &radius_);
  int get_area() const;
  double get_circumference() const;
  // private skal settes slik
private:
  const double radius;
  //semikolon på slutten av deklarasjon
};

// ==> Implementasjon av klassen
// public og private settes i deklarasonen, ikke her
// radius_ er parameteret, radius skal være utenfor parantesene
Circle::Circle(const double &radius_) : radius(radius_) {}
// deklarasjonen sier at denne må være const
int Circle::get_area() const {
  return pi * radius * radius;
}

// manglet returtype
double Circle::get_circumference() const {
  // circumference manglet datatype
  double circumference = 2.0 * pi * radius;
  return circumference;
}