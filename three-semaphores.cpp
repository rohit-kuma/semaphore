#include <iostream>
#include <semaphore.h>
#include <thread>
#include <chrono>
using namespace std;
sem_t sem1;
sem_t sem2;
sem_t sem3;
void fun1()
{
  while(1)
  {
     sem_wait(&sem1);
       cout<<"T1 : "<< "1" <<endl;
     sem_post(&sem2);
  }
}
void fun2()
{
  while(1)
  {
   sem_wait(&sem2);
    cout<<"T2 : "<< "2" <<endl;
   sem_post(&sem3);
  }
}
void fun3()
{ while(1)
  {
   sem_wait(&sem3);
     cout<<"T3 : "<< "3" <<endl;
   sem_post(&sem1);
  }
}
int main() {
  sem_init(&sem1, 0, 1);
  sem_init(&sem2, 0, 0);
  sem_init(&sem3, 0, 0);
  thread t1, t2, t3;
  t1 = thread(fun1);
  t2 = thread(fun2);
  t3 = thread(fun3);
  t1.join();
  t2.join();
  t3.join();
  sem_destroy(&sem1);
  sem_destroy(&sem2);
  sem_destroy(&sem3);
  return 0;
}
