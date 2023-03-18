/**
 * @file server.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "F:/GitHubRepos/absolute_cpp/common.hpp" //always include for every new hpp and cpp file

using namespace std;

class Server
{
    private:
        string name;
        string ip;
        int port;
    public:
        Server();
        Server(string newName, string newIp, int newPort);
        void setName(string newName);
        void setIp(string newIp);
        void setPort(int newPort);
        string getName();
        string getIp();
        int getPort();
        void print();
        void showStatus();
        Server creator();
        Server destructor();
};

int main(int argc, char **argv); 

void Server::showStatus()
{
    cout << "Server is running" << endl;
}

Server::Server()
{
    name = "default";
    ip = "10.02.100.20213";
    port = 0;
}

Server::Server(string newName, string newIp, int newPort)
{
    name = newName;
    ip = newIp;
    port = newPort;
}

void Server::setName(string newName)
{
    name = newName;
}

void Server::setIp(string newIp)
{
    ip = newIp;
}

void Server::setPort(int newPort)
{
    port = newPort;
}

string Server::getName()
{
    return name;
}

string Server::getIp()
{
    return ip;
}

int Server::getPort()
{
    return port;
}

void Server::print()
{
    cout << "name: " << name << endl;
    cout << "ip: " << ip << endl;
    cout << "port: " << port << endl;
}

Server Server::creator()
{
    Server newServer;
    return newServer;
}

Server Server::destructor()
{
    Server newServer;
    return newServer;
}

int main(int argc, char **argv) {
    Server server1;
    server1.print();
    Server server2("server2", "10.02.100.20213", 8080);
    server2.print();
    Server server3;
    server3.setName("server3");
    server3.setIp("10.02.100.20213");
    server3.setPort(8080);
    server3.print();
    Server server4 = server3.creator();
    server4.print();
    Server server5 = server4.destructor();
    server5.print();
    server5.showStatus();
    return 0;
}