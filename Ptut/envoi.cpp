#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

#define SHELLSCRIPT2 "ssh root@10.105.1.32 \"cd ~/essai_code/test_boutton_led; g++ -lmraa -Wall prog.cpp -o prog && ./prog\""


int main(int args,char* argv[]) {
string cmd = "scp ";
cmd += argv[1] ;
cmd +=" root@10.105.1.32:~/essai_code/prog.cpp\n";
const char* commande=cmd.c_str();
 printf("%s",argv[1]);
 
system(commande);
 system("scp ./Periph.cpp root@10.105.1.32:~/essai_code/Periph.cpp\n");
 system("scp ./Periph.hpp root@10.105.1.32:~/essai_code/Periph.hpp\n");
system("ssh root@10.105.1.32 \"cd ~/essai_code/; g++ -lmraa -Wall prog.cpp Periph.cpp -o prog && ./prog\"");

return 0;
}
