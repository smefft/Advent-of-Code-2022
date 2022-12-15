#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() {
  ifstream File;
  int numElves;
  int total;
  string line;
  string newline = "\n";
  vector<int> elfTotals;
  int topThree;
  
  File.open("ElfFood.txt");
  while (!File.eof()) {
    getline(File, line);
    //cout<<line<<endl;
    if (line != "") {
      total+=stoi(line);
    }
    else {
      elfTotals.push_back(total);
      total = 0;
    }
    
  }
  int max_value = elfTotals[0];
  for (int i=0; i<elfTotals.size(); i++) {
    if (elfTotals[i]>max_value) {
      max_value = elfTotals[i];
    }
  }
  //cout<<max_value<<endl;

  int size = elfTotals.size();
  sort(elfTotals.begin(), elfTotals.end());
  //cout<<elfTotals[0]<<" "<<elfTotals[elfTotals.size()-1]<<endl;
  topThree = elfTotals[size-1] + elfTotals[size-2] + elfTotals[size-3];
  cout<<topThree<<endl;
  File.close();
  return 0;
}
