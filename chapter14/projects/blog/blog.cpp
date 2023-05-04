/**
 * @file blog.cpp
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

class BlogPost
{
protected:
    string author;
    string date;
    string title;
public:
    BlogPost(const string& author, const string& date, const string& title)
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
    ~BlogPost() {}
};

class BlogVisitor:public BlogPost
{
protected:
    string visitor;
public:
    BlogVisitor(const string& author, const string& date, const string& title, const string& visitor)
        : BlogPost(author, date, title), visitor(visitor) {}

    const string& getVisitor() const { return visitor; }
    void setVisitor(const string& visitor) { this->visitor = visitor; }

    virtual void print() const override {
        BlogPost::print();
        cout << "Visitor: " << visitor << endl;
    }
    ~BlogVisitor() {}
};

class BlogComment:public BlogPost
{
protected:
    string comment;
public:
    BlogComment(const string& author, const string& date, const string& title, const string& comment)
        : BlogPost(author, date, title), comment(comment) {}

    const string& getComment() const { return comment; }
    void setComment(const string& comment) { this->comment = comment; }

    virtual void print() const override {
        BlogPost::print();
        cout << "Comment: " << comment << endl;
    }
    ~BlogComment() {}
};

class BlogPostList
{
private:
    BlogPost** list;
    int size;
    int capacity;
public:
    BlogPostList(int capacity = 10)
        : capacity(capacity), size(0) {
        list = new BlogPost*[capacity];
    }

    void add(BlogPost* blogPost) {
        if (size == capacity) {
            capacity *= 2;
            BlogPost** newList = new BlogPost*[capacity];
            for (int i = 0; i < size; i++) {
                newList[i] = list[i];
            }
            delete[] list;
            list = newList;
        }
        list[size++] = blogPost;
    }

    void print() const {
        for (int i = 0; i < size; i++) {
            list[i]->print();
            cout << endl;
        }
    }

    ~BlogPostList() {
        for (int i = 0; i < size; i++) {
            delete list[i];
        }
        delete[] list;
    }
};

class Viewer
{
private:
    string name;
public:
    Viewer() {}
    Viewer(const string& name)
        : name(name) {}

    const string& getName() const { return name; }
    void setName(const string& name) { this->name = name; }

    void view(BlogPostList& blogPostList) {
        blogPostList.print();
    }
};

class Owner
{
private:
    string name;
public:
    Owner() {}
    Owner(const string& name)
        : name(name) {}

    const string& getName() const { return name; }
    void setName(const string& name) { this->name = name; }

    void add(BlogPostList& blogPostList, BlogPost* blogPost) {
        blogPostList.add(blogPost);
    }
};

int main(int argc, char ** argv)
{
    BlogPostList blogPostList;
    blogPostList.add(new BlogPost("John", "2021-05-04", "My first blog post"));
    blogPostList.add(new BlogVisitor("John", "2021-05-04", "My first blog post", "Mary"));
    blogPostList.add(new BlogComment("John", "2021-05-04", "My first blog post", "Nice post!"));
    blogPostList.print();
    Owner owner;
    owner.add(blogPostList, new BlogPost("John", "2021-05-04", "My first blog post"));
    owner.add(blogPostList, new BlogVisitor("John", "2021-05-04", "My first blog post", "Mary"));
    owner.add(blogPostList, new BlogComment("John", "2021-05-04", "My first blog post", "Nice post!"));
    Viewer viewer("Mary");
    viewer.view(blogPostList);
    return 0;
}
