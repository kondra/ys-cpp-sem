#include <iostream>
#include <map>

/*
class Temp {
  void f();
};
class Temp2: C, Temp {
};
*/

void f(); //declaration

void f() {
} // definition

inline f() {
}

class C; //declaration

class C {
  void g();
};//declaration

class C::g() {
}//definition

//фабрика

typedef Shape * (*TCreator)();
typedef std::map<int, TCreator> TRegistry;

TRegistry& GetRegistry() {
  static TRegistry registry;
  return registry;
}

const int
  iLine = 1,
  iCircle = 
  2,
  iTriangle = 3;

class Shape {
public:
  template<typename T>
  static Shape * Create() {
    return new T;
  }
  virtual void Draw() const = 0;
  virtual ~Shape() {}
};

class Line: public Shape {
public:
  void Draw() const {}
  static bool isRegistered;
};

bool Line::isRegistered = GetRegistry().insert(std::make_pair(iLine, Shape::Create<Line>)).second;

class Circle: public Shape {
public:
  static Circle * Create() {
    return new Circle;
  }
  void Draw() const {}
};

class Triangle: public Shape {
public:
  static Triangle * Create() {
    return new Triangle;
  }
  void Draw() const {}
};

Shape * CreateObject(int id) {
  auto iter = Registry.find(id);
  if (iter != Registry.end()) {
    return (iter->second)();
  } else {
    return 0;
  }

  /*
  switch (id) {
    case iLine:
      return new Line;
    case iTriangle:
      return new Triangle;
    case iCircle:
      return new Circle;
  }
  */
}

int main() {
  return 0;
}
