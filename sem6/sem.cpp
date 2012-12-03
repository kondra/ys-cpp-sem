
/*
class C {
  private:

  protected:

  public:
    double d;

};

//private by default
class D: public C {

};
*/
/*
class C {
  protected:
    void f() {

    }
};

class D: public C {
  public:
    using C::f; //так станет видно

};

int main() {
  D d;
  d.f();//не видно
}  */

class Figure {
  protected:
    int Colour;

  public:
    void Draw() const;

};

class Ellips: public Figure {
  protected:
};

class Circle: public Figure {
  protected:
    double x, y;
    double Radius;
};

class Triangle: public Figure {
  public:
    //выберем из figure лучший вариант
    using Figure::Draw;
  protected:
    double X1, Y1, X2, Y2, X3, Y3;
    // в самом конце убъется по protected
    void Draw(double a = 0.0);
  private:
    int Draw(const std::vector<int>& v);
};

class RightTriangle: public Triangle {
  protected:
};

int main() {
  RightTriangle tr;
  tr.Draw();
}
