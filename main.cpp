#include <iostream>
using namespace std;

void swap (int* th, const int* rhs, int size){
    for (int i = 0; i < size; i++){
        *(th+i) = *(rhs+i);
    }
}

class IntList {
public:
    IntList ( int size = 0 , int initvalue = 0);
    IntList ( const IntList & lis );
    ~ IntList ();
    int getSize () const { return size_ ; }
    IntList & operator =( const IntList & rhs );
private :
    int * list_ ; // list of values ( int )
    int size_ ;
};


IntList::IntList ( int size  , int initvalue) {
    if( size > 0){
        list_ = new int[ size ];
        size_ = size ;
        for( int i = 0; i < size_ ; i ++)
            list_ [i] = initvalue ;
    }
    else {
        list_ = 0;
        size_ = 0;
    }

}

//1) write a definition for the destructor
IntList::~IntList() {
    for (int i = 0; i < size_; i++) {
        cout <<"Destructor Called for : " << list_+i << endl;
        delete (list_+i);
    }
}

//2) fix the copy constructor
IntList :: IntList ( const IntList & L ){
    size_=L.size_;
    list_ = new int[size_];
    for (int i = 0; i <size_; i++) {
        *(list_+i) = *(L.list_+i);
    }

}


//3) rewrite the copy assignment operator using an optimized method
IntList& IntList:: operator =( const IntList& rhs ){

    swap(this->list_, rhs.list_, rhs.size_);


    /*if( list_ )
        delete [] list_ ;
    size_ = rhs . size_ ;
    if( rhs . size_ > 0){
        list_ = new int [ rhs . size_ ];
        for ( int i = 0; i < rhs . size_ ; i ++)
            list_ [ i ] = rhs . list_ [ i ];
    }
    else
        list_ = 0;*/

return *this;
}



//4) Swap Function


int main(){

    IntList L1 (5,0);
    //4- declare L2 and make that l2=l1 is properly working

   return 0;
}
