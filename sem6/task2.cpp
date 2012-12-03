#include <iostream>
#include <vector>
#include <string>
#include <map>

enum PublicationType {
  ARTICLE = 1,
  BOOK = 2,
  ABSTRACT = 3,
  INTERNET = 4
};

class Publication;

class Author {
  private:
    std::string name;
    std::string workplace;
    std::vector<Publication*> publications;

  public:
    Author() {
    }
    Author(const std::string& name_, const std::string& workplace_) :
      name(name_),
      workplace(workplace_) {
    }

    void add_publication(Publication* p) {
      publications.push_back(p);
    }

    std::string get_name() const {
      return name;
    }

    std::string get_workplace() const {
      return workplace;
    }

    std::vector<Publication*> get_publications() const {
      return publications;
    }

    void print() const {
      std::cout << name << " at " << workplace << '\n';
    }

};

class Publication {
  protected:
    std::string name;
    int year;
    std::vector<Author*> authors;

    virtual void print_subfields() const = 0;

  public:
    Publication() {

    }
    Publication(const std::string& name_, int year_, const std::vector<Author*>& authors_) :
      name(name_),
      year(year_),
      authors(authors_) {
    }

    void print() const {
      std::cout << "Name: " << name << ", year: " << year << '\n';
      std::cout << "Authors:\n";
      for (size_t i = 0; i < authors.size(); ++i) {
        authors[i]->print();
      }
      print_subfields();
    }

    std::vector<Author*> get_authors() const {
      return authors;
    }

    virtual ~Publication() {
    }
};

class Article: public Publication {
  private:
    std::string journal;

    void print_subfields() const {
      std::cout << "Type: Article\n" << "Journal: " << journal << '\n';
    }

  public:
    Article() {

    }
    Article(const std::string& name_, int year_, const std::vector<Author*>& authors_, const std::string& journal_) :
      Publication(name_, year_, authors_),
      journal(journal_) {
    }

};

class Book: public Publication {
  private:
    std::string publishing_house;

    void print_subfields() const {
      std::cout << "Type: Book\n" << "Publishing house: " << publishing_house << '\n';
    }

  public:
    Book() {
    }
    Book(const std::string& name_, int year_, const std::vector<Author*>& authors_, const std::string& publishing_house_) :
      Publication(name_, year_, authors_),
      publishing_house(publishing_house_) {
    }
};

class Abstract: public Publication {
  private:
    std::string conference;

    void print_subfields() const {
      std::cout << "Type: Abstract\n" << "Conference: " << conference << '\n';
    }

  public:
    Abstract() {

    }
    Abstract(const std::string& name_, int year_, const std::vector<Author*>& authors_, const std::string& conference_) :
      Publication(name_, year_, authors_),
      conference(conference_) {
    }
};

class Internet: public Publication {
  private:
    std::string url;

    void print_subfields() const {
      std::cout << "Type: Internet\n" << "url: " << url << '\n';
    }

  public:
    Internet() {

    }
    Internet(const std::string& name_, int year_, const std::vector<Author*>& authors_, const std::string& url_) :
      Publication(name_, year_, authors_),
      url(url_) {
    }
};

int main() {
  Publication* publ[100];

  int type;
  int year;
  int authors_number;
  std::string publ_name;
  std::string author_name;
  std::string author_workplace;
  std::vector<Author> authors(100);

  std::map<std::string, size_t> authors_map;

  size_t authors_index;
  std::vector<Author*> pauthors;

  Article articles[100];
  Book books[100];
  Abstract abstracts[100];
  Internet internets[100];

  size_t articles_cnt = 0;
  size_t books_cnt = 0;
  size_t abstracts_cnt = 0;
  size_t internets_cnt = 0;

  size_t count = 0;
  size_t cc = 0;

  size_t pc = 0;

  while (!std::cin.eof()) {
    ++cc;
    pauthors.clear();
    std::cin >> type;
    std::cin >> authors_number;
    for (size_t i = 0; i < authors_number; ++i) {
      std::cin >> author_name >> author_workplace;
      if (authors_map.find(author_name) == authors_map.end()) {
        authors[count++] = Author(author_name, author_workplace);
        authors_map[author_name] = count - 1;
        authors_index = count - 1;

      } else {
        authors_index = authors_map[author_name];
      }
      pauthors.push_back(&authors[authors_index]);
    }
    std::cin >> publ_name;
    std::cin >> year;
    if (type == ARTICLE) {
      std::string str;
      std::cin >> str;
      articles[articles_cnt++] = Article(publ_name, year, pauthors, str);
      publ[pc++] = (&articles[articles_cnt - 1]);
    } else if (type == BOOK) {
      std::string str;
      std::cin >> str;
      books[books_cnt++] = Book(publ_name, year, pauthors, str);
      publ[pc++] = (&books[books_cnt - 1]);
    } else if (type == ABSTRACT) {
      std::string str;
      std::cin >> str;
      abstracts[abstracts_cnt++] = Abstract(publ_name, year, pauthors, str);
      publ[pc++] = (&abstracts[abstracts_cnt - 1]);
    } else if (type == INTERNET) {
      std::string str;
      std::cin >> str;
      internets[internets_cnt++] = Internet(publ_name, year, pauthors, str);
      publ[pc++] = &internets[internets_cnt - 1];
    }
    if (cc == 4) {
      break;
    }
    for (size_t i = 0; i < pauthors.size(); ++i) {
      pauthors[i]->add_publication(publ[pc - 1]);
    }
  }

  for (size_t i = 0; i < pc; ++i) {
    publ[i]->print();
  }

  return 0;
}
