#include<iostream>


using namespace std;
class LibMat
{
private:
    /* data */
public:
    LibMat(/* args */);
    virtual ~LibMat() // virtual function must be inside class decalaration
{
    cout<<"LibMat:: ~LibMat() desctructor!\n";
}
    virtual void print() const{
        cout<<" LibMat:: print() -- I am a LibMat object!\n";
    }

};

LibMat::LibMat(/* args */)
{
    cout<<"LibMat::LibMat() default constructor!\n";
}

class Book: public LibMat
{
private:
    /* data */
    string _title;
    string _author;
public:
    Book(const string &title, const string &author)
    :_title(title), _author(author){
        cout<<"Book::Book("<<_title<<", "<< _author<<") constructor \n";
    }


    virtual ~Book(){
        cout<<"Book:: ~Book() destructor!\n";
    }

    virtual void print() const{
        cout << "Book::print() -- I ama Book object!\n"
        <<" My title is: "<<_title<<"\n"
        <<" My author is: "<<_author<<"\n";
    }

protected:
    const string & title() const {
        return _title;
    }
    const string & author() const{
        return _author;
    }
};


class AudioBook: public Book
{
private:
    const string _reader;
protected:
    const string& reader(const string& reader){
        return _reader;
    }
public:
    AudioBook(const string& title, const string& author, const string& reader)
    :Book(title, author), _reader(reader){
        cout<<"I am constructor of AudioBook::AudioBook("<< title<<", "<< author <<", "<<reader<<")"<<endl; 
    };
    ~AudioBook(){
        cout<<"~AudioBook::AudioBook()"<<endl;
    };
    virtual void print() const{
        cout<<" The printer for audio book with title: "<< title() <<", author: "<<author()<<" and reader: "<<_reader<<endl; 
    }
};




void print(const LibMat &mat){
    cout<<"in global print(): about to print mat.print()\n";
    mat.print();
}

int main(int argc, char const *argv[])
{
    cout<<endl<<"Creating a libMat object to print()"<<endl;
    LibMat libmat;
    Book book("TITLE", "AUTHOR");
    AudioBook audiobook("TITLE_AUDIO", "AUTHOR_AUDIO", "READER");
    print(libmat);
    print(book);
    print(audiobook);
    return 0;
}

