#include <iostream>
using namespace std;

void cText(char* destination, const char* source) {
    int i = 0;
    while (true) {
        destination[i] = source[i];
        if (source[i] == '\0') {
            break;
        }
        i = i + 1;
    }
}

bool sText(const char* text1, const char* text2) {
    int i = 0;
    while (true) {
        if (text1[i] != text2[i]) {
            return false;
        }
        if (text1[i] == '\0' && text2[i] == '\0') {
            break;
        }
        i = i + 1;
    }
    return true;
}

class Information {
public:
    char title[80];
    char author[80];
    Information() {
        title[0] = '\0';
        author[0] = '\0';
    }

    Information(const char* t, const char* a) {
        cText(title, t);
        cText(author, a);
    }

    char* getTitle() {
        return title;
    }

    char* getAuthor() {
        return author;
    }

    void setTitle(const char* t) {
        cText(title, t);
    }

    void setAuthor(const char* a) {
        cText(author, a);
    }
};

bool compareBooks(Information* book1, Information* book2) {
    return sText(book1->getTitle(), book2->getTitle()) &&
           sText(book1->getAuthor(), book2->getAuthor());
}

int main() {
    Information books[100];
    int bookCount = 0;
    int number;

    do {
        cout << "***** 도서 정보 관리 프로그램 *****" << endl;
        cout << "1. 도서 추가" << endl;
        cout << "2. 도서 검색" << endl;
        cout << "3. 도서 정보 수정" << endl;
        cout << "4. 프로그램 종료" << endl;
        cout << "번호를 입력하세요: ";
        cin >> number;

        if (number == 1) {
            char title[80], author[80];
            cout << "도서 제목을 입력하세요: ";
            cin.ignore(); 
            cin.getline(title, 80);
            cout << "도서 저자를 입력하세요: ";
            cin.getline(author, 80);

            Information newBook(title, author);
            books[bookCount] = newBook;
            bookCount = bookCount + 1;

            cout << "도서가 추가되었습니다." << endl << endl;
        }

        else if (number == 2) {
            if (bookCount == 0) {
                cout << "등록된 도서가 없습니다." << endl << endl;
                continue;
            }

            char title[80], author[80];
            cout << "검색할 도서 제목을 입력하세요: ";
            cin.ignore();
            cin.getline(title, 80);
            cout << "검색할 도서 저자를 입력하세요: ";
            cin.getline(author, 80);

            Information target(title, author);
            bool found = false;
            int index = 0;

            while (index < bookCount) {
                if (compareBooks(&books[index], &target)) {
                    cout << "제목: " << books[index].getTitle() << ", 저자: " << books[index].getAuthor() << endl << endl;
                    found = true;
                    break;
                }
                index = index + 1;
            }

            if (!found) {
                cout << "해당 도서를 찾을 수 없습니다." << endl << endl;
            }
        }

        else if (number == 3) {
            if (bookCount == 0) {
                cout << "등록된 도서가 없습니다." << endl << endl;
                continue;
            }

            char title[80], author[80];
            cout << "수정할 도서 제목을 입력하세요: ";
            cin.ignore();
            cin.getline(title, 80);
            cout << "수정할 도서 저자를 입력하세요: ";
            cin.getline(author, 80);

            Information target(title, author);
            bool found = false;
            int index = 0;

            while (index < bookCount) {
                if (compareBooks(&books[index], &target)) {
                    char newTitle[80], newAuthor[80];
                    cout << "새로운 도서 제목을 입력하세요: ";
                    cin.getline(newTitle, 80);
                    cout << "새로운 도서 저자를 입력하세요: ";
                    cin.getline(newAuthor, 80);

                    books[index].setTitle(newTitle);
                    books[index].setAuthor(newAuthor);

                    cout << "도서 정보가 성공적으로 수정되었습니다." << endl << endl;
                    found = true;
                    break;
                }
                index = index + 1;
            }

            if (!found) {
                cout << "일치하는 도서를 찾을 수 없습니다." << endl << endl;
            }
        }

        else if (number == 4) {
            cout << "프로그램을 종료합니다." << endl;
        }

        else {
            cout << "정확한 번호를 입력하세요." << endl << endl;
        }

    } while (number != 4);

    return 0;
}
