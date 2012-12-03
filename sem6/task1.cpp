#include <iostream>

class Formatter {
  public:
    virtual void printHeader() const = 0;
    virtual void printTitle() const = 0;
    virtual void printParagraph() const = 0;
    virtual void printFooter() const = 0;
    virtual bool eof() const = 0;
    virtual ~Formatter() {
    }
};

class WikiFormatter: public Formatter {
  public:
    virtual void printHeader() const {
      std::cout << "wiki text: header\n";
    }
    virtual void printTitle() const {
      std::cout << "wiki text: title\n";
    }
    virtual void printParagraph() const {
      std::cout << "wiki text: paragraph\n";
    }
    virtual void printFooter() const {
      std::cout << "wiki text: footer\n";
    }
    virtual bool eof() const {
      return true;
    }
};

class HtmlFormatter: public Formatter {
  public:
    virtual void printHeader() const {
      std::cout << "html text: header\n";
    }
    virtual void printTitle() const {
      std::cout << "html text: title\n";
    }
    virtual void printParagraph() const {
      std::cout << "html text: paragraph\n";
    }
    virtual void printFooter() const {
      std::cout << "html text: footer\n";
    }
    virtual bool eof() const {
      return true;
    }
};

class PlainTextFormatter: public Formatter {
  public:
    virtual void printHeader() const {
      std::cout << "plain text: header\n";
    }
    virtual void printTitle() const {
      std::cout << "plain text: title\n";
    }
    virtual void printParagraph() const {
      std::cout << "plain text: paragraph\n";
    }
    virtual void printFooter() const {
      std::cout << "plain text: footer\n";
    }
    virtual bool eof() const {
      return true;
    }
};

void printDocument(Formatter& f) {
  f.printHeader();
  f.printTitle();
  while (!f.eof()) {
    f.printParagraph();
  }
  f.printFooter();
}

int main() {
  HtmlFormatter html;
  WikiFormatter wiki;
  PlainTextFormatter plain;

  printDocument(html);
  printDocument(wiki);
  printDocument(plain);

  return 0;
}
