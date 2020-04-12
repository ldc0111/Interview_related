/*************************************************************************
	> File Name: 3.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月20日 星期五 16时26分19秒
 ************************************************************************/

// example for thread::joinable
#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <unistd.h> 
void mythread() 
{
  // do stuff...
}
void mytime(){
    while(0)
    sleep(5);
}

int main() 
{
  std::thread foo;
  std::thread bar(mythread);
  std::thread cdd(mytime);

  std::cout << "Joinable after construction:\n" << std::boolalpha;
  std::cout << "foo: " << foo.joinable() << '\n';
  std::cout << "bar: " << bar.joinable() << '\n';
  std::cout << "bar: " << cdd.joinable() << '\n';

  std::cout << "foo: " << foo.get_id() << '\n';
  std::cout << "bar: " << bar.get_id() << '\n';
  std::cout << "cdd: " << cdd.get_id() << '\n';

  //if (foo.joinable()) foo.join();
  //if (bar.joinable()) bar.join();
  //if (cdd.joinable()) cdd.join();

  std::cout << "Joinable after joining:\n" << std::boolalpha;
  std::cout << "foo: " << foo.joinable() << '\n';
  std::cout << "bar: " << bar.joinable() << '\n';
  std::cout << "cdd: " << cdd.joinable() << '\n';

  cdd.join();
  std::cout << "cdd: " << cdd.joinable() << '\n';

  return 0;
}
