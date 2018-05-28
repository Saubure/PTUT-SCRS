#include <ctime>
#include <iostream>


using namespace std;

int main()
{
  time_t result = time(NULL);
cout<<asctime(localtime(&result))<<endl;
  

}
