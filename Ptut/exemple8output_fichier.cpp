#include <fstream>
#include <string>

using namespace std;

int main(void){
string evt1 = "Appui";
float time1 = 20.0;

ofstream out("out.txt");
if (out)
out << "(" << evt1 << ";" << time1 << ")" <<endl;

return 0;

}
