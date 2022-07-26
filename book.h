#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED
#include <vector>
#include <string>
using std::vector;
using std::string;


namespace BookReader {

class Book {
private:
string isbn;
string author;
string title;
vector <string> pages;
public:
    void Read();
    const string& GetAuthor() const;
    void SetAuthor(const string& author);
    const string& GetIsbn() const;
    void SetIsbn(const string& isbn);
    const vector<string>& GetPages() const ;
    void SetPages(const vector<string>& pages);
    const string& GetTitle() const ;
    void SetTitle(const string& title);
    string ToString();
};


}


#endif // BOOK_H_INCLUDED
