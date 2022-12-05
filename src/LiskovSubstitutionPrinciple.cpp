#include <iostream>
#include <vector>
#include <fstream>
#include <boost/lexical_cast.hpp>


using std::cout;
using std::endl;

void printHeader() {
   cout << endl;
   cout << "================================================" << endl;
   cout << "Design Patterns in Modern C++ by Dmitri Nesteruk" << endl;
   cout << "SOLID, Liskov Substitution Principle" << endl;
   cout << "================================================" << endl;
   cout << endl;
}

class Rectangle {
protected:
    int width;
    int height;

public:
    Rectangle( const int width, const int height )
             : width( width ),
               height( height ) {}

    int get_width() const { return width; }
    int get_height() const { return height; }

    virtual void set_width( const int width ) { this->width = width; }
    virtual void set_height( const int height ) { this->height = height; }

    int calc_area() const { return ( width * height ); }

};

class Square : public Rectangle {
public:
    Square( int size ) : Rectangle( size, size ) {}

    void set_width( const int width ) override {
        this->height = width;
        this->width = width;
    }

     void set_height( const int height ) override {
        this->height = height;
        this->width = height;
    }
};

void process( Rectangle & rectangle ) {
    int width = rectangle.get_width();
    int height = 10;
    rectangle.set_height( height );

    cout << "Expected area: " << ( width * height )
         << ", calculated: " << rectangle.calc_area() << endl;
}

int main(int argc, char *argv[]) {
   printHeader();

   Rectangle rectangle( 5, 5 );
   Square square( 5 );

   cout << "Calling process() for rectangle:" << endl;
   process( rectangle );

   cout << "Calling process() for square:" << endl;
   process( square );

   cout << endl;
   return 0;
}
