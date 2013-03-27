#include <iostream>
#include <stdexcept>

int gcd(int a, int b) {
    int c;
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

class Rational {
    int numerator_;
    int denominator_;

    void normalize() {
        numerator_ = numerator();
        denominator_ = denominator();
    }
public:
    Rational(int numerator = 0, int denominator = 1) : numerator_(numerator), denominator_(denominator) {
    }

    int numerator() const {
        int d = gcd(numerator_, denominator_);
        if (d == 0) {
            throw std::logic_error("division by zero");
        }
        return numerator_ / d;
    }

    int denominator() const {
        int d = gcd(numerator_, denominator_);
        if (d == 0) {
            throw std::logic_error("division by zero");
        }
        return denominator_ / d;
    }

    Rational& operator += (const Rational& q) {
        numerator_ = numerator_ * q.denominator_ + q.numerator_ * denominator_;
        denominator_ *= q.denominator_;
        normalize();
        return *this;
    }

    Rational& operator -= (const Rational& q) {
        numerator_ = numerator_ * q.denominator_ - q.numerator_ * denominator_;
        denominator_ *= q.denominator_;
        normalize();
        return *this;
    }

    Rational& operator *= (const Rational& q) {
        numerator_ *= q.numerator_;
        denominator_ *= q.denominator_;
        normalize();
        return *this;
    }

    Rational& operator /= (const Rational& q) {
        numerator_ *= q.denominator_;
        denominator_ *= q.numerator_;
        normalize();
        return *this;
    }

    Rational operator + (const Rational& q) const {
        Rational result(*this);
        return result += q;
    }

    Rational operator - (const Rational& q) const {
        Rational result(*this);
        return result -= q;
    }

    Rational operator * (const Rational& q) const {
        Rational result(*this);
        return result *= q;
    }

    Rational operator / (const Rational& q) const {
        Rational result(*this);
        return result /= q;
    }

    bool operator == (const Rational& other) const {
        return numerator_ * other.denominator_ == other.numerator_ * denominator_;
    }

    bool operator <= (const Rational& other) const {
        return numerator_ * other.denominator_ <= other.numerator_ * denominator_;
    }

    bool operator >= (const Rational& other) const {
        return numerator_ * other.denominator_ >= other.numerator_ * denominator_;
    }

    bool operator > (const Rational& other) const {
        return !(*this <= other);
    }

    bool operator < (const Rational& other) const {
        return !(*this >= other);
    }

    bool operator != (const Rational& other) const {
        return !(*this == other);
    }

    Rational& operator ++ () {
        return *this += 1;
    }

    Rational& operator ++ (int) {
        Rational result(*this);
        *this += 1;
        return result;
    }

    Rational& operator -- () {
        return *this -= 1;
    }

    Rational& operator -- (int) {
        Rational result(*this);
        *this -= 1;
        return result;
    }

    Rational operator + () const {
        return *this;
    }

    Rational operator - () const {
        Rational result(*this);
        result.numerator_ *= -1;
        return result;
    }

    friend std::ostream& operator << (std::ostream& out, const Rational& q);
};

std::ostream& operator << (std::ostream& out, const Rational& q) {
    out << q.numerator_ << ' ' << q.denominator_;
    return out;
}

int main() {
    Rational q(5, 2), r(1, 3), p(2, 1);
    Rational x, y, z;
    x = y = z = q;
    std::cout << x << std::endl;
    x += r;
    std::cout << x << std::endl;
    y *= q;
    std::cout << y << std::endl;
    x++;
    std::cout << x << std::endl;
    x += Rational(1, 6);
    std::cout << x << std::endl;
    std::cout << x.normalize() << std::endl;
    Rational u(0, 0);
    std::cout << u.denominator() << std::endl;

}
