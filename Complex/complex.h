#ifndef complex_H
#define complex_H
#include <string>
#include <sstream>
#include <iostream>

template<typename T> class complex
{
public:
    //   Constructors
    complex<T>();
	// ~complex<T>();
       
    // member variables
    complex<T>(T re, T im);
    complex<T>(const complex<T>& val);

    // member functions
    int getReal() const;
    int getImaginary() const;
    void putReal(int re);
    void putImaginary(int im);
    std::string toString() const;
    std::string intToString(int val);

    // Overloaded 
    complex<T>& operator=(const complex<T>& );

    //Overloaded Addition Operator
    friend complex<T> operator+(const complex<T>& lhs, const complex<T>& rhs);
    friend complex<T> operator+(const complex<T>& lhs, const complex<T>& rhs) {
        complex<T> temp;
        temp.putReal(lhs.getReal() + rhs.getReal());
        temp.putImaginary(lhs.getImaginary() + rhs.getImaginary());
        return temp;
    }
    
    //Overloaded Subtraction Operator
    friend complex<T> operator-(const complex<T>& lhs, const complex<T>& rhs);
    friend complex<T> operator-(const complex<T>& lhs, const complex<T>& rhs) {
        complex<T> minus;
        minus.putReal(lhs.getReal() - rhs.getReal());
        minus.putImaginary(lhs.getImaginary() - rhs.getImaginary());
        return minus;
    }

    //Overloaded Mulitiplication Operator
    friend complex<T> operator*(const complex<T>& lhs, const complex<T>& rhs);
    friend complex<T> operator*(const complex<T>& lhs, const complex<T>& rhs) {
        complex<T> multiply;
        multiply.putReal(lhs.getReal() * rhs.getReal() - lhs.getImaginary() * rhs.getImaginary());
        multiply.putImaginary(lhs.getReal() * rhs.getImaginary() + lhs.getImaginary() * rhs.getReal());
        return multiply;
    }

    //Overloaded Division Operator
    friend complex<T> operator/(const complex<T>& lhs, const complex<T>& rhs);
    friend complex<T> operator/(const complex<T>& lhs, const complex<T>& rhs) {
        complex<T> divide(lhs);
        int squareSum = rhs._re * rhs._re + rhs._im * rhs._im;
        divide._re = (lhs._re * rhs._re + lhs._im * rhs._im) / squareSum;
        divide._im = (lhs._im * rhs._re - lhs._re * rhs._im) / squareSum;
        return divide;
    }


    //Overloaded Equality Operator
    friend bool operator==(const complex<T> &lhs, const complex<T>& rhs);
    friend bool operator==(const complex<T> &lhs, const complex<T>& rhs)
    {
        return rhs.getReal() == lhs.getReal() && rhs.getImaginary()== lhs.getReal();
    }

    //Overloaded Inequality Operator
    friend bool operator!=(const complex<T>& lhs, const complex<T>& rhs);
    friend bool operator!=(const complex<T>& lhs, const complex<T>& rhs)
    {
        return rhs.getReal() != lhs.getReal() || rhs.getImaginary() != lhs.getReal();
    }

     
    template<typename U>
    friend std::ostream& operator<<(std::ostream& out, const complex<U>& complex);
    template<typename U>
    friend std::istream& operator>> (std::istream& is, complex<U>& complex);

private:
	T _re;
	T _im;
};


// Default constructor
template<typename T>
complex<T>::complex() {
    _re = 0;
    _im = 0;
}
template<typename T>
complex<T>::complex(T re, T im) {
    _re = re;
    _im = im;
}


template<typename T>
int complex<T>::getReal() const {
    return _re;
}

template<typename T>
int complex<T>::getImaginary() const {
    return _im;
}

template<typename T>
void complex<T>::putReal(int re) {
    _re = re;
}

template<typename T>
void complex<T>::putImaginary(int im) {
    _im = im;
}

template<typename T>
std::string complex<T>::intToString(int val) {
    std::stringstream ss;
    ss << val;
    return ss.str();
}

template<typename T>
complex<T>::complex(const complex<T>& val) {
    _re = val._re;
    _im = val._im;
}


template<typename U>
std::istream& operator>>(std::istream& is, complex<U>& complex)
{
    int real;
    int imaginary;
    std::cout << "Input the real value" << std::endl;
    is >> real;
    std::cout << "Input the imaginary value" << std::endl;
    is >> imaginary;
    // Assign the real and imaginary parts to complex
    complex.putReal(real);
    complex.putImaginary(imaginary);

    return is;
}


template<typename U>
std::ostream& operator<<(std::ostream& out, const complex<U>& complex)

{
    out << complex.getReal();
    out << "+";
    out << complex.getImaginary();
    out << "i";
    return out;
}

template<typename T>
// to add the i to the imaginary part of complex number
std::string complex<T>::toString() const {
    std::string s = "";
    s += intToString(_re);
    s += " ";
    if (_im > 0) {
        s += "+ " + intToString(_im) + "i";
    }
    else if (_im < 0) {
        s += "- " + intToString(-_im) + "i";
    }
    return s;
}
template<typename T>
complex<T>& complex<T>::operator=(const complex<T>& rhs)
{
    _re = rhs._re;
    _im = rhs._im;
    return *this;
}




#endif // complex_H
