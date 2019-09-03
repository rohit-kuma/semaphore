#include <iostream>
#include <semaphore.h>
#include <thread>
#include <chrono>
using namespace std;
int var = 1;
int loop = 100;
void fun1()
{
  while(loop)
  {
    while(var != 1);
    this_thread::sleep_for(chrono::seconds(1));
    cout<<"T1 : "<<var<<endl;
    var = 2;
  }
}
void fun2()
{
  while(loop)
  {
    while(var != 2);
    cout<<"T2 : "<<var<<endl;
    var = 3;
  }
}
void fun3()
{
  while(loop)
  {
    while(var != 3);
    cout<<"T3 : "<<var<<endl;
    var = 1;
  }
}
int main() {
  thread t1, t2, t3;
  t1 = thread(fun1);
  t2 = thread(fun2);
  t3 = thread(fun3);
  t1.join();
  t2.join();
  t3.join();
  return 0;

}
