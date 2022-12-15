#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>

using namespace std;

void addValue(int, char);

vector<char> one;  
vector<char> two;  
vector<char> three;  
vector<char> four;
vector<char> five;  
vector <char> six;  
vector <char> seven;  
vector <char> eight; 
vector <char> nine;

int main() {
  one.push_back('H'); one.push_back('B');  one.push_back('V');  one.push_back('W'); one.push_back('N');  one.push_back('M'); one.push_back('L');  one.push_back('P');
  two.push_back('M'); two.push_back('M'); two.push_back('Q'); two.push_back('H');
  three.push_back('N');  three.push_back('D');  three.push_back('B');  three.push_back('G');  three.push_back('F');  three.push_back('Q');  three.push_back('M'); three.push_back('L');
  four.push_back('Z'); four.push_back('T'); four.push_back('F'); four.push_back('Q'); four.push_back('M'); four.push_back('W'); four.push_back('G');
  five.push_back('M'); five.push_back('T'); five.push_back('H'); five.push_back('P'); 
  six.push_back('C'); six.push_back('B'); six.push_back('M'); six.push_back('J'); six.push_back('D'); six.push_back('H'); six.push_back('G'); six.push_back('T');
  seven.push_back('M'); seven.push_back('N');seven.push_back('B');seven.push_back('F');seven.push_back('V');seven.push_back('R');
  eight.push_back('P'); eight.push_back('L');eight.push_back('H');eight.push_back('M');eight.push_back('R');eight.push_back('G');eight.push_back('S');
  nine.push_back('P'); nine.push_back('D'); nine.push_back('B'); nine.push_back('C'); nine.push_back('N'); 

  ifstream file;

  file.open("crates.txt"); //open() is a function

  string word;
  string instructions[6]; //1 is amount to be moved, 3 is from where, 5 is to where
  int i=0, j,  numMoved, moveFrom, moveTo, size, count=0;
  
  while (file >> word || !file.eof()) { //eof() is a function //can use >> in c++
    instructions[i] = word;
    i++;
    
    if (i==6) {
      i=0;
      count++;
      //cout<<count<<" ";
      
      numMoved = stoi(instructions[1]);
      moveFrom = stoi(instructions[3]);
      moveTo = stoi(instructions[5]);

      /*if (moveFrom == 3) {
	for (j=0; j<numMoved; j++) {
	  cout<<three[three.size()-1]<<endl;
	  three.pop_back();
	}
	}*/
      
      switch(moveFrom) {
      case 1:{
	//cout<<" 1"<<endl;
	for (j=numMoved; j>0; j--) {
	  size = one.size();
	  addValue(moveTo, one[size-j]);
	  //cout<<one[size-1]<<endl;
	  //one.pop_back();
	}
	for (j=0; j<numMoved; j++) {
	  one.pop_back();
	}
      }
	break;
      case 2:{
	//cout<<" 2 "<<endl;

	for (j=numMoved; j>0; j--) {
	  size = two.size();
	  addValue(moveTo, two[size-j]);
	  //two.pop_back();
	}
	for (j=0; j<numMoved; j++) {
	  two.pop_back();
	}
      }
	break;
      case 3: {
	//cout<<" 3 "<<endl;

	for (j=numMoved; j>0; j--) {
	  size = three.size();
	  //cout<<j<<" "<<three[size-1]<<endl;
	  addValue(moveTo, three[size-j]);
	  //three.pop_back();
	}
	for (j=0; j<numMoved; j++) {
	  three.pop_back();
	}
      }
	break;
      case 4: {
	//cout<<" 4 "<<endl;

	for (j=numMoved; j>0; j--) {
	  size = four.size();
	  addValue(moveTo, four[size-j]);
	  //cout<<four[size-1]<<endl;
	  //four.pop_back();
	}
	for (j=0; j<numMoved; j++) {
	  four.pop_back();
	}
       
      }
	break;
      case 5: {
	//cout<<" 5 "<<endl;

	for (j=numMoved; j>0; j--) {
	  size = five.size();
	  addValue(moveTo, five[size-j]);
	  //five.pop_back();
	}
	for (j=0; j<numMoved; j++) {
	  five.pop_back();
	}
      }
	break;
      case 6: {
	//cout<<" 6 "<<endl;

	for (j=numMoved; j>0; j--) {
	  size = six.size();
	  addValue(moveTo, six[size-j]);
	  //cout<<six[size-1]<<endl;
	  //six.pop_back();
	}
	for (j=0; j<numMoved; j++) {
	  six.pop_back();
	}
      }
	break;
      case 7: {
	//cout<<" 7 "<<endl;

	for (j=numMoved; j>0; j--) {
	  size = seven.size();
	  addValue(moveTo, seven[size-j]);
	  //seven.pop_back();
	}
	for (j=0; j<numMoved; j++) {
	  seven.pop_back();
	}
      }
	break;
      case 8: {
	//cout<<" 8 "<<endl;

	for (j=numMoved; j>0; j--) {
	  size = eight.size();
	  addValue(moveTo, eight[size-j]);
	  //eight.pop_back();
	}
	for (j=0; j<numMoved; j++) {
	  eight.pop_back();
	}
      }
	break;
      case 9: {
	//cout<<" 9 "<<endl;

	for (j=numMoved; j>0; j--) {
	  size = nine.size();
	  addValue(moveTo, nine[size-j]);
	  //cout<<nine[size-1]<<endl;
	  //nine.pop_back();
	}
	for (j=0; j<numMoved; j++) {
	  nine.pop_back();
	}
      }
	break;
      default:{
	cout<<"Shouldn't be happening. wtf"<<endl;
      }
	break;
      }
      //cout<<"end switch"<<endl;
    }
    //cout<<"end if"<<endl;
  }
  //cout<<"end while"<<endl;

  file.close();
  //cout<<one[one.size()-1]<<" "<<two[two.size()-1]<<" "<<three[three.size()-1]<<" "<<four[four.size()-1]<<" "<<five[five.size()-1]<<endl;
  cout<<"file closed"<<endl;

  cout<<one[one.size()-1]<<" "<<two[two.size()-1]<<" "<<three[three.size()-1]<<" "<<four[four.size()-1]<<" "<<five[five.size()-1]<<" "<<six[six.size()-1]<<" "<<seven[seven.size()-1]<<" "<<eight[eight.size()-1]<<" "<<nine[nine.size()-1]<<endl;;
  return 0;
}

void addValue(int stack, char value) {
  //cout<<"Value: "<<value<<endl;
  if (stack == 1) {one.push_back(value);}
  else if (stack == 2) {two.push_back(value);}
  else if (stack == 3) {three.push_back(value);}
  else if (stack == 4) {four.push_back(value);}
  else if (stack ==5) {five.push_back(value);}
  else if (stack == 6) {six.push_back(value);}
  else if (stack == 7) {seven.push_back(value);}
  else if (stack == 8) {eight.push_back(value);}
  else if (stack == 9) {nine.push_back(value);}
}
