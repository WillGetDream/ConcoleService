#include <iostream>
#include "string"
using namespace std;


class Console
{
public:
    virtual ~Console() {}
    virtual void print(string msg) = 0;
    virtual void setColor(int color) = 0;
};

class LoggedConsole:public Console{
public:
    virtual void print(string msg){
        cout<<"print "<< msg<<endl;

    }
    virtual void setColor(int color){
        cout<<"set color of the LoggedConsole to: "<<color<<endl;
    }
};

class NotifyConsole:public Console{
public:
    virtual void print(string msg){
        cout<<"print "<< msg<<endl;
    }
    virtual void setColor(int color){
        cout<<"set color of the notityConsole to: "<<color<<endl;
    }
};



class Locator
{
public:
    static Console* getService() { return service_; }

    static void provide(Console* service)
    {
        service_=service;
    }
private:
    static Console* service_;
};

Console* Locator::service_=NULL;

int main() {

    //LoggedConsole
    LoggedConsole *console=new LoggedConsole();
    Locator::provide(console);
    Locator::getService()->print("Log Console ");
    Locator::getService()->setColor(2);


    //NotifyConsole
    NotifyConsole *console2=new NotifyConsole();
    Locator::provide(console2);
    Locator::getService()->print("notify Console ");
    Locator::getService()->setColor(1);


    return 0;
}
