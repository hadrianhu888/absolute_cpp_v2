/**
 * @file documents.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-04
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:\GitHubRepos\absolute_cpp_v2\common.hpp"

using namespace std;

class Document
{
protected:
    string author;
    string date;
    string title;
public:
    Document(const string& author, const string& date, const string& title)
        : author(author), date(date), title(title) {}

    const string& getAuthor() const { return author; }
    void setAuthor(const string& author) { this->author = author; }

    const string& getDate() const { return date; }
    void setDate(const string& date) { this->date = date; }

    const string& getTitle() const { return title; }
    void setTitle(const string& title) { this->title = title; }

    const string& getAuthorName() const { return author; }
    void setAuthorName(const string& author) { this->author = author; }

    const string& getText() const { return date; }
    void setText(const string& date) { this->date = date; }

    virtual void print() const {
        cout << "Author: " << author << endl;
        cout << "Date: " << date << endl;
        cout << "Title: " << title << endl;
    }
    ~Document() {}
};

class Email:public Document
{
protected:
    string sender;
    string recipient;
    string subject;
public:
    Email(const string& author, const string& date, const string& title, const string& sender, const string& recipient, const string& subject)
        : Document(author, date, title), sender(sender), recipient(recipient), subject(subject) {}

    const string& getSender() const { return sender; }
    void setSender(const string& sender) { this->sender = sender; }

    const string& getRecipient() const { return recipient; }
    void setRecipient(const string& recipient) { this->recipient = recipient; }

    const string& getSubject() const { return subject; }
    void setSubject(const string& subject) { this->subject = subject; }

    virtual void print() const override {
        cout << "Sender: " << sender << endl;
        cout << "Recipient: " << recipient << endl;
        cout << "Subject: " << subject << endl;
    }
    ~Email() {}
};

class File:public Document
{
protected:
    string pathname;
public:
    File(const string& author, const string& date, const string& title, const string& pathname)
        : Document(author, date, title), pathname(pathname) {}

    const string& getPathname() const { return pathname; }
    void setPathname(const string& pathname) { this->pathname = pathname; }

    virtual void print() const override {
        cout << "Pathname: " << pathname << endl;
    }
    ~File() {}
};

bool containsKeyWords(const Document& document, const string& keyWords)
{
    return document.getTitle().find(keyWords) != string::npos;
}

int main(int argc, char ** argv)
{
    Document document("John Doe", "2021-05-04", "My Document");
    Email email("John Doe", "2021-05-04", "My Document", "john@example.com", "jane@example.com", "Hello");
    File file("John Doe", "2021-05-04", "My Document", "C:\\Users\\John Doe\\Documents\\My Document.txt");

    document.print();
    cout << endl;
    email.print();
    cout << endl;
    file.print();
    cout << endl;

    cout << "Contains keywords: " << containsKeyWords(document, "My") << endl;

    return 0;
}
